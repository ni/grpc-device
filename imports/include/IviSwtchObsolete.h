/*****************************************************************************
 *                          I V I - S W T C H  1.0                           
 *----------------------------------------------------------------------------
 *    Copyright (c) 1999-2020 National Instruments.  All Rights Reserved.         
 *----------------------------------------------------------------------------
 *                                                                           
 * Title:       IviSwtchObsolete.h                                           
 * Purpose:     IviSwtch Class value and attribute Id declarations for the   
 *              now obsolete IviSwtch 1.0 specification.                      
 *              These macros are defined to keep backward compatibility with 
 *              previous versions of this file.  Swtich specific drivers     
 *              should no longer use these macros. Instead, the drivers must 
 *              use definitions from the current IviSwtch.h header file.     
 *****************************************************************************/

#ifndef IVISWTCH_HEADER_OBSOLETE
#define IVISWTCH_HEADER_OBSOLETE
#include <ivi.h>

    /*- Obsolete Inherent Attributes -*/
#define IVISWTCH_ATTR_CLASS_MAJOR_VERSION        IVI_ATTR_CLASS_MAJOR_VERSION
#define IVISWTCH_ATTR_CLASS_MINOR_VERSION        IVI_ATTR_CLASS_MINOR_VERSION
#define IVISWTCH_ATTR_CLASS_REVISION             IVI_ATTR_CLASS_REVISION

#define IVISWTCH_ATTR_CLASS_PREFIX               IVI_ATTR_CLASS_PREFIX
#define IVISWTCH_ATTR_SPECIFIC_PREFIX            IVI_ATTR_SPECIFIC_PREFIX
#define IVISWTCH_ATTR_MODULE_PATHNAME            IVI_ATTR_MODULE_PATHNAME

#define IVISWTCH_ATTR_DRIVER_MAJOR_VERSION       IVI_ATTR_DRIVER_MAJOR_VERSION
#define IVISWTCH_ATTR_DRIVER_MINOR_VERSION       IVI_ATTR_DRIVER_MINOR_VERSION
#define IVISWTCH_ATTR_DRIVER_REVISION            IVI_ATTR_DRIVER_REVISION

#define IVISWTCH_ATTR_ENGINE_MAJOR_VERSION       IVI_ATTR_ENGINE_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVISWTCH_ATTR_ENGINE_MINOR_VERSION       IVI_ATTR_ENGINE_MINOR_VERSION        /* ViInt32,  read-only */
#define IVISWTCH_ATTR_ENGINE_REVISION            IVI_ATTR_ENGINE_REVISION             /* ViString, read-only */

#define IVISWTCH_ATTR_NUM_CHANNELS               IVI_ATTR_NUM_CHANNELS
#define IVISWTCH_ATTR_QUERY_INSTR_STATUS         IVI_ATTR_QUERY_INSTR_STATUS /* ViBoolean */
#define IVISWTCH_ATTR_RESOURCE_DESCRIPTOR        IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only */

#define IVISWTCH_ATTR_IO_SESSION_TYPE                  IVI_ATTR_IO_SESSION_TYPE
#define IVISWTCH_ATTR_IO_SESSION                       IVI_ATTR_IO_SESSION

#define IVISWTCH_ATTR_CLASS_DRIVER_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVISWTCH_ATTR_CLASS_DRIVER_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_MINOR_VERSION     /* ViInt32,  read-only */

#define IVISWTCH_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVISWTCH_ATTR_SPECIFIC_DRIVER_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION  /* ViInt32,  read-only */

#define IVISWTCH_ATTR_ATTRIBUTE_CAPABILITIES    IVI_ATTR_ATTRIBUTE_CAPABILITIES        /* ViString, read-only */

        /*- Error Info -*/
#define IVISWTCH_ATTR_PRIMARY_ERROR                    IVI_ATTR_PRIMARY_ERROR                  /* ViInt32  */
#define IVISWTCH_ATTR_SECONDARY_ERROR                  IVI_ATTR_SECONDARY_ERROR                /* ViInt32  */
#define IVISWTCH_ATTR_ERROR_ELABORATION                IVI_ATTR_ERROR_ELABORATION              /* ViString */

    /*- IviSwtch Obsolete Macros -*/
#define IVISWTCH_VAL_1_WIRE       (1L)
#define IVISWTCH_VAL_2_WIRE       (2L)
#define IVISWTCH_VAL_3_WIRE       (3L)
#define IVISWTCH_VAL_4_WIRE       (4L)
#define IVISWTCH_VAL_GPIB_GET     (101L)
#define IVISWTCH_VAL_SW_TRIG_FUNC (3L)

#define IVISWTCH_VAL_TRIGGER_SPECIFIC_EXT_BASE        (1000L)

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviSwtch_GetErrorInfo (ViSession vi, 
                                         ViStatus *primaryError, 
                                         ViStatus *secondaryError, 
                                         ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC IviSwtch_ClearErrorInfo (ViSession vi);

    /*- IviSwtch Obsolete Functions -*/
ViStatus _VI_FUNC   IviSwtch_SendSWTrigger          (ViSession vi);

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#endif /* IVISWTCH_HEADER_OBSOLETE */
