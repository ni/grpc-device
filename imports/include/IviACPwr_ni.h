/****************************************************************************
 *                           I V I - A C P W R
 *---------------------------------------------------------------------------
 *    Copyright (c) 2011-2020 National Instruments.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:       IviACPwr_ni.h
 * Purpose:     IviACPwr Class declarations for the Base and Extended
 *              IviACPwr Capabilities.
 ****************************************************************************/

#ifndef IVIACPWR_HEADER
#define IVIACPWR_HEADER

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

#define IVIACPWR_MAJOR_VERSION                        (1L)
#define IVIACPWR_MINOR_VERSION                        (0L)

#define IVIACPWR_CLASS_SPEC_MAJOR_VERSION             (1L)
#define IVIACPWR_CLASS_SPEC_MINOR_VERSION             (2L)

#define IVIACPWR_DRIVER_VENDOR                        "National Instruments"
#ifdef _IVI_mswin64_
#define IVIACPWR_DRIVER_DESCRIPTION                   "IviACPwr Class Driver [Compiled for 64-bit.]"
#else
#define IVIACPWR_DRIVER_DESCRIPTION                   "IviACPwr Class Driver"
#endif

/****************************************************************************
 *------------------------------ Useful Macros -----------------------------*
 ****************************************************************************/


/****************************************************************************
 *------------------ IviACPwr Class Attribute Defines ----------------------*
 ****************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVIACPWR_ATTR_CACHE                                         IVI_ATTR_CACHE                         /* ViBoolean */
#define IVIACPWR_ATTR_RANGE_CHECK                                   IVI_ATTR_RANGE_CHECK                   /* ViBoolean */
#define IVIACPWR_ATTR_QUERY_INSTRUMENT_STATUS                       IVI_ATTR_QUERY_INSTRUMENT_STATUS       /* ViBoolean */
#define IVIACPWR_ATTR_RECORD_COERCIONS                              IVI_ATTR_RECORD_COERCIONS              /* ViBoolean */
#define IVIACPWR_ATTR_SIMULATE                                      IVI_ATTR_SIMULATE                      /* ViBoolean */
#define IVIACPWR_ATTR_INTERCHANGE_CHECK                             IVI_ATTR_INTERCHANGE_CHECK             /* ViBoolean */
#define IVIACPWR_ATTR_SPY                                           IVI_ATTR_SPY                           /* ViBoolean */
#define IVIACPWR_ATTR_USE_SPECIFIC_SIMULATION                       IVI_ATTR_USE_SPECIFIC_SIMULATION       /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIACPWR_ATTR_GROUP_CAPABILITIES                            IVI_ATTR_GROUP_CAPABILITIES            /* ViString, read-only */
#define IVIACPWR_ATTR_FUNCTION_CAPABILITIES                         IVI_ATTR_FUNCTION_CAPABILITIES         /* ViString, read-only */

        /*- Class Driver Information -*/
#define IVIACPWR_ATTR_CLASS_DRIVER_PREFIX                           IVI_ATTR_CLASS_DRIVER_PREFIX                       /* ViString, read-only */
#define IVIACPWR_ATTR_CLASS_DRIVER_VENDOR                           IVI_ATTR_CLASS_DRIVER_VENDOR                       /* ViString, read-only */
#define IVIACPWR_ATTR_CLASS_DRIVER_DESCRIPTION                      IVI_ATTR_CLASS_DRIVER_DESCRIPTION                  /* ViString, read-only */
#define IVIACPWR_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION         IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVIACPWR_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION         IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32,  read-only */

        /*- Specific Driver Information -*/
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_PREFIX                        IVI_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString, read-only */
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_LOCATOR                       IVI_ATTR_SPECIFIC_DRIVER_LOCATOR                   /* ViString, read-only */
#define IVIACPWR_ATTR_IO_RESOURCE_DESCRIPTOR                        IVI_ATTR_IO_RESOURCE_DESCRIPTOR                    /* ViString, read-only */
#define IVIACPWR_ATTR_LOGICAL_NAME                                  IVI_ATTR_LOGICAL_NAME                              /* ViString, read-only */
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_VENDOR                        IVI_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString, read-only */
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_DESCRIPTION                   IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString, read-only */
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION      IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIACPWR_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION      IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/
#define IVIACPWR_ATTR_INSTRUMENT_FIRMWARE_REVISION                  IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION   /* ViString, read-only */
#define IVIACPWR_ATTR_INSTRUMENT_MANUFACTURER                       IVI_ATTR_INSTRUMENT_MANUFACTURER        /* ViString, read-only */
#define IVIACPWR_ATTR_INSTRUMENT_MODEL                              IVI_ATTR_INSTRUMENT_MODEL               /* ViString, read-only */
#define IVIACPWR_ATTR_SUPPORTED_INSTRUMENT_MODELS                   IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS    /* ViString, read-only */

        /*- Version Information -*/
#define IVIACPWR_ATTR_CLASS_DRIVER_REVISION                         IVI_ATTR_CLASS_DRIVER_REVISION          /* ViString, read-only */

#define IVIACPWR_ATTR_SPECIFIC_DRIVER_REVISION                      IVI_ATTR_SPECIFIC_DRIVER_REVISION       /* ViString, read-only */

        /*- Driver Setup information -*/
#define IVIACPWR_ATTR_DRIVER_SETUP                                  IVI_ATTR_DRIVER_SETUP                   /* ViString */

    /*- IviACPwr Fundamental Attributes -*/
#define IVIACPWR_ATTR_CURRENT_LIMIT                                 (IVI_CLASS_PUBLIC_ATTR_BASE+ 13L)  /* ViReal64, applies to OutputPhase           */
#define IVIACPWR_ATTR_FREQUENCY                                     (IVI_CLASS_PUBLIC_ATTR_BASE+ 1L)   /* ViReal64                                   */
#define IVIACPWR_ATTR_NUM_PHASES                                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 2L)   /* ViInt32, read-only                         */
#define IVIACPWR_ATTR_OUTPUT_ENABLED                                (IVI_CLASS_PUBLIC_ATTR_BASE+ 14L)  /* ViBoolean, applies to OutputPhase          */
#define IVIACPWR_ATTR_VOLTAGE_LEVEL                                 (IVI_CLASS_PUBLIC_ATTR_BASE+ 16L)  /* ViReal64, applies to OutputPhase           */
#define IVIACPWR_ATTR_WAVEFORM                                      (IVI_CLASS_PUBLIC_ATTR_BASE+ 17L)  /* ViString, applies to OutputPhase           */
#define IVIACPWR_ATTR_OUTPUT_PHASE_COUNT                            (IVI_CLASS_PUBLIC_ATTR_BASE+ 36L)  /* ViInt32, read-only                         */
#define IVIACPWR_ATTR_NUM_VOLTAGE_RANGES                            (IVI_CLASS_PUBLIC_ATTR_BASE+ 15L)  /* ViInt32, read-only, applies to OutputPhase */
#define IVIACPWR_ATTR_VOLTAGE_RANGE                                 (IVI_CLASS_PUBLIC_ATTR_BASE+ 18L)  /* ViReal64, applies to OutputPhase           */
#define IVIACPWR_ATTR_NUM_FREQUENCY_RANGES                          (IVI_CLASS_PUBLIC_ATTR_BASE+ 3L)   /* ViInt32, read-only                         */
#define IVIACPWR_ATTR_FREQUENCY_RANGE                               (IVI_CLASS_PUBLIC_ATTR_BASE+ 4L)   /* ViReal64                                   */

    /* IviACPwrPhase Extended Attributes */
#define IVIACPWR_ATTR_PHASE_ANGLE                                   (IVI_CLASS_PUBLIC_ATTR_BASE+ 19L)  /* ViReal64, applies to OutputPhase */

    /* IviACPwrExternalSync Extended Attributes */
#define IVIACPWR_ATTR_EXTERNAL_SYNC_ENABLED                         (IVI_CLASS_PUBLIC_ATTR_BASE+ 10L)  /* ViBoolean            */
#define IVIACPWR_ATTR_EXTERNAL_SYNC_PHASE_OFFSET                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 11L)  /* ViReal64             */
#define IVIACPWR_ATTR_EXTERNAL_SYNC_LOCKED                          (IVI_CLASS_PUBLIC_ATTR_BASE+ 12L)  /* ViBoolean, read-only */

    /* IviACPwrCurrentProtection Extended Attributes */
#define IVIACPWR_ATTR_CURRENT_PROTECTION_THRESHOLD                  (IVI_CLASS_PUBLIC_ATTR_BASE+ 25L)  /* ViReal64, applies to OutputPhase             */
#define IVIACPWR_ATTR_CURRENT_PROTECTION_DELAY                      (IVI_CLASS_PUBLIC_ATTR_BASE+ 23L)  /* ViReal64, applies to OutputPhase             */
#define IVIACPWR_ATTR_CURRENT_PROTECTION_ENABLED                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 24L)  /* ViBoolean, applies to OutputPhase            */
#define IVIACPWR_ATTR_CURRENT_PROTECTION_TRIPPED                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 26L)  /* ViBoolean, read-only, applies to OutputPhase */

    /* IviACPwrVoltageProtection Extended Attributes */
#define IVIACPWR_ATTR_UNDER_VOLTAGE_PROTECTION_LIMIT                (IVI_CLASS_PUBLIC_ATTR_BASE+ 30L)  /* ViReal64, applies to OutputPhase             */
#define IVIACPWR_ATTR_OVER_VOLTAGE_PROTECTION_LIMIT                 (IVI_CLASS_PUBLIC_ATTR_BASE+ 28L)  /* ViReal64, applies to OutputPhase             */
#define IVIACPWR_ATTR_OVER_VOLTAGE_PROTECTION_ENABLED               (IVI_CLASS_PUBLIC_ATTR_BASE+ 27L)  /* ViBoolean, applies to OutputPhase            */
#define IVIACPWR_ATTR_UNDER_VOLTAGE_PROTECTION_ENABLED              (IVI_CLASS_PUBLIC_ATTR_BASE+ 29L)  /* ViBoolean, applies to OutputPhase            */
#define IVIACPWR_ATTR_VOLTAGE_PROTECTION_TRIPPED                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 31L)  /* ViBoolean, read-only, applies to OutputPhase */

    /* IviACPwrArbWaveform Extended Attributes */
#define IVIACPWR_ATTR_NUM_WAVEFORMS_MAX                             (IVI_CLASS_PUBLIC_ATTR_BASE+ 5L)   /* ViInt32, read-only */
#define IVIACPWR_ATTR_NUM_OPTIMAL_DATA_POINTS                       (IVI_CLASS_PUBLIC_ATTR_BASE+ 6L)   /* ViInt32, read-only */
#define IVIACPWR_ATTR_FIXED_WAVEFORM_COUNT                          (IVI_CLASS_PUBLIC_ATTR_BASE+ 7L)   /* ViInt32, read-only */
#define IVIACPWR_ATTR_USER_WAVEFORM_COUNT                           (IVI_CLASS_PUBLIC_ATTR_BASE+ 8L)   /* ViInt32, read-only */
#define IVIACPWR_ATTR_AVAILABLE_WAVEFORM_COUNT                      (IVI_CLASS_PUBLIC_ATTR_BASE+ 9L)   /* ViInt32, read-only */

    /* IviACPwrImpedance Extended Attributes */
#define IVIACPWR_ATTR_OUTPUT_IMPEDANCE_ENABLED                      (IVI_CLASS_PUBLIC_ATTR_BASE+ 21L)  /* ViBoolean, applies to OutputPhase */
#define IVIACPWR_ATTR_OUTPUT_IMPEDANCE_RESISTIVE                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 22L)  /* ViReal64, applies to OutputPhase  */
#define IVIACPWR_ATTR_OUTPUT_IMPEDANCE_INDUCTIVE                    (IVI_CLASS_PUBLIC_ATTR_BASE+ 20L)  /* ViReal64, applies to OutputPhase  */

    /* IviACPwrDCGeneration Extended Attributes */
#define IVIACPWR_ATTR_DC_MODE                                       (IVI_CLASS_PUBLIC_ATTR_BASE+ 32L)  /* ViInt32, applies to OutputPhase             */
#define IVIACPWR_ATTR_DC_VOLTAGE_LEVEL                              (IVI_CLASS_PUBLIC_ATTR_BASE+ 33L)  /* ViReal64, applies to OutputPhase            */
#define IVIACPWR_ATTR_DC_RANGE_MIN                                  (IVI_CLASS_PUBLIC_ATTR_BASE+ 40L)  /* ViReal64, read-only, applies to OutputPhase */
#define IVIACPWR_ATTR_DC_RANGE_MAX                                  (IVI_CLASS_PUBLIC_ATTR_BASE+ 41L)  /* ViReal64, read-only, applies to OutputPhase */
#define IVIACPWR_ATTR_DC_NUM_RANGES                                 (IVI_CLASS_PUBLIC_ATTR_BASE+ 35L)  /* ViInt32, read-only, applies to OutputPhase  */

    /* IviACPwrVoltageRamp Extended Attributes */
#define IVIACPWR_ATTR_VOLTAGE_RAMP_BUSY                             (IVI_CLASS_PUBLIC_ATTR_BASE+ 37L)  /* ViBoolean, read-only, applies to OutputPhase */

    /* IviACPwrCurrentRamp Extended Attributes */
#define IVIACPWR_ATTR_CURRENT_RAMP_BUSY                             (IVI_CLASS_PUBLIC_ATTR_BASE+ 38L)  /* ViBoolean, read-only, applies to OutputPhase */

    /* IviACPwrFrequencyRamp Extended Attributes */
#define IVIACPWR_ATTR_FREQUENCY_RAMP_BUSY                           (IVI_CLASS_PUBLIC_ATTR_BASE+ 39L)  /* ViBoolean, read-only */

/****************************************************************************
 *----------------- IviACPwr Class Attribute Value Defines -----------------*
 ****************************************************************************/
    /*- Values Defines for IVIACPWR_ATTR_DC_MODE -*/
#define IVIACPWR_VAL_MODE_AC_ONLY                           (0L)
#define IVIACPWR_VAL_MODE_DC_ONLY                           (1L)
#define IVIACPWR_VAL_MODE_AC_DC                             (2L)

#define IVIACPWR_VAL_DC_MODE_CLASS_EXT_BASE                 (500L)
#define IVIACPWR_VAL_DC_MODE_SPECIFIC_EXT_BASE              (1000L)

/****************************************************************************
 *----------------- IviACPwr Function Parameter Value Definitions ----------*
 ****************************************************************************/

    /*- Fetch Measurement -*/
#define IVIACPWR_VAL_MEASURE_VOLTAGE_RMS_LN                 (0L)
#define IVIACPWR_VAL_MEASURE_CURRENT_RMS                    (1L)
#define IVIACPWR_VAL_MEASURE_FREQUENCY                      (2L)
#define IVIACPWR_VAL_MEASURE_VOLTAGE_DC                     (3L)
#define IVIACPWR_VAL_MEASURE_CURRENT_DC                     (4L)
#define IVIACPWR_VAL_MEASURE_POWER_FACTOR                   (5L)
#define IVIACPWR_VAL_MEASURE_CREST_FACTOR                   (6L)
#define IVIACPWR_VAL_MEASURE_CURRENT_PEAK                   (7L)
#define IVIACPWR_VAL_MEASURE_POWER_VA                       (8L)
#define IVIACPWR_VAL_MEASURE_POWER_REAL                     (9L)
#define IVIACPWR_VAL_MEASURE_POWER_DC                       (10L)
#define IVIACPWR_VAL_MEASURE_PHASE_ANGLE                    (11L)
#define IVIACPWR_VAL_MEASURE_VOLTAGE_RMS_LL                 (12L)
#define IVIACPWR_VAL_MEASURE_CURRENT_OHD                    (13L)
#define IVIACPWR_VAL_MEASURE_CURRENT_EHD                    (14L)
#define IVIACPWR_VAL_MEASURE_CURRENT_THD                    (15L)
#define IVIACPWR_VAL_MEASURE_VOLTAGE_OHD                    (16L)
#define IVIACPWR_VAL_MEASURE_VOLTAGE_EHD                    (17L)
#define IVIACPWR_VAL_MEASURE_VOLTAGE_THD                    (18L)

    /*- Fetch Measurement Array -*/
#define IVIACPWR_VAL_MEASURE_ARRAY_CURRENT_HARMONIC_PHASE   (0L)
#define IVIACPWR_VAL_MEASURE_ARRAY_CURRENT_HARMONIC_ABS     (1L)
#define IVIACPWR_VAL_MEASURE_ARRAY_CURRENT_HARMONIC_PCT     (2L)
#define IVIACPWR_VAL_MEASURE_ARRAY_VOLTAGE_HARMONIC_PHASE   (3L)
#define IVIACPWR_VAL_MEASURE_ARRAY_VOLTAGE_HARMONIC_ABS     (4L)
#define IVIACPWR_VAL_MEASURE_ARRAY_VOLTAGE_HARMONIC_PCT     (5L)
#define IVIACPWR_VAL_MEASURE_ARRAY_CURRENT_CYCLE            (6L)
#define IVIACPWR_VAL_MEASURE_ARRAY_VOLTAGE_CYCLE            (7L)

    /*- Initiate Measurement -*/
#define IVIACPWR_VAL_MEASUREMENT_GROUP_BASE                 (1L)
#define IVIACPWR_VAL_MEASUREMENT_GROUP_HARMONIC             (2L)
#define IVIACPWR_VAL_MEASUREMENT_GROUP_DISTORTION           (4L)
#define IVIACPWR_VAL_MEASUREMENT_GROUP_WAVEFORM             (8L)

    /*- Query Arbitrary Waveform Catalog -*/
#define IVIACPWR_VAL_WAVEFORM_CATALOG_FIXED                 (0L)
#define IVIACPWR_VAL_WAVEFORM_CATALOG_USER                  (1L)
#define IVIACPWR_VAL_WAVEFORM_CATALOG_ALL                   (2L)

/****************************************************************************
 *--------- IviACPwr Class Instrument Driver Function Declarations ---------*
 ****************************************************************************/
    /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviACPwr_init(ViRsrc logicalName,
                                ViBoolean idQuery,
                                ViBoolean resetDevice,
                                ViSession *vi);

ViStatus _VI_FUNC IviACPwr_close(ViSession vi);

ViStatus _VI_FUNC IviACPwr_reset(ViSession vi);

ViStatus _VI_FUNC IviACPwr_self_test(ViSession vi,
                                     ViInt16 *selfTestResult,
                                     ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviACPwr_error_query(ViSession vi,
                                       ViInt32 *errorCode,
                                       ViChar errorMessage[]);

ViStatus _VI_FUNC IviACPwr_error_message(ViSession vi,
                                         ViStatus statusCode,
                                         ViChar message[]);

ViStatus _VI_FUNC IviACPwr_revision_query(ViSession vi,
                                          ViChar driverRev[],
                                          ViChar instrRev[]);

    /*- Utility Functions -*/
ViStatus _VI_FUNC IviACPwr_InvalidateAllAttributes(ViSession vi);

ViStatus _VI_FUNC IviACPwr_ResetWithDefaults(ViSession vi);

ViStatus _VI_FUNC IviACPwr_Disable(ViSession vi);


    /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviACPwr_InitWithOptions(ViRsrc logicalName,
                                           ViBoolean IDQuery,
                                           ViBoolean resetDevice,
                                           ViConstString optionString,
                                           ViSession *vi);

    /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviACPwr_GetAttributeViInt32(ViSession vi,
                                               ViConstString PhaseName,
                                               ViAttr attributeId,
                                               ViInt32 *value);

ViStatus _VI_FUNC IviACPwr_SetAttributeViInt32(ViSession vi,
                                               ViConstString PhaseName,
                                               ViAttr attributeId,
                                               ViInt32 value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViInt32(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviACPwr_GetAttributeViInt64(ViSession vi, 
                                               ViConstString PhaseName,
                                               ViAttr attributeId, 
                                               ViInt64 *value);

ViStatus _VI_FUNC IviACPwr_SetAttributeViInt64(ViSession vi, 
                                               ViConstString PhaseName,
                                               ViAttr attributeId,
                                               ViInt64 value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViInt64(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViInt64 value);
#endif

ViStatus _VI_FUNC IviACPwr_GetAttributeViReal64(ViSession vi,
                                                ViConstString PhaseName,
                                                ViAttr attributeId,
                                                ViReal64 *value);

ViStatus _VI_FUNC IviACPwr_SetAttributeViReal64(ViSession vi,
                                                ViConstString PhaseName,
                                                ViAttr attributeId,
                                                ViReal64 value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViReal64(ViSession vi,
                                                  ViConstString PhaseName,
                                                  ViAttr attributeId,
                                                  ViReal64 value);

ViStatus _VI_FUNC IviACPwr_GetAttributeViString(ViSession vi,
                                                ViConstString PhaseName,
                                                ViAttr attributeId,
                                                ViInt32 bufferSize,
                                                ViChar value[]);

ViStatus _VI_FUNC IviACPwr_SetAttributeViString(ViSession vi,
                                                ViConstString PhaseName,
                                                ViAttr attributeId,
                                                ViConstString value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViString(ViSession vi,
                                                  ViConstString PhaseName,
                                                  ViAttr attributeId,
                                                  ViConstString value);

ViStatus _VI_FUNC IviACPwr_GetAttributeViBoolean(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViBoolean *value);

ViStatus _VI_FUNC IviACPwr_SetAttributeViBoolean(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViBoolean value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViBoolean(ViSession vi,
                                                   ViConstString PhaseName,
                                                   ViAttr attributeId,
                                                   ViBoolean value);

ViStatus _VI_FUNC IviACPwr_GetAttributeViSession(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViSession *value);

ViStatus _VI_FUNC IviACPwr_SetAttributeViSession(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViAttr attributeId,
                                                 ViSession value);

ViStatus _VI_FUNC IviACPwr_CheckAttributeViSession(ViSession vi,
                                                   ViConstString PhaseName,
                                                   ViAttr attributeId,
                                                   ViSession value);

    /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviACPwr_LockSession(ViSession vi,
                                       ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviACPwr_UnlockSession(ViSession vi,
                                         ViBoolean *callerHasLock);

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviACPwr_GetError(ViSession vi,
                                    ViStatus *errorCode,
                                    ViInt32 bufferSize,
                                    ViChar description[]);

ViStatus _VI_FUNC IviACPwr_ClearError(ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviACPwr_GetNextInterchangeWarning(ViSession vi,
                                                     ViInt32 bufferSize,
                                                     ViChar warning[]);

ViStatus _VI_FUNC IviACPwr_ClearInterchangeWarnings(ViSession vi);
ViStatus _VI_FUNC IviACPwr_ResetInterchangeCheck(ViSession vi);

ViStatus _VI_FUNC IviACPwr_GetNextCoercionRecord(ViSession vi,
                                                 ViInt32 bufferSize,
                                                 ViChar record[]);

ViStatus _VI_FUNC IviACPwr_GetSpecificDriverCHandle(ViSession vi,
                                                    ViSession* specificDriverCHandle);

ViStatus _VI_FUNC IviACPwr_GetSpecificDriverIUnknownPtr(ViSession vi,
                                                        void* specificDriverIUnknownPtr);

    /*- IviACPwrBase Functions -*/
ViStatus _VI_FUNC IviACPwr_ConfigureCurrentLimit(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViReal64 Limit);
ViStatus _VI_FUNC IviACPwr_ConfigureOutputEnabled(ViSession vi,
                                                  ViConstString PhaseName,
                                                  ViBoolean Enabled);
ViStatus _VI_FUNC IviACPwr_ConfigureVoltageLevel(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViReal64 VoltageLevel);
ViStatus _VI_FUNC IviACPwr_ConfigureVoltageRange(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViReal64 Range);
ViStatus _VI_FUNC IviACPwr_ConfigureFrequency(ViSession vi,
                                              ViReal64 Frequency);
ViStatus _VI_FUNC IviACPwr_ConfigureFrequencyRange(ViSession vi,
                                                   ViReal64 Range);
ViStatus _VI_FUNC IviACPwr_ConfigureWaveform(ViSession vi,
                                             ViConstString PhaseName,
                                             ViConstString WaveformName);
ViStatus _VI_FUNC IviACPwr_QueryVoltageRangeCapabilities(ViSession vi,
                                                         ViConstString PhaseName,
                                                         ViInt32 Range,
                                                         ViConstString WaveformName,
                                                         ViReal64 * MinVoltage,
                                                         ViReal64 * MaxVoltage);
ViStatus _VI_FUNC IviACPwr_QueryFrequencyRangeCapabilities(ViSession vi,
                                                           ViInt32 Range,
                                                           ViReal64 * MinFrequency,
                                                           ViReal64 * MaxFrequency);
ViStatus _VI_FUNC IviACPwr_GetOutputPhaseName(ViSession vi,
                                              ViInt32 Index,
                                              ViInt32 NameBufferSize,
                                              ViChar  Name[]);

    /*- IviACPwrMeasurement Functions -*/
ViStatus _VI_FUNC IviACPwr_InitiateMeasurement(ViSession vi,
                                               ViInt32 Group);
ViStatus _VI_FUNC IviACPwr_FetchMeasurement(ViSession vi,
                                            ViConstString PhaseName,
                                            ViInt32 MeasurementType,
                                            ViReal64 * Measurement);
ViStatus _VI_FUNC IviACPwr_FetchMeasurementArray(ViSession vi,
                                                 ViConstString PhaseName,
                                                 ViInt32 MeasurementType,
                                                 ViInt32 MeasurementBufferSize,
                                                 ViReal64 Measurement[],
                                                 ViInt32 * MeasurementActualSize);

    /*- IviACPwrPhase Functions -*/
ViStatus _VI_FUNC IviACPwr_ConfigurePhaseAngle(ViSession vi,
                                               ViConstString PhaseName,
                                               ViReal64 PhaseAngle);

    /*- IviACPwrExternalSync Functions -*/
ViStatus _VI_FUNC IviACPwr_ConfigureExternalSync(ViSession vi,
                                                 ViBoolean Enabled,
                                                 ViReal64  PhaseOffset);
ViStatus _VI_FUNC IviACPwr_QueryExternalSyncLocked(ViSession vi,
                                                   ViBoolean * Locked);

    /*- IviACPwrCurrentProtection Functions -*/
ViStatus _VI_FUNC IviACPwr_QueryCurrentProtectionTripped(ViSession vi,
                                                         ViConstString PhaseName,
                                                         ViBoolean * Tripped);
ViStatus _VI_FUNC IviACPwr_ResetCurrentProtection(ViSession vi,
                                                  ViConstString PhaseName);
ViStatus _VI_FUNC IviACPwr_ConfigureCurrentProtection(ViSession vi,
                                                      ViConstString PhaseName,
                                                      ViBoolean Enabled,
                                                      ViReal64 Threshold,
                                                      ViReal64 Delay);

    /*- IviACPwrVoltageProtection Functions -*/
ViStatus _VI_FUNC IviACPwr_QueryVoltageProtectionTripped(ViSession vi,
                                                         ViConstString PhaseName,
                                                         ViBoolean * Tripped);
ViStatus _VI_FUNC IviACPwr_ResetVoltageProtection(ViSession vi,
                                                  ViConstString PhaseName);
ViStatus _VI_FUNC IviACPwr_ConfigureVoltageProtection(ViSession vi,
                                                      ViConstString PhaseName,
                                                      ViBoolean UnderEnabled,
                                                      ViBoolean OverEnabled,
                                                      ViReal64 UnderLimit,
                                                      ViReal64 OverLimit);

    /*- IviACPwrArbWaveform Functions -*/
ViStatus _VI_FUNC IviACPwr_ClearArbWaveform(ViSession vi,
                                            ViConstString WaveformName);

ViStatus _VI_FUNC IviACPwr_WriteArbWaveform(ViSession vi,
                                            ViConstString WaveformName,
                                            ViInt32 WaveformDataBufferSize,
                                            ViReal64 WaveformData[]);

ViStatus _VI_FUNC IviACPwr_QueryArbWaveformCatalog(ViSession vi,
                                                   ViInt32 CatalogType,
                                                   ViInt32 CatalogBufferSize,
                                                   ViChar Catalog[]);

    /*- IviACPwrImpedance Functions -*/
ViStatus _VI_FUNC IviACPwr_ConfigureOutputImpedance(ViSession vi,
                                                    ViConstString PhaseName,
                                                    ViBoolean Enabled,
                                                    ViReal64 ResistiveValue,
                                                    ViReal64 InductiveValue);

ViStatus _VI_FUNC IviACPwr_QueryOutputImpedanceCapabilities(ViSession vi,
                                                            ViConstString PhaseName,
                                                            ViReal64 * ResistiveMin,
                                                            ViReal64 * ResistiveMax,
                                                            ViReal64 * InductiveMin,
                                                            ViReal64 * InductiveMax);

    /*- IviACPwrDCGeneration Functions -*/
ViStatus _VI_FUNC IviACPwr_ConfigureDC(ViSession vi,
                                       ViConstString PhaseName,
                                       ViInt32 Mode,
                                       ViReal64 DCVoltageLevel);
ViStatus _VI_FUNC IviACPwr_ConfigureDCRange(ViSession vi,
                                            ViConstString PhaseName,
                                            ViReal64 Minimum,
                                            ViReal64 Maximum);
ViStatus _VI_FUNC IviACPwr_QueryDCCapabilities(ViSession vi,
                                               ViConstString PhaseName,
                                               ViInt32 Range,
                                               ViReal64 * Minimum,
                                               ViReal64 * Maximum);

    /*- IviACPwrVoltageRamp Functions -*/
ViStatus _VI_FUNC IviACPwr_RampVoltage(ViSession vi,
                                       ViConstString PhaseName,
                                       ViReal64 StartVoltage,
                                       ViReal64 EndVoltage,
                                       ViReal64 Duration);
ViStatus _VI_FUNC IviACPwr_QueryVoltageRampBusy(ViSession vi,
                                                ViConstString PhaseName,
                                                ViBoolean * Busy);
ViStatus _VI_FUNC IviACPwr_AbortVoltageRamp(ViSession vi,
                                            ViConstString PhaseName);

    /*- IviACPwrCurrentRamp Functions -*/
ViStatus _VI_FUNC IviACPwr_RampCurrent(ViSession vi,
                                       ViConstString PhaseName,
                                       ViReal64 StartCurrent,
                                       ViReal64 EndCurrent,
                                       ViReal64 Duration);
ViStatus _VI_FUNC IviACPwr_QueryCurrentRampBusy(ViSession vi,
                                                ViConstString PhaseName,
                                                ViBoolean * Busy);
ViStatus _VI_FUNC IviACPwr_AbortCurrentRamp(ViSession vi,
                                            ViConstString PhaseName);

    /*- IviACPwrFrequencyRamp Functions -*/
ViStatus _VI_FUNC IviACPwr_RampFrequency(ViSession vi,
                                         ViReal64 StartFrequency,
                                         ViReal64 EndFrequency,
                                         ViReal64 Duration);
ViStatus _VI_FUNC IviACPwr_QueryFrequencyRampBusy(ViSession vi,
                                                  ViBoolean * Busy);
ViStatus _VI_FUNC IviACPwr_AbortFrequencyRamp(ViSession vi);

/****************************************************************************
 *--------------- IviACPwr Class Error And Completion Codes ----------------*
 ****************************************************************************/
#define IVIACPWR_ERROR_ALL_PHASES_REQUIRED               (IVI_CLASS_ERROR_BASE + 0x0002L)
#define IVIACPWR_ERROR_CURRENT_PROTECTION                (IVI_CLASS_ERROR_BASE + 0x0003L)
#define IVIACPWR_ERROR_DUPLICATE_WAVEFORM_NAME           (IVI_CLASS_ERROR_BASE + 0x0004L)
#define IVIACPWR_ERROR_INVALID_WAVEFORM_NAME             (IVI_CLASS_ERROR_BASE + 0x0005L)
#define IVIACPWR_ERROR_MEASUREMENT_NOT_INITIATED         (IVI_CLASS_ERROR_BASE + 0x0006L)
#define IVIACPWR_ERROR_MEASUREMENT_NOT_SUPPORTED         (IVI_CLASS_ERROR_BASE + 0x0007L)
#define IVIACPWR_ERROR_NO_WAVEFORMS_AVAILABLE            (IVI_CLASS_ERROR_BASE + 0x0008L)
#define IVIACPWR_ERROR_PHASE_VALUES_DIFFERENT            (IVI_CLASS_ERROR_BASE + 0x000AL)
#define IVIACPWR_ERROR_UNSUPPORTED_MEASUREMENT_GROUP     (IVI_CLASS_ERROR_BASE + 0x000BL)
#define IVIACPWR_ERROR_VOLTAGE_PROTECTION                (IVI_CLASS_ERROR_BASE + 0x000CL)
#define IVIACPWR_ERROR_WAVEFORM_IN_USE                   (IVI_CLASS_ERROR_BASE + 0x000EL)
#define IVIACPWR_ERROR_WAVEFORM_NOT_FOUND                (IVI_CLASS_ERROR_BASE + 0x000FL)
#define IVIACPWR_ERROR_WAVEFORM_RESERVED                 (IVI_CLASS_ERROR_BASE + 0x0010L)
#define IVIACPWR_ERROR_WAVEFORM_DC_OFFSET                (IVI_CLASS_ERROR_BASE + 0x000DL)
#define IVIACPWR_ERROR_ALL_PHASES_NOT_SUPPORTED          (IVI_CLASS_ERROR_BASE + 0x0001L)
#define IVIACPWR_ERROR_OUTPUT_ENABLED                    (IVI_CLASS_ERROR_BASE + 0x0009L)

#define IVIACPWR_ERRMSG_ALL_PHASES_REQUIRED              "All phases required."
#define IVIACPWR_ERRMSG_CURRENT_PROTECTION               "Current protection tripped."
#define IVIACPWR_ERRMSG_DUPLICATE_WAVEFORM_NAME          "Duplicate waveform name."
#define IVIACPWR_ERRMSG_INVALID_WAVEFORM_NAME            "Invalid waveform name."
#define IVIACPWR_ERRMSG_MEASUREMENT_NOT_INITIATED        "Measurement not initiated."
#define IVIACPWR_ERRMSG_MEASUREMENT_NOT_SUPPORTED        "Measurement not supported."
#define IVIACPWR_ERRMSG_NO_WAVEFORMS_AVAILABLE           "No waveforms available."
#define IVIACPWR_ERRMSG_PHASE_VALUES_DIFFERENT           "Phase values different."
#define IVIACPWR_ERRMSG_UNSUPPORTED_MEASUREMENT_GROUP    "Unsupported measurement group."
#define IVIACPWR_ERRMSG_VOLTAGE_PROTECTION               "Voltage Protection tripped."
#define IVIACPWR_ERRMSG_WAVEFORM_IN_USE                  "Waveform in use."
#define IVIACPWR_ERRMSG_WAVEFORM_NOT_FOUND               "Waveform not found."
#define IVIACPWR_ERRMSG_WAVEFORM_RESERVED                "Waveform reserved."
#define IVIACPWR_ERRMSG_WAVEFORM_DC_OFFSET               "Waveform DC Offset."
#define IVIACPWR_ERRMSG_ALL_PHASES_NOT_SUPPORTED         "All phases not supported."
#define IVIACPWR_ERRMSG_OUTPUT_ENABLED                   "Output is enabled."

#define IVIACPWR_ERROR_CODES_AND_MSGS \
        { IVIACPWR_ERROR_ALL_PHASES_REQUIRED,            IVIACPWR_ERRMSG_ALL_PHASES_REQUIRED           }, \
        { IVIACPWR_ERROR_CURRENT_PROTECTION,             IVIACPWR_ERRMSG_CURRENT_PROTECTION            }, \
        { IVIACPWR_ERROR_DUPLICATE_WAVEFORM_NAME,        IVIACPWR_ERRMSG_DUPLICATE_WAVEFORM_NAME       }, \
        { IVIACPWR_ERROR_INVALID_WAVEFORM_NAME,          IVIACPWR_ERRMSG_INVALID_WAVEFORM_NAME         }, \
        { IVIACPWR_ERROR_MEASUREMENT_NOT_INITIATED,      IVIACPWR_ERRMSG_MEASUREMENT_NOT_INITIATED     }, \
        { IVIACPWR_ERROR_MEASUREMENT_NOT_SUPPORTED,      IVIACPWR_ERRMSG_MEASUREMENT_NOT_SUPPORTED     }, \
        { IVIACPWR_ERROR_NO_WAVEFORMS_AVAILABLE,         IVIACPWR_ERRMSG_NO_WAVEFORMS_AVAILABLE        }, \
        { IVIACPWR_ERROR_PHASE_VALUES_DIFFERENT,         IVIACPWR_ERRMSG_PHASE_VALUES_DIFFERENT        }, \
        { IVIACPWR_ERROR_UNSUPPORTED_MEASUREMENT_GROUP,  IVIACPWR_ERRMSG_UNSUPPORTED_MEASUREMENT_GROUP }, \
        { IVIACPWR_ERROR_VOLTAGE_PROTECTION,             IVIACPWR_ERRMSG_VOLTAGE_PROTECTION            }, \
        { IVIACPWR_ERROR_WAVEFORM_IN_USE,                IVIACPWR_ERRMSG_WAVEFORM_IN_USE               }, \
        { IVIACPWR_ERROR_WAVEFORM_NOT_FOUND,             IVIACPWR_ERRMSG_WAVEFORM_NOT_FOUND            }, \
        { IVIACPWR_ERROR_WAVEFORM_RESERVED,              IVIACPWR_ERRMSG_WAVEFORM_RESERVED             }, \
        { IVIACPWR_ERROR_WAVEFORM_DC_OFFSET,             IVIACPWR_ERRMSG_WAVEFORM_DC_OFFSET            }, \
        { IVIACPWR_ERROR_ALL_PHASES_NOT_SUPPORTED,       IVIACPWR_ERRMSG_ALL_PHASES_NOT_SUPPORTED      }, \
        { IVIACPWR_ERROR_OUTPUT_ENABLED,                 IVIACPWR_ERRMSG_OUTPUT_ENABLED                }

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* IVIACPWR_HEADER */
