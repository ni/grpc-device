/****************************************************************************
 *                                niScope                                   *
 *--------------------------------------------------------------------------*
 *   Copyright (c) National Instruments 2004-2022.  All Rights Reserved.    *
 *--------------------------------------------------------------------------*
 *                                                                          *
 * Title:    niScope.h                                                      *
 * Purpose:  niScope                                                        *
 *           instrument driver declarations.                                *
 *                                                                          *
 ****************************************************************************/

#ifndef __NISCOPE_HEADER
#define __NISCOPE_HEADER

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include "ivi.h"
#include "IviScope.h"
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <string.h>


#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif


/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NISCOPE_MAJOR_VERSION                                                  22                                                            // Instrument driver major version
#define NISCOPE_MINOR_VERSION                                                  500                                                           // Instrument driver minor version


/****************************************************************************
 *---------------------- Useful Macros and Defines -------------------------*
 ****************************************************************************/
/* Maximum length of a niscope function name */
#define MAX_FUNCTION_NAME_SIZE      55
/* Maximum size of an error message returned from niScope_errorHandler */
#define MAX_ERROR_DESCRIPTION       (IVI_MAX_MESSAGE_BUF_SIZE * 2 + MAX_FUNCTION_NAME_SIZE + 75)

/* This macro handles all errors and warnings returned from NI SCOPE.
   It requires two variables be declared:
      ViStatus error
      ViChar errorSource[MAX_FUNCTION_NAME_SIZE]
   and a line marked "Error:" that marks the beginning of cleanup code.
   If a function returns an error code, "error" is set to the error code
   and "errorSource" is set to the calling function's name, and execution
   skips to the "Error:" line.  Otherwise, "error" and "errorSource" store
   the location of warnings that occur, and execution proceeds normally.    */
#define handleErr(fCall) {                                           \
        int code = (fCall);                                          \
        if (code != 0) {                                             \
           const char* fCallSrc = #fCall;                            \
           const char* funcName = fCallSrc + strspn(fCallSrc, " ("); \
           size_t funcNameLen = strcspn(funcName, " (");             \
           if (funcNameLen > MAX_FUNCTION_NAME_SIZE - 1)             \
              funcNameLen = MAX_FUNCTION_NAME_SIZE - 1;              \
           if (code < 0) {                                           \
              error = code;                                          \
              strncpy(errorSource, funcName, funcNameLen);           \
              errorSource[funcNameLen] = '\0';                       \
              goto Error; }                                          \
           else if ((error == 0) && (code > 0)) {                    \
              error = code;                                          \
              strncpy(errorSource, funcName, funcNameLen);           \
              errorSource[funcNameLen] = '\0'; } } }

/* Use this macro to set a customized error elaboration for a particular function
   call.  The overwrite parameter in Ivi_SetErrorInfo is set to VI_TRUE so this
   macro will overwrite the default error elaboration that is on the error queue. */
#define niScopeCheckParm(fCall, paramPosition, errorElaboration)                        \
        if (error = (fCall), (error = (error < 0) ? (error) : VI_SUCCESS))              \
           {Ivi_SetErrorInfo(vi, VI_TRUE, error, Ivi_ParamPositionError(paramPosition), \
           errorElaboration); goto Error;} else

/* Use this macro in the same manner as above but for cases where it is not a user
   set parameter that is in error
   Let errors over-ride warnings, but if there's no error or warning don't clear the
   previous warning!  If there are TWO warnings, then the new one will take precedence. */
#define niScopeCheckErrElab(fCall,elab)                              \
   {  int tempErrorForElab = (fCall);                                \
      if (tempErrorForElab < 0)                                      \
      {                                                              \
         Ivi_SetErrorInfo(vi, VI_TRUE, tempErrorForElab, 0, elab);   \
         error = tempErrorForElab;                                   \
         goto Error;                                                 \
      }                                                              \
      else if (tempErrorForElab > 0)                                 \
      {                                                              \
         Ivi_SetErrorInfo(vi, VI_TRUE, tempErrorForElab, 0, elab);   \
         error = tempErrorForElab;                                   \
      }                                                              \
   }

/* WARNING: These are overrides of some of the IVI macros to preserve warnings.
   These changes should ONLY affect the way warnings are dealt with.  However,
   there are other functions that may erase warning messages. */
#ifdef viCheckErrElab
#undef viCheckErrElab
#define viCheckErrElab(fCall, elab)                            \
   {                                                           \
      int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab);       \
         goto Error;                                           \
      }                                                        \
      if ((error == 0) && (code > 0))                          \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab);       \
      }                                                        \
   }
#endif


/* checkErr shouldn't ignore warning messages, so this is an override of the IVI version. */
#ifdef checkErr
#undef checkErr
#define checkErr(fCall)                                        \
   {  int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         goto Error;                                           \
      }                                                        \
      else if ((error == 0) && (code > 0))                     \
      {                                                        \
         error = code;                                         \
      }                                                        \
   }
#endif


#ifdef viCheckErr
#undef viCheckErr
#define viCheckErr(fCall)                                      \
   {                                                           \
      int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL);    \
         goto Error;                                           \
      }                                                        \
      if ((error == 0) && (code > 0))                          \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL);    \
      }                                                        \
   }
#endif


/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
 /*- NOTE: multi channel denotes an attribute specified on a per channel basis -*/

// -- User Options --
#define NISCOPE_ATTR_CACHE                                                     IVI_ATTR_CACHE                                                // 1050004 (0x100594), ViBoolean
#define NISCOPE_ATTR_RANGE_CHECK                                               IVI_ATTR_RANGE_CHECK                                          // 1050002 (0x100592), ViBoolean
#define NISCOPE_ATTR_QUERY_INSTRUMENT_STATUS                                   IVI_ATTR_QUERY_INSTRUMENT_STATUS                              // 1050003 (0x100593), ViBoolean
#define NISCOPE_ATTR_RECORD_COERCIONS                                          IVI_ATTR_RECORD_COERCIONS                                     // 1050006 (0x100596), ViBoolean
#define NISCOPE_ATTR_SIMULATE                                                  IVI_ATTR_SIMULATE                                             // 1050005 (0x100595), ViBoolean
#define NISCOPE_ATTR_INTERCHANGE_CHECK                                         IVI_ATTR_INTERCHANGE_CHECK                                    // 1050021 (0x1005a5), ViBoolean

// -- Instrument Capabilities --
#define NISCOPE_ATTR_CHANNEL_COUNT                                             IVI_ATTR_CHANNEL_COUNT                                        // 1050203 (0x10065b), ViInt32,    read-only
#define NISCOPE_ATTR_SUPPORTED_INSTRUMENT_MODELS                               IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS                          // 1050327 (0x1006d7), ViString,   read-only
#define NISCOPE_ATTR_GROUP_CAPABILITIES                                        IVI_ATTR_GROUP_CAPABILITIES                                   // 1050401 (0x100721), ViString,   read-only

// -- Instrument Version And Identification --
#define NISCOPE_ATTR_SPECIFIC_DRIVER_DESCRIPTION                               IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION                          // 1050514 (0x100792), ViString,   read-only
#define NISCOPE_ATTR_SPECIFIC_DRIVER_PREFIX                                    IVI_ATTR_SPECIFIC_DRIVER_PREFIX                               // 1050302 (0x1006be), ViString,   read-only
#define NISCOPE_ATTR_SPECIFIC_DRIVER_VENDOR                                    IVI_ATTR_SPECIFIC_DRIVER_VENDOR                               // 1050513 (0x100791), ViString,   read-only
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION                  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION             // 1050515 (0x100793), ViInt32,    read-only
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION                  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION             // 1050516 (0x100794), ViInt32,    read-only
#define NISCOPE_ATTR_SPECIFIC_DRIVER_REVISION                                  IVI_ATTR_SPECIFIC_DRIVER_REVISION                             // 1050551 (0x1007b7), ViString,   read-only
#define NISCOPE_ATTR_INSTRUMENT_MANUFACTURER                                   IVI_ATTR_INSTRUMENT_MANUFACTURER                              // 1050511 (0x10078f), ViString,   read-only
#define NISCOPE_ATTR_INSTRUMENT_MODEL                                          IVI_ATTR_INSTRUMENT_MODEL                                     // 1050512 (0x100790), ViString,   read-only
#define NISCOPE_ATTR_INSTRUMENT_FIRMWARE_REVISION                              IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION                         // 1050510 (0x10078e), ViString,   read-only

// -- Advanced Session Information --
#define NISCOPE_ATTR_IO_RESOURCE_DESCRIPTOR                                    IVI_ATTR_IO_RESOURCE_DESCRIPTOR                               // 1050304 (0x1006c0), ViString,   read-only
#define NISCOPE_ATTR_LOGICAL_NAME                                              IVI_ATTR_LOGICAL_NAME                                         // 1050305 (0x1006c1), ViString,   read-only
#define NISCOPE_ATTR_DRIVER_SETUP                                              IVI_ATTR_DRIVER_SETUP                                         // 1050007 (0x100597), ViString,   read-only

// -- Acquisition Subsystem --
#define NISCOPE_ATTR_ACQUISITION_TYPE                                          IVISCOPE_ATTR_ACQUISITION_TYPE                                // 1250101 (0x131335), ViInt32
#define NISCOPE_ATTR_SAMPLE_MODE                                               IVISCOPE_ATTR_SAMPLE_MODE                                     // 1250106 (0x13133a), ViInt32,    read-only

// -- Vertical Subsystem --
#define NISCOPE_ATTR_CHANNEL_ENABLED                                           IVISCOPE_ATTR_CHANNEL_ENABLED                                 // 1250005 (0x1312d5), ViBoolean,  multi-channel
#define NISCOPE_ATTR_PROBE_ATTENUATION                                         IVISCOPE_ATTR_PROBE_ATTENUATION                               // 1250004 (0x1312d4), ViReal64,   multi-channel
#define NISCOPE_ATTR_VERTICAL_RANGE                                            IVISCOPE_ATTR_VERTICAL_RANGE                                  // 1250001 (0x1312d1), ViReal64,   multi-channel
#define NISCOPE_ATTR_VERTICAL_OFFSET                                           IVISCOPE_ATTR_VERTICAL_OFFSET                                 // 1250002 (0x1312d2), ViReal64,   multi-channel
#define NISCOPE_ATTR_VERTICAL_COUPLING                                         IVISCOPE_ATTR_VERTICAL_COUPLING                               // 1250003 (0x1312d3), ViInt32,    multi-channel
#define NISCOPE_ATTR_MAX_INPUT_FREQUENCY                                       IVISCOPE_ATTR_MAX_INPUT_FREQUENCY                             // 1250006 (0x1312d6), ViReal64,   multi-channel
#define NISCOPE_ATTR_INPUT_IMPEDANCE                                           IVISCOPE_ATTR_INPUT_IMPEDANCE                                 // 1250103 (0x131337), ViReal64,   multi-channel

// -- Horizontal Subsystem --
#define NISCOPE_ATTR_HORZ_TIME_PER_RECORD                                      IVISCOPE_ATTR_HORZ_TIME_PER_RECORD                            // 1250007 (0x1312d7), ViReal64
#define NISCOPE_ATTR_ACQUISITION_START_TIME                                    IVISCOPE_ATTR_ACQUISITION_START_TIME                          // 1250109 (0x13133d), ViReal64
#define NISCOPE_ATTR_HORZ_MIN_NUM_PTS                                          IVISCOPE_ATTR_HORZ_MIN_NUM_PTS                                // 1250009 (0x1312d9), ViInt32
#define NISCOPE_ATTR_HORZ_RECORD_LENGTH                                        IVISCOPE_ATTR_HORZ_RECORD_LENGTH                              // 1250008 (0x1312d8), ViInt32,    read-only
#define NISCOPE_ATTR_HORZ_RECORD_REF_POSITION                                  (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)                            // 1250011 (0x1312db), ViReal64
#define NISCOPE_ATTR_HORZ_SAMPLE_RATE                                          IVISCOPE_ATTR_HORZ_SAMPLE_RATE                                // 1250010 (0x1312da), ViReal64,   read-only

// -- Trigger Subsystem --
#define NISCOPE_ATTR_TRIGGER_TYPE                                              IVISCOPE_ATTR_TRIGGER_TYPE                                    // 1250012 (0x1312dc), ViInt32
#define NISCOPE_ATTR_TRIGGER_SOURCE                                            IVISCOPE_ATTR_TRIGGER_SOURCE                                  // 1250013 (0x1312dd), ViString
#define NISCOPE_ATTR_TRIGGER_LEVEL                                             IVISCOPE_ATTR_TRIGGER_LEVEL                                   // 1250017 (0x1312e1), ViReal64
#define NISCOPE_ATTR_TRIGGER_DELAY_TIME                                        (IVI_CLASS_PUBLIC_ATTR_BASE + 15L)                            // 1250015 (0x1312df), ViReal64
#define NISCOPE_ATTR_TRIGGER_HOLDOFF                                           IVISCOPE_ATTR_TRIGGER_HOLDOFF                                 // 1250016 (0x1312e0), ViReal64
#define NISCOPE_ATTR_TRIGGER_COUPLING                                          IVISCOPE_ATTR_TRIGGER_COUPLING                                // 1250014 (0x1312de), ViInt32
#define NISCOPE_ATTR_TRIGGER_SLOPE                                             IVISCOPE_ATTR_TRIGGER_SLOPE                                   // 1250018 (0x1312e2), ViInt32

// -- Iviscopetvtrigger Extension --
#define NISCOPE_ATTR_TV_TRIGGER_EVENT                                          IVISCOPE_ATTR_TV_TRIGGER_EVENT                                // 1250205 (0x13139d), ViInt32
#define NISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER                                    IVISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER                          // 1250206 (0x13139e), ViInt32
#define NISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT                                  IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT                        // 1250201 (0x131399), ViInt32
#define NISCOPE_ATTR_TV_TRIGGER_POLARITY                                       IVISCOPE_ATTR_TV_TRIGGER_POLARITY                             // 1250204 (0x13139c), ViInt32

// -- Iviscopeglitchtrigger Extension --
#define NISCOPE_ATTR_GLITCH_CONDITION                                          IVISCOPE_ATTR_GLITCH_CONDITION                                // 1250403 (0x131463), ViInt32
#define NISCOPE_ATTR_GLITCH_WIDTH                                              IVISCOPE_ATTR_GLITCH_WIDTH                                    // 1250401 (0x131461), ViReal64
#define NISCOPE_ATTR_GLITCH_POLARITY                                           IVISCOPE_ATTR_GLITCH_POLARITY                                 // 1250402 (0x131462), ViInt32

// -- Iviscopewidthtrigger Extension --
#define NISCOPE_ATTR_WIDTH_CONDITION                                           IVISCOPE_ATTR_WIDTH_CONDITION                                 // 1250504 (0x1314c8), ViInt32
#define NISCOPE_ATTR_WIDTH_LOW_THRESHOLD                                       IVISCOPE_ATTR_WIDTH_LOW_THRESHOLD                             // 1250501 (0x1314c5), ViReal64
#define NISCOPE_ATTR_WIDTH_HIGH_THRESHOLD                                      IVISCOPE_ATTR_WIDTH_HIGH_THRESHOLD                            // 1250502 (0x1314c6), ViReal64
#define NISCOPE_ATTR_WIDTH_POLARITY                                            IVISCOPE_ATTR_WIDTH_POLARITY                                  // 1250503 (0x1314c7), ViInt32

// -- Iviscoperunttrigger Extension --
#define NISCOPE_ATTR_RUNT_POLARITY                                             IVISCOPE_ATTR_RUNT_POLARITY                                   // 1250303 (0x1313ff), ViInt32
#define NISCOPE_ATTR_RUNT_LOW_THRESHOLD                                        IVISCOPE_ATTR_RUNT_LOW_THRESHOLD                              // 1250302 (0x1313fe), ViReal64
#define NISCOPE_ATTR_RUNT_HIGH_THRESHOLD                                       IVISCOPE_ATTR_RUNT_HIGH_THRESHOLD                             // 1250301 (0x1313fd), ViReal64

// -- Measurement Functions --
#define NISCOPE_ATTR_MEAS_HIGH_REF                                             IVISCOPE_ATTR_MEAS_HIGH_REF                                   // 1250607 (0x13152f), ViReal64
#define NISCOPE_ATTR_MEAS_LOW_REF                                              IVISCOPE_ATTR_MEAS_LOW_REF                                    // 1250608 (0x131530), ViReal64
#define NISCOPE_ATTR_MEAS_MID_REF                                              IVISCOPE_ATTR_MEAS_MID_REF                                    // 1250609 (0x131531), ViReal64

// -- Additional Instrument-Specific Attributes --
#define NISCOPE_ATTR_HORZ_NUM_RECORDS                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)                          // 1150001 (0x118c31), ViInt32
#define NISCOPE_ATTR_INPUT_CLOCK_SOURCE                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)                          // 1150002 (0x118c32), ViString
#define NISCOPE_ATTR_OUTPUT_CLOCK_SOURCE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)                          // 1150003 (0x118c33), ViString
#define NISCOPE_ATTR_HORZ_ENFORCE_REALTIME                                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)                          // 1150004 (0x118c34), ViBoolean
#define NISCOPE_ATTR_BINARY_SAMPLE_WIDTH                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)                          // 1150005 (0x118c35), ViInt32
#define NISCOPE_ATTR_TRIGGER_HYSTERESIS                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)                          // 1150006 (0x118c36), ViReal64
#define NISCOPE_ATTR_CLOCK_SYNC_PULSE_SOURCE                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)                          // 1150007 (0x118c37), ViString
#define NISCOPE_ATTR_MASTER_ENABLE                                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)                          // 1150008 (0x118c38), ViBoolean
#define NISCOPE_ATTR_MIN_SAMPLE_RATE                                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)                          // 1150009 (0x118c39), ViReal64
#define NISCOPE_ATTR_TRIGGER_WINDOW_MODE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)                         // 1150012 (0x118c3c), ViInt32
#define NISCOPE_ATTR_TRIGGER_WINDOW_LOW_LEVEL                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)                         // 1150013 (0x118c3d), ViReal64
#define NISCOPE_ATTR_TRIGGER_WINDOW_HIGH_LEVEL                                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)                         // 1150014 (0x118c3e), ViReal64
#define NISCOPE_ATTR_MEAS_REF_LEVEL_UNITS                                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)                         // 1150016 (0x118c40), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_OTHER_CHANNEL                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)                         // 1150018 (0x118c42), ViString,   multi-channel
#define NISCOPE_ATTR_MEAS_HYSTERESIS_PERCENT                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)                         // 1150019 (0x118c43), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_LAST_ACQ_HISTOGRAM_SIZE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)                         // 1150020 (0x118c44), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_SIZE                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)                         // 1150021 (0x118c45), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_LOW_VOLTS                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)                         // 1150022 (0x118c46), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_HIGH_VOLTS                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)                         // 1150023 (0x118c47), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_SIZE                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)                         // 1150024 (0x118c48), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_VOLTS                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)                         // 1150025 (0x118c49), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_VOLTS                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)                         // 1150026 (0x118c4a), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_TIME                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)                         // 1150027 (0x118c4b), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_TIME                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)                         // 1150028 (0x118c4c), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_POLYNOMIAL_INTERPOLATION_ORDER                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)                         // 1150029 (0x118c4d), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_INTERPOLATION_SAMPLING_FACTOR                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)                         // 1150030 (0x118c4e), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_CUTOFF_FREQ                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)                         // 1150031 (0x118c4f), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_CENTER_FREQ                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)                         // 1150032 (0x118c50), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_RIPPLE                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)                         // 1150033 (0x118c51), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_TRANSIENT_WAVEFORM_PERCENT                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)                         // 1150034 (0x118c52), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_TYPE                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)                         // 1150035 (0x118c53), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_ORDER                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)                         // 1150036 (0x118c54), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_TAPS                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)                         // 1150037 (0x118c55), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_CHAN_LOW_REF_LEVEL                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)                         // 1150038 (0x118c56), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_CHAN_MID_REF_LEVEL                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)                         // 1150039 (0x118c57), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_CHAN_HIGH_REF_LEVEL                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)                         // 1150040 (0x118c58), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FILTER_WIDTH                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)                         // 1150041 (0x118c59), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_FIR_FILTER_WINDOW                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)                         // 1150042 (0x118c5a), ViInt32,    multi-channel
#define NISCOPE_ATTR_MEAS_ARRAY_GAIN                                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)                         // 1150043 (0x118c5b), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_ARRAY_OFFSET                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)                         // 1150044 (0x118c5c), ViReal64,   multi-channel
#define NISCOPE_ATTR_MEAS_PERCENTAGE_METHOD                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)                         // 1150045 (0x118c5d), ViInt32,    multi-channel

// -- Advanced Synchronization Attributes --
#define NISCOPE_ATTR_ACQ_ARM_SOURCE                                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L)                         // 1150053 (0x118c65), ViString
#define NISCOPE_ATTR_IS_PROBE_COMP_ON                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 66L)                         // 1150066 (0x118c72), ViBoolean,  read-only
#define NISCOPE_ATTR_USE_SPEC_INITIAL_X                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)                         // 1150067 (0x118c73), ViBoolean
#define NISCOPE_ATTR_ALLOW_MORE_RECORDS_THAN_MEMORY                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)                         // 1150068 (0x118c74), ViBoolean
#define NISCOPE_ATTR_ONBOARD_MEMORY_SIZE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)                         // 1150069 (0x118c75), ViInt32,    read-only
#define NISCOPE_ATTR_RIS_NUM_AVERAGES                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)                         // 1150070 (0x118c76), ViInt32
#define NISCOPE_ATTR_RIS_METHOD                                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)                         // 1150071 (0x118c77), ViInt32
#define NISCOPE_ATTR_FETCH_INTERLEAVED_DATA                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)                         // 1150072 (0x118c78), ViBoolean
#define NISCOPE_ATTR_MAX_REAL_TIME_SAMPLING_RATE                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)                         // 1150073 (0x118c79), ViReal64,   read-only
#define NISCOPE_ATTR_MAX_RIS_RATE                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)                         // 1150074 (0x118c7a), ViReal64,   read-only
#define NISCOPE_ATTR_TRIGGER_IMPEDANCE                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)                         // 1150075 (0x118c7b), ViReal64
#define NISCOPE_ATTR_DEVICE_NUMBER                                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)                         // 1150076 (0x118c7c), ViInt32,    read-only
#define NISCOPE_ATTR_FETCH_RELATIVE_TO                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)                         // 1150077 (0x118c7d), ViInt32
#define NISCOPE_ATTR_FETCH_OFFSET                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)                         // 1150078 (0x118c7e), ViInt32
#define NISCOPE_ATTR_FETCH_RECORD_NUMBER                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)                         // 1150079 (0x118c7f), ViInt32
#define NISCOPE_ATTR_FETCH_NUM_RECORDS                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)                         // 1150080 (0x118c80), ViInt32
#define NISCOPE_ATTR_FETCH_MEAS_NUM_SAMPLES                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)                         // 1150081 (0x118c81), ViInt32
#define NISCOPE_ATTR_POINTS_DONE                                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)                         // 1150082 (0x118c82), ViReal64,   read-only
#define NISCOPE_ATTR_RECORDS_DONE                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)                         // 1150083 (0x118c83), ViInt32,    read-only
#define NISCOPE_ATTR_BACKLOG                                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 84L)                         // 1150084 (0x118c84), ViReal64,   read-only
#define NISCOPE_ATTR_POLL_INTERVAL                                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L)                        // 1150100 (0x118c94), ViInt32
#define NISCOPE_ATTR_PLL_LOCK_STATUS                                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1303L)                       // 1151303 (0x119147), ViBoolean,  read-only

// -- New Attributes For Ni-Scope 2.5 --
#define NISCOPE_ATTR_DEVICE_TEMPERATURE                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86L)                         // 1150086 (0x118c86), ViReal64,   read-only
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_SRC                                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87L)                         // 1150087 (0x118c87), ViString
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_RATE                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88L)                         // 1150088 (0x118c88), ViReal64
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_DIV                                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89L)                         // 1150089 (0x118c89), ViInt32
#define NISCOPE_ATTR_REF_CLK_RATE                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90L)                         // 1150090 (0x118c8a), ViReal64
#define NISCOPE_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91L)                         // 1150091 (0x118c8b), ViString
#define NISCOPE_ATTR_ENABLE_DC_RESTORE                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93L)                         // 1150093 (0x118c8d), ViBoolean
#define NISCOPE_ATTR_ADV_TRIG_SRC                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94L)                         // 1150094 (0x118c8e), ViString
#define NISCOPE_ATTR_ARM_REF_TRIG_SRC                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95L)                         // 1150095 (0x118c8f), ViString
#define NISCOPE_ATTR_REF_TRIG_TDC_ENABLE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96L)                         // 1150096 (0x118c90), ViBoolean
#define NISCOPE_ATTR_RESOLUTION                                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L)                        // 1150102 (0x118c96), ViInt32,    read-only

// -- New Attributes For Ni-Scope 2.6 --
#define NISCOPE_ATTR_START_TO_REF_TRIGGER_HOLDOFF                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L)                        // 1150103 (0x118c97), ViReal64

// -- New Attributes For Ni-Scope 2.7 --
#define NISCOPE_ATTR_SERIAL_NUMBER                                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L)                        // 1150104 (0x118c98), ViString,   read-only
#define NISCOPE_ATTR_OSCILLATOR_PHASE_DAC_VALUE                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L)                        // 1150105 (0x118c99), ViInt32

// -- New Attributes For Ni-Scope 2.8 --
#define NISCOPE_ATTR_RIS_IN_AUTO_SETUP_ENABLE                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L)                        // 1150106 (0x118c9a), ViBoolean
#define NISCOPE_ATTR_CHANNEL_TERMINAL_CONFIGURATION                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L)                        // 1150107 (0x118c9b), ViInt32,    multi-channel
#define NISCOPE_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109L)                        // 1150109 (0x118c9d), ViString
#define NISCOPE_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L)                        // 1150110 (0x118c9e), ViString
#define NISCOPE_ATTR_READY_FOR_REF_EVENT_OUTPUT_TERMINAL                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L)                        // 1150111 (0x118c9f), ViString
#define NISCOPE_ATTR_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L)                        // 1150112 (0x118ca0), ViString

// -- New Attributes For Ni-Scope 2.9.1 --
#define NISCOPE_ATTR_FLEX_FIR_ANTIALIAS_FILTER_TYPE                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271L)                        // 1150271 (0x118d3f), ViInt32,    multi-channel

// -- New Attributes For Ni-Scope 3.0. Attributes For The Ni 5142 & 5622 Osp Functionality. --
#define NISCOPE_ATTR_DDC_ENABLED                                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 300L)                        // 1150300 (0x118d5c), ViBoolean,  multi-channel
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 302L)                        // 1150302 (0x118d5e), ViBoolean,  multi-channel
#define NISCOPE_ATTR_DDC_CENTER_FREQUENCY                                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 303L)                        // 1150303 (0x118d5f), ViReal64,   multi-channel
#define NISCOPE_ATTR_DDC_DATA_PROCESSING_MODE                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 304L)                        // 1150304 (0x118d60), ViInt32
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_I                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 305L)                        // 1150305 (0x118d61), ViReal64,   multi-channel
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_Q                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 306L)                        // 1150306 (0x118d62), ViReal64,   multi-channel
#define NISCOPE_ATTR_DIGITAL_GAIN                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 307L)                        // 1150307 (0x118d63), ViReal64,   multi-channel
#define NISCOPE_ATTR_DIGITAL_OFFSET                                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 308L)                        // 1150308 (0x118d64), ViReal64,   multi-channel
#define NISCOPE_ATTR_OVERFLOW_ERROR_REPORTING                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 309L)                        // 1150309 (0x118d65), ViInt32
#define NISCOPE_ATTR_DDC_Q_SOURCE                                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 310L)                        // 1150310 (0x118d66), ViString,   multi-channel
#define NISCOPE_ATTR_FETCH_INTERLEAVED_IQ_DATA                                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 311L)                        // 1150311 (0x118d67), ViBoolean

// -- New Attributes For Ni-Scope 3.1. --
#define NISCOPE_ATTR_EQUALIZATION_NUM_COEFFICIENTS                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312L)                        // 1150312 (0x118d68), ViInt32,    multi-channel, read-only
#define NISCOPE_ATTR_EQUALIZATION_FILTER_ENABLED                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 313L)                        // 1150313 (0x118d69), ViBoolean,  multi-channel
#define NISCOPE_ATTR_REF_TRIGGER_DETECTOR_LOCATION                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 314L)                        // 1150314 (0x118d6a), ViInt32
#define NISCOPE_ATTR_REF_TRIGGER_MINIMUM_QUIET_TIME                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 315L)                        // 1150315 (0x118d6b), ViReal64

// -- New Attributes For Ni-Scope 3.2 --
#define NISCOPE_ATTR_ENABLE_TIME_INTERLEAVED_SAMPLING                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)                        // 1150128 (0x118cb0), ViBoolean,  multi-channel

// -- New Attributes For Ni-Scope 3.3 --
#define NISCOPE_ATTR_DATA_TRANSFER_BLOCK_SIZE                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316L)                        // 1150316 (0x118d6c), ViInt32

// -- New Attributes For Ni-Scope 3.4 --
#define NISCOPE_ATTR_TRIGGER_MODIFIER                                          IVISCOPE_ATTR_TRIGGER_MODIFIER                                // 1250102 (0x131336), ViInt32
#define NISCOPE_ATTR_TRIGGER_AUTO_TRIGGERED                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 278L)                        // 1150278 (0x118d46), ViBoolean,  read-only
#define NISCOPE_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 97L)                         // 1150097 (0x118c91), ViString
#define NISCOPE_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)                         // 1150098 (0x118c92), ViString
#define NISCOPE_ATTR_END_OF_RECORD_EVENT_OUTPUT_TERMINAL                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)                         // 1150099 (0x118c93), ViString
#define NISCOPE_ATTR_END_OF_ACQUISITION_EVENT_OUTPUT_TERMINAL                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L)                        // 1150101 (0x118c95), ViString
#define NISCOPE_ATTR_5V_OUT_OUTPUT_TERMINAL                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L)                        // 1150129 (0x118cb1), ViString

// -- New Attributes For Ni-Scope 3.5 --
#define NISCOPE_ATTR_BANDPASS_FILTER_ENABLED                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 318L)                        // 1150318 (0x118d6e), ViBoolean,  multi-channel
#define NISCOPE_ATTR_DITHER_ENABLED                                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 319L)                        // 1150319 (0x118d6f), ViBoolean,  multi-channel
#define NISCOPE_ATTR_FRACTIONAL_RESAMPLE_ENABLED                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320L)                        // 1150320 (0x118d70), ViBoolean
#define NISCOPE_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L)                        // 1150321 (0x118d71), ViReal64
#define NISCOPE_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L)                        // 1150322 (0x118d72), ViInt32

// -- Ni-5900 Specific Definitions --
#define NISCOPE_ATTR_SIGNAL_COND_GAIN                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 279L)                        // 1150279 (0x118d47), ViReal64,   multi-channel, read-only
#define NISCOPE_ATTR_SIGNAL_COND_OFFSET                                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 280L)                        // 1150280 (0x118d48), ViReal64,   multi-channel, read-only

// -- New Attributes For Ni-Scope 3.6, Peer-To-Peer --
#define NISCOPE_ATTR_P2P_ENABLED                                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 338L)                        // 1150338 (0x118d82), ViBoolean
#define NISCOPE_ATTR_P2P_CHANNELS_TO_STREAM                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 339L)                        // 1150339 (0x118d83), ViString
#define NISCOPE_ATTR_P2P_ENDPOINT_SIZE                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 342L)                        // 1150342 (0x118d86), ViInt32,    read-only
#define NISCOPE_ATTR_P2P_SAMPLES_AVAIL_IN_ENDPOINT                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 328L)                        // 1150328 (0x118d78), ViInt32,    read-only
#define NISCOPE_ATTR_P2P_MOST_SAMPLES_AVAIL_IN_ENDPOINT                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 341L)                        // 1150341 (0x118d85), ViInt32,    read-only
#define NISCOPE_ATTR_P2P_SAMPLES_TRANSFERRED                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 340L)                        // 1150340 (0x118d84), ViInt64,    read-only
#define NISCOPE_ATTR_P2P_ENDPOINT_OVERFLOW                                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 344L)                        // 1150344 (0x118d88), ViBoolean,  read-only
#define NISCOPE_ATTR_P2P_FIFO_ENDPOINT_COUNT                                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 345L)                        // 1150345 (0x118d89), ViInt32,    read-only
#define NISCOPE_ATTR_P2P_ONBOARD_MEMORY_ENABLED                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 354L)                        // 1150354 (0x118d92), ViBoolean
#define NISCOPE_ATTR_P2P_MANUAL_CONFIGURATION_ENABLED                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 343L)                        // 1150343 (0x118d87), ViBoolean
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 329L)                        // 1150329 (0x118d79), ViInt64,    read-only
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR_TYPE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 330L)                        // 1150330 (0x118d7a), ViInt32
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 331L)                        // 1150331 (0x118d7b), ViInt64
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR_TYPE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 332L)                        // 1150332 (0x118d7c), ViInt32
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_SIZE                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 333L)                        // 1150333 (0x118d7d), ViInt64
#define NISCOPE_ATTR_P2P_NOTIFY_PUSH_MESSAGE_ON                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 334L)                        // 1150334 (0x118d7e), ViInt32
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 335L)                        // 1150335 (0x118d7f), ViInt64
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 336L)                        // 1150336 (0x118d80), ViInt32
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_VALUE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 337L)                        // 1150337 (0x118d81), ViInt64

// -- New Attributes For Ni-Scope 3.8 --
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_MULT                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 367L)                        // 1150367 (0x118d9f), ViInt32

// -- New Attributes For Ni-Scope 4.0, Peer-To-Peer --
#define NISCOPE_ATTR_P2P_STREAM_RELATIVE_TO                                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 373L)                        // 1150373 (0x118da5), ViInt32
#define NISCOPE_ATTR_P2P_SAMPLES_TRANSFERRED_PER_RECORD                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 380L)                        // 1150380 (0x118dac), ViInt32,    read-only

// -- New Attributes For Ni-Scope 4.2 --
#define NISCOPE_ATTR_END_OF_RECORD_TO_ADVANCE_TRIGGER_HOLDOFF                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 366L)                        // 1150366 (0x118d9e), ViReal64

// -- New Attributes For Ni-Scope 15.1 --
#define NISCOPE_ATTR_ABSOLUTE_SAMPLE_CLOCK_OFFSET                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 374L)                        // 1150374 (0x118da6), ViReal64
#define NISCOPE_ATTR_FPGA_BITFILE_PATH                                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 375L)                        // 1150375 (0x118da7), ViString,   read-only

// -- New Attributes For Ni-Scope 16.1 --
#define NISCOPE_ATTR_INTERLEAVING_OFFSET_CORRECTION_ENABLED                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 376L)                        // 1150376 (0x118da8), ViBoolean,  multi-channel
#define NISCOPE_ATTR_HIGH_PASS_FILTER_FREQUENCY                                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 377L)                        // 1150377 (0x118da9), ViReal64,   multi-channel

// -- New Attributes For Ni-Scope 18.6 --
#define NISCOPE_ATTR_RUNT_TIME_CONDITION                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 132L)                        // 1150132 (0x118cb4), ViInt32
#define NISCOPE_ATTR_RUNT_TIME_LOW_LIMIT                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 133L)                        // 1150133 (0x118cb5), ViReal64
#define NISCOPE_ATTR_RUNT_TIME_HIGH_LIMIT                                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 134L)                        // 1150134 (0x118cb6), ViReal64

// -- New Attributes For Ni-Scope 18.7 --
#define NISCOPE_ATTR_CABLE_SENSE_VOLTAGE                                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 137L)                        // 1150137 (0x118cb9), ViReal64
#define NISCOPE_ATTR_CABLE_SENSE_MODE                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 138L)                        // 1150138 (0x118cba), ViReal64
#define NISCOPE_ATTR_CABLE_SENSE_SIGNAL_ENABLE                                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 139L)                        // 1150139 (0x118cbb), ViBoolean

// -- New Attributes For Ni-Scope 19.0 --
#define NISCOPE_ATTR_ENABLED_CHANNELS                                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 140L)                        // 1150140 (0x118cbc), ViString,   read-only

// -- New Attributes For Ni-Scope 20.0 --
#define NISCOPE_ATTR_END_OF_ACQUISITION_EVENT_TERMINAL_NAME                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 141L)                        // 1150141 (0x118cbd), ViString,   read-only
#define NISCOPE_ATTR_END_OF_RECORD_EVENT_TERMINAL_NAME                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 142L)                        // 1150142 (0x118cbe), ViString,   read-only
#define NISCOPE_ATTR_ADVANCE_TRIGGER_TERMINAL_NAME                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 143L)                        // 1150143 (0x118cbf), ViString,   read-only
#define NISCOPE_ATTR_REF_TRIGGER_TERMINAL_NAME                                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 144L)                        // 1150144 (0x118cc0), ViString,   read-only
#define NISCOPE_ATTR_START_TRIGGER_TERMINAL_NAME                               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 145L)                        // 1150145 (0x118cc1), ViString,   read-only
#define NISCOPE_ATTR_READY_FOR_ADVANCE_EVENT_TERMINAL_NAME                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 146L)                        // 1150146 (0x118cc2), ViString,   read-only
#define NISCOPE_ATTR_READY_FOR_REF_EVENT_TERMINAL_NAME                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 147L)                        // 1150147 (0x118cc3), ViString,   read-only
#define NISCOPE_ATTR_READY_FOR_START_EVENT_TERMINAL_NAME                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 148L)                        // 1150148 (0x118cc4), ViString,   read-only


/****************************************************************************
 *------------------ Attribute and Parameter Value Defines -----------------*
 ****************************************************************************/
// Values used in
//     NISCOPE_ATTR_RIS_METHOD
#define NISCOPE_VAL_RIS_EXACT_NUM_AVERAGES                                     1                                                             // 1 (0x1)
#define NISCOPE_VAL_RIS_MIN_NUM_AVERAGES                                       2                                                             // 2 (0x2)
#define NISCOPE_VAL_RIS_INCOMPLETE                                             3                                                             // 3 (0x3)
#define NISCOPE_VAL_RIS_LIMITED_BIN_WIDTH                                      5                                                             // 5 (0x5)

// Values used in
//     niScope_SendSoftwareTriggerEdge
#define NISCOPE_VAL_SOFTWARE_TRIGGER_START                                     0                                                             // 0 (0x0)
#define NISCOPE_VAL_SOFTWARE_TRIGGER_ARM_REFERENCE                             1                                                             // 1 (0x1)
#define NISCOPE_VAL_SOFTWARE_TRIGGER_REFERENCE                                 2                                                             // 2 (0x2)
#define NISCOPE_VAL_SOFTWARE_TRIGGER_ADVANCE                                   3                                                             // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_VERTICAL_COUPLING, niScope_ConfigureVertical
#define NISCOPE_VAL_AC                                                         IVISCOPE_VAL_AC                                               // 0 (0x0)
#define NISCOPE_VAL_DC                                                         IVISCOPE_VAL_DC                                               // 1 (0x1)
#define NISCOPE_VAL_GND                                                        IVISCOPE_VAL_GND                                              // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_MAX_INPUT_FREQUENCY
#define NISCOPE_VAL_BANDWIDTH_FULL                                             -1.0
#define NISCOPE_VAL_BANDWIDTH_DEVICE_DEFAULT                                   0.0
#define NISCOPE_VAL_20MHZ_BANDWIDTH                                            20000000.0
#define NISCOPE_VAL_100MHZ_BANDWIDTH                                           100000000.0
#define NISCOPE_VAL_20MHZ_MAX_INPUT_FREQUENCY                                  20000000.0
#define NISCOPE_VAL_100MHZ_MAX_INPUT_FREQUENCY                                 100000000.0

// Values used in
//     NISCOPE_ATTR_INPUT_IMPEDANCE
#define NISCOPE_VAL_50_OHMS                                                    50.0
#define NISCOPE_VAL_75_OHMS                                                    75.0
#define NISCOPE_VAL_1_MEG_OHM                                                  1000000.0

// Values used in
//     NISCOPE_ATTR_TRIGGER_TYPE
#define NISCOPE_VAL_EDGE_TRIGGER                                               IVISCOPE_VAL_EDGE_TRIGGER                                     // 1 (0x1)
#define NISCOPE_VAL_HYSTERESIS_TRIGGER                                         (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 1L)            // 1001 (0x3e9)
#define NISCOPE_VAL_DIGITAL_TRIGGER                                            (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 2L)            // 1002 (0x3ea)
#define NISCOPE_VAL_WINDOW_TRIGGER                                             (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 3L)            // 1003 (0x3eb)
#define NISCOPE_VAL_SOFTWARE_TRIGGER                                           (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 4L)            // 1004 (0x3ec)
#define NISCOPE_VAL_TV_TRIGGER                                                 IVISCOPE_VAL_TV_TRIGGER                                       // 5 (0x5)
#define NISCOPE_VAL_GLITCH_TRIGGER                                             IVISCOPE_VAL_GLITCH_TRIGGER                                   // 4 (0x4)
#define NISCOPE_VAL_WIDTH_TRIGGER                                              IVISCOPE_VAL_WIDTH_TRIGGER                                    // 2 (0x2)
#define NISCOPE_VAL_RUNT_TRIGGER                                               IVISCOPE_VAL_RUNT_TRIGGER                                     // 3 (0x3)
#define NISCOPE_VAL_IMMEDIATE_TRIGGER                                          IVISCOPE_VAL_IMMEDIATE_TRIGGER                                // 6 (0x6)

// Values used in
//     NISCOPE_ATTR_TRIGGER_SOURCE
#define NISCOPE_VAL_IMMEDIATE                                                  "VAL_IMMEDIATE"
#define NISCOPE_VAL_EXTERNAL                                                   IVISCOPE_VAL_EXTERNAL
#define NISCOPE_VAL_SW_TRIG_FUNC                                               "VAL_SW_TRIG_FUNC"
#define NISCOPE_VAL_TTL0                                                       IVISCOPE_VAL_TTL0
#define NISCOPE_VAL_TTL1                                                       IVISCOPE_VAL_TTL1
#define NISCOPE_VAL_TTL2                                                       IVISCOPE_VAL_TTL2
#define NISCOPE_VAL_TTL3                                                       IVISCOPE_VAL_TTL3
#define NISCOPE_VAL_TTL4                                                       IVISCOPE_VAL_TTL4
#define NISCOPE_VAL_TTL5                                                       IVISCOPE_VAL_TTL5
#define NISCOPE_VAL_TTL6                                                       IVISCOPE_VAL_TTL6
#define NISCOPE_VAL_TTL7                                                       IVISCOPE_VAL_TTL7
#define NISCOPE_VAL_ECL0                                                       IVISCOPE_VAL_ECL0
#define NISCOPE_VAL_ECL1                                                       IVISCOPE_VAL_ECL1
#define NISCOPE_VAL_PXI_STAR                                                   IVISCOPE_VAL_PXI_STAR
#define NISCOPE_VAL_RTSI_0                                                     IVISCOPE_VAL_RTSI_0
#define NISCOPE_VAL_RTSI_1                                                     IVISCOPE_VAL_RTSI_1
#define NISCOPE_VAL_RTSI_2                                                     IVISCOPE_VAL_RTSI_2
#define NISCOPE_VAL_RTSI_3                                                     IVISCOPE_VAL_RTSI_3
#define NISCOPE_VAL_RTSI_4                                                     IVISCOPE_VAL_RTSI_4
#define NISCOPE_VAL_RTSI_5                                                     IVISCOPE_VAL_RTSI_5
#define NISCOPE_VAL_RTSI_6                                                     IVISCOPE_VAL_RTSI_6
#define NISCOPE_VAL_RTSI_7                                                     "VAL_RTSI_7"
#define NISCOPE_VAL_PFI_0                                                      "VAL_PFI_0"
#define NISCOPE_VAL_PFI_1                                                      "VAL_PFI_1"
#define NISCOPE_VAL_PFI_2                                                      "VAL_PFI_2"
#define NISCOPE_VAL_PFI_3                                                      "VAL_PFI_3"
#define NISCOPE_VAL_PFI_4                                                      "VAL_PFI_4"
#define NISCOPE_VAL_PFI_5                                                      "VAL_PFI_5"
#define NISCOPE_VAL_PFI_6                                                      "VAL_PFI_6"
#define NISCOPE_VAL_PFI_7                                                      "VAL_PFI_7"
#define NISCOPE_VAL_AUX_0_PFI_0                                                "VAL_AUX_0_PFI_0"
#define NISCOPE_VAL_AUX_0_PFI_1                                                "VAL_AUX_0_PFI_1"
#define NISCOPE_VAL_AUX_0_PFI_3                                                "VAL_AUX_0_PFI_3"
#define NISCOPE_VAL_AUX_0_PFI_4                                                "VAL_AUX_0_PFI_4"
#define NISCOPE_VAL_AUX_0_PFI_5                                                "VAL_AUX_0_PFI_5"
#define NISCOPE_VAL_AUX_0_PFI_6                                                "VAL_AUX_0_PFI_6"
#define NISCOPE_VAL_AUX_0_PFI_7                                                "VAL_AUX_0_PFI_7"
#define NISCOPE_VAL_AUX_0_PFI_2                                                "VAL_AUX_0_PFI_2"

// Values used in
//     NISCOPE_ATTR_FETCH_RELATIVE_TO
#define NISCOPE_VAL_READ_POINTER                                               388                                                           // 388 (0x184)
#define NISCOPE_VAL_PRETRIGGER                                                 477                                                           // 477 (0x1dd)
#define NISCOPE_VAL_NOW                                                        481                                                           // 481 (0x1e1)
#define NISCOPE_VAL_START                                                      482                                                           // 482 (0x1e2)
#define NISCOPE_VAL_TRIGGER                                                    483                                                           // 483 (0x1e3)

// Values used in
//     NISCOPE_ATTR_TRIGGER_MODIFIER
#define NISCOPE_VAL_NO_TRIGGER_MOD                                             IVISCOPE_VAL_NO_TRIGGER_MOD                                   // 1 (0x1)
#define NISCOPE_VAL_AUTO                                                       IVISCOPE_VAL_AUTO                                             // 2 (0x2)
#define NISCOPE_VAL_AUTO_LEVEL                                                 IVISCOPE_VAL_AUTO_LEVEL                                       // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_TRIGGER_COUPLING, niScope_ConfigureTriggerEdge, niScope_ConfigureTriggerGlitch,
//     niScope_ConfigureTriggerHysteresis, niScope_ConfigureTriggerRunt, niScope_ConfigureTriggerVideo,
//     niScope_ConfigureTriggerWidth, niScope_ConfigureTriggerWindow
// #define NISCOPE_VAL_AC                                                      DEFINED ABOVE (IVISCOPE_VAL_AC)                               // 0 (0x0)
// #define NISCOPE_VAL_DC                                                      DEFINED ABOVE (IVISCOPE_VAL_DC)                               // 1 (0x1)
#define NISCOPE_VAL_HF_REJECT                                                  IVISCOPE_VAL_HF_REJECT                                        // 3 (0x3)
#define NISCOPE_VAL_LF_REJECT                                                  IVISCOPE_VAL_LF_REJECT                                        // 4 (0x4)
#define NISCOPE_VAL_AC_PLUS_HF_REJECT                                          (IVISCOPE_VAL_TRIGGER_COUPLING_SPECIFIC_EXT_BASE + 1L)        // 1001 (0x3e9)

// Values used in
//     NISCOPE_ATTR_TRIGGER_SLOPE, niScope_ConfigureTriggerDigital, niScope_ConfigureTriggerEdge,
//     niScope_ConfigureTriggerHysteresis
#define NISCOPE_VAL_NEGATIVE                                                   IVISCOPE_VAL_NEGATIVE                                         // 0 (0x0)
#define NISCOPE_VAL_POSITIVE                                                   IVISCOPE_VAL_POSITIVE                                         // 1 (0x1)
#define NISCOPE_VAL_SLOPE_EITHER                                               3                                                             // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_ACQUISITION_TYPE
#define NISCOPE_VAL_NORMAL                                                     IVISCOPE_VAL_NORMAL                                           // 0 (0x0)
#define NISCOPE_VAL_FLEXRES                                                    (IVISCOPE_VAL_ACQUISITION_TYPE_SPECIFIC_EXT_BASE + 1L)        // 1001 (0x3e9)
#define NISCOPE_VAL_DDC                                                        (IVISCOPE_VAL_ACQUISITION_TYPE_SPECIFIC_EXT_BASE + 2L)        // 1002 (0x3ea)

// Interpolation
#define NISCOPE_VAL_NO_INTERPOLATION                                           IVISCOPE_VAL_NO_INTERPOLATION                                 // 1 (0x1)
#define NISCOPE_VAL_SINE_X                                                     IVISCOPE_VAL_SINE_X                                           // 2 (0x2)
#define NISCOPE_VAL_LINEAR                                                     IVISCOPE_VAL_LINEAR                                           // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT
#define NISCOPE_VAL_NTSC                                                       IVISCOPE_VAL_NTSC                                             // 1 (0x1)
#define NISCOPE_VAL_PAL                                                        IVISCOPE_VAL_PAL                                              // 2 (0x2)
#define NISCOPE_VAL_SECAM                                                      IVISCOPE_VAL_SECAM                                            // 3 (0x3)
#define NISCOPE_VAL_M_PAL                                                      (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 1L)        // 1001 (0x3e9)
#define NISCOPE_VAL_480I_59_94_FIELDS_PER_SECOND                               (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 10L)       // 1010 (0x3f2)
#define NISCOPE_VAL_480I_60_FIELDS_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 11L)       // 1011 (0x3f3)
#define NISCOPE_VAL_480P_59_94_FRAMES_PER_SECOND                               (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 15L)       // 1015 (0x3f7)
#define NISCOPE_VAL_480P_60_FRAMES_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 16L)       // 1016 (0x3f8)
#define NISCOPE_VAL_576I_50_FIELDS_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 20L)       // 1020 (0x3fc)
#define NISCOPE_VAL_576P_50_FRAMES_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 25L)       // 1025 (0x401)
#define NISCOPE_VAL_720P_50_FRAMES_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 31L)       // 1031 (0x407)
#define NISCOPE_VAL_720P_59_94_FRAMES_PER_SECOND                               (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 32L)       // 1032 (0x408)
#define NISCOPE_VAL_720P_60_FRAMES_PER_SECOND                                  (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 33L)       // 1033 (0x409)
#define NISCOPE_VAL_1080I_50_FIELDS_PER_SECOND                                 (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 40L)       // 1040 (0x410)
#define NISCOPE_VAL_1080I_59_94_FIELDS_PER_SECOND                              (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 41L)       // 1041 (0x411)
#define NISCOPE_VAL_1080I_60_FIELDS_PER_SECOND                                 (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 42L)       // 1042 (0x412)
#define NISCOPE_VAL_1080P_24_FRAMES_PER_SECOND                                 (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 45L)       // 1045 (0x415)

// Values used in
//     NISCOPE_ATTR_TV_TRIGGER_POLARITY, niScope_ConfigureTriggerVideo
#define NISCOPE_VAL_TV_POSITIVE                                                IVISCOPE_VAL_TV_POSITIVE                                      // 1 (0x1)
#define NISCOPE_VAL_TV_NEGATIVE                                                IVISCOPE_VAL_TV_NEGATIVE                                      // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_TV_TRIGGER_EVENT, niScope_ConfigureTriggerVideo
#define NISCOPE_VAL_TV_EVENT_FIELD1                                            IVISCOPE_VAL_TV_EVENT_FIELD1                                  // 1 (0x1)
#define NISCOPE_VAL_TV_EVENT_FIELD2                                            IVISCOPE_VAL_TV_EVENT_FIELD2                                  // 2 (0x2)
#define NISCOPE_VAL_TV_EVENT_ANY_FIELD                                         IVISCOPE_VAL_TV_EVENT_ANY_FIELD                               // 3 (0x3)
#define NISCOPE_VAL_TV_EVENT_ANY_LINE                                          IVISCOPE_VAL_TV_EVENT_ANY_LINE                                // 4 (0x4)
#define NISCOPE_VAL_TV_EVENT_LINE_NUMBER                                       IVISCOPE_VAL_TV_EVENT_LINE_NUMBER                             // 5 (0x5)

// Values used in
//     NISCOPE_ATTR_GLITCH_CONDITION, niScope_ConfigureTriggerGlitch
#define NISCOPE_VAL_GLITCH_GREATER_THAN                                        IVISCOPE_VAL_GLITCH_GREATER_THAN                              // 2 (0x2)
#define NISCOPE_VAL_GLITCH_LESS_THAN                                           IVISCOPE_VAL_GLITCH_LESS_THAN                                 // 1 (0x1)

// Values used in
//     NISCOPE_ATTR_GLITCH_POLARITY, niScope_ConfigureTriggerGlitch
#define NISCOPE_VAL_GLITCH_POSITIVE                                            IVISCOPE_VAL_GLITCH_POSITIVE                                  // 1 (0x1)
#define NISCOPE_VAL_GLITCH_NEGATIVE                                            IVISCOPE_VAL_GLITCH_NEGATIVE                                  // 2 (0x2)
#define NISCOPE_VAL_GLITCH_EITHER                                              IVISCOPE_VAL_GLITCH_EITHER                                    // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_WIDTH_CONDITION, niScope_ConfigureTriggerWidth
#define NISCOPE_VAL_WIDTH_WITHIN                                               IVISCOPE_VAL_WIDTH_WITHIN                                     // 1 (0x1)
#define NISCOPE_VAL_WIDTH_OUTSIDE                                              IVISCOPE_VAL_WIDTH_OUTSIDE                                    // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_WIDTH_POLARITY, niScope_ConfigureTriggerWidth
#define NISCOPE_VAL_WIDTH_POSITIVE                                             IVISCOPE_VAL_WIDTH_POSITIVE                                   // 1 (0x1)
#define NISCOPE_VAL_WIDTH_NEGATIVE                                             IVISCOPE_VAL_WIDTH_NEGATIVE                                   // 2 (0x2)
#define NISCOPE_VAL_WIDTH_EITHER                                               IVISCOPE_VAL_WIDTH_EITHER                                     // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_RUNT_POLARITY, niScope_ConfigureTriggerRunt
#define NISCOPE_VAL_RUNT_POSITIVE                                              IVISCOPE_VAL_RUNT_POSITIVE                                    // 1 (0x1)
#define NISCOPE_VAL_RUNT_NEGATIVE                                              IVISCOPE_VAL_RUNT_NEGATIVE                                    // 2 (0x2)
#define NISCOPE_VAL_RUNT_EITHER                                                IVISCOPE_VAL_RUNT_EITHER                                      // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_RUNT_TIME_CONDITION
#define NISCOPE_VAL_RUNT_TIME_CONDITION_NONE                                   0                                                             // 0 (0x0)
#define NISCOPE_VAL_RUNT_TIME_CONDITION_WITHIN                                 1                                                             // 1 (0x1)
#define NISCOPE_VAL_RUNT_TIME_CONDITION_OUTSIDE                                2                                                             // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_CABLE_SENSE_MODE
#define NISCOPE_VAL_CABLE_SENSE_MODE_DISABLED                                  0                                                             // 0 (0x0)
#define NISCOPE_VAL_CABLE_SENSE_MODE_ON_DEMAND                                 1                                                             // 1 (0x1)

// Values used in
//     NISCOPE_ATTR_SAMPLE_MODE
#define NISCOPE_VAL_REAL_TIME                                                  IVISCOPE_VAL_REAL_TIME                                        // 0 (0x0)
#define NISCOPE_VAL_EQUIVALENT_TIME                                            IVISCOPE_VAL_EQUIVALENT_TIME                                  // 1 (0x1)

// Values used in
//     niScope_ConfigureClock, niScope_ExportSignal
#define NISCOPE_VAL_NO_SOURCE                                                  "VAL_NO_SOURCE"
#define NISCOPE_VAL_RTSI_CLOCK                                                 "VAL_RTSI_CLOCK"
// #define NISCOPE_VAL_EXTERNAL                                                DEFINED ABOVE (IVISCOPE_VAL_EXTERNAL)                        
// #define NISCOPE_VAL_PFI_0                                                   DEFINED ABOVE ("VAL_PFI_0")                                  
// #define NISCOPE_VAL_PFI_1                                                   DEFINED ABOVE ("VAL_PFI_1")                                  
// #define NISCOPE_VAL_PFI_2                                                   DEFINED ABOVE ("VAL_PFI_2")                                  
#define NISCOPE_VAL_CLK_IN                                                     "VAL_CLK_IN"
#define NISCOPE_VAL_CLK_OUT                                                    "VAL_CLK_OUT"
#define NISCOPE_VAL_INTERNAL10MHZ_OSC                                          "VAL_INTERNAL10MHZ_OSC"
#define NISCOPE_VAL_PXI_CLK                                                    "VAL_PXI_CLK"
#define NISCOPE_VAL_PXI_CLK10                                                  "VAL_PXI_CLK10"
#define NISCOPE_VAL_PXI_CLK100                                                 "VAL_PXI_CLK100"
#define NISCOPE_VAL_PXIE_DSTAR_A                                               "VAL_PXIE_DSTAR_A"
#define NISCOPE_VAL_AUX_0_CLK_IN                                               "VAL_AUX_0_CLK_IN"
#define NISCOPE_VAL_AUX_0_CLK_OUT                                              "VAL_AUX_0_CLK_OUT"
#define NISCOPE_VAL_ONBOARD_CONFIGURABLE_RATE_CLK                              "VAL_ONBOARD_CONFIGURABLE_RATE_CLK"

// Values used in
//     NISCOPE_ATTR_SAMP_CLK_TIMEBASE_SRC
// #define NISCOPE_VAL_CLK_IN                                                  DEFINED ABOVE ("VAL_CLK_IN")                                 
// #define NISCOPE_VAL_NO_SOURCE                                               DEFINED ABOVE ("VAL_NO_SOURCE")                              
// #define NISCOPE_VAL_PXI_STAR                                                DEFINED ABOVE (IVISCOPE_VAL_PXI_STAR)                        
// #define NISCOPE_VAL_PXIE_DSTAR_A                                            DEFINED ABOVE ("VAL_PXIE_DSTAR_A")                           
// #define NISCOPE_VAL_AUX_0_CLK_IN                                            DEFINED ABOVE ("VAL_AUX_0_CLK_IN")                           
// #define NISCOPE_VAL_ONBOARD_CONFIGURABLE_RATE_CLK                           DEFINED ABOVE ("VAL_ONBOARD_CONFIGURABLE_RATE_CLK")          

// Values used in
//     niScope_ExportSignal
#define NISCOPE_VAL_REF_TRIGGER                                                1                                                             // 1 (0x1)
#define NISCOPE_VAL_START_TRIGGER                                              2                                                             // 2 (0x2)
#define NISCOPE_VAL_END_OF_ACQUISITION_EVENT                                   3                                                             // 3 (0x3)
#define NISCOPE_VAL_END_OF_RECORD_EVENT                                        4                                                             // 4 (0x4)
#define NISCOPE_VAL_ADVANCE_TRIGGER                                            5                                                             // 5 (0x5)
#define NISCOPE_VAL_READY_FOR_ADVANCE_EVENT                                    6                                                             // 6 (0x6)
#define NISCOPE_VAL_READY_FOR_START_EVENT                                      7                                                             // 7 (0x7)
#define NISCOPE_VAL_READY_FOR_REF_EVENT                                        10                                                            // 10 (0xa)
#define NISCOPE_VAL_5V_OUT                                                     13                                                            // 13 (0xd)
#define NISCOPE_VAL_REF_CLOCK                                                  100                                                           // 100 (0x64)
#define NISCOPE_VAL_SAMPLE_CLOCK                                               101                                                           // 101 (0x65)

// Values used in
//     NISCOPE_ATTR_TRIGGER_WINDOW_MODE, niScope_ConfigureTriggerWindow
#define NISCOPE_VAL_ENTERING_WINDOW                                            0                                                             // 0 (0x0)
#define NISCOPE_VAL_LEAVING_WINDOW                                             1                                                             // 1 (0x1)
#define NISCOPE_VAL_ENTERING_OR_LEAVING_WINDOW                                 2                                                             // 2 (0x2)

// Max Time
#define NISCOPE_VAL_MAX_TIME_INFINITE                                          0xFFFFFFFFUL                                                  // 4294967295 (0xffffffff)
#define NISCOPE_VAL_MAX_TIME_IMMEDIATE                                         0                                                             // 0 (0x0)
#define NISCOPE_VAL_MAX_TIME_NONE                                              0                                                             // 0 (0x0)

// Values used in
//     niScope_AcquisitionStatus
#define NISCOPE_VAL_ACQ_COMPLETE                                               IVISCOPE_VAL_ACQ_COMPLETE                                     // 1 (0x1)
#define NISCOPE_VAL_ACQ_IN_PROGRESS                                            IVISCOPE_VAL_ACQ_IN_PROGRESS                                  // 0 (0x0)
#define NISCOPE_VAL_ACQ_STATUS_UNKNOWN                                         IVISCOPE_VAL_ACQ_STATUS_UNKNOWN                               // -1 (-0x1)

// Values used in
//     NISCOPE_ATTR_MEAS_FILTER_TYPE
#define NISCOPE_VAL_MEAS_LOWPASS                                               0                                                             // 0 (0x0)
#define NISCOPE_VAL_MEAS_HIGHPASS                                              1                                                             // 1 (0x1)
#define NISCOPE_VAL_MEAS_BANDPASS                                              2                                                             // 2 (0x2)
#define NISCOPE_VAL_MEAS_BANDSTOP                                              3                                                             // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_MEAS_PERCENTAGE_METHOD
#define NISCOPE_VAL_MEAS_LOW_HIGH                                              0                                                             // 0 (0x0)
#define NISCOPE_VAL_MEAS_MIN_MAX                                               1                                                             // 1 (0x1)
#define NISCOPE_VAL_MEAS_BASE_TOP                                              2                                                             // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_MEAS_REF_LEVEL_UNITS
#define NISCOPE_VAL_MEAS_VOLTAGE                                               0                                                             // 0 (0x0)
#define NISCOPE_VAL_MEAS_PERCENTAGE                                            1                                                             // 1 (0x1)

// Values used in
//     niScope_FetchMeasurement, niScope_FetchMeasurementStats, niScope_ReadMeasurement
#define NISCOPE_VAL_NO_MEASUREMENT                                             4000                                                          // 4000 (0xfa0)
#define NISCOPE_VAL_RISE_TIME                                                  IVISCOPE_VAL_RISE_TIME                                        // 0 (0x0)
#define NISCOPE_VAL_FALL_TIME                                                  IVISCOPE_VAL_FALL_TIME                                        // 1 (0x1)
#define NISCOPE_VAL_FREQUENCY                                                  IVISCOPE_VAL_FREQUENCY                                        // 2 (0x2)
#define NISCOPE_VAL_PERIOD                                                     IVISCOPE_VAL_PERIOD                                           // 3 (0x3)
#define NISCOPE_VAL_VOLTAGE_RMS                                                IVISCOPE_VAL_VOLTAGE_RMS                                      // 4 (0x4)
#define NISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK                                       IVISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK                             // 5 (0x5)
#define NISCOPE_VAL_VOLTAGE_MAX                                                IVISCOPE_VAL_VOLTAGE_MAX                                      // 6 (0x6)
#define NISCOPE_VAL_VOLTAGE_MIN                                                IVISCOPE_VAL_VOLTAGE_MIN                                      // 7 (0x7)
#define NISCOPE_VAL_VOLTAGE_HIGH                                               IVISCOPE_VAL_VOLTAGE_HIGH                                     // 8 (0x8)
#define NISCOPE_VAL_VOLTAGE_LOW                                                IVISCOPE_VAL_VOLTAGE_LOW                                      // 9 (0x9)
#define NISCOPE_VAL_VOLTAGE_AVERAGE                                            IVISCOPE_VAL_VOLTAGE_AVERAGE                                  // 10 (0xa)
#define NISCOPE_VAL_WIDTH_NEG                                                  IVISCOPE_VAL_WIDTH_NEG                                        // 11 (0xb)
#define NISCOPE_VAL_WIDTH_POS                                                  IVISCOPE_VAL_WIDTH_POS                                        // 12 (0xc)
#define NISCOPE_VAL_DUTY_CYCLE_NEG                                             IVISCOPE_VAL_DUTY_CYCLE_NEG                                   // 13 (0xd)
#define NISCOPE_VAL_DUTY_CYCLE_POS                                             IVISCOPE_VAL_DUTY_CYCLE_POS                                   // 14 (0xe)
#define NISCOPE_VAL_AMPLITUDE                                                  IVISCOPE_VAL_AMPLITUDE                                        // 15 (0xf)
#define NISCOPE_VAL_VOLTAGE_CYCLE_RMS                                          IVISCOPE_VAL_VOLTAGE_CYCLE_RMS                                // 16 (0x10)
#define NISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE                                      IVISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE                            // 17 (0x11)
#define NISCOPE_VAL_OVERSHOOT                                                  IVISCOPE_VAL_OVERSHOOT                                        // 18 (0x12)
#define NISCOPE_VAL_PRESHOOT                                                   IVISCOPE_VAL_PRESHOOT                                         // 19 (0x13)
#define NISCOPE_VAL_LOW_REF_VOLTS                                              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 0L)    // 1000 (0x3e8)
#define NISCOPE_VAL_MID_REF_VOLTS                                              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1L)    // 1001 (0x3e9)
#define NISCOPE_VAL_HIGH_REF_VOLTS                                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2L)    // 1002 (0x3ea)
#define NISCOPE_VAL_AREA                                                       (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 3L)    // 1003 (0x3eb)
#define NISCOPE_VAL_CYCLE_AREA                                                 (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 4L)    // 1004 (0x3ec)
#define NISCOPE_VAL_INTEGRAL                                                   (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 5L)    // 1005 (0x3ed)
#define NISCOPE_VAL_VOLTAGE_BASE                                               (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 6L)    // 1006 (0x3ee)
#define NISCOPE_VAL_VOLTAGE_TOP                                                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 7L)    // 1007 (0x3ef)
#define NISCOPE_VAL_FFT_FREQUENCY                                              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 8L)    // 1008 (0x3f0)
#define NISCOPE_VAL_FFT_AMPLITUDE                                              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 9L)    // 1009 (0x3f1)
#define NISCOPE_VAL_RISE_SLEW_RATE                                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 10L)   // 1010 (0x3f2)
#define NISCOPE_VAL_FALL_SLEW_RATE                                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 11L)   // 1011 (0x3f3)
#define NISCOPE_VAL_AC_ESTIMATE                                                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 12L)   // 1012 (0x3f4)
#define NISCOPE_VAL_DC_ESTIMATE                                                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 13L)   // 1013 (0x3f5)
#define NISCOPE_VAL_TIME_DELAY                                                 (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 14L)   // 1014 (0x3f6)
#define NISCOPE_VAL_AVERAGE_PERIOD                                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 15L)   // 1015 (0x3f7)
#define NISCOPE_VAL_AVERAGE_FREQUENCY                                          (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 16L)   // 1016 (0x3f8)
#define NISCOPE_VAL_VOLTAGE_BASE_TO_TOP                                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 17L)   // 1017 (0x3f9)
#define NISCOPE_VAL_PHASE_DELAY                                                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 18L)   // 1018 (0x3fa)

// Voltage Histogram
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN                                     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1000L) // 2000 (0x7d0)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_STDEV                                    (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1001L) // 2001 (0x7d1)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_PEAK_TO_PEAK                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1002L) // 2002 (0x7d2)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEDIAN                                   (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1003L) // 2003 (0x7d3)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_HITS                                     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1004L) // 2004 (0x7d4)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MAX                                      (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1005L) // 2005 (0x7d5)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MIN                                      (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1006L) // 2006 (0x7d6)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_STDEV                          (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1007L) // 2007 (0x7d7)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_2_STDEV                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1008L) // 2008 (0x7d8)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_3_STDEV                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1009L) // 2009 (0x7d9)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MODE                                     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1010L) // 2010 (0x7da)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_NEW_HITS                                 (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1011L) // 2011 (0x7db)

// Time Histogram
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN                                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2000L) // 3000 (0xbb8)
#define NISCOPE_VAL_TIME_HISTOGRAM_STDEV                                       (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2001L) // 3001 (0xbb9)
#define NISCOPE_VAL_TIME_HISTOGRAM_PEAK_TO_PEAK                                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2002L) // 3002 (0xbba)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEDIAN                                      (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2003L) // 3003 (0xbbb)
#define NISCOPE_VAL_TIME_HISTOGRAM_HITS                                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2004L) // 3004 (0xbbc)
#define NISCOPE_VAL_TIME_HISTOGRAM_MAX                                         (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2005L) // 3005 (0xbbd)
#define NISCOPE_VAL_TIME_HISTOGRAM_MIN                                         (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2006L) // 3006 (0xbbe)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_STDEV                             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2007L) // 3007 (0xbbf)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_2_STDEV                           (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2008L) // 3008 (0xbc0)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_3_STDEV                           (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2009L) // 3009 (0xbc1)
#define NISCOPE_VAL_TIME_HISTOGRAM_MODE                                        (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2010L) // 3010 (0xbc2)
#define NISCOPE_VAL_TIME_HISTOGRAM_NEW_HITS                                    (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2011L) // 3011 (0xbc3)

// Values used in
//     niScope_ActualMeasWfmSize, niScope_AddWaveformProcessing, niScope_FetchArrayMeasurement
// #define NISCOPE_VAL_NO_MEASUREMENT                                          DEFINED ABOVE (4000)                                          // 4000 (0xfa0)
#define NISCOPE_VAL_LAST_ACQ_HISTOGRAM                                         4001                                                          // 4001 (0xfa1)
#define NISCOPE_VAL_FFT_PHASE_SPECTRUM                                         4002                                                          // 4002 (0xfa2)
#define NISCOPE_VAL_FFT_AMP_SPECTRUM_VOLTS_RMS                                 4003                                                          // 4003 (0xfa3)
#define NISCOPE_VAL_MULTI_ACQ_VOLTAGE_HISTOGRAM                                4004                                                          // 4004 (0xfa4)
#define NISCOPE_VAL_MULTI_ACQ_TIME_HISTOGRAM                                   4005                                                          // 4005 (0xfa5)
#define NISCOPE_VAL_ARRAY_INTEGRAL                                             4006                                                          // 4006 (0xfa6)
#define NISCOPE_VAL_DERIVATIVE                                                 4007                                                          // 4007 (0xfa7)
#define NISCOPE_VAL_INVERSE                                                    4008                                                          // 4008 (0xfa8)
#define NISCOPE_VAL_HANNING_WINDOW                                             4009                                                          // 4009 (0xfa9)
#define NISCOPE_VAL_FLAT_TOP_WINDOW                                            4010                                                          // 4010 (0xfaa)
#define NISCOPE_VAL_POLYNOMIAL_INTERPOLATION                                   4011                                                          // 4011 (0xfab)
#define NISCOPE_VAL_MULTIPLY_CHANNELS                                          4012                                                          // 4012 (0xfac)
#define NISCOPE_VAL_ADD_CHANNELS                                               4013                                                          // 4013 (0xfad)
#define NISCOPE_VAL_SUBTRACT_CHANNELS                                          4014                                                          // 4014 (0xfae)
#define NISCOPE_VAL_DIVIDE_CHANNELS                                            4015                                                          // 4015 (0xfaf)
#define NISCOPE_VAL_MULTI_ACQ_AVERAGE                                          4016                                                          // 4016 (0xfb0)
#define NISCOPE_VAL_BUTTERWORTH_FILTER                                         4017                                                          // 4017 (0xfb1)
#define NISCOPE_VAL_CHEBYSHEV_FILTER                                           4018                                                          // 4018 (0xfb2)
#define NISCOPE_VAL_FFT_AMP_SPECTRUM_DB                                        4019                                                          // 4019 (0xfb3)
#define NISCOPE_VAL_HAMMING_WINDOW                                             4020                                                          // 4020 (0xfb4)
#define NISCOPE_VAL_WINDOWED_FIR_FILTER                                        4021                                                          // 4021 (0xfb5)
#define NISCOPE_VAL_BESSEL_FILTER                                              4022                                                          // 4022 (0xfb6)
#define NISCOPE_VAL_TRIANGLE_WINDOW                                            4023                                                          // 4023 (0xfb7)
#define NISCOPE_VAL_BLACKMAN_WINDOW                                            4024                                                          // 4024 (0xfb8)
#define NISCOPE_VAL_ARRAY_OFFSET                                               4025                                                          // 4025 (0xfb9)
#define NISCOPE_VAL_ARRAY_GAIN                                                 4026                                                          // 4026 (0xfba)

// Values used in
//     NISCOPE_ATTR_DDC_DATA_PROCESSING_MODE
#define NISCOPE_VAL_REAL                                                       0                                                             // 0 (0x0)
#define NISCOPE_VAL_COMPLEX                                                    1                                                             // 1 (0x1)

// Values used in
//     NISCOPE_ATTR_CHANNEL_TERMINAL_CONFIGURATION
#define NISCOPE_VAL_SINGLE_ENDED                                               0                                                             // 0 (0x0)
#define NISCOPE_VAL_UNBALANCED_DIFFERENTIAL                                    1                                                             // 1 (0x1)
#define NISCOPE_VAL_DIFFERENTIAL                                               2                                                             // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_FLEX_FIR_ANTIALIAS_FILTER_TYPE
#define NISCOPE_VAL_48_TAP_STANDARD                                            0                                                             // 0 (0x0)
#define NISCOPE_VAL_48_TAP_HANNING                                             1                                                             // 1 (0x1)
#define NISCOPE_VAL_16_TAP_HANNING                                             2                                                             // 2 (0x2)
#define NISCOPE_VAL_8_TAP_HANNING                                              3                                                             // 3 (0x3)

// Values used in
//     NISCOPE_ATTR_OVERFLOW_ERROR_REPORTING
#define NISCOPE_VAL_ERROR_REPORTING_ERROR                                      0                                                             // 0 (0x0)
#define NISCOPE_VAL_ERROR_REPORTING_WARNING                                    1                                                             // 1 (0x1)
#define NISCOPE_VAL_ERROR_REPORTING_DISABLED                                   2                                                             // 2 (0x2)

// Values used in
//     NISCOPE_ATTR_REF_TRIGGER_DETECTOR_LOCATION
#define NISCOPE_VAL_ANALOG_DETECTION_CIRCUIT                                   0                                                             // 0 (0x0)
#define NISCOPE_VAL_DDC_OUTPUT                                                 1                                                             // 1 (0x1)

// Values used in
//     NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR_TYPE, NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR_TYPE,
//     NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE
#define NISCOPE_VAL_ADDR_PHYSICAL                                              0                                                             // 0 (0x0)
#define NISCOPE_VAL_ADDR_VIRTUAL                                               1                                                             // 1 (0x1)

// Values used in
//     NISCOPE_ATTR_P2P_NOTIFY_PUSH_MESSAGE_ON
#define NISCOPE_VAL_NOTIFY_NEVER                                               0                                                             // 0 (0x0)
#define NISCOPE_VAL_NOTIFY_DONE                                                1                                                             // 1 (0x1)

// P2P Stream Relative To
#define NISCOPE_VAL_STREAM_RELATIVE_TO_START_TRIGGER                           0                                                             // 0 (0x0)
#define NISCOPE_VAL_STREAM_RELATIVE_TO_REFERENCE_TRIGGER                       1                                                             // 1 (0x1)
#define NISCOPE_VAL_STREAM_RELATIVE_TO_SYNC_TRIGGER                            2                                                             // 2 (0x2)


/****************************************************************************
 *-------------------------------- Constants -------------------------------*
 ****************************************************************************/
#define NISCOPE_VAL_INPUT                                                      0                                                             // 0 (0x0)
#define NISCOPE_VAL_OUTPUT                                                     1                                                             // 1 (0x1)
#define NISCOPE_VAL_NONE                                                       0                                                             // 0 (0x0)
#define NISCOPE_VAL_TRUE                                                       VI_TRUE                                                       // 1 (0x1)
#define NISCOPE_VAL_FALSE                                                      VI_FALSE                                                      // 0 (0x0)
#define NISCOPE_VAL_SELF_CALIBRATION                                           0                                                             // 0 (0x0)
#define NISCOPE_VAL_EXTERNAL_CALIBRATION                                       1                                                             // 1 (0x1)
#define NISCOPE_VAL_RESTORE_FACTORY_CALIBRATION                                2                                                             // 2 (0x2)
#define NISCOPE_VAL_CAL_RESTORE_EXTERNAL_CALIBRATION                           NISCOPE_VAL_RESTORE_FACTORY_CALIBRATION                       // 2 (0x2)
#define NISCOPE_VAL_ALL_MEASUREMENTS                                           10000                                                         // 10000 (0x2710)


/****************************************************************************
 *----------------------------- Type Definitions ---------------------------*
 ****************************************************************************/
#pragma pack(push,8)
struct niScope_wfmInfo
{
    ViReal64 absoluteInitialX;
    ViReal64 relativeInitialX;
    ViReal64 xIncrement;
    ViInt32 actualSamples;
    ViReal64 offset;
    ViReal64 gain;
    ViReal64 reserved1;
    ViReal64 reserved2;
};

struct niScope_coefficientInfo
{
    ViReal64 offset;
    ViReal64 gain;
    ViReal64 reserved1;
    ViReal64 reserved2;
};

#if !defined(_NIComplexNumber)
#define _NIComplexNumber
typedef struct NIComplexNumber_struct
{
    ViReal64 real;
    ViReal64 imaginary;
} NIComplexNumber;
#endif // !defined(_NIComplexNumber)

#if !defined(_NIComplexI16)
#define _NIComplexI16
typedef struct NIComplexI16_struct
{
    ViInt16 real;
    ViInt16 imaginary;
} NIComplexI16;
#endif // !defined(_NIComplexI16)

#pragma pack(pop)


/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/
// -- Init And Close Functions --
ViStatus _VI_FUNC niScope_init(
   ViRsrc resourceName,
   ViBoolean idQuery,
   ViBoolean resetDevice,
   ViSession* vi);

ViStatus _VI_FUNC niScope_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean idQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niScope_close(
   ViSession vi);

// -- Autosetup Functions --
ViStatus _VI_FUNC niScope_AutoSetup(
   ViSession vi);

// -- Vertical Subsystem Configuration --
ViStatus _VI_FUNC niScope_ConfigureVertical(
   ViSession vi,
   ViConstString channelList,
   ViReal64 range,
   ViReal64 offset,
   ViInt32 coupling,
   ViReal64 probeAttenuation,
   ViBoolean enabled);

ViStatus _VI_FUNC niScope_ConfigureChanCharacteristics(
   ViSession vi,
   ViConstString channelList,
   ViReal64 inputImpedance,
   ViReal64 maxInputFrequency);

// -- Horizontal Subsystem Configuration --
ViStatus _VI_FUNC niScope_ConfigureHorizontalTiming(
   ViSession vi,
   ViReal64 minSampleRate,
   ViInt32 minNumPts,
   ViReal64 refPosition,
   ViInt32 numRecords,
   ViBoolean enforceRealtime);

// -- Synchronization Configuration --
ViStatus _VI_FUNC niScope_ConfigureClock(
   ViSession vi,
   ViConstString inputClockSource,
   ViConstString outputClockSource,
   ViConstString clockSyncPulseSource,
   ViBoolean masterEnabled);

ViStatus _VI_FUNC niScope_ExportSignal(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

ViStatus _VI_FUNC niScope_AdjustSampleClockRelativeDelay(
   ViSession vi,
   ViReal64 delay);

// -- Triggering Subsystem Configuration --
ViStatus _VI_FUNC niScope_ConfigureTriggerEdge(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 level,
   ViInt32 slope,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerGlitch(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 level,
   ViReal64 width,
   ViInt32 polarity,
   ViInt32 glitchCondition,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerHysteresis(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 level,
   ViReal64 hysteresis,
   ViInt32 slope,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerWindow(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 lowLevel,
   ViReal64 highLevel,
   ViInt32 windowMode,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerSoftware(
   ViSession vi,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_SendSoftwareTriggerEdge(
   ViSession vi,
   ViInt32 whichTrigger);

ViStatus _VI_FUNC niScope_ConfigureTriggerImmediate(
   ViSession vi);

ViStatus _VI_FUNC niScope_ConfigureTriggerRunt(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 lowThreshold,
   ViReal64 highThreshold,
   ViInt32 polarity,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerDigital(
   ViSession vi,
   ViConstString triggerSource,
   ViInt32 slope,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerVideo(
   ViSession vi,
   ViConstString triggerSource,
   ViBoolean enableDcRestore,
   ViInt32 signalFormat,
   ViInt32 event,
   ViInt32 lineNumber,
   ViInt32 polarity,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerWidth(
   ViSession vi,
   ViConstString triggerSource,
   ViReal64 level,
   ViReal64 lowThreshold,
   ViReal64 highThreshold,
   ViInt32 polarity,
   ViInt32 condition,
   ViInt32 triggerCoupling,
   ViReal64 holdoff,
   ViReal64 delay);

// -- Onboard Signal Processing Subsystem Configuration --
ViStatus _VI_FUNC niScope_ConfigureEqualizationFilterCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 numberOfCoefficients,
   ViReal64 coefficients[]);

ViStatus _VI_FUNC niScope_GetEqualizationFilterCoefficients(
   ViSession vi,
   ViConstString channel,
   ViInt32 numberOfCoefficients,
   ViReal64 coefficients[]);

ViStatus _VI_FUNC niScope_GetFrequencyResponse(
   ViSession vi,
   ViConstString channel,
   ViInt32 bufferSize,
   ViReal64 frequencies[],
   ViReal64 amplitudes[],
   ViReal64 phases[],
   ViInt32* numberOfFrequencies);

// -- Waveform Acquisition Subsystem --
ViStatus _VI_FUNC niScope_ConfigureAcquisition(
   ViSession vi,
   ViInt32 acquisitionType);

ViStatus _VI_FUNC niScope_InitiateAcquisition(
   ViSession vi);

ViStatus _VI_FUNC niScope_Abort(
   ViSession vi);

ViStatus _VI_FUNC niScope_Commit(
   ViSession vi);

ViStatus _VI_FUNC niScope_Read(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   ViReal64 waveform[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_Fetch(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   ViReal64 waveform[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_FetchBinary8(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   ViInt8 waveform[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_FetchBinary16(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   ViInt16 waveform[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_FetchBinary32(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   ViInt32 waveform[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_FetchComplex(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   NIComplexNumber wfm[],
   struct niScope_wfmInfo wfmInfo[]);

ViStatus _VI_FUNC niScope_FetchComplexBinary16(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 numSamples,
   NIComplexI16 wfm[],
   struct niScope_wfmInfo wfmInfo[]);

// -- Status --
ViStatus _VI_FUNC niScope_AcquisitionStatus(
   ViSession vi,
   ViInt32* acquisitionStatus);

// -- Actual Values --
ViStatus _VI_FUNC niScope_ActualNumWfms(
   ViSession vi,
   ViConstString channelList,
   ViInt32* numWfms);

ViStatus _VI_FUNC niScope_ActualMeasWfmSize(
   ViSession vi,
   ViInt32 arrayMeasFunction,
   ViInt32* measWaveformSize);

ViStatus _VI_FUNC niScope_ActualRecordLength(
   ViSession vi,
   ViInt32* recordLength);

ViStatus _VI_FUNC niScope_SampleRate(
   ViSession vi,
   ViReal64* sampleRate);

ViStatus _VI_FUNC niScope_SampleMode(
   ViSession vi,
   ViInt32* sampleMode);

// -- Waveform Measurement Functions --
ViStatus _VI_FUNC niScope_AddWaveformProcessing(
   ViSession vi,
   ViConstString channelList,
   ViInt32 measFunction);

ViStatus _VI_FUNC niScope_ClearWaveformProcessing(
   ViSession vi,
   ViConstString channelList);

ViStatus _VI_FUNC niScope_ClearWaveformMeasurementStats(
   ViSession vi,
   ViConstString channelList,
   ViInt32 clearableMeasurementFunction);

ViStatus _VI_FUNC niScope_ReadMeasurement(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 scalarMeasFunction,
   ViReal64 result[]);

ViStatus _VI_FUNC niScope_FetchMeasurement(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 scalarMeasFunction,
   ViReal64 result[]);

ViStatus _VI_FUNC niScope_FetchMeasurementStats(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 scalarMeasFunction,
   ViReal64 result[],
   ViReal64 mean[],
   ViReal64 stdev[],
   ViReal64 min[],
   ViReal64 max[],
   ViInt32 numInStats[]);

ViStatus _VI_FUNC niScope_FetchArrayMeasurement(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViInt32 arrayMeasFunction,
   ViInt32 measWfmSize,
   ViReal64 measWfm[],
   struct niScope_wfmInfo wfmInfo[]);

// -- Utility Functions --
ViStatus _VI_FUNC niScope_reset(
   ViSession vi);

ViStatus _VI_FUNC niScope_self_test(
   ViSession vi,
   ViInt16* selfTestResult,
   ViChar selfTestMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niScope_Disable(
   ViSession vi);

ViStatus _VI_FUNC niScope_ResetDevice(
   ViSession vi);

ViStatus _VI_FUNC niScope_CalSelfCalibrate(
   ViSession vi,
   ViConstString channelList,
   ViInt32 option);

ViStatus _VI_FUNC niScope_revision_query(
   ViSession vi,
   ViChar driverRevision[IVI_MAX_MESSAGE_BUF_SIZE],
   ViChar firmwareRevision[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niScope_ProbeCompensationSignalStart(
   ViSession vi);

ViStatus _VI_FUNC niScope_ProbeCompensationSignalStop(
   ViSession vi);

ViStatus _VI_FUNC niScope_CableSenseSignalStart(
   ViSession vi);

ViStatus _VI_FUNC niScope_CableSenseSignalStop(
   ViSession vi);

ViStatus _VI_FUNC niScope_IsDeviceReady(
   ViRsrc resourceName,
   ViConstString channelList,
   ViBoolean* deviceReady);

ViStatus _VI_FUNC niScope_GetChannelName(
   ViSession vi,
   ViInt32 index,
   ViInt32 bufferSize,
   ViChar channelString[]);

ViStatus _VI_FUNC niScope_GetChannelNameFromString(
   ViSession vi,
   ViConstString index,
   ViInt32 bufferSize,
   ViChar name[]);

// -- Error Functions --
ViStatus _VI_FUNC niScope_errorHandler(
   ViSession vi,
   ViStatus errorCode,
   const ViChar errorSource[MAX_FUNCTION_NAME_SIZE],
   ViChar errorDescription[MAX_ERROR_DESCRIPTION]);

ViStatus _VI_FUNC niScope_GetError(
   ViSession vi,
   ViStatus* errorCode,
   ViInt32 bufferSize,
   ViChar description[]);

ViStatus _VI_FUNC niScope_GetErrorMessage(
   ViSession vi,
   ViStatus errorCode,
   ViInt32 bufferSize,
   ViChar errorMessage[]);

// -- Session Locking Functions --
ViStatus _VI_FUNC niScope_LockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

ViStatus _VI_FUNC niScope_UnlockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

// -- Typesafe Get, Set, And Check Attribute Functions --
ViStatus _VI_FUNC niScope_GetAttributeViInt32(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt32* value);

ViStatus _VI_FUNC niScope_SetAttributeViInt32(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt32 value);

ViStatus _VI_FUNC niScope_CheckAttributeViInt32(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt32 value);

ViStatus _VI_FUNC niScope_GetAttributeViInt64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt64* value);

ViStatus _VI_FUNC niScope_SetAttributeViInt64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt64 value);

ViStatus _VI_FUNC niScope_CheckAttributeViInt64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt64 value);

ViStatus _VI_FUNC niScope_GetAttributeViReal64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViReal64* value);

ViStatus _VI_FUNC niScope_SetAttributeViReal64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViReal64 value);

ViStatus _VI_FUNC niScope_CheckAttributeViReal64(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViReal64 value);

ViStatus _VI_FUNC niScope_GetAttributeViString(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViInt32 bufSize,
   ViChar value[]);

ViStatus _VI_FUNC niScope_SetAttributeViString(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViConstString value);

ViStatus _VI_FUNC niScope_CheckAttributeViString(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViConstString value);

ViStatus _VI_FUNC niScope_GetAttributeViSession(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViSession* value);

ViStatus _VI_FUNC niScope_SetAttributeViSession(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViSession value);

ViStatus _VI_FUNC niScope_CheckAttributeViSession(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViSession value);

ViStatus _VI_FUNC niScope_GetAttributeViBoolean(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViBoolean* value);

ViStatus _VI_FUNC niScope_SetAttributeViBoolean(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViBoolean value);

ViStatus _VI_FUNC niScope_CheckAttributeViBoolean(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId,
   ViBoolean value);

ViStatus _VI_FUNC niScope_ResetAttribute(
   ViSession vi,
   ViConstString channelList,
   ViAttr attributeId);

ViStatus _VI_FUNC niScope_ResetAllAttributes(
   ViSession vi);

// -- Import And Export Attribute Configuration Functions --
ViStatus _VI_FUNC niScope_ImportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);

ViStatus _VI_FUNC niScope_ExportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);

ViStatus _VI_FUNC niScope_ImportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

ViStatus _VI_FUNC niScope_ExportAttributeConfigurationFile(
   ViSession vi,
   ViConstString filePath);

// -- Scaling And Normalization Functions --
ViStatus _VI_FUNC niScope_GetScalingCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   struct niScope_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

ViStatus _VI_FUNC niScope_GetNormalizationCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   struct niScope_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

// -- Peer-To-Peer Streaming Functions --
ViStatus _VI_FUNC niScope_GetStreamEndpointHandle(
   ViSession vi,
   ViConstString streamName,
   ViUInt32* writerHandle);



/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#define NISCOPE_WARN_INVALID_WFM_ELEMENT                                       IVISCOPE_WARN_INVALID_WFM_ELEMENT                             // 1073356801 (0x3ffa2001)
#define NISCOPE_WARN_HEATER_CIRCUIT_TEMPERATURE                                (IVI_SPECIFIC_WARN_BASE + 1L)                                 // 1073364993 (0x3ffa4001)
#define NISCOPE_WARN_INVALID_DATA                                              (IVI_SPECIFIC_WARN_BASE + 2L)                                 // 1073364994 (0x3ffa4002)
#define NISCOPE_WARN_CHANNEL_OVERLOAD                                          (IVI_SPECIFIC_WARN_BASE + 3L)                                 // 1073364995 (0x3ffa4003)
#define NISCOPE_WARN_AUTOSETUP_NO_SIGNAL                                       (IVI_SPECIFIC_WARN_BASE + 4L)                                 // 1073364996 (0x3ffa4004)
#define NISCOPE_WARN_PLL_UNLOCKED                                              (IVI_SPECIFIC_WARN_BASE + 5L)                                 // 1073364997 (0x3ffa4005)
#define NISCOPE_WARN_PLL_UNLOCKED_AND_ADC_OVERLOAD                             (IVI_SPECIFIC_WARN_BASE + 6L)                                 // 1073364998 (0x3ffa4006)
#define NISCOPE_WARN_TIMESTAMP_ROLLOVER                                        (IVI_SPECIFIC_WARN_BASE + 7L)                                 // 1073364999 (0x3ffa4007)
#define NISCOPE_WARN_ADC_OVERLOAD                                              (IVI_SPECIFIC_WARN_BASE + 8L)                                 // 1073365000 (0x3ffa4008)
#define NISCOPE_WARN_P2P_OVERFLOW                                              (IVI_SPECIFIC_WARN_BASE + 9L)                                 // 1073365001 (0x3ffa4009)
#define NISCOPE_ERROR_CHANNEL_NOT_ENABLED                                      IVISCOPE_ERROR_CHANNEL_NOT_ENABLED                            // 3220840449 (0xbffa2001)
#define NISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT                            IVISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT                  // 3220840450 (0xbffa2002)
#define NISCOPE_ERROR_MAX_TIME_EXCEEDED                                        IVISCOPE_ERROR_MAX_TIME_EXCEEDED                              // 3220840451 (0xbffa2003)
#define NISCOPE_ERROR_SOFTWARE_FAILURE                                         (IVI_SPECIFIC_ERROR_BASE + 1L)                                // 3220848641 (0xbffa4001)
#define NISCOPE_ERROR_HARDWARE_FAILURE                                         (IVI_SPECIFIC_ERROR_BASE + 2L)                                // 3220848642 (0xbffa4002)
#define NISCOPE_ERROR_INSUFFICIENT_MEMORY                                      (IVI_SPECIFIC_ERROR_BASE + 3L)                                // 3220848643 (0xbffa4003)
#define NISCOPE_ERROR_INVALID_DATA                                             (IVI_SPECIFIC_ERROR_BASE + 4L)                                // 3220848644 (0xbffa4004)
#define NISCOPE_ERROR_GAIN_CAL_FAILURE                                         (IVI_SPECIFIC_ERROR_BASE + 5L)                                // 3220848645 (0xbffa4005)
#define NISCOPE_ERROR_SINE_CAL_FAILURE                                         (IVI_SPECIFIC_ERROR_BASE + 6L)                                // 3220848646 (0xbffa4006)
#define NISCOPE_ERROR_LIN_CAL_FAILURE                                          (IVI_SPECIFIC_ERROR_BASE + 7L)                                // 3220848647 (0xbffa4007)
#define NISCOPE_ERROR_ADC_CAL_FAILURE                                          (IVI_SPECIFIC_ERROR_BASE + 8L)                                // 3220848648 (0xbffa4008)
#define NISCOPE_ERROR_ACQ_IN_PROGRESS                                          (IVI_SPECIFIC_ERROR_BASE + 9L)                                // 3220848649 (0xbffa4009)
#define NISCOPE_ERROR_DATA_NOT_AVAILABLE                                       (IVI_SPECIFIC_ERROR_BASE + 10L)                               // 3220848650 (0xbffa400a)
#define NISCOPE_ERROR_HEATER_CIRCUIT_CAL_FAILURE                               (IVI_SPECIFIC_ERROR_BASE + 11L)                               // 3220848651 (0xbffa400b)
#define NISCOPE_ERROR_FLEXRES_CONFIG_CORRUPT                                   (IVI_SPECIFIC_ERROR_BASE + 12L)                               // 3220848652 (0xbffa400c)
#define NISCOPE_ERROR_GAIN_OFFSET_CAL_FAILURE                                  (IVI_SPECIFIC_ERROR_BASE + 13L)                               // 3220848653 (0xbffa400d)
#define NISCOPE_ERROR_CREATE_THREAD                                            (IVI_SPECIFIC_ERROR_BASE + 14L)                               // 3220848654 (0xbffa400e)
#define NISCOPE_ERROR_WRONG_PASSWORD                                           (IVI_SPECIFIC_ERROR_BASE + 15L)                               // 3220848655 (0xbffa400f)
#define NISCOPE_ERROR_INVALID_GAIN                                             (IVI_SPECIFIC_ERROR_BASE + 16L)                               // 3220848656 (0xbffa4010)
#define NISCOPE_ERROR_INVALID_CAL_SESSION                                      (IVI_SPECIFIC_ERROR_BASE + 19L)                               // 3220848659 (0xbffa4013)
#define NISCOPE_ERROR_BAD_MEASUREMENT                                          (IVI_SPECIFIC_ERROR_BASE + 20L)                               // 3220848660 (0xbffa4014)
#define NISCOPE_ERROR_BUFFER_NOT_ACQUIRED                                      (IVI_SPECIFIC_ERROR_BASE + 21L)                               // 3220848661 (0xbffa4015)
#define NISCOPE_ERROR_TRIGGER_HAS_NOT_OCCURRED                                 (IVI_SPECIFIC_ERROR_BASE + 22L)                               // 3220848662 (0xbffa4016)
#define NISCOPE_ERROR_ILLEGAL_RELATIVE_TO                                      (IVI_SPECIFIC_ERROR_BASE + 23L)                               // 3220848663 (0xbffa4017)
#define NISCOPE_ERROR_DATA_OVERWRITTEN                                         (IVI_SPECIFIC_ERROR_BASE + 24L)                               // 3220848664 (0xbffa4018)
#define NISCOPE_ERROR_INVALID_TIMESTAMP_EVENT_TAG                              (IVI_SPECIFIC_ERROR_BASE + 26L)                               // 3220848666 (0xbffa401a)
#define NISCOPE_ERROR_TIMEOUT_TRANSFERRING_TIMESTAMPS                          (IVI_SPECIFIC_ERROR_BASE + 27L)                               // 3220848667 (0xbffa401b)
#define NISCOPE_ERROR_TIMEOUT_CHECKING_STATUS                                  (IVI_SPECIFIC_ERROR_BASE + 28L)                               // 3220848668 (0xbffa401c)
#define NISCOPE_ERROR_TIMEOUT_TRANSFERRING_DATA                                (IVI_SPECIFIC_ERROR_BASE + 29L)                               // 3220848669 (0xbffa401d)
#define NISCOPE_ERROR_PLL_FAILURE                                              (IVI_SPECIFIC_ERROR_BASE + 30L)                               // 3220848670 (0xbffa401e)
#define NISCOPE_ERROR_PAR_TO_SER_CONV_FAILURE                                  (IVI_SPECIFIC_ERROR_BASE + 31L)                               // 3220848671 (0xbffa401f)
#define NISCOPE_ERROR_DMA_CONFIG_ERROR                                         (IVI_SPECIFIC_ERROR_BASE + 32L)                               // 3220848672 (0xbffa4020)
#define NISCOPE_ERROR_ILLEGAL_USER_OFFSET                                      (IVI_SPECIFIC_ERROR_BASE + 33L)                               // 3220848673 (0xbffa4021)
#define NISCOPE_ERROR_NOT_A_SCOPE                                              (IVI_SPECIFIC_ERROR_BASE + 34L)                               // 3220848674 (0xbffa4022)
#define NISCOPE_ERROR_TIMEOUT_CLEARING_TIO                                     (IVI_SPECIFIC_ERROR_BASE + 35L)                               // 3220848675 (0xbffa4023)
#define NISCOPE_ERROR_RIS_DID_NOT_COMPLETE                                     (IVI_SPECIFIC_ERROR_BASE + 36L)                               // 3220848676 (0xbffa4024)
#define NISCOPE_ERROR_INVALID_RIS_METHOD                                       (IVI_SPECIFIC_ERROR_BASE + 37L)                               // 3220848677 (0xbffa4025)
#define NISCOPE_ERROR_INVALID_RIS_NUM_AVERAGES                                 (IVI_SPECIFIC_ERROR_BASE + 38L)                               // 3220848678 (0xbffa4026)
#define NISCOPE_ERROR_ILLEGAL_DATATYPE                                         (IVI_SPECIFIC_ERROR_BASE + 39L)                               // 3220848679 (0xbffa4027)
#define NISCOPE_ERROR_ATTRIBUTES_DIFFER_BY_CHANNEL                             (IVI_SPECIFIC_ERROR_BASE + 40L)                               // 3220848680 (0xbffa4028)
#define NISCOPE_ERROR_TRIGGER_DELAY_INVALID_WITH_RIS                           (IVI_SPECIFIC_ERROR_BASE + 41L)                               // 3220848681 (0xbffa4029)
#define NISCOPE_ERROR_INITIATE_NOT_CALLED                                      (IVI_SPECIFIC_ERROR_BASE + 42L)                               // 3220848682 (0xbffa402a)
#define NISCOPE_ERROR_INVALID_FUNCTION_USE                                     (IVI_SPECIFIC_ERROR_BASE + 43L)                               // 3220848683 (0xbffa402b)
#define NISCOPE_ERROR_HOLDOFF_DELAY_NONZERO                                    (IVI_SPECIFIC_ERROR_BASE + 44L)                               // 3220848684 (0xbffa402c)
#define NISCOPE_ERROR_CHANNEL_NAME_TOO_LONG                                    (IVI_SPECIFIC_ERROR_BASE + 45L)                               // 3220848685 (0xbffa402d)
#define NISCOPE_ERROR_DIGITIZER_ALREADY_IN_USE                                 (IVI_SPECIFIC_ERROR_BASE + 46L)                               // 3220848686 (0xbffa402e)
#define NISCOPE_ERROR_SIM_MODEL_NOT_SUPPORTED                                  (IVI_SPECIFIC_ERROR_BASE + 47L)                               // 3220848687 (0xbffa402f)
#define NISCOPE_ERROR_SPECIFICDLL_LOAD_FAILURE                                 (IVI_SPECIFIC_ERROR_BASE + 48L)                               // 3220848688 (0xbffa4030)
#define NISCOPE_ERROR_SPECIFICDLL_GET_ADDRESS_FAILURE                          (IVI_SPECIFIC_ERROR_BASE + 49L)                               // 3220848689 (0xbffa4031)
#define NISCOPE_ERROR_TRIGGER_TYPE_INVALID                                     (IVI_SPECIFIC_ERROR_BASE + 50L)                               // 3220848690 (0xbffa4032)
#define NISCOPE_ERROR_INVALID_FETCH_PARAMETERS                                 (IVI_SPECIFIC_ERROR_BASE + 51L)                               // 3220848691 (0xbffa4033)
#define NISCOPE_ERROR_EXT_CAL_NOT_COMPLETE                                     (IVI_SPECIFIC_ERROR_BASE + 52L)                               // 3220848692 (0xbffa4034)
#define NISCOPE_ERROR_EXT_CAL_CONSTS_INVALID                                   (IVI_SPECIFIC_ERROR_BASE + 53L)                               // 3220848693 (0xbffa4035)
#define NISCOPE_ERROR_INVALID_NUM_WAVEFORMS                                    (IVI_SPECIFIC_ERROR_BASE + 54L)                               // 3220848694 (0xbffa4036)
#define NISCOPE_ERROR_DIGITIZER_NOT_SUPPORTED_WITH_ACCESSORY                   (IVI_SPECIFIC_ERROR_BASE + 55L)                               // 3220848695 (0xbffa4037)
#define NISCOPE_ERROR_DIGITAL_TRIGGER_NOT_SUPPORTED_WITH_RIS                   (IVI_SPECIFIC_ERROR_BASE + 56L)                               // 3220848696 (0xbffa4038)
#define NISCOPE_ERROR_SELF_CAL_NOT_COMPLETE                                    (IVI_SPECIFIC_ERROR_BASE + 57L)                               // 3220848697 (0xbffa4039)
#define NISCOPE_ERROR_PATTERN_NOISE_SAMPLE_WORDS                               (IVI_SPECIFIC_ERROR_BASE + 58L)                               // 3220848698 (0xbffa403a)
#define NISCOPE_ERROR_PATTERN_NOISE_INPUT_EXPECTATION                          (IVI_SPECIFIC_ERROR_BASE + 59L)                               // 3220848699 (0xbffa403b)
#define NISCOPE_ERROR_INVALID_SESSION                                          0xBFFA1190                                                    // 3220836752 (0xbffa1190)
#define NISCOPE_ERROR_1MOHM_PATH_BANDWIDTH_LIMITED                             (IVI_SPECIFIC_ERROR_BASE + 60L)                               // 3220848700 (0xbffa403c)
#define NISCOPE_ERROR_EXT_CAL_STEP_OUT_OF_ORDER                                (IVI_SPECIFIC_ERROR_BASE + 61L)                               // 3220848701 (0xbffa403d)
#define NISCOPE_ERROR_MULTIPLES_2_ALLOWED_SAMPLE_CLK_TIMEBASE_DIV              (IVI_SPECIFIC_ERROR_BASE + 62L)                               // 3220848702 (0xbffa403e)
#define NISCOPE_ERROR_CAL_INPUT_VOLTAGE_DETECTED                               (IVI_SPECIFIC_ERROR_BASE + 63L)                               // 3220848703 (0xbffa403f)
#define NISCOPE_ERROR_EXT_CAL_ATTENUATOR_FAILED                                (IVI_SPECIFIC_ERROR_BASE + 64L)                               // 3220848704 (0xbffa4040)
#define NISCOPE_ERROR_TDC_CAL_TIME_OUT                                         (IVI_SPECIFIC_ERROR_BASE + 65L)                               // 3220848705 (0xbffa4041)
#define NISCOPE_ERROR_TDC_CAL_FAILURE                                          (IVI_SPECIFIC_ERROR_BASE + 66L)                               // 3220848706 (0xbffa4042)
#define NISCOPE_ERROR_TRIGGER_CAL_FAILURE                                      (IVI_SPECIFIC_ERROR_BASE + 67L)                               // 3220848707 (0xbffa4043)
#define NISCOPE_ERROR_OFFSET_DAC_CAL_FAILURE                                   (IVI_SPECIFIC_ERROR_BASE + 68L)                               // 3220848708 (0xbffa4044)
#define NISCOPE_ERROR_INVALID_FETCH_POSITION                                   (IVI_SPECIFIC_ERROR_BASE + 69L)                               // 3220848709 (0xbffa4045)
#define NISCOPE_ERROR_RIS_MODE_NOT_SUPPORTED_WITH_P2P                          (IVI_SPECIFIC_ERROR_BASE + 70L)                               // 3220848710 (0xbffa4046)


/*- niScopeObsolete.h included for backwards compatibility -*/
#include "niScopeObsolete.h"

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NISCOPE_HEADER */
