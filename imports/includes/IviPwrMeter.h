/****************************************************************************
 *                         IVIPWRMETER                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       IviPwrMeter.h                                                    
 * Purpose:     IviPwrMeter Class declarations for the Base and Extended  
 *              IviPwrMeter Capabilities.                                        
 ****************************************************************************/

#ifndef IVIPWRMETER_HEADER
#define IVIPWRMETER_HEADER

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

#define IVIPWRMETER_MAJOR_VERSION              (4L)
#define IVIPWRMETER_MINOR_VERSION              (0L)

#define IVIPWRMETER_CLASS_SPEC_MAJOR_VERSION   (2L)
#define IVIPWRMETER_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVIPWRMETER_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIPWRMETER_DRIVER_DESCRIPTION         "IviPwrMeter Class Driver [Compiled for 64-bit.]"
#else
#define IVIPWRMETER_DRIVER_DESCRIPTION         "IviPwrMeter Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/
/*- Defined values for Operator parameter of function -*/
/*- IviPwrMeter_ConfigureMeasurement -*/
#define IVIPWRMETER_VAL_NONE                                                (0L)
#define IVIPWRMETER_VAL_DIFFERENCE                                          (1L)
#define IVIPWRMETER_VAL_SUM                                                 (2L)
#define IVIPWRMETER_VAL_QUOTIENT                                            (3L)

/*- Defined values for MeasurementStatus parameter of function -*/
/*- IviPwrMeter_IsMeasurementComplete -*/
#define IVIPWRMETER_VAL_MEAS_COMPLETE                                       (1L)
#define IVIPWRMETER_VAL_MEAS_IN_PROGRESS                                    (0L)
#define IVIPWRMETER_VAL_MEAS_STATUS_UNKNOWN                                 (-1L)

/*- Defined values for RangeType parameter of function -*/
/*- IviPwrMeter_QueryResultRangeType -*/
#define IVIPWRMETER_VAL_IN_RANGE                                            (0L)
#define IVIPWRMETER_VAL_UNDER_RANGE                                         (-1L)
#define IVIPWRMETER_VAL_OVER_RANGE                                          (1L)

/*- Defined values for MaxTime parameter of function -*/
/*- IviPwrMeter_Read -*/
/*- Defined values for MaxTime parameter of function -*/
/*- IviPwrMeter_ReadChannel -*/
#define IVIPWRMETER_VAL_MAX_TIME_IMMEDIATE                                  (0x0L)
#define IVIPWRMETER_VAL_MAX_TIME_INFINITE                                   (0xFFFFFFFFUL)

/*- Defined values for ZeroStatus parameter of function -*/
/*- IviPwrMeter_IsZeroComplete -*/
#define IVIPWRMETER_VAL_ZERO_COMPLETE                                       (1L)
#define IVIPWRMETER_VAL_ZERO_IN_PROGRESS                                    (0L)
#define IVIPWRMETER_VAL_ZERO_STATUS_UNKNOWN                                 (-1L)

/*- Defined values for CalibrationStatus parameter of function -*/
/*- IviPwrMeter_IsCalibrationComplete -*/
#define IVIPWRMETER_VAL_CALIBRATION_COMPLETE                                (1L)
#define IVIPWRMETER_VAL_CALIBRATION_IN_PROGRESS                             (0L)
#define IVIPWRMETER_VAL_CALIBRATION_STATUS_UNKNOWN                          (-1L)



/****************************************************************************
 *------------------ IviPwrMeter Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVIPWRMETER_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVIPWRMETER_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVIPWRMETER_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVIPWRMETER_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVIPWRMETER_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVIPWRMETER_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVIPWRMETER_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVIPWRMETER_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

	/* Instrument Capabilities */
#define IVIPWRMETER_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT                 /* ViInt32,  read-only  */

        /*- Instrument Capabilities -*/
#define IVIPWRMETER_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVIPWRMETER_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIPWRMETER_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVIPWRMETER_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVIPWRMETER_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVIPWRMETER_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVIPWRMETER_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVIPWRMETER_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                    /* ViString, read-only */
#define IVIPWRMETER_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIPWRMETER_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVIPWRMETER_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVIPWRMETER_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVIPWRMETER_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only */
  
        /*- Version Information -*/
#define IVIPWRMETER_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVIPWRMETER_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVIPWRMETER_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviPwrMeter Fundamental Attributes -*/
#define IVIPWRMETER_ATTR_AVERAGING_AUTO_ENABLED         (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)    /* ViBoolean */
#define IVIPWRMETER_ATTR_CORRECTION_FREQUENCY           (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)    /* ViReal64 */
#define IVIPWRMETER_ATTR_OFFSET                         (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)    /* ViReal64 */
#define IVIPWRMETER_ATTR_RANGE_AUTO_ENABLED             (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)    /* ViBoolean */
#define IVIPWRMETER_ATTR_UNITS                          (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)    /* ViInt32 */

    /*- IviPwrMeter Extended Attributes -*/
        /*- IviPwrMeterChannelAcquisition Extension Group -*/
#define IVIPWRMETER_ATTR_CHANNEL_ENABLED                (IVI_CLASS_PUBLIC_ATTR_BASE + 51L)   /* ViBoolean */

        /*- IviPwrMeterManualRange Extension Group -*/
#define IVIPWRMETER_ATTR_RANGE_LOWER                    (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* ViReal64 */
#define IVIPWRMETER_ATTR_RANGE_UPPER                    (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)  /* ViReal64 */

        /*- IviPwrMeterTriggerSource Extension Group -*/
#define IVIPWRMETER_ATTR_TRIGGER_SOURCE                 (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* ViInt32 */

        /*- IviPwrMeterInternalTrigger Extension Group -*/
#define IVIPWRMETER_ATTR_INTERNAL_TRIGGER_EVENT_SOURCE  (IVI_CLASS_PUBLIC_ATTR_BASE + 251L)  /* ViString */
#define IVIPWRMETER_ATTR_INTERNAL_TRIGGER_LEVEL         (IVI_CLASS_PUBLIC_ATTR_BASE + 252L)  /* ViReal64 */
#define IVIPWRMETER_ATTR_INTERNAL_TRIGGER_SLOPE         (IVI_CLASS_PUBLIC_ATTR_BASE + 253L)  /* ViInt32 */

        /*- IviPwrMeterAveragingCount Extension Group -*/
#define IVIPWRMETER_ATTR_AVERAGING_COUNT                (IVI_CLASS_PUBLIC_ATTR_BASE + 301L)  /* ViInt32 */

        /*- IviPwrMeterDutyCycleCorrection Extension Group -*/
#define IVIPWRMETER_ATTR_DUTY_CYCLE_CORRECTION          (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* ViReal64 */
#define IVIPWRMETER_ATTR_DUTY_CYCLE_CORRECTION_ENABLED  (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* ViBoolean */

        /*- IviPwrMeterReferenceOscillator Extension Group -*/
#define IVIPWRMETER_ATTR_REF_OSCILLATOR_ENABLED         (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* ViBoolean */
#define IVIPWRMETER_ATTR_REF_OSCILLATOR_FREQUENCY       (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* ViReal64 */
#define IVIPWRMETER_ATTR_REF_OSCILLATOR_LEVEL           (IVI_CLASS_PUBLIC_ATTR_BASE + 503L)  /* ViReal64 */


/****************************************************************************
 *----------------- IviPwrMeter Class Attribute Value Defines -----------------*
 ****************************************************************************/
/*- Defined values for attribute IVIPWRMETER_ATTR_UNITS -*/
#define IVIPWRMETER_VAL_DBM                                                 (1L)
#define IVIPWRMETER_VAL_DBMV                                                (2L)
#define IVIPWRMETER_VAL_DBUV                                                (3L)
#define IVIPWRMETER_VAL_WATTS                                               (4L)
#define IVIPWRMETER_VAL_UNITS_CLASS_EXT_BASE                                (500L)
#define IVIPWRMETER_VAL_UNITS_SPECIFIC_EXT_BASE                             (1000L)

/*- Defined values for attribute IVIPWRMETER_ATTR_TRIGGER_SOURCE -*/
#define IVIPWRMETER_VAL_IMMEDIATE                                           (1L)
#define IVIPWRMETER_VAL_EXTERNAL                                            (2L)
#define IVIPWRMETER_VAL_INTERNAL                                            (3L)
#define IVIPWRMETER_VAL_SOFTWARE_TRIG                                       (4L)
#define IVIPWRMETER_VAL_TTL0                                                (100L)
#define IVIPWRMETER_VAL_TTL1                                                (101L)
#define IVIPWRMETER_VAL_TTL2                                                (102L)
#define IVIPWRMETER_VAL_TTL3                                                (103L)
#define IVIPWRMETER_VAL_TTL4                                                (104L)
#define IVIPWRMETER_VAL_TTL5                                                (105L)
#define IVIPWRMETER_VAL_TTL6                                                (106L)
#define IVIPWRMETER_VAL_TTL7                                                (107L)
#define IVIPWRMETER_VAL_ECL0                                                (200L)
#define IVIPWRMETER_VAL_ECL1                                                (201L)
#define IVIPWRMETER_VAL_PXI_STAR                                            (300L)
#define IVIPWRMETER_VAL_RTSI_0                                              (400L)
#define IVIPWRMETER_VAL_RTSI_1                                              (401L)
#define IVIPWRMETER_VAL_RTSI_2                                              (402L)
#define IVIPWRMETER_VAL_RTSI_3                                              (403L)
#define IVIPWRMETER_VAL_RTSI_4                                              (404L)
#define IVIPWRMETER_VAL_RTSI_5                                              (405L)
#define IVIPWRMETER_VAL_RTSI_6                                              (406L)
#define IVIPWRMETER_VAL_TRIGGER_SOURCE_CLASS_EXT_BASE                       (500L)
#define IVIPWRMETER_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE                    (1000L)

/*- Defined values for attribute IVIPWRMETER_ATTR_INTERNAL_TRIGGER_SLOPE -*/
#define IVIPWRMETER_VAL_NEGATIVE                                            (0L)
#define IVIPWRMETER_VAL_POSITIVE                                            (1L)
#define IVIPWRMETER_VAL_TRIGGER_SLOPE_CLASS_EXT_BASE                        (500L)
#define IVIPWRMETER_VAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE                     (1000L)
#define IVIPWRMETER_VAL_INTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE               (500L)
#define IVIPWRMETER_VAL_INTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE            (1000L)

/****************************************************************************
*----------------- IviPwrMeter Function Parameter Value Defines -----------------*
****************************************************************************/
/*- Defined values for Configure Measurement -*/
#define IVIPWRMETER_VAL_OPERATOR_CLASS_EXT_BASE                             (500L)
#define IVIPWRMETER_VAL_OPERATOR_SPECIFIC_EXT_BASE                          (1000L)

/****************************************************************************
 *--------- IviPwrMeter Class Instrument Driver Function Declarations ---------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviPwrMeter_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviPwrMeter_close (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_reset (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviPwrMeter_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviPwrMeter_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviPwrMeter_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);
    /*- Utility Functions -*/
ViStatus _VI_FUNC IviPwrMeter_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviPwrMeter_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviPwrMeter_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviPwrMeter_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviPwrMeter_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviPwrMeter_GetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViString (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviPwrMeter_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviPwrMeter_GetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviPwrMeter_SetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviPwrMeter_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviPwrMeter_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviPwrMeter_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviPwrMeter_GetError (ViSession vi, 
                                   ViStatus *errorCode, 
                                   ViInt32 bufferSize, 
                                   ViChar description[]);

ViStatus _VI_FUNC IviPwrMeter_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviPwrMeter_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviPwrMeter_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviPwrMeter_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviPwrMeter_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);

    /*- IviPwrMeter Fundamental Capabilities -*/
ViStatus _VI_FUNC IviPwrMeter_Abort (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_ConfigureAveragingAutoEnabled (ViSession vi,
                                                             ViConstString Channel,
                                                             ViBoolean AveragingAutoEnabled);

ViStatus _VI_FUNC IviPwrMeter_ConfigureCorrectionFrequency (ViSession vi,
                                                            ViConstString Channel,
                                                            ViReal64 CorrectionFrequency);

ViStatus _VI_FUNC IviPwrMeter_ConfigureMeasurement (ViSession vi,
                                                    ViInt32 Operator,
                                                    ViConstString Operand1,
                                                    ViConstString Operand2);

ViStatus _VI_FUNC IviPwrMeter_ConfigureOffset (ViSession vi,
                                               ViConstString Channel,
                                               ViReal64 Offset);

ViStatus _VI_FUNC IviPwrMeter_ConfigureRangeAutoEnabled (ViSession vi,
                                                         ViConstString Channel,
                                                         ViBoolean RangeAutoEnabled);

ViStatus _VI_FUNC IviPwrMeter_ConfigureUnits (ViSession vi,
                                              ViInt32 Units);

ViStatus _VI_FUNC IviPwrMeter_Fetch (ViSession vi,
                                     ViReal64* Result);

ViStatus _VI_FUNC IviPwrMeter_GetChannelName (ViSession vi,
                                              ViInt32 ChannelIndex,
                                              ViInt32 ChannelNameBufferSize,
                                              ViChar ChannelName[]);

ViStatus _VI_FUNC IviPwrMeter_Initiate (ViSession vi);

ViStatus _VI_FUNC IviPwrMeter_IsMeasurementComplete (ViSession vi,
                                                     ViInt32* MeasurementStatus);

ViStatus _VI_FUNC IviPwrMeter_QueryResultRangeType (ViSession vi,
                                                    ViReal64 MeasurementValue,
                                                    ViInt32* RangeType);

ViStatus _VI_FUNC IviPwrMeter_Read (ViSession vi,
                                    ViInt32 MaxTime,
                                    ViReal64* Result);


    /*- IviPwrMeterChannelAcquisition Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureChannelEnabled (ViSession vi,
                                                       ViConstString Channel,
                                                       ViBoolean ChannelEnabled);

ViStatus _VI_FUNC IviPwrMeter_FetchChannel (ViSession vi,
                                            ViConstString Channel,
                                            ViReal64* Result);

ViStatus _VI_FUNC IviPwrMeter_ReadChannel (ViSession vi,
                                           ViConstString Channel,
                                           ViInt32 MaxTime,
                                           ViReal64* Result);


    /*- IviPwrMeterManualRange Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureRange (ViSession vi,
                                              ViConstString Channel,
                                              ViReal64 RangeLower,
                                              ViReal64 RangeUpper);


    /*- IviPwrMeterTriggerSource Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureTriggerSource (ViSession vi,
                                                      ViInt32 TriggerSource);


    /*- IviPwrMeterInternalTrigger Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureInternalTrigger (ViSession vi,
                                                        ViConstString EventSource,
                                                        ViInt32 Slope);

ViStatus _VI_FUNC IviPwrMeter_ConfigureInternalTriggerLevel (ViSession vi,
                                                             ViReal64 TriggerLevel);


    /*- IviPwrMeterSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_SendSoftwareTrigger (ViSession vi);


    /*- IviPwrMeterAveragingCount Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureAveragingCount (ViSession vi,
                                                       ViConstString Channel,
                                                       ViInt32 Count);


    /*- IviPwrMeterZeroCorrection Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_IsZeroComplete (ViSession vi,
                                              ViInt32* ZeroStatus);

ViStatus _VI_FUNC IviPwrMeter_Zero (ViSession vi,
                                    ViConstString Channel);

ViStatus _VI_FUNC IviPwrMeter_ZeroAllChannels (ViSession vi);


    /*- IviPwrMeterDutyCycleCorrection Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureDutyCycleCorrection (ViSession vi,
                                                            ViConstString Channel,
                                                            ViBoolean CorrectionEnabled,
                                                            ViReal64 Correction);


    /*- IviPwrMeterCalibration Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_Calibrate (ViSession vi,
                                         ViConstString Channel);

ViStatus _VI_FUNC IviPwrMeter_IsCalibrationComplete (ViSession vi,
                                                     ViInt32* CalibrationStatus);


    /*- IviPwrMeterReferenceOscillator Extension Group -*/
ViStatus _VI_FUNC IviPwrMeter_ConfigureRefOscillator (ViSession vi,
                                                      ViReal64 Frequency,
                                                      ViReal64 Level);

ViStatus _VI_FUNC IviPwrMeter_ConfigureRefOscillatorEnabled (ViSession vi,
                                                             ViBoolean RefOscillatorEnabled);



/****************************************************************************
 *--------------- IviPwrMeter Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVIPWRMETER_WARN_UNDER_RANGE             (IVI_CLASS_WARN_BASE + 0x0001L)
#define IVIPWRMETER_WARN_OVER_RANGE              (IVI_CLASS_WARN_BASE + 0x0002L)

#define IVIPWRMETER_ERROR_CHANNEL_NOT_ENABLED    (IVI_CLASS_ERROR_BASE + 0x0001L)
#define IVIPWRMETER_ERROR_MAX_TIME_EXCEEDED      (IVI_CLASS_ERROR_BASE + 0x0020L)
#define IVIPWRMETER_ERROR_TRIGGER_NOT_SOFTWARE   (IVI_CROSS_CLASS_ERROR_BASE + 0x0001L)



#define IVIPWRMETER_WARNMSG_UNDER_RANGE          "Measurement is under range."
#define IVIPWRMETER_WARNMSG_OVER_RANGE           "Measurement is over range."

#define IVIPWRMETER_ERRMSG_CHANNEL_NOT_ENABLED   "The specified channel is not enabled for measurement."
#define IVIPWRMETER_ERRMSG_MAX_TIME_EXCEEDED     "Maximum timeout exceeded before operation could complete."
#define IVIPWRMETER_ERRMSG_TRIGGER_NOT_SOFTWARE  "The trigger source is not set to software trigger."



#define IVIPWRMETER_ERROR_CODES_AND_MSGS \
    {IVIPWRMETER_WARN_UNDER_RANGE,           IVIPWRMETER_WARNMSG_UNDER_RANGE},\
    {IVIPWRMETER_WARN_OVER_RANGE,            IVIPWRMETER_WARNMSG_OVER_RANGE},\
    {IVIPWRMETER_ERROR_CHANNEL_NOT_ENABLED,  IVIPWRMETER_ERRMSG_CHANNEL_NOT_ENABLED},\
    {IVIPWRMETER_ERROR_MAX_TIME_EXCEEDED,    IVIPWRMETER_ERRMSG_MAX_TIME_EXCEEDED},\
    {IVIPWRMETER_ERROR_TRIGGER_NOT_SOFTWARE, IVIPWRMETER_ERRMSG_TRIGGER_NOT_SOFTWARE}


/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVIPWRMETER_HEADER */
