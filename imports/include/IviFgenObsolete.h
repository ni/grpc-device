/*****************************************************************************
 *                              I V I - F G E N                              *
 *---------------------------------------------------------------------------*
 *    Copyright (c) 1999-2020 National Instruments.  All Rights Reserved.    *
 *---------------------------------------------------------------------------*
 *                                                                           *
 * Title:       IviFgenObsolete.h                                            * 
 * Purpose:     IviFgen Class value and attribute Id declarations for the    *
 *              now obsolete IviFgen 1.0 specification.                      * 
 *              These macros are defined to keep backward compatibility with *
 *              previous versions of this file.  Instrument specific         *
 *              drivers should no longer use these macros. Instead, the      *
 *              drivers must use definitions from the current IviFgen.h      *
 *              header file.                                                 *
 *****************************************************************************/

#ifndef __IVIFGEN_HEADER_OBSOLETE
#define __IVIFGEN_HEADER_OBSOLETE
#include <ivi.h>

    /*- Obsolete Inherent Attributes -*/
#define IVIFGEN_ATTR_CLASS_MAJOR_VERSION        IVI_ATTR_CLASS_MAJOR_VERSION
#define IVIFGEN_ATTR_CLASS_MINOR_VERSION        IVI_ATTR_CLASS_MINOR_VERSION
#define IVIFGEN_ATTR_CLASS_REVISION             IVI_ATTR_CLASS_REVISION

#define IVIFGEN_ATTR_CLASS_PREFIX               IVI_ATTR_CLASS_PREFIX
#define IVIFGEN_ATTR_SPECIFIC_PREFIX            IVI_ATTR_SPECIFIC_PREFIX
#define IVIFGEN_ATTR_MODULE_PATHNAME            IVI_ATTR_MODULE_PATHNAME

#define IVIFGEN_ATTR_DRIVER_MAJOR_VERSION       IVI_ATTR_DRIVER_MAJOR_VERSION
#define IVIFGEN_ATTR_DRIVER_MINOR_VERSION       IVI_ATTR_DRIVER_MINOR_VERSION
#define IVIFGEN_ATTR_DRIVER_REVISION            IVI_ATTR_DRIVER_REVISION

#define IVIFGEN_ATTR_ENGINE_MAJOR_VERSION       IVI_ATTR_ENGINE_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVIFGEN_ATTR_ENGINE_MINOR_VERSION       IVI_ATTR_ENGINE_MINOR_VERSION        /* ViInt32,  read-only */
#define IVIFGEN_ATTR_ENGINE_REVISION            IVI_ATTR_ENGINE_REVISION             /* ViString, read-only */

#define IVIFGEN_ATTR_NUM_CHANNELS               IVI_ATTR_NUM_CHANNELS
#define IVIFGEN_ATTR_QUERY_INSTR_STATUS         IVI_ATTR_QUERY_INSTR_STATUS             /* ViBoolean */
#define IVIFGEN_ATTR_RESOURCE_DESCRIPTOR        IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only */

#define IVIFGEN_ATTR_IO_SESSION_TYPE                  IVI_ATTR_IO_SESSION_TYPE
#define IVIFGEN_ATTR_IO_SESSION                       IVI_ATTR_IO_SESSION

#define IVIFGEN_ATTR_CLASS_DRIVER_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION         /* ViInt32,  read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_MINOR_VERSION         /* ViInt32,  read-only */

#define IVIFGEN_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION        /* ViInt32,  read-only */

#define IVIFGEN_ATTR_ATTRIBUTE_CAPABILITIES    IVI_ATTR_ATTRIBUTE_CAPABILITIES      /* ViString, read-only */

        /*- Error Info -*/
#define IVIFGEN_ATTR_PRIMARY_ERROR                    IVI_ATTR_PRIMARY_ERROR               /* ViInt32  */
#define IVIFGEN_ATTR_SECONDARY_ERROR                  IVI_ATTR_SECONDARY_ERROR             /* ViInt32  */
#define IVIFGEN_ATTR_ERROR_ELABORATION                IVI_ATTR_ERROR_ELABORATION           /* ViString */

    /*- Obsolete Attributes -*/
#define IVIFGEN_ATTR_CYCLE_COUNT            (IVI_CLASS_PUBLIC_ATTR_BASE + 301L)

    /*- Obsolete values for function parameters -*/
#define IVIFGEN_VAL_FIRST_WAVEFORM_HANDLE   (10000L)
#define IVIFGEN_VAL_LAST_WAVEFORM_HANDLE    (IVIFGEN_VAL_FIRST_WAVEFORM_HANDLE + 9999L)

#define IVIFGEN_VAL_FIRST_SEQUENCE_HANDLE   (100000L)
#define IVIFGEN_VAL_LAST_SEQUENCE_HANDLE    (IVIFGEN_VAL_FIRST_SEQUENCE_HANDLE + 9999L)

    /*- Obsolete values for attributes -*/
        /*- IVIFGEN_ATTR_REF_CLOCK_SOURCE values -*/
#define IVIFGEN_VAL_INTERNAL                (0L)
#define IVIFGEN_VAL_RTSI_CLOCK              (101L)

        /*- IVIFGEN_ATTR_OUTPUT_IMPEDANCE values -*/
#define IVIFGEN_VAL_50_OHMS                 (50.0)
#define IVIFGEN_VAL_75_OHMS                 (75.0)
#define IVIFGEN_VAL_1_MEGA_OHM              (1.0e+6)

        /*- IVIFGEN_ATTR_FUNC_WAVEFORM values -*/
#define IVIFGEN_VAL_WFM_BASE                (0L)

        /*- IVIFGEN_ATTR_TRIGGER_SOURCE values -*/
#define IVIFGEN_VAL_IMMEDIATE               (0L)
#define IVIFGEN_VAL_SW_TRIG_FUNC            (2L)
#define IVIFGEN_VAL_GPIB_GET                (101L)

        /*- IVIFGEN_ATTR_CYCLE_COUNT values -*/
#define IVIFGEN_VAL_GENERATE_CONTINUOUS     (-1L)

        /*- IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_AM_INTERNAL_DC          (6L)
    
        /*- IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_FM_INTERNAL_DC          (6L)
    
    /*- Obsolete error and completion code values -*/
#define IVIFGEN_ERROR_NOT_CONFIGURABLE              (IVI_CLASS_ERROR_BASE+0x0001L) 
#define IVIFGEN_ERROR_NOT_GENERATING                (IVI_CLASS_ERROR_BASE+0x0002L)
#define IVIFGEN_ERROR_INVALID_MODE                  (IVI_CLASS_ERROR_BASE+0x0003L)        
#define IVIFGEN_ERROR_INVALID_WFM_LENGTH            (IVI_CLASS_ERROR_BASE+0x0005L)
#define IVIFGEN_ERROR_INVALID_WFM_ELEMENT           (IVI_CLASS_ERROR_BASE+0x0006L)
#define IVIFGEN_ERROR_INVALID_WAVEFORM              (IVI_CLASS_ERROR_BASE+0x0007L)        
#define IVIFGEN_ERROR_INVALID_SEQ_LENGTH            (IVI_CLASS_ERROR_BASE+0x000AL)
#define IVIFGEN_ERROR_INVALID_LOOP_COUNT            (IVI_CLASS_ERROR_BASE+0x000BL)
#define IVIFGEN_ERROR_INVALID_SEQUENCE              (IVI_CLASS_ERROR_BASE+0x000CL)

#define IVIFGEN_ERRMSG_NOT_CONFIGURABLE             "The operation cannot be completed because the function generator is not configurable" 
#define IVIFGEN_ERRMSG_NOT_GENERATING               "The operation cannot be completed because the function generator is not generating a signal" 
#define IVIFGEN_ERRMSG_INVALID_MODE                 "The operation cannot be completed in the current output mode."        
#define IVIFGEN_ERRMSG_INVALID_WFM_LENGTH           "The waveform length is invalid."
#define IVIFGEN_ERRMSG_INVALID_WFM_ELEMENT          "One of the elements in the waveform data array is invalid."
#define IVIFGEN_ERRMSG_INVALID_WAVEFORM             "The specified waveform is invalid."        
#define IVIFGEN_ERRMSG_INVALID_SEQ_LENGTH           "The sequence length is invalid."
#define IVIFGEN_ERRMSG_INVALID_LOOP_COUNT           "One of the the elements in the loop count array is invalid."
#define IVIFGEN_ERRMSG_INVALID_SEQUENCE             "The specified sequence is invalid."

    /*- Obsolete Error Information Functions -*/
ViStatus _VI_FUNC IviFgen_GetErrorInfo (ViSession vi, 
                                        ViStatus *primaryError,
                                        ViStatus *secondaryError,
                                        ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC IviFgen_ClearErrorInfo (ViSession vi);

    /*- Obsolete functions -*/
ViStatus _VI_FUNC IviFgen_EnableOutput       (ViSession vi, ViConstString channelName);
ViStatus _VI_FUNC IviFgen_DisableOutput      (ViSession vi, ViConstString channelName);
ViStatus _VI_FUNC IviFgen_ConfigureTrigger   (ViSession vi, ViConstString channelName,
                                              ViInt32 trigSource, ViInt32 cycleCount);
ViStatus _VI_FUNC IviFgen_SendSWTrigger      (ViSession vi);
ViStatus _VI_FUNC IviFgen_EnableAM           (ViSession vi, ViConstString channelName,
                                              ViInt32 amSource);
ViStatus _VI_FUNC IviFgen_DisableAM          (ViSession vi, ViConstString channelName);
ViStatus _VI_FUNC IviFgen_EnableFM                  (ViSession vi, ViConstString channelName,
                                                     ViInt32 fmSource);
ViStatus _VI_FUNC IviFgen_DisableFM                 (ViSession vi, ViConstString channelName);

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#endif /* __IVIFGEN_HEADER_OBSOLETE */
