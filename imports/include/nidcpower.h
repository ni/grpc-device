/****************************************************************************
 *              National Instruments DC Power Supplies and SMUs
 *--------------------------------------------------------------------------*
 *      Copyright (c) National Instruments 2020.  All Rights Reserved.      *
 *--------------------------------------------------------------------------*
 *
 * Title:    nidcpower.h
 * Purpose:  National Instruments DC Power Supplies and SMUs Instrument
 *           Driver declarations
 *
 ****************************************************************************/

#ifndef __NIDCPOWER_HEADER
#define __NIDCPOWER_HEADER

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#include <IviDCPwr.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

/******************************************************************************/
/*                   Instrument Driver Revision Information                   */
/******************************************************************************/
#define NIDCPOWER_MAJOR_VERSION               20     /* Instrument driver major version   */
#define NIDCPOWER_MINOR_VERSION                6     /* Instrument driver minor version   */
#define NIDCPOWER_UPDATE_VERSION               0     /* Instrument driver update version  */

#define NIDCPOWER_CLASS_SPEC_MAJOR_VERSION     3     /* Class specification major version */
#define NIDCPOWER_CLASS_SPEC_MINOR_VERSION     0     /* Class specification minor version */


/******************************************************************************/
/*                             Attribute Defines                              */
/******************************************************************************/
#define NIDCPOWER_ATTR_BASE                       IVI_SPECIFIC_PUBLIC_ATTR_BASE
#define NIDCPOWER_ATTR_PRIVATE_BASE               IVI_SPECIFIC_PRIVATE_ATTR_BASE
#define NIDCPOWER_ERROR_BASE                      IVI_SPECIFIC_ERROR_BASE
#define NIDCPOWER_WARN_BASE                       IVI_SPECIFIC_WARN_BASE

/*- User Options -*/
#define NIDCPOWER_ATTR_RANGE_CHECK                                          IVI_ATTR_RANGE_CHECK                              /* ViBoolean device */
#define NIDCPOWER_ATTR_QUERY_INSTRUMENT_STATUS                              IVI_ATTR_QUERY_INSTRUMENT_STATUS                  /* ViBoolean device */
#define NIDCPOWER_ATTR_CACHE                                                IVI_ATTR_CACHE                                    /* ViBoolean device */
#define NIDCPOWER_ATTR_SIMULATE                                             IVI_ATTR_SIMULATE                                 /* ViBoolean device */
#define NIDCPOWER_ATTR_RECORD_COERCIONS                                     IVI_ATTR_RECORD_COERCIONS                         /* ViBoolean device */
#define NIDCPOWER_ATTR_INTERCHANGE_CHECK                                    IVI_ATTR_INTERCHANGE_CHECK                        /* ViBoolean device */

/*- Instrument Capabilities -*/
#define NIDCPOWER_ATTR_CHANNEL_COUNT                                        IVI_ATTR_CHANNEL_COUNT                            /* ViInt32   device  read-only */

/*- Driver Information -*/
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_PREFIX                               IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString  device  read-only */
#define NIDCPOWER_ATTR_SUPPORTED_INSTRUMENT_MODELS                          IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS              /* ViString  device  read-only */
#define NIDCPOWER_ATTR_GROUP_CAPABILITIES                                   IVI_ATTR_GROUP_CAPABILITIES                       /* ViString  device  read-only */
#define NIDCPOWER_ATTR_INSTRUMENT_MANUFACTURER                              IVI_ATTR_INSTRUMENT_MANUFACTURER                  /* ViString  device  read-only */
#define NIDCPOWER_ATTR_INSTRUMENT_MODEL                                     IVI_ATTR_INSTRUMENT_MODEL                         /* ViString  device  read-only */
#define NIDCPOWER_ATTR_INSTRUMENT_FIRMWARE_REVISION                         IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION             /* ViString  device  read-only */
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_REVISION                             IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString  device  read-only */
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_VENDOR                               IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString  device  read-only */
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_DESCRIPTION                          IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString  device  read-only */
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION             IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32   device  read-only */
#define NIDCPOWER_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION             IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32   device  read-only */
#define NIDCPOWER_ATTR_SERIAL_NUMBER                                        NIDCPOWER_ATTR_BASE + 152L                        /* ViString  device  read-only */

/*- Advanced Session Information -*/
#define NIDCPOWER_ATTR_LOGICAL_NAME                                         IVI_ATTR_LOGICAL_NAME                             /* ViString  device  read-only */
#define NIDCPOWER_ATTR_IO_RESOURCE_DESCRIPTOR                               IVI_ATTR_IO_RESOURCE_DESCRIPTOR                   /* ViString  device  read-only */
#define NIDCPOWER_ATTR_DRIVER_SETUP                                         IVI_ATTR_DRIVER_SETUP                             /* ViString  device  read-only */

/*- Source Configuration -*/
#define NIDCPOWER_ATTR_SOURCE_MODE                                          NIDCPOWER_ATTR_BASE + 54L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_OUTPUT_FUNCTION                                      NIDCPOWER_ATTR_BASE + 8L                          /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_OUTPUT_ENABLED                                       IVIDCPWR_ATTR_OUTPUT_ENABLED                      /* ViBoolean multi-channel */
#define NIDCPOWER_ATTR_OUTPUT_CONNECTED                                     NIDCPOWER_ATTR_BASE + 60L                         /* ViBoolean multi-channel */
#define NIDCPOWER_ATTR_OUTPUT_RESISTANCE                                    NIDCPOWER_ATTR_BASE + 61L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_TRANSIENT_RESPONSE                                   NIDCPOWER_ATTR_BASE + 62L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_GAIN_BANDWIDTH                               NIDCPOWER_ATTR_BASE + 67L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_COMPENSATION_FREQUENCY                       NIDCPOWER_ATTR_BASE + 68L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_POLE_ZERO_RATIO                              NIDCPOWER_ATTR_BASE + 69L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_GAIN_BANDWIDTH                               NIDCPOWER_ATTR_BASE + 70L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_COMPENSATION_FREQUENCY                       NIDCPOWER_ATTR_BASE + 71L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_POLE_ZERO_RATIO                              NIDCPOWER_ATTR_BASE + 72L                         /* ViReal64  multi-channel */

/*- DC Voltage Output Function Configuration -*/
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL                                        IVIDCPWR_ATTR_VOLTAGE_LEVEL                       /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT                                        IVIDCPWR_ATTR_CURRENT_LIMIT                       /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL_RANGE                                  NIDCPOWER_ATTR_BASE + 5L                          /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT_RANGE                                  NIDCPOWER_ATTR_BASE + 4L                          /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT_BEHAVIOR                               IVIDCPWR_ATTR_CURRENT_LIMIT_BEHAVIOR              /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LEVEL_AUTORANGE                              NIDCPOWER_ATTR_BASE + 15L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT_AUTORANGE                              NIDCPOWER_ATTR_BASE + 16L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT_HIGH                                   NIDCPOWER_ATTR_BASE + 187L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LIMIT_LOW                                    NIDCPOWER_ATTR_BASE + 188L                        /* ViReal64  multi-channel */

/*- DC Current Output Function Configuration -*/
#define NIDCPOWER_ATTR_CURRENT_LEVEL                                        NIDCPOWER_ATTR_BASE + 9L                          /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT                                        NIDCPOWER_ATTR_BASE + 10L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LEVEL_RANGE                                  NIDCPOWER_ATTR_BASE + 11L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_RANGE                                  NIDCPOWER_ATTR_BASE + 12L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_CURRENT_LEVEL_AUTORANGE                              NIDCPOWER_ATTR_BASE + 17L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_AUTORANGE                              NIDCPOWER_ATTR_BASE + 18L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_HIGH                                   NIDCPOWER_ATTR_BASE + 185L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_VOLTAGE_LIMIT_LOW                                    NIDCPOWER_ATTR_BASE + 186L                        /* ViReal64  multi-channel */

/*- Pulse Voltage Output Function Configuration -*/
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LEVEL                                  NIDCPOWER_ATTR_BASE + 80L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT                                  NIDCPOWER_ATTR_BASE + 81L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LEVEL                             NIDCPOWER_ATTR_BASE + 82L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT                             NIDCPOWER_ATTR_BASE + 83L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LEVEL_RANGE                            NIDCPOWER_ATTR_BASE + 84L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_RANGE                            NIDCPOWER_ATTR_BASE + 85L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_HIGH                             NIDCPOWER_ATTR_BASE + 193L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_CURRENT_LIMIT_LOW                              NIDCPOWER_ATTR_BASE + 194L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT_HIGH                        NIDCPOWER_ATTR_BASE + 195L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LIMIT_LOW                         NIDCPOWER_ATTR_BASE + 196L                        /* ViReal64  multi-channel */

/*- Pulse Current Output Function Configuration -*/
#define NIDCPOWER_ATTR_PULSE_CURRENT_LEVEL                                  NIDCPOWER_ATTR_BASE + 86L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT                                  NIDCPOWER_ATTR_BASE + 87L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_CURRENT_LEVEL                             NIDCPOWER_ATTR_BASE + 88L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT                             NIDCPOWER_ATTR_BASE + 89L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_CURRENT_LEVEL_RANGE                            NIDCPOWER_ATTR_BASE + 90L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_RANGE                            NIDCPOWER_ATTR_BASE + 91L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_HIGH                             NIDCPOWER_ATTR_BASE + 189L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_VOLTAGE_LIMIT_LOW                              NIDCPOWER_ATTR_BASE + 190L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT_HIGH                        NIDCPOWER_ATTR_BASE + 191L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_BIAS_VOLTAGE_LIMIT_LOW                         NIDCPOWER_ATTR_BASE + 192L                        /* ViReal64  multi-channel */

/*- Advanced Source Configuration -*/
#define NIDCPOWER_ATTR_SOURCE_DELAY                                         NIDCPOWER_ATTR_BASE + 51L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_OVERRANGING_ENABLED                                  NIDCPOWER_ATTR_BASE + 7L                          /* ViBoolean device */
#define NIDCPOWER_ATTR_OUTPUT_CAPACITANCE                                   NIDCPOWER_ATTR_BASE + 14L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_SEQUENCE_LOOP_COUNT                                  NIDCPOWER_ATTR_BASE + 25L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_SEQUENCE_LOOP_COUNT_IS_FINITE                        NIDCPOWER_ATTR_BASE + 78L                         /* ViBoolean device */
#define NIDCPOWER_ATTR_COMPLIANCE_LIMIT_SYMMETRY                            NIDCPOWER_ATTR_BASE + 184L                        /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_SEQUENCE_STEP_DELTA_TIME                             NIDCPOWER_ATTR_BASE + 198L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_SEQUENCE_STEP_DELTA_TIME_ENABLED                     NIDCPOWER_ATTR_BASE + 199L                        /* ViBoolean multi-channel */
#define NIDCPOWER_ATTR_ACTUAL_POWER_ALLOCATION                              NIDCPOWER_ATTR_BASE + 205L                        /* ViReal64  multi-channel  read-only */
#define NIDCPOWER_ATTR_REQUESTED_POWER_ALLOCATION                           NIDCPOWER_ATTR_BASE + 206L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_POWER_ALLOCATION_MODE                                NIDCPOWER_ATTR_BASE + 207L                        /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_MERGED_CHANNELS                                      NIDCPOWER_ATTR_BASE + 249L                        /* ViString  multi-channel */

/*- Advanced Pulsing Source Configuration -*/
#define NIDCPOWER_ATTR_PULSE_BIAS_DELAY                                     NIDCPOWER_ATTR_BASE + 92L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_ON_TIME                                        NIDCPOWER_ATTR_BASE + 93L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_PULSE_OFF_TIME                                       NIDCPOWER_ATTR_BASE + 94L                         /* ViReal64  multi-channel */

/*- Over Voltage Protection Configuration -*/
#define NIDCPOWER_ATTR_OVP_ENABLED                                          IVIDCPWR_ATTR_OVP_ENABLED                         /* ViBoolean multi-channel */
#define NIDCPOWER_ATTR_OVP_LIMIT                                            IVIDCPWR_ATTR_OVP_LIMIT                           /* ViReal64  multi-channel */

/*- Measurement Configuration -*/
#define NIDCPOWER_ATTR_SENSE                                                NIDCPOWER_ATTR_BASE + 13L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_AUTO_ZERO                                            NIDCPOWER_ATTR_BASE + 55L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_APERTURE_TIME                                        NIDCPOWER_ATTR_BASE + 58L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_APERTURE_TIME_UNITS                                  NIDCPOWER_ATTR_BASE + 59L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_POWER_LINE_FREQUENCY                                 NIDCPOWER_ATTR_BASE + 20L                         /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_SAMPLES_TO_AVERAGE                                   NIDCPOWER_ATTR_BASE + 3L                          /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_FETCH_BACKLOG                                        NIDCPOWER_ATTR_BASE + 56L                         /* ViInt32   device  read-only */
#define NIDCPOWER_ATTR_AUTORANGE                                            NIDCPOWER_ATTR_BASE + 244L                        /* ViInt32   multi-channel */

/*- Advanced Measurement Configuration -*/
#define NIDCPOWER_ATTR_MEASURE_WHEN                                         NIDCPOWER_ATTR_BASE + 57L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_RESET_AVERAGE_BEFORE_MEASUREMENT                     NIDCPOWER_ATTR_BASE + 6L                          /* ViBoolean multi-channel */
#define NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH                                NIDCPOWER_ATTR_BASE + 63L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_MEASURE_RECORD_LENGTH_IS_FINITE                      NIDCPOWER_ATTR_BASE + 64L                         /* ViBoolean device */
#define NIDCPOWER_ATTR_MEASURE_RECORD_DELTA_TIME                            NIDCPOWER_ATTR_BASE + 65L                         /* ViReal64  device  read-only */
#define NIDCPOWER_ATTR_DC_NOISE_REJECTION                                   NIDCPOWER_ATTR_BASE + 66L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_SELF_CALIBRATION_PERSISTENCE                         NIDCPOWER_ATTR_BASE + 73L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_MEASURE_BUFFER_SIZE                                  NIDCPOWER_ATTR_BASE + 77L                         /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_BEHAVIOR                                   NIDCPOWER_ATTR_BASE + 245L                        /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_APERTURE_TIME_MODE                         NIDCPOWER_ATTR_BASE + 246L                        /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME                      NIDCPOWER_ATTR_BASE + 247L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME_UNITS                NIDCPOWER_ATTR_BASE + 248L                        /* ViInt32   multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_CURRENT_RANGE                      NIDCPOWER_ATTR_BASE + 255L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_MINIMUM_VOLTAGE_RANGE                      NIDCPOWER_ATTR_BASE + 256L                        /* ViReal64  multi-channel */
#define NIDCPOWER_ATTR_AUTORANGE_THRESHOLD_MODE                             NIDCPOWER_ATTR_BASE + 257L                        /* ViInt32   multi-channel */

/*- Start Trigger Configuration -*/
#define NIDCPOWER_ATTR_START_TRIGGER_TYPE                                   NIDCPOWER_ATTR_BASE + 21L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE                      NIDCPOWER_ATTR_BASE + 22L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_INPUT_TERMINAL            NIDCPOWER_ATTR_BASE + 23L                         /* ViString  device */
#define NIDCPOWER_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL               NIDCPOWER_ATTR_BASE + 24L                         /* ViString  device */

/*- Source Trigger Configuration -*/
#define NIDCPOWER_ATTR_SOURCE_TRIGGER_TYPE                                  NIDCPOWER_ATTR_BASE + 30L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_EDGE                     NIDCPOWER_ATTR_BASE + 31L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_INPUT_TERMINAL           NIDCPOWER_ATTR_BASE + 32L                         /* ViString  device */
#define NIDCPOWER_ATTR_EXPORTED_SOURCE_TRIGGER_OUTPUT_TERMINAL              NIDCPOWER_ATTR_BASE + 33L                         /* ViString  device */

/*- Measure Trigger Configuration -*/
#define NIDCPOWER_ATTR_MEASURE_TRIGGER_TYPE                                 NIDCPOWER_ATTR_BASE + 34L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_EDGE                    NIDCPOWER_ATTR_BASE + 35L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_INPUT_TERMINAL          NIDCPOWER_ATTR_BASE + 36L                         /* ViString  device */
#define NIDCPOWER_ATTR_EXPORTED_MEASURE_TRIGGER_OUTPUT_TERMINAL             NIDCPOWER_ATTR_BASE + 37L                         /* ViString  device */

/*- Sequence Advance Trigger Configuration -*/
#define NIDCPOWER_ATTR_SEQUENCE_ADVANCE_TRIGGER_TYPE                        NIDCPOWER_ATTR_BASE + 26L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE           NIDCPOWER_ATTR_BASE + 27L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_INPUT_TERMINAL NIDCPOWER_ATTR_BASE + 28L                         /* ViString  device */
#define NIDCPOWER_ATTR_EXPORTED_SEQUENCE_ADVANCE_TRIGGER_OUTPUT_TERMINAL    NIDCPOWER_ATTR_BASE + 29L                         /* ViString  device */

/*- Source Iteration Complete Event Configuration -*/
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_OUTPUT_TERMINAL                NIDCPOWER_ATTR_BASE + 43L                         /* ViString  device */
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_POLARITY                 NIDCPOWER_ATTR_BASE + 41L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_WIDTH                    NIDCPOWER_ATTR_BASE + 42L                         /* ViReal64  device */

/*- Measure Complete Event Configuration -*/
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_OUTPUT_TERMINAL               NIDCPOWER_ATTR_BASE + 47L                         /* ViString  device */
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_DELAY                         NIDCPOWER_ATTR_BASE + 46L                         /* ViReal64  device */
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_POLARITY                NIDCPOWER_ATTR_BASE + 44L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_WIDTH                   NIDCPOWER_ATTR_BASE + 45L                         /* ViReal64  device */

/*- Sequence Iteration Complete Event Configuration -*/
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_OUTPUT_TERMINAL    NIDCPOWER_ATTR_BASE + 40L                         /* ViString  device */
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY     NIDCPOWER_ATTR_BASE + 38L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_WIDTH        NIDCPOWER_ATTR_BASE + 39L                         /* ViReal64  device */

/*- Sequence Engine Done Event Configuration -*/
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_OUTPUT_TERMINAL           NIDCPOWER_ATTR_BASE + 50L                         /* ViString  device */
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY            NIDCPOWER_ATTR_BASE + 48L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_WIDTH               NIDCPOWER_ATTR_BASE + 49L                         /* ViReal64  device */

/*- Advanced Sequencing -*/
#define NIDCPOWER_ATTR_ACTIVE_ADVANCED_SEQUENCE                             NIDCPOWER_ATTR_BASE + 74L                         /* ViString  multi-channel */
#define NIDCPOWER_ATTR_ACTIVE_ADVANCED_SEQUENCE_STEP                        NIDCPOWER_ATTR_BASE + 75L                         /* ViInt64   multi-channel */

/*- Pulse Trigger -*/
#define NIDCPOWER_ATTR_PULSE_TRIGGER_TYPE                                   NIDCPOWER_ATTR_BASE + 95L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_EDGE                      NIDCPOWER_ATTR_BASE + 96L                         /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_INPUT_TERMINAL            NIDCPOWER_ATTR_BASE + 97L                         /* ViString  device */
#define NIDCPOWER_ATTR_EXPORTED_PULSE_TRIGGER_OUTPUT_TERMINAL               NIDCPOWER_ATTR_BASE + 98L                         /* ViString  device */

/*- Pulse Complete Event Configuration -*/
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_OUTPUT_TERMINAL                 NIDCPOWER_ATTR_BASE + 99L                         /* ViString  device */
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_POLARITY                  NIDCPOWER_ATTR_BASE + 100L                        /* ViInt32   device */
#define NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_WIDTH                     NIDCPOWER_ATTR_BASE + 101L                        /* ViReal64  device */

/*- Ready For Pulse Trigger Event Configuration -*/
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_OUTPUT_TERMINAL        NIDCPOWER_ATTR_BASE + 102L                        /* ViString  device */
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY         NIDCPOWER_ATTR_BASE + 103L                        /* ViInt32   device */
#define NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_WIDTH            NIDCPOWER_ATTR_BASE + 104L                        /* ViReal64  device */

/*- Shutdown Trigger Configuration -*/
#define NIDCPOWER_ATTR_SHUTDOWN_TRIGGER_TYPE                                NIDCPOWER_ATTR_BASE + 275L                        /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE                   NIDCPOWER_ATTR_BASE + 276L                        /* ViInt32   device */
#define NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_INPUT_TERMINAL         NIDCPOWER_ATTR_BASE + 277L                        /* ViString  device */

/*- Interlock State -*/
#define NIDCPOWER_ATTR_INTERLOCK_INPUT_OPEN                                 NIDCPOWER_ATTR_BASE + 105L                        /* ViBoolean device  read-only */

/*- Advanced Instrument Configuration -*/
#define NIDCPOWER_ATTR_POWER_SOURCE                                         NIDCPOWER_ATTR_BASE + 0L                          /* ViInt32   device */
#define NIDCPOWER_ATTR_POWER_SOURCE_IN_USE                                  NIDCPOWER_ATTR_BASE + 1L                          /* ViInt32   device  read-only */
#define NIDCPOWER_ATTR_AUXILIARY_POWER_SOURCE_AVAILABLE                     NIDCPOWER_ATTR_BASE + 2L                          /* ViBoolean device  read-only */

/******************************************************************************/
/*                          Attribute Value Defines                           */
/******************************************************************************/
#define NIDCPOWER_VAL_BASE                                (1000L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_CURRENT_LIMIT_BEHAVIOR -*/
#define NIDCPOWER_VAL_CURRENT_REGULATE                      IVIDCPWR_VAL_CURRENT_REGULATE
#define NIDCPOWER_VAL_CURRENT_TRIP                          IVIDCPWR_VAL_CURRENT_TRIP

/*- Defined values for RangeType parameter of function -*/
/*-   ConfigureOutputRange -*/
#define NIDCPOWER_VAL_RANGE_CURRENT                         IVIDCPWR_VAL_RANGE_CURRENT
#define NIDCPOWER_VAL_RANGE_VOLTAGE                         IVIDCPWR_VAL_RANGE_VOLTAGE

/*- Defined values for OutputState parameter of function -*/
/*-   QueryOutputState -*/
#define NIDCPOWER_VAL_OUTPUT_CONSTANT_VOLTAGE               IVIDCPWR_VAL_OUTPUT_CONSTANT_VOLTAGE
#define NIDCPOWER_VAL_OUTPUT_CONSTANT_CURRENT               IVIDCPWR_VAL_OUTPUT_CONSTANT_CURRENT
#define NIDCPOWER_VAL_OUTPUT_OVER_VOLTAGE                   IVIDCPWR_VAL_OUTPUT_OVER_VOLTAGE
#define NIDCPOWER_VAL_OUTPUT_OVER_CURRENT                   IVIDCPWR_VAL_OUTPUT_OVER_CURRENT
#define NIDCPOWER_VAL_OUTPUT_UNREGULATED                    IVIDCPWR_VAL_OUTPUT_UNREGULATED

/*- Defined values for MeasurementType parameter of function -*/
/*-   Measure -*/
#define NIDCPOWER_VAL_MEASURE_CURRENT                       IVIDCPWR_VAL_MEASURE_CURRENT
#define NIDCPOWER_VAL_MEASURE_VOLTAGE                       IVIDCPWR_VAL_MEASURE_VOLTAGE

/*- Defined values for Action parameter of function -*/
/*-   CloseExtCal -*/
#define NIDCPOWER_VAL_CANCEL                                (NIDCPOWER_VAL_BASE + 1L)
#define NIDCPOWER_VAL_COMMIT                                (NIDCPOWER_VAL_BASE + 2L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_POWER_SOURCE -*/
/*-   NIDCPOWER_ATTR_POWER_SOURCE_IN_USE -*/
#define NIDCPOWER_VAL_INTERNAL                              (NIDCPOWER_VAL_BASE + 3L)
#define NIDCPOWER_VAL_AUXILIARY                             (NIDCPOWER_VAL_BASE + 4L)
#define NIDCPOWER_VAL_AUTOMATIC                             (NIDCPOWER_VAL_BASE + 5L)

/*- Defined values for OutputFunction parameter of function -*/
/*-   ConfigureOutputFunction -*/
/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_OUTPUT_FUNCTION -*/
#define NIDCPOWER_VAL_DC_VOLTAGE                            (NIDCPOWER_VAL_BASE + 6L)
#define NIDCPOWER_VAL_DC_CURRENT                            (NIDCPOWER_VAL_BASE + 7L)
#define NIDCPOWER_VAL_PULSE_VOLTAGE                         (NIDCPOWER_VAL_BASE + 49L)
#define NIDCPOWER_VAL_PULSE_CURRENT                         (NIDCPOWER_VAL_BASE + 50L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_SENSE -*/
#define NIDCPOWER_VAL_LOCAL                                 (NIDCPOWER_VAL_BASE + 8L)
#define NIDCPOWER_VAL_REMOTE                                (NIDCPOWER_VAL_BASE + 9L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_OUTPUT_CAPACITANCE -*/
#define NIDCPOWER_VAL_LOW                                   (NIDCPOWER_VAL_BASE + 10L)
#define NIDCPOWER_VAL_HIGH                                  (NIDCPOWER_VAL_BASE + 11L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_START_TRIGGER_TYPE -*/
/*-   NIDCPOWER_ATTR_SOURCE_TRIGGER_TYPE -*/
/*-   NIDCPOWER_ATTR_MEASURE_TRIGGER_TYPE -*/
/*-   NIDCPOWER_ATTR_SEQUENCE_ADVANCE_TRIGGER_TYPE -*/
/*-   NIDCPOWER_ATTR_PULSE_TRIGGER_TYPE -*/
/*-   NIDCPOWER_ATTR_SHUTDOWN_TRIGGER_TYPE -*/
#define NIDCPOWER_VAL_NONE                                  (NIDCPOWER_VAL_BASE + 12L)
#define NIDCPOWER_VAL_DIGITAL_EDGE                          (NIDCPOWER_VAL_BASE + 14L)
#define NIDCPOWER_VAL_SOFTWARE_EDGE                         (NIDCPOWER_VAL_BASE + 15L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_SOURCE_TRIGGER_EDGE -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_MEASURE_TRIGGER_EDGE -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_SEQUENCE_ADVANCE_TRIGGER_EDGE -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_PULSE_TRIGGER_EDGE -*/
/*-   NIDCPOWER_ATTR_DIGITAL_EDGE_SHUTDOWN_TRIGGER_EDGE -*/
#define NIDCPOWER_VAL_RISING                                (NIDCPOWER_VAL_BASE + 16L)
#define NIDCPOWER_VAL_FALLING                               (NIDCPOWER_VAL_BASE + 17L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_SOURCE_COMPLETE_EVENT_PULSE_POLARITY -*/
/*-   NIDCPOWER_ATTR_MEASURE_COMPLETE_EVENT_PULSE_POLARITY -*/
/*-   NIDCPOWER_ATTR_SEQUENCE_ITERATION_COMPLETE_EVENT_PULSE_POLARITY -*/
/*-   NIDCPOWER_ATTR_SEQUENCE_ENGINE_DONE_EVENT_PULSE_POLARITY -*/
/*-   NIDCPOWER_ATTR_PULSE_COMPLETE_EVENT_PULSE_POLARITY -*/
/*-   NIDCPOWER_ATTR_READY_FOR_PULSE_TRIGGER_EVENT_PULSE_POLARITY -*/
#define NIDCPOWER_VAL_ACTIVE_HIGH                           (NIDCPOWER_VAL_BASE + 18L)
#define NIDCPOWER_VAL_ACTIVE_LOW                            (NIDCPOWER_VAL_BASE + 19L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_SOURCE_MODE -*/
#define NIDCPOWER_VAL_SINGLE_POINT                          (NIDCPOWER_VAL_BASE + 20L)
#define NIDCPOWER_VAL_SEQUENCE                              (NIDCPOWER_VAL_BASE + 21L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_VOLTAGE_LEVEL_AUTORANGE -*/
/*-   NIDCPOWER_ATTR_CURRENT_LIMIT_AUTORANGE -*/
/*-   NIDCPOWER_ATTR_CURRENT_LEVEL_AUTORANGE -*/
/*-   NIDCPOWER_ATTR_VOLTAGE_LIMIT_AUTORANGE -*/
/*-   NIDCPOWER_ATTR_AUTO_ZERO -*/
/*-   NIDCPOWER_ATTR_AUTORANGE -*/
#define NIDCPOWER_VAL_OFF                                   (0L)
#define NIDCPOWER_VAL_ONCE                                  (NIDCPOWER_VAL_BASE + 24L)
#define NIDCPOWER_VAL_ON                                    (1L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_MEASURE_WHEN -*/
#define NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE   (NIDCPOWER_VAL_BASE + 25L)
#define NIDCPOWER_VAL_ON_DEMAND                             (NIDCPOWER_VAL_BASE + 26L)
#define NIDCPOWER_VAL_ON_MEASURE_TRIGGER                    (NIDCPOWER_VAL_BASE + 27L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_POWER_LINE_FREQUENCY -*/
#define NIDCPOWER_VAL_50_HERTZ                              (50.0)
#define NIDCPOWER_VAL_60_HERTZ                              (60.0)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_APERTURE_TIME_UNITS -*/
/*-   NIDCPOWER_ATTR_AUTORANGE_MINIMUM_APERTURE_TIME_UNITS -*/
#define NIDCPOWER_VAL_SECONDS                               (NIDCPOWER_VAL_BASE + 28L)
#define NIDCPOWER_VAL_POWER_LINE_CYCLES                     (NIDCPOWER_VAL_BASE + 29L)

/*- Defined values for Signal parameter of function -*/
/*-   ExportSignal -*/
#define NIDCPOWER_VAL_SOURCE_COMPLETE_EVENT                 (NIDCPOWER_VAL_BASE + 30L)
#define NIDCPOWER_VAL_MEASURE_COMPLETE_EVENT                (NIDCPOWER_VAL_BASE + 31L)
#define NIDCPOWER_VAL_SEQUENCE_ITERATION_COMPLETE_EVENT     (NIDCPOWER_VAL_BASE + 32L)
#define NIDCPOWER_VAL_SEQUENCE_ENGINE_DONE_EVENT            (NIDCPOWER_VAL_BASE + 33L)
#define NIDCPOWER_VAL_PULSE_COMPLETE_EVENT                  (NIDCPOWER_VAL_BASE + 51L)
#define NIDCPOWER_VAL_READY_FOR_PULSE_TRIGGER_EVENT         (NIDCPOWER_VAL_BASE + 52L)
#define NIDCPOWER_VAL_START_TRIGGER                         (NIDCPOWER_VAL_BASE + 34L)
#define NIDCPOWER_VAL_SOURCE_TRIGGER                        (NIDCPOWER_VAL_BASE + 35L)
#define NIDCPOWER_VAL_MEASURE_TRIGGER                       (NIDCPOWER_VAL_BASE + 36L)
#define NIDCPOWER_VAL_SEQUENCE_ADVANCE_TRIGGER              (NIDCPOWER_VAL_BASE + 37L)
#define NIDCPOWER_VAL_PULSE_TRIGGER                         (NIDCPOWER_VAL_BASE + 53L)
#define NIDCPOWER_VAL_SHUTDOWN_TRIGGER                      (NIDCPOWER_VAL_BASE + 118L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_TRANSIENT_RESPONSE -*/
#define NIDCPOWER_VAL_NORMAL                                (NIDCPOWER_VAL_BASE + 38L)
#define NIDCPOWER_VAL_FAST                                  (NIDCPOWER_VAL_BASE + 39L)
#define NIDCPOWER_VAL_SLOW                                  (NIDCPOWER_VAL_BASE + 41L)
#define NIDCPOWER_VAL_CUSTOM                                (NIDCPOWER_VAL_BASE + 42L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_DC_NOISE_REJECTION -*/
#define NIDCPOWER_VAL_DC_NOISE_REJECTION_NORMAL             (NIDCPOWER_VAL_BASE + 44L)
#define NIDCPOWER_VAL_DC_NOISE_REJECTION_SECOND_ORDER       (NIDCPOWER_VAL_BASE + 43L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_SELF_CALIBRATION_PERSISTENCE -*/
#define NIDCPOWER_VAL_KEEP_IN_MEMORY                        (NIDCPOWER_VAL_BASE + 45L)
#define NIDCPOWER_VAL_WRITE_TO_EEPROM                       (NIDCPOWER_VAL_BASE + 46L)

/*- Defined values for InternalReference parameter of function -*/
/*-   ConnectInternalReference, CalAdjustInternalReference -*/
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_5V                 (NIDCPOWER_VAL_BASE + 54L)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_100KOHM            (NIDCPOWER_VAL_BASE + 55L)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_GROUND             (NIDCPOWER_VAL_BASE + 56L)
#define NIDCPOWER_VAL_INTERNAL_REFERENCE_NONE               (NIDCPOWER_VAL_BASE + 57L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_COMPLIANCE_LIMIT_SYMMETRY -*/
#define NIDCPOWER_VAL_COMPLIANCE_LIMIT_SYMMETRY_SYMMETRIC   (0L)
#define NIDCPOWER_VAL_COMPLIANCE_LIMIT_SYMMETRY_ASYMMETRIC  (1L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_POWER_ALLOCATION_MODE -*/
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_DISABLED        (NIDCPOWER_VAL_BASE + 58L)
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_AUTOMATIC       (NIDCPOWER_VAL_BASE + 59L)
#define NIDCPOWER_VAL_POWER_ALLOCATION_MODE_MANUAL          (NIDCPOWER_VAL_BASE + 60L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_AUTORANGE_BEHAVIOR -*/
#define NIDCPOWER_VAL_RANGE_UP_TO_LIMIT_THEN_DOWN           (NIDCPOWER_VAL_BASE + 107L)
#define NIDCPOWER_VAL_RANGE_UP                              (NIDCPOWER_VAL_BASE + 108L)
#define NIDCPOWER_VAL_RANGE_UP_AND_DOWN                     (NIDCPOWER_VAL_BASE + 109L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_AUTORANGE_APERTURE_TIME_MODE -*/
#define NIDCPOWER_VAL_APERTURE_TIME_AUTO                    (NIDCPOWER_VAL_BASE + 110L)
#define NIDCPOWER_VAL_APERTURE_TIME_CUSTOM                  (NIDCPOWER_VAL_BASE + 111L)

/*- Defined values for attributes -*/
/*-   NIDCPOWER_ATTR_AUTORANGE_THRESHOLD_MODE -*/
#define NIDCPOWER_VAL_THRESHOLD_MODE_NORMAL                 (NIDCPOWER_VAL_BASE + 112L)
#define NIDCPOWER_VAL_THRESHOLD_MODE_FAST_STEP              (NIDCPOWER_VAL_BASE + 113L)
#define NIDCPOWER_VAL_THRESHOLD_MODE_HIGH_HYSTERESIS        (NIDCPOWER_VAL_BASE + 114L)
#define NIDCPOWER_VAL_THRESHOLD_MODE_MEDIUM_HYSTERESIS      (NIDCPOWER_VAL_BASE + 115L)
#define NIDCPOWER_VAL_THRESHOLD_MODE_HOLD                   (NIDCPOWER_VAL_BASE + 116L)


/******************************************************************************/
/*                  Instrument Driver Function Declarations                   */
/******************************************************************************/

   /*- Initialize and Close Functions -*/
   ViStatus _VI_FUNC niDCPower_InitializeWithChannels(
      ViRsrc resourceName,
      ViConstString channels,
      ViBoolean reset,
      ViConstString optionString,
      ViSession *vi);

   ViStatus _VI_FUNC niDCPower_InitializeWithIndependentChannels(
      ViRsrc resourceName,
      ViBoolean reset,
      ViConstString optionString,
      ViSession *vi);

   ViStatus _VI_FUNC niDCPower_close(
      ViSession vi);

   /*- Source -*/
   ViStatus _VI_FUNC niDCPower_ConfigureSourceMode(
      ViSession vi,
      ViInt32 sourceMode);

   ViStatus _VI_FUNC niDCPower_ConfigureSourceModeWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViInt32 sourceMode);

   ViStatus _VI_FUNC niDCPower_ConfigureOutputFunction(
      ViSession vi,
      ViConstString channelName,
      ViInt32 outputFunction);

   ViStatus _VI_FUNC niDCPower_ConfigureOutputEnabled(
      ViSession vi,
      ViConstString channelName,
      ViBoolean enabled);

   ViStatus _VI_FUNC niDCPower_SetSequence(
      ViSession vi,
      ViConstString channelName,
      const ViReal64 values[],
      const ViReal64 sourceDelays[],
      ViUInt32 size);

   /*- DC Voltage -*/
   ViStatus _VI_FUNC niDCPower_ConfigureVoltageLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigureCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViInt32 behavior,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigureVoltageLevelRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   ViStatus _VI_FUNC niDCPower_ConfigureCurrentLimitRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   ViStatus _VI_FUNC niDCPower_ConfigureOutputResistance(
      ViSession vi,
      ViConstString channelName,
      ViReal64 resistance);

   /*- DC Current -*/
   ViStatus _VI_FUNC niDCPower_ConfigureCurrentLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigureCurrentLevelRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   ViStatus _VI_FUNC niDCPower_ConfigureVoltageLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigureVoltageLimitRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   /*- Pulse Voltage -*/
   ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasVoltageLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLevelRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLimitRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   /*- Pulse Current -*/
   ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasCurrentLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 level);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseBiasVoltageLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 limit);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseCurrentLevelRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   ViStatus _VI_FUNC niDCPower_ConfigurePulseVoltageLimitRange(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range);

   /*- Advanced Sequencing */
   ViStatus _VI_FUNC niDCPower_CreateAdvancedSequence(
      ViSession vi,
      ViConstString sequenceName,
      ViInt32 attributeIDCount,
      const ViInt32 attributeIDs[],
      ViBoolean setAsActiveSequence);

   ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString sequenceName,
      ViInt32 attributeIDCount,
      const ViInt32 attributeIDs[],
      ViBoolean setAsActiveSequence);

   ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceStep(
      ViSession vi,
      ViBoolean setAsActiveStep);

   ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceStepWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViBoolean setAsActiveStep);

   ViStatus _VI_FUNC niDCPower_CreateAdvancedSequenceCommitStepWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViBoolean setAsActiveStep);

   ViStatus _VI_FUNC niDCPower_DeleteAdvancedSequence(
      ViSession vi,
      ViConstString sequenceName);

   ViStatus _VI_FUNC niDCPower_DeleteAdvancedSequenceWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString sequenceName);

   /*- Measure */
   ViStatus _VI_FUNC niDCPower_ConfigureApertureTime(
      ViSession vi,
      ViConstString channelName,
      ViReal64 apertureTime,
      ViInt32 units);

   ViStatus _VI_FUNC niDCPower_ConfigureAutoZero(
      ViSession vi,
      ViConstString channelName,
      ViInt32 autoZero);

   ViStatus _VI_FUNC niDCPower_ConfigurePowerLineFrequency(
      ViSession vi,
      ViReal64 powerLineFrequency);

   ViStatus _VI_FUNC niDCPower_ConfigureSense(
      ViSession vi,
      ViConstString channelName,
      ViInt32 sense);

   ViStatus _VI_FUNC niDCPower_Measure(
      ViSession vi,
      ViConstString channelName,
      ViInt32 measurementType,
      ViReal64* measurement);

   ViStatus _VI_FUNC niDCPower_MeasureMultiple(
      ViSession vi,
      ViConstString channelName,
      ViReal64 voltageMeasurements[],
      ViReal64 currentMeasurements[]);

   ViStatus _VI_FUNC niDCPower_FetchMultiple(
      ViSession vi,
      ViConstString channelName,
      ViReal64 timeout,
      ViInt32 count,
      ViReal64 voltageMeasurements[],
      ViReal64 currentMeasurements[],
      ViBoolean inCompliance[],
      ViInt32* actualCount);
   ViStatus _VI_FUNC niDCPower_QueryInCompliance(
      ViSession vi,
      ViConstString channelName,
      ViBoolean *inCompliance);

   ViStatus _VI_FUNC niDCPower_QueryOutputState(
      ViSession vi,
      ViConstString channelName,
      ViInt32 outputState,
      ViBoolean* inState);

   /*- Control -*/
   ViStatus _VI_FUNC niDCPower_Commit(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_CommitWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_Initiate(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_InitiateWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_Abort(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_AbortWithChannels(
      ViSession vi,
      ViConstString channelName);

   /*- Query -*/
   ViStatus _VI_FUNC niDCPower_QueryMaxCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 voltageLevel,
      ViReal64* maxCurrentLimit);

   ViStatus _VI_FUNC niDCPower_QueryMaxVoltageLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 currentLimit,
      ViReal64* maxVoltageLevel);

   ViStatus _VI_FUNC niDCPower_QueryMinCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 voltageLevel,
      ViReal64* minCurrentLimit);

   /*- Calibration Functions -*/
   ViStatus _VI_FUNC niDCPower_InitExtCal(
      ViRsrc resourceName,
      ViConstString password,
      ViSession *vi);

   ViStatus _VI_FUNC niDCPower_CloseExtCal(
      ViSession vi,
      ViInt32 action);

   ViStatus _VI_FUNC niDCPower_CalAdjustVoltageLevel(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range,
      ViUInt32 numberOfMeasurements,
      const ViReal64 requestedOutputs[],
      const ViReal64 measuredOutputs[]);

   ViStatus _VI_FUNC niDCPower_CalAdjustVoltageMeasurement(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range,
      ViUInt32 numberOfMeasurements,
      const ViReal64 reportedOutputs[],
      const ViReal64 measuredOutputs[]);

   ViStatus _VI_FUNC niDCPower_CalAdjustCurrentLimit(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range,
      ViUInt32 numberOfMeasurements,
      const ViReal64 requestedOutputs[],
      const ViReal64 measuredOutputs[]);

   ViStatus _VI_FUNC niDCPower_CalAdjustCurrentMeasurement(
      ViSession vi,
      ViConstString channelName,
      ViReal64 range,
      ViUInt32 numberOfMeasurements,
      const ViReal64 reportedOutputs[],
      const ViReal64 measuredOutputs[]);

   ViStatus _VI_FUNC niDCPower_CalAdjustOutputResistance(
      ViSession vi,
      ViConstString channelName,
      ViUInt32 numberOfValues,
      const ViReal64 requestedOutputs[],
      const ViReal64 measuredOutputs[]);

   ViStatus _VI_FUNC niDCPower_CalAdjustResidualVoltageOffset(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_CalAdjustResidualCurrentOffset(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConnectInternalReference(
      ViSession vi,
      ViInt32 internalReference);

   ViStatus _VI_FUNC niDCPower_CalAdjustInternalReference(
      ViSession vi,
      ViInt32 internalReference,
      ViReal64 internalReferenceValue);

   ViStatus _VI_FUNC niDCPower_CalSelfCalibrate(
      ViSession vi,
      ViConstString channelName);

   /*- Calibration Utility Functions -*/
   ViStatus _VI_FUNC niDCPower_ChangeExtCalPassword(
      ViSession vi,
      ViConstString oldPassword,
      ViConstString newPassword);

   ViStatus _VI_FUNC niDCPower_GetExtCalRecommendedInterval(
      ViSession vi,
      ViInt32* months);

   ViStatus _VI_FUNC niDCPower_GetExtCalLastDateAndTime(
      ViSession vi,
      ViInt32* year,
      ViInt32* month,
      ViInt32* day,
      ViInt32* hour,
      ViInt32* minute);

   ViStatus _VI_FUNC niDCPower_GetCalUserDefinedInfoMaxSize(
      ViSession vi,
      ViInt32* infoSize);

   ViStatus _VI_FUNC niDCPower_SetCalUserDefinedInfo(
      ViSession vi,
      ViConstString info);

   ViStatus _VI_FUNC niDCPower_GetCalUserDefinedInfo(
      ViSession vi,
      ViString info);

   ViStatus _VI_FUNC niDCPower_ReadCurrentTemperature(
      ViSession vi,
      ViReal64* temperature);

   ViStatus _VI_FUNC niDCPower_GetExtCalLastTemp(
      ViSession vi,
      ViReal64* temperature);

   ViStatus _VI_FUNC niDCPower_GetSelfCalLastDateAndTime(
      ViSession vi,
      ViInt32* year,
      ViInt32* month,
      ViInt32* day,
      ViInt32* hour,
      ViInt32* minute);

   ViStatus _VI_FUNC niDCPower_GetSelfCalLastTemp(
      ViSession vi,
      ViReal64* temperature);

   /*- Triggers and Events Functions -*/
   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeStartTrigger(
      ViSession vi,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeStartTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeStartTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeStartTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_DisableStartTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_DisableStartTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSequenceAdvanceTrigger(
      ViSession vi,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSequenceAdvanceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSequenceAdvanceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_DisableSequenceAdvanceTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_DisableSequenceAdvanceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSourceTrigger(
      ViSession vi,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeSourceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSourceTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeSourceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_DisableSourceTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_DisableSourceTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeMeasureTrigger(
      ViSession vi,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeMeasureTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeMeasureTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeMeasureTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgePulseTrigger(
      ViSession vi,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgePulseTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgePulseTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgePulseTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_DisablePulseTrigger(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_DisablePulseTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ConfigureDigitalEdgeShutdownTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViConstString inputTerminal,
      ViInt32 edge);

   ViStatus _VI_FUNC niDCPower_ConfigureSoftwareEdgeShutdownTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_DisableShutdownTriggerWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ExportSignal(
      ViSession vi,
      ViInt32 signal,
      ViConstString signalIdentifier,
      ViConstString outputTerminal);

   ViStatus _VI_FUNC niDCPower_ExportSignalWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViInt32 signal,
      ViConstString signalIdentifier,
      ViConstString outputTerminal);

   ViStatus _VI_FUNC niDCPower_SendSoftwareEdgeTrigger(
      ViSession vi,
      ViInt32 trigger);

   ViStatus _VI_FUNC niDCPower_SendSoftwareEdgeTriggerWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViInt32 trigger);

   ViStatus _VI_FUNC niDCPower_WaitForEvent(
      ViSession vi,
      ViInt32 eventId,
      ViReal64 timeout);

   ViStatus _VI_FUNC niDCPower_WaitForEventWithChannels(
      ViSession vi,
      ViConstString channelName,
      ViInt32 eventId,
      ViReal64 timeout);

   /*- Utility Functions -*/
   ViStatus _VI_FUNC niDCPower_Disable(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_reset(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ResetWithChannels(
      ViSession vi,
      ViConstString channelName);

   ViStatus _VI_FUNC niDCPower_ResetDevice(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_self_test(
      ViSession vi,
      ViInt16 *testResult,
      ViChar testMessage[]);

   /*- Other IVI Utility Functions -*/
   ViStatus _VI_FUNC niDCPower_revision_query(
      ViSession vi,
      ViChar instrumentDriverRevision[],
      ViChar firmwareRevision[]);

   ViStatus _VI_FUNC niDCPower_ResetWithDefaults(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_GetChannelName(
      ViSession vi,
      ViInt32 index,
      ViInt32 bufferSize,
      ViChar name[]);

   ViStatus _VI_FUNC niDCPower_GetChannelNameFromString(
      ViSession vi,
      ViConstString index,
      ViInt32 bufferSize,
      ViChar name[]);

   ViStatus _VI_FUNC niDCPower_GetNextCoercionRecord(
      ViSession vi,
      ViInt32 bufferSize,
      ViChar record[]);

   ViStatus _VI_FUNC niDCPower_ClearInterchangeWarnings(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ResetInterchangeCheck(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_GetNextInterchangeWarning(
      ViSession vi,
      ViInt32 bufferSize,
      ViChar warnString[]);

   ViStatus _VI_FUNC niDCPower_InvalidateAllAttributes(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_ConfigureOVP(
      ViSession vi,
      ViConstString channelName,
      ViBoolean enabled,
      ViReal64 limit);

      /*- Error Info Utility Functions -*/
   ViStatus _VI_FUNC niDCPower_GetError(
      ViSession vi, ViStatus *errorCode,
      ViInt32 bufferSize,
      ViChar description[]);

   ViStatus _VI_FUNC niDCPower_ClearError(
      ViSession vi);

   ViStatus _VI_FUNC niDCPower_error_message(
      ViSession vi,
      ViStatus errorCode,
      ViChar errorMessage[256]);

   ViStatus _VI_FUNC niDCPower_error_query(
      ViSession vi,
      ViInt32 *errorCode,
      ViChar errorMessage[]);

      /*- Locking Utility Functions -*/
   ViStatus _VI_FUNC niDCPower_LockSession(
      ViSession vi,
      ViBoolean *callerHasLock);

   ViStatus _VI_FUNC niDCPower_UnlockSession(
      ViSession vi,
      ViBoolean *callerHasLock);

   /*- Set and Get Attribute Functions -*/
   ViStatus _VI_FUNC niDCPower_SetAttributeViInt32(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViInt32 value);

   ViStatus _VI_FUNC niDCPower_SetAttributeViInt64(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViInt64 value);

   ViStatus _VI_FUNC niDCPower_SetAttributeViReal64(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViReal64 value);

   ViStatus _VI_FUNC niDCPower_SetAttributeViString(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViConstString value);

   ViStatus _VI_FUNC niDCPower_SetAttributeViSession(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViSession value);

   ViStatus _VI_FUNC niDCPower_SetAttributeViBoolean(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViBoolean value);

   ViStatus _VI_FUNC niDCPower_GetAttributeViInt32(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViInt32 *value);

   ViStatus _VI_FUNC niDCPower_GetAttributeViInt64(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViInt64 *value);

   ViStatus _VI_FUNC niDCPower_GetAttributeViReal64(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViReal64 *value);

   ViStatus _VI_FUNC niDCPower_GetAttributeViString(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViInt32 bufSize,
      ViChar value[]);

   ViStatus _VI_FUNC niDCPower_GetAttributeViSession(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViSession *value);

   ViStatus _VI_FUNC niDCPower_GetAttributeViBoolean(
      ViSession vi,
      ViConstString channelName,
      ViAttr attribute,
      ViBoolean *value);

   /*- Import and Export Attribute Configuration Functions -*/
   ViStatus _VI_FUNC niDCPower_ImportAttributeConfigurationFile(
      ViSession vi,
      ViConstString filePath);

   ViStatus _VI_FUNC niDCPower_ExportAttributeConfigurationFile(
      ViSession vi,
      ViConstString filePath);

   ViStatus _VI_FUNC niDCPower_ImportAttributeConfigurationBuffer(
      ViSession vi,
      ViInt32 size,
      ViAddr configuration);

   ViStatus _VI_FUNC niDCPower_ExportAttributeConfigurationBuffer(
      ViSession vi,
      ViInt32 size,
      ViAddr configuration);

#include "nidcpowerObsolete.h"

/******************************************************************************/
/*                              End Include File                              */
/******************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NIDCPOWER_HEADER */

