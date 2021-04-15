/*****************************************************************************
 *                            N I - D M M
 *----------------------------------------------------------------------------
 *    Copyright (c) National Instruments 2012.  All Rights Reserved.
 *----------------------------------------------------------------------------
 *
 * Title:       nidmmObsolete.h
 * Purpose:     Declarations of constants and functions that are now obsolete
 *              in the NI-DMM driver.
 *              They are defined here to maintain backward compatibility with
 *              previous versions of driver. New applications should not use
 *              any of the definitions in this file. Instead, they must
 *              use definitions from the nidmm.h header file.
 *****************************************************************************/

#ifndef __NIDMM__HEADER_OBSOLETE
   #define __NIDMM__HEADER_OBSOLETE

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

   /*********************************************************************************
   * This section lists all attributes and values that became obsolete. Do not use  *
   * these attributes and values in your drivers and applications.                  *
   *********************************************************************************/

   #if (defined(_EXPORTING) && defined(_IVI_mswin32_))
      #define NIDMM_DECLSPEC    __declspec(dllexport)
   #else
      #define NIDMM_DECLSPEC
   #endif

   /*  Use NIDMM_ATTR_CHANNEL_COUNT instead */
   #define NIDMM_ATTR_NUM_CHANNELS             IVI_ATTR_NUM_CHANNELS              /* ViInt32, read only*/
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_PREFIX instead */
   #define NIDMM_ATTR_SPECIFIC_PREFIX          IVI_ATTR_SPECIFIC_PREFIX           /* ViString, read only*/
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_REVISION instead */
   #define NIDMM_ATTR_DRIVER_REVISION          IVI_ATTR_DRIVER_REVISION           /* ViString, read only*/
   /*  Use NIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION instead */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION   IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION /* ViInt32, read only  */
   /*  Use NIDMM_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION instead */
   #define NIDMM_ATTR_SPECIFIC_DRIVER_MINOR_VERSION   IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION /* ViInt32, read only  */
   /*  Use NIDMM_ATTR_QUERY_INSTRUMENT_STATUS instead */
   #define NIDMM_ATTR_QUERY_INSTR_STATUS       IVI_ATTR_QUERY_INSTR_STATUS        /* ViBoolean */
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION instead */
   #define NIDMM_ATTR_DRIVER_MAJOR_VERSION     IVI_ATTR_DRIVER_MAJOR_VERSION      /* ViInt32, read only  */
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_MINOR_VERSION instead */
   #define NIDMM_ATTR_DRIVER_MINOR_VERSION     IVI_ATTR_DRIVER_MINOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_PRIMARY_ERROR            IVI_ATTR_PRIMARY_ERROR             /* ViInt32   */
   #define NIDMM_ATTR_SECONDARY_ERROR          IVI_ATTR_SECONDARY_ERROR           /* ViInt32   */
   #define NIDMM_ATTR_ERROR_ELABORATION        IVI_ATTR_ERROR_ELABORATION         /* ViString  */
   #define NIDMM_ATTR_ENGINE_MAJOR_VERSION     IVI_ATTR_ENGINE_MAJOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_ENGINE_MINOR_VERSION     IVI_ATTR_ENGINE_MINOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_ENGINE_REVISION          IVI_ATTR_ENGINE_REVISION           /* ViString, read-only */
   #define NIDMM_ATTR_VISA_RM_SESSION          IVI_ATTR_VISA_RM_SESSION           /* ViSession, read only */
   #define NIDMM_ATTR_DEFER_UPDATE             IVI_ATTR_DEFER_UPDATE              /* ViBoolean */
   #define NIDMM_ATTR_RETURN_DEFERRED_VALUES   IVI_ATTR_RETURN_DEFERRED_VALUES    /* ViBoolean */
   /*  Use NIDMM_ATTR_IO_RESOURCE_DESCRIPTOR instead */
   #define NIDMM_ATTR_RESOURCE_DESCRIPTOR      IVI_ATTR_RESOURCE_DESCRIPTOR       /* ViString, read only */
   /*  Use NIDMM_ATTR_RESOLUTION_ABSOLUTE */
   #define NIDMM_ATTR_RESOLUTION               NIDMM_ATTR_RESOLUTION_DIGITS       /* ViReal64  */
   /*  Use NIDMM_ATTR_TRIGGER */
   #define NIDMM_ATTR_START_TRIGGER            (NIDMM_ATTR_BASE + 8L)             /* ViInt32   */
   #define NIDMM_ATTR_START_TRIG_SLOPE         (NIDMM_ATTR_BASE + 9L)             /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_TRIGGER_DELAY     (NIDMM_ATTR_BASE + 11L)            /* ViReal64  */
   #define NIDMM_ATTR_OLD_TRIGGER_MODEL        (NIDMM_ATTR_BASE + 12L)            /* ViBoolean */
   #define NIDMM_ATTR_CHAN_NAMES               (NIDMM_ATTR_BASE + 4L)             /* ViString, read only */
   #define NIDMM_ATTR_ID_QUERY_RESPONSE        (NIDMM_ATTR_BASE + 1L)             /* ViString, read only */
   #define NIDMM_ATTR_AI_NUM_CHANNELS          (NIDMM_ATTR_BASE + 5L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_FILTER_NOTCH             (NIDMM_ATTR_BASE + 6L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_CONVER_PER_SAMPLE        (NIDMM_ATTR_BASE + 7L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_AI_BUFFER_SIZE           (NIDMM_ATTR_BASE + 13L)            /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_DELAY_MODE        (NIDMM_ATTR_BASE + 31L)            /* ViInt32  */
   #define NIDMM_VAL_3_5_DIGITS                (3.5)
   #define NIDMM_VAL_4_5_DIGITS                (4.5)
   #define NIDMM_VAL_5_5_DIGITS                (5.5)
   #define NIDMM_VAL_6_5_DIGITS                (6.5)
   #define NIDMM_VAL_7_5_DIGITS                (7.5)
   /*  Use NIDMM_VAL_SOFTWARE_TRIG instead */
   #define NIDMM_VAL_SW_TRIG_FUNC              IVIDMM_VAL_SW_TRIG_FUNC
   /*  Use NIDMM_VAL_POSITIVE instead */
   #define NIDMM_VAL_POS                       IVIDMM_VAL_POSITIVE
   /*  Use NIDMM_VAL_NEGATIVE instead */
   #define NIDMM_VAL_NEG                       IVIDMM_VAL_NEGATIVE
   /*  Use NIDMM_VAL_MILLIAMP instead */
   #define NIDMM_VAL_1_MILIAMP         0.001
   #define NIDMM_WARN_FREQ_UNDERRANGE          (NIDMM_WARN_EXT_STATUS_BASE + 0x80) // 0x3FFA4F80 1073368960
   /*  Use NIDMM_VAL_PXI_TRIG<0-7> instead */
   #define NIDMM_VAL_TTL0                      IVIDMM_VAL_TTL0
   #define NIDMM_VAL_TTL1                      IVIDMM_VAL_TTL1
   #define NIDMM_VAL_TTL2                      IVIDMM_VAL_TTL2
   #define NIDMM_VAL_TTL3                      IVIDMM_VAL_TTL3
   #define NIDMM_VAL_TTL4                      IVIDMM_VAL_TTL4
   #define NIDMM_VAL_TTL5                      IVIDMM_VAL_TTL5
   #define NIDMM_VAL_TTL6                      IVIDMM_VAL_TTL6
   #define NIDMM_VAL_TTL7                      IVIDMM_VAL_TTL7
   /*  Use NIDMM_VAL_LBR_TRIG<0-1> instead */
   #define NIDMM_VAL_LBR_TRIG_0           (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 3L)
   #define NIDMM_VAL_LBR_TRIG_1           (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 4L)
   /*  Use NIDMM_VAL_AUX_TRIG1 instead */
   #define NIDMM_VAL_AUX_TRIG_1           (NIDMM_VAL_TRIGGER_SOURCE_SPECIFIC_EXT_BASE + 1L)
   /*  Internal constants used in the NI 407x external calibration procedure */
   #define NIDMM_EXTCAL_MISCCAL_MAX_TYPES      6L
   #define NIDMM_EXTCAL_LC_MAX_STAGES          6L


   /*********************************************************************************
   * This section lists all driver functions that became obsolete. Do not use       *
   * these functions in your drivers and applications.                              *
   *********************************************************************************/
   ViStatus _VI_FUNC niDMM_error_message(
      ViSession   vi,
      ViStatus    errorCode,
      ViChar      errMessage[]);

   ViStatus _VI_FUNC niDMM_GetErrorInfo(
      ViSession   vi,
      ViStatus    *primaryError,
      ViStatus    *secondaryError,
      ViChar      errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

   ViStatus _VI_FUNC niDMM_ClearErrorInfo(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_error_query(
      ViSession   vi,
      ViStatus    *errorCode,
      ViChar      errMessage[]);

   ViStatus _VI_FUNC niDMM_Configure(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    minFrequency,
      ViReal64    maxFrequency);

   ViStatus _VI_FUNC niDMM_ConfigureMeasurement(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolution);

   ViStatus _VI_FUNC niDMM_ConfigureSampleDelayMode(
      ViSession   vi,
      ViInt32     sampleDelayMode);

   ViStatus _VI_FUNC niDMM_Measure(
      ViSession   vi,
      ViInt32     measFunction,
      ViInt32     maxTime,
      ViReal64    *reading);

   ViStatus _VI_FUNC niDMM_MeasureMultiPoint(
      ViSession   vi,
      ViInt32     function,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    readingArray[],
      ViInt32     *actualPts);

   ViStatus _VI_FUNC niDMM_ConfigureMeasurementComplete(
      ViSession   vi,
      ViInt32     destination,
      ViInt32     slope);

   ViStatus _VI_FUNC niDMM_SendSWTrigger(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_SetPowerlineFrequency(
      ViSession   vi,
      ViReal64    frequency);

   ViStatus _VI_FUNC niDMM_ConfigureStartTrigger(
      ViSession   vi,
      ViInt32     source,
      ViInt32     slope);

   ViStatus _VI_FUNC niDMM_SetAutoZero(
      ViSession   vi,
      ViInt32     enable);

   ViStatus _VI_FUNC niDMM_GetDigitsOfPrecision(
      ViSession   vi,
      ViReal64    *digits);

   ViStatus _VI_FUNC niDMM_ConvertDigitsToAbsolute(
      ViInt32   productID,
      ViInt32   function,
      ViReal64  range,
      ViReal64  resolution,
      ViPReal64 absoluteUnits);

   ViStatus _VI_FUNC niDMM_ConvertAbsoluteToDigits(
      ViInt32   productID,
      ViInt32   function,
      ViReal64  range,
      ViReal64  resolution,
      ViPReal64 digits);

   ViStatus _VI_FUNC niDMM_FormatMeasDigitsResolution(
      ViInt32  productID,
      ViInt32  function,
      ViReal64 range,
      ViReal64 resolution,
      ViReal64 reading,
      ViChar   modeString[],
      ViChar   rangeString[],
      ViChar   dataString[]);

   ViStatus _VI_FUNC niDMM_FormatMeasAbsoluteResolution(
      ViInt32  productID,
      ViInt32  function,
      ViReal64 range,
      ViReal64 resolution,
      ViReal64 reading,
      ViChar   modeString[],
      ViChar   rangeString[],
      ViChar   dataString[]);

   ViStatus _VI_FUNC niDMM_FormatMeas(
      ViInt32     function,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    reading,
      ViChar      modeString[],
      ViChar      rangeString[],
      ViChar      dataString[]);

   ViStatus _VI_FUNC niDMM_FormatMeasAbsolute(
      ViInt32     function,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    reading,
      ViChar      modeString[],
      ViChar      rangeString[],
      ViChar      dataString[]);

   ViStatus _VI_FUNC niDMM_CalculateAccuracy(
      ViSession   vi,
      ViReal64    frequency,
      ViReal64    *multiplier,
      ViReal64    *offset);

   ViStatus _VI_FUNC niDMM_GetViReal64Type(
      ViSession   vi,
      ViReal64    value,
      ViInt32*    type);

   /*********************************************************************************
   * This section lists constants for some of the error codes returned by NI-DMM.   *
   * Do not use these constants in your drivers and applications as they may vary   *
   * by driver release or device model.                                             *
   *********************************************************************************/

   #define NIDMM_ERROR_MAX_TIME_EXCEEDED              IVIDMM_ERROR_MAX_TIME_EXCEEDED        // 0xBFFA2003 (-1074126845)
   #define NIDMM_ERROR_UNKNOWN_DEVICE                 (NIDMM_ERROR_BASE + 0L)               // 0xBFFA4000 (-1074118656)
   #define NIDMM_ERROR_INVALID_DESCRIPTOR             (NIDMM_ERROR_BASE + 1L)               // 0xBFFA4001 (-1074118655)
   #define NIDMM_ERROR_INVALID_DRIVER_SETUP           (NIDMM_ERROR_BASE + 2L)               // 0xBFFA4002 (-1074118654)
   #define NIDMM_ERROR_ATTRIBUTE_INVALIDATED          (NIDMM_ERROR_BASE + 3L)               // 0xBFFA4003 (-1074118653)
   #define NIDMM_ERROR_INVALID_TRIG                   (NIDMM_ERROR_BASE + 4L)               // 0xBFFA4004 (-1074118652)
   #define NIDMM_ERROR_TRANSFER_IN_PROGRESS           (NIDMM_ERROR_BASE + 5L)               // 0xBFFA4005 (-1074118651)
   #define NIDMM_ERROR_INTERNAL                       (NIDMM_ERROR_BASE + 6L)               // 0xBFFA4006 (-1074118650)
   #define NIDMM_ERROR_NUM_SESSIONS_EXCEEDED          (NIDMM_ERROR_BASE + 7L)               // 0xBFFA4007 (-1074118649)
   #define NIDMM_ERROR_REV_QUERY_FAILURE              (NIDMM_ERROR_BASE + 8L)               // 0xBFFA4008 (-1074118648)
   #define NIDMM_ERROR_AC_TEST_FAILURE                (NIDMM_ERROR_BASE + 9L)               // 0xBFFA4009 (-1074118647)
   #define NIDMM_ERROR_DC_TEST_FAILURE                (NIDMM_ERROR_BASE + 10L)              // 0xBFFA400A (-1074118646)
   #define NIDMM_ERROR_RESISTANCE_TEST_FAILURE        (NIDMM_ERROR_BASE + 11L)              // 0xBFFA400B (-1074118645)
   #define NIDMM_ERROR_INVALID_SCAN_CONFIG            (NIDMM_ERROR_BASE + 12L)              // 0xBFFA400C (-1074118644)
   #define NIDMM_ERROR_INVALID_AUTO_RANGE             (NIDMM_ERROR_BASE + 13L)              // 0xBFFA400D (-1074118643)
   #define NIDMM_ERROR_INVALID_RESOLUTION             (NIDMM_ERROR_BASE + 14L)              // 0xBFFA400E (-1074118642)
   #define NIDMM_ERROR_DATA_NOT_AVAILABLE             (NIDMM_ERROR_BASE + 15L)              // 0xBFFA400F (-1074118641)
   #define NIDMM_ERROR_SELF_CAL_OVERRANGE             (NIDMM_ERROR_BASE + 16L)              // 0xBFFA4010 (-1074118640)
   #define NIDMM_ERROR_DEVICE_IN_USE_BY_PROC          (NIDMM_ERROR_BASE + 17L)              // 0xBFFA4011 (-1074118639)
   #define NIDMM_ERROR_EXT_TRIG_LINE_IN_USE           (NIDMM_ERROR_BASE + 18L)              // 0xBFFA4012 (-1074118638)
   #define NIDMM_ERROR_CALIBRATION                    (NIDMM_ERROR_BASE + 19L)              // 0xBFFA4013 (-1074118637)
   #define NIDMM_ERROR_DRIVER_INITIALIZATION          (NIDMM_ERROR_BASE + 20L)              // 0xBFFA4014 (-1074118636)
   #define NIDMM_ERROR_BUFFER_OVERWRITE               (NIDMM_ERROR_BASE + 21L)              // 0xBFFA4015 (-1074118635)
   #define NIDMM_ERROR_INVALID_MODE                   (NIDMM_ERROR_BASE + 22L)              // 0xBFFA4016 (-1074118634)

   #define NIDMM_ERROR_SELF_TEST_FAILURE              (NIDMM_ERROR_BASE + 23L)              // 0xBFFA4017 (-1074118633)
   #define NIDMM_ERROR_WAVEFORM_CONFIG                (NIDMM_ERROR_BASE + 24L)              // 0xBFFA4018 (-1074118632)
   #define NIDMM_ERROR_WAVEFORM_ACQ_TIME              (NIDMM_ERROR_BASE + 25L)              // 0xBFFA4019 (-1074118631)
   #define NIDMM_ERROR_INVALID_MEAS_COMP_DEST         (NIDMM_ERROR_BASE + 26L)              // 0xBFFA401A (-1074118630)
   #define NIDMM_ERROR_CABLE_COMP_NOT_ALLOWED         (NIDMM_ERROR_BASE + 27L)              // 0xBFFA401B (-1074118629)
   #define NIDMM_ERROR_INVALID_CABLE_COMP_VALUE       (NIDMM_ERROR_BASE + 28L)              // 0xBFFA401C (-1074118628)
   #define NIDMM_ERROR_CABLE_COMP_FAILED              (NIDMM_ERROR_BASE + 29L)              // 0xBFFA401D (-1074118627)
   #define NIDMM_ERROR_INVALID_CABLE_COMP_SETUP       (NIDMM_ERROR_BASE + 30L)              // 0xBFFA401E (-1074118626)
   #define NIDMM_ERROR_SERIAL_PORT_ERROR              (NIDMM_ERROR_BASE + 31L)              // 0xBFFA401F (-1074118625)
   #define NIDMM_ERROR_AVERAGING_NOT_ALLOWED          (NIDMM_ERROR_BASE + 32L)              // 0xBFFA4020 (-1074118624)
   #define NIDMM_ERROR_COMMIT_WHILE_RUNNING           (NIDMM_ERROR_BASE + 33L)              // 0xBFFA4021 (-1074118623)
   #define NIDMM_ERROR_INVALID_BUFFER_SIZE            (NIDMM_ERROR_BASE + 34L)              // 0xBFFA4022 (-1074118622)
   #define NIDMM_ERROR_INVALID_APERTURE_AVG_TIME      (NIDMM_ERROR_BASE + 35L)              // 0xBFFA4023 (-1074118621)
   #define NIDMM_ERROR_TEMPERATURE_RESOLUTION         (NIDMM_ERROR_BASE + 36L)              // 0xBFFA4024 (-1074118620)

   #define NIDMM_ERROR_FIRMWARE_LOAD                  (NIDMM_ERROR_BASE + 800L)             // 0xBFFA4320 (-1074117856)
   #define NIDMM_ERROR_DRIVER_TIMEOUT                 (NIDMM_ERROR_BASE + 801L)             // 0xBFFA4321 (-1074117855)
   #define NIDMM_ERROR_ACQ_IN_PROGRESS                (NIDMM_ERROR_BASE + 802L)             // 0xBFFA4322 (-1074117854)
   #define NIDMM_ERROR_VERSION_MISMATCH               (NIDMM_ERROR_BASE + 803L)             // 0xBFFA4323 (-1074117853)
   #define NIDMM_ERROR_EEPROM_NOT_RESERVED            (NIDMM_ERROR_BASE + 804L)             // 0xBFFA4324 (-1074117852)
   #define NIDMM_ERROR_SET_SA_SOURCE_TO_AUXIO         (NIDMM_ERROR_BASE + 805L)             // 0xBFFA4325 (-1074117851)
   #define NIDMM_ERROR_SCANLIST_SIZE_EXCEEDED         (NIDMM_ERROR_BASE + 806L)             // 0xBFFA4326 (-1074117850)
   #define NIDMM_ERROR_FEATURE_NOT_SUPPORTED          (NIDMM_ERROR_BASE + 807L)             // 0xBFFA4327 (-1074117849)
   #define NIDMM_ERROR_BAD_READ                       (NIDMM_ERROR_BASE + 808L)             // 0xBFFA4328 (-1074117848)
   #define NIDMM_ERROR_AZ_REQUIRED                    (NIDMM_ERROR_BASE + 809L)             // 0xBFFA4329 (-1074117847)
   #define NIDMM_ERROR_MAX_SETTLE_TIME_EXCEEDED       (NIDMM_ERROR_BASE + 810L)             // 0xBFFA432A (-1074117846)
   #define NIDMM_ERROR_AZ_REQUIRED_FOR_75             (NIDMM_ERROR_BASE + 812L)             // 0xBFFA432C (-1074117844)

   #define NIDMM_ERROR_INTERNAL_HARDWARE              (NIDMM_ERROR_BASE + 900L)             // 0xBFFA4384 (-1074117756)
   #define NIDMM_ERROR_EEPROM_WRITE                   (NIDMM_ERROR_BASE + 901L)             // 0xBFFA4385 (-1074117755)
   #define NIDMM_ERROR_SERIAL_PORT_RESET_FAIL         (NIDMM_ERROR_BASE + 902L)             // 0xBFFA4386 (-1074117754)
   #define NIDMM_ERROR_DEVICE_NOT_READY               (NIDMM_ERROR_BASE + 903L)             // 0xBFFA4387 (-1074117753)
   #define NIDMM_ERROR_HARDWARE_FIFO_OVERFLOW         (NIDMM_ERROR_BASE + 904L)             // 0xBFFA4388 (-1074117752)
   #define NIDMM_ERROR_HARDWARE_STATUS_INVALID        (NIDMM_ERROR_BASE + 905L)             // 0xBFFA4389 (-1074117751)

   #define NIDMM_ERROR_EXTCAL_INVALID_PASSWORD        (NIDMM_ERROR_EXTCAL_ERROR_BASE + 0L)  // 0xBFFA4200 (-1074118144)
   #define NIDMM_ERROR_EXTCAL_INCOMPLETE_CAL          (NIDMM_ERROR_EXTCAL_ERROR_BASE + 1L)  // 0xBFFA4201 (-1074118143)
   #define NIDMM_ERROR_EXTCAL_CAL_SESSION_NOT_VALID   (NIDMM_ERROR_EXTCAL_ERROR_BASE + 2L)  // 0xBFFA4202 (-1074118142)
   #define NIDMM_ERROR_EXTCAL_SIMULATION_NOT_ALLOWED  (NIDMM_ERROR_EXTCAL_ERROR_BASE + 3L)  // 0xBFFA4203 (-1074118141)
   #define NIDMM_ERROR_EXTCAL_RESOURCE_NOT_AVAILABLE  (NIDMM_ERROR_EXTCAL_ERROR_BASE + 4L)  // 0xBFFA4204 (-1074118140)
   #define NIDMM_ERROR_EXTCAL_SESSION_ALREADY_OPEN    (NIDMM_ERROR_EXTCAL_ERROR_BASE + 6L)  // 0xBFFA4206 (-1074118138)
   #define NIDMM_ERROR_EXTCAL_IMPROPER_CLOSE          (NIDMM_ERROR_EXTCAL_ERROR_BASE + 7L)  // 0xBFFA4207 (-1074118137)
   #define NIDMM_ERROR_EXTCAL_IMPROPER_INIT           (NIDMM_ERROR_EXTCAL_ERROR_BASE + 8L)  // 0xBFFA4208 (-1074118136)
   #define NIDMM_ERROR_EXTCAL_BAD_LEAKAGE_RESISTANCE  (NIDMM_ERROR_EXTCAL_ERROR_BASE + 9L)  // 0xBFFA4209 (-1074118135)
   #define NIDMM_ERROR_EXTCAL_DEPENDENCY_CHECK_FAILED (NIDMM_ERROR_EXTCAL_ERROR_BASE + 10L) // 0xBFFA420A (-1074118134)
   #define NIDMM_ERROR_EXTCAL_BAD_GAIN                (NIDMM_ERROR_EXTCAL_ERROR_BASE + 11L) // 0xBFFA420B (-1074118133)
   #define NIDMM_ERROR_EXTCAL_BAD_FILTER              (NIDMM_ERROR_EXTCAL_ERROR_BASE + 12L) // 0xBFFA420C (-1074118132)
   #define NIDMM_ERROR_EXTCAL_BAD_LC_COEFF            (NIDMM_ERROR_EXTCAL_ERROR_BASE + 13L) // 0xBFFA420D (-1074118131)
   #define NIDMM_ERROR_EXTCAL_BAD_LINEARIZATION       (NIDMM_ERROR_EXTCAL_ERROR_BASE + 14L) // 0xBFFA420E (-1074118130)
   #define NIDMM_ERROR_EXTCAL_BAD_OFFSET              (NIDMM_ERROR_EXTCAL_ERROR_BASE + 15L) // 0xBFFA420F (-1074118129)
   #define NIDMM_ERROR_EXTCAL_LEAKAGE_DEPRECATED      (NIDMM_ERROR_EXTCAL_ERROR_BASE + 16L) // 0xBFFA4210 (-1074118128)



   /****************************************************************************
    *---------------------------- End Include File ----------------------------*
    ****************************************************************************/

   #if defined(__cplusplus) || defined(__cplusplus__)
}
   #endif

#endif // __NIDMM__HEADER_OBSOLETE
