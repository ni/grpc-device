/****************************************************************************
 *                           I V I - D C P W R                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2000-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       ividcpwr.h                                                    
 * Purpose:     IviDCPwr Class declarations for the Base and Extended  
 *              IviDCPwr Capabilities.                                        
 ****************************************************************************/

#ifndef IVIDCPWR_HEADER
#define IVIDCPWR_HEADER

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

#define IVIDCPWR_MAJOR_VERSION              (4L)
#define IVIDCPWR_MINOR_VERSION              (0L)

#define IVIDCPWR_CLASS_SPEC_MAJOR_VERSION   (3L)
#define IVIDCPWR_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVIDCPWR_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIDCPWR_DRIVER_DESCRIPTION         "IviDCPwr Class Driver [Compiled for 64-bit.]"
#else
#define IVIDCPWR_DRIVER_DESCRIPTION         "IviDCPwr Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/

    /*- Defined values for rangeType parameter of function -*/
    /*- IviDCPwr_ConfigureOutputRange -*/
#define IVIDCPWR_VAL_RANGE_CURRENT                  (0L)
#define IVIDCPWR_VAL_RANGE_VOLTAGE                  (1L)

#define IVIDCPWR_VAL_RANGE_TYPE_CLASS_EXT_BASE      (500L)
#define IVIDCPWR_VAL_RANGE_TYPE_SPECIFIC_EXT_BASE   (1000L)

    /*- Defined values for outputState parameter of function -*/
    /*- IviDCPwr_QueryOutputState -*/
#define IVIDCPWR_VAL_OUTPUT_CONSTANT_VOLTAGE        (0L)
#define IVIDCPWR_VAL_OUTPUT_CONSTANT_CURRENT        (1L)
#define IVIDCPWR_VAL_OUTPUT_OVER_VOLTAGE            (2L)
#define IVIDCPWR_VAL_OUTPUT_OVER_CURRENT            (3L)
#define IVIDCPWR_VAL_OUTPUT_UNREGULATED             (4L)

#define IVIDCPWR_VAL_OUTPUT_STATE_CLASS_EXT_BASE    (500L)
#define IVIDCPWR_VAL_OUTPUT_STATE_SPECIFIC_EXT_BASE (1000L)

    /*- Defined values for measurementType parameter of function -*/
    /*- IviDCPwr_Measure -*/
#define IVIDCPWR_VAL_MEASURE_CURRENT            (0L)
#define IVIDCPWR_VAL_MEASURE_VOLTAGE            (1L)

#define IVIDCPWR_VAL_MEASURE_CLASS_EXT_BASE     (500L)
#define IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE  (1000L)

/****************************************************************************
 *------------------ IviDCPwr Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVIDCPWR_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVIDCPWR_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVIDCPWR_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVIDCPWR_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVIDCPWR_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVIDCPWR_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVIDCPWR_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVIDCPWR_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIDCPWR_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVIDCPWR_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIDCPWR_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVIDCPWR_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVIDCPWR_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVIDCPWR_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVIDCPWR_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                       /* ViString, read-only */
#define IVIDCPWR_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIDCPWR_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVIDCPWR_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVIDCPWR_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVIDCPWR_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only */
    
        /*- Version Information -*/
#define IVIDCPWR_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVIDCPWR_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviDCPwr Fundamental Attributes -*/
#define IVIDCPWR_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT                 /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_VOLTAGE_LEVEL             (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)      /* ViReal64,  multi-channel */
#define IVIDCPWR_ATTR_OVP_ENABLED               (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)      /* ViBoolean, multi-channel */
#define IVIDCPWR_ATTR_OVP_LIMIT                 (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)      /* ViReal64,  multi-channel */
#define IVIDCPWR_ATTR_CURRENT_LIMIT_BEHAVIOR    (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)      /* ViInt32,   multi-channel */
#define IVIDCPWR_ATTR_CURRENT_LIMIT             (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)      /* ViReal64,  multi-channel */
#define IVIDCPWR_ATTR_OUTPUT_ENABLED            (IVI_CLASS_PUBLIC_ATTR_BASE + 6L)      /* ViBoolean, multi-channel */

    /*- IviDCPwr Extended Attributes -*/
        /*- Trigger Attributes -*/
#define IVIDCPWR_ATTR_TRIGGER_SOURCE            (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)    /* ViInt32,   multi-channel */
#define IVIDCPWR_ATTR_TRIGGERED_CURRENT_LIMIT   (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)    /* ViReal64,  multi-channel */
#define IVIDCPWR_ATTR_TRIGGERED_VOLTAGE_LEVEL   (IVI_CLASS_PUBLIC_ATTR_BASE + 103L)    /* ViReal64,  multi-channel */

/****************************************************************************
 *----------------- IviDCPwr Class Attribute Value Defines -----------------*
 ****************************************************************************/

    /*- Defined values for attribute IVIDCPWR_ATTR_CURRENT_LIMIT_BEHAVIOR -*/
#define IVIDCPWR_VAL_CURRENT_REGULATE                           (0L)
#define IVIDCPWR_VAL_CURRENT_TRIP                               (1L)

#define IVIDCPWR_VAL_CURRENT_LIMIT_BEHAVIOR_CLASS_EXT_BASE      (500L)
#define IVIDCPWR_VAL_CURRENT_LIMIT_BEHAVIOR_SPECIFIC_EXT_BASE   (1000L)

    /*- Defined values for attribute IVIDCPWR_ATTR_TRIGGER_SOURCE -*/
#define IVIDCPWR_VAL_TRIG_IMMEDIATE                         (0L)
#define IVIDCPWR_VAL_TRIG_EXTERNAL                          (1L)
#define IVIDCPWR_VAL_SOFTWARE_TRIG                          (2L)
#define IVIDCPWR_VAL_TRIG_TTL0                              (3L)
#define IVIDCPWR_VAL_TRIG_TTL1                              (4L)
#define IVIDCPWR_VAL_TRIG_TTL2                              (5L)
#define IVIDCPWR_VAL_TRIG_TTL3                              (6L)
#define IVIDCPWR_VAL_TRIG_TTL4                              (7L)
#define IVIDCPWR_VAL_TRIG_TTL5                              (8L)
#define IVIDCPWR_VAL_TRIG_TTL6                              (9L)
#define IVIDCPWR_VAL_TRIG_TTL7                              (10L)
#define IVIDCPWR_VAL_TRIG_ECL0                              (11L)
#define IVIDCPWR_VAL_TRIG_ECL1                              (12L)
#define IVIDCPWR_VAL_TRIG_PXI_STAR                          (13L)
#define IVIDCPWR_VAL_TRIG_RTSI_0                            (14L)
#define IVIDCPWR_VAL_TRIG_RTSI_1                            (15L)
#define IVIDCPWR_VAL_TRIG_RTSI_2                            (16L)
#define IVIDCPWR_VAL_TRIG_RTSI_3                            (17L)
#define IVIDCPWR_VAL_TRIG_RTSI_4                            (18L)
#define IVIDCPWR_VAL_TRIG_RTSI_5                            (19L)
#define IVIDCPWR_VAL_TRIG_RTSI_6                            (20L)

#define IVIDCPWR_VAL_TRIG_SRC_CLASS_EXT_BASE                (500L)
#define IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE             (1000L)

/****************************************************************************
 *--------- IviDCPwr Class Instrument Driver Function Declarations ---------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviDCPwr_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviDCPwr_close (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_reset (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviDCPwr_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviDCPwr_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviDCPwr_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviDCPwr_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_Disable (ViSession vi);


    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviDCPwr_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviDCPwr_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviDCPwr_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviDCPwr_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviDCPwr_GetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViString (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviDCPwr_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviDCPwr_GetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviDCPwr_SetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviDCPwr_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviDCPwr_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviDCPwr_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviDCPwr_GetError (ViSession vi, 
                                     ViStatus *errorCode, 
                                     ViInt32 bufferSize, 
                                     ViChar description[]);

ViStatus _VI_FUNC IviDCPwr_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviDCPwr_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviDCPwr_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviDCPwr_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviDCPwr_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);

ViStatus _VI_FUNC IviDCPwr_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);

    /*- IviDCPwrBase Functions -*/
ViStatus _VI_FUNC IviDCPwr_ConfigureOutputEnabled (ViSession vi,
                                                   ViConstString channelName,
                                                   ViBoolean enabled);

ViStatus _VI_FUNC IviDCPwr_ConfigureOutputRange (ViSession vi,
                                                 ViConstString channelName,
                                                 ViInt32 rangeType,
                                                 ViReal64 range);

ViStatus _VI_FUNC IviDCPwr_ConfigureCurrentLimit (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 behavior,
                                                  ViReal64 limit);

ViStatus _VI_FUNC IviDCPwr_ConfigureOVP (ViSession vi,
                                         ViConstString channelName,
                                         ViBoolean enabled,
                                         ViReal64 limit);

ViStatus _VI_FUNC IviDCPwr_ConfigureVoltageLevel (ViSession vi,
                                                  ViConstString channelName,
                                                  ViReal64 level);

ViStatus _VI_FUNC IviDCPwr_GetChannelName (ViSession vi,
                                           ViInt32 index,
                                           ViInt32 bufferSize,
                                           ViChar name[]);

ViStatus _VI_FUNC IviDCPwr_QueryOutputState (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 outputState,
                                             ViBoolean* inState);

ViStatus _VI_FUNC IviDCPwr_QueryMaxCurrentLimit (ViSession vi,
                                                 ViConstString channelName,
                                                 ViReal64 voltageLevel,
                                                 ViReal64* maxCurrentLimit);

ViStatus _VI_FUNC IviDCPwr_QueryMaxVoltageLevel (ViSession vi,
                                                 ViConstString channelName,
                                                 ViReal64 currentLimit,
                                                 ViReal64* maxVoltageLevel);

ViStatus _VI_FUNC IviDCPwr_ResetOutputProtection (ViSession vi,
                                                  ViConstString channelName);

    /*- IviDcPwrTrigger Functions -*/
ViStatus _VI_FUNC IviDCPwr_ConfigureTriggerSource (ViSession vi,
                                                   ViConstString channelName,
                                                   ViInt32 source);

ViStatus _VI_FUNC IviDCPwr_ConfigureTriggeredVoltageLevel (ViSession vi,
                                                           ViConstString channelName,
                                                           ViReal64 level);

ViStatus _VI_FUNC IviDCPwr_ConfigureTriggeredCurrentLimit (ViSession vi,
                                                           ViConstString channelName,
                                                           ViReal64 limit);

ViStatus _VI_FUNC IviDCPwr_Abort (ViSession vi);

ViStatus _VI_FUNC IviDCPwr_Initiate (ViSession vi);

    /*- IviDCPwrSoftwareTrigger Functions -*/
ViStatus _VI_FUNC IviDCPwr_SendSoftwareTrigger (ViSession vi);

    /*- IviDCPwrMeasure Functions -*/
ViStatus _VI_FUNC IviDCPwr_Measure (ViSession vi,
                                    ViConstString channelName,
                                    ViInt32 measurementType,
                                    ViReal64* measurement);

/****************************************************************************
 *--------------- IviDCPwr Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVIDCPWR_ERROR_TRIGGER_NOT_SOFTWARE   (IVI_CROSS_CLASS_ERROR_BASE + 1L)

#define IVIDCPWR_ERRMSG_TRIGGER_NOT_SOFTWARE  "The trigger source is not set to software trigger."

#define IVIDCPWR_ERROR_CODES_AND_MSGS \
        {IVIDCPWR_ERROR_TRIGGER_NOT_SOFTWARE, IVIDCPWR_ERRMSG_TRIGGER_NOT_SOFTWARE}

/*- IviDCPwrObsolete.h included for backwards compatibility -*/
#include "IviDCPwrObsolete.h"

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVIDCPWR_HEADER */

