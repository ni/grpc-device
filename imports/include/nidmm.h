/*****************************************************************************
 *                            N I - D M M
 *----------------------------------------------------------------------------
 *    Copyright (c) National Instruments 2020.  All Rights Reserved.
 *----------------------------------------------------------------------------
 *
 * Title:       nidmm.h
 * Purpose:     NiDmm Class value, attribute Id, and function declarations.
 *
 * National Instruments, Austin Texas
 * PH. (800)433-3488
 * Website  http://www.ni.com
 *
 *****************************************************************************/

#ifndef __NIDMM__HEADER
   #define __NIDMM__HEADER

   #if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
   #endif

   /******************************************************************************/
   /*                               Include Files                                */
   /******************************************************************************/

   #define IVI_DO_NOT_INCLUDE_VISA_HEADERS
   #include "IviDmm.h"
   #include "ivi.h"
   #undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

   #ifdef _CVI_
      #pragma EnableLibraryRuntimeChecking
   #endif


   /******************************************************************************/
   /*                         Version/Revision Constants                         */
   /******************************************************************************/

   #define NIDMM_MAJOR_VERSION                 20
   #define NIDMM_MINOR_VERSION                 1

   #define NIDMM_CLASS_SPEC_MAJOR_VERSION      4
   #define NIDMM_CLASS_SPEC_MINOR_VERSION      1

   #define NIDMM_ATTR_BASE                     IVI_SPECIFIC_PUBLIC_ATTR_BASE
   #define NIDMM_ATTR_PRIVATE_BASE             IVI_SPECIFIC_PRIVATE_ATTR_BASE
   #define NIDMM_ERROR_BASE                    IVI_SPECIFIC_ERROR_BASE
   #define NIDMM_WARN_BASE                     IVI_SPECIFIC_WARN_BASE

   // additional status base
   #define NIDMM_ERROR_EXT_STATUS_BASE         (NIDMM_ERROR_BASE + 0x0F00)
   #define NIDMM_ERROR_EXTCAL_ERROR_BASE       (NIDMM_ERROR_BASE + 0x0200)

   // additional warning base
   #define NIDMM_WARN_EXT_STATUS_BASE          (NIDMM_WARN_BASE + 0x0F00)
   #define NIDMM_WARN_EXTCAL_WARN_BASE         (NIDMM_WARN_BASE + 0x0200)

   #define NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE    IVIDMM_VAL_FUNC_SPECIFIC_EXT_BASE
   #define NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE   IVIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE

   /******************************************************************************/
   /*                     Instrument Specific Warning Codes                      */
   /******************************************************************************/

   #define NIDMM_WARN_NOT_SUPPORTED            (NIDMM_WARN_BASE  +  0L) // 0x3FFA4000  1073364992
   #define NIDMM_WARN_SIMULATING               (NIDMM_WARN_BASE  +  1L) // 0x3FFA4001  1073364993
   #define NIDMM_WARN_RANGE_INVALIDATED        (NIDMM_WARN_BASE  +  2L) // 0x3FFA4002  1073364994

   // additional warnings
   #define NIDMM_WARN_UNDERRANGE               (NIDMM_WARN_EXT_STATUS_BASE + 0x80) // 0x3FFA4F80 1073368960
   #define NIDMM_WARN_OVERRANGE                IVIDMM_WARN_OVER_RANGE

   #define NIDMM_WARN_EXTCAL_SELF_CAL_NEEDED          (NIDMM_WARN_EXTCAL_WARN_BASE + 0L)
   #define NIDMM_WARN_EXTCAL_BUFFER_TRUNCATED         (NIDMM_WARN_EXTCAL_WARN_BASE + 1L)

   /******************************************************************************/
   /*                                 Attributes                                 */
   /******************************************************************************/
   /*- User Options -*/
   #define NIDMM_ATTR_RANGE_CHECK                              IVI_ATTR_RANGE_CHECK                              /* ViBoolean */
   #define NIDMM_ATTR_QUERY_INSTRUMENT_STATUS                  IVI_ATTR_QUERY_INSTRUMENT_STATUS                  /* ViBoolean */
   #define NIDMM_ATTR_CACHE                                    IVI_ATTR_CACHE                                    /* ViBoolean */
   #define NIDMM_ATTR_SIMULATE                                 IVI_ATTR_SIMULATE                                 /* ViBoolean */
   #define NIDMM_ATTR_RECORD_COERCIONS                         IVI_ATTR_RECORD_COERCIONS                         /* ViBoolean */
   #define NIDMM_ATTR_INTERCHANGE_CHECK                        IVI_ATTR_INTERCHANGE_CHECK                        /* ViBoolean */

   /*- Class Driver Identification -*/
   #define NIDMM_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32   (read only) */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32   (read only) */

   /*- Driver Identification -*/
   #define NIDMM_ATTR_SPECIFIC_DRIVER_DESCRIPTION              IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString  (read only) */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_PREFIX                   IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString  (read only) */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_VENDOR                   IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString  (read only) */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_REVISION                 IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString  (read only) */
   #define NIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION    /* ViInt32   (read only) */
   #define NIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION    /* ViInt32   (read only) */

   /*- Driver Capabilities -*/
   #define NIDMM_ATTR_CHANNEL_COUNT                            IVI_ATTR_CHANNEL_COUNT                            /* ViInt32   (read only) */
   #define NIDMM_ATTR_SUPPORTED_INSTRUMENT_MODELS              IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS              /* ViString  (read only) */
   #define NIDMM_ATTR_GROUP_CAPABILITIES                       IVI_ATTR_GROUP_CAPABILITIES                       /* ViString  (read only) */

   /*- Instrument Identification -*/
   #define NIDMM_ATTR_INSTRUMENT_MANUFACTURER                  IVI_ATTR_INSTRUMENT_MANUFACTURER                  /* ViString  (read only) */
   #define NIDMM_ATTR_INSTRUMENT_MODEL                         IVI_ATTR_INSTRUMENT_MODEL                         /* ViString  (read only) */
   #define NIDMM_ATTR_INSTRUMENT_FIRMWARE_REVISION             IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION             /* ViString  (read only) */

   /*- Advanced Session I/O -*/
   #define NIDMM_ATTR_LOGICAL_NAME                             IVI_ATTR_LOGICAL_NAME                             /* ViString  (read only) */
   #define NIDMM_ATTR_IO_RESOURCE_DESCRIPTOR                   IVI_ATTR_IO_RESOURCE_DESCRIPTOR                   /* ViString  (read only) */
   #define NIDMM_ATTR_DRIVER_SETUP                             IVI_ATTR_DRIVER_SETUP                             /* ViString  (read only) */
   #define NIDMM_ATTR_IO_SESSION                               IVI_ATTR_IO_SESSION                               /* ViSession (read only) */

   /*- IviDmmBase Capability Group -*/
   #define NIDMM_ATTR_FUNCTION                                 IVIDMM_ATTR_FUNCTION                              /* ViInt32   */
   #define NIDMM_ATTR_RANGE                                    IVIDMM_ATTR_RANGE                                 /* ViReal64  */
   #define NIDMM_ATTR_RESOLUTION_ABSOLUTE                      IVIDMM_ATTR_RESOLUTION_ABSOLUTE                   /* ViReal64  */
   #define NIDMM_ATTR_RESOLUTION_DIGITS                        (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)                 /* ViReal64  */
   #define NIDMM_ATTR_TRIGGER_DELAY                            IVIDMM_ATTR_TRIGGER_DELAY                         /* ViReal64  */
   #define NIDMM_ATTR_TRIGGER_SOURCE                           IVIDMM_ATTR_TRIGGER_SOURCE                        /* ViInt32   */

   /*- IviDmmAcMeasurement Extension Group -*/
   #define NIDMM_ATTR_AC_MAX_FREQ                              IVIDMM_ATTR_AC_MAX_FREQ                           /* ViReal64  */
   #define NIDMM_ATTR_AC_MIN_FREQ                              IVIDMM_ATTR_AC_MIN_FREQ                           /* ViReal64  */

   /*- IviDmmFrequencyMeasurement Extension Group -*/
   #define NIDMM_ATTR_FREQ_VOLTAGE_RANGE                       IVIDMM_ATTR_FREQ_VOLTAGE_RANGE                    /* ViReal64  */

   /*- IviDmmMultiPoint Extension Group -*/
   #define NIDMM_ATTR_MEAS_COMPLETE_DEST                       IVIDMM_ATTR_MEAS_COMPLETE_DEST                    /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_COUNT                             IVIDMM_ATTR_SAMPLE_COUNT                          /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_INTERVAL                          IVIDMM_ATTR_SAMPLE_INTERVAL                       /* ViReal64  */
   #define NIDMM_ATTR_SAMPLE_TRIGGER                           IVIDMM_ATTR_SAMPLE_TRIGGER                        /* ViInt32   */
   #define NIDMM_ATTR_TRIGGER_COUNT                            IVIDMM_ATTR_TRIGGER_COUNT                         /* ViInt32   */

   /*- IviDmmDeviceInfo Extension Group -*/
   #define NIDMM_ATTR_APERTURE_TIME                            IVIDMM_ATTR_APERTURE_TIME                         /* ViReal64  */
   #define NIDMM_ATTR_APERTURE_TIME_UNITS                      IVIDMM_ATTR_APERTURE_TIME_UNITS                   /* ViInt32   */

   /*- IviDmmAutoRangeValue Extension Group -*/
   #define NIDMM_ATTR_AUTO_RANGE_VALUE                         IVIDMM_ATTR_AUTO_RANGE_VALUE                      /* ViReal64  (read only) */

   /*- IviDmmAutoZero Extension Group -*/
   #define NIDMM_ATTR_AUTO_ZERO                                IVIDMM_ATTR_AUTO_ZERO                             /* ViInt32   */

   /*- IviDmmPowerLineFrequency Extension Group -*/
   #define NIDMM_ATTR_POWERLINE_FREQ                           IVIDMM_ATTR_POWERLINE_FREQ                        /* ViReal64  */

   /*- Advanced Triggering -*/
   #define NIDMM_ATTR_TRIGGER_SLOPE                            IVIDMM_ATTR_TRIGGER_SLOPE                         /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_TRIGGER_SLOPE                     (NIDMM_ATTR_BASE + 10L)                           /* ViInt32   */
   #define NIDMM_ATTR_MEAS_DEST_SLOPE                          (NIDMM_ATTR_BASE + 2L)                            /* ViInt32   */

   /*- Advanced measurement configuration attributes -*/
   #define NIDMM_ATTR_ADC_CALIBRATION                          (NIDMM_ATTR_BASE + 22L)                           /* ViInt32   */
   #define NIDMM_ATTR_OFFSET_COMP_OHMS                         (NIDMM_ATTR_BASE + 23L)                           /* ViInt32   */
   #define NIDMM_ATTR_NUMBER_OF_AVERAGES                       (NIDMM_ATTR_BASE + 32L)                           /* ViInt32   */
   #define NIDMM_ATTR_CURRENT_SOURCE                           (NIDMM_ATTR_BASE + 25L)                           /* ViReal64  */
   #define NIDMM_ATTR_DC_NOISE_REJECTION                       (NIDMM_ATTR_BASE + 26L)                           /* ViInt32   */
   #define NIDMM_ATTR_SETTLE_TIME                              (NIDMM_ATTR_BASE + 28L)                           /* ViReal64  */
   #define NIDMM_ATTR_INPUT_RESISTANCE                         (NIDMM_ATTR_BASE + 29L)                           /* ViReal64  */
   #define NIDMM_ATTR_LATENCY                                  (NIDMM_ATTR_BASE + 34L)                           /* ViInt32   */
   #define NIDMM_ATTR_BUFFER_SIZE                              (NIDMM_ATTR_BASE + 37L)                           /* ViInt32   */
   #define NIDMM_ATTR_SHUNT_VALUE                              (NIDMM_ATTR_BASE + 3L)                            /* ViReal64  */

   /*- Behavior model attribute -*/
   #define NIDMM_ATTR_OPERATION_MODE                           (NIDMM_ATTR_BASE + 14L)                           /* ViInt32   */

   /*- Waveform acquisition attributes -*/
   #define NIDMM_ATTR_WAVEFORM_RATE                            (NIDMM_ATTR_BASE + 18L)                           /* ViReal64  */
   #define NIDMM_ATTR_WAVEFORM_POINTS                          (NIDMM_ATTR_BASE + 19L)                           /* ViInt32   */

   /*- Waveform acquisition signal coupling attribute -*/
   #define NIDMM_ATTR_WAVEFORM_COUPLING                        (NIDMM_ATTR_BASE + 27L)                           /* ViInt32   */

   /*- Frequency voltage auto range value attribute -*/
   #define NIDMM_ATTR_FREQ_VOLTAGE_AUTO_RANGE_VALUE            (NIDMM_ATTR_BASE + 44L)                           /* ViReal64  */

   /*- Capacitance and Inductance Measurement Attributes -*/
   #define NIDMM_ATTR_CABLE_COMP_TYPE                          (NIDMM_ATTR_BASE + 45L)                           /* ViInt32   */
   #define NIDMM_ATTR_SHORT_CABLE_COMP_REACTANCE               (NIDMM_ATTR_BASE + 46L)                           /* ViReal64  */
   #define NIDMM_ATTR_SHORT_CABLE_COMP_RESISTANCE              (NIDMM_ATTR_BASE + 47L)                           /* ViReal64  */
   #define NIDMM_ATTR_OPEN_CABLE_COMP_SUSCEPTANCE              (NIDMM_ATTR_BASE + 48L)                           /* ViReal64  */
   #define NIDMM_ATTR_OPEN_CABLE_COMP_CONDUCTANCE              (NIDMM_ATTR_BASE + 49L)                           /* ViReal64  */
   #define NIDMM_ATTR_LC_CALCULATION_MODEL                     (NIDMM_ATTR_BASE + 52L)                           /* ViInt32   */
   #define NIDMM_ATTR_DC_BIAS                                  (NIDMM_ATTR_BASE + 53L)                           /* ViInt32   */
   #define NIDMM_ATTR_LC_NUMBER_MEAS_TO_AVERAGE                (NIDMM_ATTR_BASE + 55L)                           /* ViInt32   */

   /*- Attribute for serial number of the instrument -*/
   #define NIDMM_ATTR_SERIAL_NUMBER                            (NIDMM_ATTR_BASE + 54L)                           /* ViString  (read only) */

   /*- Attribute for product number of the instrument -*/
   #define NIDMM_ATTR_CONFIG_PRODUCT_NUMBER                    (NIDMM_ATTR_BASE + 61L)                           /* ViInt32   (read only) */

   /*- Attributes for Temperature Functions -*/
   #define NIDMM_ATTR_TEMP_TRANSDUCER_TYPE                     IVIDMM_ATTR_TEMP_TRANSDUCER_TYPE                  /* ViInt32   */
   #define NIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE                    IVIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE                 /* ViInt32   */
   #define NIDMM_ATTR_TEMP_TC_TYPE                             IVIDMM_ATTR_TEMP_TC_TYPE                          /* ViInt32   */
   #define NIDMM_ATTR_TEMP_TC_FIXED_REF_JUNC                   IVIDMM_ATTR_TEMP_TC_FIXED_REF_JUNC                /* ViReal64  */
   #define NIDMM_ATTR_TEMP_RTD_TYPE                            (NIDMM_ATTR_BASE + 120L)                          /* ViInt32   */
   #define NIDMM_ATTR_TEMP_RTD_RES                             IVIDMM_ATTR_TEMP_RTD_RES                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_RTD_A                               (NIDMM_ATTR_BASE + 121L)                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_RTD_B                               (NIDMM_ATTR_BASE + 122L)                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_RTD_C                               (NIDMM_ATTR_BASE + 123L)                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_THERMISTOR_TYPE                     (NIDMM_ATTR_BASE + 124L)                          /* ViInt32   */
   #define NIDMM_ATTR_TEMP_THERMISTOR_A                        (NIDMM_ATTR_BASE + 125L)                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_THERMISTOR_B                        (NIDMM_ATTR_BASE + 126L)                          /* ViReal64  */
   #define NIDMM_ATTR_TEMP_THERMISTOR_C                        (NIDMM_ATTR_BASE + 127L)                          /* ViReal64  */

   /******************************************************************************/
   /*                              Attribute Values                              */
   /******************************************************************************/

   /*- Defined values for describing floating point number types -*/
   #define NIDMM_VAL_TYPE_NORMAL          IVI_VAL_TYPE_NORMAL
   #define NIDMM_VAL_TYPE_NAN             IVI_VAL_TYPE_NAN
   #define NIDMM_VAL_TYPE_PINF            IVI_VAL_TYPE_PINF
   #define NIDMM_VAL_TYPE_NINF            IVI_VAL_TYPE_NINF

   /*- Defined values for NIDMM_ATTR_FUNCTION -*/
   #define NIDMM_VAL_DC_VOLTS             IVIDMM_VAL_DC_VOLTS
   #define NIDMM_VAL_AC_VOLTS             IVIDMM_VAL_AC_VOLTS
   #define NIDMM_VAL_DC_CURRENT           IVIDMM_VAL_DC_CURRENT
   #define NIDMM_VAL_AC_CURRENT           IVIDMM_VAL_AC_CURRENT
   #define NIDMM_VAL_2_WIRE_RES           IVIDMM_VAL_2_WIRE_RES
   #define NIDMM_VAL_4_WIRE_RES           IVIDMM_VAL_4_WIRE_RES
   #define NIDMM_VAL_FREQ                 IVIDMM_VAL_FREQ
   #define NIDMM_VAL_PERIOD               IVIDMM_VAL_PERIOD
   #define NIDMM_VAL_TEMPERATURE          IVIDMM_VAL_TEMPERATURE
   #define NIDMM_VAL_AC_VOLTS_DC_COUPLED  (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 1L)
   #define NIDMM_VAL_DIODE                (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 2L)
   #define NIDMM_VAL_WAVEFORM_VOLTAGE     (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 3L)
   #define NIDMM_VAL_WAVEFORM_CURRENT     (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 4L)
   #define NIDMM_VAL_CAPACITANCE          (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 5L)
   #define NIDMM_VAL_INDUCTANCE           (NIDMM_VAL_FUNC_SPECIFIC_EXT_BASE + 6L)

   /*- Defined values for NIDMM_ATTR_RANGE -*/
   #define NIDMM_VAL_AUTO_RANGE_ON        IVIDMM_VAL_AUTO_RANGE_ON
   #define NIDMM_VAL_AUTO_RANGE_OFF       IVIDMM_VAL_AUTO_RANGE_OFF
   #define NIDMM_VAL_AUTO_RANGE_ONCE      IVIDMM_VAL_AUTO_RANGE_ONCE

   /*- Defined values for NIDMM_ATTR_FREQ_VOLTAGE_RANGE -*/
   /* #define NIDMM_VAL_AUTO_RANGE_ON     DEFINED ABOVE */
   /* #define NIDMM_VAL_AUTO_RANGE_OFF    DEFINED ABOVE */

   /*- Defined values for NIDMM_ATTR_TRIGGER_DELAY -*/
   #define NIDMM_VAL_AUTO_DELAY           -1.0

   #define NIDMM_VAL_AUTO_DELAY_ON        IVIDMM_VAL_AUTO_DELAY_ON
   #define NIDMM_VAL_AUTO_DELAY_OFF       IVIDMM_VAL_AUTO_DELAY_OFF

   /*- Defined value for NIDMM_ATTR_SAMPLE_INTERVAL -*/
   /* #define NIDMM_VAL_AUTO_DELAY        DEFINED ABOVE */

   /*- Defined values for NIDMM_ATTR_TRIGGER_SOURCE -*/
   #define NIDMM_VAL_IMMEDIATE            IVIDMM_VAL_IMMEDIATE
   #define NIDMM_VAL_EXTERNAL             IVIDMM_VAL_EXTERNAL
   #define NIDMM_VAL_SOFTWARE_TRIG        IVIDMM_VAL_SOFTWARE_TRIG
   #define NIDMM_VAL_PXI_TRIG0            IVIDMM_VAL_TTL0
   #define NIDMM_VAL_PXI_TRIG1            IVIDMM_VAL_TTL1
   #define NIDMM_VAL_PXI_TRIG2            IVIDMM_VAL_TTL2
   #define NIDMM_VAL_PXI_TRIG3            IVIDMM_VAL_TTL3
   #define NIDMM_VAL_PXI_TRIG4            IVIDMM_VAL_TTL4
   #define NIDMM_VAL_PXI_TRIG5            IVIDMM_VAL_TTL5
   #define NIDMM_VAL_PXI_TRIG6            IVIDMM_VAL_TTL6
   #define NIDMM_VAL_PXI_TRIG7            IVIDMM_VAL_TTL7
   #define NIDMM_VAL_PXI_STAR             IVIDMM_VAL_PXI_STAR
   #define NIDMM_VAL_LBR_TRIG1            (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 4L)
   #define NIDMM_VAL_AUX_TRIG1            (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 1L)

   /*- Defined values for NIDMM_ATTR_MEAS_COMPLETE_DEST -*/
   #define NIDMM_VAL_NONE                 IVIDMM_VAL_NONE

   /* #define NIDMM_VAL_EXTERNAL          DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG0         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG1         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG2         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG3         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG4         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG5         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG6         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG7         DEFINED ABOVE */
   #define NIDMM_VAL_LBR_TRIG0            (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 3L)

   /*- Defined values for NIDMM_ATTR_SAMPLE_TRIGGER -*/
   /* #define NIDMM_VAL_IMMEDIATE         DEFINED ABOVE */
   /* #define NIDMM_VAL_EXTERNAL          DEFINED ABOVE */
   /* #define NIDMM_VAL_SOFTWARE_TRIG     DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG0         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG1         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG2         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG3         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG4         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG5         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG6         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_TRIG7         DEFINED ABOVE */
   /* #define NIDMM_VAL_PXI_STAR          DEFINED ABOVE */
   /* #define NIDMM_VAL_LBR_TRIG1         DEFINED ABOVE */
   /* #define NIDMM_VAL_AUX_TRIG1         DEFINED ABOVE */
   #define NIDMM_VAL_INTERVAL             IVIDMM_VAL_INTERVAL

   /*- Defined values for NIDMM_ATTR_TRIGGER_SLOPE,
       NIDMM_ATTR_SAMPLE_TRIGGER_SLOPE, and
       NIDMM_ATTR_MEAS_DEST_SLOPE, -*/
   #define NIDMM_VAL_POSITIVE             IVIDMM_VAL_POSITIVE
   #define NIDMM_VAL_NEGATIVE             IVIDMM_VAL_NEGATIVE

   /*- Defined value for NIDMM_ATTR_TRIGGER_COUNT -*/
   #define NIDMM_VAL_TRIG_COUNT_INFINITE      0

   /*- Definde value for NIDMM_ATTR_SAMPLE_COUNT -*/
   #define NIDMM_VAL_SAMPLE_COUNT_INFINITE    0

   /*- Defined values for NIDMM_ATTR_POWERLINE_FREQ -*/
   #define NIDMM_VAL_50_HERTZ             (50.0)
   #define NIDMM_VAL_60_HERTZ             (60.0)

   /*- Defined values for NIDMM_ATTR_APERTURE_TIME_UNITS -*/
   #define NIDMM_VAL_SECONDS              IVIDMM_VAL_SECONDS
   #define NIDMM_VAL_POWER_LINE_CYCLES    IVIDMM_VAL_POWER_LINE_CYCLES

   /*- Defined values for NIDMM_ATTR_APERTURE_TIME -*/
   #define NIDMM_VAL_APERTURE_TIME_AUTO    -1.0
   #define NIDMM_VAL_1_PLC                  1.0
   #define NIDMM_VAL_5_PLC                  5.0
   #define NIDMM_VAL_6_PLC                  6.0
   #define NIDMM_VAL_10_PLC                10.0
   #define NIDMM_VAL_12_PLC                12.0
   #define NIDMM_VAL_100_PLC              100.0
   #define NIDMM_VAL_120_PLC              120.0

   /*- Defined value for NIDMM_ATTR_SETTLE_TIME -*/
   #define NIDMM_VAL_SETTLE_TIME_AUTO      -1.0

   /*- Defined values for NIDMM_ATTR_AUTO_ZERO -*/
   #define NIDMM_VAL_AUTO_ZERO_AUTO       -1
   #define NIDMM_VAL_AUTO_ZERO_OFF        IVIDMM_VAL_AUTO_ZERO_OFF
   #define NIDMM_VAL_AUTO_ZERO_ON         IVIDMM_VAL_AUTO_ZERO_ON
   #define NIDMM_VAL_AUTO_ZERO_ONCE       IVIDMM_VAL_AUTO_ZERO_ONCE

   /*- Defined values for NIDMM_ATTR_ADC_CALIBRATION -*/
   #define NIDMM_VAL_ADC_CALIBRATION_AUTO    -1
   #define NIDMM_VAL_ADC_CALIBRATION_OFF      0
   #define NIDMM_VAL_ADC_CALIBRATION_ON       1

   /*- Defined values for NIDMM_ATTR_OFFSET_COMP_OHMS -*/
   #define NIDMM_VAL_OFFSET_COMP_OHMS_OFF     0
   #define NIDMM_VAL_OFFSET_COMP_OHMS_ON      1

   /*- Defined values for NIDMM_ATTR_CURRENT_SOURCE -*/
   #define NIDMM_VAL_1_MICROAMP         0.000001
   #define NIDMM_VAL_10_MICROAMP        0.00001
   #define NIDMM_VAL_100_MICROAMP       0.0001
   #define NIDMM_VAL_1_MILLIAMP         0.001

   /*- Defined values for NIDMM_ATTR_DC_NOISE_REJECTION -*/
   #define NIDMM_VAL_DCNR_AUTO         -1
   #define NIDMM_VAL_DCNR_NORMAL        0
   #define NIDMM_VAL_DCNR_SECOND_ORDER  1
   #define NIDMM_VAL_DCNR_HIGH_ORDER    2

   /*- Defined values for NIDMM_ATTR_INPUT_RESISTANCE -*/
   #define NIDMM_VAL_1_MEGAOHM                    1000000.0
   #define NIDMM_VAL_10_MEGAOHM                  10000000.0
   #define NIDMM_VAL_GREATER_THAN_10_GIGAOHM  10000000000.0
   #define NIDMM_VAL_RESISTANCE_NA                      0.0

   /*- Defined value for NIDMM_ATTR_LATENCY -*/
   #define NIDMM_VAL_LATENCY_AUTO      -1

   /*- Defined value for NIDMM_ATTR_BUFFER_SIZE -*/
   #define NIDMM_VAL_BUFFER_SIZE_AUTO  -1

   /*- Defined values for calibration functions -*/
   #define NIDMM_VAL_INTERNAL_AREA      0
   #define NIDMM_VAL_EXTERNAL_AREA      1

   /*- Defined values for time limit -*/
   #define NIDMM_VAL_TIME_LIMIT_AUTO         -1

   /*- Defined values for NIDMM_ATTR_OPERATION_MODE -*/
   #define NIDMM_VAL_IVIDMM_MODE             0
   #define NIDMM_VAL_WAVEFORM_MODE           1

   /*- Defined Values for NIDMM_ATTR_WAVEFORM_COUPLING -*/
   #define NIDMM_VAL_WAVEFORM_COUPLING_AC    0
   #define NIDMM_VAL_WAVEFORM_COUPLING_DC    1

   /*- Defined values for NIDMM_ATTR_CALCULATION_MODEL -*/
   #define NIDMM_VAL_CALC_MODEL_AUTO         -1
   #define NIDMM_VAL_CALC_MODEL_SERIES       0
   #define NIDMM_VAL_CALC_MODEL_PARALLEL     1

   /*- Defined values for NIDMM_ATTR_DC_BIAS -*/
   #define NIDMM_VAL_DC_BIAS_OFF          0
   #define NIDMM_VAL_DC_BIAS_ON           1

   /*- Defined values for the typeOfCompensation parameter of "niDMM_LC_Measurement_Compensation" -*/
   #define NIDMM_VAL_CABLE_COMP_NONE               0
   #define NIDMM_VAL_CABLE_COMP_OPEN               1
   #define NIDMM_VAL_CABLE_COMP_SHORT              2
   #define NIDMM_VAL_CABLE_COMP_OPEN_AND_SHORT     3

   /*- Defined values for the action parameter of "niDMM_control" -*/
   #define NIDMM_VAL_CONTROL_COMMIT                0   // Commit

   /*- Defined values for NIDMM_ATTR_TEMP_TRANSDUCER_TYPE -*/
   #define NIDMM_VAL_THERMOCOUPLE            IVIDMM_VAL_THERMOCOUPLE
   #define NIDMM_VAL_THERMISTOR              IVIDMM_VAL_THERMISTOR
   #define NIDMM_VAL_2_WIRE_RTD              IVIDMM_VAL_2_WIRE_RTD
   #define NIDMM_VAL_4_WIRE_RTD              IVIDMM_VAL_4_WIRE_RTD

   /*- Defined values for NIDMM_ATTR_TEMP_TC_REF_JUNC_TYPE -*/
   #define NIDMM_VAL_TEMP_REF_JUNC_FIXED     IVIDMM_VAL_TEMP_REF_JUNC_FIXED

   /*- Defined values for NIDMM_ATTR_TEMP_TC_TYPE -*/
   #define NIDMM_VAL_TEMP_TC_B               IVIDMM_VAL_TEMP_TC_B
   #define NIDMM_VAL_TEMP_TC_E               IVIDMM_VAL_TEMP_TC_E
   #define NIDMM_VAL_TEMP_TC_J               IVIDMM_VAL_TEMP_TC_J
   #define NIDMM_VAL_TEMP_TC_K               IVIDMM_VAL_TEMP_TC_K
   #define NIDMM_VAL_TEMP_TC_N               IVIDMM_VAL_TEMP_TC_N
   #define NIDMM_VAL_TEMP_TC_R               IVIDMM_VAL_TEMP_TC_R
   #define NIDMM_VAL_TEMP_TC_S               IVIDMM_VAL_TEMP_TC_S
   #define NIDMM_VAL_TEMP_TC_T               IVIDMM_VAL_TEMP_TC_T

   /*- Defined values for NIDMM_ATTR_TEMP_RTD_TYPE -*/
   #define NIDMM_VAL_TEMP_RTD_CUSTOM         0
   #define NIDMM_VAL_TEMP_RTD_PT3750         1
   #define NIDMM_VAL_TEMP_RTD_PT3851         2
   #define NIDMM_VAL_TEMP_RTD_PT3911         3
   #define NIDMM_VAL_TEMP_RTD_PT3916         4
   #define NIDMM_VAL_TEMP_RTD_PT3920         5
   #define NIDMM_VAL_TEMP_RTD_PT3928         6

   /*- Defined values for NIDMM_ATTR_TEMP_THERMISTOR_TYPE -*/
   #define NIDMM_VAL_TEMP_THERMISTOR_CUSTOM  0
   #define NIDMM_VAL_TEMP_THERMISTOR_44004   1
   #define NIDMM_VAL_TEMP_THERMISTOR_44006   2
   #define NIDMM_VAL_TEMP_THERMISTOR_44007   3

   /******************************************************************************/
   /*                       External Calibration Constants                       */
   /******************************************************************************/

   #define NIDMM_EXTCAL_MISCCAL_VREF                  0L
   #define NIDMM_EXTCAL_MISCCAL_RREF                  1L
   #define NIDMM_EXTCAL_MISCCAL_ZINT                  2L
   #define NIDMM_EXTCAL_MISCCAL_2WIRELEAKAGE          3L
   #define NIDMM_EXTCAL_MISCCAL_4WIRELEAKAGE          4L
   #define NIDMM_EXTCAL_MISCCAL_SECTION               5L
   #define NIDMM_EXTCAL_MISCCAL_VREF_DC_VOLTAGE       6L
   #define NIDMM_EXTCAL_MISCCAL_VREF_DC_CURRENT       7L
   #define NIDMM_EXTCAL_MISCCAL_VREF_AC_VOLTAGE       8L
   #define NIDMM_EXTCAL_MISCCAL_VREF_AC_CURRENT       9L
   #define NIDMM_EXTCAL_MISCCAL_VREF_RESISTANCE       10L
   #define NIDMM_EXTCAL_MISCCAL_VOLTAGE_AC_FILTER     11L

   #define NIDMM_EXTCAL_ACTION_ABORT                  0L
   #define NIDMM_EXTCAL_ACTION_SAVE                   1L

   #define NIDMM_EXTCAL_LC_OPEN                       0L
   #define NIDMM_EXTCAL_LC_SHORT                      1L
   #define NIDMM_EXTCAL_LC_25OHM                      2L
   #define NIDMM_EXTCAL_LC_1KOHM                      3L
   #define NIDMM_EXTCAL_LC_5KOHM                      4L
   #define NIDMM_EXTCAL_LC_100KOHM                    5L
   #define NIDMM_EXTCAL_LC_125OHM                     6L

   #define NIDMM_4022_CONFIG_GUARD                    0L
   #define NIDMM_4022_CONFIG_CURRENT_100_NANOAMP      2L
   #define NIDMM_4022_CONFIG_CURRENT_10_MICROAMP      3L
   #define NIDMM_4022_CONFIG_CURRENT_1_MILLIAMP       7L
   #define NIDMM_4022_CONFIG_DISCONNECT_AGND          8L

   /******************************************************************************/
   /*               NI-DMM Specific Driver Functions Declarations                */
   /******************************************************************************/

   /*- Init and Close Functions -*/
   ViStatus _VI_FUNC niDMM_init(
      ViRsrc      resourceName,
      ViBoolean   IDQuery,
      ViBoolean   reset,
      ViSession   *newVi);

   ViStatus _VI_FUNC niDMM_InitWithOptions(
      ViRsrc      resourceName,
      ViBoolean   IDQuery,
      ViBoolean   resetDevice,
      ViString    optionsString,
      ViSession   *newVi);

   ViStatus _VI_FUNC niDMM_close(
      ViSession   vi);

   /*- Error Functions -*/
   ViStatus _VI_FUNC niDMM_GetError(
      ViSession   vi,
      ViStatus    *errorCode,
      ViInt32     bufferSize,
      ViChar      description[]);

   ViStatus _VI_FUNC niDMM_GetErrorMessage(
      ViSession   vi,
      ViStatus    errorCode,
      ViInt32     bufferSize,
      ViChar      errMessage[]);

   ViStatus _VI_FUNC niDMM_ClearError(
      ViSession   vi);

   /*- Utility Functions -*/
   ViStatus _VI_FUNC niDMM_reset(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_self_test(
      ViSession   vi,
      ViInt16     *selfTestResult,
      ViChar      selfTestMessage[]);

   ViStatus _VI_FUNC niDMM_SelfCal(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_revision_query(
      ViSession   vi,
      ViChar      driverRev[],
      ViChar      instrRev[]);

   ViStatus _VI_FUNC niDMM_InvalidateAllAttributes(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_ResetWithDefaults(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_Disable(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_GetMeasurementPeriod(
      ViSession   vi,
      ViReal64    *period);

   /*- IviDmmBase Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureTrigger(
      ViSession   vi,
      ViInt32     trigSource,
      ViReal64    triggerDelay);

   ViStatus _VI_FUNC niDMM_Read(
      ViSession   vi,
      ViInt32     maxTime,
      ViReal64    *reading);

   ViStatus _VI_FUNC niDMM_Fetch(
      ViSession   vi,
      ViInt32     maxTime,
      ViReal64    *reading);

   ViStatus _VI_FUNC niDMM_Abort(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_Initiate(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_IsOverRange(
      ViSession   vi,
      ViReal64    measurementValue,
      ViBoolean   *isOverRange);

   ViStatus _VI_FUNC niDMM_IsUnderRange(
      ViSession   vi,
      ViReal64    measurementValue,
      ViBoolean   *isUnderRange);

   /*- IviDmmAcMeasurement Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureACBandwidth(
      ViSession   vi,
      ViReal64    minFreq,
      ViReal64    maxFreq);

   /*- IviDmmFrequencyMeasurement Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureFrequencyVoltageRange(
      ViSession   vi,
      ViReal64    frequencyVoltageRange);

   /*- IviDmmMultiPoint Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureMeasCompleteDest(
      ViSession   vi,
      ViInt32     destination);

   ViStatus _VI_FUNC niDMM_ConfigureMultiPoint(
      ViSession   vi,
      ViInt32     triggerCount,
      ViInt32     sampleCount,
      ViInt32     sampleTrigger,
      ViReal64    sampleInterval);

   ViStatus _VI_FUNC niDMM_ReadMultiPoint(
      ViSession   vi,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    readingArray[],
      ViInt32     *actualPts);

   ViStatus _VI_FUNC niDMM_FetchMultiPoint(
      ViSession   vi,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    readingArray[],
      ViInt32     *actualPts);

   /*- IviDmmTriggerSlope Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureTriggerSlope(
      ViSession   vi,
      ViInt32     polarity);

   /*- IviDmmSoftwareTrigger Functions -*/
   ViStatus _VI_FUNC niDMM_SendSoftwareTrigger(
      ViSession   vi);

   /*- IviDmmDeviceInfo Functions -*/
   ViStatus _VI_FUNC niDMM_GetApertureTimeInfo (
      ViSession   vi,
      ViReal64    *apertureTime,
      ViInt32     *apertureTimeUnits);

   /*- IviDmmAutoRangeValue Functions -*/
   ViStatus _VI_FUNC niDMM_GetAutoRangeValue(
      ViSession   vi,
      ViReal64    *autoRangeValue);

   /*- IviDmmAutoZero Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureAutoZeroMode(
      ViSession   vi,
      ViInt32     autoZeroMode);

   /*- IviDmmPowerLineFrequency Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigurePowerLineFrequency(
      ViSession   vi,
      ViReal64    frequency);

   /*- Extended Instrument Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureMeasurementDigits(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolutionDigits);

   ViStatus _VI_FUNC niDMM_ConfigureMeasurementAbsolute(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolutionAbsolute);

   ViStatus _VI_FUNC niDMM_ConfigureMeasCompleteSlope(
      ViSession   vi,
      ViInt32     polarity);

   ViStatus _VI_FUNC niDMM_ConfigureSampleTriggerSlope(
      ViSession   vi,
      ViInt32     polarity);

   ViStatus _VI_FUNC niDMM_ReadStatus(
      ViSession   vi,
      ViInt32     *acqBacklog,
      ViInt16     *acqDone);

   ViStatus _VI_FUNC niDMM_Control(
      ViSession   vi,
      ViInt32     action);

   /*- Functions for Advanced Measurement Configuration attributes -*/
   ViStatus _VI_FUNC niDMM_ConfigureADCCalibration(
      ViSession   vi,
      ViInt32     adcGainComp);

   ViStatus _VI_FUNC niDMM_ConfigureOffsetCompOhms(
      ViSession   vi,
      ViInt32     offsetCompOhms);

   ViStatus _VI_FUNC niDMM_ConfigureCurrentSource(
      ViSession   vi,
      ViReal64    diodeCurrentSrc);

   /*- Capacitance and Inductance Measurement Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureCableCompType(
      ViSession vi,
      ViInt32 typeOfCompensation);

   ViStatus _VI_FUNC niDMM_PerformOpenCableComp(
      ViSession vi,
      ViReal64  *conductance,
      ViReal64  *susceptance);

   ViStatus _VI_FUNC niDMM_PerformShortCableComp(
      ViSession vi,
      ViReal64  *resistance,
      ViReal64  *reactance);

   ViStatus _VI_FUNC niDMM_ConfigureOpenCableCompValues(
      ViSession vi,
      ViReal64  conductance,
      ViReal64  susceptance);

   ViStatus _VI_FUNC niDMM_ConfigureShortCableCompValues(
      ViSession vi,
      ViReal64  resistance,
      ViReal64  reactance);

   /*- Locking Functions --*/
   ViStatus _VI_FUNC niDMM_LockSession(
      ViSession   vi,
      ViBoolean   *callerHasLock);

   ViStatus _VI_FUNC niDMM_UnlockSession(
      ViSession   vi,
      ViBoolean   *callerHasLock);

   /*- Waveform Acquisition Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureWaveformAcquisition(
      ViSession   vi,
      ViInt32     function,
      ViReal64    range,
      ViReal64    rate,
      ViInt32     waveformPoints);

   ViStatus _VI_FUNC niDMM_ConfigureWaveformCoupling(
      ViSession   vi,
      ViInt32     coupling);

   ViStatus _VI_FUNC niDMM_FetchWaveform(
      ViSession   vi,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    waveformArray[],
      ViInt32     *actualPoints);

   ViStatus _VI_FUNC niDMM_ReadWaveform(
      ViSession   vi,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    waveformArray[],
      ViInt32     *actualPoints);

   /*- Set, Get, and Check Attribute Functions -*/
   ViStatus _VI_FUNC niDMM_GetAttributeViInt32(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViInt32       *value);

   ViStatus _VI_FUNC niDMM_SetAttributeViInt32(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViInt32       value);

   ViStatus _VI_FUNC niDMM_CheckAttributeViInt32(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViInt32       value);

   ViStatus _VI_FUNC niDMM_GetAttributeViReal64(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViReal64      *value);

   ViStatus _VI_FUNC niDMM_SetAttributeViReal64(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViReal64      value);

   ViStatus _VI_FUNC niDMM_CheckAttributeViReal64(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViReal64      value);

   ViStatus _VI_FUNC niDMM_GetAttributeViString(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViInt32       bufSize,
      ViChar        value[]);

   ViStatus _VI_FUNC niDMM_SetAttributeViString(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViChar        value[]);

   ViStatus _VI_FUNC niDMM_CheckAttributeViString(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViChar        value[]);

   ViStatus _VI_FUNC niDMM_GetAttributeViSession(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViSession     *value);

   ViStatus _VI_FUNC niDMM_SetAttributeViSession(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViSession     value);

   ViStatus _VI_FUNC niDMM_CheckAttributeViSession(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViSession     value);

   ViStatus _VI_FUNC niDMM_GetAttributeViBoolean(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViBoolean     *value);

   ViStatus _VI_FUNC niDMM_SetAttributeViBoolean(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViBoolean     value);

   ViStatus _VI_FUNC niDMM_CheckAttributeViBoolean(
      ViSession     vi,
      ViConstString channelName,
      ViAttr        attributeId,
      ViBoolean     value);

   /*- Import and Export Session Configuration Functions -*/
   ViStatus _VI_FUNC niDMM_ImportAttributeConfigurationFile(
      ViSession vi,
      ViConstString filePath);

   ViStatus _VI_FUNC niDMM_ExportAttributeConfigurationFile(
      ViSession vi,
      ViConstString filePath);

   ViStatus _VI_FUNC niDMM_ImportAttributeConfigurationBuffer(
      ViSession vi,
      ViInt32 size,
      const ViAddr configuration);

   ViStatus _VI_FUNC niDMM_ExportAttributeConfigurationBuffer(
      ViSession vi,
      ViInt32 size,
      ViAddr configuration);

   /*- Interchangeability Checking Functions -*/
   ViStatus _VI_FUNC niDMM_GetNextCoercionRecord(
      ViSession   vi,
      ViInt32     bufferSize,
      ViChar      record[]);

   ViStatus _VI_FUNC niDMM_GetNextInterchangeWarning(
      ViSession   vi,
      ViInt32     bufferSize,
      ViChar      warnString[]);

   ViStatus _VI_FUNC niDMM_ResetInterchangeCheck(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_ClearInterchangeWarnings(
      ViSession   vi);

   /*- 4022 Functions -*/
   ViStatus _VI_FUNC niDMM_4022Control(
      ViRsrc      resourceName,
      ViInt32     configuration);

   /*- Channel Info Functions -*/
   ViStatus _VI_FUNC niDMM_GetChannelName(
      ViSession   vi,
      ViInt32     index,
      ViInt32     bufferSize,
      ViChar      name[]);

   /*- External Cal Init and Close Functions -*/
   ViStatus _VI_FUNC niDMM_InitExtCal(
      ViRsrc      resourceName,
      ViChar      password[],
      ViSession   *newVi);

   ViStatus _VI_FUNC niDMM_CloseExtCal(
      ViSession   vi,
      ViInt32     action);

   /*- Adjust Functions -*/
   ViStatus _VI_FUNC niDMM_CalAdjustLinearization(
      ViSession   vi,
      ViInt32     mode,
      ViReal64    range,
      ViReal64    inputR,
      ViReal64    expectedValue);

   ViStatus _VI_FUNC niDMM_CalAdjustGain(
      ViSession   vi,
      ViInt32     mode,
      ViReal64    range,
      ViReal64    inputR,
      ViReal64    expectedValue);

   ViStatus _VI_FUNC niDMM_CalAdjustOffset(
      ViSession   vi,
      ViInt32     mode,
      ViReal64    range,
      ViReal64    inputR);

   ViStatus _VI_FUNC niDMM_CalAdjustMisc(
      ViSession   vi,
      ViInt32     type);

   ViStatus _VI_FUNC niDMM_CalAdjustLC(
      ViSession   vi,
      ViInt32     type);

   ViStatus _VI_FUNC niDMM_CalAdjustACFilter(
      ViSession   vi,
      ViInt32     mode,
      ViReal64    range,
      ViReal64    frequency,
      ViReal64    expectedValue);

   /*- Utility Functions -*/
   ViStatus _VI_FUNC niDMM_RestoreLastExtCalConstants(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_SetCalPassword(
      ViSession   vi,
      ViChar      oldPassword[],
      ViChar      newPassword[]);

   ViStatus _VI_FUNC niDMM_GetExtCalRecommendedInterval(
      ViSession   vi,
      ViInt32    *months);

   ViStatus _VI_FUNC niDMM_SetCalUserDefinedInfo(
      ViSession   vi,
      ViChar      info[]);

   ViStatus _VI_FUNC niDMM_GetCalUserDefinedInfoMaxSize(
      ViSession   vi,
      ViInt32    *infoSize);

   ViStatus _VI_FUNC niDMM_GetCalUserDefinedInfo(
      ViSession   vi,
      ViInt32     bufferSize,
      ViChar      info[]);

   ViStatus _VI_FUNC niDMM_GetSelfCalSupported(
      ViSession   vi,
      ViBoolean  *selfCalSupported);

   ViStatus _VI_FUNC niDMM_GetCalDateAndTime(
      ViSession   vi,
      ViInt32     calType,
      ViInt32     *month,
      ViInt32     *day,
      ViInt32     *year,
      ViInt32     *hour,
      ViInt32     *minute);

   ViStatus _VI_FUNC niDMM_GetCalCount(
      ViSession   vi,
      ViInt32     calType,
      ViInt32     *count);

   ViStatus _VI_FUNC niDMM_GetLastCalTemp(
      ViSession   vi,
      ViInt32     calType,
      ViReal64    *temperature);

   ViStatus _VI_FUNC niDMM_GetDevTemp(
      ViSession   vi,
      ViString    reserved,
      ViReal64    *temperature);

   /*- Temperature Measurement Functions -*/
   ViStatus _VI_FUNC niDMM_ConfigureTransducerType(
      ViSession vi,
      ViInt32 transducerType);

   ViStatus _VI_FUNC niDMM_ConfigureThermocouple(
      ViSession vi,
      ViInt32 thermocoupleType,
      ViInt32 refJunctionType);

   ViStatus _VI_FUNC niDMM_ConfigureFixedRefJunction(
      ViSession vi,
      ViReal64 fixedRefJunction);

   ViStatus _VI_FUNC niDMM_ConfigureRTDType(
      ViSession vi,
      ViInt32 rtdType,
      ViReal64 resistance);

   ViStatus _VI_FUNC niDMM_ConfigureRTDCustom(
      ViSession vi,
      ViReal64 a,
      ViReal64 b,
      ViReal64 c);

   ViStatus _VI_FUNC niDMM_ConfigureThermistorType(
      ViSession vi,
      ViInt32 thermistorType);

   ViStatus _VI_FUNC niDMM_ConfigureThermistorCustom(
      ViSession vi,
      ViReal64 a,
      ViReal64 b,
      ViReal64 c);

   /*- IviDmmObsolete.h included for backwards compatibility -*/
   #include "nidmmObsolete.h"

   /******************************************************************************/
   /*                              END INCLUDE FILE                              */
   /******************************************************************************/

   #if defined(__cplusplus) || defined(__cplusplus__)
}
   #endif

#endif // __NIDMM__HEADER

