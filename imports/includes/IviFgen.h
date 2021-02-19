/******************************************************************************
 *                            I V I - F G E N
 *-----------------------------------------------------------------------------
 *    Copytight (c) 1998-2020 National Instruments.  All Rights Reserved.
 *-----------------------------------------------------------------------------
 *
 * Title:       ivifgen.h
 * Purpose:     IviFgen Class declarations for the Base and Extended
 *              IviFgen Capabilities.
 ******************************************************************************/
 
#ifndef IVIFGEN_HEADER
#define IVIFGEN_HEADER

#include <ivi.h>

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#if defined(__cplusplus) || defined(__cpluplus__)
extern "C" {
#endif

/******************************************************************************
 *------------------ Instrument Driver Revision Information ------------------*
 ******************************************************************************/

#define IVIFGEN_MAJOR_VERSION               (5L)
#define IVIFGEN_MINOR_VERSION               (0L)

#define IVIFGEN_CLASS_SPEC_MAJOR_VERSION    (5L)
#define IVIFGEN_CLASS_SPEC_MINOR_VERSION    (2L)

#define IVIFGEN_DRIVER_VENDOR               "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIFGEN_DRIVER_DESCRIPTION          "IviFgen Class Driver [Compiled for 64-bit.]"
#else
#define IVIFGEN_DRIVER_DESCRIPTION          "IviFgen Class Driver"
#endif

/******************************************************************************
 *---------------------- IviFgen Class Attribute Defines ---------------------*
 ******************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVIFGEN_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIFGEN_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIFGEN_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS     /* ViBoolean */
#define IVIFGEN_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIFGEN_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIFGEN_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIFGEN_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVIFGEN_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIFGEN_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIFGEN_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION    /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     /* ViString, read-only */
#define IVIFGEN_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      /* ViString, read-only */
#define IVIFGEN_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIFGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIFGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /*- Version Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION              /* ViString, read-only */

#define IVIFGEN_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION             /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIFGEN_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                /* ViString */

    /*- IviFgen Fundamental Attributes -*/
#define IVIFGEN_ATTR_CHANNEL_COUNT              IVI_ATTR_CHANNEL_COUNT              /* (ViInt32), read-only */
#define IVIFGEN_ATTR_OUTPUT_MODE                (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)   /* (ViInt32) */
#define IVIFGEN_ATTR_REF_CLOCK_SOURCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)   /* (ViInt32) */
#define IVIFGEN_ATTR_OUTPUT_ENABLED             (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)   /* (ViBoolean,  Multi-Channel) */
#define IVIFGEN_ATTR_OUTPUT_IMPEDANCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)   /* (ViReal64,   Multi-Channel) */
#define IVIFGEN_ATTR_OPERATION_MODE             (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)   /* (ViInt32,    Multi-Channel) */

    /*- IviFgenSampleClock Extended Attributes -*/
#define IVIFGEN_ATTR_SAMPLE_CLOCK_SOURCE         (IVI_CLASS_PUBLIC_ATTR_BASE + 21L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_SAMPLE_CLOCK_OUTPUT_ENABLED (IVI_CLASS_PUBLIC_ATTR_BASE + 22L) /* (ViBoolean) */

    /*- IviFgenTerminalConfiguration Extended Attributes -*/
#define IVIFGEN_ATTR_TERMINAL_CONFIGURATION      (IVI_CLASS_PUBLIC_ATTR_BASE + 31L)  /* (ViInt32,    Multi-Channel) */

    /*- IviFgenStdFunc Extended Attributes -*/
#define IVIFGEN_ATTR_FUNC_WAVEFORM              (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_FUNC_AMPLITUDE             (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DC_OFFSET             (IVI_CLASS_PUBLIC_ATTR_BASE + 103L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_FREQUENCY             (IVI_CLASS_PUBLIC_ATTR_BASE + 104L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_START_PHASE           (IVI_CLASS_PUBLIC_ATTR_BASE + 105L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH       (IVI_CLASS_PUBLIC_ATTR_BASE + 106L)  /* (ViReal64,  Multi-Channel)  */

    /*- IviFgenArbWfm Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_ARB_GAIN                   (IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_OFFSET                 (IVI_CLASS_PUBLIC_ATTR_BASE + 203L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_SAMPLE_RATE            (IVI_CLASS_PUBLIC_ATTR_BASE + 204L)  /* (ViReal64)  */

#define IVIFGEN_ATTR_MAX_NUM_WAVEFORMS          (IVI_CLASS_PUBLIC_ATTR_BASE + 205L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_WAVEFORM_QUANTUM           (IVI_CLASS_PUBLIC_ATTR_BASE + 206L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 207L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 208L)  /* (ViInt32, Read-only)   */

    /*- IviFgenArbFrequency Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_FREQUENCY              (IVI_CLASS_PUBLIC_ATTR_BASE + 209L)  /* (ViReal64, Multi-Channel)  */    

    /*- IviFgenArbSeq Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_SEQUENCE_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_MAX_NUM_SEQUENCES          (IVI_CLASS_PUBLIC_ATTR_BASE + 212L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 213L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 214L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_LOOP_COUNT             (IVI_CLASS_PUBLIC_ATTR_BASE + 215L)  /* (ViInt32, Read-only)   */

    /*- IviFgenArbWfmSize64 Extended Attributes -*/
#define IVIFGEN_ATTR_MIN_WAVEFORM_SIZE64        (IVI_CLASS_PUBLIC_ATTR_BASE + 221L)  /* (ViInt64, Read-only)   */
#define IVIFGEN_ATTR_MAX_WAVEFORM_SIZE64        (IVI_CLASS_PUBLIC_ATTR_BASE + 222L)  /* (ViInt64, Read-only)   */

    /*- IviFgenArbWfmBinary Extended Attributes -*/
#define IVIFGEN_ATTR_BINARY_ALIGNMENT           (IVI_CLASS_PUBLIC_ATTR_BASE + 241L)  /* (ViInt32, Read-only)   */
#define	IVIFGEN_ATTR_SAMPLE_BIT_RESOLUTION      (IVI_CLASS_PUBLIC_ATTR_BASE + 242L)  /* (ViInt32, Read-only)   */

    /*- IviFgenArbDataMask Extended Attributes -*/
#define IVIFGEN_ATTR_OUTPUT_DATA_MASK           (IVI_CLASS_PUBLIC_ATTR_BASE + 261L)  /* (ViInt32) */

    /*- IviFgenArbSeqDepth Extended Attributes -*/
#define IVIFGEN_ATTR_SEQUENCE_DEPTH_MAX         (IVI_CLASS_PUBLIC_ATTR_BASE + 281L)  /* (ViInt32, Read-only)   */

    /*- IviFgenTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_TRIGGER_SOURCE             (IVI_CLASS_PUBLIC_ATTR_BASE + 302L)  /* (ViInt32, Multi-Channel)   */

    /*- IviFgenInternalTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_INTERNAL_TRIGGER_RATE      (IVI_CLASS_PUBLIC_ATTR_BASE + 310L)  /* (ViReal64)   */  

    /*- IviFgenStartTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_START_TRIGGER_DELAY        (IVI_CLASS_PUBLIC_ATTR_BASE + 320L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_START_TRIGGER_SLOPE        (IVI_CLASS_PUBLIC_ATTR_BASE + 321L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_START_TRIGGER_SOURCE       (IVI_CLASS_PUBLIC_ATTR_BASE + 322L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_START_TRIGGER_THRESHOLD    (IVI_CLASS_PUBLIC_ATTR_BASE + 323L)  /* (ViReal64, Multi-Channel)  */

    /*- IviFgenStopTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_STOP_TRIGGER_DELAY         (IVI_CLASS_PUBLIC_ATTR_BASE + 330L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_STOP_TRIGGER_SLOPE         (IVI_CLASS_PUBLIC_ATTR_BASE + 331L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_STOP_TRIGGER_SOURCE        (IVI_CLASS_PUBLIC_ATTR_BASE + 332L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_STOP_TRIGGER_THRESHOLD     (IVI_CLASS_PUBLIC_ATTR_BASE + 333L)  /* (ViReal64, Multi-Channel)  */

    /*- IviFgenHoldTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_HOLD_TRIGGER_DELAY         (IVI_CLASS_PUBLIC_ATTR_BASE + 340L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_HOLD_TRIGGER_SLOPE         (IVI_CLASS_PUBLIC_ATTR_BASE + 341L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_HOLD_TRIGGER_SOURCE        (IVI_CLASS_PUBLIC_ATTR_BASE + 342L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_HOLD_TRIGGER_THRESHOLD      (IVI_CLASS_PUBLIC_ATTR_BASE + 343L)  /* (ViReal64, Multi-Channel)  */

    /*- IviFgenBurst Extended Attributes -*/
#define IVIFGEN_ATTR_BURST_COUNT                (IVI_CLASS_PUBLIC_ATTR_BASE + 350L)  /* (ViInt32, Multi-Channel)   */  

    /*- IviFgenResumeTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_RESUME_TRIGGER_DELAY       (IVI_CLASS_PUBLIC_ATTR_BASE + 360L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_RESUME_TRIGGER_SLOPE       (IVI_CLASS_PUBLIC_ATTR_BASE + 361L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_RESUME_TRIGGER_SOURCE      (IVI_CLASS_PUBLIC_ATTR_BASE + 362L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_RESUME_TRIGGER_THRESHOLD   (IVI_CLASS_PUBLIC_ATTR_BASE + 363L)  /* (ViReal64, Multi-Channel)  */

    /*- IviFgenAdvanceTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_ADVANCE_TRIGGER_DELAY      (IVI_CLASS_PUBLIC_ATTR_BASE + 370L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ADVANCE_TRIGGER_SLOPE      (IVI_CLASS_PUBLIC_ATTR_BASE + 371L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_ADVANCE_TRIGGER_SOURCE     (IVI_CLASS_PUBLIC_ATTR_BASE + 372L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_ADVANCE_TRIGGER_THRESHOLD  (IVI_CLASS_PUBLIC_ATTR_BASE + 373L)  /* (ViReal64, Multi-Channel)  */

    /*- IviFgenModulateAM Extended Attributes -*/
#define IVIFGEN_ATTR_AM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_AM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_AM_INTERNAL_DEPTH          (IVI_CLASS_PUBLIC_ATTR_BASE + 403L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 404L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_AM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 405L)  /* (ViReal64)  */

    /*- IviFgenModulateFM Extended Attributes -*/
#define IVIFGEN_ATTR_FM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_FM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_FM_INTERNAL_DEVIATION      (IVI_CLASS_PUBLIC_ATTR_BASE + 503L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 504L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_FM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 505L)  /* (ViReal64)  */

    /*- IviFgenDataMarker Extended Attributes -*/
#define IVIFGEN_ATTR_DATAMARKER_AMPLITUDE       (IVI_CLASS_PUBLIC_ATTR_BASE + 601L)  /* (ViReal64) */
#define IVIFGEN_ATTR_DATAMARKER_BIT_POSITION    (IVI_CLASS_PUBLIC_ATTR_BASE + 602L)  /* (ViInt32)  */
#define IVIFGEN_ATTR_DATAMARKER_COUNT           (IVI_CLASS_PUBLIC_ATTR_BASE + 603L)  /* (ViInt32, Read-only )      */
#define IVIFGEN_ATTR_DATAMARKER_DELAY           (IVI_CLASS_PUBLIC_ATTR_BASE + 604L)  /* (ViReal64) */
#define IVIFGEN_ATTR_DATAMARKER_DESTINATION     (IVI_CLASS_PUBLIC_ATTR_BASE + 605L)  /* (ViString) */
#define IVIFGEN_ATTR_DATAMARKER_POLARITY        (IVI_CLASS_PUBLIC_ATTR_BASE + 606L)  /* (ViInt32)  */
#define IVIFGEN_ATTR_DATAMARKER_SOURCE_CHANNEL  (IVI_CLASS_PUBLIC_ATTR_BASE + 607L)  /* (ViString) */

    /*- IviFgenSparseMarker Extended Attributes -*/
#define IVIFGEN_ATTR_SPARSEMARKER_AMPLITUDE     (IVI_CLASS_PUBLIC_ATTR_BASE + 701L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_SPARSEMARKER_COUNT         (IVI_CLASS_PUBLIC_ATTR_BASE + 702L)  /* (ViInt32,  Read-only)      */
#define IVIFGEN_ATTR_SPARSEMARKER_DELAY         (IVI_CLASS_PUBLIC_ATTR_BASE + 703L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_SPARSEMARKER_DESTINATION   (IVI_CLASS_PUBLIC_ATTR_BASE + 704L)  /* (ViString, Multi-Channel)  */
#define IVIFGEN_ATTR_SPARSEMARKER_POLARITY      (IVI_CLASS_PUBLIC_ATTR_BASE + 705L)  /* (ViInt32,  Multi-Channel)  */
#define IVIFGEN_ATTR_SPARSEMARKER_WFMHANDLE     (IVI_CLASS_PUBLIC_ATTR_BASE + 706L)  /* (ViInt32,  Multi-Channel)  */

/******************************************************************************
 *------------------- IviFgen Class Attribute Value Defines ------------------*
 ******************************************************************************/

   /*- Defined valued for attribute IVIFGEN_ATTR_OUTPUT_MODE -*/
#define IVIFGEN_VAL_OUTPUT_FUNC                         (0L)
#define IVIFGEN_VAL_OUTPUT_ARB                          (1L)
#define IVIFGEN_VAL_OUTPUT_SEQ                          (2L)

#define IVIFGEN_VAL_OUT_MODE_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_OUT_MODE_SPECIFIC_EXT_BASE          (1000L)

   /*- Defined valued for attribute IVIFGEN_ATTR_OPERATION_MODE -*/
#define IVIFGEN_VAL_OPERATE_CONTINUOUS                  (0L)
#define IVIFGEN_VAL_OPERATE_BURST                       (1L)

#define IVIFGEN_VAL_OP_MODE_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_OP_MODE_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_REF_CLOCK_SOURCE -*/
#define IVIFGEN_VAL_REF_CLOCK_INTERNAL                  (0L)
#define IVIFGEN_VAL_REF_CLOCK_EXTERNAL                  (1L)
#define IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK                (101L)

#define IVIFGEN_VAL_CLK_SRC_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_CLK_SRC_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_FUNC_WAVEFORM -*/
#define IVIFGEN_VAL_WFM_SINE                            (1L)
#define IVIFGEN_VAL_WFM_SQUARE                          (2L)
#define IVIFGEN_VAL_WFM_TRIANGLE                        (3L)
#define IVIFGEN_VAL_WFM_RAMP_UP                         (4L)
#define IVIFGEN_VAL_WFM_RAMP_DOWN                       (5L)
#define IVIFGEN_VAL_WFM_DC                              (6L)

#define IVIFGEN_VAL_WFM_CLASS_EXT_BASE                  (500L)
#define IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE               (1000L)

    /*- Defined values for attribute IVIFGEN_ATTR_TRIGGER_SOURCE -*/
#define IVIFGEN_VAL_EXTERNAL                            (1L)
#define IVIFGEN_VAL_SOFTWARE_TRIG                       (2L)
#define IVIFGEN_VAL_INTERNAL_TRIGGER                    (3L) 
#define IVIFGEN_VAL_TTL0                                (111L)
#define IVIFGEN_VAL_TTL1                                (112L)
#define IVIFGEN_VAL_TTL2                                (113L)
#define IVIFGEN_VAL_TTL3                                (114L)
#define IVIFGEN_VAL_TTL4                                (115L)
#define IVIFGEN_VAL_TTL5                                (116L)
#define IVIFGEN_VAL_TTL6                                (117L)
#define IVIFGEN_VAL_TTL7                                (118L)
#define IVIFGEN_VAL_ECL0                                (119L)
#define IVIFGEN_VAL_ECL1                                (120L)
#define IVIFGEN_VAL_PXI_STAR                            (131L)
#define IVIFGEN_VAL_RTSI_0                              (141L)
#define IVIFGEN_VAL_RTSI_1                              (142L)
#define IVIFGEN_VAL_RTSI_2                              (143L)
#define IVIFGEN_VAL_RTSI_3                              (144L)
#define IVIFGEN_VAL_RTSI_4                              (145L)
#define IVIFGEN_VAL_RTSI_5                              (146L)
#define IVIFGEN_VAL_RTSI_6                              (147L)

#define IVIFGEN_VAL_TRIG_SRC_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE          (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_START_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_STOP_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_HOLD_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_RESUME_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_ADVANCE_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_RESUME_TRIGGER_SOURCE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_DATA_MARKER_DESTINATION -*/
  /*- Defined values for attribute IVIFGEN_ATTR_SPARSE_MARKER_DESTINATION -*/
#define IVIFGEN_VAL_TRIGGER_SOURCE_NONE                 ""
#define IVIFGEN_VAL_TRIGGER_SOURCE_IMMEDIATE            "Immediate"
#define IVIFGEN_VAL_TRIGGER_SOURCE_EXTERNAL             "External"
#define IVIFGEN_VAL_TRIGGER_SOURCE_INTERNAL             "Internal"
#define IVIFGEN_VAL_TRIGGER_SOURCE_SOFTWARE             "Software"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN0                 "LAN0"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN1                 "LAN1"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN2                 "LAN2"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN3                 "LAN3"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN4                 "LAN4"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN5                 "LAN5"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN6                 "LAN6"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LAN7                 "LAN7"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI0                 "LXI0"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI1                 "LXI1"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI2                 "LXI2"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI3                 "LXI3"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI4                 "LXI4"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI5                 "LXI5"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI6                 "LXI6"
#define IVIFGEN_VAL_TRIGGER_SOURCE_LXI7                 "LXI7"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL0                 "TTL0"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL1                 "TTL1"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL2                 "TTL2"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL3                 "TTL3"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL4                 "TTL4"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL5                 "TTL5"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL6                 "TTL6"
#define IVIFGEN_VAL_TRIGGER_SOURCE_TTL7                 "TTL7"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_STAR             "PXI_STAR"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG0            "PXI_TRIG0"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG1            "PXI_TRIG1"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG2            "PXI_TRIG2"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG3            "PXI_TRIG3"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG4            "PXI_TRIG4"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG5            "PXI_TRIG5"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG6            "PXI_TRIG6"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXI_TRIG7            "PXI_TRIG7"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXIE_DSTARA          "PXIe_DSTARA"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXIE_DSTARB          "PXIe_DSTARB"
#define IVIFGEN_VAL_TRIGGER_SOURCE_PXIE_DSTARC          "PXIe_DSTARC"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI0                "RTSI0"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI1                "RTSI1"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI2                "RTSI2"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI3                "RTSI3"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI4                "RTSI4"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI5                "RTSI5"
#define IVIFGEN_VAL_TRIGGER_SOURCE_RTSI6                "RTSI6"

  /*- Defined values for attribute IVIFGEN_ATTR_SAMPLE_CLOCK_SOURCE -*/
#define IVIFGEN_VAL_SAMPLE_CLOCK_SOURCE_INTERNAL        (0L)
#define IVIFGEN_VAL_SAMPLE_CLOCK_SOURCE_EXTERNAL        (1L)
	
  /*- Defined values for attribute IVIFGEN_ATTR_DATAMARKER_POLARITY -*/
#define IVIFGEN_VAL_MARKER_POLARITY_ACTIVE_HIGH         (0L)
#define IVIFGEN_VAL_MARKER_POLARITY_ACTIVE_LOW          (1L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_SOURCE -*/
#define IVIFGEN_VAL_AM_INTERNAL                         (0L)
#define IVIFGEN_VAL_AM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_AM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_AM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_AM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_AM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_AM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_AM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_SOURCE -*/
#define IVIFGEN_VAL_FM_INTERNAL                         (0L)
#define IVIFGEN_VAL_FM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_FM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_FM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_FM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_FM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_FM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_FM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_BINARY_ALIGNMENT -*/
#define IVIFGEN_VAL_BINARY_ALIGNMENT_LEFT               (0L)
#define IVIFGEN_VAL_BINARY_ALIGNMENT_RIGHT              (1L)

#define IVIFGEN_VAL_BINARY_ALIGNMENT_CLASS_EXT_BASE     (500L)
#define IVIFGEN_VAL_BINARY_ALIGNMENT_SPECIFIC_EXT_BASE  (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_OUTPUT_TERMINAL_CONFIGURATION -*/
#define IVIFGEN_VAL_TERMINAL_CONFIGURATION_SINGLE_ENDED         (0L)
#define IVIFGEN_VAL_TERMINAL_CONFIGURATION_DIFFERENTIAL         (1L)

#define IVIFGEN_VAL_TERMINAL_CONFIGURATION_CLASS_EXT_BASE       (500L)
#define IVIFGEN_VAL_TERMINAL_CONFIGURATION_SPECIFIC_EXT_BASE    (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_START_TRIGGER_SLOPE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_STOP_TRIGGER_SLOPE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_HOLD_TRIGGER_SLOPE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_RESUME_TRIGGER_SLOPE -*/
  /*- Defined values for attribute IVIFGEN_ATTR_ADVANCE_TRIGGER_SLOPE -*/
#define IVIFGEN_VAL_TRIGGER_POSITIVE                    (0L)
#define IVIFGEN_VAL_TRIGGER_NEGATIVE                    (1L)
#define IVIFGEN_VAL_TRIGGER_EITHER                      (2L)

#define IVIFGEN_VAL_TRIGGER_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_TRIGGER_SPECIFIC_EXT_BASE           (1000L)
	
   /*- Defined values for waveformHandle parameter for function IviFgen_ClearArbWaveform -*/
#define IVIFGEN_VAL_ALL_WAVEFORMS                       (-1L)

   /*- Defined values for sequenceHandle parameter for function IviFgen_ClearArbSequence -*/
#define IVIFGEN_VAL_ALL_SEQUENCES                       (-1L)

/******************************************************************************
 *----------- IviFgen Class Instrument Driver Function Declarations ----------*
 ******************************************************************************/
   /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviFgen_init (ViRsrc logicalName, 
                                ViBoolean IDQuery,
                                ViBoolean resetDevice, 
                                ViSession *vi);

ViStatus _VI_FUNC IviFgen_close (ViSession vi);

ViStatus _VI_FUNC IviFgen_reset (ViSession vi);

ViStatus _VI_FUNC IviFgen_self_test (ViSession vi, 
                                     ViInt16* selfTestResult,
                                     ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviFgen_error_query (ViSession vi, 
                                       ViInt32 *errorCode, 
                                       ViChar errorMessage[]);

ViStatus _VI_FUNC IviFgen_error_message (ViSession vi, 
                                         ViStatus statusCode,
                                         ViChar message[]);

ViStatus _VI_FUNC IviFgen_revision_query (ViSession vi, 
                                          ViChar driverRev[],
                                          ViChar instrRev[]);
                                           
    /*- Utility Functions -*/
ViStatus _VI_FUNC IviFgen_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviFgen_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviFgen_Disable (ViSession vi);

   /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviFgen_InitWithOptions (ViRsrc logicalName, 
                                           ViBoolean IDQuery,
                                           ViBoolean resetDevice, 
                                           ViConstString optionString, 
                                           ViSession *vi);

   /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviFgen_GetAttributeViInt32 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId, 
                                               ViInt32 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViInt32 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId,
                                               ViInt32 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViInt32 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attributeId,
                                                 ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviFgen_GetAttributeViInt64 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId, 
                                               ViInt64 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViInt64 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId,
                                               ViInt64 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViInt64 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attributeId,
                                                 ViInt64 value);
#endif

ViStatus _VI_FUNC IviFgen_GetAttributeViReal64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViReal64 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViReal64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViReal64 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViReal64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId, 
                                                  ViReal64 value);

ViStatus _VI_FUNC IviFgen_GetAttributeViString (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViInt32 bufferSize,
                                                ViChar value[]);

ViStatus _VI_FUNC IviFgen_SetAttributeViString (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViConstString value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViString (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId, 
                                                  ViConstString value);

ViStatus _VI_FUNC IviFgen_GetAttributeViBoolean (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViBoolean *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViBoolean (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViBoolean value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViBoolean (ViSession vi, 
                                                   ViConstString channelName,
                                                   ViAttr attributeId, 
                                                   ViBoolean value);

ViStatus _VI_FUNC IviFgen_GetAttributeViSession (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViSession *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViSession (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViSession value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViSession (ViSession vi, 
                                                   ViConstString channelName,
                                                   ViAttr attributeId, 
                                                   ViSession value);

   /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviFgen_LockSession (ViSession vi, 
                                       ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviFgen_UnlockSession (ViSession vi, 
                                         ViBoolean *callerHasLock);

   /*- Error Information Functions -*/
ViStatus _VI_FUNC IviFgen_GetError (ViSession vi, 
                                    ViStatus *errorCode,
                                    ViInt32 bufferSize,
                                    ViChar description[]);

ViStatus _VI_FUNC IviFgen_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviFgen_GetNextInterchangeWarning (ViSession vi, 
                                                     ViInt32 bufferSize, 
                                                     ViChar warning[]);

ViStatus _VI_FUNC IviFgen_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviFgen_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviFgen_GetNextCoercionRecord (ViSession vi, 
                                                 ViInt32 bufferSize, 
                                                 ViChar record[]);

ViStatus _VI_FUNC IviFgen_GetSpecificDriverCHandle (ViSession vi,
                                                    ViSession* specificDriverCHandle);
   
ViStatus _VI_FUNC IviFgen_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);
   /*- IviFgenBase Capability Group  -*/
ViStatus _VI_FUNC IviFgen_ConfigureOutputMode (ViSession vi, 
                                               ViInt32 outputMode);
ViStatus _VI_FUNC IviFgen_ConfigureOperationMode (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 operationMode);

ViStatus _VI_FUNC IviFgen_ConfigureRefClockSource (ViSession vi, 
                                                   ViInt32 refClockSource);

ViStatus _VI_FUNC IviFgen_ConfigureOutputImpedance (ViSession vi, 
                                                    ViConstString channelName,
                                                    ViReal64 outputImpedance);

ViStatus _VI_FUNC IviFgen_ConfigureOutputEnabled (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_GetChannelName (ViSession vi,
                                          ViInt32 index,
                                          ViInt32 bufferSize,
                                          ViChar name[]);

ViStatus _VI_FUNC IviFgen_InitiateGeneration (ViSession vi);

ViStatus _VI_FUNC IviFgen_AbortGeneration    (ViSession vi);

   /*- IviFgenStdFunc Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureStandardWaveform (ViSession vi, 
                                                     ViConstString channelName,
                                                     ViInt32 waveform, 
                                                     ViReal64 amplitude,
                                                     ViReal64 dcOffset, 
                                                     ViReal64 frequency,
                                                     ViReal64 startPhase);

    /*- IviFgenArbWfm Extension Group -*/
ViStatus _VI_FUNC IviFgen_QueryArbWfmCapabilities (ViSession vi, 
                                                   ViInt32 *maxNumWfms,
                                                   ViInt32 *wfmQuantum,
                                                   ViInt32 *minWfmSize,
                                                   ViInt32 *maxWfmSize);

ViStatus _VI_FUNC IviFgen_CreateArbWaveform (ViSession vi,
                                             ViInt32 wfmSize,
                                             ViReal64 wfmData[], 
                                             ViInt32 *wfmHandle);

ViStatus _VI_FUNC IviFgen_ConfigureSampleRate (ViSession vi, 
                                               ViReal64 sampleRate);

ViStatus _VI_FUNC IviFgen_ConfigureArbWaveform (ViSession vi, 
                                                ViConstString channelName,
                                                ViInt32 wfmHandle,
                                                ViReal64 arbGain,
                                                ViReal64 arbOffset);

ViStatus _VI_FUNC IviFgen_ClearArbWaveform (ViSession vi, 
                                            ViInt32 wfmHandle);

    /*- IviFgenArbFrequency Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureArbFrequency (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViReal64 frequency);

    /*- IviFgenArbSeq Extension Group -*/ 
ViStatus _VI_FUNC IviFgen_QueryArbSeqCapabilities (ViSession vi, 
                                                   ViInt32 *maxNumSeqs,
                                                   ViInt32 *minSeqLength, 
                                                   ViInt32 *maxSeqLength,
                                                   ViInt32 *maxLoopCount);

ViStatus _VI_FUNC IviFgen_CreateArbSequence (ViSession vi, 
                                             ViInt32 seqLength,
                                             ViInt32 wfmHandle[], 
                                             ViInt32 wfmLoopCount[],
                                             ViInt32 *seqHandle);

ViStatus _VI_FUNC IviFgen_ConfigureArbSequence (ViSession vi, 
                                                ViConstString channelName,
                                                ViInt32 seqHandle,
                                                ViReal64 arbGain,
                                                ViReal64 arbOffset);

ViStatus _VI_FUNC IviFgen_ClearArbSequence (ViSession vi, 
                                            ViInt32 seqHandle);

ViStatus _VI_FUNC IviFgen_ClearArbMemory (ViSession vi);

    /*- IviFgenTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureTriggerSource (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 trigSource);

    /*- IviFgenStartTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureStartTrigger (ViSession vi,
                                                 ViConstString channelName,
                                                 ViConstString source,
                                                 ViInt32 slope);

    /*- IviFgenStopTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureStopTrigger (ViSession vi,
                                                ViConstString channelName,
                                                ViConstString source,
                                                ViInt32 slope);

ViStatus _VI_FUNC IviFgen_SendSoftwareStopTrigger (ViSession vi);

    /*- IviFgenHoldTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureHoldTrigger (ViSession vi,
                                                ViConstString channelName,
                                                ViConstString source,
                                                ViInt32 slope);

ViStatus _VI_FUNC IviFgen_SendSoftwareHoldTrigger (ViSession vi);

    /*- IviFgenResumeTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureResumeTrigger (ViSession vi,
                                                  ViConstString channelName,
                                                  ViConstString source,
                                                  ViInt32 slope);

ViStatus _VI_FUNC IviFgen_SendSoftwareResumeTrigger (ViSession vi);

    /*- IviFgenAdvanceTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureAdvanceTrigger (ViSession vi,
                                                   ViConstString channelName,
                                                   ViConstString source,
                                                   ViInt32 slope);

ViStatus _VI_FUNC IviFgen_SendSoftwareAdvanceTrigger (ViSession vi);

    /*- IviFgenInternalTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureInternalTriggerRate (ViSession vi,
                                                        ViReal64 rate);

    /*- IviFgenSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_SendSoftwareTrigger (ViSession vi);

    /*- IviFgenBurst Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureBurstCount (ViSession vi,
                                               ViConstString channelName,
                                               ViInt32 count);

    /*- IviFgenModulateAM Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureAMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_ConfigureAMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source);

ViStatus _VI_FUNC IviFgen_ConfigureAMInternal (ViSession vi, 
                                               ViReal64 amdepth,
                                               ViInt32 amWaveform,
                                               ViReal64 amFrequency);

    /*- IviFgenModulateFM Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureFMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_ConfigureFMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source);

ViStatus _VI_FUNC IviFgen_ConfigureFMInternal (ViSession vi, 
                                               ViReal64 fmdeviation,
                                               ViInt32 fmWaveform,
                                               ViReal64 fmFrequency);

    /*- IviFgenSampleClock Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureSampleClock (ViSession vi, 
                                                ViInt32 source);

ViStatus _VI_FUNC IviFgen_ConfigureSampleClockOutputEnabled (ViSession vi,
                                                             ViBoolean enabled);

    /*- IviFgenArbWfmSize64 Extension Group -*/
ViStatus _VI_FUNC IviFgen_QueryArbWfmCapabilities64 (ViSession vi,
                                                     ViInt32 *maxNumWfms,
                                                     ViInt32 *wfmQuantum,
                                                     ViInt64 *minWfmSize,
                                                     ViInt64 *maxWfmSize);

    /*- IviFgenArbChannelWfm Extension Group -*/
ViStatus _VI_FUNC IviFgen_CreateChannelArbWaveform (ViSession vi,
                                                    ViConstString channelName,
                                                    ViInt64 wfmSize,
                                                    ViReal64 wfmData[],
                                                    ViInt32 *wfmHandle);

    /*- IviFgenArbWfmBinary Extension Group -*/
ViStatus _VI_FUNC IviFgen_CreateChannelArbWaveform16 (ViSession vi,
                                                      ViConstString channelName,
                                                      ViInt64 wfmSize,
                                                      ViInt16 wfmData[],
                                                      ViInt32 *wfmHandle);

ViStatus _VI_FUNC IviFgen_CreateChannelArbWaveform32 (ViSession vi,
                                                      ViConstString channelName,
                                                      ViInt64 wfmSize,
                                                      ViInt32 wfmData[],
                                                      ViInt32 *wfmHandle);

    /*- IviFgenDataMarker Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureDataMarker (ViSession vi,
                                               ViConstString name,
                                               ViConstString sourceChannel,
                                               ViInt32 bitPosition,
                                               ViConstString destination);

ViStatus _VI_FUNC IviFgen_GetDataMarkerName (ViSession vi,
                                             ViInt32 index, 
                                             ViInt32 nameBufferSize,
                                             ViChar name[]);

ViStatus _VI_FUNC IviFgen_DisableAllDataMarkers (ViSession vi);

    /*- IviFgenSparseMarker Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureSparseMarker (ViSession vi,
                                                 ViConstString name,
                                                 ViInt32 wfmHandle,
                                                 ViInt64 numIndexes, 
                                                 ViInt64 indexes[],
                                                 ViConstString destination);

ViStatus _VI_FUNC IviFgen_GetSparseMarkerName (ViSession vi,
                                               ViInt32 index, 
                                               ViInt32 nameBufferSize,
                                               ViChar name[]);

ViStatus _VI_FUNC IviFgen_GetSparseMarkerIndexes (ViSession vi,
                                                  ViConstString name,
                                                  ViInt64 indexesArraySize,
                                                  ViInt64 indexes[],
                                                  ViInt64 *indexesActualSize);

ViStatus _VI_FUNC IviFgen_SetSparseMarkerIndexes (ViSession vi,
                                                  ViConstString name,
                                                  ViInt64 indexesArraySize,
                                                  ViInt64 indexes[]);

ViStatus _VI_FUNC IviFgen_DisableAllSparseMarkers (ViSession vi);

/******************************************************************************
 *----------------- IviFgen Class Error And Completion Codes -----------------*
 ******************************************************************************/
#define IVIFGEN_ERROR_NO_WFMS_AVAILABLE       (IVI_CLASS_ERROR_BASE + 4L)
#define IVIFGEN_ERROR_WFM_IN_USE              (IVI_CLASS_ERROR_BASE + 8L)
#define IVIFGEN_ERROR_NO_SEQS_AVAILABLE       (IVI_CLASS_ERROR_BASE + 9L)
#define IVIFGEN_ERROR_SEQ_IN_USE              (IVI_CLASS_ERROR_BASE + 13L)
#define IVIFGEN_ERROR_INVALID_WFM_CHANNEL     (IVI_CLASS_ERROR_BASE + 14L)
#define IVIFGEN_ERROR_TRIGGER_NOT_SOFTWARE    (IVI_CROSS_CLASS_ERROR_BASE + 1L)

#define IVIFGEN_ERRMSG_NO_WFMS_AVAILABLE      "The function generator's waveform memory is full."
#define IVIFGEN_ERRMSG_WFM_IN_USE             "The waveform is currently in use."
#define IVIFGEN_ERRMSG_NO_SEQS_AVAILABLE      "The function generator's sequence memory is full."
#define IVIFGEN_ERRMSG_SEQ_IN_USE             "The sequence is currently in use."
#define IVIFGEN_ERRMSG_INVALID_WFM_CHANNEL    "The waveform was created on a different channel than the one for which it is being configured."
#define IVIFGEN_ERRMSG_TRIGGER_NOT_SOFTWARE   "The trigger source is not set to software trigger."

#define IVIFGEN_ERROR_CODES_AND_MSGS \
        { IVIFGEN_ERROR_NO_WFMS_AVAILABLE,    IVIFGEN_ERRMSG_NO_WFMS_AVAILABLE   }, \
        { IVIFGEN_ERROR_WFM_IN_USE,           IVIFGEN_ERRMSG_WFM_IN_USE          }, \
        { IVIFGEN_ERROR_NO_SEQS_AVAILABLE,    IVIFGEN_ERRMSG_NO_SEQS_AVAILABLE   }, \
        { IVIFGEN_ERROR_SEQ_IN_USE,           IVIFGEN_ERRMSG_SEQ_IN_USE          }, \
        { IVIFGEN_ERROR_INVALID_WFM_CHANNEL,  IVIFGEN_ERRMSG_INVALID_WFM_CHANNEL }, \
        { IVIFGEN_ERROR_TRIGGER_NOT_SOFTWARE, IVIFGEN_ERRMSG_TRIGGER_NOT_SOFTWARE}

/*- IviFgenObsolete.h included for backwards compatibility -*/
#include "IviFgenObsolete.h"

/******************************************************************************
 *----------------------------- End Include File -----------------------------*
 ******************************************************************************/
#if defined(__cplusplus) || defined(c__plusplus)
}
#endif

#endif /* IVIFGEN_HEADER */
