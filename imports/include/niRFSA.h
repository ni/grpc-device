/****************************************************************************
 *                           NI RF Signal Analyzer
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2006-2020.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niRFSA.h
 * Purpose:  NI RF Signal Analyzer
 *           Instrument Driver declarations.
 *
 ****************************************************************************/
#ifndef ___niRFSA_niRFSA_h___
#define ___niRFSA_niRFSA_h___

#include <ivi.h>
#include "niRFSAErrors.h"

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

// Bitness check for Supported Platforms
#if ((defined(_WIN32) || defined(WIN32)) && !defined(_WIN64))
   #define kRFSA_32BitPlatform 1
#elif defined(_WIN64) || (defined(__linux__) && defined(__x86_64__))
   #define kRFSA_64BitPlatform 1
#else
   #error "Unknown platform"
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*- IVI Inherent Attributes --------------------------------------------*/

/*- User Options */
#define NIRFSA_ATTR_CACHE                                  /* ViBoolean */  IVI_ATTR_CACHE
#define NIRFSA_ATTR_RANGE_CHECK                            /* ViBoolean */  IVI_ATTR_RANGE_CHECK
#define NIRFSA_ATTR_QUERY_INSTRUMENT_STATUS                /* ViBoolean */  IVI_ATTR_QUERY_INSTRUMENT_STATUS
#define NIRFSA_ATTR_RECORD_COERCIONS                       /* ViBoolean */  IVI_ATTR_RECORD_COERCIONS
#define NIRFSA_ATTR_SIMULATE                               /* ViBoolean */  IVI_ATTR_SIMULATE
#define NIRFSA_ATTR_INTERCHANGE_CHECK                      /* ViBoolean */  IVI_ATTR_INTERCHANGE_CHECK

/*- Instrument Capabilities --------------------------------------------*/

/*- Specific Driver Information, Read-only -----------------------------*/
#define NIRFSA_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NIRFSA_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_PREFIX
#define NIRFSA_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_VENDOR
#define NIRFSA_ATTR_SPECIFIC_DRIVER_REVISION                  /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_REVISION
#define NIRFSA_ATTR_SUPPORTED_INSTRUMENT_MODELS               /* ViString */  IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS
#define NIRFSA_ATTR_CHANNEL_COUNT                             /* ViInt32  */  IVI_ATTR_CHANNEL_COUNT
#define NIRFSA_ATTR_INSTRUMENT_MANUFACTURER                   /* ViString */  IVI_ATTR_INSTRUMENT_MANUFACTURER
#define NIRFSA_ATTR_INSTRUMENT_MODEL                          /* ViString */  IVI_ATTR_INSTRUMENT_MODEL
#define NIRFSA_ATTR_INSTRUMENT_FIRMWARE_REVISION              /* ViString */  IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION
#define NIRFSA_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32  */  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
#define NIRFSA_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32  */  IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
#define NIRFSA_ATTR_GROUP_CAPABILITIES                        /* ViString */  IVI_ATTR_GROUP_CAPABILITIES

/*- Instrument Information -*/
#define NIRFSA_ATTR_MEMORY_SIZE                               /* ViInt64  */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)

/*- Advanced Session Information, read-only ----------------------------*/
#define NIRFSA_ATTR_IO_RESOURCE_DESCRIPTOR                 /* ViString */  IVI_ATTR_RESOURCE_DESCRIPTOR
#define NIRFSA_ATTR_LOGICAL_NAME                           /* ViString */  IVI_ATTR_LOGICAL_NAME
#define NIRFSA_ATTR_DRIVER_SETUP                           /* ViString */  IVI_ATTR_DRIVER_SETUP

/*- Instrument-Specific Attributes -------------------------------------*/

/*- Acquisition Type ---------------------------------------------------*/
#define NIRFSA_ATTR_ACQUISITION_TYPE                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)

/*- Vertical -----------------------------------------------------------*/
#define NIRFSA_ATTR_REFERENCE_LEVEL                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)
#define NIRFSA_ATTR_REFERENCE_LEVEL_HEADROOM               /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 309L)
#define NIRFSA_ATTR_ATTENUATION                            /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)
#define NIRFSA_ATTR_MIXER_LEVEL                            /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)
#define NIRFSA_ATTR_MIXER_LEVEL_OFFSET                     /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 127L)
#define NIRFSA_ATTR_MECHANICAL_ATTENUATION                 /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)
#define NIRFSA_ATTR_RF_PREAMP_ENABLED                      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L)
#define NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL                  /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 130L)
#define NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL_OFFSET           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 131L)
#define NIRFSA_ATTR_RF_ATTENUATION_STEP_SIZE               /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 155L)
#define NIRFSA_ATTR_DEVICE_CONFIGURATION_TEMPERATURE       /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 159L)

#define NIRFSA_ATTR_IF_ATTENUATION                         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)
#define NIRFSA_ATTR_RF_ATTENUATION_INDEX                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)
#define NIRFSA_ATTR_RF_ATTENUATION_TABLE                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)
#define NIRFSA_ATTR_IF1_ATTEN_VALUE                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)
#define NIRFSA_ATTR_IF2_ATTEN_VALUE                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)
#define NIRFSA_ATTR_MINIMUM_ACPR                           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 142L)
#define NIRFSA_ATTR_OSP_DATA_SCALING_FACTOR                /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 151L)
#define NIRFSA_ATTR_OVERFLOW_ERROR_REPORTING               /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271L)
#define NIRFSA_ATTR_STEP_GAIN_ENABLED                      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 157L)
#define NIRFSA_ATTR_AMPLITUDE_SETTLING                     /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 163L)
#define NIRFSA_ATTR_DIGITAL_GAIN                           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 301L)

/*- Signal Path Control (Advanced) --------------------------------------*/
#define NIRFSA_ATTR_CHANNEL_COUPLING                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 149L)
#define NIRFSA_ATTR_DOWNCONVERTER_PRESELECTOR_ENABLED      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 132L)
#define NIRFSA_ATTR_INPUT_ISOLATION_ENABLED                /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 170L)
#define NIRFSA_ATTR_RF_PRESELECTOR_FILTER                  /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 166L)
#define NIRFSA_ATTR_LOW_FREQUENCY_BYPASS_ENABLED           /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 207L)
#define NIRFSA_ATTR_NOTCH_FILTER_ENABLED                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 167L)
#define NIRFSA_ATTR_SIGNAL_CONDITIONING_ENABLED            /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 160L)
#define NIRFSA_ATTR_IF_CONDITIONING_DOWN_CONVERSION_ENABLED/* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 161L)
#define NIRFSA_ATTR_IF_FILTER_BANDWIDTH                    /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 205L)
#define NIRFSA_ATTR_FIXED_GROUP_DELAY_ACROSS_PORTS         /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 324L)
#define NIRFSA_ATTR_SELECTED_PORTS                         /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 297L)
#define NIRFSA_ATTR_AVAILABLE_PORTS                        /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 306L)

/*- IQ Acquisition -----------------------------------------------------*/
#define NIRFSA_ATTR_IQ_CARRIER_FREQUENCY                   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 59L)
#define NIRFSA_ATTR_IQ_RATE                                /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)
#define NIRFSA_ATTR_NUMBER_OF_SAMPLES_IS_FINITE            /* ViBoolean   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)
#define NIRFSA_ATTR_NUMBER_OF_SAMPLES                      /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)
#define NIRFSA_ATTR_NUMBER_OF_RECORDS_IS_FINITE            /* ViBoolean   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)
#define NIRFSA_ATTR_NUMBER_OF_RECORDS                      /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 11L)
#define NIRFSA_ATTR_ALLOW_MORE_RECORDS_THAN_MEMORY         /* ViBoolean   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 154L)

/*- Spectrum Acquisition -----------------------------------------------*/
#define NIRFSA_ATTR_CENTER_FREQUENCY                       /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)
#define NIRFSA_ATTR_SPECTRUM_SPAN                          /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)
#define NIRFSA_ATTR_IF_OUTPUT_FREQUENCY                    /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86L)
#define NIRFSA_ATTR_POWER_SPECTRUM_UNITS                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)
#define NIRFSA_ATTR_RESOLUTION_BANDWIDTH                   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)
#define NIRFSA_ATTR_RESOLUTION_BANDWIDTH_TYPE              /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)
#define NIRFSA_ATTR_SPECTRUM_NUMBER_OF_AVERAGES            /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)
#define NIRFSA_ATTR_SPECTRUM_AVERAGING_MODE                /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)
#define NIRFSA_ATTR_FFT_WINDOW_TYPE                        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 17L)
#define NIRFSA_ATTR_NUMBER_OF_SPECTRAL_LINES               /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)
#define NIRFSA_ATTR_SPECTRUM_OSP_SAMPLING_RATIO            /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 144L)
#define NIRFSA_ATTR_FFT_WIDTH                              /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 169L)
#define NIRFSA_ATTR_SMOOTH_SPECTRUM_ENABLED                /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 219L)

/*- Clocking -----------------------------------------------------------*/
#define NIRFSA_ATTR_REF_CLOCK_SOURCE                       /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)
#define NIRFSA_ATTR_REF_CLOCK_RATE                         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)
#define NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)
#define NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_RATE   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)
#define NIRFSA_ATTR_PXI_CHASSIS_CLK10_SOURCE               /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)
#define NIRFSA_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL     /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)
#define NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_RATE                      /* ViReal64 */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 228L)
#define NIRFSA_ATTR_EXPORTED_DIGITIZER_SAMPLE_CLOCK_OUTPUT_TERMINAL  /* ViString */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 229L)

/*- Start Trigger ------------------------------------------------------*/
#define NIRFSA_ATTR_START_TRIGGER_TYPE                     /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)
#define NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE      /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)
#define NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)
#define NIRFSA_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)
#define NIRFSA_ATTR_START_TRIGGER_TERMINAL_NAME            /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 122L)

/*- Reference Trigger --------------------------------------------------*/
#define NIRFSA_ATTR_REF_TRIGGER_TYPE                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)
#define NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE        /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)
#define NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_EDGE          /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)
#define NIRFSA_ATTR_REF_TRIGGER_MINIMUM_QUIET_TIME         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 58L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SOURCE       /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 55L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_LEVEL        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 56L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SLOPE        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 57L)
#define NIRFSA_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL   /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)
#define NIRFSA_ATTR_REF_TRIGGER_TERMINAL_NAME              /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 123L)
#define NIRFSA_ATTR_REF_TRIGGER_DELAY                      /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 60L)
#define NIRFSA_ATTR_START_TO_REF_TRIGGER_HOLDOFF           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)
#define NIRFSA_ATTR_REF_TO_REF_TRIGGER_HOLDOFF             /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)
#define NIRFSA_ATTR_REF_TRIGGER_PRETRIGGER_SAMPLES         /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)
#define NIRFSA_ATTR_REF_TRIGGER_OSP_DELAY_ENABLED          /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 196L)

/*- Advance Trigger ---------------------------------------------------*/
#define NIRFSA_ATTR_ADVANCE_TRIGGER_TYPE                     /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)
#define NIRFSA_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE      /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)
#define NIRFSA_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)
#define NIRFSA_ATTR_ADVANCE_TRIGGER_TERMINAL_NAME            /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 124L)

/*- Arm Reference Trigger ---------------------------------------------*/
#define NIRFSA_ATTR_ARM_REF_TRIGGER_TYPE                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)
#define NIRFSA_ATTR_DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE    /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)

/*- Events -------------------------------------------------------------*/
#define NIRFSA_ATTR_EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL   /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)
#define NIRFSA_ATTR_EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)
#define NIRFSA_ATTR_EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL     /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)
#define NIRFSA_ATTR_EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL     /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)
#define NIRFSA_ATTR_EXPORTED_DONE_EVENT_OUTPUT_TERMINAL              /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 54L)

#define NIRFSA_ATTR_READY_FOR_START_EVENT_TERMINAL_NAME    /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 117L)
#define NIRFSA_ATTR_READY_FOR_ADVANCE_EVENT_TERMINAL_NAME  /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 118L)
#define NIRFSA_ATTR_READY_FOR_REF_EVENT_TERMINAL_NAME      /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 119L)
#define NIRFSA_ATTR_END_OF_RECORD_EVENT_TERMINAL_NAME      /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 120L)
#define NIRFSA_ATTR_DONE_EVENT_TERMINAL_NAME               /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 121L)

#define NIRFSA_ATTR_USER_SOURCE_PULSE_WIDTH_UNITS /* ViInt32  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L)
#define NIRFSA_ATTR_USER_SOURCE_PULSE_WIDTH       /* ViReal64 */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L)

/*- Fetching ------------------------------------------------------------*/
#define NIRFSA_ATTR_FETCH_RELATIVE_TO                      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)
#define NIRFSA_ATTR_FETCH_OFFSET                           /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L)
#define NIRFSA_ATTR_RECORDS_DONE                           /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L)
#define NIRFSA_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L)
#define NIRFSA_ATTR_DATA_TRANSFER_BLOCK_SIZE               /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L)
#define NIRFSA_ATTR_PHASE_OFFSET                           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L)

/*- Advanced ------------------------------------------------------------*/
#define NIRFSA_ATTR_DIGITAL_IF_EQUALIZATION_ENABLED        /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L)
#define NIRFSA_ATTR_FFT_WINDOW_SIZE                        /* ViInt32, read-only  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L)
#define NIRFSA_ATTR_FFT_SIZE                               /* ViInt32, read-only  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L)
#define NIRFSA_ATTR_FFT_WINDOW_SHAPE_FACTOR                /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 206L)
#define NIRFSA_ATTR_DEVICE_TEMPERATURE                     /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L)
#define NIRFSA_ATTR_TEMPERATURE_READ_INTERVAL              /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 61L)
#define NIRFSA_ATTR_DOWNCONVERTER_GAIN                     /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 65L)
#define NIRFSA_ATTR_NISCOPE_SESSION                        /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L)
#define NIRFSA_ATTR_RF_CONDITIONING_SESSION                /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 200L)
#define NIRFSA_ATTR_IF_CONDITIONING_SESSION                /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 201L)
#define NIRFSA_ATTR_DIGITIZER_VERTICAL_RANGE               /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)
#define NIRFSA_ATTR_ENABLE_FRACTIONAL_RESAMPLING           /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)
#define NIRFSA_ATTR_IF_FILTER                              /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)
#define NIRFSA_ATTR_LO_TEMPERATURE                         /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89L)
#define NIRFSA_ATTR_DIGITIZER_TEMPERATURE                  /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90L)
#define NIRFSA_ATTR_RF_CONDITIONING_TEMPERATURE            /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 211L)
#define NIRFSA_ATTR_IF_CONDITIONING_TEMPERATURE            /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 210L)
#define NIRFSA_ATTR_FPGA_TEMPERATURE                       /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 254L)

#define NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)
#define NIRFSA_ATTR_MECHANICAL_ATTENUATOR_ENABLED          /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)
#define NIRFSA_ATTR_EXTERNAL_GAIN                          /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94L)
#define NIRFSA_ATTR_5665_PRESELECTOR_TUNING_DAC_VALUE      /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 158L)

#define NIRFSA_ATTR_ALLOW_OUT_OF_SPECIFICATION_USER_SETTINGS  /* ViInt32          */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 256L)

#define NIRFSA_ATTR_THERMAL_CORRECTION_TEMPERATURE_RESOLUTION /* ViReal64         */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 300L)
#define NIRFSA_ATTR_THERMAL_CORRECTION_HEADROOM_RANGE         /* ViReal64         */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316L)

/*- Inband Retuning -----------------------------------------------------*/
#define NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY         /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)

/*- LO control attributes ----------------------------------------------*/
#define NIRFSA_ATTR_NIRFSG_SESSION                         /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)
#define NIRFSA_ATTR_LO_FREQUENCY                           /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)
#define NIRFSA_ATTR_LO_INJECTION_SIDE                      /* ViInt32,            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)
#define NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH           /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)
#define NIRFSA_ATTR_FREQUENCY_SETTLING_UNITS               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87L)
#define NIRFSA_ATTR_FREQUENCY_SETTLING                     /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88L)
#define NIRFSA_ATTR_LO_EXPORT_ENABLED                      /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 134L)
#define NIRFSA_ATTR_LO2_EXPORT_ENABLED                     /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 235L)
#define NIRFSA_ATTR_LO_YIG_MAIN_COIL_DRIVE                 /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 135L)
#define NIRFSA_ATTR_LO_SOURCE                              /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 162L)
#define NIRFSA_ATTR_RF_OUT_LO_EXPORT_ENABLED               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 298L)
#define NIRFSA_ATTR_LO_OUT_EXPORT_CONFIGURE_FROM_RFSG      /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 299L)

/*- Calibration ---------------------------------------------------------*/
#define NIRFSA_ATTR_CAL_RF_PATH_SELECTION                  /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)
#define NIRFSA_ATTR_CAL_IF_FILTER_SELECTION                /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L)
#define NIRFSA_ATTR_CAL_LO_PATH_SELECTION                  /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 113L)
#define NIRFSA_ATTR_CAL_IF_ATTENUATION_TABLE_SELECTION     /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 141L)
#define NIRFSA_ATTR_CAL_LO1_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 114L)
#define NIRFSA_ATTR_CAL_LO2_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 115L)
#define NIRFSA_ATTR_CAL_LO3_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 116L)
#define NIRFSA_ATTR_CAL_IF_ATTENUATION_INDEX               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109L)
#define NIRFSA_ATTR_CAL_RF_ELECTRONIC_ATTENUATION_INDEX    /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L)
#define NIRFSA_ATTR_CAL_RF_MECHANICAL_ATTENUATION_INDEX    /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_THROUGH_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 146L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_300_KHZ_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 147L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_5_MHZ_FILTER    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 148L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_100_MHZ_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 223L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_320_MHZ_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 224L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_765_MHZ_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 225L)
#define NIRFSA_ATTR_CAL_DIGITIZER_ID                       /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 226L)
#define NIRFSA_ATTR_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_SELECTION /* ViInt32  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 215L)
#define NIRFSA_ATTR_RF_HIGH_PASS_FILTERING                 /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 220L)
#define NIRFSA_ATTR_CAL_IF_ATTENUATION_TABLE_SIZE          /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 216L)

/*- Device Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_SERIAL_NUMBER                          /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L)
#define NIRFSA_ATTR_MODULE_REVISION                        /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91L)
#define NIRFSA_ATTR_MODULE_POWER_CONSUMPTION               /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 255L)
#define NIRFSA_ATTR_SIGNAL_BANDWIDTH                       /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 267L)
#define NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH         /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 125L)
#define NIRFSA_ATTR_PRESELECTOR_PRESENT                    /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 136L)
#define NIRFSA_ATTR_RF_PREAMP_PRESENT                      /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 137L)
#define NIRFSA_ATTR_MAX_DEVICE_INSTANTANEOUS_BANDWIDTH     /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 236L)
#define NIRFSA_ATTR_MAX_IQ_RATE                            /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 237L)

/*- List mode attributes ------------------------------------------------*/
#define NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST              /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 92L)
#define NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST_STEP         /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93L)
#define NIRFSA_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE /* ViString*/ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95L)
#define NIRFSA_ATTR_CONFIGURATION_LIST_STEP_IN_PROGRESS    /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 126L)
#define NIRFSA_ATTR_DDC_REF_TRIGGER_OVERRIDE               /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 164L)
#define NIRFSA_ATTR_MINIMUM_RECONFIG_TIME                  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 165L)
#define NIRFSA_ATTR_CONTIGUOUS_MULTIRECORD                 /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 172L)
#define NIRFSA_ATTR_TIMER_START_SOURCE                     /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 173L)
#define NIRFSA_ATTR_START_TRIGGER_DELAY                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 175L)


/* Timer Event configuration attributes */
#define NIRFSA_ATTR_TIMER_EVENT_INTERVAL                   /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96L)

/*- P2P Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_P2P_ENABLED                            /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 97L)
#define NIRFSA_ATTR_P2P_FIFO_ENDPOINT_COUNT                /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)
#define NIRFSA_ATTR_P2P_SAMPLES_TRANSFERRED                /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)
#define NIRFSA_ATTR_P2P_SAMPLES_AVAILABLE_IN_ENDPOINT      /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L)
#define NIRFSA_ATTR_P2P_MOST_SAMPLES_AVAILABLE_IN_ENDPOINT /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L)
#define NIRFSA_ATTR_P2P_ENDPOINT_SIZE                      /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L)
#define NIRFSA_ATTR_P2P_ENDPOINT_OVERFLOW                  /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L)
#define NIRFSA_ATTR_P2P_ONBOARD_MEMORY_ENABLED             /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L)

/*- Cal Tone Controls ---------------------------------------*/
#define NIRFSA_ATTR_DOWNCONVERTER_CAL_TONE_MODE         /* ViInt32   */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 139L)
#define NIRFSA_ATTR_DOWNCONVERTER_CAL_TONE_FREQUENCY    /* ViReal64  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 140L)
#define NIRFSA_ATTR_RF_CONDITIONING_CAL_TONE_MODE        /* ViInt32   */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 208L)
#define NIRFSA_ATTR_RF_CONDITIONING_CAL_TONE_FREQUENCY   /* ViReal64  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 209L)
#define NIRFSA_ATTR_CAL_TONE_STEP_ATTENUATION           /* ViReal64  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 168L)
#define NIRFSA_ATTR_CAL_TONE_POWER_REFERRED_TO_RF_IN    /* ViReal64  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 174L)

/*- Misc ----------------------------------------------------*/
#define NIRFSA_ATTR_NOISE_SOURCE_POWER_ENABLED                 /*ViInt32      */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 222L)

/*- Input Port ---------------------------------------------------------------*/
#define NIRFSA_ATTR_INPUT_PORT                                 /* ViInt32     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 180L)

/*- LO control attributes ----------------------------------------------------*/
#define NIRFSA_ATTR_LO_IN_POWER                                /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 186L)
#define NIRFSA_ATTR_LO_OUT_POWER                               /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 246L)
#define NIRFSA_ATTR_LO_PLL_FRACTIONAL_MODE_ENABLED             /* ViInt32     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 187L)
#define NIRFSA_ATTR_LO_FREQUENCY_STEP_SIZE                     /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 188L)
#define NIRFSA_ATTR_LO_VCO_FREQUENCY_STEP_SIZE                 /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312L)

/*- IQ In Port attributes ----------------------------------------------------*/
#define NIRFSA_ATTR_IQ_IN_PORT_CARRIER_FREQUENCY               /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 181L)
#define NIRFSA_ATTR_IQ_IN_PORT_TERMINAL_CONFIGURATION          /* ViInt32     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 182L)
#define NIRFSA_ATTR_IQ_IN_PORT_VERTICAL_RANGE                  /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 183L)
#define NIRFSA_ATTR_IQ_IN_PORT_TEMPERATURE                     /* ViReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 204L)
#define NIRFSA_ATTR_COMMON_MODE                                /* VIReal64    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 269L)

/*- Trigger Synchronization attributes ---------------------------------------*/
#define NIRFSA_ATTR_SYNC_START_TRIGGER_MASTER                  /*ViBoolean    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 176L)
#define NIRFSA_ATTR_SYNC_START_TRIGGER_DIST_LINE               /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 177L)
#define NIRFSA_ATTR_SYNC_REF_TRIGGER_MASTER                    /*ViBoolean    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 178L)
#define NIRFSA_ATTR_SYNC_REF_TRIGGER_DIST_LINE                 /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 179L)
#define NIRFSA_ATTR_SYNC_REF_TRIGGER_DELAY_ENABLED             /*ViInt32      */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 189L)
#define NIRFSA_ATTR_SYNC_ADVANCE_TRIGGER_MASTER                /*ViBoolean    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 184L)
#define NIRFSA_ATTR_SYNC_ADVANCE_TRIGGER_DIST_LINE             /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 185L)
#define NIRFSA_ATTR_SYNC_SAMPLE_CLOCK_MASTER                   /*ViBoolean    */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 217L)
#define NIRFSA_ATTR_SYNC_SAMPLE_CLOCK_DIST_LINE                /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 218L)

/*- Trigger attributes -------------------------------------------------------*/
#define NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_SOURCE          /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 192L)
#define NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_SLOPE           /*ViInt32      */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 193L)
#define NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_LEVEL           /*ViReal64     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 194L)
#define NIRFSA_ATTR_IQ_ANALOG_EDGE_REF_TRIGGER_HYSTERESIS      /*ViReal64     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 195L)

/*- Signal Path Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_DECIMATION_DELAY                           /*ViReal64     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 191L)
#define NIRFSA_ATTR_ABSOLUTE_DELAY                             /*ViReal64     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 266L)

/*- RF Downconverter Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE       /*ViInt32      */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 305L)
#define NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET            /*ViReal64     */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 203L)

/*- FPGA Extensions Attributes -----------------------------------------------*/
#define NIRFSA_ATTR_FPGA_BITFILE_PATH                          /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 221L)
#define NIRFSA_ATTR_FPGA_TARGET_NAME                           /*ViString     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 233L)

/*- Spur Reduction Attributes ---------------------------------------------------------*/
#define NIRFSA_ATTR_SUBSPAN_OVERLAP                            /*ViReal64     */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 234L)

/*- Host DMA Buffer Attributes -----------------------------------------------*/
#define NIRFSA_ATTR_HOST_DMA_BUFFER_SIZE                       /*ViInt64      */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 285L)

/*- De-embedding Attributes -------------------------------------------------*/
#define NIRFSA_ATTR_DEEMBEDDING_TYPE                          /*ViInt32      */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 307L)
#define NIRFSA_ATTR_DEEMBEDDING_SELECTED_TABLE                /*ViString     */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 308L)
#define NIRFSA_ATTR_DEEMBEDDING_COMPENSATION_GAIN             /*ViReal64     */     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 325L)

/****************************************************************************
 *------ Device-Specific Attribute Value Defines (5644R/5645R/5646R) -------*
 ****************************************************************************/

/*- NIRFSA_ATTR_INPUT_PORT Values -*/
#define NIRFSA_VAL_RF_IN                                2000
#define NIRFSA_VAL_IQ_IN                                2001
#define NIRFSA_VAL_CAL_IN                               2002
#define NIRFSA_VAL_I_ONLY                               2003

/*- NIRFSA_ATTR_IQ_IN_PORT_TERMINAL_CONFIGURATION Values -*/
#define NIRFSA_VAL_DIFFERENTIAL                         2100
#define NIRFSA_VAL_SINGLE_ENDED                         2101

/*- Additional values for Trigger Type attributes -*/
#define NIRFSA_VAL_IQ_ANALOG_EDGE                       605

/*- Trigger Synchronization attribute values -*/
#define NIRFSA_VAL_SYNC_START_TRIGGER_STR               "Sync_Start"
#define NIRFSA_VAL_SYNC_REF_TRIGGER_STR                 "Sync_Ref"
#define NIRFSA_VAL_SYNC_ADVANCE_TRIGGER_STR             "Sync_Advance"


/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

/*- NIRFSA_ATTR_ACQUISITION_TYPE Values -*/
#define NIRFSA_VAL_IQ                                   100
#define NIRFSA_VAL_SPECTRUM                             101

/*- NIRFSA_ATTR_POWER_SPECTRUM_UNITS Values -*/
#define NIRFSA_VAL_DBM                                  200
#define NIRFSA_VAL_VOLTS_SQUARED                        201
#define NIRFSA_VAL_DBMV                                 202
#define NIRFSA_VAL_DBUV                                 203
#define NIRFSA_VAL_VOLTS                                204
#define NIRFSA_VAL_WATTS                                205

/*- NIRFSA_ATTR_RESOLUTION_BANDWIDTH_TYPE Values -*/
#define NIRFSA_VAL_RBW_3DB                              300
#define NIRFSA_VAL_RBW_6DB                              301
#define NIRFSA_VAL_RBW_BIN_WIDTH                        302
#define NIRFSA_VAL_RBW_ENBW                             303

/*- NIRFSA_ATTR_AVERAGING_MODE Values -*/
#define NIRFSA_VAL_NO_AVERAGING                         400
#define NIRFSA_VAL_RMS_AVERAGING                        401
#define NIRFSA_VAL_VECTOR_AVERAGING                     402
#define NIRFSA_VAL_PEAK_HOLD_AVERAGING                  403
#define NIRFSA_VAL_MIN_HOLD_AVERAGING                   404
#define NIRFSA_VAL_SCALAR_AVERAGING                     405
#define NIRFSA_VAL_LOG_AVERAGING                        406

/*- NIRFSA_ATTR_FFT_WINDOW_TYPE Values -*/
#define NIRFSA_VAL_UNIFORM                              500
#define NIRFSA_VAL_HANNING                              501
#define NIRFSA_VAL_HAMMING                              502
#define NIRFSA_VAL_BLACKMAN_HARRIS                      503
#define NIRFSA_VAL_EXACT_BLACKMAN                       504
#define NIRFSA_VAL_BLACKMAN                             505
#define NIRFSA_VAL_FLAT_TOP                             506
#define NIRFSA_VAL_4_TERM_BLACKMAN_HARRIS               507
#define NIRFSA_VAL_7_TERM_BLACKMAN_HARRIS               508
#define NIRFSA_VAL_LOW_SIDE_LOBE                        509
#define NIRFSA_VAL_GAUSSIAN                             510
#define NIRFSA_VAL_KAISER_BESSEL                        511

/*- Values For Trigger Type Attributes -*/
#define NIRFSA_VAL_NONE                                 600
#define NIRFSA_VAL_DIGITAL_EDGE                         601
#define NIRFSA_VAL_DIGITAL_LEVEL                        602
#define NIRFSA_VAL_IQ_POWER_EDGE                        603
#define NIRFSA_VAL_SOFTWARE_EDGE                        604

/*- NIRFSA_ATTR_FETCH_RELATIVE_TO Values -*/
#define NIRFSA_VAL_MOST_RECENT_SAMPLE                   700
#define NIRFSA_VAL_FIRST_SAMPLE                         701
#define NIRFSA_VAL_REF_TRIGGER                          702
#define NIRFSA_VAL_FIRST_PRETRIGGER_SAMPLE              703
#define NIRFSA_VAL_CURRENT_READ_POSITION                704

/*- NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH Values -*/
#define NIRFSA_VAL_NARROW                               800
#define NIRFSA_VAL_MEDIUM                               801
#define NIRFSA_VAL_WIDE                                 802

/*- Values For Digital Edge Attributes -*/
#define NIRFSA_VAL_RISING_EDGE                          900
#define NIRFSA_VAL_FALLING_EDGE                         901

/*- Values For Slope Attributes -*/
#define NIRFSA_VAL_RISING_SLOPE                        1000
#define NIRFSA_VAL_FALLING_SLOPE                       1001

/*- Values For Send Software Edge Trigger -*/
#define NIRFSA_VAL_START_TRIGGER                       1100
/* #define NIRFSA_VAL_REF_TRIGGER                       702  (Defined Above) */
#define NIRFSA_VAL_ADVANCE_TRIGGER                     1102
#define NIRFSA_VAL_ARM_REF_TRIGGER                     1103

/*- Values for Export Signals -*/
#define NIRFSA_VAL_READY_FOR_START_EVENT               1200
#define NIRFSA_VAL_READY_FOR_REF_EVENT                 1201
#define NIRFSA_VAL_READY_FOR_ADVANCE_EVENT             1202
#define NIRFSA_VAL_END_OF_RECORD_EVENT                 1203
#define NIRFSA_VAL_DONE_EVENT                          1204
#define NIRFSA_VAL_REF_CLOCK                           1205
#define NIRFSA_VAL_USER                                1206

/*- Values for LO Injection attribute-*/
#define NIRFSA_VAL_LO_INJECTION_HIGH_SIDE              1300
#define NIRFSA_VAL_LO_INJECTION_LOW_SIDE               1301

/*- Values for NIRFSA_ATTR_REF_CLOCK_SOURCE and NIRFSA_ATTR_PXI_CHASSIS_CLK10_SOURCE -*/
#define NIRFSA_VAL_NONE_STR                            "None"
#define NIRFSA_VAL_ONBOARD_CLOCK_STR                   "OnboardClock"
#define NIRFSA_VAL_REF_IN_STR                          "RefIn"
#define NIRFSA_VAL_PXI_CLK_STR                         "PXI_Clk"
#define NIRFSA_VAL_REF_IN_2_STR                        "RefIn2"
#define NIRFSA_VAL_PXI_CLK_MASTER_STR                  "PXI_ClkMaster"

/*- Values for NIRFSA_ATTR_LO_SOURCE -*/
#define NIRFSA_VAL_LO_IN_STR                           "LO_In"
#define NIRFSA_VAL_ONBOARD_STR                         "Onboard"
#define NIRFSA_VAL_LO_SOURCE_SECONDARY_STR             "Secondary"
#define NIRFSA_VAL_LO_SOURCE_SG_SA_SHARED_STR          "SG_SA_Shared"

/*- Values for NIRFSA_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL -*/
/* #define NIRFSA_VAL_NONE_STR                            "None" (Defined Above) */
#define NIRFSA_VAL_CLK_OUT_STR                         "ClkOut"
#define NIRFSA_VAL_REF_OUT_STR                         "RefOut"
#define NIRFSA_VAL_REF_OUT2_STR                        "RefOut2"
#define NIRFSA_VAL_IF_COND_REF_OUT_STR                 "IFCondRefOut"

/*- Values for NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE -*/
#define NIRFSA_VAL_CLK_IN_STR                          "ClkIn"
/* #define NIRFSA_VAL_ONBOARD_CLOCK_STR                "OnboardClock" (Defined Above) */
/* #define NIRFSA_VAL_PXI_STAR_STR                     "PXI_STAR"     (Defined Below) */
#define NIRFSA_VAL_LO_REF_CLK_STR                      "LORefClk"
#define NIRFSA_VAL_DOWNCONVERTER_LO2_OUT_STR           "DownconverterLO2Out"

/*- Values for digital source and export terminal attributes:
    NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE
    NIRFSA_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_DONE_EVENT_OUTPUT_TERMINAL
-*/

#define NIRFSA_VAL_DO_NOT_EXPORT_STR                   ""
#define NIRFSA_VAL_PFI0_STR                            "PFI0"
#define NIRFSA_VAL_PFI1_STR                            "PFI1"
#define NIRFSA_VAL_PXI_TRIG0_STR                       "PXI_Trig0"
#define NIRFSA_VAL_PXI_TRIG1_STR                       "PXI_Trig1"
#define NIRFSA_VAL_PXI_TRIG2_STR                       "PXI_Trig2"
#define NIRFSA_VAL_PXI_TRIG3_STR                       "PXI_Trig3"
#define NIRFSA_VAL_PXI_TRIG4_STR                       "PXI_Trig4"
#define NIRFSA_VAL_PXI_TRIG5_STR                       "PXI_Trig5"
#define NIRFSA_VAL_PXI_TRIG6_STR                       "PXI_Trig6"
#define NIRFSA_VAL_PXI_TRIG7_STR                       "PXI_Trig7"
#define NIRFSA_VAL_PXI_STAR_STR                        "PXI_STAR"
#define NIRFSA_VAL_PXIE_DSTARB_STR                     "PXIe_DStarB"
#define NIRFSA_VAL_PXIE_DSTARC_STR                     "PXIe_DStarC"
#define NIRFSA_VAL_RTSI0_STR                           NIRFSA_VAL_PXI_TRIG0_STR
#define NIRFSA_VAL_RTSI1_STR                           NIRFSA_VAL_PXI_TRIG1_STR
#define NIRFSA_VAL_RTSI2_STR                           NIRFSA_VAL_PXI_TRIG2_STR
#define NIRFSA_VAL_RTSI3_STR                           NIRFSA_VAL_PXI_TRIG3_STR
#define NIRFSA_VAL_RTSI4_STR                           NIRFSA_VAL_PXI_TRIG4_STR
#define NIRFSA_VAL_RTSI5_STR                           NIRFSA_VAL_PXI_TRIG5_STR
#define NIRFSA_VAL_RTSI6_STR                           NIRFSA_VAL_PXI_TRIG6_STR
#define NIRFSA_VAL_RTSI7_STR                           NIRFSA_VAL_PXI_TRIG7_STR
#define NIRFSA_VAL_TIMER_EVENT_STR                     "TimerEvent"
#define NIRFSA_VAL_END_OF_RECORD_EVENT_STR             "EndOfRecordEvent"
#define NIRFSA_VAL_START_TRIGGER_STR                   "StartTrigger"
#define NIRFSA_VAL_REFERENCE_TRIGGER_STR               "ReferenceTrigger"
#define NIRFSA_VAL_USER_SOURCE0_STR                    "UserSource0"
#define NIRFSA_VAL_USER_SOURCE1_STR                    "UserSource1"
#define NIRFSA_VAL_USER_SOURCE2_STR                    "UserSource2"
#define NIRFSA_VAL_USER_SOURCE3_STR                    "UserSource3"
#define NIRFSA_VAL_USER_SOURCE4_STR                    "UserSource4"
#define NIRFSA_VAL_USER_SOURCE5_STR                    "UserSource5"
#define NIRFSA_VAL_USER_SOURCE6_STR                    "UserSource6"
#define NIRFSA_VAL_USER_SOURCE7_STR                    "UserSource7"

/*- Values for NIRFSA_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE -*/
/* #define NIRFSA_VAL_TIMER_EVENT_STR                     "TimerEvent" (Defined Above) */
/* #define NIRFSA_VAL_END_OR_RECORD_EVENT_STR             "EndOfRecordEvent" (Defined Above) */

/*- Values for NIRFSA_ATTR_TIMER_START_SOURCE -*/
/* #define NIRFSA_VAL_START_TRIGGER_STR                   "StartTrigger" (Defined Above) */
/* #define NIRFSA_VAL_REFERENCE_TRIGGER_STR               "ReferenceTrigger" (Defined Above) */

/*- Values for IF Filter attribute -*/
#define NIRFSA_VAL_187_5_MHZ_WIDE                                 1400
#define NIRFSA_VAL_187_5_MHZ_NARROW                               1401
#define NIRFSA_VAL_53_MHZ                                         1402
#define NIRFSA_VAL_BYPASS                                         1403

/////////////////////////////////////////////////////////////////////////
// Values for External Calibration
/*- Defined values for action in niRFSA_CloseExtCal()  ---------------*/
#define NIRFSA_VAL_EXT_CAL_ABORT                                  1500
#define NIRFSA_VAL_EXT_CAL_COMMIT                                 1501

/*- Defined values for calibration step in niRFSA_InitializeCalibrationStep() ---------------*/
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_CALIBRATION             1600
#define NIRFSA_VAL_EXT_CAL_IF_RESPONSE_CALIBRATION                1601
#define NIRFSA_VAL_EXT_CAL_REF_LEVEL_CALIBRATION                  1602
#define NIRFSA_VAL_EXT_CAL_LO_EXPORT_CALIBRATION                  1603
#define NIRFSA_VAL_EXT_CAL_GAIN_REFERENCE_CALIBRATION             1604

/*- Defined values for NIRFSA_ATTR_CAL_RF_PATH_SELECTION  ---------------*/
#define NIRFSA_VAL_EXT_CAL_RF_BAND_1                              1700
#define NIRFSA_VAL_EXT_CAL_RF_BAND_2                              1701
#define NIRFSA_VAL_EXT_CAL_RF_BAND_3                              1702
#define NIRFSA_VAL_EXT_CAL_RF_BAND_4                              1703

/*- Defined values for refLevelCalDataType in
 * niRFSA_CalAdjustRefLevelCalibration()  ---------------*/
#define NIRFSA_VAL_EXT_CAL_DEFAULT                                1800
#define NIRFSA_VAL_EXT_CAL_MECHANICAL_ATTENUATOR_DISABLED         1801

/*- Values for NIRFSA_ATTR_MECHANICAL_ATTENUATOR_ENABLED, NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED,
 *  NIRFSA_ATTR_REF_TRIGGER_OSP_DELAY_ENABLED, NIRFSA_ATTR_INPUT_ISOLATION_ENABLED,
 *  NIRFSA_ATTR_LO_OUT_EXPORT_CONFIGURE_FROM_RFSG and NIRFSA_ATTR_RF_OUT_LO_EXPORT_ENABLED.
 *  NIRFSA_VAL_ENABLED is also for NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE. -*/
#define NIRFSA_VAL_DISABLED                                       1900
#define NIRFSA_VAL_ENABLED                                        1901

/*- Value for NIRFSA_ATTR_RF_OUT_LO_EXPORT_ENABLED  -*/
#define NIRFSA_VAL_UNSPECIFIED                                    1902

/*- Additional values for NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE */
#define NIRFSA_VAL_AUTOMATIC                                      1903
#define NIRFSA_VAL_USER_DEFINED                                   1904

/*- Values for Frequency Settling units attribute */
#define NIRFSA_VAL_FSU_PPM                                        2000
#define NIRFSA_VAL_FSU_SECONDS_AFTER_LOCK                         2001
#define NIRFSA_VAL_FSU_SECONDS_AFTER_IO                           2002

/*- Values for NIRFSA_ATTR_CAL_IF_FILTER_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_1                       2100 // 5Mhz Bandpass IF Filter
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_2                       2101 // 300Khz BandPass IF Filter
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_3                       2102 // Bypass Path (no IF Filter)
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_4                       2103
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_5                       2104
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_6                       2105
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_7                       2106
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_8                       2107
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_9                       2108
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_10                      2109
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_11                      2110

/*-Values For niRFSA_CalAdjustLOExportCalibration:LONumber-*/
#define NIRFSA_VAL_EXT_CAL_LO1                                    2200 // Variable LO
#define NIRFSA_VAL_EXT_CAL_LO2                                    2201 // 4Ghz LO
#define NIRFSA_VAL_EXT_CAL_LO3                                    2202 // 800Mhz LO

/*- Values for NIRFSA_ATTR_CAL_LO_PATH_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_LO_PATH_1                              2300 // LO x1
#define NIRFSA_VAL_EXT_CAL_LO_PATH_2                              2301 // LO Doubler Enabled (5605)/LO x2 LF 6.4GHz LPF (5606)
#define NIRFSA_VAL_EXT_CAL_LO_PATH_3                              2302 // LO x2 HF 9.7GHz LPF (5606)
#define NIRFSA_VAL_EXT_CAL_LO_PATH_4                              2303 // LO x4 LF 6.4GHz LPF (5606)
#define NIRFSA_VAL_EXT_CAL_LO_PATH_5                              2304 // LO x4 HF 9.7GHz LPF (5606)

/*- Values for NIRFSA_ATTR_LO_YIG_MAIN_COIL_DRIVE attribute-*/
#define NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_NORMAL                  2400
#define NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_FAST                    2401

/*- Values for NIRFSA_ATTR_RF_PREAMP_ENABLED attribute-*/
#define NIRFSA_VAL_RF_PREAMP_DISABLED                             2500 // Preamp Disabled
#define NIRFSA_VAL_RF_PREAMP_ENABLED_WHEN_IN_SIGNAL_PATH          2501 // The RF preamp will be automatically enabled when it is in the signal path and will be automatically disabled when it is out of the signal path
#define NIRFSA_VAL_RF_PREAMP_ENABLED                              2502 // Preamp Enabled
#define NIRFSA_VAL_RF_PREAMP_AUTOMATIC                            2503 // Automatic

/*- Values for NIRFSA_ATTR_DOWNCONVERTER_PRESELECTOR_ENABLED attribute-*/
#define NIRFSA_VAL_PRESELECTOR_DISABLED                           2600 // Preselector Disabled
#define NIRFSA_VAL_PRESELECTOR_ENABLED_WHEN_IN_SIGNAL_PATH        2601 // The preselector will be automatically enabled when it is in the signal path and will be automatically disabled when it is out of the signal path.
#define NIRFSA_VAL_PRESELECTOR_ENABLED                            2602 // Preselector Enabled

/*- Values for SELF CAL steps -*/
#define NIRFSA_VAL_SELF_CAL_OMIT_NONE                             0x0000000000000000
#define NIRFSA_VAL_SELF_CAL_PRESELECTOR_ALIGNMENT                 0x0000000000000001
#define NIRFSA_VAL_SELF_CAL_GAIN_REFERENCE                        0x0000000000000002
#define NIRFSA_VAL_SELF_CAL_IF_FLATNESS                           0x0000000000000004
#define NIRFSA_VAL_SELF_CAL_DIGITIZER_SELF_CAL                    0x0000000000000008
#define NIRFSA_VAL_SELF_CAL_LO_SELF_CAL                           0x0000000000000010
#define NIRFSA_VAL_SELF_CAL_AMPLITUDE_ACCURACY                    0x0000000000000020
#define NIRFSA_VAL_SELF_CAL_RESIDUAL_LO_POWER                     0x0000000000000040
#define NIRFSA_VAL_SELF_CAL_IMAGE_SUPPRESSION                     0x0000000000000080
#define NIRFSA_VAL_SELF_CAL_SYNTHESIZER_ALIGNMENT                 0x0000000000000100
#define NIRFSA_VAL_SELF_CAL_DC_OFFSET                             0x0000000000000200


/*- Values for Cal Tone Mode -*/
#define NIRFSA_VAL_CAL_TONE_DISABLED                              2700
#define NIRFSA_VAL_CAL_TONE_LOWBAND_RF                            2701
#define NIRFSA_VAL_CAL_TONE_HIGHBAND_RF                           2702
#define NIRFSA_VAL_CAL_TONE_HIGHBAND_IF                           2703
#define NIRFSA_VAL_CAL_TONE_LOWBAND_RF_WITHOUT_ALC                2704
#define NIRFSA_VAL_CAL_TONE_COMB_GENERATOR                        2705

/* Values for niRFSA_GetDeviceResponse response type */
#define NIRFSA_VAL_DOWNCONVERTER_IF_RESPONSE                      2800
#define NIRFSA_VAL_DOWNCONVERTER_RF_RESPONSE                      2801
#define NIRFSA_VAL_DOWNCONVERTER_COMBINED_RESPONSE                2802
#define NIRFSA_VAL_VSA_IF_RESPONSE                                2803
#define NIRFSA_VAL_VSA_COMBINED_RESPONSE                          2804

/*- Values for NIRFSA_ATTR_CAL_IF_ATTENUATION_TABLE_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_TABLE_STANDARD          2900
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_TABLE_ACPR              2901

/*- Values for NIRFSA_ATTR_CHANNEL_COUPLING attribute -*/
#define NIRFSA_VAL_AC                                             3001
#define NIRFSA_VAL_DC                                             3002

/*- Values for External Alignment ----------------------------------*/
/*- Values for External Alignment Steps -                           */
/*- This is an enumeration value. Future values will not be bitwise */
/*- ORed with this value.                                           */
#define NIRFSA_VAL_EXT_ALIGNMENT_PRESELECTOR                         1

/*- Defined values for action in niRFSA_CloseExternalAlignmentCal() -*/
#define NIRFSA_VAL_EXT_ALIGNMENT_ABORT                            3100
#define NIRFSA_VAL_EXT_ALIGNMENT_COMMIT                           3101

/*- Values for NIRFSA_ATTR_STEP_GAIN_ENABLED attribute -*/
#define NIRFSA_VAL_STEP_GAIN_DISABLED                             3200
#define NIRFSA_VAL_STEP_GAIN_ENABLED                              3201

/*- Values for NIRFSA_ATTR_RF_PRESELECTOR_FILTER attribute -*/
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_NONE                3300  // None
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_1                   3301  // 19-35 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_2                   3302  // 33-61 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_3                   3303  // 59-110 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_4                   3304  // 90-167 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_5                   3305  // 140-245 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_6                   3306  // 205-370 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_7                   3307  // 330-595 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_8                   3308  // 550-975 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_9                   3309  // 910-1600 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_10                  3310  // 1520-2040 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_11                  3311  // 1960-2540 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_12                  3312  // 2460-3040 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_13                  3313  // 2960-3840 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_14                  3314  // 3760-4640 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_15                  3315  // 4560-5840 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_16                  3316  // 5760-7040 MHz
#define NIRFSA_VAL_RF_PRESELECTOR_FILTER_PATH_EXTERNAL_FILTER     3317  // External Filter

/*- Values for NIRFSA_ATTR_NOTCH_FILTER_ENABLED attribute -*/
#define NIRFSA_VAL_NOTCH_FILTER_DISABLED                          3400
#define NIRFSA_VAL_NOTCH_FILTER_ENABLED_WHEN_IN_SIGNAL_PATH       3401
#define NIRFSA_VAL_NOTCH_FILTER_ENABLED                           3402

/*- Values for NIRFSA_ATTR_SIGNAL_CONDITIONING_ENABLED attribute -*/
#define NIRFSA_VAL_SIGNAL_CONDITIONING_ENABLED                    3600
#define NIRFSA_VAL_SIGNAL_CONDITIONING_BYPASSED                   3601

/*- Values for NIRFSA_ATTR_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_1  3700 //Through Path
#define NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_2  3701 //Attenuator Only
#define NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_3  3702 //1350MHz HPF
#define NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_4  3703 //2200MHz HPF
#define NIRFSA_VAL_EXT_CAL_RF_LOWBAND_SIGNAL_CONDITIONING_PATH_5  3704 //Preamp Path

/*- Values for S-parameters orientation passed to Create De-embedding S-parameter Table functions -*/
#define NIRFSA_VAL_PORT1_TOWARDS_DUT                              3800
#define NIRFSA_VAL_PORT2_TOWARDS_DUT                              3801

/*- Values for NIRFSA_ATTR_DEEMBEDDING_TYPE attribute -*/
#define NIRFSA_VAL_DEEMBEDDING_TYPE_NONE                          3900
#define NIRFSA_VAL_DEEMBEDDING_TYPE_SCALAR                        3901
#define NIRFSA_VAL_DEEMBEDDING_TYPE_VECTOR                        3902

/*- Values for niRFSA_ConfigureDeembeddingTableInterpolationLinear -*/
#define NIRFSA_VAL_LINEAR_INTERPOLATION_FORMAT_REAL_AND_IMAGINARY      4000
#define NIRFSA_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_AND_PHASE     4001
#define NIRFSA_VAL_LINEAR_INTERPOLATION_FORMAT_MAGNITUDE_DB_AND_PHASE  4002

/*- Values for NIRFSA_ATTR_OVERFLOW_ERROR_REPORTING attribute -*/
#define NIRFSA_VAL_ERROR_REPORTING_WARNING                        1301
#define NIRFSA_VAL_ERROR_REPORTING_DISABLED                       1302

/*- Values for stepsToOmit in ResetWithOptions-*/
#define NIRFSA_VAL_RESET_WITH_OPTIONS_NONE                        0x0ULL //reset everything
#define NIRFSA_VAL_RESET_WITH_OPTIONS_ROUTES                      0x1ULL //do not reset routes
#define NIRFSA_VAL_RESET_WITH_OPTIONS_DEEMBEDDING_TABLES          0x2ULL

/*- Values for NIRFSA_ATTR_USER_SOURCE_PULSE_WIDTH_UNITS -*/
#define NIRFSA_VAL_PULSE_WIDTH_UNITS_SECONDS       6200
#define NIRFSA_VAL_PULSE_WIDTH_UNITS_CLOCK_PERIODS 6201

/*- SMT Structures -----------------------------------------------*/
#if kRFSA_32BitPlatform
   #pragma pack(push, 1)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

#ifndef __SmtSpectrumInfo__
#define __SmtSpectrumInfo__
typedef struct {
   unsigned short spectrumType;
   unsigned short linearDB;
   unsigned short window;
   int windowSize;
   int FFTSize;
} SmtSpectrumInfo;
#endif

#if kRFSA_32BitPlatform
   #pragma pack(pop)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_init (
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean reset,
   ViSession* vi);

ViStatus _VI_FUNC niRFSA_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean reset,
   ViConstString optionString,
   ViSession* newVi);

ViStatus _VI_FUNC niRFSA_close(
   ViSession vi);

/*- Peer-to-Peer utility -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_GetStreamEndpointHandle(
   ViSession vi,
   ViConstString streamEndpoint,
   ViUInt32* writerHandle);

/*- Calibration -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_InitExtCal(
   ViRsrc resourceName,
   ViConstString password,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niRFSA_InitializeCalibrationStep(
   ViSession vi,
   ViInt32 calibrationStep);

ViStatus _VI_FUNC niRFSA_CloseCalibrationStep(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_CloseExtCal(
   ViSession vi,
   ViInt32 action);

ViStatus _VI_FUNC niRFSA_SelfCalibrate(
   ViSession vi,
   ViInt64 stepsToOmit);

ViStatus _VI_FUNC niRFSA_IsSelfCalValid(
   ViSession vi,
   ViBoolean* selfCalValid,
   ViInt64* validSteps);

ViStatus _VI_FUNC niRFSA_InitializeExternalAlignment(
   ViRsrc resourceName,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niRFSA_CloseExternalAlignment(
   ViSession vi,
   ViInt32 action);

ViStatus _VI_FUNC niRFSA_InitializeExternalAlignmentStep(
   ViSession vi,
   ViInt64 externalAlignmentStep);

ViStatus _VI_FUNC niRFSA_CloseExternalAlignmentStep(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_SelfCalibrateRange(
   ViSession vi,
   ViInt64 stepsToOmit,
   ViReal64 minFrequency,
   ViReal64 maxFrequency,
   ViReal64 minReferenceLevel,
   ViReal64 maxReferenceLevel);

/* Calibration Utility Functions */
ViStatus _VI_FUNC niRFSA_GetExtCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niRFSA_GetExtCalLastTemp(
   ViSession vi,
   ViReal64* temperature);

ViStatus _VI_FUNC niRFSA_GetExtCalRecommendedInterval(
   ViSession vi,
   ViInt32* months);

ViStatus _VI_FUNC niRFSA_ChangeExtCalPassword(
   ViSession vi,
   ViConstString oldPassword,
   ViConstString newPassword);

ViStatus _VI_FUNC niRFSA_SetCalUserDefinedInfo(
   ViSession vi,
   ViConstString info);

ViStatus _VI_FUNC niRFSA_GetCalUserDefinedInfo(
   ViSession vi,
   ViChar info[]);

ViStatus _VI_FUNC niRFSA_GetCalUserDefinedInfoMaxSize(
   ViSession vi,
   ViInt32* infoSize);

ViStatus _VI_FUNC niRFSA_ExtCalStoreBaselineForSelfCalibration(
   ViSession vi,
   ViString password,
   ViInt64 selfCalibrationStep);

ViStatus _VI_FUNC niRFSA_GetSelfCalLastDateAndTime(
   ViSession vi,
   ViInt64 selfCalibrationStep,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niRFSA_GetSelfCalLastTemp(
   ViSession vi,
   ViInt64 selfCalibrationStep,
   ViReal64* temp);

ViStatus _VI_FUNC niRFSA_GetGainReferenceCalBaseline(
   ViSession vi,
   ViInt32  bufferSize,
   ViReal64 gainReferenceCalConstants[],
   ViInt32* numberOfGainReferenceCalConstants);

ViStatus _VI_FUNC niRFSA_ClearSelfCalibrateRange(
   ViSession vi);

/*- Calibration Adjust Functions-------------------------------------*/
ViStatus _VI_FUNC niRFSA_CalAdjustIFAttenuationCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32 IFFilter,
   ViInt32 numberOfAttenuators,
   ViReal64* attenuatorSettings,
   ViReal64 measurement);

ViStatus _VI_FUNC niRFSA_CalAdjustIFResponseCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32  IFFilter,
   ViReal64 RFFrequency,
   ViReal64 bandWidth,
   ViInt32  numberOfMeasurements,
   ViReal64* measurements);

ViStatus _VI_FUNC niRFSA_CalAdjustRefLevelCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32 referenceLevelDataType,
   ViInt32 rfBand,
   ViInt32 attenuatorTableNumber,
   ViReal64 frequency,
   ViReal64 measurement);

ViStatus _VI_FUNC niRFSA_CalAdjustLOExportCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32   loNumber,
   ViInt32   numberOfFrequencyPoints,
   ViReal64* frequencyPoints,
   ViReal64* loAttenuation);

ViStatus _VI_FUNC niRFSA_CalAdjustDeviceGain(
   ViSession vi,
   ViConstString channelList,
   ViReal64 frequency,
   ViReal64 gain);

ViStatus _VI_FUNC niRFSA_CalSetTemperature(
   ViSession vi,
   ViConstString channelList,
   ViReal64 temperature);

ViStatus _VI_FUNC niRFSA_ExternalAlignmentAdjustPreselector(
   ViSession vi,
   ViInt32 numberOfCoefficients,
   ViReal64 coefficients[]);

ViStatus _VI_FUNC niRFSA_CalAdjustCalTonePower(
   ViSession vi,
   ViConstString channelList,
   ViReal64 measurement);

/*- Required VXIplug&play Functions ----------------------------------------*/
ViStatus _VI_FUNC niRFSA_reset(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ResetDevice(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ResetWithOptions(
   ViSession vi,
   ViUInt64 stepsToOmit);

ViStatus _VI_FUNC niRFSA_self_test(
   ViSession vi,
   ViInt16 *testResult,/*Output*/
   ViChar testMessage[]);

ViStatus _VI_FUNC niRFSA_error_query(
   ViSession vi,
   ViInt32 *errorCode,
   ViChar errorMessage[]);

ViStatus _VI_FUNC niRFSA_error_message(
   ViSession vi,
   ViStatus statusCode,
   ViChar errorMessage[]);

ViStatus _VI_FUNC niRFSA_revision_query(
   ViSession vi,
   ViChar driverRev[],
   ViChar instrRev[]);

ViStatus _VI_FUNC niRFSA_Disable(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ResetWithDefaults(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_InvalidateAllAttributes(
   ViSession vi);


/*- Error Functions --------------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_GetError(
   ViSession vi,
   ViStatus *errorCode,
   ViInt32 errorDescriptionBufferSize,
   ViChar errorDescription[]);

ViStatus _VI_FUNC niRFSA_ClearError(
   ViSession vi);

/*- Required IVI Functions ---------------------------------------------*/
ViStatus _VI_FUNC niRFSA_LockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

ViStatus _VI_FUNC niRFSA_UnlockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

/*- Acquisition Type Configuration -------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureAcquisitionType(
   ViSession vi,
   ViInt32 acquisitionType);

/*- Reference Level Configuration --------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureReferenceLevel(
   ViSession vi,
   ViConstString channelList,
   ViReal64 referenceLevel);

/*- IQ Acquisition Configuration ---------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureIQCarrierFrequency(
   ViSession vi,
   ViConstString channelList,
   ViReal64 carrierFrequency);

ViStatus _VI_FUNC niRFSA_ConfigureIQRate(
   ViSession vi,
   ViConstString channelList,
   ViReal64 iqRate);

ViStatus _VI_FUNC niRFSA_ConfigureNumberOfSamples(
   ViSession vi,
   ViConstString channelList,
   ViBoolean numberOfSamplesIsFinite,
   ViInt64 samplesPerRecord);

ViStatus _VI_FUNC niRFSA_ConfigureNumberOfRecords(
   ViSession vi,
   ViConstString channelList,
   ViBoolean numberOfRecordsIsFinite,
   ViInt64 numberOfRecords);

/*- Spectrum Acquisition Configuration ---------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureSpectrumFrequencyCenterSpan(
   ViSession vi,
   ViConstString channelList,
   ViReal64 centerFrequency,
   ViReal64 span);

ViStatus _VI_FUNC niRFSA_ConfigureSpectrumFrequencyStartStop(
   ViSession vi,
   ViConstString channelList,
   ViReal64 startFrequency,
   ViReal64 stopFrequency);

ViStatus _VI_FUNC niRFSA_ConfigureResolutionBandwidth(
   ViSession vi,
   ViConstString channelList,
   ViReal64 resolutionBandwidth);

/*- Clock Configuration ------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureRefClock(
   ViSession vi,
   ViConstString clockSource,
   ViReal64 refClockRate);

ViStatus _VI_FUNC niRFSA_ConfigurePXIChassisClk10(
   ViSession vi,
   ViConstString pxiClk10Source);

/*- Trigger Configuration ----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeStartTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_DisableStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeRefTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_ConfigureIQPowerEdgeRefTrigger(
   ViSession vi,
   ViConstString source,
   ViReal64 level,
   ViInt32 slope,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeRefTrigger(
   ViSession vi,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_DisableRefTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeAdvanceTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeAdvanceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_DisableAdvanceTrigger(
   ViSession vi);

/*- Reading / Fetching IQ Data ------------------------------------------*/
#if !defined(_NIComplexNumber)
#define _NIComplexNumber

#pragma pack(push, 8)
typedef struct NIComplexNumber_struct {
   ViReal64 real;
   ViReal64 imaginary;
} NIComplexNumber;
#pragma pack(pop)

#endif

#if !defined(_NIComplexNumberF32)
#define _NIComplexNumberF32

#if kRFSA_32BitPlatform
   #pragma pack(push, 1)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

typedef struct NIComplexNumberF32_struct {
   ViReal32 real;
   ViReal32 imaginary;
} NIComplexNumberF32;

#if kRFSA_32BitPlatform
   #pragma pack(pop)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

#endif


#if !defined(_niRFSA_wfmInfo)
#define _niRFSA_wfmInfo

#pragma pack(push,8)
typedef struct niRFSA_wfmInfo_struct
{
   ViReal64 absoluteInitialX;
   ViReal64 relativeInitialX;
   ViReal64 xIncrement;
   ViInt64 actualSamples;
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
} niRFSA_wfmInfo;
#pragma pack(pop)

#endif

#pragma pack(push,8)
typedef struct niRFSA_coefficientInfo_struct
{
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
} niRFSA_coefficientInfo;
#pragma pack(pop)

#if kRFSA_32BitPlatform
   #pragma pack(push, 2)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif

#if !defined(_NIComplexI16)
#define _NIComplexI16
typedef struct NIComplexI16_struct {
   ViInt16 real;
   ViInt16 imaginary;
} NIComplexI16;
#endif

#if kRFSA_32BitPlatform
   #pragma pack(pop)
#elif kRFSA_64BitPlatform
   // Nothing needed for 64 bit platforms
#else
   #error Unknown Platform
#endif



ViStatus _VI_FUNC niRFSA_ReadIQSingleRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   NIComplexNumber* data,
   ViInt64 dataArraySize,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQSingleRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumber* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQSingleRecordComplexF32(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumberF32* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQMultiRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViInt64 startingRecord,
   ViInt64 numberOfRecords,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumber* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQMultiRecordComplexF32(
   ViSession vi,
   ViConstString channelList,
   ViInt64 startingRecord,
   ViInt64 numberOfRecords,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumberF32* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQSingleRecordComplexI16(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexI16* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQMultiRecordComplexI16
(
   ViSession vi,
   ViConstString channelList,
   ViInt64 startingRecord,
   ViInt64 numberOfRecords,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexI16* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_GetFetchBacklog(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64* backlog);

ViStatus _VI_FUNC niRFSA_GetScalingCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 arraySize,
   niRFSA_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

ViStatus _VI_FUNC niRFSA_GetNormalizationCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 arraySize,
   niRFSA_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

/*- Reading Spectrum Data ----------------------------------------------*/
#if !defined(_niRFSA_spectrumInfo)
#define _niRFSA_spectrumInfo

#pragma pack(push,8)
typedef struct niRFSA_spectrumInfo_struct
{
   ViReal64 initialFrequency;
   ViReal64 frequencyIncrement;
   ViInt32 numberOfSpectralLines;
   ViReal64 reserved1;
   ViReal64 reserved2;
   ViReal64 reserved3;
   ViReal64 reserved4;
   ViReal64 reserved5;
} niRFSA_spectrumInfo;
#pragma pack(pop)

#endif

ViStatus _VI_FUNC niRFSA_ReadPowerSpectrumF64(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViReal64 powerSpectrumData[],
   ViInt32 dataArraySize,
   niRFSA_spectrumInfo* spectrumInfo);

ViStatus _VI_FUNC niRFSA_ReadPowerSpectrumF32(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViReal32 powerSpectrumData[],
   ViInt32 dataArraySize,
   niRFSA_spectrumInfo* spectrumInfo);

ViStatus _VI_FUNC niRFSA_GetNumberOfSpectralLines(
   ViSession vi,
   ViConstString channelList,
   ViInt32* numberOfSpectralLines);

/*- Control Functions --------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_Initiate(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_Abort(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_Commit(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_CheckAcquisitionStatus(
   ViSession vi,
   ViBoolean* isDone);

/*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_PerformThermalCorrection(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ExportSignal(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

ViStatus _VI_FUNC niRFSA_GetTerminalName
(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViInt32 bufferSize,
   ViChar terminalName[]);

ViStatus _VI_FUNC niRFSA_SendSoftwareEdgeTrigger(
   ViSession vi,
   ViInt32 trigger,
   ViConstString triggerIdentifier);

ViStatus _VI_FUNC niRFSA_GetSpectralInfoForSMT(
   ViSession vi,
   SmtSpectrumInfo* spectrumInfo);

ViStatus _VI_FUNC niRFSA_GetFrequencyResponse(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   ViReal64 frequencies[],
   ViReal64 magnitudeResponse[],
   ViReal64 phaseResponse[],
   ViInt32* numberOfFrequencies);

ViStatus _VI_FUNC niRFSA_GetDeviceResponse(
   ViSession vi,
   ViConstString channelList,
   ViInt32 responseType,
   ViInt32 bufferSize,
   ViReal64 frequencies[],
   ViReal64 magnitudeResponse[],
   ViReal64 phaseResponse[],
   ViInt32* numberOfFrequencies);

ViStatus _VI_FUNC niRFSA_GetRelayOperationsCount(
   ViSession vi,
   ViConstString channelList,
   ViInt32 operationsCount[],
   ViInt32* bufferSize);

ViStatus _VI_FUNC niRFSA_GetRelayName(
   ViSession vi,
   ViConstString channelList,
   ViInt32 index,
   ViChar name[],
   ViInt32* bufferSize);

ViStatus _VI_FUNC niRFSA_EnableSessionAccess
(
   ViSession vi,
   ViBoolean enable
);


/*-------------------------------- List Mode API ----------------------------------------*/
ViStatus _VI_FUNC niRFSA_CreateConfigurationList(
   ViSession vi,
   ViConstString listName,
   ViInt32 numberOfListAttributes,
   const ViAttr* listAttributeIDs,
   ViBoolean setAsActiveList);

ViStatus _VI_FUNC niRFSA_CreateConfigurationListStep(
   ViSession vi,
   ViBoolean setAsActiveStep);

ViStatus _VI_FUNC niRFSA_DeleteConfigurationList(
   ViSession vi,
   ViConstString listName);

/*- Attributes ---------------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_SetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 value);

ViStatus _VI_FUNC niRFSA_SetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64 value);

ViStatus _VI_FUNC niRFSA_SetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64 value);

ViStatus _VI_FUNC niRFSA_SetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViConstString value);

ViStatus _VI_FUNC niRFSA_SetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean value);

ViStatus _VI_FUNC niRFSA_SetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession value);

ViStatus _VI_FUNC niRFSA_GetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 *value);

ViStatus _VI_FUNC niRFSA_GetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64 *value);

ViStatus _VI_FUNC niRFSA_GetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64 *value) ;

ViStatus _VI_FUNC niRFSA_GetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 bufSize, ViChar value[]);

ViStatus _VI_FUNC niRFSA_GetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean *value);

ViStatus _VI_FUNC niRFSA_GetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession *value);

ViStatus _VI_FUNC niRFSA_ResetAttribute(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId);

/*-------------------------------- Sparameter de-embedding API ----------------------------------------*/

ViStatus _VI_FUNC niRFSA_CreateDeembeddingSparameterTableS2PFile(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   ViConstString s2pFilePath,
   ViInt32 sparameterOrientation);

ViStatus _VI_FUNC niRFSA_CreateDeembeddingSparameterTableArray(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   const ViReal64 frequencies[], ViInt32 frequenciesSize,
   const NIComplexNumber sparameterTable[], ViInt32 sparameterTableSize,
   ViInt32 numberOfPorts,
   ViInt32 sparameterOrientation);

ViStatus _VI_FUNC niRFSA_DeleteDeembeddingTable(
   ViSession vi,
   ViConstString port,
   ViConstString tableName);

ViStatus _VI_FUNC niRFSA_DeleteAllDeembeddingTables(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ConfigureDeembeddingTableInterpolationNearest
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName
);

ViStatus _VI_FUNC niRFSA_ConfigureDeembeddingTableInterpolationLinear
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName,
   ViInt32 format
);

ViStatus _VI_FUNC niRFSA_ConfigureDeembeddingTableInterpolationSpline
(
   ViSession vi,
   ViConstString port,
   ViConstString tableName
);

ViStatus _VI_FUNC niRFSA_GetDeembeddingSparameters
(
   ViSession vi,
   NIComplexNumber *sparameters, ViInt32 sparametersArraySize,
   ViInt32 *numberOfSparameters,
   ViInt32 *numberOfPorts
);

/****************************************************************************
 *--------------------------------- obsolete -------------------------------*
 ****************************************************************************/
#define NIRFSA_ATTR_SPECTRUM_CENTER_FREQUENCY                     /* ViReal64    */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_MINIMUM_QUIET_TIME  /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 58L)
#define NIRFSA_VAL_PXI_CLK10_STR                       "PXI_Clk10"
#define NIRFSA_VAL_LOW                                  NIRFSA_VAL_NARROW
#define NIRFSA_VAL_HIGH                                 NIRFSA_VAL_WIDE
// Create an alias in case someone used the unsupported constant
#define NIRFSA_ATTR_RECONFIGURATION_TRIGGER_SOURCE                          NIRFSA_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE
#define NIRFSA_ATTR_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE                  NIRFSA_ATTR_DIGITAL_EDGE_CONFIGURATION_LIST_STEP_TRIGGER_SOURCE
#define NIRFSA_CAL_TONE_FREQUENCY                                           NIRFSA_ATTR_CAL_TONE_FREQUENCY
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_DOWNCONVERTER_ONLY_MODE      NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_EXTERNAL_DIGITIZER_MODE
#define NIRFSA_ATTR_PRESELECTOR_ENABLED                 NIRFSA_ATTR_DOWNCONVERTER_PRESELECTOR_ENABLED

#define NIRFSA_ATTR_CAL_TONE_MODE                       NIRFSA_ATTR_DOWNCONVERTER_CAL_TONE_MODE
#define NIRFSA_ATTR_CAL_TONE_FREQUENCY                  NIRFSA_ATTR_DOWNCONVERTER_CAL_TONE_FREQUENCY

// Typo created in RFSA 2.5.2
#define NIRFSA_VAL_END_OR_RECORD_EVENT_STR              NIRFSA_VAL_END_OF_RECORD_EVENT_STR

// Added in 14.1. We have the same error description but from different components
#define NIRFSA_WARN_IFDIG_WARN                          NIRFSA_WARN_NISCOPE_WARN
#define NIRFSA_ERROR_IFDIG_ERROR                        NIRFSA_ERROR_NISCOPE_ERROR

// Created RF_CONDITIONING attributes as more general aliases of existing RF_PRESELECTOR attributes
#define NIRFSA_ATTR_RF_PRESELECTOR_CAL_TONE_MODE        NIRFSA_ATTR_RF_CONDITIONING_CAL_TONE_MODE
#define NIRFSA_ATTR_RF_PRESELECTOR_CAL_TONE_FREQUENCY   NIRFSA_ATTR_RF_CONDITIONING_CAL_TONE_FREQUENCY

ViStatus _VI_FUNC niRFSA_SelfCal(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_CalAdjustDownconverterGain(
   ViSession vi,
   ViConstString channelList,
   ViReal64 frequency,
   ViReal64 gain);

ViStatus _VI_FUNC niRFSA_SetUserData
(
   ViSession vi,
   ViConstString identifier,
   ViInt32 bufferSize,
   ViInt8 data[]
);

ViStatus _VI_FUNC niRFSA_GetUserData
(
   ViSession vi,
   ViConstString identifier,
   ViInt32 bufferSize,
   ViInt8 data[],
   ViInt32* actualDataSize
);

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* ___niRFSA_niRFSA_h___ */

