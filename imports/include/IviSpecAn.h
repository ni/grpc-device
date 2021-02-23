/****************************************************************************
 *                         IVISPECAN                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       IviSpecAn.h                                                    
 * Purpose:     IviSpecAn Class declarations for the Base and Extended  
 *              IviSpecAn Capabilities.                                        
 ****************************************************************************/

#ifndef IVISPECAN_HEADER
#define IVISPECAN_HEADER

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

#define IVISPECAN_MAJOR_VERSION              (4L)
#define IVISPECAN_MINOR_VERSION              (0L)

#define IVISPECAN_CLASS_SPEC_MAJOR_VERSION   (2L)
#define IVISPECAN_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVISPECAN_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVISPECAN_DRIVER_DESCRIPTION         "IviSpecAn Class Driver [Compiled for 64-bit.]"
#else
#define IVISPECAN_DRIVER_DESCRIPTION         "IviSpecAn Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/


/****************************************************************************
 *------------------ IviSpecAn Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVISPECAN_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVISPECAN_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVISPECAN_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVISPECAN_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVISPECAN_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVISPECAN_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVISPECAN_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVISPECAN_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

	/* Instrument Capabilities */
#define IVISPECAN_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT                 /* ViInt32,  read-only  */

        /*- Instrument Capabilities -*/
#define IVISPECAN_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVISPECAN_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVISPECAN_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVISPECAN_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVISPECAN_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVISPECAN_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISPECAN_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVISPECAN_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                    /* ViString, read-only */
#define IVISPECAN_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISPECAN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVISPECAN_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVISPECAN_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVISPECAN_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVISPECAN_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only */
  
        /*- Version Information -*/
#define IVISPECAN_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVISPECAN_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVISPECAN_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviSpecAn Fundamental Attributes -*/
#define IVISPECAN_ATTR_AMPLITUDE_UNITS                               (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)    /* ViInt32 */
#define IVISPECAN_ATTR_ATTENUATION                                   (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)    /* ViReal64 */
#define IVISPECAN_ATTR_ATTENUATION_AUTO                              (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)    /* ViBoolean */
#define IVISPECAN_ATTR_DETECTOR_TYPE                                 (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)    /* ViInt32 */
#define IVISPECAN_ATTR_DETECTOR_TYPE_AUTO                            (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)    /* ViBoolean */
#define IVISPECAN_ATTR_FREQUENCY_START                               (IVI_CLASS_PUBLIC_ATTR_BASE + 6L)    /* ViReal64 */
#define IVISPECAN_ATTR_FREQUENCY_STOP                                (IVI_CLASS_PUBLIC_ATTR_BASE + 7L)    /* ViReal64 */
#define IVISPECAN_ATTR_FREQUENCY_OFFSET                              (IVI_CLASS_PUBLIC_ATTR_BASE + 8L)    /* ViReal64 */
#define IVISPECAN_ATTR_INPUT_IMPEDANCE                               (IVI_CLASS_PUBLIC_ATTR_BASE + 9L)    /* ViReal64 */
#define IVISPECAN_ATTR_NUMBER_OF_SWEEPS                              (IVI_CLASS_PUBLIC_ATTR_BASE + 10L)   /* ViInt32 */
#define IVISPECAN_ATTR_REFERENCE_LEVEL                               (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)   /* ViReal64 */
#define IVISPECAN_ATTR_REFERENCE_LEVEL_OFFSET                        (IVI_CLASS_PUBLIC_ATTR_BASE + 12L)   /* ViReal64 */
#define IVISPECAN_ATTR_RESOLUTION_BANDWIDTH                          (IVI_CLASS_PUBLIC_ATTR_BASE + 13L)   /* ViReal64 */
#define IVISPECAN_ATTR_RESOLUTION_BANDWIDTH_AUTO                     (IVI_CLASS_PUBLIC_ATTR_BASE + 14L)   /* ViBoolean */
#define IVISPECAN_ATTR_SWEEP_MODE_CONTINUOUS                         (IVI_CLASS_PUBLIC_ATTR_BASE + 15L)   /* ViBoolean */
#define IVISPECAN_ATTR_SWEEP_TIME                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 16L)   /* ViReal64 */
#define IVISPECAN_ATTR_SWEEP_TIME_AUTO                               (IVI_CLASS_PUBLIC_ATTR_BASE + 17L)   /* ViBoolean */
#define IVISPECAN_ATTR_TRACE_COUNT                                   (IVI_CLASS_PUBLIC_ATTR_BASE + 18L)   /* ViInt32 */
#define IVISPECAN_ATTR_TRACE_SIZE                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 19L)   /* ViInt32 */
#define IVISPECAN_ATTR_TRACE_TYPE                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 20L)   /* ViInt32 */
#define IVISPECAN_ATTR_VERTICAL_SCALE                                (IVI_CLASS_PUBLIC_ATTR_BASE + 21L)   /* ViInt32 */
#define IVISPECAN_ATTR_VIDEO_BANDWIDTH                               (IVI_CLASS_PUBLIC_ATTR_BASE + 22L)   /* ViReal64 */
#define IVISPECAN_ATTR_VIDEO_BANDWIDTH_AUTO                          (IVI_CLASS_PUBLIC_ATTR_BASE + 23L)   /* ViBoolean */

    /*- IviSpecAn Extended Attributes -*/
        /*- IviSpecAnMarker Extension Group -*/
#define IVISPECAN_ATTR_ACTIVE_MARKER                                 (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* ViString */
#define IVISPECAN_ATTR_MARKER_AMPLITUDE                              (IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* ViReal64 */
#define IVISPECAN_ATTR_MARKER_COUNT                                  (IVI_CLASS_PUBLIC_ATTR_BASE + 203L)  /* ViInt32 */
#define IVISPECAN_ATTR_MARKER_ENABLED                                (IVI_CLASS_PUBLIC_ATTR_BASE + 204L)  /* ViBoolean */
#define IVISPECAN_ATTR_MARKER_FREQUENCY_COUNTER_ENABLED              (IVI_CLASS_PUBLIC_ATTR_BASE + 205L)  /* ViBoolean */
#define IVISPECAN_ATTR_MARKER_FREQUENCY_COUNTER_RESOLUTION           (IVI_CLASS_PUBLIC_ATTR_BASE + 206L)  /* ViReal64 */
#define IVISPECAN_ATTR_MARKER_POSITION                               (IVI_CLASS_PUBLIC_ATTR_BASE + 207L)  /* ViReal64 */
#define IVISPECAN_ATTR_MARKER_THRESHOLD                              (IVI_CLASS_PUBLIC_ATTR_BASE + 208L)  /* ViReal64 */
#define IVISPECAN_ATTR_MARKER_TRACE                                  (IVI_CLASS_PUBLIC_ATTR_BASE + 209L)  /* ViString */
#define IVISPECAN_ATTR_PEAK_EXCURSION                                (IVI_CLASS_PUBLIC_ATTR_BASE + 210L)  /* ViReal64 */
#define IVISPECAN_ATTR_SIGNAL_TRACK_ENABLED                          (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* ViBoolean */

        /*- IviSpecAnTrigger Extension Group -*/
#define IVISPECAN_ATTR_TRIGGER_SOURCE                                (IVI_CLASS_PUBLIC_ATTR_BASE + 301L)  /* ViInt32 */

        /*- IviSpecAnExternalTrigger Extension Group -*/
#define IVISPECAN_ATTR_EXTERNAL_TRIGGER_LEVEL                        (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* ViReal64 */
#define IVISPECAN_ATTR_EXTERNAL_TRIGGER_SLOPE                        (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* ViInt32 */

        /*- IviSpecAnVideoTrigger Extension Group -*/
#define IVISPECAN_ATTR_VIDEO_TRIGGER_LEVEL                           (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* ViReal64 */
#define IVISPECAN_ATTR_VIDEO_TRIGGER_SLOPE                           (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* ViInt32 */

        /*- IviSpecAnDisplay Extension Group -*/
#define IVISPECAN_ATTR_NUMBER_OF_DIVISIONS                           (IVI_CLASS_PUBLIC_ATTR_BASE + 602L)  /* ViInt32 */
#define IVISPECAN_ATTR_UNITS_PER_DIVISION                            (IVI_CLASS_PUBLIC_ATTR_BASE + 601L)  /* ViReal64 */

        /*- IviSpecAnMarkerType Extension Group -*/
#define IVISPECAN_ATTR_MARKER_TYPE                                   (IVI_CLASS_PUBLIC_ATTR_BASE + 701L)  /* ViInt32 */

        /*- IviSpecAnDeltaMarker Extension Group -*/
#define IVISPECAN_ATTR_REFERENCE_MARKER_AMPLITUDE                    (IVI_CLASS_PUBLIC_ATTR_BASE + 801L)  /* ViReal64 */
#define IVISPECAN_ATTR_REFERENCE_MARKER_POSITION                     (IVI_CLASS_PUBLIC_ATTR_BASE + 802L)  /* ViReal64 */

        /*- IviSpecAnExternalMixer Extension Group -*/
#define IVISPECAN_ATTR_EXTERNAL_MIXER_AVERAGE_CONVERSION_LOSS        (IVI_CLASS_PUBLIC_ATTR_BASE + 901L)  /* ViReal64 */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_BIAS                           (IVI_CLASS_PUBLIC_ATTR_BASE + 902L)  /* ViReal64 */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_BIAS_ENABLED                   (IVI_CLASS_PUBLIC_ATTR_BASE + 903L)  /* ViBoolean */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_BIAS_LIMIT                     (IVI_CLASS_PUBLIC_ATTR_BASE + 904L)  /* ViReal64 */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_CONVERSION_LOSS_TABLE_ENABLED  (IVI_CLASS_PUBLIC_ATTR_BASE + 905L)  /* ViBoolean */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_ENABLED                        (IVI_CLASS_PUBLIC_ATTR_BASE + 906L)  /* ViBoolean */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_HARMONIC                       (IVI_CLASS_PUBLIC_ATTR_BASE + 907L)  /* ViInt32 */
#define IVISPECAN_ATTR_EXTERNAL_MIXER_NUMBER_OF_PORTS                (IVI_CLASS_PUBLIC_ATTR_BASE + 908L)  /* ViInt32 */

        /*- IviSpecAn Extension Bases -*/
#define IVISPECAN_VENDOR_CLASS_VAL_EXT_BASE                                (500L)
#define IVISPECAN_INSTR_SPECIFIC_VAL_EXT_BASE                              (1000L)
/****************************************************************************
 *----------------- IviSpecAn Class Attribute Value Defines -----------------*
 ****************************************************************************/
/*- Defined values for attribute IVISPECAN_ATTR_AMPLITUDE_UNITS -*/
#define IVISPECAN_VAL_AMPLITUDE_UNITS_DBM                                 (1L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_DBMV                                (2L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_DBUV                                (3L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_VOLT                                (4L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_WATT                                (5L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_CLASS_EXT_BASE                      (500L)
#define IVISPECAN_VAL_AMPLITUDE_UNITS_SPECIFIC_EXT_BASE                   (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_DETECTOR_TYPE -*/
#define IVISPECAN_VAL_DETECTOR_TYPE_AUTO_PEAK                             (1L)
#define IVISPECAN_VAL_DETECTOR_TYPE_AVERAGE                               (2L)
#define IVISPECAN_VAL_DETECTOR_TYPE_MAX_PEAK                              (3L)
#define IVISPECAN_VAL_DETECTOR_TYPE_MIN_PEAK                              (4L)
#define IVISPECAN_VAL_DETECTOR_TYPE_SAMPLE                                (5L)
#define IVISPECAN_VAL_DETECTOR_TYPE_RMS                                   (6L)
#define IVISPECAN_VAL_DETECTOR_TYPE_CLASS_EXT_BASE                        (500L)
#define IVISPECAN_VAL_DETECTOR_TYPE_SPECIFIC_EXT_BASE                     (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_TRACE_TYPE -*/
#define IVISPECAN_VAL_TRACE_TYPE_CLEAR_WRITE                              (1L)
#define IVISPECAN_VAL_TRACE_TYPE_MAX_HOLD                                 (2L)
#define IVISPECAN_VAL_TRACE_TYPE_MIN_HOLD                                 (3L)
#define IVISPECAN_VAL_TRACE_TYPE_VIDEO_AVERAGE                            (4L)
#define IVISPECAN_VAL_TRACE_TYPE_VIEW                                     (5L)
#define IVISPECAN_VAL_TRACE_TYPE_STORE                                    (6L)
#define IVISPECAN_VAL_TRACE_TYPE_CLASS_EXT_BASE                           (500L)
#define IVISPECAN_VAL_TRACE_TYPE_SPECIFIC_EXT_BASE                        (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_VERTICAL_SCALE -*/
#define IVISPECAN_VAL_VERTICAL_SCALE_LINEAR                               (1L)
#define IVISPECAN_VAL_VERTICAL_SCALE_LOGARITHMIC                          (2L)
#define IVISPECAN_VAL_VERTICAL_SCALE_CLASS_EXT_BASE                       (500L)
#define IVISPECAN_VAL_VERTICAL_SCALE_SPECIFIC_EXT_BASE                    (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_TRIGGER_SOURCE -*/
#define IVISPECAN_VAL_TRIGGER_SOURCE_EXTERNAL                             (1L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_IMMEDIATE                            (2L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_SOFTWARE                             (3L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_AC_LINE                              (4L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_VIDEO                                (5L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_CLASS_EXT_BASE                       (500L)
#define IVISPECAN_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE                    (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_EXTERNAL_TRIGGER_SLOPE -*/
#define IVISPECAN_VAL_EXTERNAL_TRIGGER_SLOPE_POSITIVE                     (1L)
#define IVISPECAN_VAL_EXTERNAL_TRIGGER_SLOPE_NEGATIVE                     (2L)
#define IVISPECAN_VAL_EXTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE               (500L)
#define IVISPECAN_VAL_EXTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE            (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_VIDEO_TRIGGER_SLOPE -*/
#define IVISPECAN_VAL_VIDEO_TRIGGER_SLOPE_POSITIVE                        (1L)
#define IVISPECAN_VAL_VIDEO_TRIGGER_SLOPE_NEGATIVE                        (2L)
#define IVISPECAN_VAL_VIDEO_TRIGGER_SLOPE_CLASS_EXT_BASE                  (500L)
#define IVISPECAN_VAL_VIDEO_TRIGGER_SLOPE_SPECIFIC_EXT_BASE               (1000L)

/*- Defined values for attribute IVISPECAN_ATTR_MARKER_TYPE -*/
#define IVISPECAN_VAL_MARKER_TYPE_NORMAL                                  (1L)
#define IVISPECAN_VAL_MARKER_TYPE_DELTA                                   (2L)
#define IVISPECAN_VAL_MARKER_TYPE_CLASS_EXT_BASE                          (500L)
#define IVISPECAN_VAL_MARKER_TYPE_SPECIFIC_EXT_BASE                       (1000L)



/****************************************************************************
 *------------- IviSpecAn Function Parameter Value Definitions -------------*
 ****************************************************************************/
/*- Defined values for status parameter of function -*/
/*- IviSpecAn_AcquisitionStatus -*/
#define IVISPECAN_VAL_ACQUISITION_STATUS_COMPLETE                         (1L)
#define IVISPECAN_VAL_ACQUISITION_STATUS_IN_PROGRESS                      (0L)
#define IVISPECAN_VAL_ACQUISITION_STATUS_UNKNOWN                          (-1L)

/*- Defined values for MaxTime parameter of function -*/
/*- IviSpecAn_ReadYTrace -*/
#define IVISPECAN_VAL_MAX_TIME_IMMEDIATE                                  (0x0L)
#define IVISPECAN_VAL_MAX_TIME_INFINITE                                   (0xFFFFFFFFUL)

/*- Defined values for SearchType parameter of function -*/
/*- IviSpecAn_MarkerSearch -*/
#define IVISPECAN_VAL_MARKER_SEARCH_HIGHEST                               (1L)
#define IVISPECAN_VAL_MARKER_SEARCH_MINIMUM                               (2L)
#define IVISPECAN_VAL_MARKER_SEARCH_NEXT_PEAK                             (3L)
#define IVISPECAN_VAL_MARKER_SEARCH_NEXT_PEAK_LEFT                        (4L)
#define IVISPECAN_VAL_MARKER_SEARCH_NEXT_PEAK_RIGHT                       (5L)
#define IVISPECAN_VAL_MARKER_SEARCH_CLASS_EXT_BASE                        (500L)
#define IVISPECAN_VAL_MARKER_SEARCH_SPECIFIC_EXT_BASE                     (1000L)

/*- Defined values for InstrumentSetting parameter of function -*/
/*- IviSpecAn_SetInstrumentFromMarker -*/
#define IVISPECAN_VAL_INSTRUMENT_SETTING_FREQUENCY_CENTER                 (1L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_FREQUENCY_SPAN                   (2L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_FREQUENCY_START                  (3L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_FREQUENCY_STOP                   (4L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_REFERENCE_LEVEL                  (5L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_CLASS_EXT_BASE                   (500L)
#define IVISPECAN_VAL_INSTRUMENT_SETTING_SPECIFIC_EXT_BASE                (1000L)


/****************************************************************************
 *--------- IviSpecAn Class Instrument Driver Function Declarations ---------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviSpecAn_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviSpecAn_close (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_reset (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviSpecAn_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviSpecAn_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviSpecAn_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);
    /*- Utility Functions -*/
ViStatus _VI_FUNC IviSpecAn_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviSpecAn_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviSpecAn_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString repeatedCapName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviSpecAn_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString repeatedCapName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviSpecAn_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString repeatedCapName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviSpecAn_GetAttributeViString (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViString (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViString (ViSession vi, 
                                                   ViConstString repeatedCapName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviSpecAn_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString repeatedCapName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviSpecAn_GetAttributeViSession (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviSpecAn_SetAttributeViSession (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviSpecAn_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString repeatedCapName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviSpecAn_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviSpecAn_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviSpecAn_GetError (ViSession vi, 
                                   ViStatus *errorCode, 
                                   ViInt32 bufferSize, 
                                   ViChar description[]);

ViStatus _VI_FUNC IviSpecAn_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviSpecAn_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviSpecAn_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviSpecAn_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviSpecAn_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);

    /*- IviSpecAn Fundamental Capabilities -*/
ViStatus _VI_FUNC IviSpecAn_Abort (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_AcquisitionStatus (ViSession vi,
                                               ViInt32* status);

ViStatus _VI_FUNC IviSpecAn_ConfigureAcquisition (ViSession vi,
                                                  ViBoolean sweepModeContinuous,
                                                  ViInt32 numberOfSweeps,
                                                  ViBoolean detectorTypeAuto,
                                                  ViInt32 detectorType,
                                                  ViInt32 verticalScale);

ViStatus _VI_FUNC IviSpecAn_ConfigureFrequencyCenterSpan (ViSession vi,
                                                          ViReal64 CenterFrequency,
                                                          ViReal64 Span);

ViStatus _VI_FUNC IviSpecAn_ConfigureFrequencyOffset (ViSession vi,
                                                      ViReal64 FrequencyOffset);

ViStatus _VI_FUNC IviSpecAn_ConfigureFrequencyStartStop (ViSession vi,
                                                         ViReal64 StartFrequency,
                                                         ViReal64 StopFrequency);

ViStatus _VI_FUNC IviSpecAn_ConfigureLevel (ViSession vi,
                                            ViInt32 AmplitudeUnits,
                                            ViReal64 InputImpedance,
                                            ViReal64 ReferenceLevel,
                                            ViReal64 ReferenceLevelOffset,
                                            ViBoolean AttenuationAuto,
                                            ViReal64 Attenuation);

ViStatus _VI_FUNC IviSpecAn_ConfigureSweepCoupling (ViSession vi,
                                                    ViBoolean ResolutionBandwidtAuto,
                                                    ViReal64 ResolutionBandwidth,
                                                    ViBoolean VideoBandwidthAuto,
                                                    ViReal64 VideoBandwidth,
                                                    ViBoolean SweepTimeAuto,
                                                    ViReal64 SweepTime);

ViStatus _VI_FUNC IviSpecAn_ConfigureTraceType (ViSession vi,
                                                ViConstString TraceName,
                                                ViInt32 TraceType);

ViStatus _VI_FUNC IviSpecAn_FetchYTrace (ViSession vi,
                                         ViConstString TraceName,
                                         ViInt32 ArrayLength,
                                         ViInt32* ActualPoints,
                                         ViReal64 Amplitude[]);

ViStatus _VI_FUNC IviSpecAn_GetTraceName (ViSession vi,
                                          ViInt32 Index,
                                          ViInt32 NameBufferSize,
                                          ViChar Name[]);

ViStatus _VI_FUNC IviSpecAn_Initiate (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_QueryTraceSize (ViSession vi,
                                            ViConstString TraceName,
                                            ViInt32* TraceSize);

ViStatus _VI_FUNC IviSpecAn_ReadYTrace (ViSession vi,
                                        ViConstString TraceName,
                                        ViInt32 MaxTime,
                                        ViInt32 ArrayLength,
                                        ViInt32* ActualPoints,
                                        ViReal64 Amplitude[]);


    /*- IviSpecAnMultitrace Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_AddTraces (ViSession vi,
                                       ViConstString DestinationTrace,
                                       ViConstString Trace1,
                                       ViConstString Trace2);

ViStatus _VI_FUNC IviSpecAn_CopyTrace (ViSession vi,
                                       ViConstString DestinationTrace,
                                       ViConstString SourceTrace);

ViStatus _VI_FUNC IviSpecAn_ExchangeTraces (ViSession vi,
                                            ViConstString Trace1,
                                            ViConstString Trace2);

ViStatus _VI_FUNC IviSpecAn_SubtractTraces (ViSession vi,
                                            ViConstString DestinationTrace,
                                            ViConstString Trace1,
                                            ViConstString Trace2);


    /*- IviSpecAnMarker Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_ConfigureMarkerEnabled (ViSession vi,
                                                    ViBoolean MarkerEnabled,
                                                    ViConstString MarkerTraceName);

ViStatus _VI_FUNC IviSpecAn_ConfigureMarkerFrequencyCounter (ViSession vi,
                                                             ViBoolean Enabled,
                                                             ViReal64 Resolution);

ViStatus _VI_FUNC IviSpecAn_ConfigureMarkerSearch (ViSession vi,
                                                   ViReal64 PeakExcursion,
                                                   ViReal64 MarkerThreshold);

ViStatus _VI_FUNC IviSpecAn_ConfigureSignalTrackEnabled (ViSession vi,
                                                         ViBoolean SignalTrackEnabled);

ViStatus _VI_FUNC IviSpecAn_DisableAllMarkers (ViSession vi);

ViStatus _VI_FUNC IviSpecAn_GetMarkerName (ViSession vi,
                                           ViInt32 Index,
                                           ViInt32 NameBufferSize,
                                           ViChar Name[]);

ViStatus _VI_FUNC IviSpecAn_MarkerSearch (ViSession vi,
                                          ViInt32 SearchType);

ViStatus _VI_FUNC IviSpecAn_MoveMarker (ViSession vi,
                                        ViReal64 MarkerPosition);

ViStatus _VI_FUNC IviSpecAn_QueryMarker (ViSession vi,
                                         ViReal64* MarkerPosition,
                                         ViReal64* MarkerAmplitude);

ViStatus _VI_FUNC IviSpecAn_SetActiveMarker (ViSession vi,
                                             ViConstString ActiveMarker);

ViStatus _VI_FUNC IviSpecAn_SetInstrumentFromMarker (ViSession vi,
                                                     ViInt32 InstrumentSetting);


    /*- IviSpecAnTrigger Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_ConfigureTriggerSource (ViSession vi,
                                                    ViInt32 TriggerSource);


    /*- IviSpecAnExternalTrigger Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_ConfigureExternalTrigger (ViSession vi,
                                                      ViReal64 ExternalTriggerLevel,
                                                      ViInt32 ExternalTriggerSlope);


    /*- IviSpecAnSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_SendSoftwareTrigger (ViSession vi);


    /*- IviSpecAnVideoTrigger Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_ConfigureVideoTrigger (ViSession vi,
                                                   ViReal64 VideoTriggerLevel,
                                                   ViInt32 VideoTriggerSlope);


    /*- IviSpecAnMarkerType Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_QueryMarkerType (ViSession vi,
                                             ViInt32* MarkerType);


    /*- IviSpecAnDeltaMarker Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_MakeMarkerDelta (ViSession vi,
                                             ViBoolean DeltaMarker);

ViStatus _VI_FUNC IviSpecAn_QueryReferenceMarker (ViSession vi,
                                                  ViReal64* ReferenceMarkerAmplitude,
                                                  ViReal64* ReferenceMarkerPosition);


    /*- IviSpecAnExternalMixer Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_ConfigureConversionLossTable (ViSession vi,
                                                          ViInt32 Count,
                                                          ViReal64 Frequency[],
                                                          ViReal64 ConversionLoss[]);

ViStatus _VI_FUNC IviSpecAn_ConfigureConversionLossTableEnabled (ViSession vi,
                                                                 ViBoolean ConversionLossTableEnabled);

ViStatus _VI_FUNC IviSpecAn_ConfigureExternalMixer (ViSession vi,
                                                    ViInt32 Harmonic,
                                                    ViReal64 AverageConversionLoss);

ViStatus _VI_FUNC IviSpecAn_ConfigureExternalMixerBias (ViSession vi,
                                                        ViReal64 Bias,
                                                        ViReal64 BiasLimit);

ViStatus _VI_FUNC IviSpecAn_ConfigureExternalMixerBiasEnabled (ViSession vi,
                                                               ViBoolean BiasEnabled);

ViStatus _VI_FUNC IviSpecAn_ConfigureExternalMixerEnabled (ViSession vi,
                                                           ViBoolean ExternalMixerEnabled);

ViStatus _VI_FUNC IviSpecAn_ConfigureExternalMixerNumberOfPorts (ViSession vi,
                                                                 ViInt32 NumberOfPorts);


    /*- IviSpecAnPreselector Extension Group -*/
ViStatus _VI_FUNC IviSpecAn_PeakPreselector (ViSession vi);



/****************************************************************************
 *--------------- IviSpecAn Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVISPECAN_WARN_MEASURE_UNCALIBRATED    (IVI_CLASS_WARN_BASE + 0x0001L)
#define IVISPECAN_WARN_OVER_RANGE              (IVI_CLASS_WARN_BASE + 0x0002L)

#define IVISPECAN_ERROR_MARKER_NOT_ENABLED     (IVI_CLASS_ERROR_BASE + 0x0003L)
#define IVISPECAN_ERROR_NOT_DELTA_MARKER       (IVI_CLASS_ERROR_BASE + 0x0002L)
#define IVISPECAN_ERROR_MAX_TIME_EXCEEDED      (IVI_CLASS_ERROR_BASE + 0x0001L)
#define IVISPECAN_ERROR_TRIGGER_NOT_SOFTWARE   (IVI_CROSS_CLASS_ERROR_BASE + 1L)



#define IVISPECAN_WARNMSG_MEASURE_UNCALIBRATED "The instrument was in an uncalibrated state when the measurement was taken."
#define IVISPECAN_WARNMSG_OVER_RANGE           "The measurement taken was over the instrument’s range."

#define IVISPECAN_ERRMSG_MARKER_NOT_ENABLED    "The Active Marker is not enabled."
#define IVISPECAN_ERRMSG_NOT_DELTA_MARKER      "The Active Marker is not a delta marker."
#define IVISPECAN_ERRMSG_MAX_TIME_EXCEEDED     "The maximum waiting time for this operation was exceeded."
#define IVISPECAN_ERRMSG_TRIGGER_NOT_SOFTWARE  "The trigger source is not set to software trigger."

#define IVISPECAN_ERROR_CODES_AND_MSGS \
    {IVISPECAN_WARN_MEASURE_UNCALIBRATED,  IVISPECAN_WARNMSG_MEASURE_UNCALIBRATED},\
    {IVISPECAN_WARN_OVER_RANGE,            IVISPECAN_WARNMSG_OVER_RANGE},\
    {IVISPECAN_ERROR_MARKER_NOT_ENABLED,   IVISPECAN_ERRMSG_MARKER_NOT_ENABLED},\
    {IVISPECAN_ERROR_NOT_DELTA_MARKER,     IVISPECAN_ERRMSG_NOT_DELTA_MARKER},\
    {IVISPECAN_ERROR_MAX_TIME_EXCEEDED,    IVISPECAN_ERRMSG_MAX_TIME_EXCEEDED},\
    {IVISPECAN_ERROR_TRIGGER_NOT_SOFTWARE, IVISPECAN_ERRMSG_TRIGGER_NOT_SOFTWARE}


/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVISPECAN_HEADER */
