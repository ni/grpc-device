/****************************************************************************
 *                              I V I - D M M                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 1999-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       ividmm.h                                                    
 * Purpose:     IviDmm Class declarations for the Base and Extended  
 *              IviDmm Capabilities.                                        
 ****************************************************************************/

#ifndef IVIDMM_HEADER
#define IVIDMM_HEADER

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

#define IVIDMM_MAJOR_VERSION                (4L)
#define IVIDMM_MINOR_VERSION                (0L)

#define IVIDMM_CLASS_SPEC_MAJOR_VERSION     (4L)
#define IVIDMM_CLASS_SPEC_MINOR_VERSION     (1L)

#define IVIDMM_DRIVER_VENDOR                "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIDMM_DRIVER_DESCRIPTION           "IviDmm Class Driver [Compiled for 64-bit.]"
#else
#define IVIDMM_DRIVER_DESCRIPTION           "IviDmm Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/
    /*- Defined values for maxTime parameter to the Measure, Read -*/
    /*- and Fetch functions -*/
#define IVIDMM_VAL_MAX_TIME_INFINITE    IVI_VAL_MAX_TIME_INFINITE
#define IVIDMM_VAL_MAX_TIME_IMMEDIATE   IVI_VAL_MAX_TIME_IMMEDIATE

/****************************************************************************
 *--------------------- IviDmm Class Attribute Defines ---------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVIDMM_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIDMM_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIDMM_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS     /* ViBoolean */
#define IVIDMM_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIDMM_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIDMM_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIDMM_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVIDMM_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIDMM_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIDMM_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIDMM_ATTR_CLASS_DRIVER_PREFIX                     IVI_ATTR_CLASS_DRIVER_PREFIX         /* ViString, read-only */
#define IVIDMM_ATTR_CLASS_DRIVER_VENDOR                     IVI_ATTR_CLASS_DRIVER_VENDOR         /* ViString, read-only */
#define IVIDMM_ATTR_CLASS_DRIVER_DESCRIPTION                IVI_ATTR_CLASS_DRIVER_DESCRIPTION    /* ViString, read-only */
#define IVIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION   IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIDMM_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      /* ViString, read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     /* ViString, read-only */
#define IVIDMM_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      /* ViString, read-only */
#define IVIDMM_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                /* ViString, read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      /* ViString, read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION /* ViString, read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIDMM_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIDMM_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIDMM_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIDMM_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /*- Version Information -*/
#define IVIDMM_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION              /* ViString, read-only */

#define IVIDMM_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION             /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIDMM_ATTR_DRIVER_SETUP              IVI_ATTR_DRIVER_SETUP                /* ViString */

    /*- IviDmm Fundamental Attributes -*/
#define IVIDMM_ATTR_FUNCTION                  (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)    /* ViInt32  */
#define IVIDMM_ATTR_RANGE                     (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)    /* ViReal64 */
#define IVIDMM_ATTR_RESOLUTION_ABSOLUTE       (IVI_CLASS_PUBLIC_ATTR_BASE + 8L)    /* ViReal64 */
#define IVIDMM_ATTR_TRIGGER_SOURCE            (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)    /* ViInt32  */
#define IVIDMM_ATTR_TRIGGER_DELAY             (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)    /* ViReal64 */

    /*- IviDmmAcMeasurement Attributes -*/
#define IVIDMM_ATTR_AC_MIN_FREQ               (IVI_CLASS_PUBLIC_ATTR_BASE + 6L)    /* ViReal64 */
#define IVIDMM_ATTR_AC_MAX_FREQ               (IVI_CLASS_PUBLIC_ATTR_BASE + 7L)    /* ViReal64 */

    /*- IviDmmFrequencyMeasurement Attributes -*/
#define IVIDMM_ATTR_FREQ_VOLTAGE_RANGE        (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* ViReal64 */

    /*- IviDmmTemperatureMeasurement Attributes -*/
#define IVIDMM_ATTR_TEMP_TRANSDUCER_TYPE      (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* ViInt32  */

    /*- IviDmmThermocouple Attributes -*/
#define IVIDMM_ATTR_TEMP_TC_TYPE              (IVI_CLASS_PUBLIC_ATTR_BASE + 231L)  /* ViInt32  */
#define IVIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE     (IVI_CLASS_PUBLIC_ATTR_BASE + 232L)  /* ViInt32  */
#define IVIDMM_ATTR_TEMP_TC_FIXED_REF_JUNC    (IVI_CLASS_PUBLIC_ATTR_BASE + 233L)  /* ViReal64 */

    /*- IviDmmResistanceTemperatureDevice Attributes -*/
#define IVIDMM_ATTR_TEMP_RTD_ALPHA            (IVI_CLASS_PUBLIC_ATTR_BASE + 241L)  /* ViReal64 */
#define IVIDMM_ATTR_TEMP_RTD_RES              (IVI_CLASS_PUBLIC_ATTR_BASE + 242L)  /* ViReal64 */

    /*- IviDmmThermistor Attributes -*/
#define IVIDMM_ATTR_TEMP_THERMISTOR_RES       (IVI_CLASS_PUBLIC_ATTR_BASE + 251L)  /* ViReal64 */

    /*- IviDmmMultiPoint Attributes -*/
#define IVIDMM_ATTR_SAMPLE_COUNT              (IVI_CLASS_PUBLIC_ATTR_BASE + 301L)  /* ViInt32  */
#define IVIDMM_ATTR_SAMPLE_TRIGGER            (IVI_CLASS_PUBLIC_ATTR_BASE + 302L)  /* ViInt32  */
#define IVIDMM_ATTR_SAMPLE_INTERVAL           (IVI_CLASS_PUBLIC_ATTR_BASE + 303L)  /* ViReal64 */
#define IVIDMM_ATTR_TRIGGER_COUNT             (IVI_CLASS_PUBLIC_ATTR_BASE + 304L)  /* ViInt32  */
#define IVIDMM_ATTR_MEAS_COMPLETE_DEST        (IVI_CLASS_PUBLIC_ATTR_BASE + 305L)  /* ViInt32  */

    /*- IviDmmTriggerSlope Attributes -*/
#define IVIDMM_ATTR_TRIGGER_SLOPE             (IVI_CLASS_PUBLIC_ATTR_BASE + 334L)  /* ViInt32  */

    /*- IviDmmDeviceInfo Attributes -*/
#define IVIDMM_ATTR_APERTURE_TIME             (IVI_CLASS_PUBLIC_ATTR_BASE + 321L)  /* ViReal64, read-only */
#define IVIDMM_ATTR_APERTURE_TIME_UNITS       (IVI_CLASS_PUBLIC_ATTR_BASE + 322L)  /* ViInt32,  read-only */

    /*- IviDmmAutoRangeValue Attributes -*/
#define IVIDMM_ATTR_AUTO_RANGE_VALUE          (IVI_CLASS_PUBLIC_ATTR_BASE + 331L)  /* ViReal64, read-only */

    /*- IviDmmAutoZero Attributes -*/
#define IVIDMM_ATTR_AUTO_ZERO                 (IVI_CLASS_PUBLIC_ATTR_BASE + 332L)  /* ViInt32  */

    /*- IviDmmPowerLineFrequency Attributes -*/
#define IVIDMM_ATTR_POWERLINE_FREQ            (IVI_CLASS_PUBLIC_ATTR_BASE + 333L)  /* ViReal64 */


/****************************************************************************
 *----------------- IviDmm Class Attribute Value Defines -------------------*
 ****************************************************************************/

    /*- Defined values for attribute IVIDMM_ATTR_FUNCTION -*/
#define IVIDMM_VAL_DC_VOLTS                     (1L)
#define IVIDMM_VAL_AC_VOLTS                     (2L)
#define IVIDMM_VAL_DC_CURRENT                   (3L)
#define IVIDMM_VAL_AC_CURRENT                   (4L)
#define IVIDMM_VAL_2_WIRE_RES                   (5L)
#define IVIDMM_VAL_4_WIRE_RES                   (101L)
#define IVIDMM_VAL_AC_PLUS_DC_VOLTS             (106L)
#define IVIDMM_VAL_AC_PLUS_DC_CURRENT           (107L)
#define IVIDMM_VAL_FREQ                         (104L)
#define IVIDMM_VAL_PERIOD                       (105L)
#define IVIDMM_VAL_TEMPERATURE                  (108L)

#define IVIDMM_VAL_FUNC_CLASS_EXT_BASE          (500L)
#define IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE       (1000L)

    /*- Defined values for attribute IVIDMM_ATTR_RANGE -*/
#define IVIDMM_VAL_AUTO_RANGE_ON                (-1.0)
#define IVIDMM_VAL_AUTO_RANGE_OFF               (-2.0)
#define IVIDMM_VAL_AUTO_RANGE_ONCE              (-3.0)

#define IVIDMM_VAL_RANGE_CLASS_EXT_BASE         (-100.0)
#define IVIDMM_VAL_RANGE_SPECIFIC_EXT_BASE      (-1000.0)

    /*- Defined values for attribute IVIDMM_ATTR_FREQ_VOLTAGE_RANGE -*/
/* #define IVIDMM_VAL_AUTO_RANGE_ON                DEFINED ABOVE */
/* #define IVIDMM_VAL_AUTO_RANGE_OFF               DEFINED ABOVE */

#define IVIDMM_VAL_FREQ_VOLT_RANGE_CLASS_EXT_BASE    (-100.0L)
#define IVIDMM_VAL_FREQ_VOLT_RANGE_SPECIFIC_EXT_BASE (-1000.0L)

    /*- Defined values for attribute IVIDMM_ATTR_TRIGGER_DELAY -*/
#define IVIDMM_VAL_AUTO_DELAY_ON                    (-1.0L)
#define IVIDMM_VAL_AUTO_DELAY_OFF                   (-2.0L)

#define IVIDMM_VAL_TRIGGER_DELAY_CLASS_EXT_BASE     (-100.0L)
#define IVIDMM_VAL_TRIGGER_DELAY_SPECIFIC_EXT_BASE  (-1000.0L)

    /*- Defined values for attribute IVIDMM_ATTR_TRIGGER_SOURCE -*/
#define IVIDMM_VAL_IMMEDIATE                        (1L)
#define IVIDMM_VAL_EXTERNAL                         (2L)
#define IVIDMM_VAL_SOFTWARE_TRIG                    (3L)
#define IVIDMM_VAL_TTL0                             (111L)
#define IVIDMM_VAL_TTL1                             (112L)
#define IVIDMM_VAL_TTL2                             (113L)
#define IVIDMM_VAL_TTL3                             (114L)
#define IVIDMM_VAL_TTL4                             (115L)
#define IVIDMM_VAL_TTL5                             (116L)
#define IVIDMM_VAL_TTL6                             (117L)
#define IVIDMM_VAL_TTL7                             (118L)
#define IVIDMM_VAL_ECL0                             (119L)
#define IVIDMM_VAL_ECL1                             (120L)
#define IVIDMM_VAL_PXI_STAR                         (131L)
#define IVIDMM_VAL_RTSI_0                           (140L)
#define IVIDMM_VAL_RTSI_1                           (141L)
#define IVIDMM_VAL_RTSI_2                           (142L)
#define IVIDMM_VAL_RTSI_3                           (143L)
#define IVIDMM_VAL_RTSI_4                           (144L)
#define IVIDMM_VAL_RTSI_5                           (145L)
#define IVIDMM_VAL_RTSI_6                           (146L)

#define IVIDMM_VAL_TRIGGER_SOURCE_CLASS_EXT_BASE    (500L)
#define IVIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE (1000L)

    /*- Defined values for attribute IVIDMM_ATTR_TEMP_TRANSDUCER_TYPE -*/
#define IVIDMM_VAL_THERMOCOUPLE                     (1L)
#define IVIDMM_VAL_THERMISTOR                       (2L)
#define IVIDMM_VAL_2_WIRE_RTD                       (3L)
#define IVIDMM_VAL_4_WIRE_RTD                       (4L)

#define IVIDMM_VAL_TRANSDUCER_CLASS_EXT_BASE        (100L)
#define IVIDMM_VAL_TRANSDUCER_SPECIFIC_EXT_BASE     (1000L)

    /*- Defined values for attribute IVIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE -*/
#define IVIDMM_VAL_TEMP_REF_JUNC_INTERNAL           (1L)
#define IVIDMM_VAL_TEMP_REF_JUNC_FIXED              (2L)
#define IVIDMM_VAL_TEMP_REF_JUNC_CLASS_EXT_BASE     (100L)
#define IVIDMM_VAL_TEMP_REF_JUNC_SPECIFIC_EXT_BASE  (1000L)
    
    /*- Defined values for attribute IVIDMM_ATTR_TEMP_TC_TYPE -*/
#define IVIDMM_VAL_TEMP_TC_B                        (1L)
#define IVIDMM_VAL_TEMP_TC_C                        (2L)
#define IVIDMM_VAL_TEMP_TC_D                        (3L)
#define IVIDMM_VAL_TEMP_TC_E                        (4L)
#define IVIDMM_VAL_TEMP_TC_G                        (5L)
#define IVIDMM_VAL_TEMP_TC_J                        (6L)
#define IVIDMM_VAL_TEMP_TC_K                        (7L)
#define IVIDMM_VAL_TEMP_TC_N                        (8L)
#define IVIDMM_VAL_TEMP_TC_R                        (9L)
#define IVIDMM_VAL_TEMP_TC_S                        (10L)
#define IVIDMM_VAL_TEMP_TC_T                        (11L)
#define IVIDMM_VAL_TEMP_TC_U                        (12L)
#define IVIDMM_VAL_TEMP_TC_V                        (13L)
#define IVIDMM_VAL_TEMP_TC_TYPE_CLASS_EXT_BASE      (100L)
#define IVIDMM_VAL_TEMP_TC_TYPE_SPECIFIC_EXT_BASE   (1000L)
    
    /*- Defined values for attribute IVIDMM_ATTR_MEAS_COMPLETE_DEST -*/
#define IVIDMM_VAL_NONE                         (-1L)
/* #define IVIDMM_VAL_EXTERNAL                  DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL0                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL1                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL2                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL3                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL4                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL5                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL6                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL7                      DEFINED ABOVE */
/* #define IVIDMM_VAL_ECL0                      DEFINED ABOVE */
/* #define IVIDMM_VAL_ECL1                      DEFINED ABOVE */
/* #define IVIDMM_VAL_PXI_STAR                  DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_0                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_1                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_2                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_3                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_4                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_5                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_6                    DEFINED ABOVE */

    /* Defined values for attribute IVIDMM_ATTR_SAMPLE_TRIGGER -*/
/* #define IVIDMM_VAL_IMMEDIATE                 DEFINED ABOVE */
/* #define IVIDMM_VAL_EXTERNAL                  DEFINED ABOVE */
/* #define IVIDMM_VAL_SOFTWARE_TRIG             DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL0                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL1                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL2                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL3                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL4                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL5                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL6                      DEFINED ABOVE */
/* #define IVIDMM_VAL_TTL7                      DEFINED ABOVE */
/* #define IVIDMM_VAL_ECL0                      DEFINED ABOVE */
/* #define IVIDMM_VAL_ECL1                      DEFINED ABOVE */
/* #define IVIDMM_VAL_PXI_STAR                  DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_0                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_1                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_2                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_3                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_4                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_5                    DEFINED ABOVE */
/* #define IVIDMM_VAL_RTSI_6                    DEFINED ABOVE */
#define IVIDMM_VAL_INTERVAL                     (10L)

    /*- Defined values for attribute IVIDMM_ATTR_TRIGGER_SLOPE -*/
#define IVIDMM_VAL_POSITIVE                         (0L)
#define IVIDMM_VAL_NEGATIVE                         (1L)

#define IVIDMM_VAL_TRIGGER_SLOPE_CLASS_EXT_BASE     (100L)
#define IVIDMM_VAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE  (1000L)

    /*- Defined values for attribute IVIDMM_ATTR_APERTURE_TIME_UNITS -*/
#define IVIDMM_VAL_SECONDS                      (0L)
#define IVIDMM_VAL_POWER_LINE_CYCLES            (1L)

    /*- Defined values for extended attribute IVIDMM_ATTR_AUTO_ZER0 -*/
#define IVIDMM_VAL_AUTO_ZERO_OFF                (0L)
#define IVIDMM_VAL_AUTO_ZERO_ON                 (1L)
#define IVIDMM_VAL_AUTO_ZERO_ONCE               (2L)

#define IVIDMM_VAL_AUTO_ZERO_CLASS_EXT_BASE     (100L)
#define IVIDMM_VAL_AUTO_ZERO_SPECIFIC_EXT_BASE  (1000L)


/****************************************************************************
 *--------- IviDmm Class Instrument Driver Function Declarations -----------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviDmm_init (ViRsrc logicalName, 
                               ViBoolean idQuery, 
                               ViBoolean resetDevice, 
                               ViSession *vi);

ViStatus _VI_FUNC IviDmm_close (ViSession vi);

ViStatus _VI_FUNC IviDmm_reset (ViSession vi);

ViStatus _VI_FUNC IviDmm_self_test (ViSession vi, 
                                    ViInt16 *selfTestResult, 
                                    ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviDmm_error_query (ViSession vi, 
                                      ViInt32 *errorCode, 
                                      ViChar errorMessage[]);

ViStatus _VI_FUNC IviDmm_error_message (ViSession vi, 
                                        ViStatus statusCode, 
                                        ViChar message[]);

ViStatus _VI_FUNC IviDmm_revision_query (ViSession vi, 
                                         ViChar driverRev[], 
                                         ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviDmm_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviDmm_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviDmm_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviDmm_InitWithOptions (ViRsrc logicalName, 
                                          ViBoolean IDQuery,
                                          ViBoolean resetDevice, 
                                          ViConstString optionString, 
                                          ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviDmm_GetAttributeViInt32 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt32 *value);

ViStatus _VI_FUNC IviDmm_SetAttributeViInt32 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt32 value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviDmm_GetAttributeViInt64 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt64 *value);

ViStatus _VI_FUNC IviDmm_SetAttributeViInt64 (ViSession vi, 
                                              ViConstString channelName,
                                              ViAttr attributeId,
                                              ViInt64 value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);
#endif

ViStatus _VI_FUNC IviDmm_GetAttributeViReal64 (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViReal64 *value);

ViStatus _VI_FUNC IviDmm_SetAttributeViReal64 (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViReal64 value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviDmm_GetAttributeViString (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViInt32 bufferSize, 
                                               ViChar value[]);

ViStatus _VI_FUNC IviDmm_SetAttributeViString (ViSession vi, 
                                               ViConstString channelName, 
                                               ViAttr attributeId, 
                                               ViConstString value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value); 

ViStatus _VI_FUNC IviDmm_GetAttributeViBoolean (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViBoolean *value);

ViStatus _VI_FUNC IviDmm_SetAttributeViBoolean (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViBoolean value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviDmm_GetAttributeViSession (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViSession *value);

ViStatus _VI_FUNC IviDmm_SetAttributeViSession (ViSession vi, 
                                                ViConstString channelName, 
                                                ViAttr attributeId, 
                                                ViSession value);

ViStatus _VI_FUNC IviDmm_CheckAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviDmm_LockSession (ViSession vi, 
                                      ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviDmm_UnlockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviDmm_GetError (ViSession vi, 
                                   ViStatus *errorCode, 
                                   ViInt32 bufferSize, 
                                   ViChar description[]);

ViStatus _VI_FUNC IviDmm_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviDmm_GetNextInterchangeWarning (ViSession vi, 
                                                    ViInt32 bufferSize,
                                                    ViChar warning[]);

ViStatus _VI_FUNC IviDmm_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviDmm_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviDmm_GetNextCoercionRecord (ViSession vi,
                                                ViInt32 bufferSize, 
                                                ViChar record[]);

ViStatus _VI_FUNC IviDmm_GetSpecificDriverCHandle (ViSession vi,
                                                   ViSession* specificDriverCHandle);

ViStatus _VI_FUNC IviDmm_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);
    /*- IviDmmBase Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureMeasurement (ViSession vi, 
                                                 ViInt32 function, 
                                                 ViReal64 range, 
                                                 ViReal64 resolution);

ViStatus _VI_FUNC   IviDmm_ConfigureTrigger (ViSession vi, 
                                             ViInt32 triggerSource, 
                                             ViReal64 triggerDelay);

ViStatus _VI_FUNC   IviDmm_Read (ViSession vi, 
                                 ViInt32 maxTime, 
                                 ViReal64 *reading);

ViStatus _VI_FUNC   IviDmm_Fetch (ViSession vi, 
                                  ViInt32 maxTime, 
                                  ViReal64 *reading);

ViStatus _VI_FUNC   IviDmm_Abort (ViSession vi);

ViStatus _VI_FUNC   IviDmm_Initiate (ViSession vi);

ViStatus _VI_FUNC   IviDmm_IsOverRange (ViSession vi, 
                                        ViReal64 measurementValue, 
                                        ViBoolean *isOverRange);

    /*- IviDmmAcMeasurement Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureACBandwidth (ViSession vi, 
                                                 ViReal64 minFreq, 
                                                 ViReal64 maxFreq);
    
    /*- IviDmmFrequencyMeasurement Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureFrequencyVoltageRange (ViSession vi, 
                                                           ViReal64 frequencyVoltageRange);

    /*- IviDmmTemperatureMeasurement Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureTransducerType (ViSession vi, 
                                                    ViInt32 transducerType);

    /*- IviDmmThermocouple Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureFixedRefJunction (ViSession vi, 
                                                      ViReal64 fixedRefJunction);
ViStatus _VI_FUNC   IviDmm_ConfigureThermocouple (ViSession vi, 
                                                  ViInt32 thermocoupleType, 
                                                  ViInt32 refJunctionType);

    /*- IviDmmRTD Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureRTD (ViSession vi, 
                                         ViReal64 alpha, 
                                         ViReal64 resistance);

    /*- IviDmmThermistor Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureThermistor (ViSession vi, 
                                                ViReal64 resistance);

    /*- IviDmmMultiPoint Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureMeasCompleteDest (ViSession vi, 
                                                      ViInt32 measCompleteDest);
ViStatus _VI_FUNC   IviDmm_ConfigureMultiPoint (ViSession vi, 
                                                ViInt32 triggerCount, 
                                                ViInt32 sampleCount, 
                                                ViInt32 sampleTrigger, 
                                                ViReal64 sampleInterval);
ViStatus _VI_FUNC   IviDmm_ReadMultiPoint      (ViSession vi, 
                                                ViInt32 maxTime, 
                                                ViInt32 arraySize, 
                                                ViReal64 readingArray[], 
                                                ViInt32 *actualPts);
ViStatus _VI_FUNC   IviDmm_FetchMultiPoint     (ViSession vi, 
                                                ViInt32 maxTime, 
                                                ViInt32 arraySize, 
                                                ViReal64 readingArray[], 
                                                ViInt32 *actualPts);

    /*- IviDmmTriggerSlope Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureTriggerSlope (ViSession vi, 
                                                  ViInt32 polarity);

    /*- IviDmmSoftwareTrigger Functions -*/
ViStatus _VI_FUNC   IviDmm_SendSoftwareTrigger (ViSession vi);

    /*- IviDmmDeviceInfo Functions -*/
ViStatus _VI_FUNC   IviDmm_GetApertureTimeInfo (ViSession vi, 
                                                ViReal64 *apertureTime, 
                                                ViInt32 *apertureTimeUnits);

    /*- IviDmmAutoRangeValue Functions -*/
ViStatus _VI_FUNC   IviDmm_GetAutoRangeValue (ViSession vi, 
                                              ViReal64 *autoRangeValue);

    /*- IviDmmAutoZero Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigureAutoZeroMode (ViSession vi, 
                                                  ViInt32 autoZeroMode);

    /*- IviDmmPowerLineFrequency Functions -*/
ViStatus _VI_FUNC   IviDmm_ConfigurePowerLineFrequency (ViSession vi, 
                                                        ViReal64 powerLineFreq);
                                                
/****************************************************************************
 *----------------- IviDmm Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVIDMM_WARN_OVER_RANGE              (IVI_CLASS_WARN_BASE  + 1)

#define IVIDMM_ERROR_TRIGGER_NOT_SOFTWARE   (IVI_CROSS_CLASS_ERROR_BASE + 1)
#define IVIDMM_ERROR_MAX_TIME_EXCEEDED      (IVI_CLASS_ERROR_BASE + 3)

#define IVIDMM_WRNMSG_OVER_RANGE            "Over range."

#define IVIDMM_ERRMSG_MAX_TIME_EXCEEDED     "Max Time exceeded before "\
                                            "operation completed."
#define IVIDMM_ERRMSG_TRIGGER_NOT_SOFTWARE  "The trigger source is not set to "\
                                            "software trigger."
#define IVIDMM_ERROR_CODES_AND_MSGS                                         \
        {IVIDMM_WARN_OVER_RANGE,            IVIDMM_WRNMSG_OVER_RANGE},          \
        {IVIDMM_ERROR_MAX_TIME_EXCEEDED,    IVIDMM_ERRMSG_MAX_TIME_EXCEEDED},    \
        {IVIDMM_ERROR_TRIGGER_NOT_SOFTWARE, IVIDMM_ERRMSG_TRIGGER_NOT_SOFTWARE} 
        
/*- IviDmmObsolete.h included for backwards compatibility -*/
#include "IviDmmObsolete.h"

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}                                                    
#endif

#endif /* IVIDMM_HEADER */

