/*****************************************************************************
 *                          I V I - S C O P E  1.0                           
 *----------------------------------------------------------------------------
 *    Copyright (c) 1999-2020 National Instruments.  All Rights Reserved.         
 *----------------------------------------------------------------------------
 *                                                                           
 * Title:       IviScopeObsolete.h                                           
 * Purpose:     IviScope Class value and attribute Id declarations for the   
 *              now obsolete IviScope 1.0 specification.                      
 *              These macros are defined to keep backward compatibility with 
 *              previous versions of this file.  Oscilloscope specific       
 *              drivers should no longer use these macros. Instead, the      
 *              drivers must use definitions from the current IviScope.h     
 *              header file.                                                 
 *****************************************************************************/

#ifndef IVISCOPE_HEADER_OBSOLETE
#define IVISCOPE_HEADER_OBSOLETE
#include <ivi.h>

    /*- Obsolete Inherent Attributes -*/
#define IVISCOPE_ATTR_CLASS_MAJOR_VERSION               IVI_ATTR_CLASS_MAJOR_VERSION
#define IVISCOPE_ATTR_CLASS_MINOR_VERSION               IVI_ATTR_CLASS_MINOR_VERSION
#define IVISCOPE_ATTR_CLASS_REVISION                    IVI_ATTR_CLASS_REVISION

#define IVISCOPE_ATTR_CLASS_PREFIX                      IVI_ATTR_CLASS_PREFIX
#define IVISCOPE_ATTR_SPECIFIC_PREFIX                   IVI_ATTR_SPECIFIC_PREFIX
#define IVISCOPE_ATTR_MODULE_PATHNAME                   IVI_ATTR_MODULE_PATHNAME

#define IVISCOPE_ATTR_DRIVER_MAJOR_VERSION              IVI_ATTR_DRIVER_MAJOR_VERSION
#define IVISCOPE_ATTR_DRIVER_MINOR_VERSION              IVI_ATTR_DRIVER_MINOR_VERSION
#define IVISCOPE_ATTR_DRIVER_REVISION                   IVI_ATTR_DRIVER_REVISION

#define IVISCOPE_ATTR_ENGINE_MAJOR_VERSION              IVI_ATTR_ENGINE_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVISCOPE_ATTR_ENGINE_MINOR_VERSION              IVI_ATTR_ENGINE_MINOR_VERSION        /* ViInt32,  read-only */
#define IVISCOPE_ATTR_ENGINE_REVISION                   IVI_ATTR_ENGINE_REVISION             /* ViString, read-only */

#define IVISCOPE_ATTR_CLASS_DRIVER_MAJOR_VERSION        IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISCOPE_ATTR_CLASS_DRIVER_MINOR_VERSION        IVI_ATTR_CLASS_DRIVER_MINOR_VERSION     /* ViInt32,  read-only */

#define IVISCOPE_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISCOPE_ATTR_SPECIFIC_DRIVER_MINOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION  /* ViInt32,  read-only */

#define IVISCOPE_ATTR_NUM_CHANNELS                      IVI_ATTR_NUM_CHANNELS
#define IVISCOPE_ATTR_QUERY_INSTR_STATUS                IVI_ATTR_QUERY_INSTR_STATUS             /* ViBoolean */
#define IVISCOPE_ATTR_RESOURCE_DESCRIPTOR               IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only */

#define IVISCOPE_ATTR_IO_SESSION_TYPE                   IVI_ATTR_IO_SESSION_TYPE
#define IVISCOPE_ATTR_IO_SESSION                        IVI_ATTR_IO_SESSION

#define IVISCOPE_ATTR_ATTRIBUTE_CAPABILITIES    IVI_ATTR_ATTRIBUTE_CAPABILITIES        /* ViString, read-only */

    /*- Error Info -*/
#define IVISCOPE_ATTR_PRIMARY_ERROR                     IVI_ATTR_PRIMARY_ERROR                  /* ViInt32  */
#define IVISCOPE_ATTR_SECONDARY_ERROR                   IVI_ATTR_SECONDARY_ERROR                /* ViInt32  */
#define IVISCOPE_ATTR_ERROR_ELABORATION                 IVI_ATTR_ERROR_ELABORATION              /* ViString */

    /*- Obsolete Attributes -*/
#define IVISCOPE_ATTR_BANDWIDTH                         (IVI_CLASS_PUBLIC_ATTR_BASE  + 6L)
#define IVISCOPE_ATTR_HORZ_RECORD_REF_POSITION          (IVI_CLASS_PUBLIC_ATTR_BASE  + 11L)
#define IVISCOPE_ATTR_TRIGGER_DELAY_TIME                (IVI_CLASS_PUBLIC_ATTR_BASE  + 15L)
#define IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_TYPE            (IVI_CLASS_PUBLIC_ATTR_BASE  + 201L)
#define IVISCOPE_ATTR_TV_TRIGGER_FIELD                  (IVI_CLASS_PUBLIC_ATTR_BASE  + 202L)
#define IVISCOPE_ATTR_TV_TRIGGER_LINE                   (IVI_CLASS_PUBLIC_ATTR_BASE  + 203L)         
        
    /*- Obsolete macros -*/
#define IVISCOPE_VAL_MAX_VALID_WFM_VOLTAGE          (1.0E+300)
#define IVISCOPE_VAL_INVALID_WFM_VOLTAGE            (1.0E+301)

    /*- Obsolete values for function parameters -*/
#define IVISCOPE_VAL_CALCULATION_SPECIFIC_DRIVER_BASE   (1000L)

    /*- Defined values for attributes -*/
        /*- IVISCOPE_ATTR_TRIGGER_TYPE values -*/
#define IVISCOPE_VAL_EDGE                       (1L)
#define IVISCOPE_VAL_WIDTH                      (101L)
#define IVISCOPE_VAL_RUNT                       (102L)
#define IVISCOPE_VAL_GLITCH                     (103L)
#define IVISCOPE_VAL_STATE                      (104L)
#define IVISCOPE_VAL_PATTERN                    (105L)
#define IVISCOPE_VAL_TV                         (106L)

    
        /*- IVISCOPE_ATTR_TRIGGER_SOURCE values -*/
#define IVISCOPE_VAL_IMMEDIATE                  "VAL_IMMEDIATE"
#define IVISCOPE_VAL_GPIB_GET                   "VAL_GPIB_GET"
#define IVISCOPE_VAL_SW_TRIG_FUNC               "VAL_SW_TRIG_FUNC"
#define IVISCOPE_VAL_AC_LINE                    "VAL_AC_LINE"

        /*- IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_TYPE values -*/
#define IVISCOPE_VAL_TV_SIGNAL_TYPE_CLASS_EXT_BASE      (100L)
#define IVISCOPE_VAL_TV_SIGNAL_TYPE_SPECIFIC_EXT_BASE   (1000L)

        /*- IVISCOPE_ATTR_TV_TRIGGER_FIELD values -*/
#define IVISCOPE_VAL_TV_FIELD1                  (1L)
#define IVISCOPE_VAL_TV_FIELD2                  (2L)
#define IVISCOPE_VAL_TV_ANY_FIELD               (-1L)

#define IVISCOPE_VAL_TV_TRIGGER_FIELD_CLASS_EXT_BASE     (100L)
#define IVISCOPE_VAL_TV_TRIGGER_FIELD_SPECIFIC_EXT_BASE  (1000L)

        /*- IVISCOPE_ATTR_ACQUISITION_TYPE value -*/
#define IVISCOPE_VAL_ACQ_TYPE_CLASS_EXT_BASE    (100L)
#define IVISCOPE_VAL_ACQ_TYPE_SPECIFIC_EXT_BASE (1000L)

        /*- IVISCOPE_ATTR_NUM_ENVELOPES values -*/
        /*- IVISCOPE_ATTR_NUM_AVERAGES values -*/
#define IVISCOPE_VAL_INFINITE                   (-1L)

        /*- IVISCOPE_ATTR_INPUT_IMPEDANCE values -*/
#define IVISCOPE_VAL_50_OHMS                    (50.0)
#define IVISCOPE_VAL_75_OHMS                    (75.0)
#define IVISCOPE_VAL_1_MEG_OHM                  (1000000.0)

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviScope_GetErrorInfo (ViSession vi, 
                                         ViStatus *primaryError, 
                                         ViStatus *secondaryError, 
                                         ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC IviScope_ClearErrorInfo (ViSession vi);

    /*- IviScope Obsolete functions -*/
ViStatus _VI_FUNC IviScope_ConfigureVertical (ViSession vi, ViConstString channel,
                                              ViReal64 range, ViReal64 offset,
                                              ViInt32 coupling, ViReal64 probeAttenuation,
                                              ViBoolean enabled);
ViStatus _VI_FUNC IviScope_ConfigureHorizontal (ViSession vi, ViReal64 timePerRecord,
                                                ViInt32 minimumRecordLength,
                                                ViReal64 triggerPosition);
ViStatus _VI_FUNC IviScope_ConfigureTriggerSource (ViSession vi, ViConstString triggerSource,
                                                   ViInt32 triggerType, ViReal64 triggerDelay,
                                                   ViReal64 holdoff);
ViStatus _VI_FUNC IviScope_ConfigureEdgeTrigger (ViSession vi, ViReal64 level,
                                                 ViInt32 triggerCoupling, ViInt32 slope);
ViStatus _VI_FUNC IviScope_SendSWTrigger (ViSession vi);
ViStatus _VI_FUNC IviScope_ConfigureTVTrigger (ViSession vi, ViInt32 TVSignalType, 
                                               ViInt32 TVField, ViInt32 TVLine, ViInt32 TVPolarity);
ViStatus _VI_FUNC IviScope_ConfigureRuntTrigger (ViSession vi, ViReal64 runtLowThreshold,
                                                 ViReal64 runtHighThreshold, ViInt32 runtPolarity);
ViStatus _VI_FUNC IviScope_ConfigureGlitchTrigger (ViSession vi, ViReal64 level,
                                                   ViReal64 glitchWidth, ViInt32 glitchPolarity);
ViStatus _VI_FUNC IviScope_ConfigureWidthTrigger (ViSession vi, ViReal64 level,
                                                  ViReal64 widthLowThreshold, ViReal64 widthHighThreshold,
                                                  ViInt32 widthPolarity, ViInt32 widthCondition);
ViStatus _VI_FUNC IviScope_ConfigureAcquisition (ViSession vi, ViInt32 acquisitionType);

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#endif /* IVISCOPE_HEADER_OBSOLETE */
