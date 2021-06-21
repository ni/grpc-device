/****************************************************************************
 *    NI-FGEN Instrument Driver for National Instruments Signal Generators
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 1998-2017.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niFgenObsolete.h
 * Purpose:  NI-FGEN Instrument Driver for National Instruments Signal Generators
 *           Obsolete functions and attributes declarations.
 *
 ****************************************************************************/

#ifndef __NIFGENOBSOLETE_HEADER
#define __NIFGENOBSOLETE_HEADER

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/*  Compatibility with older versions ------*/

/*-  Deprecated Attributes and Values --------*/
//
// Obsoleted prior to NI-FGEN 2.4
//
#define NIFGEN_ATTR_SPECIFIC_PREFIX                         IVI_ATTR_SPECIFIC_DRIVER_PREFIX              /* ViString, Read-only */
#define NIFGEN_ATTR_DRIVER_MAJOR_VERSION                    IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION       /* ViInt32, Read-only */
#define NIFGEN_ATTR_DRIVER_MINOR_VERSION                    IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION       /* ViInt32, Read-only */
#define NIFGEN_ATTR_DRIVER_REVISION                         IVI_ATTR_SPECIFIC_DRIVER_REVISION            /* ViString, Read-only */
#define NIFGEN_ATTR_ENGINE_MAJOR_VERSION                    IVI_ATTR_ENGINE_MAJOR_VERSION                /* ViInt32, Read-only */
#define NIFGEN_ATTR_ENGINE_MINOR_VERSION                    IVI_ATTR_ENGINE_MINOR_VERSION                /* ViInt32, Read-only */
#define NIFGEN_ATTR_ENGINE_REVISION                         IVI_ATTR_ENGINE_REVISION                     /* ViString, Read-only */
#define NIFGEN_ATTR_VISA_RM_SESSION                         IVI_ATTR_VISA_RM_SESSION                     /* ViSession, Read-only */
#define NIFGEN_ATTR_IO_SESSION                              IVI_ATTR_IO_SESSION                          /* ViSession, Read-only */
#define NIFGEN_ATTR_DEFER_UPDATE                            IVI_ATTR_DEFER_UPDATE                        /* ViBoolean */
#define NIFGEN_ATTR_RETURN_DEFERRED_VALUES                  IVI_ATTR_RETURN_DEFERRED_VALUES              /* ViBoolean */
#define NIFGEN_ATTR_PRIMARY_ERROR                           IVI_ATTR_PRIMARY_ERROR                       /* ViInt32   */
#define NIFGEN_ATTR_SECONDARY_ERROR                         IVI_ATTR_SECONDARY_ERROR                     /* ViInt32   */
#define NIFGEN_ATTR_ERROR_ELABORATION                       IVI_ATTR_ERROR_ELABORATION                   /* ViString  */
#define NIFGEN_ATTR_CYCLE_COUNT                             IVIFGEN_ATTR_BURST_COUNT                     /* ViInt32, multi-channel */
#define NIFGEN_VAL_TTL7                                     IVIFGEN_VAL_TTL7
#define NIFGEN_VAL_RTSI_CLOCK                               IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK
#define NIFGEN_ATTR_NUM_CHANNELS                            IVI_ATTR_NUM_CHANNELS                        /* ViInt32,  Read-only */
#define NIFGEN_ATTR_QUERY_INSTR_STATUS                      IVI_ATTR_QUERY_INSTR_STATUS                  /* ViBoolean */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION           IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION       /* ViInt32  */
#define NIFGEN_ATTR_SPECIFIC_DRIVER_MINOR_VERSION           IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION       /* ViInt32  */
#define NIFGEN_VAL_SW_TRIG_FUNC                             IVIFGEN_VAL_SOFTWARE_TRIG
#define NIFGEN_ATTR_OSP_DATA_RATE                           NIFGEN_ATTR_OSP_IQ_RATE                      /* ViReal64 */

//
// Obsoleted in NI-FGEN 2.4
//
/*- Defined values for attribute NIFGEN_ATTR_TRIGGER_SOURCE ------------*/
#define NIFGEN_VAL_IMMEDIATE                    0L
#define NIFGEN_VAL_EXTERNAL                     IVIFGEN_VAL_EXTERNAL
#define NIFGEN_VAL_SOFTWARE_TRIG                IVIFGEN_VAL_SOFTWARE_TRIG
#define NIFGEN_VAL_PXI_STAR                     IVIFGEN_VAL_PXI_STAR
#define NIFGEN_VAL_RTSI_0                       IVIFGEN_VAL_RTSI_0
#define NIFGEN_VAL_RTSI_1                       IVIFGEN_VAL_RTSI_1
#define NIFGEN_VAL_RTSI_2                       IVIFGEN_VAL_RTSI_2
#define NIFGEN_VAL_RTSI_3                       IVIFGEN_VAL_RTSI_3
#define NIFGEN_VAL_RTSI_4                       IVIFGEN_VAL_RTSI_4
#define NIFGEN_VAL_RTSI_5                       IVIFGEN_VAL_RTSI_5
#define NIFGEN_VAL_RTSI_6                       IVIFGEN_VAL_RTSI_6
#define NIFGEN_VAL_TTL0                         IVIFGEN_VAL_TTL0
#define NIFGEN_VAL_TTL1                         IVIFGEN_VAL_TTL1
#define NIFGEN_VAL_TTL2                         IVIFGEN_VAL_TTL2
#define NIFGEN_VAL_TTL3                         IVIFGEN_VAL_TTL3
#define NIFGEN_VAL_TTL4                         IVIFGEN_VAL_TTL4
#define NIFGEN_VAL_TTL5                         IVIFGEN_VAL_TTL5
#define NIFGEN_VAL_TTL6                         IVIFGEN_VAL_TTL6

/*- Defined values for attribute NIFGEN_ATTR_UPDATE_CLOCK_SOURCE ------------*/
#define NIFGEN_VAL_INTERNAL                     (0L)
/*NIFGEN_VAL_EXTERNAL*/

/*- Defined values for signal routing ----------------------------------*/
#define NIFGEN_VAL_PLL_REF_SOURCE               (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 3L)
#define NIFGEN_VAL_PFI_1                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 12L)
#define NIFGEN_VAL_PFI_2                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 13L)
#define NIFGEN_VAL_PFI_3                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 14L)
#define NIFGEN_VAL_PFI_4                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 15L)
#define NIFGEN_VAL_PFI_5                        (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 16L)
#define NIFGEN_VAL_UPDATE_CLOCK                 (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 17L)
#define NIFGEN_VAL_OTHER_TERMINAL               (IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 18L)

/*- Defined values for attribute NIFGEN_ATTR_REF_CLOCK_SOURCE ----------*/
#define NIFGEN_VAL_REF_CLOCK_INTERNAL           IVIFGEN_VAL_REF_CLOCK_INTERNAL
#define NIFGEN_VAL_REF_CLOCK_EXTERNAL           IVIFGEN_VAL_REF_CLOCK_EXTERNAL
#define NIFGEN_VAL_REF_CLOCK_RTSI_CLOCK         IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK
#define NIFGEN_VAL_REF_CLOCK_TTL7               IVIFGEN_VAL_TTL7
#define NIFGEN_VAL_REF_IN                       (NIFGEN_VAL_CLK_SRC_BASE + 0L)
#define NIFGEN_VAL_PXI_CLK10                    (NIFGEN_VAL_CLK_SRC_BASE + 1L)
#define NIFGEN_VAL_CLK_IN                       (NIFGEN_VAL_CLK_SRC_BASE + 2L)
#define NIFGEN_VAL_DDC_CLK_IN                   (NIFGEN_VAL_CLK_SRC_BASE + 3L)

/*- Attributes ---------------------*/
#define NIFGEN_ATTR_UPDATE_CLOCK_SOURCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L) /* ViInt32 */
#define NIFGEN_ATTR_REF_CLOCK_SOURCE        IVIFGEN_ATTR_REF_CLOCK_SOURCE         /* ViInt32 */

//
// Obsoleted in NI-FGEN 2.6.1
//
#define NIFGEN_ATTR_OPERATION_MODE           IVIFGEN_ATTR_OPERATION_MODE            /* ViInt32 */
#define NIFGEN_ATTR_ACTUAL_ARB_SAMPLE_RATE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109L) /* ViReal64, read-only */
#define NIFGEN_ATTR_DAQMX_TASK              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 221L) /* ViInt32 */

/*-  Deprecated Types --------------*/

//
// Obsoleted in NI-FGEN 2.4
//
#ifndef NIFGEN_NICOMPLEXNUMBER_TYPE_UNDEFINED
   typedef NIComplexNumber niFgen_ComplexF64;
#endif



/*-  Deprecated Functions ----------*/

//
// Obsoleted in NI-FGEN 2.0
//
ViStatus _VI_FUNC niFgen_IviInit(
   ViChar instrName[],
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViSession vi);

ViStatus _VI_FUNC niFgen_IviClose(
   ViSession vi);

ViStatus _VI_FUNC niFgen_GetErrorInfo(
   ViSession vi,
   ViStatus *primaryError,
   ViStatus *secondaryError,
   ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niFgen_ClearErrorInfo(
   ViSession vi);

ViStatus _VI_FUNC niFgen_EnableOutput(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC niFgen_DisableOutput(
   ViSession vi,
   ViConstString channelName);

ViStatus _VI_FUNC  niFgen_ConfigureTrigger(
   ViSession vi,
   ViConstString channelName,
   ViInt32 trigSource,
   ViInt32 cycleCount);

ViStatus _VI_FUNC  niFgen_SendSWTrigger(
   ViSession vi);


//
// Obsoleted in NI-FGEN 2.2
//

// use niFgen_CreateWaveformF64 instead
ViStatus _VI_FUNC  niFgen_CreateArbWaveform(
   ViSession vi,
   ViInt32 wfmSize,
   ViReal64 wfmData[],
   ViInt32 *wfmHandle);

// use niFgen_CreateWaveformI16 instead
ViStatus _VI_FUNC  niFgen_CreateBinary16ArbWaveform(
   ViSession vi,
   ViInt32 wfmSize,
   ViInt16 wfmData[],
   ViInt32 *wfmHandle);

//
// Obsoleted in NI-FGEN 2.3
//

// use niFgen_SetAttributeViReal64 with attribute NIFGEN_ATTR_ARB_GAIN instead
ViStatus _VI_FUNC  niFgen_ConfigureGain(
   ViSession vi,
   ViConstString channelName,
   ViReal64 Gain);

//
// Obsoleted in NI-FGEN 2.4
//

// use niFgen_ConfigureReferenceClock instead
ViStatus _VI_FUNC niFgen_ConfigureRefClockSource(
   ViSession vi,
   ViInt32 referenceClockSource);

// use niFgen_ConfigureReferenceClock instead
ViStatus _VI_FUNC niFgen_ConfigureRefClockFrequency(
   ViSession vi,
   ViReal64 frequency);

// use niFgen_ConfigureSampleClockSource instead
ViStatus _VI_FUNC niFgen_ConfigureUpdateClockSource(
   ViSession vi,
   ViInt32 source);

// use niFgen_SendSoftwareEdgeTrigger instead
ViStatus _VI_FUNC niFgen_SendSoftwareTrigger(
   ViSession vi);

// use the configure trigger specific to the trigger instead
ViStatus _VI_FUNC  niFgen_ConfigureTriggerSource(
   ViSession vi,
   ViConstString channelName,
   ViInt32 trigSource);

//
// Obsoleted in NI-FGEN 2.7
//

ViStatus _VI_FUNC niFgen_CalAdjustCalADC(
   ViSession vi,
   ViReal64* voltagesMeasuredExternally,
   ViReal64* voltagesMeasuredWithCalADC);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NIFGENOBSOLETE_HEADER */



