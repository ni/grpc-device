
/****************************************************************************
 *                                niTClk                                    *
 *--------------------------------------------------------------------------*
 *   Copyright (c) National Instruments 2003-2021.  All Rights Reserved.    *
 ****************************************************************************/

#ifndef ___niTClk_h___
#define ___niTClk_h___

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "IviVisaType.h"
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NITCLK_MAJOR_VERSION                                                                20      // Instrument driver major version
#define NITCLK_MINOR_VERSION                                                                7       // Instrument driver minor version
#define NITCLK_UPDATE_VERSION                                                               0       // Instrument driver update version


/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
#define NITCLK_ATTR_SYNC_PULSE_SOURCE                                                       1       // 1 (0x1),    ViString
#define NITCLK_ATTR_EXPORTED_SYNC_PULSE_OUTPUT_TERMINAL                                     2       // 2 (0x2),    ViString
#define NITCLK_ATTR_START_TRIGGER_MASTER_SESSION                                            3       // 3 (0x3),    ViSession
#define NITCLK_ATTR_REF_TRIGGER_MASTER_SESSION                                              4       // 4 (0x4),    ViSession
#define NITCLK_ATTR_SCRIPT_TRIGGER_MASTER_SESSION                                           5       // 5 (0x5),    ViSession
#define NITCLK_ATTR_PAUSE_TRIGGER_MASTER_SESSION                                            6       // 6 (0x6),    ViSession
#define NITCLK_ATTR_TCLK_ACTUAL_PERIOD                                                      8       // 8 (0x8),    ViReal64,   read-only
#define NITCLK_ATTR_EXPORTED_TCLK_OUTPUT_TERMINAL                                           9       // 9 (0x9),    ViString
#define NITCLK_ATTR_SYNC_PULSE_CLOCK_SOURCE                                                 10      // 10 (0xa),   ViString
#define NITCLK_ATTR_SAMPLE_CLOCK_DELAY                                                      11      // 11 (0xb),   ViReal64
#define NITCLK_ATTR_SYNC_PULSE_SENDER_SYNC_PULSE_SOURCE                                     13      // 13 (0xd),   ViString
#define NITCLK_ATTR_SEQUENCER_FLAG_MASTER_SESSION                                           16      // 16 (0x10),  ViSession
#define NITCLK_ATTR_CONDITIONAL_JUMP_TRIGGER_MASTER_SESSION                                 17      // 17 (0x11),  ViSession


/****************************************************************************
 *------------------ Attribute and Parameter Value Defines -----------------*
 ****************************************************************************/
// Values used in
//     niTClk_SynchronizeWithOptions
#define NITCLK_VAL_SYNCHRONIZE_OPTIONS_NONE                                                 0       // 0 (0x0)
#define NITCLK_VAL_SYNCHRONIZE_OPTIONS_ALLOW_TCLK_DRIFT                                     1       // 1 (0x1)

// Values used in
//     niTClk_FinishSyncPulseSenderSynchronizeWithAdjustmentType
#define NITCLK_VAL_ADJUSTMENT_TYPE_AUTO                                                     0       // 0 (0x0)
#define NITCLK_VAL_ADJUSTMENT_TYPE_TCLK_DIVISOR                                             1       // 1 (0x1)
#define NITCLK_VAL_ADJUSTMENT_TYPE_TCLK_TIMEBASE                                            2       // 2 (0x2)
#define NITCLK_VAL_ADJUSTMENT_TYPE_NONE                                                     3       // 3 (0x3)


/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/
ViStatus _VI_FUNC niTClk_ConfigureForHomogeneousTriggers(
   ViUInt32 sessionCount,
   const ViSession sessions[]);

ViStatus _VI_FUNC niTClk_Synchronize(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTclkPeriod);

ViStatus _VI_FUNC niTClk_Initiate(
   ViUInt32 sessionCount,
   const ViSession sessions[]);

ViStatus _VI_FUNC niTClk_WaitUntilDone(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 timeout);

ViStatus _VI_FUNC niTClk_GetExtendedErrorInfo(
   ViChar errorString[],
   ViUInt32 errorStringSize);

// -- Advanced Functions --
ViStatus _VI_FUNC niTClk_SynchronizeToSyncPulseSender(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime);

ViStatus _VI_FUNC niTClk_IsDone(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViBoolean* done);

ViStatus _VI_FUNC niTClk_SetupForSyncPulseSenderSynchronize(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime);

ViStatus _VI_FUNC niTClk_FinishSyncPulseSenderSynchronize(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime);

ViStatus _VI_FUNC niTClk_GetTClkMeasurementForExternalSyncPulse(
   ViSession session,
   ViReal64* measurement);

ViStatus _VI_FUNC niTClk_AdjustSyncPulseSenderTClkTimebase(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 tclkAdjustment);

ViStatus _VI_FUNC niTClk_AdjustSyncPulseSenderTClkDivisors(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 tclkAdjustment);

ViStatus _VI_FUNC niTClk_GetTClkAdjustmentForDistributedTClk(
   ViReal64 tclkPeriod,
   ViUInt32 measurementsForSenderSize,
   ViReal64 measurementsForSender[],
   ViUInt32 measurementsForReceiverSize,
   ViReal64 measurementsForReceiver[],
   ViReal64* tclkAdjustment);

ViStatus _VI_FUNC niTClk_FinishSyncPulseSenderSynchronizeWithAdjustmentType(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime,
   ViUInt32 adjustmentType);

// -- Deprecated Functions --
ViStatus _VI_FUNC niTClk_SynchronizeWithOptions(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime,
   ViUInt32 options);

ViStatus _VI_FUNC niTClk_GetTClkDriftInPPM(
   ViUInt32 sessionCount,
   const ViSession sessions[],
   ViReal64 minTime,
   ViReal64* maxTClkDriftInPPM);

// -- Set Attribute --
ViStatus _VI_FUNC niTClk_SetAttributeViString(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViConstString value);

ViStatus _VI_FUNC niTClk_SetAttributeViSession(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession value);

ViStatus _VI_FUNC niTClk_SetAttributeViReal64(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64 value);

// -- Get Attribute --
ViStatus _VI_FUNC niTClk_GetAttributeViString(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 bufSize,
   ViChar value[]);

ViStatus _VI_FUNC niTClk_GetAttributeViSession(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession* value);

ViStatus _VI_FUNC niTClk_GetAttributeViReal64(
   ViSession session,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64* value);


/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#define NITCLK_SUCCESS                                                                      0       // 0 (0x0)
#define NITCLK_ERROR_START_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                                -250001 // -250001 (-0x3d091)
#define NITCLK_ERROR_REF_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                                  -250002 // -250002 (-0x3d092)
#define NITCLK_ERROR_SCRIPT_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                               -250003 // -250003 (-0x3d093)
#define NITCLK_ERROR_PAUSE_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                                -250004 // -250004 (-0x3d094)
#define NITCLK_ERROR_START_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW                    -250005 // -250005 (-0x3d095)
#define NITCLK_ERROR_REF_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW                      -250006 // -250006 (-0x3d096)
#define NITCLK_ERROR_SCRIPT_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW                   -250007 // -250007 (-0x3d097)
#define NITCLK_ERROR_PAUSE_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW                    -250008 // -250008 (-0x3d098)
#define NITCLK_ERROR_CHAN_NAME_NOT_EMPTY                                                    -250009 // -250009 (-0x3d099)
#define NITCLK_ERROR_REF_CLK_RATE_ZERO                                                      -250010 // -250010 (-0x3d09a)
#define NITCLK_ERROR_REF_CLK_RATE_NEGATIVE                                                  -250011 // -250011 (-0x3d09b)
#define NITCLK_ERROR_UNEQUAL_REF_CLK_RATES                                                  -250012 // -250012 (-0x3d09c)
#define NITCLK_ERROR_MIN_TCLK_PERIOD_NOT_SUPPORTED                                          -250013 // -250013 (-0x3d09d)
#define NITCLK_ERROR_REF_CLK_SRC_NONE                                                       -250014 // -250014 (-0x3d09e)
#define NITCLK_ERROR_EXT_SAMP_CLK_RATE_NOT_ALSO_INT                                         -250015 // -250015 (-0x3d09f)
#define NITCLK_ERROR_CANNOT_FIND_COMMON_TCLK_PERIOD                                         -250016 // -250016 (-0x3d0a0)
#define NITCLK_ERROR_INCONSISTENT_SYNC_PULSE_CLK_SRC                                        -250017 // -250017 (-0x3d0a1)
#define NITCLK_ERROR_INCONSISTENT_REF_CLK_SRC                                               -250018 // -250018 (-0x3d0a2)
#define NITCLK_ERROR_NO_START_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS                          -250019 // -250019 (-0x3d0a3)
#define NITCLK_ERROR_NO_REF_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS                            -250020 // -250020 (-0x3d0a4)
#define NITCLK_ERROR_NO_PAUSE_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS                          -250021 // -250021 (-0x3d0a5)
#define NITCLK_ERROR_NO_SCRIPT_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS                         -250022 // -250022 (-0x3d0a6)
#define NITCLK_ERROR_MULTIPLE_START_TRIG_MASTERS                                            -250023 // -250023 (-0x3d0a7)
#define NITCLK_ERROR_TIMEOUT_NOT_SUPPORTED                                                  -250024 // -250024 (-0x3d0a8)
#define NITCLK_ERROR_OP_NOT_DONE_WITHIN_TIMEOUT                                             -250025 // -250025 (-0x3d0a9)
#define NITCLK_ERROR_MULTIPLE_SESSIONS_EXPORT_SYNC_PULSE                                    -250026 // -250026 (-0x3d0aa)
#define NITCLK_ERROR_SESSION_NOT_SUPPORTED                                                  -250027 // -250027 (-0x3d0ab)
#define NITCLK_ERROR_ZERO_SESSIONS                                                          -250028 // -250028 (-0x3d0ac)
#define NITCLK_ERROR_SESSIONS_ARRAY_NULL                                                    -250029 // -250029 (-0x3d0ad)
#define NITCLK_ERROR_SESSION_SPECIFIED_TWICE                                                -250030 // -250030 (-0x3d0ae)
#define NITCLK_ERROR_TWO_SESSIONS_FOR_ONE_DEVICE                                            -250031 // -250031 (-0x3d0af)
#define NITCLK_ERROR_SESSION_NOT_VALID                                                      -250032 // -250032 (-0x3d0b0)
#define NITCLK_ERROR_COMMIT_FAILED                                                          -250033 // -250033 (-0x3d0b1)
#define NITCLK_ERROR_INITIATE_FAILED                                                        -250034 // -250034 (-0x3d0b2)
#define NITCLK_ERROR_IS_DONE_FAILED                                                         -250035 // -250035 (-0x3d0b3)
#define NITCLK_ERROR_NULL_ERROR_STRING                                                      -250036 // -250036 (-0x3d0b4)
#define NITCLK_ERROR_ZERO_START_TRIG_MASTERS                                                -250037 // -250037 (-0x3d0b5)
#define NITCLK_ERROR_ATTRIBUTE_ID_NOT_SUPPORTED                                             -250038 // -250038 (-0x3d0b6)
#define NITCLK_ERROR_GET_ATTRIBUTE_FUNCTION_NOT_SUPPORTED_DUE_TO_DATA_TYPE                  -250039 // -250039 (-0x3d0b7)
#define NITCLK_ERROR_SET_ATTRIBUTE_FUNCTION_NOT_SUPPORTED_DUE_TO_DATA_TYPE                  -250040 // -250040 (-0x3d0b8)
#define NITCLK_ERROR_GET_ATTRIBUTE_NOT_SUPPORTED                                            -250041 // -250041 (-0x3d0b9)
#define NITCLK_ERROR_SET_ATTRIBUTE_NOT_SUPPORTED                                            -250042 // -250042 (-0x3d0ba)
#define NITCLK_ERROR_INSTRUMENT_DRIVER_CALL_FAILED                                          -250043 // -250043 (-0x3d0bb)
#define NITCLK_ERROR_EXT_SAMP_CLK_RATE_NOT_ABOVE_ZERO                                       -250044 // -250044 (-0x3d0bc)
#define NITCLK_ERROR_EXT_SAMP_CLK_RATES_UNEQUAL                                             -250045 // -250045 (-0x3d0bd)
#define NITCLK_ERROR_TRIG_MASTER_SESSION_NO_LONGER_VALID                                    -250046 // -250046 (-0x3d0be)
#define NITCLK_ERROR_MULTIPLE_SESSIONS_EXPORT_ONBOARD_REF_CLK                               -250047 // -250047 (-0x3d0bf)
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED                                           -250048 // -250048 (-0x3d0c0)
#define NITCLK_ERROR_ONE_START_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS                          -250049 // -250049 (-0x3d0c1)
#define NITCLK_ERROR_ONE_REF_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS                            -250050 // -250050 (-0x3d0c2)
#define NITCLK_ERROR_ONE_PAUSE_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS                          -250051 // -250051 (-0x3d0c3)
#define NITCLK_ERROR_ONE_SCRIPT_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS                         -250052 // -250052 (-0x3d0c4)
#define NITCLK_ERROR_ALL_BUT_ONE_START_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER             -250053 // -250053 (-0x3d0c5)
#define NITCLK_ERROR_ALL_BUT_ONE_REF_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER               -250054 // -250054 (-0x3d0c6)
#define NITCLK_ERROR_ALL_BUT_ONE_PAUSE_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER             -250055 // -250055 (-0x3d0c7)
#define NITCLK_ERROR_ALL_BUT_ONE_SCRIPT_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER            -250056 // -250056 (-0x3d0c8)
#define NITCLK_ERROR_NUM_SESSIONS_START_TRIG_CONFIGURED                                     -250057 // -250057 (-0x3d0c9)
#define NITCLK_ERROR_NUM_SESSIONS_REF_TRIG_CONFIGURED                                       -250058 // -250058 (-0x3d0ca)
#define NITCLK_ERROR_NUM_SESSIONS_PAUSE_TRIG_CONFIGURED                                     -250059 // -250059 (-0x3d0cb)
#define NITCLK_ERROR_NUM_SESSIONS_SCRIPT_TRIG_CONFIGURED                                    -250060 // -250060 (-0x3d0cc)
#define NITCLK_ERROR_SAMP_CLK_RATE_TOO_LOW                                                  -250061 // -250061 (-0x3d0cd)
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_ACQ_SESSIONS                          -250062 // -250062 (-0x3d0ce)
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_EXT_SAMP_CLK                          -250063 // -250063 (-0x3d0cf)
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_EXT_SAMP_CLK_TIMEBASE                 -250064 // -250064 (-0x3d0d0)
#define NITCLK_ERROR_MORE_THAN_ONE_REF_TRIG_MASTER                                          -250065 // -250065 (-0x3d0d1)
#define NITCLK_ERROR_ACTIVE_CHANNELS_NOT_SUPPORTED_FOR_LABVIEW                              -250066 // -250066 (-0x3d0d2)
#define NITCLK_ERROR_ACTIVE_CHANNELS_FOR_SCRIPT_TRIGGER_MASTER_FOR_LABVIEW                  -250067 // -250067 (-0x3d0d3)
#define NITCLK_ERROR_VALUE_IS_NULL                                                          -250068 // -250068 (-0x3d0d4)
#define NITCLK_ERROR_CHANNEL_NAME_FOR_SCRIPT_TRIGGER_MASTER                                 -250069 // -250069 (-0x3d0d5)
#define NITCLK_ERROR_INCOMPATIBLE_VERSIONS_OF_NITCLK_AND_INSTRUMENT_DRIVER                  -250070 // -250070 (-0x3d0d6)
#define NITCLK_ERROR_INCOMPATIBLE_VERSIONS_OF_NITCLK_AND_2_INSTRUMENT_DRIVERS               -250071 // -250071 (-0x3d0d7)
#define NITCLK_ERROR_EXT_SAMP_CLK_AND_OR_SAMP_CLK_TIMEBASE_RATE_UNMATCHED                   -250072 // -250072 (-0x3d0d8)
#define NITCLK_ERROR_INVALID_ORDERING_OF_DEVICES_LIST                                       -250073 // -250073 (-0x3d0d9)
#define NITCLK_ERROR_SESSIONS_CANNOT_BE_SYNC_DUE_TO_CONFIGURATION                           -250074 // -250074 (-0x3d0da)
#define NITCLK_ERROR_DRIVER_VERSION_DOES_NOT_SUPPORT_ATTRIBUTE                              -250075 // -250075 (-0x3d0db)
#define NITCLK_ERROR_SESSIONS_CANNOT_CONFIGURED_DUE_TO_CONFIGURATION                        -250076 // -250076 (-0x3d0dc)
#define NITCLK_ERROR_NO_SEQUENCER_FLAGS_CONFIGURED_ONE_OR_MORE_MASTERS                      -250077 // -250077 (-0x3d0dd)
#define NITCLK_ERROR_NUM_SESSIONS_SEQUENCER_FLAGS_CONFIGURED                                -250078 // -250078 (-0x3d0de)
#define NITCLK_ERROR_SEQUENCER_FLAG_MASTER_DOES_NOT_SUPPORT_TCLK                            -250079 // -250079 (-0x3d0df)
#define NITCLK_ERROR_ALL_BUT_ONE_SEQUENCER_FLAGS_CONFIGURED_AND_NONE_TRIG_NOT_MASTER        -250080 // -250080 (-0x3d0e0)
#define NITCLK_ERROR_ONE_SEQUENCER_FLAG_CONFIGURED_ONE_OR_MORE_MASTERS                      -250081 // -250081 (-0x3d0e1)
#define NITCLK_ERROR_SEQUENCER_FLAG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW                -250082 // -250082 (-0x3d0e2)
#define NITCLK_ERROR_NUMBER_OF_MEASUREMENTS_DOES_NOT_MATCH_FOR_SENDER_AND_RECEIVER          -250083 // -250083 (-0x3d0e3)
#define NITCLK_ERROR_NUMBER_OF_MEASUREMENTS_IS_ZERO                                         -250084 // -250084 (-0x3d0e4)
#define NITCLK_ERROR_MEASUREMENT_ARRAY_NULL                                                 -250085 // -250085 (-0x3d0e5)
#define NITCLK_ERROR_INVALID_ADJUSTMENT_TYPE                                                -250086 // -250086 (-0x3d0e6)
#define NITCLK_ERROR_INVALID_SYNCHRONIZE_OPTION                                             -250087 // -250087 (-0x3d0e7)
#define NITCLK_ERROR_REMOTE_SESSIONS_HAVE_DIFFERENT_SERVERS                                 -250088 // -250088 (-0x3d0e8)
#define NITCLK_ERROR_ONLY_SOME_SESSIONS_ARE_REMOTE                                          -250089 // -250089 (-0x3d0e9)
#define NITCLK_ERROR_NO_CONDITIONAL_JUMP_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS               -250090 // -250090 (-0x3d0ea)
#define NITCLK_ERROR_ONE_CONDITIONAL_JUMP_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS               -250091 // -250091 (-0x3d0eb)
#define NITCLK_ERROR_ALL_BUT_ONE_CONDITIONAL_JUMP_TRIGS_CONFIGURED_AND_NONE_TRIG_NOT_MASTER -250092 // -250092 (-0x3d0ec)
#define NITCLK_ERROR_NUM_SESSIONS_CONDITIONAL_JUMP_TRIGS_CONFIGURED                         -250093 // -250093 (-0x3d0ed)
#define NITCLK_ERROR_CONDITIONAL_JUMP_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW         -250094 // -250094 (-0x3d0ee)
#define NITCLK_ERROR_CONDITIONAL_JUMP_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                     -250095 // -250095 (-0x3d0ef)
#define NITCLK_ERROR_CHANNEL_NAME_FOR_CONDITIONAL_JUMP_TRIG_MASTER                          -250096 // -250096 (-0x3d0f0)
#define NITCLK_ERROR_ACTIVE_CHANNELS_FOR_CONDITIONAL_JUMP_TRIG_MASTER_FOR_LABVIEW           -250097 // -250097 (-0x3d0f1)
#define NITCLK_WARNING_COMMIT_RETURNED_WARNING                                              250000  // 250000 (0x3d090)
#define NITCLK_WARNING_INITIATE_RETURNED_WARNING                                            250001  // 250001 (0x3d091)
#define NITCLK_WARNING_IS_DONE_RETURNED_WARNING                                             250002  // 250002 (0x3d092)
#define NITCLK_WARNING_STRING_TRUNCATED_TO_FIT_BUFFER                                       250003  // 250003 (0x3d093)
#define NITCLK_WARNING_INSTRUMENT_DRIVER_CALL_RETURNED_WARNING                              250004  // 250004 (0x3d094)


/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* ___niTClk_h___ */
