/*****************************************************************************
 *                             I V I - DMM                                   
 *----------------------------------------------------------------------------
 *    Copyright (c) 1998-2020 National Instruments.  All Rights Reserved.         
 *----------------------------------------------------------------------------
 *                                                                           
 * Title:       IviDmmObsolete.h                                              
 * Purpose:     IviDmm Class value and attribute Id declarations for the     
 *              now obsolete IviDmm 1.0 specification.                        
 *              These macros are defined to keep backward compatibility with 
 *              previous versions of this file.  Dmm specific drivers        
 *              should no longer use these macros. Instead, the drivers must 
 *              use definitions from the current IviDmm.h header file.       
 *****************************************************************************/

#ifndef IVIDMM_HEADER_OBSOLETE
#define IVIDMM_HEADER_OBSOLETE

    /*- Obsolete Inherent Attributes -*/
#define IVIDMM_ATTR_CLASS_MAJOR_VERSION       IVI_ATTR_CLASS_MAJOR_VERSION         /* ViInt32,  read-only */
#define IVIDMM_ATTR_CLASS_MINOR_VERSION       IVI_ATTR_CLASS_MINOR_VERSION         /* ViInt32,  read-only */
#define IVIDMM_ATTR_CLASS_REVISION            IVI_ATTR_CLASS_REVISION              /* ViString, read-only */

#define IVIDMM_ATTR_CLASS_PREFIX              IVI_ATTR_CLASS_PREFIX                /* ViString, read-only */
#define IVIDMM_ATTR_SPECIFIC_PREFIX           IVI_ATTR_SPECIFIC_PREFIX             /* ViString, read-only */
#define IVIDMM_ATTR_MODULE_PATHNAME           IVI_ATTR_MODULE_PATHNAME             /* ViString, read-only */

#define IVIDMM_ATTR_DRIVER_MAJOR_VERSION      IVI_ATTR_DRIVER_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVIDMM_ATTR_DRIVER_MINOR_VERSION      IVI_ATTR_DRIVER_MINOR_VERSION        /* ViInt32,  read-only */
#define IVIDMM_ATTR_DRIVER_REVISION           IVI_ATTR_DRIVER_REVISION             /* ViString, read-only */

#define IVIDMM_ATTR_ENGINE_MAJOR_VERSION      IVI_ATTR_ENGINE_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVIDMM_ATTR_ENGINE_MINOR_VERSION      IVI_ATTR_ENGINE_MINOR_VERSION        /* ViInt32,  read-only */
#define IVIDMM_ATTR_ENGINE_REVISION           IVI_ATTR_ENGINE_REVISION             /* ViString, read-only */

#define IVIDMM_ATTR_NUM_CHANNELS              IVI_ATTR_NUM_CHANNELS                /* ViInt32,  read-only */
#define IVIDMM_ATTR_QUERY_INSTR_STATUS        IVI_ATTR_QUERY_INSTR_STATUS             /* ViBoolean */
#define IVIDMM_ATTR_RESOURCE_DESCRIPTOR       IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only */

#define IVIDMM_ATTR_IO_SESSION_TYPE                  IVI_ATTR_IO_SESSION_TYPE
#define IVIDMM_ATTR_IO_SESSION                       IVI_ATTR_IO_SESSION

#define IVIDMM_ATTR_CLASS_DRIVER_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION         /* ViInt32,  read-only */
#define IVIDMM_ATTR_CLASS_DRIVER_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_MINOR_VERSION         /* ViInt32,  read-only */

#define IVIDMM_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION        /* ViInt32,  read-only */
#define IVIDMM_ATTR_SPECIFIC_DRIVER_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION        /* ViInt32,  read-only */

#define IVIDMM_ATTR_ATTRIBUTE_CAPABILITIES    IVI_ATTR_ATTRIBUTE_CAPABILITIES      /* ViString, read-only */

        /*- Error Info -*/
#define IVIDMM_ATTR_PRIMARY_ERROR             IVI_ATTR_PRIMARY_ERROR               /* ViInt32  */
#define IVIDMM_ATTR_SECONDARY_ERROR           IVI_ATTR_SECONDARY_ERROR             /* ViInt32  */
#define IVIDMM_ATTR_ERROR_ELABORATION         IVI_ATTR_ERROR_ELABORATION           /* ViString */

    /*- Obsolete Macros -*/
#define IVIDMM_VAL_OVER_RANGE_READING         (1.0E+301)
#define IVIDMM_VAL_MAX_VALID_READING          (1.0E+300)

    /*- Obsolete Attributes -*/
#define IVIDMM_ATTR_RESOLUTION                (IVI_CLASS_PUBLIC_ATTR_BASE  + 3L)

    /*- Obsolete values for attributes -*/
        /*- IVIDMM_ATTR_FUNCTION values -*/
#define IVIDMM_VAL_DIODE                      (102)
#define IVIDMM_VAL_CONTINUITY                 (103)
#define IVIDMM_VAL_TEMP_F                     (109)
#define IVIDMM_VAL_TEMP_C                     (108)
#define IVIDMM_VAL_SIEMENS                    (110)
#define IVIDMM_VAL_COULOMBS                   (111)
    
        /*- IVIDMM_ATTR_RESOLUTION values -*/
#define IVIDMM_VAL_3_5_DIGITS                 (3.5)
#define IVIDMM_VAL_4_DIGITS                   (4.0)
#define IVIDMM_VAL_4_5_DIGITS                 (4.5)
#define IVIDMM_VAL_5_DIGITS                   (5.0)
#define IVIDMM_VAL_5_5_DIGITS                 (5.5)
#define IVIDMM_VAL_6_DIGITS                   (6.0)
#define IVIDMM_VAL_6_5_DIGITS                 (6.5)
#define IVIDMM_VAL_7_DIGITS                   (7.0)
#define IVIDMM_VAL_7_5_DIGITS                 (7.5)

        /*- IVIDMM_ATTR_TRIGGER_SOURCE values -*/
#define IVIDMM_VAL_GPIB_GET                   (101L)
#define IVIDMM_VAL_SW_TRIG_FUNC               (3L)

        /*- IVIDMM_ATTR_POWERLINE_FREQ values -*/
#define IVIDMM_VAL_50_HERTZ                   (50.0)
#define IVIDMM_VAL_60_HERTZ                   (60.0)
#define IVIDMM_VAL_400_HERTZ                  (400.0)

        /*- IVIDMM_ATTR_TRIGGER_POLARITY values -*/
#define IVIDMM_VAL_POS                        IVIDMM_VAL_POSITIVE
#define IVIDMM_VAL_NEG                        IVIDMM_VAL_NEGATIVE

    /*- Obsolete error and completion code values -*/
#define IVIDMM_ERROR_ACCURACY_UNKNOWN                       (IVI_CLASS_ERROR_BASE + 1)
#define IVIDMM_ERROR_ACCURACY_UNKNOWN_WHILE_AUTORANGING     (IVI_CLASS_ERROR_BASE + 2)

#define IVIDMM_ERRMSG_ACCURACY_UNKNOWN                      "The accuracy is unknown or not specified."
#define IVIDMM_ERRMSG_ACCURACY_UNKNOWN_WHILE_AUTORANGING    "The accuracy could not be determined while the DMM was autoranging." 

    /*- Obsolete Error Information Functions -*/
ViStatus _VI_FUNC IviDmm_GetErrorInfo (ViSession vi, 
                                       ViStatus *primaryError, 
                                       ViStatus *secondaryError, 
                                       ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC IviDmm_ClearErrorInfo (ViSession vi);

    /*- Obsolete functions -*/

ViStatus _VI_FUNC   IviDmm_Configure           (ViSession vi, ViInt32 measFunction, ViReal64 range, 
                                                ViReal64 resolution, ViReal64 acMinFreq, ViReal64 acMaxFreq);
ViStatus _VI_FUNC   IviDmm_SendSWTrigger       (ViSession vi);
ViStatus _VI_FUNC   IviDmm_CalculateAccuracy   (ViSession vi, ViReal64 freqOfInterest, 
                                                ViReal64 *readingMultiplier, ViReal64 *offset);


/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#endif /* __IVIDMM_HEADER_OBSOLETE */
