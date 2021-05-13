/****************************************************************************
 *          National Instruments Digital Pattern Driver                     *
 *--------------------------------------------------------------------------*
 *   Copyright (c) National Instruments 2017.  All Rights Reserved.         *
 *--------------------------------------------------------------------------*
 *                                                                          *
 * Title:    niDigital.h                                                    *
 * Purpose:  National Instruments Digital Pattern Driver declarations.      *
 *                                                                          *
 ****************************************************************************/

#ifndef ___niDigital_niDigital_h___
#define ___niDigital_niDigital_h___

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#ifdef _CVI_
   #pragma EnableLibraryRuntimeChecking
#endif


#if defined(__cplusplus) || defined(__cplusplus__)
   extern "C" {
#endif


/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIDIGITAL_MAJOR_VERSION             20    /* Instrument driver major version   */
#define NIDIGITAL_MINOR_VERSION             6    /* Instrument driver minor version   */

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*- IVI Inherent Attributes ------------------------------------------------*/
#define NIDIGITAL_ATTR_CACHE                                         /* ViBoolean   */  IVI_ATTR_CACHE
#define NIDIGITAL_ATTR_RANGE_CHECK                                   /* ViBoolean   */  IVI_ATTR_RANGE_CHECK
#define NIDIGITAL_ATTR_QUERY_INSTRUMENT_STATUS                       /* ViBoolean   */  IVI_ATTR_QUERY_INSTRUMENT_STATUS
#define NIDIGITAL_ATTR_RECORD_COERCIONS                              /* ViBoolean   */  IVI_ATTR_RECORD_COERCIONS
#define NIDIGITAL_ATTR_SIMULATE                                      /* ViBoolean   */  IVI_ATTR_SIMULATE
#define NIDIGITAL_ATTR_INTERCHANGE_CHECK                             /* ViBoolean   */  IVI_ATTR_INTERCHANGE_CHECK
#define NIDIGITAL_ATTR_LOGICAL_NAME                                  /* ViString    */  IVI_ATTR_LOGICAL_NAME
#define NIDIGITAL_ATTR_GROUP_CAPABILITIES                            /* ViString    */  IVI_ATTR_GROUP_CAPABILITIES
#define NIDIGITAL_ATTR_SUPPORTED_INSTRUMENT_MODELS                   /* ViString    */  IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

/*- Specific Driver Information, Read-only ---------------------------------*/
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_DESCRIPTION                   /* ViString    */  IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_PREFIX                        /* ViString    */  IVI_ATTR_SPECIFIC_DRIVER_PREFIX
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_VENDOR                        /* ViString    */  IVI_ATTR_SPECIFIC_DRIVER_VENDOR
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_REVISION                      /* ViString    */  IVI_ATTR_SPECIFIC_DRIVER_REVISION
#define NIDIGITAL_ATTR_CHANNEL_COUNT                                 /* ViInt32     */  IVI_ATTR_CHANNEL_COUNT
#define NIDIGITAL_ATTR_INSTRUMENT_MANUFACTURER                       /* ViString    */  IVI_ATTR_INSTRUMENT_MANUFACTURER
#define NIDIGITAL_ATTR_INSTRUMENT_MODEL                              /* ViString    */  IVI_ATTR_INSTRUMENT_MODEL
#define NIDIGITAL_ATTR_INSTRUMENT_FIRMWARE_REVISION                  /* ViString    */  IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION      /* ViInt32     */  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
#define NIDIGITAL_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION      /* ViInt32     */  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
#define NIDIGITAL_ATTR_IO_RESOURCE_DESCRIPTOR                        /* ViString    */  IVI_ATTR_RESOURCE_DESCRIPTOR

/*- Driver Setup Information -----------------------------------------------*/
#define NIDIGITAL_ATTR_DRIVER_SETUP                                  /* ViString    */  IVI_ATTR_DRIVER_SETUP

/*- Device Attributes ------------------------------------------------------*/
#define NIDIGITAL_ATTR_SERIAL_NUMBER                                 /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  1L)

/*- Pin Control ------------------------------------------------------------*/
#define NIDIGITAL_ATTR_SELECTED_FUNCTION                             /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  4L)

/*- Level Configuration ----------------------------------------------------*/
#define NIDIGITAL_ATTR_VIL                                           /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  7L)
#define NIDIGITAL_ATTR_VIH                                           /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  8L)
#define NIDIGITAL_ATTR_VOL                                           /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  9L)
#define NIDIGITAL_ATTR_VOH                                           /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)
#define NIDIGITAL_ATTR_VTERM                                         /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 11L)
#define NIDIGITAL_ATTR_TERMINATION_MODE                              /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE +  6L)
#define NIDIGITAL_ATTR_ACTIVE_LOAD_IOL                               /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)
#define NIDIGITAL_ATTR_ACTIVE_LOAD_IOH                               /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)
#define NIDIGITAL_ATTR_ACTIVE_LOAD_VCOM                              /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)

/*- Trigger Configuration --------------------------------------------------*/
#define NIDIGITAL_ATTR_START_TRIGGER_TYPE                            /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)
#define NIDIGITAL_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE             /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)
#define NIDIGITAL_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE               /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)
#define NIDIGITAL_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL        /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)

#define NIDIGITAL_ATTR_CONDITIONAL_JUMP_TRIGGER_TYPE                 /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)
#define NIDIGITAL_ATTR_DIGITAL_EDGE_CONDITIONAL_JUMP_TRIGGER_SOURCE  /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)
#define NIDIGITAL_ATTR_DIGITAL_EDGE_CONDITIONAL_JUMP_TRIGGER_EDGE    /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)
#define NIDIGITAL_ATTR_EXPORTED_CONDITIONAL_JUMP_TRIGGER_OUTPUT_TERMINAL /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)
#define NIDIGITAL_ATTR_CONDITIONAL_JUMP_TRIGGER_TERMINAL_NAME        /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)

/*- PPMU -------------------------------------------------------------------*/
#define NIDIGITAL_ATTR_PPMU_OUTPUT_FUNCTION                          /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)

#define NIDIGITAL_ATTR_PPMU_VOLTAGE_LEVEL                            /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)
#define NIDIGITAL_ATTR_PPMU_CURRENT_LIMIT                            /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 54L)
#define NIDIGITAL_ATTR_PPMU_CURRENT_LIMIT_RANGE                      /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 17L)
#define NIDIGITAL_ATTR_PPMU_CURRENT_LIMIT_SUPPORTED                  /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 55L)
#define NIDIGITAL_ATTR_PPMU_CURRENT_LIMIT_BEHAVIOR                   /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 64L)

#define NIDIGITAL_ATTR_PPMU_CURRENT_LEVEL                            /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)
#define NIDIGITAL_ATTR_PPMU_CURRENT_LEVEL_RANGE                      /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)
#define NIDIGITAL_ATTR_PPMU_VOLTAGE_LIMIT_LOW                        /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)
#define NIDIGITAL_ATTR_PPMU_VOLTAGE_LIMIT_HIGH                       /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)

#define NIDIGITAL_ATTR_PPMU_APERTURE_TIME                            /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)
#define NIDIGITAL_ATTR_PPMU_APERTURE_TIME_UNITS                      /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)

#define NIDIGITAL_ATTR_PPMU_ALLOW_EXTENDED_VOLTAGE_RANGE             /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)

/*- Patterns ---------------------------------------------------------------*/
#define NIDIGITAL_ATTR_START_LABEL                                   /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)
#define NIDIGITAL_ATTR_MASK_COMPARE                                  /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 60L)

/*- Pattern Opcode Event ---------------------------------------------------*/
#define NIDIGITAL_ATTR_EXPORTED_PATTERN_OPCODE_EVENT_OUTPUT_TERMINAL /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)

/*- Timing Offset ----------------------------------------------------------*/
#define NIDIGITAL_ATTR_TDR_OFFSET                                    /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L)
#define NIDIGITAL_ATTR_TIMING_ABSOLUTE_DELAY_ENABLED                 /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)
#define NIDIGITAL_ATTR_TIMING_ABSOLUTE_DELAY                         /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)

/*- Keep Alive -------------------------------------------------------------*/
#define NIDIGITAL_ATTR_HALT_ON_KEEP_ALIVE_OPCODE                     /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 62L)
#define NIDIGITAL_ATTR_IS_KEEP_ALIVE_ACTIVE                          /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 63L)

/*- Frequency Measurement --------------------------------------------------*/
#define NIDIGITAL_ATTR_FREQUENCY_COUNTER_MEASUREMENT_TIME            /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)
#define NIDIGITAL_ATTR_FREQUENCY_COUNTER_MEASUREMENT_MODE            /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 84L)
#define NIDIGITAL_ATTR_FREQUENCY_COUNTER_HYSTERESIS_ENABLED          /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)

/*- Clock Generator --------------------------------------------------------*/
#define NIDIGITAL_ATTR_CLOCK_GENERATOR_FREQUENCY                     /* ViReal64    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)
#define NIDIGITAL_ATTR_CLOCK_GENERATOR_IS_RUNNING                    /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)

/*- History RAM ------------------------------------------------------------*/
#define NIDIGITAL_ATTR_HISTORY_RAM_TRIGGER_TYPE                      /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)
#define NIDIGITAL_ATTR_CYCLE_NUMBER_HISTORY_RAM_TRIGGER_CYCLE_NUMBER /* ViInt64     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)
#define NIDIGITAL_ATTR_PATTERN_LABEL_HISTORY_RAM_TRIGGER_VECTOR_OFFSET  /* ViInt64  */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L)
#define NIDIGITAL_ATTR_PATTERN_LABEL_HISTORY_RAM_TRIGGER_CYCLE_OFFSET   /* ViInt64  */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)
#define NIDIGITAL_ATTR_PATTERN_LABEL_HISTORY_RAM_TRIGGER_LABEL       /* ViString    */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L)
#define NIDIGITAL_ATTR_HISTORY_RAM_CYCLES_TO_ACQUIRE                 /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L)
#define NIDIGITAL_ATTR_HISTORY_RAM_PRETRIGGER_SAMPLES                /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L)
#define NIDIGITAL_ATTR_HISTORY_RAM_MAX_SAMPLES_TO_ACQUIRE_PER_SITE   /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)
#define NIDIGITAL_ATTR_HISTORY_RAM_NUMBER_OF_SAMPLES_IS_FINITE       /* ViBoolean   */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)
#define NIDIGITAL_ATTR_HISTORY_RAM_BUFFER_SIZE_PER_SITE              /* ViInt64     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)

/*- Synchronization --------------------------------------------------------*/
#define NIDIGITAL_ATTR_START_TRIGGER_TERMINAL_NAME                  /* ViString     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)
#define NIDIGITAL_ATTR_SEQUENCER_FLAG_TERMINAL_NAME                 /* ViString     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 59L)
#define NIDIGITAL_ATTR_PATTERN_OPCODE_EVENT_TERMINAL_NAME           /* ViString     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)

/*- TDR Endpoint Termination------------------------------------------------*/
#define NIDIGITAL_ATTR_TDR_ENDPOINT_TERMINATION                      /* ViInt32     */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)

/*- Digital States ---------------------------------------------------------*/
#define NIDIGITAL_VAL_0                         0
#define NIDIGITAL_VAL_1                         1
#define NIDIGITAL_VAL_L                         3
#define NIDIGITAL_VAL_H                         4
#define NIDIGITAL_VAL_X                         5
#define NIDIGITAL_VAL_M                         6
#define NIDIGITAL_VAL_V                         7
#define NIDIGITAL_VAL_D                         8
#define NIDIGITAL_VAL_E                         9
#define NIDIGITAL_VAL_NOT_A_PIN_STATE           254
#define NIDIGITAL_VAL_PIN_STATE_NOT_ACQUIRED    255

/*- Values for NIDIGITAL_ATTR_SELECTED_FUNCTION ----------------------------*/
#define NIDIGITAL_VAL_DIGITAL                   1100
#define NIDIGITAL_VAL_PPMU                      1101
#define NIDIGITAL_VAL_OFF                       1102
#define NIDIGITAL_VAL_DISCONNECT                1103

/*- Values for NIDIGITAL_ATTR_TERMINATION_MODE -----------------------------*/
#define NIDIGITAL_VAL_ACTIVE_LOAD               1200
#define NIDIGITAL_VAL_VTERM                     1201
#define NIDIGITAL_VAL_HIGH_Z                    1202

/*- Values for NIDIGITAL_ATTR_PPMU_OUTPUT_FUNCTION -------------------------*/
#define NIDIGITAL_VAL_DC_VOLTAGE                1300
#define NIDIGITAL_VAL_DC_CURRENT                1301

/*- Values for drive edge set format ---------------------------------------*/
#define NIDIGITAL_VAL_NR                        1500
#define NIDIGITAL_VAL_RL                        1501
#define NIDIGITAL_VAL_RH                        1502
#define NIDIGITAL_VAL_SBC                       1503

/*- Values for Trigger Type ------------------------------------------------*/
#define NIDIGITAL_VAL_NONE                      1700
#define NIDIGITAL_VAL_DIGITAL_EDGE              1701
#define NIDIGITAL_VAL_SOFTWARE                  1702

/*- Values for Digital Edge Attributes -------------------------------------*/
#define NIDIGITAL_VAL_RISING_EDGE               1800
#define NIDIGITAL_VAL_FALLING_EDGE              1801

/*- Values for Signals -----------------------------------------------------*/
#define NIDIGITAL_VAL_START_TRIGGER             2000
#define NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER  2001
#define NIDIGITAL_VAL_PATTERN_OPCODE_EVENT      2002
#define NIDIGITAL_VAL_REF_CLOCK                 2003

/*- Values for NIDIGITAL_ATTR_HISTORY_RAM_MAX_SAMPLES_TO_ACQUIRE_PER_SITE --*/
#define NIDIGITAL_VAL_ACQUIRE_ALL_SAMPLES       -1

/*- Values for Terminals ---------------------------------------------------*/
#define NIDIGITAL_VAL_DO_NOT_EXPORT_STR         ""
#define NIDIGITAL_VAL_PXI_TRIG0_STR             "PXI_Trig0"
#define NIDIGITAL_VAL_PXI_TRIG1_STR             "PXI_Trig1"
#define NIDIGITAL_VAL_PXI_TRIG2_STR             "PXI_Trig2"
#define NIDIGITAL_VAL_PXI_TRIG3_STR             "PXI_Trig3"
#define NIDIGITAL_VAL_PXI_TRIG4_STR             "PXI_Trig4"
#define NIDIGITAL_VAL_PXI_TRIG5_STR             "PXI_Trig5"
#define NIDIGITAL_VAL_PXI_TRIG6_STR             "PXI_Trig6"
#define NIDIGITAL_VAL_PXI_TRIG7_STR             "PXI_Trig7"

/*- Values for Pattern Opcode Event ----------------------------------------*/
#define NIDIGITAL_VAL_PATTERN_OPCODE_EVENT0     "patternOpcodeEvent0"
#define NIDIGITAL_VAL_PATTERN_OPCODE_EVENT1     "patternOpcodeEvent1"
#define NIDIGITAL_VAL_PATTERN_OPCODE_EVENT2     "patternOpcodeEvent2"
#define NIDIGITAL_VAL_PATTERN_OPCODE_EVENT3     "patternOpcodeEvent3"

/*- Values for Sequencer Flags ---------------------------------------------*/
#define NIDIGITAL_VAL_SEQUENCER_FLAG0           "seqflag0"
#define NIDIGITAL_VAL_SEQUENCER_FLAG1           "seqflag1"
#define NIDIGITAL_VAL_SEQUENCER_FLAG2           "seqflag2"
#define NIDIGITAL_VAL_SEQUENCER_FLAG3           "seqflag3"

/*- Values for Sequencer Registers -----------------------------------------*/
#define NIDIGITAL_VAL_SEQUENCER_REGISTER0       "reg0"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER1       "reg1"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER2       "reg2"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER3       "reg3"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER4       "reg4"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER5       "reg5"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER6       "reg6"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER7       "reg7"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER8       "reg8"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER9       "reg9"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER10      "reg10"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER11      "reg11"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER12      "reg12"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER13      "reg13"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER14      "reg14"
#define NIDIGITAL_VAL_SEQUENCER_REGISTER15      "reg15"

/*- Values for Conditional Jump Triggers -----------------------------------*/
#define NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER0   "conditionalJumpTrigger0"
#define NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER1   "conditionalJumpTrigger1"
#define NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER2   "conditionalJumpTrigger2"
#define NIDIGITAL_VAL_CONDITIONAL_JUMP_TRIGGER3   "conditionalJumpTrigger3"

/*- Values for NIDIGITAL_ATTR_APERTURE_TIME_UNITS --------------------------*/
#define NIDIGITAL_VAL_SECONDS                   2100

/*- Values for niDigital PPMU Measure function -----------------------------*/
#define NIDIGITAL_VAL_MEASURE_CURRENT           2400
#define NIDIGITAL_VAL_MEASURE_VOLTAGE           2401

/*- Source and Capture Memory bit order ------------------------------------*/
#define NIDIGITAL_VAL_MSB_FIRST                 2500
#define NIDIGITAL_VAL_LSB_FIRST                 2501

/* Source Memory Data Mapping ----------------------------------------------*/
#define NIDIGITAL_VAL_BROADCAST                 2600
#define NIDIGITAL_VAL_SITE_UNIQUE               2601

/*- Values for PPMU Current Limit Behavior ---------------------------------*/
#define NIDIGITAL_VAL_CURRENT_REGULATE          3100

/*- Values for Site Result Type --------------------------------------------*/
#define NIDIGITAL_VAL_PASS_FAIL                 3300
#define NIDIGITAL_VAL_CAPTURE_WAVEFORM          3301

/*- Values for HRAM Trigger Type -------------------------------------------*/
#define NIDIGITAL_VAL_FIRST_FAILURE             2200
#define NIDIGITAL_VAL_CYCLE_NUMBER              2201
#define NIDIGITAL_VAL_PATTERN_LABEL             2202

/*- Values for HRAM Cycles to Acquire --------------------------------------*/
#define NIDIGITAL_VAL_FAILED_CYCLES             2303
#define NIDIGITAL_VAL_ALL_CYCLES                2304

/*- Values for Time Set Edge -----------------------------------------------*/
#define NIDIGITAL_VAL_DRIVE_ON                  2800
#define NIDIGITAL_VAL_DRIVE_DATA                2801
#define NIDIGITAL_VAL_DRIVE_RETURN              2802
#define NIDIGITAL_VAL_DRIVE_OFF                 2803
#define NIDIGITAL_VAL_COMPARE_STROBE            2804
#define NIDIGITAL_VAL_DRIVE_DATA2               2805
#define NIDIGITAL_VAL_DRIVE_RETURN2             2806
#define NIDIGITAL_VAL_COMPARE_STROBE2           2807

/*- Values for NIDIGITAL_ATTR_TDR_ENDPOINT_TERMINATION -----------------------------*/
#define NIDIGITAL_VAL_TDR_TO_OPEN               3600
#define NIDIGITAL_VAL_TDR_TO_SHORT_TO_GROUND    3601

/*- Values for NIDIGITAL_ATTR_FREQUENCY_COUNTER_MEASUREMENT_MODE -------------------*/
#define NIDIGITAL_VAL_BANKED               3700
#define NIDIGITAL_VAL_PARALLEL             3701


/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close ---------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_init(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViSession* newVi);

ViStatus _VI_FUNC niDigital_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession* newVi);

ViStatus _VI_FUNC niDigital_close(
   ViSession vi);

/*- Session Locking --------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_LockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

ViStatus _VI_FUNC niDigital_UnlockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

/*- Utility ----------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_reset(
   ViSession vi);

ViStatus _VI_FUNC niDigital_ResetDevice(
   ViSession vi);

ViStatus _VI_FUNC niDigital_self_test(
   ViSession vi,
   ViInt16* testResult,
   ViChar testMessage[]);

/*- Error Handling ---------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_GetError(
   ViSession vi,
   ViStatus* errorCode,
   ViInt32 errorDescriptionBufferSize,
   ViChar errorDescription[]);

ViStatus _VI_FUNC niDigital_ClearError(
   ViSession vi);

ViStatus _VI_FUNC  niDigital_error_message(
   ViSession vi,
   ViStatus errorCode,
   ViChar errorMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

/*- Calibration ------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_SelfCalibrate(
   ViSession vi);

/*- Attributes -------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_GetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32* value);

ViStatus _VI_FUNC niDigital_GetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt64* value);

ViStatus _VI_FUNC niDigital_GetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViReal64* value);

ViStatus _VI_FUNC niDigital_GetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32 bufferSize,
   ViChar value[]);

ViStatus _VI_FUNC niDigital_GetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViSession* value);

ViStatus _VI_FUNC niDigital_GetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViBoolean* value);

ViStatus _VI_FUNC niDigital_SetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32 value);

ViStatus _VI_FUNC niDigital_SetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt64 value);

ViStatus _VI_FUNC niDigital_SetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViReal64 value);

ViStatus _VI_FUNC niDigital_SetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViConstString value);

ViStatus _VI_FUNC niDigital_SetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViSession value);

ViStatus _VI_FUNC niDigital_SetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViBoolean value);

ViStatus _VI_FUNC niDigital_ResetAttribute(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId);

/*- Pin Map ----------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_LoadPinMap(
   ViSession vi,
   ViConstString pinMapFilePath);

ViStatus _VI_FUNC niDigital_EnableSites(
   ViSession vi,
   ViConstString siteList);

ViStatus _VI_FUNC niDigital_DisableSites(
   ViSession vi,
   ViConstString siteList);

ViStatus _VI_FUNC niDigital_IsSiteEnabled(
   ViSession vi,
   ViConstString site,
   ViBoolean* enable);

/*- Low Level -*/
ViStatus _VI_FUNC niDigital_CreatePinMap(
   ViSession vi,
   ViConstString dutPinList,
   ViConstString systemPinList);

ViStatus _VI_FUNC niDigital_CreatePinGroup(
   ViSession vi,
   ViConstString pinGroupName,
   ViConstString pinList);

ViStatus _VI_FUNC niDigital_CreateChannelMap(
   ViSession vi,
   ViInt32 numSites);

ViStatus _VI_FUNC niDigital_MapPinToChannel(
   ViSession vi,
   ViConstString pin,
   ViInt32 site,
   ViConstString channel);

ViStatus _VI_FUNC niDigital_EndChannelMap(
   ViSession vi);

ViStatus _VI_FUNC niDigital_GetPinName(
   ViSession vi,
   ViInt32 pinIndex,
   ViInt32 nameBufferSize,
   ViChar name[]);

ViStatus _VI_FUNC niDigital_GetChannelName(
   ViSession vi,
   ViInt32 index, /* 1-based */
   ViInt32 nameBufferSize,
   ViChar name[]);

ViStatus _VI_FUNC niDigital_GetChannelNameFromString(
   ViSession vi,
   ViConstString index, /* 0-based */
   ViInt32 nameBufferSize,
   ViChar name[]);

/*- Pin Control ------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_SelectFunction(
   ViSession vi,
   ViConstString channelList,
   ViInt32 function);

/*- Static I/O -------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_ReadStatic(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   ViUInt8 data[],
   ViInt32* actualNumRead);

ViStatus _VI_FUNC niDigital_WriteStatic(
   ViSession vi,
   ViConstString channelList,
   ViUInt8 state);

/*- Clock Generator --------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_ClockGenerator_GenerateClock(
   ViSession vi,
   ViConstString channelList,
   ViReal64 frequency,
   ViBoolean selectDigitalFunction);

ViStatus _VI_FUNC niDigital_ClockGenerator_Initiate(
   ViSession vi,
   ViConstString channelList);

ViStatus _VI_FUNC niDigital_ClockGenerator_Abort(
   ViSession vi,
   ViConstString channelList);

/*- Levels and Timing ------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_LoadSpecifications(
   ViSession vi,
   ViConstString specificationsFilePath);

ViStatus _VI_FUNC niDigital_UnloadSpecifications(
   ViSession vi,
   ViConstString specificationsFilePath);

ViStatus _VI_FUNC niDigital_LoadLevels(
   ViSession vi,
   ViConstString levelsFilePath);

ViStatus _VI_FUNC niDigital_LoadTiming(
   ViSession vi,
   ViConstString timingFilePath);

ViStatus _VI_FUNC niDigital_ApplyLevelsAndTiming(
   ViSession vi,
   ViConstString siteList,
   ViConstString levelsSheet,
   ViConstString timingSheet,
   ViConstString initialStateHighPins,
   ViConstString initialStateLowPins,
   ViConstString initialStateTristatePins);

ViStatus _VI_FUNC niDigital_ConfigureVoltageLevels(
   ViSession vi,
   ViConstString channelList,
   ViReal64 vil,
   ViReal64 vih,
   ViReal64 vol,
   ViReal64 voh,
   ViReal64 vterm);

ViStatus _VI_FUNC niDigital_ConfigureActiveLoadLevels(
   ViSession vi,
   ViConstString channelList,
   ViReal64 iol,
   ViReal64 ioh,
   ViReal64 vcom);

ViStatus _VI_FUNC niDigital_ConfigureTerminationMode(
   ViSession vi,
   ViConstString channelList,
   ViInt32 mode);

ViStatus _VI_FUNC niDigital_CreateTimeSet(
   ViSession vi,
   ViConstString name);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetPeriod(
   ViSession vi,
   ViConstString timeSet,
   ViReal64 period);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetDriveEdges(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViInt32 format,
   ViReal64 driveOnEdge,
   ViReal64 driveDataEdge,
   ViReal64 driveReturnEdge,
   ViReal64 driveOffEdge);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetCompareEdgesStrobe(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViReal64 strobeEdge);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetDriveFormat(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViInt32 driveFormat);

ViStatus _VI_FUNC niDigital_DeleteAllTimeSets(
   ViSession vi);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetEdgeMultiplier(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViInt32 edgeMultiplier);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetDriveEdges2x(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViInt32 format,
   ViReal64 driveOnEdge,
   ViReal64 driveDataEdge,
   ViReal64 driveReturnEdge,
   ViReal64 driveOffEdge,
   ViReal64 driveData2Edge,
   ViReal64 driveReturn2Edge);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetCompareEdgesStrobe2x(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViReal64 strobeEdge,
   ViReal64 strobe2Edge);

ViStatus _VI_FUNC niDigital_ConfigureTimeSetEdge(
   ViSession vi,
   ViConstString pinList,
   ViConstString timeSet,
   ViInt32 edge,
   ViReal64 time);

ViStatus _VI_FUNC niDigital_GetTimeSetPeriod(
   ViSession vi,
   ViConstString timeSet,
   ViReal64* period);

ViStatus _VI_FUNC niDigital_GetTimeSetEdge(
   ViSession vi,
   ViConstString pin,
   ViConstString timeSet,
   ViInt32 edge,
   ViReal64* time);

ViStatus _VI_FUNC niDigital_GetTimeSetEdgeMultiplier(
   ViSession vi,
   ViConstString pin,
   ViConstString timeSet,
   ViInt32* edgeMultiplier);

ViStatus _VI_FUNC niDigital_GetTimeSetDriveFormat(
   ViSession vi,
   ViConstString pin,
   ViConstString timeSet,
   ViInt32* format);

ViStatus _VI_FUNC niDigital_GetTimeSetName(
   ViSession vi,
   ViInt32 timeSetIndex,
   ViInt32 nameBufferSize,
   ViChar name[]);

/*- TDR --------------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_TDR(
   ViSession vi,
   ViConstString channelList,
   ViBoolean applyOffsets,
   ViInt32 offsetsBufferSize,
   ViReal64 offsets[],
   ViInt32* actualNumOffsets);

ViStatus _VI_FUNC niDigital_ApplyTDROffsets(
   ViSession vi,
   ViConstString channelList,
   ViInt32 numOffsets,
   ViReal64 offsets[]);

/*- PPMU Configuration -----------------------------------------------------*/
ViStatus _VI_FUNC niDigital_PPMU_ConfigureOutputFunction(
   ViSession vi,
   ViConstString channelList,
   ViInt32 outputFunction);

ViStatus _VI_FUNC niDigital_PPMU_ConfigureApertureTime(
   ViSession vi,
   ViConstString channelName,
   ViReal64 apertureTime,
   ViInt32 units);

/*- DC Voltage -*/
ViStatus _VI_FUNC niDigital_PPMU_ConfigureVoltageLevel(
   ViSession vi,
   ViConstString channelList,
   ViReal64 voltageLevel);

ViStatus _VI_FUNC niDigital_PPMU_ConfigureCurrentLimit(
   ViSession vi,
   ViConstString channelList,
   ViInt32 behavior,
   ViReal64 limit);

ViStatus _VI_FUNC niDigital_PPMU_ConfigureCurrentLimitRange(
   ViSession vi,
   ViConstString channelList,
   ViReal64 range);

/*- DC Current -*/
ViStatus _VI_FUNC niDigital_PPMU_ConfigureCurrentLevel(
   ViSession vi,
   ViConstString channelList,
   ViReal64 currentLevel);

ViStatus _VI_FUNC niDigital_PPMU_ConfigureCurrentLevelRange(
   ViSession vi,
   ViConstString channelList,
   ViReal64 range);

ViStatus _VI_FUNC niDigital_PPMU_ConfigureVoltageLimits(
   ViSession vi,
   ViConstString channelList,
   ViReal64 lowerVoltageLimit,
   ViReal64 upperVoltageLimit);

/*- PPMU Action-------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_PPMU_Source(
   ViSession vi,
   ViConstString channelList);

ViStatus _VI_FUNC niDigital_PPMU_Measure(
   ViSession vi,
   ViConstString channelList,
   ViInt32 measurementType,
   ViInt32 bufferSize,
   ViReal64 measurements[],
   ViInt32* actualNumRead);

/*- Pattern Configuration --------------------------------------------------*/
ViStatus _VI_FUNC niDigital_LoadPattern(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niDigital_UnloadAllPatterns(
   ViSession vi,
   ViBoolean unloadKeepAlivePattern);

ViStatus _VI_FUNC niDigital_ConfigureStartLabel(
   ViSession vi,
   ViConstString label);

ViStatus _VI_FUNC niDigital_ConfigurePatternBurstSites(
   ViSession vi,
   ViConstString siteList);

ViStatus _VI_FUNC niDigital_GetPatternPinIndexes(
   ViSession vi,
   ViConstString startLabel,
   ViInt32 pinIndexesBufferSize,
   ViInt32 pinIndexes[],
   ViInt32* actualNumPins);

ViStatus _VI_FUNC niDigital_GetPatternPinList(
   ViSession vi,
   ViConstString startLabel,
   ViInt32 pinListBufferSize,
   ViChar pinList[]);

ViStatus _VI_FUNC niDigital_GetPatternName(
   ViSession vi,
   ViInt32 patternIndex,
   ViInt32 nameBufferSize,
   ViChar name[]);

/*- Pattern Action ---------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_BurstPattern(
   ViSession vi,
   ViConstString siteList,
   ViConstString startLabel,
   ViBoolean selectDigitalFunction,
   ViBoolean waitUntilDone,
   ViReal64 timeout);

ViStatus _VI_FUNC niDigital_BurstPatternSynchronized(
   ViUInt32 sessionCount,
   ViSession sessions[],
   ViConstString siteList,
   ViConstString startLabel,
   ViBoolean selectDigitalFunction,
   ViBoolean waitUntilDone,
   ViReal64 timeout);

/*- Low Level -*/
ViStatus _VI_FUNC niDigital_Commit(
   ViSession vi);

ViStatus _VI_FUNC niDigital_Initiate(
   ViSession vi);

ViStatus _VI_FUNC niDigital_IsDone(
   ViSession vi,
   ViBoolean* done);

ViStatus _VI_FUNC niDigital_WaitUntilDone(
   ViSession vi,
   ViReal64 timeout);

ViStatus _VI_FUNC niDigital_Abort(
   ViSession vi);

ViStatus _VI_FUNC niDigital_AbortKeepAlive(
   ViSession vi);

/*- History RAM ------------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_ConfigurePatternLabelHistoryRAMTrigger(
   ViSession vi,
   ViConstString label,
   ViInt64 vectorOffset,
   ViInt64 cycleOffset,
   ViInt32 pretriggerSamples);

ViStatus _VI_FUNC niDigital_ConfigureCycleNumberHistoryRAMTrigger(
   ViSession vi,
   ViInt64 cycleNumber,
   ViInt32 pretriggerSamples);

ViStatus _VI_FUNC niDigital_ConfigureFirstFailureHistoryRAMTrigger(
   ViSession vi,
   ViInt32 pretriggerSamples);

ViStatus _VI_FUNC niDigital_ConfigureHistoryRAMCyclesToAcquire(
   ViSession vi,
   ViInt32 cyclesToAcquire);

ViStatus _VI_FUNC niDigital_GetHistoryRAMSampleCount(
   ViSession vi,
   ViConstString site,
   ViInt64* sampleCount);

ViStatus _VI_FUNC niDigital_FetchHistoryRAMCycleInformation(
   ViSession vi,
   ViConstString site,
   ViInt64 sampleIndex,
   ViInt32* patternIndex,
   ViInt32* timeSetIndex,
   ViInt64* vectorNumber,
   ViInt64* cycleNumber,
   ViInt32* numDutCycles);

ViStatus _VI_FUNC niDigital_FetchHistoryRAMCyclePinData(
   ViSession vi,
   ViConstString site,
   ViConstString pinList,
   ViInt64 sampleIndex,
   ViInt32 dutCycleIndex,
   ViInt32 pinDataBufferSize,
   ViUInt8 expectedPinStates[],
   ViUInt8 actualPinStates[],
   ViBoolean perPinPassFail[],
   ViInt32* actualNumPinData);

ViStatus _VI_FUNC niDigital_FetchHistoryRAMScanCycleNumber(
   ViSession vi,
   ViConstString site,
   ViInt64 sampleIndex,
   ViInt64* scanCycleNumber);

/*- Source Memory ----------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_CreateSourceWaveformParallel(
   ViSession vi,
   ViConstString pinList,
   ViConstString waveformName,
   ViInt32 dataMapping);

ViStatus _VI_FUNC niDigital_CreateSourceWaveformSerial(
   ViSession vi,
   ViConstString pinList,
   ViConstString waveformName,
   ViInt32 dataMapping,
   ViUInt32 sampleWidth,
   ViInt32 bitOrder);

ViStatus _VI_FUNC niDigital_CreateSourceWaveformFromFileTDMS(
   ViSession vi,
   ViConstString waveformName,
   ViConstString waveformFilePath,
   ViBoolean writeWaveformData);

ViStatus _VI_FUNC niDigital_WriteSourceWaveformBroadcastU32(
   ViSession vi,
   ViConstString waveformName,
   ViInt32 waveformSize,
   ViUInt32 waveformData[]);

ViStatus _VI_FUNC niDigital_WriteSourceWaveformSiteUniqueU32(
   ViSession vi,
   ViConstString siteList,
   ViConstString waveformName,
   ViInt32 numWaveforms,
   ViInt32 samplesPerWaveform,
   ViUInt32 waveformData[]);

ViStatus _VI_FUNC niDigital_WriteSourceWaveformDataFromFileTDMS(
   ViSession vi,
   ViConstString waveformName,
   ViConstString waveformFilePath);

/*- Capture Memory ---------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_CreateCaptureWaveformParallel(
   ViSession vi,
   ViConstString pinList,
   ViConstString waveformName);

ViStatus _VI_FUNC niDigital_CreateCaptureWaveformSerial(
   ViSession vi,
   ViConstString pinList,
   ViConstString waveformName,
   ViUInt32 sampleWidth,
   ViInt32 bitOrder);

ViStatus _VI_FUNC niDigital_CreateCaptureWaveformFromFileDigicapture(
   ViSession vi,
   ViConstString waveformName,
   ViConstString waveformFilePath);

ViStatus _VI_FUNC niDigital_FetchCaptureWaveformU32(
   ViSession vi,
   ViConstString siteList,
   ViConstString waveformName,
   ViInt32 samplesToRead,
   ViReal64 timeout,
   ViInt32 dataBufferSize,
   ViUInt32 data[],
   ViInt32* actualNumWaveforms,
   ViInt32* actualSamplesPerWaveform);

/*- Triggers and Events ----------------------------------------------------*/
ViStatus _VI_FUNC niDigital_ExportSignal(
   ViSession      vi,
   ViInt32        signal,
   ViConstString  signalIdentifier,
   ViConstString  outputTerminal);

ViStatus _VI_FUNC niDigital_ConfigureDigitalEdgeStartTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niDigital_ConfigureSoftwareEdgeStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDigital_DisableStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niDigital_SendSoftwareEdgeTrigger(
   ViSession vi,
   ViInt32 trigger,
   ViConstString triggerIdentifier);

/*- Conditional Jump Trigger -----------------------------------------------*/
ViStatus _VI_FUNC niDigital_ConfigureDigitalEdgeConditionalJumpTrigger(
   ViSession vi,
   ViConstString triggerIdentifier,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niDigital_ConfigureSoftwareEdgeConditionalJumpTrigger(
   ViSession vi,
   ViConstString triggerIdentifier);

ViStatus _VI_FUNC niDigital_DisableConditionalJumpTrigger(
   ViSession vi,
   ViConstString triggerIdentifier);

/*- Sequencer Flag ---------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_WriteSequencerFlag(
   ViSession vi,
   ViConstString flag,
   ViBoolean value);

ViStatus _VI_FUNC niDigital_WriteSequencerFlagSynchronized(
   ViUInt32 sessionCount,
   ViSession sessions[],
   ViConstString flag,
   ViBoolean value);

ViStatus _VI_FUNC niDigital_ReadSequencerFlag(
   ViSession vi,
   ViConstString flag,
   ViBoolean* value);

/*- Sequencer Register -----------------------------------------------------*/
ViStatus _VI_FUNC niDigital_WriteSequencerRegister(
   ViSession vi,
   ViConstString reg,
   ViInt32 value);

ViStatus _VI_FUNC niDigital_ReadSequencerRegister(
   ViSession vi,
   ViConstString reg,
   ViInt32* value);

/*- Match Fail Combination -------------------------------------------------*/
ViStatus _VI_FUNC niDigital_EnableMatchFailCombination(
   ViUInt32 sessionCount,
   ViSession sessions[],
   ViSession syncSession);

/*- Pattern Results --------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_GetSitePassFail(
   ViSession vi,
   ViConstString siteList,
   ViInt32 passFailBufferSize,
   ViBoolean passFail[],
   ViInt32* actualNumSites);

ViStatus _VI_FUNC niDigital_GetFailCount(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   ViInt64 failureCount[],
   ViInt32* actualNumRead);

/*- Sort Results -----------------------------------------------------------*/
ViStatus _VI_FUNC niDigital_GetPinResultsPinInformation(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   ViInt32 pinIndexes[],
   ViInt32 siteNumbers[],
   ViInt32 channelIndexes[], /* 1-based index */
   ViInt32* actualNumValues);

ViStatus _VI_FUNC niDigital_GetSiteResultsSiteNumbers(
   ViSession vi,
   ViConstString siteList,
   ViInt32 siteResultType,
   ViInt32 siteNumbersBufferSize,
   ViInt32 siteNumbers[],
   ViInt32* actualNumSiteNumbers);

ViStatus _VI_FUNC niDigital_SortPinResultsBySiteViReal64(
   ViInt32 sessionCount,
   ViSession sessions[],
   ViConstString channelList,
   ViInt32 numResults,
   ViReal64 results[],
   ViInt32 pinIndexes[],
   ViInt32 siteNumbers[]);

ViStatus _VI_FUNC niDigital_SortPinResultsBySiteViInt64(
   ViInt32 sessionCount,
   ViSession sessions[],
   ViConstString channelList,
   ViInt32 numResults,
   ViInt64 results[],
   ViInt32 pinIndexes[],
   ViInt32 siteNumbers[]);

ViStatus _VI_FUNC niDigital_SortPinResultsBySiteViUInt8(
   ViInt32 sessionCount,
   ViSession sessions[],
   ViConstString channelList,
   ViInt32 numResults,
   ViUInt8 results[],
   ViInt32 pinIndexes[],
   ViInt32 siteNumbers[]);

ViStatus _VI_FUNC niDigital_SortSiteResultsViBoolean(
   ViInt32 sessionCount,
   ViSession sessions[],
   ViConstString siteList,
   ViInt32 siteResultType,
   ViInt32 numResults,
   ViBoolean results[],
   ViInt32 siteNumbers[],
   ViInt32* actualNumResults);

ViStatus _VI_FUNC niDigital_SortSiteResultsViUInt32Waveform(
   ViInt32 sessionCount,
   ViSession sessions[],
   ViConstString siteList,
   ViInt32 siteResultType,
   ViInt32 numWaveforms,
   ViInt32 numSamplesPerWaveform,
   ViUInt32 waveforms[],
   ViInt32 siteNumbers[],
   ViInt32* actualNumWaveforms);

/*- Frequency Measurement --------------------------------------------------*/
ViStatus _VI_FUNC niDigital_FrequencyCounter_ConfigureMeasurementTime(
   ViSession vi,
   ViConstString channelList,
   ViReal64 measurementTime);

ViStatus _VI_FUNC niDigital_FrequencyCounter_ConfigureMeasurementMode(
   ViSession vi,
   ViInt32 mode);

ViStatus _VI_FUNC niDigital_FrequencyCounter_MeasureFrequency(
   ViSession vi,
   ViConstString channelList,
   ViInt32 frequenciesBufferSize,
   ViReal64 frequencies[],
   ViInt32* actualNumFrequencies);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/

/* IVI_SPECIFIC_ERROR_BASE == 0xbffa4000 */
#define NIDIGITAL_ERROR_BASE IVI_SPECIFIC_ERROR_BASE

/* IVI_SPECIFIC_WARN_BASE == 0x3ffa4000 */
#define NIDIGITAL_WARN_BASE IVI_SPECIFIC_WARN_BASE

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* ___niDigital_niDigital_h___ */
