/****************************************************************************
 *                             I V I - S C O P E                             
 *---------------------------------------------------------------------------
 *    Copyright (c) 1998-2020 National Instruments.  All Rights Reserved.         
 *---------------------------------------------------------------------------
 *                                                                           
 * Title:       iviscope.h                                                    
 * Purpose:     IviScope Class declarations for the Base and Extended         
 *              IviScope Capabilities.                                                 
 ****************************************************************************/

#ifndef IVISCOPE_HEADER
#define IVISCOPE_HEADER

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

#define IVISCOPE_MAJOR_VERSION                  (4L)
#define IVISCOPE_MINOR_VERSION                  (0L)

#define IVISCOPE_SPECIFICATION_MAJOR_VERSION    (4L)
#define IVISCOPE_SPECIFICATION_MINOR_VERSION    (1L)

#define IVISCOPE_DRIVER_VENDOR                  "National Instruments"
#ifdef	_IVI_mswin64_
#define IVISCOPE_DRIVER_DESCRIPTION				"IviScope Class Driver [Compiled for 64-bit.]"
#else
#define IVISCOPE_DRIVER_DESCRIPTION				"IviScope Class Driver"
#endif

/****************************************************************************
 *-------------------- IviScope Class Attribute Defines --------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVISCOPE_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVISCOPE_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVISCOPE_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVISCOPE_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVISCOPE_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVISCOPE_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVISCOPE_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVISCOPE_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVISCOPE_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVISCOPE_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVISCOPE_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVISCOPE_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                       /* ViString, read-only */
#define IVISCOPE_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVISCOPE_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVISCOPE_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVISCOPE_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVISCOPE_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

	/*- Version Information -*/
#define IVISCOPE_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVISCOPE_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviScope Fundamental Attributes -*/
        /*- Channel Subsystem -*/
#define IVISCOPE_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT               /* ViInt32,  read-only */
#define IVISCOPE_ATTR_VERTICAL_RANGE            (IVI_CLASS_PUBLIC_ATTR_BASE  + 1L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_VERTICAL_OFFSET           (IVI_CLASS_PUBLIC_ATTR_BASE  + 2L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_VERTICAL_COUPLING         (IVI_CLASS_PUBLIC_ATTR_BASE  + 3L)   /* ViInt32,   Multi-Channel */
#define IVISCOPE_ATTR_PROBE_ATTENUATION         (IVI_CLASS_PUBLIC_ATTR_BASE  + 4L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_CHANNEL_ENABLED           (IVI_CLASS_PUBLIC_ATTR_BASE  + 5L)   /* ViBoolean, Multi-Channel */
#define IVISCOPE_ATTR_MAX_INPUT_FREQUENCY       (IVI_CLASS_PUBLIC_ATTR_BASE  + 6L)   /* ViReal64,  Multi-Channel */
#define IVISCOPE_ATTR_INPUT_IMPEDANCE           (IVI_CLASS_PUBLIC_ATTR_BASE  + 103L) /* ViReal64,  Multi-Channel */
    
        /*- Acquisition Subsystem -*/
#define IVISCOPE_ATTR_ACQUISITION_TYPE          (IVI_CLASS_PUBLIC_ATTR_BASE  + 101L) /* ViInt32    */
#define IVISCOPE_ATTR_ACQUISITION_START_TIME    (IVI_CLASS_PUBLIC_ATTR_BASE  + 109L) /* ViReal64  */
#define IVISCOPE_ATTR_HORZ_TIME_PER_RECORD      (IVI_CLASS_PUBLIC_ATTR_BASE  + 7L)   /* ViReal64  */
#define IVISCOPE_ATTR_HORZ_RECORD_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE  + 8L)   /* ViInt32, Read-only  */
#define IVISCOPE_ATTR_HORZ_MIN_NUM_PTS          (IVI_CLASS_PUBLIC_ATTR_BASE  + 9L)   /* ViInt32   */
#define IVISCOPE_ATTR_HORZ_SAMPLE_RATE          (IVI_CLASS_PUBLIC_ATTR_BASE  + 10L)  /* ViReal64, Read-only */

        /*- Triggering Subsystem -*/
#define IVISCOPE_ATTR_TRIGGER_TYPE              (IVI_CLASS_PUBLIC_ATTR_BASE  + 12L)  /* ViInt32   */
#define IVISCOPE_ATTR_TRIGGER_SOURCE            (IVI_CLASS_PUBLIC_ATTR_BASE  + 13L)  /* ViString  */
#define IVISCOPE_ATTR_TRIGGER_COUPLING          (IVI_CLASS_PUBLIC_ATTR_BASE  + 14L)  /* ViInt32   */
#define IVISCOPE_ATTR_TRIGGER_HOLDOFF           (IVI_CLASS_PUBLIC_ATTR_BASE  + 16L)  /* ViReal64  */

        /*- Edge Triggering Attributes -*/
#define IVISCOPE_ATTR_TRIGGER_LEVEL             (IVI_CLASS_PUBLIC_ATTR_BASE  + 17L)  /* ViReal64  */
#define IVISCOPE_ATTR_TRIGGER_SLOPE             (IVI_CLASS_PUBLIC_ATTR_BASE  + 18L)  /* ViInt32   */
    
    /*- IviScope Extended Attributes -*/
        /*- IviScopeTVTrigger Extension Group -*/
#define IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT  (IVI_CLASS_PUBLIC_ATTR_BASE + 201L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_EVENT          (IVI_CLASS_PUBLIC_ATTR_BASE + 205L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER    (IVI_CLASS_PUBLIC_ATTR_BASE + 206L) /* ViInt32   */
#define IVISCOPE_ATTR_TV_TRIGGER_POLARITY       (IVI_CLASS_PUBLIC_ATTR_BASE + 204L) /* ViInt32   */

        /*- IviScopeRuntTrigger Extension Group -*/
#define IVISCOPE_ATTR_RUNT_HIGH_THRESHOLD       (IVI_CLASS_PUBLIC_ATTR_BASE + 301L) /* ViReal64  */
#define IVISCOPE_ATTR_RUNT_LOW_THRESHOLD        (IVI_CLASS_PUBLIC_ATTR_BASE + 302L) /* ViReal64  */
#define IVISCOPE_ATTR_RUNT_POLARITY             (IVI_CLASS_PUBLIC_ATTR_BASE + 303L) /* ViInt32   */

        /*- IviScopeGlitchTrigger Extension Group -*/
#define IVISCOPE_ATTR_GLITCH_WIDTH              (IVI_CLASS_PUBLIC_ATTR_BASE + 401L) /* ViReal64  */
#define IVISCOPE_ATTR_GLITCH_POLARITY           (IVI_CLASS_PUBLIC_ATTR_BASE + 402L) /* ViInt32   */
#define IVISCOPE_ATTR_GLITCH_CONDITION          (IVI_CLASS_PUBLIC_ATTR_BASE + 403L) /* ViInt32   */

        /*- IviScopeWidthTrigger Extension Group -*/
#define IVISCOPE_ATTR_WIDTH_LOW_THRESHOLD       (IVI_CLASS_PUBLIC_ATTR_BASE + 501L) /* ViReal64  */
#define IVISCOPE_ATTR_WIDTH_HIGH_THRESHOLD      (IVI_CLASS_PUBLIC_ATTR_BASE + 502L) /* ViReal64  */
#define IVISCOPE_ATTR_WIDTH_POLARITY            (IVI_CLASS_PUBLIC_ATTR_BASE + 503L) /* ViInt32   */
#define IVISCOPE_ATTR_WIDTH_CONDITION           (IVI_CLASS_PUBLIC_ATTR_BASE + 504L) /* ViInt32   */

        /*- IviScopeAcLineTrigger Extension Group -*/
#define IVISCOPE_ATTR_AC_LINE_TRIGGER_SLOPE     (IVI_CLASS_PUBLIC_ATTR_BASE + 701L) /* ViInt32   */

        /*- IviScopeMinMaxWaveform Extension Group -*/
#define IVISCOPE_ATTR_NUM_ENVELOPES             (IVI_CLASS_PUBLIC_ATTR_BASE + 105L) /* ViInt32   */
    
        /*- IviScopeWaveformMeas Extension Group -*/
#define IVISCOPE_ATTR_MEAS_HIGH_REF             (IVI_CLASS_PUBLIC_ATTR_BASE + 607L) /* ViReal64, Percentage */
#define IVISCOPE_ATTR_MEAS_LOW_REF              (IVI_CLASS_PUBLIC_ATTR_BASE + 608L) /* ViReal64, Percentage */
#define IVISCOPE_ATTR_MEAS_MID_REF              (IVI_CLASS_PUBLIC_ATTR_BASE + 609L) /* ViReal64, Percentage */

        /*- IviScope Trigger Modifier Extension Group -*/
#define IVISCOPE_ATTR_TRIGGER_MODIFIER          (IVI_CLASS_PUBLIC_ATTR_BASE + 102L) /* ViInt32   */

        /*- IviScope Average Acquisition Extension Group -*/
#define IVISCOPE_ATTR_NUM_AVERAGES              (IVI_CLASS_PUBLIC_ATTR_BASE + 104L) /* ViInt32   */

        /*- IviScope Sample Mode Extension Group -*/
#define IVISCOPE_ATTR_SAMPLE_MODE               (IVI_CLASS_PUBLIC_ATTR_BASE + 106L) /* ViInt32, R/O  */

        /*- IviScope Continuous Acquisition Extension Group -*/
#define IVISCOPE_ATTR_INITIATE_CONTINUOUS       (IVI_CLASS_PUBLIC_ATTR_BASE + 107L) /* ViBoolean */

        /*- IviScope Probe Auto Sense Extension Group -*/
#define IVISCOPE_ATTR_PROBE_SENSE_VALUE         (IVI_CLASS_PUBLIC_ATTR_BASE + 108L) /* ViReal64, R/O */

        /*- IviScope Interpolation Extension Group -*/
#define IVISCOPE_ATTR_INTERPOLATION             (IVI_CLASS_PUBLIC_ATTR_BASE  + 19L) /* ViInt32   */

/*****************************************************************************
 *------ IviScope Class Function Parameter and Attribute Value Defines ------*
 *****************************************************************************/

    /*- Defined values for maxTime parameter to the waveform acquisition and measurement functions -*/
#define IVISCOPE_VAL_MAX_TIME_INFINITE          IVI_VAL_MAX_TIME_INFINITE
#define IVISCOPE_VAL_MAX_TIME_IMMEDIATE         IVI_VAL_MAX_TIME_IMMEDIATE

    /*- Defined values for the status parameter of the IviScope_AcquisitionStatus function -*/
#define IVISCOPE_VAL_ACQ_COMPLETE                               (1L)
#define IVISCOPE_VAL_ACQ_IN_PROGRESS                            (0L)
#define IVISCOPE_VAL_ACQ_STATUS_UNKNOWN                         (-1L)

    /*- Defined values for the measurementFunction parameter of the IviScope_ReadWaveformMeasurment function -*/
#define IVISCOPE_VAL_RISE_TIME                                  (0L)
#define IVISCOPE_VAL_FALL_TIME                                  (1L)
#define IVISCOPE_VAL_FREQUENCY                                  (2L)
#define IVISCOPE_VAL_PERIOD                                     (3L)
#define IVISCOPE_VAL_VOLTAGE_RMS                                (4L)
#define IVISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK                       (5L)
#define IVISCOPE_VAL_VOLTAGE_MAX                                (6L)
#define IVISCOPE_VAL_VOLTAGE_MIN                                (7L)
#define IVISCOPE_VAL_VOLTAGE_HIGH                               (8L)
#define IVISCOPE_VAL_VOLTAGE_LOW                                (9L)
#define IVISCOPE_VAL_VOLTAGE_AVERAGE                            (10L)
#define IVISCOPE_VAL_WIDTH_NEG                                  (11L)
#define IVISCOPE_VAL_WIDTH_POS                                  (12L)
#define IVISCOPE_VAL_DUTY_CYCLE_NEG                             (13L)
#define IVISCOPE_VAL_DUTY_CYCLE_POS                             (14L)
#define IVISCOPE_VAL_AMPLITUDE                                  (15L)
#define IVISCOPE_VAL_VOLTAGE_CYCLE_RMS                          (16L)
#define IVISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE                      (17L)
#define IVISCOPE_VAL_OVERSHOOT                                  (18L)
#define IVISCOPE_VAL_PRESHOOT                                   (19L)

#define IVISCOPE_VAL_MEASUREMENT_FUNCTION_CLASS_EXT_BASE        (100L)
#define IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE     (1000L)

    /*- Defined values for IVISCOPE_ATTR_VERTICAL_COUPLING -*/
#define IVISCOPE_VAL_AC                                         (0L)
#define IVISCOPE_VAL_DC                                         (1L)
#define IVISCOPE_VAL_GND                                        (2L)
#define IVISCOPE_VAL_VERTICAL_COUPLING_CLASS_EXT_BASE           (100L)
#define IVISCOPE_VAL_VERTICAL_COUPLING_SPECIFIC_EXT_BASE        (1000L)

    /*- Defined values for IVISCOPE_ATTR_TRIGGER_TYPE -*/
#define IVISCOPE_VAL_EDGE_TRIGGER                               (1L)
#define IVISCOPE_VAL_WIDTH_TRIGGER                              (2L)
#define IVISCOPE_VAL_RUNT_TRIGGER                               (3L)
#define IVISCOPE_VAL_GLITCH_TRIGGER                             (4L)
#define IVISCOPE_VAL_TV_TRIGGER                                 (5L)
#define IVISCOPE_VAL_IMMEDIATE_TRIGGER                          (6L)
#define IVISCOPE_VAL_AC_LINE_TRIGGER                            (7L)
#define IVISCOPE_VAL_TRIGGER_TYPE_CLASS_EXT_BASE                (200L)
#define IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE             (1000L)


    /*- Defined values for IVISCOPE_ATTR_TRIGGER_SLOPE -*/
#define IVISCOPE_VAL_POSITIVE                                   (1L)
#define IVISCOPE_VAL_NEGATIVE                                   (0L)

    /*- Defined values for IVISCOPE_ATTR_TRIGGER_SOURCE -*/
#define IVISCOPE_VAL_EXTERNAL                      "VAL_EXTERNAL"
#define IVISCOPE_VAL_TTL0                          "VAL_TTL0"
#define IVISCOPE_VAL_TTL1                          "VAL_TTL1"
#define IVISCOPE_VAL_TTL2                          "VAL_TTL2"
#define IVISCOPE_VAL_TTL3                          "VAL_TTL3"
#define IVISCOPE_VAL_TTL4                          "VAL_TTL4"
#define IVISCOPE_VAL_TTL5                          "VAL_TTL5"
#define IVISCOPE_VAL_TTL6                          "VAL_TTL6"
#define IVISCOPE_VAL_TTL7                          "VAL_TTL7"
#define IVISCOPE_VAL_ECL0                          "VAL_ECL0"
#define IVISCOPE_VAL_ECL1                          "VAL_ECL1"
#define IVISCOPE_VAL_PXI_STAR                      "VAL_PXI_STAR"
#define IVISCOPE_VAL_RTSI_0                        "VAL_RTSI_0"
#define IVISCOPE_VAL_RTSI_1                        "VAL_RTSI_1"
#define IVISCOPE_VAL_RTSI_2                        "VAL_RTSI_2"
#define IVISCOPE_VAL_RTSI_3                        "VAL_RTSI_3"
#define IVISCOPE_VAL_RTSI_4                        "VAL_RTSI_4"
#define IVISCOPE_VAL_RTSI_5                        "VAL_RTSI_5"
#define IVISCOPE_VAL_RTSI_6                        "VAL_RTSI_6"
    /*  
        In addition to the above defines, 
        IVISCOPE_ATTR_TRIGGER_SOURCE accpets any defined 
        channel name or string representation of a channel number
    */

    /*- Defined extended values for IVISCOPE_ATTR_PROBE_ATTENUATION -*/
#define IVISCOPE_VAL_PROBE_SENSE_ON                            (-1L)

#define IVISCOPE_VAL_PROBE_ATTENUATION_CLASS_EXT_BASE          (-100L)
#define IVISCOPE_VAL_PROBE_ATTENUATION_SPECIFIC_EXT_BASE       (-1000L)

    /*- Defined values for IVISCOPE_ATTR_TRIGGER_COUPLING -*/
/* #define IVISCOPE_VAL_AC                      DEFINED ABOVE */
/* #define IVISCOPE_VAL_DC                      DEFINED ABOVE */
#define IVISCOPE_VAL_HF_REJECT                                 (3L)
#define IVISCOPE_VAL_LF_REJECT                                 (4L)
#define IVISCOPE_VAL_NOISE_REJECT                              (5L)

#define IVISCOPE_VAL_TRIGGER_COUPLING_CLASS_EXT_BASE           (100L)
#define IVISCOPE_VAL_TRIGGER_COUPLING_SPECIFIC_EXT_BASE        (1000L)

    /*- Defined values for IVISCOPE_ATTR_INTERPOLATION -*/
#define IVISCOPE_VAL_NO_INTERPOLATION                          (1L)
#define IVISCOPE_VAL_SINE_X                                    (2L)
#define IVISCOPE_VAL_LINEAR                                    (3L)
#define IVISCOPE_VAL_INTERPOLATION_CLASS_EXT_BASE              (100L)
#define IVISCOPE_VAL_INTERPOLATION_SPECIFIC_EXT_BASE           (1000L)
    
    /*- Defined values for IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT -*/
#define IVISCOPE_VAL_NTSC                                      (1L)
#define IVISCOPE_VAL_PAL                                       (2L)
#define IVISCOPE_VAL_SECAM                                     (3L)
#define IVISCOPE_VAL_TV_SIGNAL_FORMAT_CLASS_EXT_BASE           (100L)
#define IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE        (1000L)

    /*- Defined values for IVISCOPE_ATTR_TV_TRIGGER_EVENT -*/
#define IVISCOPE_VAL_TV_EVENT_FIELD1                           (1L)
#define IVISCOPE_VAL_TV_EVENT_FIELD2                           (2L)
#define IVISCOPE_VAL_TV_EVENT_ANY_FIELD                        (3L)
#define IVISCOPE_VAL_TV_EVENT_ANY_LINE                         (4L)
#define IVISCOPE_VAL_TV_EVENT_LINE_NUMBER                      (5L)
#define IVISCOPE_VAL_TV_TRIGGER_EVENT_CLASS_EXT_BASE           (100L)
#define IVISCOPE_VAL_TV_TRIGGER_EVENT_SPECIFIC_EXT_BASE        (1000L)

    /*- Defined values for IVISCOPE_ATTR_TV_TRIGGER_POLARITY -*/
#define IVISCOPE_VAL_TV_POSITIVE                               (1L)
#define IVISCOPE_VAL_TV_NEGATIVE                               (2L)
#define IVISCOPE_VAL_TV_TRIGGER_POLARITY_CLASS_EXT_BASE        (100L)
#define IVISCOPE_VAL_TV_TRIGGER_POLARITY_SPECIFIC_EXT_BASE     (1000L)

    /*- Defined values for IVISCOPE_ATTR_RUNT_POLARITY -*/
#define IVISCOPE_VAL_RUNT_POSITIVE                             (1L)
#define IVISCOPE_VAL_RUNT_NEGATIVE                             (2L)
#define IVISCOPE_VAL_RUNT_EITHER                               (3L)

    /*- Defined values for IVISCOPE_ATTR_GLITCH_POLARITY -*/
#define IVISCOPE_VAL_GLITCH_POSITIVE                            (1L)
#define IVISCOPE_VAL_GLITCH_NEGATIVE                            (2L)
#define IVISCOPE_VAL_GLITCH_EITHER                              (3L)

    /*- Defined values for IVISCOPE_ATTR_GLITCH_CONDITION -*/
#define IVISCOPE_VAL_GLITCH_LESS_THAN                           (1L)
#define IVISCOPE_VAL_GLITCH_GREATER_THAN                        (2L)

    /*- Defined values for IVISCOPE_ATTR_WIDTH_POLARITY -*/
#define IVISCOPE_VAL_WIDTH_POSITIVE                             (1L)
#define IVISCOPE_VAL_WIDTH_NEGATIVE                             (2L)
#define IVISCOPE_VAL_WIDTH_EITHER                               (3L)
    
    /*- Defined values for IVISCOPE_ATTR_WIDTH_CONDITION -*/
#define IVISCOPE_VAL_WIDTH_WITHIN                               (1L)
#define IVISCOPE_VAL_WIDTH_OUTSIDE                              (2L)

    /*- Defined values for IVISCOPE_ATTR_AC_LINE_TRIGGER_SLOPE -*/
#define IVISCOPE_VAL_AC_LINE_POSITIVE                           (1L)
#define IVISCOPE_VAL_AC_LINE_NEGATIVE                           (2L)
#define IVISCOPE_VAL_AC_LINE_EITHER                             (3L)

    /*- Defined values for IVISCOPE_ATTR_ACQUISITION_TYPE -*/
#define IVISCOPE_VAL_NORMAL                                     (0L)
#define IVISCOPE_VAL_PEAK_DETECT                                (1L)
#define IVISCOPE_VAL_HI_RES                                     (2L)
#define IVISCOPE_VAL_ENVELOPE                                   (3L)
#define IVISCOPE_VAL_AVERAGE                                    (4L)

#define IVISCOPE_VAL_ACQUISITION_TYPE_CLASS_EXT_BASE            (100L)
#define IVISCOPE_VAL_ACQUISITION_TYPE_SPECIFIC_EXT_BASE         (1000L)

    /*- Defined values for IVISCOPE_ATTR_TRIGGER_MODIFIER -*/
#define IVISCOPE_VAL_NO_TRIGGER_MOD                             (1L)
#define IVISCOPE_VAL_AUTO                                       (2L)
#define IVISCOPE_VAL_AUTO_LEVEL                                 (3L)

#define IVISCOPE_VAL_TRIGGER_MOD_CLASS_EXT_BASE                 (100L)
#define IVISCOPE_VAL_TRIGGER_MOD_SPECIFIC_EXT_BASE              (1000L)

    /*- Defined values for IVISCOPE_ATTR_SAMPLE_MODE  */
#define IVISCOPE_VAL_REAL_TIME                                  (0L)
#define IVISCOPE_VAL_EQUIVALENT_TIME                            (1L)

/*****************************************************************************
 *-------- IviScope Class Instrument Driver Function Declarations -----------*
 *****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviScope_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviScope_close (ViSession vi);

ViStatus _VI_FUNC IviScope_reset (ViSession vi);

ViStatus _VI_FUNC IviScope_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviScope_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviScope_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviScope_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviScope_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviScope_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviScope_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviScope_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviScope_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviScope_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviScope_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviScope_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviScope_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviScope_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviScope_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviScope_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviScope_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviScope_GetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviScope_SetAttributeViString (ViSession vi, 
                                                 ViConstString channelName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviScope_CheckAttributeViString (ViSession vi, 
                                                   ViConstString channelName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviScope_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviScope_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviScope_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviScope_GetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviScope_SetAttributeViSession (ViSession vi, 
                                                  ViConstString channelName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviScope_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString channelName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviScope_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviScope_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviScope_GetError (ViSession vi, 
                                     ViStatus *errorCode, 
                                     ViInt32 bufferSize, 
                                     ViChar description[]);

ViStatus _VI_FUNC IviScope_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviScope_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviScope_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviScope_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviScope_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviScope_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);

ViStatus _VI_FUNC IviScope_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);
    /*- IviScope Fundamental Capabilities -*/
ViStatus _VI_FUNC IviScope_ConfigureChannel (ViSession vi, 
                                             ViConstString channel,
                                             ViReal64 range, 
                                             ViReal64 offset,
                                             ViInt32 coupling, 
                                             ViReal64 probeAttenuation,
                                             ViBoolean enabled);

ViStatus _VI_FUNC IviScope_ConfigureChanCharacteristics (ViSession vi,
                                                         ViConstString channel,
                                                         ViReal64 inputImpedance,
                                                         ViReal64 maxInputFrequency);

ViStatus _VI_FUNC IviScope_ConfigureAcquisitionType (ViSession vi, 
                                                     ViInt32 acquisitionType);

ViStatus _VI_FUNC IviScope_ConfigureAcquisitionRecord (ViSession vi, 
                                                       ViReal64 timePerRecord,
                                                       ViInt32 minimumRecordLength,
                                                       ViReal64 acqStartTime);

ViStatus _VI_FUNC IviScope_ActualRecordLength (ViSession vi, 
                                               ViInt32 *actualRecordLength);

ViStatus _VI_FUNC IviScope_SampleRate (ViSession vi, ViReal64 *sampleRate);

ViStatus _VI_FUNC IviScope_ConfigureTrigger (ViSession vi, 
                                             ViInt32 triggerType, 
                                             ViReal64 holdoff);

ViStatus _VI_FUNC IviScope_ConfigureTriggerCoupling (ViSession vi, 
                                                     ViInt32 coupling);

ViStatus _VI_FUNC IviScope_ConfigureEdgeTriggerSource (ViSession vi, 
                                                       ViConstString source,
                                                       ViReal64 level, 
                                                       ViInt32 slope);

ViStatus _VI_FUNC IviScope_ReadWaveform (ViSession vi, 
                                         ViConstString channel, 
                                         ViInt32 waveformSize,
                                         ViInt32 maxTime, 
                                         ViReal64 waveform[], 
                                         ViInt32 *actualPoints,
                                         ViReal64 *initialX, 
                                         ViReal64 *xIncrement);

ViStatus _VI_FUNC IviScope_Abort (ViSession vi);

ViStatus _VI_FUNC IviScope_InitiateAcquisition (ViSession vi);

ViStatus _VI_FUNC IviScope_AcquisitionStatus (ViSession vi, 
                                              ViInt32 *status);

ViStatus _VI_FUNC IviScope_FetchWaveform (ViSession vi, 
                                          ViConstString channel, 
                                          ViInt32 waveformSize,
                                          ViReal64 waveform[], 
                                          ViInt32 *actualPoints,
                                          ViReal64 *initialX, 
                                          ViReal64 *xIncrement);

ViStatus _VI_FUNC IviScope_IsInvalidWfmElement (ViSession vi, 
                                                ViReal64 elementValue,
                                                ViBoolean *isInvalid);

ViStatus _VI_FUNC IviScope_GetChannelName (ViSession vi, 
										   ViInt32 index,
                                           ViInt32 bufferSize,
                                           ViChar name[]);

    /*- IviScopeTVTrigger Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureTVTriggerSource (ViSession vi, 
                                                     ViConstString source, 
                                                     ViInt32 TVSignalFormat, 
                                                     ViInt32 TVEvent, 
                                                     ViInt32 TVPolarity);
ViStatus _VI_FUNC IviScope_ConfigureTVTriggerLineNumber (ViSession vi, 
                                                         ViInt32 lineNumber);

    /*- IviScopeRuntTrigger Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureRuntTriggerSource (ViSession vi, 
                                                       ViConstString source,
                                                       ViReal64 runtLowThreshold,
                                                       ViReal64 runtHighThreshold, 
                                                       ViInt32 runtPolarity);

    /*- IviScopeGlitchTrigger Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureGlitchTriggerSource (ViSession vi, 
                                                         ViConstString source,
                                                         ViReal64 level, 
                                                         ViReal64 glitchWidth, 
                                                         ViInt32 glitchPolarity,
                                                         ViInt32 glitchCondition);

    /*- IviScopeWidthTrigger Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureWidthTriggerSource (ViSession vi, 
                                                        ViConstString source,
                                                        ViReal64 level, 
                                                        ViReal64 widthLowThreshold, 
                                                        ViReal64 widthHighThreshold,
                                                        ViInt32 widthPolarity, 
                                                        ViInt32 widthCondition);

    /*- IviScopeAcLineTrigger Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureAcLineTriggerSlope (ViSession vi, 
                                                        ViInt32 slope);

    /*- IviScopeTriggerModifier Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureTriggerModifier (ViSession vi, 
                                                     ViInt32 triggerModifier);

    /*- IviScopeMinMaxWaveform Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureNumEnvelopes (ViSession vi, 
                                                  ViInt32 numberOfEnvelopes);

ViStatus _VI_FUNC IviScope_ReadMinMaxWaveform (ViSession vi, 
                                               ViConstString channel, 
                                               ViInt32 waveformSize, 
                                               ViInt32 maxTime,
                                               ViReal64 minWaveform[], 
                                               ViReal64 maxWaveform[], 
                                               ViInt32 *actualPoints, 
                                               ViReal64 *initialX, 
                                               ViReal64 *xIncrement);

ViStatus _VI_FUNC IviScope_FetchMinMaxWaveform (ViSession vi, 
                                                ViConstString channel, 
                                                ViInt32 waveformSize, 
                                                ViReal64 minWaveform[], 
                                                ViReal64 maxWaveform[],
                                                ViInt32 *actualPoints, 
                                                ViReal64 *initialX,
                                                ViReal64 *xIncrement);
    
    /*- IviScopeWaveformMeas Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureRefLevels (ViSession vi, ViReal64 lowRef, ViReal64 midRef, ViReal64 highRef);

ViStatus _VI_FUNC IviScope_ReadWaveformMeasurement (ViSession vi,
                                                    ViConstString channel, 
                                                    ViInt32 measurementFunction, 
                                                    ViInt32 maxTime, 
                                                    ViReal64 *measurement);

ViStatus _VI_FUNC IviScope_FetchWaveformMeasurement(ViSession vi,
                                                    ViConstString channel, 
                                                    ViInt32 measurementFunction, 
                                                    ViReal64 *measurement);

    /*- IviScope Average Acquisition Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureNumAverages (ViSession vi, 
                                                 ViInt32 numberOfAverages);

    /*- IviScope Continuous Acquisition Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureInitiateContinuous (ViSession vi, 
                                                        ViBoolean continuousAcquisition);

    /*- IviScope Interpolation Extension Group -*/
ViStatus _VI_FUNC IviScope_ConfigureInterpolation (ViSession vi, 
                                                   ViInt32 interpolation);

    /*- IviScope Sample Mode Extension Group -*/
ViStatus _VI_FUNC IviScope_SampleMode (ViSession vi, ViInt32 *sampleMode);

    /*- IviScope Probe Auto Sense Extension Group -*/
ViStatus _VI_FUNC IviScope_AutoProbeSenseValue (ViSession vi,
                                                ViConstString channel,
                                                ViReal64 *autoProbeSenseValue);
    /*- IviScope Auto Setup Extension Group -*/
ViStatus _VI_FUNC IviScope_AutoSetup (ViSession vi);
    
/*****************************************************************************
 *---------------- IviScope Class Error And Completion Codes ----------------*
 *****************************************************************************/
#define IVISCOPE_WARN_INVALID_WFM_ELEMENT              (IVI_CLASS_WARN_BASE+0x0001L)

#define IVISCOPE_ERROR_CHANNEL_NOT_ENABLED             (IVI_CLASS_ERROR_BASE+0x0001L)
#define IVISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT   (IVI_CLASS_ERROR_BASE+0x0002L)
#define IVISCOPE_ERROR_MAX_TIME_EXCEEDED               (IVI_CLASS_ERROR_BASE+0x0003L)
#define IVISCOPE_ERROR_INVALID_ACQ_TYPE                (IVI_CLASS_ERROR_BASE+0x0004L)

#define IVISCOPE_WARNMSG_INVALID_WFM_ELEMENT           "One of the elements in the waveform array is invalid."

#define IVISCOPE_ERRMSG_CHANNEL_NOT_ENABLED            "Specified channel is not enabled."
#define IVISCOPE_ERRMSG_UNABLE_TO_PERFORM_MEASUREMENT  "Unable to perform desired measurement operation."
#define IVISCOPE_ERRMSG_MAX_TIME_EXCEEDED              "Maximum time exceeded before the operation completed."
#define IVISCOPE_ERRMSG_INVALID_ACQ_TYPE               "Invalid acquisition type."

#define IVISCOPE_ERROR_CODES_AND_MSGS \
        {IVISCOPE_ERROR_CHANNEL_NOT_ENABLED,           IVISCOPE_ERRMSG_CHANNEL_NOT_ENABLED}, \
        {IVISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT, IVISCOPE_ERRMSG_UNABLE_TO_PERFORM_MEASUREMENT}, \
        {IVISCOPE_ERROR_MAX_TIME_EXCEEDED,             IVISCOPE_ERRMSG_MAX_TIME_EXCEEDED}, \
        {IVISCOPE_ERROR_INVALID_ACQ_TYPE,              IVISCOPE_ERRMSG_INVALID_ACQ_TYPE}, \
        {IVISCOPE_WARN_INVALID_WFM_ELEMENT,            IVISCOPE_WARNMSG_INVALID_WFM_ELEMENT}

/*- IviScopeObsolete.h included for backwards compatibility -*/
#include "IviScopeObsolete.h"

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVISCOPE_HEADER */
