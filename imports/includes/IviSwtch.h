/****************************************************************************
 *                             I V I - S W T C H                             
 *---------------------------------------------------------------------------
 *    Copyright (c) 1998-2020 National Instruments.  All Rights Reserved.         
 *---------------------------------------------------------------------------
 *                                                                           
 * Title:       iviswtch.h                                                    
 * Purpose:     IviSwtch Class declarations for the Base and Extended  
 *              IviSwtch Capabilities.                                                 
 ****************************************************************************/

#ifndef IVISWTCH_HEADER
#define IVISWTCH_HEADER

#include <ivi.h>

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/

#define IVISWTCH_MAJOR_VERSION              (4L)
#define IVISWTCH_MINOR_VERSION              (0L)

#define IVISWTCH_CLASS_SPEC_MAJOR_VERSION   (4L)
#define IVISWTCH_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVISWTCH_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVISWTCH_DRIVER_DESCRIPTION         "IviSwtch Class Driver [Compiled for 64-bit.]"
#else
#define IVISWTCH_DRIVER_DESCRIPTION         "IviSwtch Class Driver"
#endif

/*****************************************************************************
 *-------------------- IviSwtch Class Attribute Defines ---------------------*
 *****************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVISWTCH_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVISWTCH_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVISWTCH_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVISWTCH_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVISWTCH_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVISWTCH_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVISWTCH_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVISWTCH_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVISWTCH_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVISWTCH_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVISWTCH_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVISWTCH_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVISWTCH_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVISWTCH_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISWTCH_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVISWTCH_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                    /* ViString, read-only */
#define IVISWTCH_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVISWTCH_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVISWTCH_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVISWTCH_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVISWTCH_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /* Version Information */
#define IVISWTCH_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVISWTCH_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVISWTCH_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviSwtch Fundamental Attributes -*/
#define IVISWTCH_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT              /* ViInt32,  read-only */
#define IVISWTCH_ATTR_IS_SOURCE_CHANNEL         (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)   /* ViBoolean, Channel-based */
#define IVISWTCH_ATTR_IS_DEBOUNCED              (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)   /* ViBoolean, Read-only */
#define IVISWTCH_ATTR_IS_CONFIGURATION_CHANNEL  (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)   /* ViBoolean, Channel-based */
#define IVISWTCH_ATTR_SETTLING_TIME             (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_BANDWIDTH                 (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_DC_VOLTAGE            (IVI_CLASS_PUBLIC_ATTR_BASE + 6L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_AC_VOLTAGE            (IVI_CLASS_PUBLIC_ATTR_BASE + 7L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_SWITCHING_DC_CURRENT  (IVI_CLASS_PUBLIC_ATTR_BASE + 8L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_SWITCHING_AC_CURRENT  (IVI_CLASS_PUBLIC_ATTR_BASE + 9L)   /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_CARRY_DC_CURRENT      (IVI_CLASS_PUBLIC_ATTR_BASE + 10L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_CARRY_AC_CURRENT      (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_SWITCHING_DC_POWER    (IVI_CLASS_PUBLIC_ATTR_BASE + 12L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_SWITCHING_AC_POWER    (IVI_CLASS_PUBLIC_ATTR_BASE + 13L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_CARRY_DC_POWER        (IVI_CLASS_PUBLIC_ATTR_BASE + 14L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_MAX_CARRY_AC_POWER        (IVI_CLASS_PUBLIC_ATTR_BASE + 15L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_CHARACTERISTIC_IMPEDANCE  (IVI_CLASS_PUBLIC_ATTR_BASE + 16L)  /* ViReal64, Read-only, Channel-based */
#define IVISWTCH_ATTR_WIRE_MODE                 (IVI_CLASS_PUBLIC_ATTR_BASE + 17L)  /* ViInt32,  Read-only, Channel-based */

    /*- IviSwtch Extended Attributes -*/
        /*- IviSwitchScanner Extension Group -*/
#define IVISWTCH_ATTR_NUM_OF_ROWS               (IVI_CLASS_PUBLIC_ATTR_BASE + 18L)  /* ViInt32, Read-only */
#define IVISWTCH_ATTR_NUM_OF_COLUMNS            (IVI_CLASS_PUBLIC_ATTR_BASE + 19L)  /* ViInt32, Read-only */
#define IVISWTCH_ATTR_SCAN_LIST                 (IVI_CLASS_PUBLIC_ATTR_BASE + 20L)  /* ViString */
#define IVISWTCH_ATTR_SCAN_MODE                 (IVI_CLASS_PUBLIC_ATTR_BASE + 21L)  /* ViInt32 */
#define IVISWTCH_ATTR_TRIGGER_INPUT             (IVI_CLASS_PUBLIC_ATTR_BASE + 22L)  /* ViInt32 */
#define IVISWTCH_ATTR_SCAN_ADVANCED_OUTPUT      (IVI_CLASS_PUBLIC_ATTR_BASE + 23L)  /* ViInt32 */
#define IVISWTCH_ATTR_IS_SCANNING               (IVI_CLASS_PUBLIC_ATTR_BASE + 24L)  /* ViBoolean, Read-only */
#define IVISWTCH_ATTR_SCAN_DELAY                (IVI_CLASS_PUBLIC_ATTR_BASE + 25L)  /* ViReal64 */
#define IVISWTCH_ATTR_CONTINUOUS_SCAN           (IVI_CLASS_PUBLIC_ATTR_BASE + 26L)  /* ViBoolean */

/*****************************************************************************
 *---------------- IviSwtch Class Attribute Value Defines -------------------*
 *****************************************************************************/

    /*- Defined values for attribute IVISWTCH_ATTR_SCAN_MODE -*/
#define IVISWTCH_VAL_NONE                                   (0L)
#define IVISWTCH_VAL_BREAK_BEFORE_MAKE                      (1L)
#define IVISWTCH_VAL_BREAK_AFTER_MAKE                       (2L)
#define IVISWTCH_VAL_SCAN_MODE_CLASS_EXT_BASE               (500L)
#define IVISWTCH_VAL_SCAN_MODE_SPECIFIC_EXT_BASE            (1000L)

    /*- Defined values for attribute IVISWTCH_ATTR_TRIGGER_INPUT -*/
#define IVISWTCH_VAL_IMMEDIATE                              (1L)
#define IVISWTCH_VAL_EXTERNAL                               (2L)
#define IVISWTCH_VAL_SOFTWARE_TRIG                          (3L)
#define IVISWTCH_VAL_TTL0                                   (111L)
#define IVISWTCH_VAL_TTL1                                   (112L)
#define IVISWTCH_VAL_TTL2                                   (113L)
#define IVISWTCH_VAL_TTL3                                   (114L)
#define IVISWTCH_VAL_TTL4                                   (115L)
#define IVISWTCH_VAL_TTL5                                   (116L)
#define IVISWTCH_VAL_TTL6                                   (117L)
#define IVISWTCH_VAL_TTL7                                   (118L)
#define IVISWTCH_VAL_ECL0                                   (119L)
#define IVISWTCH_VAL_ECL1                                   (120L)
#define IVISWTCH_VAL_PXI_STAR                               (125L)
#define IVISWTCH_VAL_RTSI_0                                 (140L)
#define IVISWTCH_VAL_RTSI_1                                 (141L)
#define IVISWTCH_VAL_RTSI_2                                 (142L)
#define IVISWTCH_VAL_RTSI_3                                 (143L)
#define IVISWTCH_VAL_RTSI_4                                 (144L)
#define IVISWTCH_VAL_RTSI_5                                 (145L)
#define IVISWTCH_VAL_RTSI_6                                 (146L)
#define IVISWTCH_VAL_TRIGGER_INPUT_CLASS_EXT_BASE           (500L)
#define IVISWTCH_VAL_TRIGGER_INPUT_SPECIFIC_EXT_BASE        (1000L)

    /*- Defined values for attribute IVISWTCH_ATTR_SCAN_ADVANCED_OUTPUT -*/
#define IVISWTCH_VAL_GPIB_SRQ                               (5L)
/* #define IVISWTCH_VAL_NONE                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_EXTERNAL                    DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL0                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL1                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL2                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL3                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL4                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL5                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL6                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_TTL7                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_ECL0                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_ECL1                        DEFINED ABOVE */
/* #define IVISWTCH_VAL_PXI_STAR                    DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_0                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_1                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_2                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_3                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_4                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_5                      DEFINED ABOVE */
/* #define IVISWTCH_VAL_RTSI_6                      DEFINED ABOVE */
#define IVISWTCH_VAL_SCAN_ADVANCED_OUTPUT_CLASS_EXT_BASE    (500L)
#define IVISWTCH_VAL_SCAN_ADVANCED_OUTPUT_SPECIFIC_EXT_BASE (1000L)

    /*- Defined values for IviSwtch_CanConnect path capability parameter -*/
#define IVISWTCH_VAL_PATH_AVAILABLE                         (1L)
#define IVISWTCH_VAL_PATH_EXISTS                            (2L)
#define IVISWTCH_VAL_PATH_UNSUPPORTED                       (3L)
#define IVISWTCH_VAL_RSRC_IN_USE                            (4L)
#define IVISWTCH_VAL_SOURCE_CONFLICT                        (5L)
#define IVISWTCH_VAL_CHANNEL_NOT_AVAILABLE                  (6L)
#define IVISWTCH_VAL_CAN_CONNECT_CLASS_EXT_BASE             (500L)
#define IVISWTCH_VAL_CAN_CONNECT_SPECIFIC_EXT_BASE          (1000L)

/*****************************************************************************
 *-------- IviSwtch Class Instrument Driver Function Declarations -----------*
 *****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviSwtch_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviSwtch_close (ViSession vi);

ViStatus _VI_FUNC IviSwtch_reset (ViSession vi);

ViStatus _VI_FUNC IviSwtch_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviSwtch_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviSwtch_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviSwtch_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviSwtch_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviSwtch_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviSwtch_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviSwtch_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviSwtch_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviSwtch_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviSwtch_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviSwtch_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviSwtch_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviSwtch_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviSwtch_GetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviSwtch_SetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViString (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviSwtch_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviSwtch_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviSwtch_GetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviSwtch_SetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviSwtch_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviSwtch_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviSwtch_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviSwtch_GetError (ViSession vi, 
                                     ViStatus *errorCode, 
                                     ViInt32 bufferSize, 
                                     ViChar description[]);

ViStatus _VI_FUNC IviSwtch_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviSwtch_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviSwtch_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviSwtch_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviSwtch_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviSwtch_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);
    /*- IviSwtchBase Capability Group Functions -*/
ViStatus _VI_FUNC IviSwtch_CanConnect (ViSession vi, 
                                       ViConstString channel1,
                                       ViConstString channel2, 
                                       ViInt32 *pathCapability);

ViStatus _VI_FUNC IviSwtch_Connect (ViSession vi, 
                                    ViConstString channel1,
                                    ViConstString channel2);

ViStatus _VI_FUNC IviSwtch_Disconnect (ViSession vi, 
                                       ViConstString channel1, 
                                       ViConstString channel2);

ViStatus _VI_FUNC IviSwtch_DisconnectAll (ViSession vi);

ViStatus _VI_FUNC IviSwtch_GetChannelName (ViSession vi,
                                           ViInt32 index,
                                           ViInt32 bufferSize,
                                           ViChar name[]);

ViStatus _VI_FUNC IviSwtch_GetPath (ViSession vi, 
                                    ViConstString channel1, 
                                    ViConstString channel2,
                                    ViInt32 bufferSize, 
                                    ViChar pathList[]);

ViStatus _VI_FUNC IviSwtch_IsDebounced (ViSession vi, 
                                        ViBoolean *isDebounced);

ViStatus _VI_FUNC IviSwtch_SetPath (ViSession vi, 
                                    ViConstString pathList);

ViStatus _VI_FUNC IviSwtch_WaitForDebounce (ViSession vi, 
                                            ViInt32 maxTime);

    /*- IviSwtchScanner Extension Group Functions -*/
ViStatus _VI_FUNC IviSwtch_AbortScan (ViSession vi);    

ViStatus _VI_FUNC IviSwtch_ConfigureScanList (ViSession vi, 
                                              ViConstString scanList, 
                                              ViInt32 scanMode);

ViStatus _VI_FUNC IviSwtch_ConfigureScanTrigger (ViSession vi, 
                                                 ViReal64 scanDelay, 
                                                 ViInt32 triggerInput, 
                                                 ViInt32 scanAdvancedOutput);

ViStatus _VI_FUNC IviSwtch_InitiateScan (ViSession vi);

ViStatus _VI_FUNC IviSwtch_IsScanning (ViSession vi, 
                                       ViBoolean *isScanning);

ViStatus _VI_FUNC IviSwtch_SetContinuousScan (ViSession vi, 
                                              ViBoolean status);

ViStatus _VI_FUNC IviSwtch_WaitForScanComplete (ViSession vi, 
                                                ViInt32 maxTime);

    /*- IviSwtchSoftwareTrigger Extension Group Functions -*/
ViStatus _VI_FUNC IviSwtch_SendSoftwareTrigger (ViSession vi);

/*****************************************************************************
 *---------------- IviSwtch Class Error And Completion Codes ----------------*
 *****************************************************************************/
#define IVISWTCH_WARN_PATH_REMAINS                  (IVI_CLASS_WARN_BASE +  1L)
#define IVISWTCH_WARN_IMPLICIT_CONNECTION_EXISTS    (IVI_CLASS_WARN_BASE +  2L)

#define IVISWTCH_ERROR_INVALID_SWITCH_PATH          (IVI_CLASS_ERROR_BASE + 1L)
#define IVISWTCH_ERROR_INVALID_SCAN_LIST            (IVI_CLASS_ERROR_BASE + 2L)
#define IVISWTCH_ERROR_RSRC_IN_USE                  (IVI_CLASS_ERROR_BASE + 3L)
#define IVISWTCH_ERROR_EMPTY_SCAN_LIST              (IVI_CLASS_ERROR_BASE + 4L)
#define IVISWTCH_ERROR_EMPTY_SWITCH_PATH            (IVI_CLASS_ERROR_BASE + 5L)
#define IVISWTCH_ERROR_SCAN_IN_PROGRESS             (IVI_CLASS_ERROR_BASE + 6L)
#define IVISWTCH_ERROR_NO_SCAN_IN_PROGRESS          (IVI_CLASS_ERROR_BASE + 7L)
#define IVISWTCH_ERROR_NO_SUCH_PATH                 (IVI_CLASS_ERROR_BASE + 8L)
#define IVISWTCH_ERROR_IS_CONFIGURATION_CHANNEL     (IVI_CLASS_ERROR_BASE + 9L)
#define IVISWTCH_ERROR_NOT_A_CONFIGURATION_CHANNEL  (IVI_CLASS_ERROR_BASE + 10L)
#define IVISWTCH_ERROR_ATTEMPT_TO_CONNECT_SOURCES   (IVI_CLASS_ERROR_BASE + 11L)
#define IVISWTCH_ERROR_EXPLICIT_CONNECTION_EXISTS   (IVI_CLASS_ERROR_BASE + 12L)
#define IVISWTCH_ERROR_LEG_MISSING_FIRST_CHANNEL    (IVI_CLASS_ERROR_BASE + 13L)
#define IVISWTCH_ERROR_LEG_MISSING_SECOND_CHANNEL   (IVI_CLASS_ERROR_BASE + 14L)
#define IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_LEG    (IVI_CLASS_ERROR_BASE + 15L)
#define IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_PATH   (IVI_CLASS_ERROR_BASE + 16L)
#define IVISWTCH_ERROR_PATH_NOT_FOUND               (IVI_CLASS_ERROR_BASE + 17L)
#define IVISWTCH_ERROR_DISCONTINUOUS_PATH           (IVI_CLASS_ERROR_BASE + 18L)
#define IVISWTCH_ERROR_CANNOT_CONNECT_DIRECTLY      (IVI_CLASS_ERROR_BASE + 19L)
#define IVISWTCH_ERROR_CHANNELS_ALREADY_CONNECTED   (IVI_CLASS_ERROR_BASE + 20L)
#define IVISWTCH_ERROR_CANNOT_CONNECT_TO_ITSELF     (IVI_CLASS_ERROR_BASE + 21L)
#define IVISWTCH_ERROR_MAX_TIME_EXCEEDED            (IVI_CLASS_ERROR_BASE + 22L)

#define IVISWTCH_ERROR_TRIGGER_NOT_SOFTWARE         (IVI_CROSS_CLASS_ERROR_BASE + 1)

#define IVISWTCH_WARNMSG_PATH_REMAINS               "Some connections remain "\
                                                    "after disconnecting."
#define IVISWTCH_WARNMSG_IMPLICIT_CONNECTION_EXISTS "The implicit connection exists between the channels."

#define IVISWTCH_ERRMSG_INVALID_SWITCH_PATH         "Invalid switch path list string."
#define IVISWTCH_ERRMSG_INVALID_SCAN_LIST           "Invalid scan list. "\
                                                    "The given scan list string does not have the correct syntax, "\
                                                    "or the scan list syntax cannot be implemented by the switch."
#define IVISWTCH_ERRMSG_RSRC_IN_USE                 "One of the channels in the path is a "\
                                                    "configuration channel that is in use."
#define IVISWTCH_ERRMSG_EMPTY_SCAN_LIST             "No scan list specified."
#define IVISWTCH_ERRMSG_EMPTY_SWITCH_PATH           "The specified path list string is empty."
#define IVISWTCH_ERRMSG_SCAN_IN_PROGRESS            "The switch module is currently scanning through the scan list."
#define IVISWTCH_ERRMSG_NO_SCAN_IN_PROGRESS         "The switch module is not currently scanning through the scan list."
#define IVISWTCH_ERRMSG_NO_SUCH_PATH                "No explicit path exists "\
                                                    "between the two channels."
#define IVISWTCH_ERRMSG_IS_CONFIGURATION_CHANNEL    "An explicit connection to a configuration channel is not allowed."
#define IVISWTCH_ERRMSG_NOT_A_CONFIGURATION_CHANNEL "One of the non-terminal "\
                                                    "channels in the path is not a "\
                                                    "configuration channel."
#define IVISWTCH_ERRMSG_ATTEMPT_TO_CONNECT_SOURCES  "A connection between two different sources is not allowed."
#define IVISWTCH_ERRMSG_EXPLICIT_CONNECTION_EXISTS  "An explicit connection "\
                                                    "between the channels already exists."
#define IVISWTCH_ERRMSG_LEG_MISSING_FIRST_CHANNEL   "A leg in the path does "\
                                                    "not begin with a channel name."
#define IVISWTCH_ERRMSG_LEG_MISSING_SECOND_CHANNEL  "A leg in the path is "\
                                                    "missing the second channel."
#define IVISWTCH_ERRMSG_CHANNEL_DUPLICATED_IN_LEG   "The first and the second "\
                                                    "channels in the leg are the same."
#define IVISWTCH_ERRMSG_CHANNEL_DUPLICATED_IN_PATH  "A channel name is "\
                                                    "duplicated in the path string."
#define IVISWTCH_ERRMSG_PATH_NOT_FOUND              "No path was found "\
                                                    "between the two channels."
#define IVISWTCH_ERRMSG_DISCONTINUOUS_PATH          "The first channel of a "\
                                                    "leg in the path is not the same as "\
                                                    "the second channel in the previous leg."
#define IVISWTCH_ERRMSG_CANNOT_CONNECT_DIRECTLY     "The path contains a leg "\
                                                    "with two channels that cannot be "\
                                                    "directly connected."
#define IVISWTCH_ERRMSG_CHANNELS_ALREADY_CONNECTED  "A leg in the path "\
                                                    "contains two channels that are "\
                                                    "already directly connected."
#define IVISWTCH_ERRMSG_CANNOT_CONNECT_TO_ITSELF    "A channel cannot be "\
                                                    "connected to itself."

#define IVISWTCH_ERRMSG_TRIGGER_NOT_SOFTWARE        "The trigger source is not set to "\
                                                    "software trigger."

#define IVISWTCH_ERRMSG_MAX_TIME_EXCEEDED           "Maximum time exceeded before the operation completed."

#define IVISWTCH_ERROR_CODES_AND_MSGS                                                             \
    {IVISWTCH_WARN_PATH_REMAINS,                    IVISWTCH_WARNMSG_PATH_REMAINS},               \
    {IVISWTCH_WARN_IMPLICIT_CONNECTION_EXISTS,      IVISWTCH_WARNMSG_IMPLICIT_CONNECTION_EXISTS}, \
    {IVISWTCH_ERROR_INVALID_SWITCH_PATH,            IVISWTCH_ERRMSG_INVALID_SWITCH_PATH},         \
    {IVISWTCH_ERROR_INVALID_SCAN_LIST,              IVISWTCH_ERRMSG_INVALID_SCAN_LIST},           \
    {IVISWTCH_ERROR_RSRC_IN_USE,                    IVISWTCH_ERRMSG_RSRC_IN_USE},                 \
    {IVISWTCH_ERROR_EMPTY_SCAN_LIST,                IVISWTCH_ERRMSG_EMPTY_SCAN_LIST},             \
    {IVISWTCH_ERROR_EMPTY_SWITCH_PATH,              IVISWTCH_ERRMSG_EMPTY_SWITCH_PATH},           \
    {IVISWTCH_ERROR_SCAN_IN_PROGRESS,               IVISWTCH_ERRMSG_SCAN_IN_PROGRESS},            \
    {IVISWTCH_ERROR_NO_SCAN_IN_PROGRESS,            IVISWTCH_ERRMSG_NO_SCAN_IN_PROGRESS},         \
    {IVISWTCH_ERROR_NO_SUCH_PATH,                   IVISWTCH_ERRMSG_NO_SUCH_PATH},                \
    {IVISWTCH_ERROR_IS_CONFIGURATION_CHANNEL,       IVISWTCH_ERRMSG_IS_CONFIGURATION_CHANNEL},    \
    {IVISWTCH_ERROR_NOT_A_CONFIGURATION_CHANNEL,    IVISWTCH_ERRMSG_NOT_A_CONFIGURATION_CHANNEL}, \
    {IVISWTCH_ERROR_ATTEMPT_TO_CONNECT_SOURCES,     IVISWTCH_ERRMSG_ATTEMPT_TO_CONNECT_SOURCES},  \
    {IVISWTCH_ERROR_EXPLICIT_CONNECTION_EXISTS,     IVISWTCH_ERRMSG_EXPLICIT_CONNECTION_EXISTS},  \
    {IVISWTCH_ERROR_LEG_MISSING_FIRST_CHANNEL,      IVISWTCH_ERRMSG_LEG_MISSING_FIRST_CHANNEL},   \
    {IVISWTCH_ERROR_LEG_MISSING_SECOND_CHANNEL,     IVISWTCH_ERRMSG_LEG_MISSING_SECOND_CHANNEL},  \
    {IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_LEG,      IVISWTCH_ERRMSG_CHANNEL_DUPLICATED_IN_LEG},   \
    {IVISWTCH_ERROR_CHANNEL_DUPLICATED_IN_PATH,     IVISWTCH_ERRMSG_CHANNEL_DUPLICATED_IN_PATH},  \
    {IVISWTCH_ERROR_PATH_NOT_FOUND,                 IVISWTCH_ERRMSG_PATH_NOT_FOUND},              \
    {IVISWTCH_ERROR_DISCONTINUOUS_PATH,             IVISWTCH_ERRMSG_DISCONTINUOUS_PATH},          \
    {IVISWTCH_ERROR_CANNOT_CONNECT_DIRECTLY,        IVISWTCH_ERRMSG_CANNOT_CONNECT_DIRECTLY},     \
    {IVISWTCH_ERROR_CHANNELS_ALREADY_CONNECTED,     IVISWTCH_ERRMSG_CHANNELS_ALREADY_CONNECTED},  \
    {IVISWTCH_ERROR_CANNOT_CONNECT_TO_ITSELF,       IVISWTCH_ERRMSG_CANNOT_CONNECT_TO_ITSELF},    \
    {IVISWTCH_ERROR_TRIGGER_NOT_SOFTWARE,           IVISWTCH_ERRMSG_TRIGGER_NOT_SOFTWARE},        \
	{IVISWTCH_ERROR_MAX_TIME_EXCEEDED,              IVISWTCH_ERRMSG_MAX_TIME_EXCEEDED}

/*- IviSwtchObsolete.h included for backwards compatibility -*/
#include "IviSwtchObsolete.h"

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVISWTCH_HEADER */
