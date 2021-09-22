/****************************************************************************
 *                          NI RF Signal Generator
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2003.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niRFSGObsolete.h
 * Purpose:  NI RF Signal Generator
 *           Obsolete functions and attributes declarations.
 *
 ****************************************************************************/
#ifndef ___niRFSG_niRFSGObsolete_h___
#define ___niRFSG_niRFSGObsolete_h___

#include <ivi.h>

#include <IviRFSigGen.h>


/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIRFSG_MAJOR_VERSION               19     /* Instrument driver major version   */
#define NIRFSG_MINOR_VERSION              100     /* Instrument driver minor version   */

/*  Compatibility with older versions ------*/

/*-  Deprecated Attributes and Values --------*/

/*
   Do not rely on driver support for these items.  These items
   have been deprecated.  Future versions of this driver may not support them
   (code that uses these items may no longer compile).
*/
#define NIRFSG_ATTR_THERMAL_CORRECTION_ENABLED                 NIRFSG_ATTR_AUTOMATIC_THERMAL_CORRECTION
#define NIRFSG_ATTR_SAMPLE_CLOCK_RATE                          NIRFSG_ATTR_IQ_RATE
#define NIRFSG_ATTR_UPCONVERTER_TEMPERATURE                    NIRFSG_ATTR_DEVICE_TEMPERATURE
#define NIRFSG_ATTR_LOCAL_OSCILLATOR_OUT_0_ENABLED             NIRFSG_ATTR_LO_OUT_ENABLED
#define NIRFSG_VAL_REF_CLOCK_SOURCE_PXI_CLK10                  NIRFSG_VAL_REF_CLOCK_SOURCE_PXI_CLK
#define NIRFSG_VAL_PXI_CLK10_STR                               "PXI_CLK10"
#define NIRFSG_ATTR_IF_CARRIER_FREQUENCY                       NIRFSG_ATTR_ARB_CARRIER_FREQUENCY
#define NIRFSG_ATTR_IF_POWER                                   NIRFSG_ATTR_ARB_POWER
#define NIRFSG_ATTR_DIGITAL_IF_EQUALIZATION_ENABLED            NIRFSG_ATTR_DIGITAL_EQUALIZATION_ENABLED
#define NIRFSG_ATTR_DUC_PRE_FILTER_GAIN                        NIRFSG_ATTR_ARB_PRE_FILTER_GAIN
#define NIRFSG_ATTR_DUC_FIR_FILTER_TYPE                        NIRFSG_ATTR_ARB_FILTER_TYPE
#define NIRFSG_ATTR_DUC_FIR_FILTER_ROOT_RAISED_COSINE_ALPHA    NIRFSG_ATTR_ARB_FILTER_ROOT_RAISED_COSINE_ALPHA
#define NIRFSG_ATTR_DUC_FIR_FILTER_RAISED_COSINE_ALPHA         NIRFSG_ATTR_ARB_FILTER_RAISED_COSINE_ALPHA
#define NIRFSG_VAL_DUC_NONE                                    NIRFSG_VAL_ARB_FILTER_TYPE_NONE
#define NIRFSG_VAL_DUC_ROOT_RAISED_COSINE                      NIRFSG_VAL_ARB_FILTER_TYPE_ROOT_RAISED_COSINE
#define NIRFSG_VAL_DUC_RAISED_COSINE                           NIRFSG_VAL_ARB_FILTER_TYPE_RAISED_COSINE
#define NIRFSG_VAL_MARKER_EVENT0                               NIRFSG_VAL_MARKER0
#define NIRFSG_VAL_MARKER_EVENT1                               NIRFSG_VAL_MARKER1
#define NIRFSG_VAL_MARKER_EVENT2                               NIRFSG_VAL_MARKER2
#define NIRFSG_VAL_MARKER_EVENT3                               NIRFSG_VAL_MARKER3
#define NIRFSG_WARN_DUC_OVERFLOW_FIR_FILTER                    NIRFSG_WARN_ARB_OVERFLOW_FIR_FILTER
#define NIRFSG_WARN_DUC_OVERFLOW_CIC_FILTER                    NIRFSG_WARN_ARB_OVERFLOW_CIC_FILTER
#define NIRFSG_WARN_DUC_OVERFLOW_IQ_SUM                        NIRFSG_WARN_ARB_OVERFLOW_IQ_SUM
#define NIRFSG_WARN_DUC_FILTER_BANDWIDTH_EXCEEDED              NIRFSG_WARN_ARB_FILTER_BANDWIDTH_EXCEEDED
#define NIRFSG_ERROR_AWG_RESOURCE_NAME_NOT_FOUND               NIRFSG_ERROR_INVALID_AWG_RESOURCE_NAME
#define NIRFSG_ERROR_AWG_RESOURCE_NAME_NOT_FOUND_IN_INIT       NIRFSG_ERROR_INVALID_AWG_RESOURCE_NAME
#define NIRFSG_ATTR_UPCONVERTER_LOOP_BANDWIDTH                 NIRFSG_ATTR_LOOP_BANDWIDTH
#define NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY_INCREMENT        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3a)
#define NIRFSG_ATTR_UPCONVERTER_CENTER_FREQUENCY_INCREMENT_ANCHOR (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x3b)
#define NIRFSG_ATTR_RF_BLANKING_EVENT_SOURCE                   NIRFSG_ATTR_RF_BLANKING_SOURCE
#define NIRFSG_ATTR_REFERENCE_OSCILLATOR_SOURCE                IVIRFSIGGEN_ATTR_REFERENCE_OSCILLATOR_SOURCE
#define NIRFSG_ATTR_EXTERNAL_CALIBRATION_USER_DEFINED_INFO          /* ViString */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4e)
#define NIRFSG_ATTR_EXTERNAL_CALIBRATION_USER_DEFINED_INFO_MAX_SIZE /* ViInt32  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x4f)
#define NIRFSG_ATTR_PEAK_POWER_ADJSUTMENT_INHERITANCE          NIRFSG_ATTR_PEAK_POWER_ADJUSTMENT_INHERITANCE
#define NIRFSG_ATTR_IQ_ENABLED               /* ViBoolean */   IVIRFSIGGEN_ATTR_IQ_ENABLED
/*- Direct DMA is deprecated starting with RFSG 17.5 -*/
#define NIRFSG_ATTR_DIRECT_DMA_ENABLED                      /* ViBoolean */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x31)
#define NIRFSG_ATTR_DIRECT_DMA_WINDOW_ADDRESS               /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x32)
#define NIRFSG_ATTR_DIRECT_DMA_WINDOW_SIZE                  /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 0x33)
/*
   NIRFSG_ATTR_REFERENCE_OSCILLATOR_SOURCE (ViInt32) is like an alias for NIRFSG_ATTR_REF_CLOCK_SOURCE (ViString)
   However, since they are different types, they must be two separate attributes.  When you set one, niRFSG automatically sets the other.
*/

/*- Values for attribute NIRFSG_ATTR_REFERENCE_OSCILLATOR_SOURCE -*/
#define NIRFSG_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL                IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_INTERNAL
#define NIRFSG_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL                IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_EXTERNAL
#define NIRFSG_VAL_REF_CLOCK_SOURCE_PXI_CLK                            (IVIRFSIGGEN_VAL_REFERENCE_OSCILLATOR_SOURCE_SPECIFIC_EXT_BASE + 1)

/*
   Old values for attributes NIRFSG_ATTR_LOOP_BANDWIDTH and NIRFSG_ATTR_REF_PLL_BANDWIDTH.
   These have been replaced by NIRFSG_VAL_NARROW and NIRFSG_VAL_WIDE.
*/
#define NIRFSG_VAL_LOW                          NIRFSG_VAL_NARROW
#define NIRFSG_VAL_HIGH                         NIRFSG_VAL_WIDE

/*- Error Info -*/
#define NIRFSG_ATTR_PRIMARY_ERROR                            /* ViInt32  */   IVIRFSIGGEN_ATTR_PRIMARY_ERROR
#define NIRFSG_ATTR_SECONDARY_ERROR                          /* ViInt32  */   IVIRFSIGGEN_ATTR_SECONDARY_ERROR
#define NIRFSG_ATTR_ERROR_ELABORATION                        /* ViString */   IVIRFSIGGEN_ATTR_ERROR_ELABORATION

/*- Deprecated (typo).  Kept in here only for RFSG 1.1 and earlier compatibility. -*/
#define NIRFSG_VAL_ON_BOARD_CLOCK_STR           "OnBoardClock"

/*- This attribute was replaced by NIRFSG_ATTR_ALC_CONTROL-*/
#define NIRFSG_ATTR_ALC_ENABLED                             /* ViBoolean */   IVIRFSIGGEN_ATTR_ALC_ENABLED

/*- IQ Modulation ----------------------------------------------------------*/
ViStatus _VI_FUNC niRFSG_ConfigureIQEnabled
(
   ViSession vi,
   ViBoolean enabled
);

#endif /* ___niRFSG_niRFSGObsolete_h___ */


