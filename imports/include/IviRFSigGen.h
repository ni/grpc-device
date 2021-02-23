/****************************************************************************
 *                         IVIRFSIGGEN                               
 *---------------------------------------------------------------------------
 *    Copyright (c) 2009-2020 National Instruments.  All Rights Reserved.        
 *---------------------------------------------------------------------------
 *                                                                          
 * Title:       IviRFSigGen.h                                                    
 * Purpose:     IviRFSigGen Class declarations for the Base and Extended  
 *              IviRFSigGen Capabilities.                                        
 ****************************************************************************/

#ifndef IVIRFSIGGEN_HEADER
#define IVIRFSIGGEN_HEADER

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

#define IVIRFSIGGEN_MAJOR_VERSION              (4L)
#define IVIRFSIGGEN_MINOR_VERSION              (0L)

#define IVIRFSIGGEN_CLASS_SPEC_MAJOR_VERSION   (2L)
#define IVIRFSIGGEN_CLASS_SPEC_MINOR_VERSION   (0L)

#define IVIRFSIGGEN_DRIVER_VENDOR              "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIRFSIGGEN_DRIVER_DESCRIPTION         "IviRFSigGen Class Driver [Compiled for 64-bit.]"
#else
#define IVIRFSIGGEN_DRIVER_DESCRIPTION         "IviRFSigGen Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/
/*- Defined values for MaxTimeMilliseconds parameter of function -*/
/*- IviRFSigGen_WaitUntilSettled -*/
#define IVIRFSIGGEN_VAL_MAX_TIME_IMMEDIATE                                  (0L)
#define IVIRFSIGGEN_VAL_MAX_TIME_INFINITE                                  (0xFFFFFFFFUL)



/****************************************************************************
 *------------------ IviRFSigGen Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/

        /*- User Options -*/
#define IVIRFSIGGEN_ATTR_CACHE                     IVI_ATTR_CACHE                         /* ViBoolean */
#define IVIRFSIGGEN_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVIRFSIGGEN_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVIRFSIGGEN_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVIRFSIGGEN_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVIRFSIGGEN_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVIRFSIGGEN_ATTR_SPY                       IVI_ATTR_SPY                           /* ViBoolean */
#define IVIRFSIGGEN_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

	/* Instrument Capabilities */
#define IVIRFSIGGEN_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT                 /* ViInt32,  read-only  */

        /*- Instrument Capabilities -*/
#define IVIRFSIGGEN_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/    
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                    /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIRFSIGGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVIRFSIGGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only */
  
        /*- Version Information -*/
#define IVIRFSIGGEN_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVIRFSIGGEN_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVIRFSIGGEN_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviRFSigGen Fundamental Attributes -*/
#define IVIRFSIGGEN_ATTR_FREQUENCY                                      (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)    /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_LEVEL                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)    /* ViReal64 */
#define IVIRFSIGGEN_ATTR_ALC_ENABLED                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)    /* ViBoolean */
#define IVIRFSIGGEN_ATTR_OUTPUT_ENABLED                                 (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)    /* ViBoolean */

    /*- IviRFSigGen Extended Attributes -*/
        /*- IviRFSigGenModulateAM Extension Group -*/
#define IVIRFSIGGEN_ATTR_AM_ENABLED                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 11L)   /* ViBoolean */
#define IVIRFSIGGEN_ATTR_AM_SOURCE                                      (IVI_CLASS_PUBLIC_ATTR_BASE + 12L)   /* ViString */
#define IVIRFSIGGEN_ATTR_AM_SCALING                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 13L)   /* ViInt32 */
#define IVIRFSIGGEN_ATTR_AM_EXTERNAL_COUPLING                           (IVI_CLASS_PUBLIC_ATTR_BASE + 14L)   /* ViInt32 */
#define IVIRFSIGGEN_ATTR_AM_NOMINAL_VOLTAGE                             (IVI_CLASS_PUBLIC_ATTR_BASE + 15L)   /* ViReal64 */
#define IVIRFSIGGEN_ATTR_AM_DEPTH                                       (IVI_CLASS_PUBLIC_ATTR_BASE + 16L)   /* ViReal64 */

        /*- IviRFSigGenModulateFM Extension Group -*/
#define IVIRFSIGGEN_ATTR_FM_ENABLED                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 21L)   /* ViBoolean */
#define IVIRFSIGGEN_ATTR_FM_SOURCE                                      (IVI_CLASS_PUBLIC_ATTR_BASE + 22L)   /* ViString */
#define IVIRFSIGGEN_ATTR_FM_EXTERNAL_COUPLING                           (IVI_CLASS_PUBLIC_ATTR_BASE + 23L)   /* ViInt32 */
#define IVIRFSIGGEN_ATTR_FM_NOMINAL_VOLTAGE                             (IVI_CLASS_PUBLIC_ATTR_BASE + 24L)   /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FM_DEVIATION                                   (IVI_CLASS_PUBLIC_ATTR_BASE + 25L)   /* ViReal64 */

        /*- IviRFSigGenModulatePM Extension Group -*/
#define IVIRFSIGGEN_ATTR_PM_ENABLED                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 31L)   /* ViBoolean */
#define IVIRFSIGGEN_ATTR_PM_SOURCE                                      (IVI_CLASS_PUBLIC_ATTR_BASE + 32L)   /* ViString */
#define IVIRFSIGGEN_ATTR_PM_EXTERNAL_COUPLING                           (IVI_CLASS_PUBLIC_ATTR_BASE + 33L)   /* ViInt32 */
#define IVIRFSIGGEN_ATTR_PM_NOMINAL_VOLTAGE                             (IVI_CLASS_PUBLIC_ATTR_BASE + 34L)   /* ViReal64 */
#define IVIRFSIGGEN_ATTR_PM_DEVIATION                                   (IVI_CLASS_PUBLIC_ATTR_BASE + 35L)   /* ViReal64 */

        /*- IviRFSigGenAnalogModulationSource Extension Group -*/
#define IVIRFSIGGEN_ATTR_ANALOG_MODULATION_SOURCE_COUNT                 (IVI_CLASS_PUBLIC_ATTR_BASE + 41L)   /* ViInt32 */

        /*- IviRFSigGenModulatePulse Extension Group -*/
#define IVIRFSIGGEN_ATTR_PULSE_MODULATION_ENABLED                       (IVI_CLASS_PUBLIC_ATTR_BASE + 51L)   /* ViBoolean */
#define IVIRFSIGGEN_ATTR_PULSE_MODULATION_SOURCE                        (IVI_CLASS_PUBLIC_ATTR_BASE + 52L)   /* ViInt32 */
#define IVIRFSIGGEN_ATTR_PULSE_MODULATION_EXTERNAL_POLARITY             (IVI_CLASS_PUBLIC_ATTR_BASE + 53L)   /* ViInt32 */

        /*- IviRFSigGenLFGenerator Extension Group -*/
#define IVIRFSIGGEN_ATTR_ACTIVE_LF_GENERATOR                            (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* ViString */
#define IVIRFSIGGEN_ATTR_LF_GENERATOR_COUNT                             (IVI_CLASS_PUBLIC_ATTR_BASE + 104L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_LF_GENERATOR_FREQUENCY                         (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_LF_GENERATOR_WAVEFORM                          (IVI_CLASS_PUBLIC_ATTR_BASE + 103L)  /* ViInt32 */

        /*- IviRFSigGenLFGeneratorOutput Extension Group -*/
#define IVIRFSIGGEN_ATTR_LF_GENERATOR_OUTPUT_AMPLITUDE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 111L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_LF_GENERATOR_OUTPUT_ENABLED                    (IVI_CLASS_PUBLIC_ATTR_BASE + 112L)  /* ViBoolean */

        /*- IviRFSigGenPulseGenerator Extension Group -*/
#define IVIRFSIGGEN_ATTR_PULSE_INTERNAL_TRIGGER_PERIOD                  (IVI_CLASS_PUBLIC_ATTR_BASE + 121L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_PULSE_WIDTH                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 122L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_PULSE_GATING_ENABLED                           (IVI_CLASS_PUBLIC_ATTR_BASE + 123L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_PULSE_TRIGGER_SOURCE                           (IVI_CLASS_PUBLIC_ATTR_BASE + 124L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_PULSE_EXTERNAL_TRIGGER_SLOPE                   (IVI_CLASS_PUBLIC_ATTR_BASE + 125L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_PULSE_EXTERNAL_TRIGGER_DELAY                   (IVI_CLASS_PUBLIC_ATTR_BASE + 126L)  /* ViReal64 */

        /*- IviRFSigGenPulseDoubleGenerator Extension Group -*/
#define IVIRFSIGGEN_ATTR_PULSE_DOUBLE_ENABLED                           (IVI_CLASS_PUBLIC_ATTR_BASE + 131L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_PULSE_DOUBLE_DELAY                             (IVI_CLASS_PUBLIC_ATTR_BASE + 132L)  /* ViReal64 */

        /*- IviRFSigGenPulseGeneratorOutput Extension Group -*/
#define IVIRFSIGGEN_ATTR_PULSE_OUTPUT_POLARITY                          (IVI_CLASS_PUBLIC_ATTR_BASE + 141L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_PULSE_OUTPUT_ENABLED                           (IVI_CLASS_PUBLIC_ATTR_BASE + 142L)  /* ViBoolean */

        /*- IviRFSigGenSweep Extension Group -*/
#define IVIRFSIGGEN_ATTR_SWEEP_MODE                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_SWEEP_TRIGGER_SOURCE                           (IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* ViInt32 */

        /*- IviRFSigGenFrequencySweep Extension Group -*/
#define IVIRFSIGGEN_ATTR_FREQUENCY_SWEEP_START                          (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_SWEEP_STOP                           (IVI_CLASS_PUBLIC_ATTR_BASE + 212L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_SWEEP_TIME                           (IVI_CLASS_PUBLIC_ATTR_BASE + 213L)  /* ViReal64 */

        /*- IviRFSigGenPowerSweep Extension Group -*/
#define IVIRFSIGGEN_ATTR_POWER_SWEEP_START                              (IVI_CLASS_PUBLIC_ATTR_BASE + 221L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_SWEEP_STOP                               (IVI_CLASS_PUBLIC_ATTR_BASE + 222L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_SWEEP_TIME                               (IVI_CLASS_PUBLIC_ATTR_BASE + 223L)  /* ViReal64 */

        /*- IviRFSigGenFrequencyStep Extension Group -*/
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_START                           (IVI_CLASS_PUBLIC_ATTR_BASE + 241L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_STOP                            (IVI_CLASS_PUBLIC_ATTR_BASE + 242L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_SCALING                         (IVI_CLASS_PUBLIC_ATTR_BASE + 243L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_SIZE                            (IVI_CLASS_PUBLIC_ATTR_BASE + 244L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_SINGLE_STEP_ENABLED             (IVI_CLASS_PUBLIC_ATTR_BASE + 245L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_FREQUENCY_STEP_DWELL                           (IVI_CLASS_PUBLIC_ATTR_BASE + 246L)  /* ViReal64 */

        /*- IviRFSigGenPowerStep Extension Group -*/
#define IVIRFSIGGEN_ATTR_POWER_STEP_START                               (IVI_CLASS_PUBLIC_ATTR_BASE + 261L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_STEP_STOP                                (IVI_CLASS_PUBLIC_ATTR_BASE + 262L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_STEP_SIZE                                (IVI_CLASS_PUBLIC_ATTR_BASE + 263L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_POWER_STEP_SINGLE_STEP_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 264L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_POWER_STEP_DWELL                               (IVI_CLASS_PUBLIC_ATTR_BASE + 265L)  /* ViReal64 */

        /*- IviRFSigGenList Extension Group -*/
#define IVIRFSIGGEN_ATTR_LIST_SELECTED_NAME                             (IVI_CLASS_PUBLIC_ATTR_BASE + 281L)  /* ViString */
#define IVIRFSIGGEN_ATTR_LIST_SINGLE_STEP_ENABLED                       (IVI_CLASS_PUBLIC_ATTR_BASE + 282L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_LIST_DWELL                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 283L)  /* ViReal64 */

        /*- IviRFSigGenALC Extension Group -*/
#define IVIRFSIGGEN_ATTR_ALC_SOURCE                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 301L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ALC_BANDWIDTH                                  (IVI_CLASS_PUBLIC_ATTR_BASE + 302L)  /* ViReal64 */

        /*- IviRFSigGenReferenceOscillator Extension Group -*/
#define IVIRFSIGGEN_ATTR_REFERENCE_OSCILLATOR_SOURCE                    (IVI_CLASS_PUBLIC_ATTR_BASE + 321L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_REFERENCE_OSCILLATOR_EXTERNAL_FREQUENCY        (IVI_CLASS_PUBLIC_ATTR_BASE + 322L)  /* ViReal64 */

        /*- IviRFSigGenModulateIQ Extension Group -*/
#define IVIRFSIGGEN_ATTR_IQ_ENABLED                                     (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_IQ_NOMINAL_VOLTAGE                             (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_IQ_SOURCE                                      (IVI_CLASS_PUBLIC_ATTR_BASE + 403L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_IQ_SWAP_ENABLED                                (IVI_CLASS_PUBLIC_ATTR_BASE + 404L)  /* ViBoolean */

        /*- IviRFSigGenIQImpairment Extension Group -*/
#define IVIRFSIGGEN_ATTR_IQ_IMPAIRMENT_ENABLED                          (IVI_CLASS_PUBLIC_ATTR_BASE + 421L)  /* ViBoolean */
#define IVIRFSIGGEN_ATTR_IQ_I_OFFSET                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 422L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_IQ_Q_OFFSET                                    (IVI_CLASS_PUBLIC_ATTR_BASE + 423L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_IQ_RATIO                                       (IVI_CLASS_PUBLIC_ATTR_BASE + 424L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_IQ_SKEW                                        (IVI_CLASS_PUBLIC_ATTR_BASE + 425L)  /* ViReal64 */

        /*- IviRFSigGenArbGenerator Extension Group -*/
#define IVIRFSIGGEN_ATTR_ARB_SELECTED_WAVEFORM                          (IVI_CLASS_PUBLIC_ATTR_BASE + 451L)  /* ViString */
#define IVIRFSIGGEN_ATTR_ARB_CLOCK_FREQUENCY                            (IVI_CLASS_PUBLIC_ATTR_BASE + 452L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_ARB_FILTER_FREQUENCY                           (IVI_CLASS_PUBLIC_ATTR_BASE + 453L)  /* ViReal64 */
#define IVIRFSIGGEN_ATTR_ARB_MAX_NUMBER_WAVEFORMS                       (IVI_CLASS_PUBLIC_ATTR_BASE + 454L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ARB_WAVEFORM_QUANTUM                           (IVI_CLASS_PUBLIC_ATTR_BASE + 455L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ARB_WAVEFORM_SIZE_MIN                          (IVI_CLASS_PUBLIC_ATTR_BASE + 456L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ARB_WAVEFORM_SIZE_MAX                          (IVI_CLASS_PUBLIC_ATTR_BASE + 457L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ARB_TRIGGER_SOURCE                             (IVI_CLASS_PUBLIC_ATTR_BASE + 458L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_ARB_EXTERNAL_TRIGGER_SLOPE                     (IVI_CLASS_PUBLIC_ATTR_BASE + 459L)  /* ViInt32 */

        /*- IviRFSigGenDigitalModulationBase Extension Group -*/
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_STANDARD_COUNT         (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_SELECTED_STANDARD      (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* ViString */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_DATA_SOURCE            (IVI_CLASS_PUBLIC_ATTR_BASE + 503L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_PRBS_TYPE              (IVI_CLASS_PUBLIC_ATTR_BASE + 504L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_SELECTED_BIT_SEQUENCE  (IVI_CLASS_PUBLIC_ATTR_BASE + 505L)  /* ViString */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_CLOCK_SOURCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 506L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE    (IVI_CLASS_PUBLIC_ATTR_BASE + 507L)  /* ViInt32 */

        /*- IviRFSigGenCDMABase Extension Group -*/
#define IVIRFSIGGEN_ATTR_CDMA_STANDARD_COUNT                            (IVI_CLASS_PUBLIC_ATTR_BASE + 601L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_CDMA_SELECTED_STANDARD                         (IVI_CLASS_PUBLIC_ATTR_BASE + 602L)  /* ViString */
#define IVIRFSIGGEN_ATTR_CDMA_TRIGGER_SOURCE                            (IVI_CLASS_PUBLIC_ATTR_BASE + 603L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_CDMA_EXTERNAL_TRIGGER_SLOPE                    (IVI_CLASS_PUBLIC_ATTR_BASE + 604L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_CDMA_TEST_MODEL_COUNT                          (IVI_CLASS_PUBLIC_ATTR_BASE + 605L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_CDMA_SELECTED_TEST_MODEL                       (IVI_CLASS_PUBLIC_ATTR_BASE + 606L)  /* ViString */
#define IVIRFSIGGEN_ATTR_CDMA_CLOCK_SOURCE                              (IVI_CLASS_PUBLIC_ATTR_BASE + 607L)  /* ViInt32 */

        /*- IviRFSigGenTDMABase Extension Group -*/
#define IVIRFSIGGEN_ATTR_TDMA_STANDARD_COUNT                            (IVI_CLASS_PUBLIC_ATTR_BASE + 701L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_TDMA_SELECTED_STANDARD                         (IVI_CLASS_PUBLIC_ATTR_BASE + 702L)  /* ViString */
#define IVIRFSIGGEN_ATTR_TDMA_TRIGGER_SOURCE                            (IVI_CLASS_PUBLIC_ATTR_BASE + 703L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_TDMA_EXTERNAL_TRIGGER_SLOPE                    (IVI_CLASS_PUBLIC_ATTR_BASE + 704L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_TDMA_FRAME_COUNT                               (IVI_CLASS_PUBLIC_ATTR_BASE + 705L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_TDMA_SELECTED_FRAME                            (IVI_CLASS_PUBLIC_ATTR_BASE + 706L)  /* ViString */
#define IVIRFSIGGEN_ATTR_TDMA_CLOCK_SOURCE                              (IVI_CLASS_PUBLIC_ATTR_BASE + 707L)  /* ViInt32 */
#define IVIRFSIGGEN_ATTR_TDMA_EXTERNAL_CLOCK_TYPE                       (IVI_CLASS_PUBLIC_ATTR_BASE + 708L)  /* ViInt32 */


/****************************************************************************
 *----------------- IviRFSigGen Class Attribute Value Defines -----------------*
 ****************************************************************************/
/*- Defined values for attribute IVIRFSIGGEN_ATTR_AM_SCALING -*/
#define IVIRFSIGGEN_VAL_AM_SCALING_LINEAR                                   (0L)
#define IVIRFSIGGEN_VAL_AM_SCALING_LOGARITHMIC                              (1L)
#define IVIRFSIGGEN_VAL_AM_SCALING_CLASS_EXT_BASE                           (500L)
#define IVIRFSIGGEN_VAL_AM_SCALING_SPECIFIC_EXT_BASE                        (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_AM_EXTERNAL_COUPLING -*/
#define IVIRFSIGGEN_VAL_AM_EXTERNAL_COUPLING_AC                             (0L)
#define IVIRFSIGGEN_VAL_AM_EXTERNAL_COUPLING_DC                             (1L)
#define IVIRFSIGGEN_VAL_AM_EXTERNAL_COUPLING_CLASS_EXT_BASE                 (500L)
#define IVIRFSIGGEN_VAL_AM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE              (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_FM_EXTERNAL_COUPLING -*/
#define IVIRFSIGGEN_VAL_FM_EXTERNAL_COUPLING_AC                             (0L)
#define IVIRFSIGGEN_VAL_FM_EXTERNAL_COUPLING_DC                             (1L)
#define IVIRFSIGGEN_VAL_FM_EXTERNAL_COUPLING_CLASS_EXT_BASE                 (500L)
#define IVIRFSIGGEN_VAL_FM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE              (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PM_EXTERNAL_COUPLING -*/
#define IVIRFSIGGEN_VAL_PM_EXTERNAL_COUPLING_AC                             (0L)
#define IVIRFSIGGEN_VAL_PM_EXTERNAL_COUPLING_DC                             (1L)
#define IVIRFSIGGEN_VAL_PM_EXTERNAL_COUPLING_CLASS_EXT_BASE                 (500L)
#define IVIRFSIGGEN_VAL_PM_EXTERNAL_COUPLING_SPECIFIC_EXT_BASE              (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PULSE_MODULATION_SOURCE -*/
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_SOURCE_INTERNAL                    (0L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_SOURCE_EXTERNAL                    (1L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_SOURCE_CLASS_EXT_BASE              (500L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_SOURCE_SPECIFIC_EXT_BASE           (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PULSE_MODULATION_EXTERNAL_POLARITY -*/
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_NORMAL           (0L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_INVERSE          (1L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_CLASS_EXT_BASE   (500L)
#define IVIRFSIGGEN_VAL_PULSE_MODULATION_EXTERNAL_POLARITY_SPECIFIC_EXT_BASE  (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_LF_GENERATOR_WAVEFORM -*/
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_SINE                          (0L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_SQUARE                        (1L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_TRIANGLE                      (2L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_RAMP_UP                       (3L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_RAMP_DOWN                     (4L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_CLASS_EXT_BASE       (500L)
#define IVIRFSIGGEN_VAL_LF_GENERATOR_WAVEFORM_SPECIFIC_EXT_BASE    (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PULSE_TRIGGER_SOURCE -*/
#define IVIRFSIGGEN_VAL_PULSE_TRIGGER_SOURCE_INTERNAL                       (0L)
#define IVIRFSIGGEN_VAL_PULSE_TRIGGER_SOURCE_EXTERNAL                       (1L)
#define IVIRFSIGGEN_VAL_PULSE_TRIGGER_SOURCE_CLASS_EXT_BASE                 (500L)
#define IVIRFSIGGEN_VAL_PULSE_TRIGGER_SOURCE_SPECIFIC_EXT_BASE              (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PULSE_EXTERNAL_TRIGGER_SLOPE -*/
#define IVIRFSIGGEN_VAL_PULSE_EXTERNAL_TRIGGER_SLOPE_POSITIVE               (0L)
#define IVIRFSIGGEN_VAL_PULSE_EXTERNAL_TRIGGER_SLOPE_NEGATIVE               (1L)
#define IVIRFSIGGEN_VAL_PULSE_EXTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE         (500L)
#define IVIRFSIGGEN_VAL_PULSE_EXTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE      (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_PULSE_OUTPUT_POLARITY -*/
#define IVIRFSIGGEN_VAL_PULSE_OUTPUT_POLARITY_NORMAL                        (0L)
#define IVIRFSIGGEN_VAL_PULSE_OUTPUT_POLARITY_INVERSE                       (1L)
#define IVIRFSIGGEN_VAL_PULSE_OUTPUT_POLARITY_CLASS_EXT_BASE                (500L)
#define IVIRFSIGGEN_VAL_PULSE_OUTPUT_POLARITY_SPECIFIC_EXT_BASE             (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_SWEEP_MODE -*/
#define IVIRFSIGGEN_VAL_SWEEP_MODE_NONE                                     (0L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_FREQUENCY_SWEEP                          (1L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_POWER_SWEEP                              (2L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_FREQUENCY_STEP                           (3L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_POWER_STEP                               (4L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_LIST                                     (5L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_CLASS_EXT_BASE                           (500L)
#define IVIRFSIGGEN_VAL_SWEEP_MODE_SPECIFIC_EXT_BASE                        (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_SWEEP_TRIGGER_SOURCE -*/
#define IVIRFSIGGEN_VAL_SWEEP_TRIGGER_SOURCE_IMMEDIATE                      (0L)
#define IVIRFSIGGEN_VAL_SWEEP_TRIGGER_SOURCE_EXTERNAL                       (1L)
#define IVIRFSIGGEN_VAL_SWEEP_TRIGGER_SOURCE_SOFTWARE                       (2L)
#define IVIRFSIGGEN_VAL_SWEEP_TRIGGER_SOURCE_CLASS_EXT_BASE                 (500L)
#define IVIRFSIGGEN_VAL_SWEEP_TRIGGER_SOURCE_SPECIFIC_EXT_BASE              (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_FREQUENCY_STEP_SCALING -*/
#define IVIRFSIGGEN_VAL_FREQUENCY_STEP_SCALING_LINEAR                       (0L)
#define IVIRFSIGGEN_VAL_FREQUENCY_STEP_SCALING_LOGARITHMIC                  (1L)
#define IVIRFSIGGEN_VAL_FREQUENCY_STEP_SCALING_CLASS_EXT_BASE               (500L)
#define IVIRFSIGGEN_VAL_FREQUENCY_STEP_SCALING_SPECIFIC_EXT_BASE            (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_ALC_SOURCE -*/
#define IVIRFSIGGEN_VAL_ALC_SOURCE_INTERNAL                                 (0L)
#define IVIRFSIGGEN_VAL_ALC_SOURCE_EXTERNAL                                 (1L)
#define IVIRFSIGGEN_VAL_ALC_SOURCE_CLASS_EXT_BASE                           (500L)
#define IVIRFSIGGEN_VAL_ALC_SOURCE_SPECIFIC_EXT_BASE                        (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_REFERENCE_OSCILLATOR_SOURCE -*/
#define IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL                (0L)
#define IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL                (1L)
#define IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_CLASS_EXT_BASE          (500L)
#define IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_SPECIFIC_EXT_BASE       (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_IQ_SOURCE -*/
#define IVIRFSIGGEN_VAL_IQ_SOURCE_DIGITAL_MODULATION_BASE                   (0L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_CDMA_BASE                                 (1L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_TDMA_BASE                                 (2L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_ARB_GENERATOR                             (3L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_EXTERNAL                                  (4L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_CLASS_EXT_BASE                            (500L)
#define IVIRFSIGGEN_VAL_IQ_SOURCE_SPECIFIC_EXT_BASE                         (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_ARB_TRIGGER_SOURCE -*/
#define IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_IMMEDIATE                        (0L)
#define IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_EXTERNAL                         (1L)
#define IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_SOFTWARE                         (2L)
#define IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_CLASS_EXT_BASE                   (500L)
#define IVIRFSIGGEN_VAL_ARB_TRIGGER_SOURCE_SPECIFIC_EXT_BASE                (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_ARB_EXTERNAL_TRIGGER_SLOPE -*/
#define IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_POSITIVE                 (0L)
#define IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_NEGATIVE                 (1L)
#define IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE           (500L)
#define IVIRFSIGGEN_VAL_ARB_EXTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE        (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_DATA_SOURCE -*/
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_DATA_SOURCE_EXTERNAL        (0L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_DATA_SOURCE_PRBS            (1L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_DATA_SOURCE_BIT_SEQUENCE    (2L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_DATA_SOURCE_CLASS_EXT_BASE  (500L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_DATA_SOURCE_SPECIFIC_EXT_BASE  (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_PRBS_TYPE -*/
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS9             (0L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS11            (1L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS15            (2L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS16            (3L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS20            (4L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS21            (5L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_PRBS23            (6L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_CLASS_EXT_BASE    (500L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_PRBS_TYPE_SPECIFIC_EXT_BASE  (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_CLOCK_SOURCE -*/
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_CLOCK_SOURCE_INTERNAL       (0L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_CLOCK_SOURCE_EXTERNAL       (1L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_CLOCK_SOURCE_CLASS_EXT_BASE  (500L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_CLOCK_SOURCE_SPECIFIC_EXT_BASE  (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE -*/
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE_BIT     (0L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE_SYMBOL  (1L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE_CLASS_EXT_BASE  (500L)
#define IVIRFSIGGEN_VAL_DIGITAL_MODULATION_BASE_EXTERNAL_CLOCK_TYPE_SPECIFIC_EXT_BASE  (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_CDMA_TRIGGER_SOURCE -*/
#define IVIRFSIGGEN_VAL_CDMA_TRIGGER_SOURCE_IMMEDIATE                       (0L)
#define IVIRFSIGGEN_VAL_CDMA_TRIGGER_SOURCE_EXTERNAL                        (1L)
#define IVIRFSIGGEN_VAL_CDMA_TRIGGER_SOURCE_SOFTWARE                        (2L)
#define IVIRFSIGGEN_VAL_CDMA_TRIGGER_SOURCE_CLASS_EXT_BASE                  (500L)
#define IVIRFSIGGEN_VAL_CDMA_TRIGGER_SOURCE_SPECIFIC_EXT_BASE               (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_CDMA_EXTERNAL_TRIGGER_SLOPE -*/
#define IVIRFSIGGEN_VAL_CDMA_EXTERNAL_TRIGGER_SLOPE_POSITIVE                (0L)
#define IVIRFSIGGEN_VAL_CDMA_EXTERNAL_TRIGGER_SLOPE_NEGATIVE                (1L)
#define IVIRFSIGGEN_VAL_CDMA_EXTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE          (500L)
#define IVIRFSIGGEN_VAL_CDMA_EXTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE       (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_CDMA_CLOCK_SOURCE -*/
#define IVIRFSIGGEN_VAL_CDMA_CLOCK_SOURCE_INTERNAL                          (0L)
#define IVIRFSIGGEN_VAL_CDMA_CLOCK_SOURCE_EXTERNAL                          (1L)
#define IVIRFSIGGEN_VAL_CDMA_CLOCK_SOURCE_CLASS_EXT_BASE                    (500L)
#define IVIRFSIGGEN_VAL_CDMA_CLOCK_SOURCE_SPECIFIC_EXT_BASE                 (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_TDMA_TRIGGER_SOURCE -*/
#define IVIRFSIGGEN_VAL_TDMA_TRIGGER_SOURCE_IMMEDIATE                       (0L)
#define IVIRFSIGGEN_VAL_TDMA_TRIGGER_SOURCE_EXTERNAL                        (1L)
#define IVIRFSIGGEN_VAL_TDMA_TRIGGER_SOURCE_SOFTWARE                        (2L)
#define IVIRFSIGGEN_VAL_TDMA_TRIGGER_SOURCE_CLASS_EXT_BASE                  (500L)
#define IVIRFSIGGEN_VAL_TDMA_TRIGGER_SOURCE_SPECIFIC_EXT_BASE               (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_TDMA_EXTERNAL_TRIGGER_SLOPE -*/
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_TRIGGER_SLOPE_POSITIVE                (0L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_TRIGGER_SLOPE_NEGATIVE                (1L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_TRIGGER_SLOPE_CLASS_EXT_BASE          (500L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_TRIGGER_SLOPE_SPECIFIC_EXT_BASE       (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_TDMA_CLOCK_SOURCE -*/
#define IVIRFSIGGEN_VAL_TDMA_CLOCK_SOURCE_INTERNAL                          (0L)
#define IVIRFSIGGEN_VAL_TDMA_CLOCK_SOURCE_EXTERNAL                          (1L)
#define IVIRFSIGGEN_VAL_TDMA_CLOCK_SOURCE_CLASS_EXT_BASE                    (500L)
#define IVIRFSIGGEN_VAL_TDMA_CLOCK_SOURCE_SPECIFIC_EXT_BASE                 (1000L)

/*- Defined values for attribute IVIRFSIGGEN_ATTR_TDMA_EXTERNAL_CLOCK_TYPE -*/
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_CLOCK_TYPE_BIT                        (0L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_CLOCK_TYPE_SYMBOL                     (1L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_CLOCK_TYPE_CLASS_EXT_BASE             (500L)
#define IVIRFSIGGEN_VAL_TDMA_EXTERNAL_CLOCK_TYPE_SPECIFIC_EXT_BASE          (1000L)



/****************************************************************************
 *--------- IviRFSigGen Class Instrument Driver Function Declarations ---------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviRFSigGen_init (ViRsrc logicalName, 
                                 ViBoolean idQuery, 
                                 ViBoolean resetDevice, 
                                 ViSession *vi);

ViStatus _VI_FUNC IviRFSigGen_close (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_reset (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_self_test (ViSession vi, 
                                      ViInt16 *selfTestResult, 
                                      ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviRFSigGen_error_query (ViSession vi, 
                                        ViInt32 *errorCode, 
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC IviRFSigGen_error_message (ViSession vi, 
                                          ViStatus statusCode, 
                                          ViChar message[]);

ViStatus _VI_FUNC IviRFSigGen_revision_query (ViSession vi, 
                                           ViChar driverRev[], 
                                           ViChar instrRev[]);
    /*- Utility Functions -*/
ViStatus _VI_FUNC IviRFSigGen_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_Disable (ViSession vi);

    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviRFSigGen_InitWithOptions (ViRsrc logicalName, 
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice, 
                                            ViConstString optionString, 
                                            ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/

ViStatus _VI_FUNC IviRFSigGen_GetAttributeViInt32 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt32 *value);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViInt32 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt32 value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViInt32 (ViSession vi, 
                                                  ViConstString repeatedCapName,
                                                  ViAttr attributeId,
                                                  ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviRFSigGen_GetAttributeViInt64 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt64 *value);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViInt64 (ViSession vi, 
                                                ViConstString repeatedCapName,
                                                ViAttr attributeId,
                                                ViInt64 value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViInt64 (ViSession vi, 
                                                  ViConstString repeatedCapName,
                                                  ViAttr attributeId,
                                                  ViInt64 value);
#endif

ViStatus _VI_FUNC IviRFSigGen_GetAttributeViReal64 (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 *value);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViReal64 (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViReal64 value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViReal64 (ViSession vi, 
                                                   ViConstString repeatedCapName, 
                                                   ViAttr attributeId, 
                                                   ViReal64 value);

ViStatus _VI_FUNC IviRFSigGen_GetAttributeViString (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViInt32 bufferSize, 
                                                 ViChar value[]);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViString (ViSession vi, 
                                                 ViConstString repeatedCapName, 
                                                 ViAttr attributeId, 
                                                 ViConstString value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViString (ViSession vi, 
                                                   ViConstString repeatedCapName, 
                                                   ViAttr attributeId, 
                                                   ViConstString value); 

ViStatus _VI_FUNC IviRFSigGen_GetAttributeViBoolean (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean *value);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViBoolean (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViBoolean value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViBoolean (ViSession vi, 
                                                    ViConstString repeatedCapName, 
                                                    ViAttr attributeId, 
                                                    ViBoolean value);

ViStatus _VI_FUNC IviRFSigGen_GetAttributeViSession (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViSession *value);

ViStatus _VI_FUNC IviRFSigGen_SetAttributeViSession (ViSession vi, 
                                                  ViConstString repeatedCapName, 
                                                  ViAttr attributeId, 
                                                  ViSession value);

ViStatus _VI_FUNC IviRFSigGen_CheckAttributeViSession (ViSession vi, 
                                                    ViConstString repeatedCapName, 
                                                    ViAttr attributeId, 
                                                    ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviRFSigGen_LockSession (ViSession vi, 
                                        ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviRFSigGen_UnlockSession (ViSession vi, 
                                          ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviRFSigGen_GetError (ViSession vi, 
                                   ViStatus *errorCode, 
                                   ViInt32 bufferSize, 
                                   ViChar description[]);

ViStatus _VI_FUNC IviRFSigGen_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviRFSigGen_GetNextInterchangeWarning (ViSession vi, 
                                                      ViInt32 bufferSize,
                                                      ViChar warning[]);

ViStatus _VI_FUNC IviRFSigGen_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviRFSigGen_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize, 
                                                  ViChar record[]);

ViStatus _VI_FUNC IviRFSigGen_GetSpecificDriverCHandle (ViSession vi,
                                                     ViSession* specificDriverCHandle);

    /*- IviRFSigGen Fundamental Capabilities -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureRF (ViSession vi,
                                           ViReal64 Frequency,
                                           ViReal64 PowerLevel);

ViStatus _VI_FUNC IviRFSigGen_ConfigureALCEnabled (ViSession vi,
                                                   ViBoolean ALCEnabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigureOutputEnabled (ViSession vi,
                                                      ViBoolean OutputEnabled);

ViStatus _VI_FUNC IviRFSigGen_DisableAllModulation (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_IsSettled (ViSession vi,
                                         ViBoolean* Done);

ViStatus _VI_FUNC IviRFSigGen_WaitUntilSettled (ViSession vi,
                                                ViInt32 MaxTimeMilliseconds);


    /*- IviRFSigGenModulateAM Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureAMEnabled (ViSession vi,
                                                  ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigureAMExternalCoupling (ViSession vi,
                                                           ViInt32 Coupling);

ViStatus _VI_FUNC IviRFSigGen_ConfigureAM (ViSession vi,
                                           ViConstString Source,
                                           ViInt32 Scaling,
                                           ViReal64 Depth);


    /*- IviRFSigGenModulateFM Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureFMEnabled (ViSession vi,
                                                  ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigureFMExternalCoupling (ViSession vi,
                                                           ViInt32 Coupling);

ViStatus _VI_FUNC IviRFSigGen_ConfigureFM (ViSession vi,
                                           ViConstString Source,
                                           ViReal64 Deviation);


    /*- IviRFSigGenModulatePM Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePMEnabled (ViSession vi,
                                                  ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePMExternalCoupling (ViSession vi,
                                                           ViInt32 Coupling);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePM (ViSession vi,
                                           ViConstString Source,
                                           ViReal64 Deviation);


    /*- IviRFSigGenAnalogModulationSource Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_GetAnalogModulationSourceName (ViSession vi,
                                                             ViInt32 Index,
                                                             ViInt32 NameBufferSize,
                                                             ViChar Name[]);


    /*- IviRFSigGenModulatePulse Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseModulationEnabled (ViSession vi,
                                                               ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseModulationSource (ViSession vi,
                                                              ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseModulationExternalPolarity (ViSession vi,
                                                                        ViInt32 Polarity);


    /*- IviRFSigGenLFGenerator Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_GetLFGeneratorName (ViSession vi,
                                                  ViInt32 Index,
                                                  ViInt32 NameBufferSize,
                                                  ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SetActiveLFGenerator (ViSession vi,
                                                    ViConstString ActiveLFGenerator);

ViStatus _VI_FUNC IviRFSigGen_ConfigureLFGenerator (ViSession vi,
                                                    ViReal64 Frequency,
                                                    ViInt32 Waveform);


    /*- IviRFSigGenLFGeneratorOutput Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureLFGeneratorOutput (ViSession vi,
                                                          ViReal64 Amplitude,
                                                          ViBoolean Enabled);


    /*- IviRFSigGenPulseGenerator Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseExternalTrigger (ViSession vi,
                                                             ViInt32 Slope,
                                                             ViReal64 Delay);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseInternalTrigger (ViSession vi,
                                                             ViReal64 Period);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePulse (ViSession vi,
                                              ViInt32 PulseTriggerSource,
                                              ViReal64 PulseWidth,
                                              ViBoolean GatingEnabled);


    /*- IviRFSigGenPulseDoubleGenerator Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseDouble (ViSession vi,
                                                    ViBoolean Enabled,
                                                    ViReal64 Delay);


    /*- IviRFSigGenPulseGeneratorOutput Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePulseOutput (ViSession vi,
                                                    ViInt32 Polarity,
                                                    ViBoolean Enabled);


    /*- IviRFSigGenSweep Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureSweep (ViSession vi,
                                              ViInt32 Mode,
                                              ViInt32 TriggerSource);


    /*- IviRFSigGenFrequencySweep Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureFrequencySweepStartStop (ViSession vi,
                                                                ViReal64 Start,
                                                                ViReal64 Stop);

ViStatus _VI_FUNC IviRFSigGen_ConfigureFrequencySweepCenterSpan (ViSession vi,
                                                                 ViReal64 Center,
                                                                 ViReal64 Span);

ViStatus _VI_FUNC IviRFSigGen_ConfigureFrequencySweepTime (ViSession vi,
                                                           ViReal64 Time);


    /*- IviRFSigGenPowerSweep Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePowerSweepStartStop (ViSession vi,
                                                            ViReal64 Start,
                                                            ViReal64 Stop);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePowerSweepTime (ViSession vi,
                                                       ViReal64 Time);


    /*- IviRFSigGenFrequencyStep Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureFrequencyStepStartStop (ViSession vi,
                                                               ViReal64 Start,
                                                               ViReal64 Stop,
                                                               ViInt32 Scaling,
                                                               ViReal64 StepSize);

ViStatus _VI_FUNC IviRFSigGen_ConfigureFrequencyStepDwell (ViSession vi,
                                                           ViBoolean SingleStepEnabled,
                                                           ViReal64 Dwell);

ViStatus _VI_FUNC IviRFSigGen_ResetFrequencyStep (ViSession vi);


    /*- IviRFSigGenPowerStep Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigurePowerStepStartStop (ViSession vi,
                                                           ViReal64 Start,
                                                           ViReal64 Stop,
                                                           ViReal64 StepSize);

ViStatus _VI_FUNC IviRFSigGen_ConfigurePowerStepDwell (ViSession vi,
                                                       ViBoolean SingleStepEnabled,
                                                       ViReal64 Dwell);

ViStatus _VI_FUNC IviRFSigGen_ResetPowerStep (ViSession vi);


    /*- IviRFSigGenList Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_CreateFrequencyList (ViSession vi,
                                                   ViConstString Name,
                                                   ViInt32 Length,
                                                   ViReal64 Frequency[]);

ViStatus _VI_FUNC IviRFSigGen_CreatePowerList (ViSession vi,
                                               ViConstString Name,
                                               ViInt32 Length,
                                               ViReal64 Power[]);

ViStatus _VI_FUNC IviRFSigGen_CreateFrequencyPowerList (ViSession vi,
                                                        ViConstString Name,
                                                        ViInt32 Length,
                                                        ViReal64 Frequency[],
                                                        ViReal64 Power[]);

ViStatus _VI_FUNC IviRFSigGen_SelectList (ViSession vi,
                                          ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ClearAllLists (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_ConfigureListDwell (ViSession vi,
                                                  ViBoolean SingleStepEnabled,
                                                  ViReal64 Dwell);

ViStatus _VI_FUNC IviRFSigGen_ResetList (ViSession vi);


    /*- IviRFSigGenALC Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureALC (ViSession vi,
                                            ViInt32 Source,
                                            ViReal64 Bandwidth);


    /*- IviRFSigGenReferenceOscillator Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureReferenceOscillator (ViSession vi,
                                                            ViInt32 Source,
                                                            ViReal64 Frequency);


    /*- IviRFSigGenSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_SendSoftwareTrigger (ViSession vi);


    /*- IviRFSigGenModulateIQ Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureIQEnabled (ViSession vi,
                                                  ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigureIQ (ViSession vi,
                                           ViInt32 Source,
                                           ViBoolean SwapEnabled);

ViStatus _VI_FUNC IviRFSigGen_CalibrateIQ (ViSession vi);


    /*- IviRFSigGenIQImpairment Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureIQImpairmentEnabled (ViSession vi,
                                                            ViBoolean Enabled);

ViStatus _VI_FUNC IviRFSigGen_ConfigureIQImpairment (ViSession vi,
                                                     ViReal64 IOffset,
                                                     ViReal64 QOffset,
                                                     ViReal64 Ratio,
                                                     ViReal64 Skew);


    /*- IviRFSigGenArbGenerator Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_ConfigureArb (ViSession vi,
                                            ViReal64 ClockFrequency,
                                            ViReal64 FilterFrequency);

ViStatus _VI_FUNC IviRFSigGen_WriteArbWaveform (ViSession vi,
                                                ViConstString Name,
                                                ViInt32 NumberOfSamples,
                                                ViReal64 IData[],
                                                ViReal64 QData[],
                                                ViBoolean MoreDataPending);

ViStatus _VI_FUNC IviRFSigGen_SelectArbWaveform (ViSession vi,
                                                 ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ClearAllArbWaveforms (ViSession vi);

ViStatus _VI_FUNC IviRFSigGen_QueryArbWaveformCapabilities (ViSession vi,
                                                            ViInt32* MaxNumberWaveforms,
                                                            ViInt32* WaveformQuantum,
                                                            ViInt32* MinWaveformSize,
                                                            ViInt32* MaxWaveformSize);

ViStatus _VI_FUNC IviRFSigGen_ConfigureArbTriggerSource (ViSession vi,
                                                         ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigureArbExternalTriggerSlope (ViSession vi,
                                                                ViInt32 Slope);


    /*- IviRFSigGenDigitalModulationBase Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_GetDigitalModulationBaseStandardName (ViSession vi,
                                                                    ViInt32 Index,
                                                                    ViInt32 NameBufferSize,
                                                                    ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SelectDigitalModulationBaseStandard (ViSession vi,
                                                                   ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ConfigureDigitalModulationBaseClockSource (ViSession vi,
                                                                         ViInt32 Source,
                                                                         ViInt32 Type);

ViStatus _VI_FUNC IviRFSigGen_ConfigureDigitalModulationBaseDataSource (ViSession vi,
                                                                        ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigureDigitalModulationBasePRBSType (ViSession vi,
                                                                      ViInt32 Type);

ViStatus _VI_FUNC IviRFSigGen_WriteDigitalModulationBaseBitSequence (ViSession vi,
                                                                     ViConstString Name,
                                                                     ViInt32 BitCount,
                                                                     ViChar Sequence[],
                                                                     ViBoolean MoreDataPending);

ViStatus _VI_FUNC IviRFSigGen_SelectDigitalModulationBaseBitSequence (ViSession vi,
                                                                      ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ClearAllDigitalModulationBaseBitSequences (ViSession vi);


    /*- IviRFSigGenCDMABase Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_GetCDMAStandardName (ViSession vi,
                                                   ViInt32 Index,
                                                   ViInt32 NameBufferSize,
                                                   ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SelectCDMAStandard (ViSession vi,
                                                  ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ConfigureCDMAClockSource (ViSession vi,
                                                        ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigureCDMATriggerSource (ViSession vi,
                                                          ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigureCDMAExternalTriggerSlope (ViSession vi,
                                                                 ViInt32 Slope);

ViStatus _VI_FUNC IviRFSigGen_GetCDMATestModelName (ViSession vi,
                                                    ViInt32 Index,
                                                    ViInt32 NameBufferSize,
                                                    ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SelectCDMATestModel (ViSession vi,
                                                   ViConstString Name);


    /*- IviRFSigGenTDMABase Extension Group -*/
ViStatus _VI_FUNC IviRFSigGen_GetTDMAStandardName (ViSession vi,
                                                   ViInt32 Index,
                                                   ViInt32 NameBufferSize,
                                                   ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SelectTDMAStandard (ViSession vi,
                                                  ViConstString Name);

ViStatus _VI_FUNC IviRFSigGen_ConfigureTDMAClockSource (ViSession vi,
                                                        ViInt32 Source,
                                                        ViInt32 Type);

ViStatus _VI_FUNC IviRFSigGen_ConfigureTDMATriggerSource (ViSession vi,
                                                               ViInt32 Source);

ViStatus _VI_FUNC IviRFSigGen_ConfigureTDMAExternalTriggerSlope (ViSession vi,
                                                                 ViInt32 Slope);

ViStatus _VI_FUNC IviRFSigGen_GetTDMAFrameName (ViSession vi,
                                                ViInt32 Index,
                                                ViInt32 NameBufferSize,
                                                ViChar Name[]);

ViStatus _VI_FUNC IviRFSigGen_SelectTDMAFrame (ViSession vi,
                                               ViConstString Name);



/****************************************************************************
 *--------------- IviRFSigGen Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVIRFSIGGEN_ERROR_TRIGGER_NOT_SOFTWARE   (IVI_CROSS_CLASS_ERROR_BASE + 0x0001L)
#define IVIRFSIGGEN_ERROR_MAX_TIME_EXCEEDED      (IVI_CLASS_ERROR_BASE + 0x0003L)
#define IVIRFSIGGEN_ERROR_LIST_UNKNOWN            (IVI_CLASS_ERROR_BASE + 0x000AL)



#define IVIRFSIGGEN_ERRMSG_TRIGGER_NOT_SOFTWARE  "The trigger source is not set to software trigger."
#define IVIRFSIGGEN_ERRMSG_MAX_TIME_EXCEEDED     "Maximum time exceeded before the operation completed."
#define IVIRFSIGGEN_ERRMSG_LIST_UNKNOWN           "The selected list is not defined."



#define IVIRFSIGGEN_ERROR_CODES_AND_MSGS \
    {IVIRFSIGGEN_ERROR_TRIGGER_NOT_SOFTWARE, IVIRFSIGGEN_ERRMSG_TRIGGER_NOT_SOFTWARE},\
    {IVIRFSIGGEN_ERROR_MAX_TIME_EXCEEDED,    IVIRFSIGGEN_ERRMSG_MAX_TIME_EXCEEDED},\
    {IVIRFSIGGEN_ERROR_LIST_UNKNOWN,          IVIRFSIGGEN_ERRMSG_LIST_UNKNOWN}


/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVIRFSIGGEN_HEADER */
