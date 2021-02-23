/*****************************************************************************
 *                          I V I - D C P W R  2.0                           
 *----------------------------------------------------------------------------
 *    Copyright (c) 2002-2020 National Instruments.  All Rights Reserved.         
 *----------------------------------------------------------------------------
 *                                                                           
 * Title:       IviDCPwrObsolete.h                                           
 * Purpose:     IviDCPwr Class value and attribute Id declarations for the   
 *              now obsolete IviDCPwr 2.0 specification.                      
 *              These macros are defined to keep backward compatibility with 
 *              previous versions of this file.  DC Power Supply specific       
 *              drivers should no longer use these macros. Instead, the      
 *              drivers must use definitions from the current IviDCPwr.h     
 *              header file.                                                 
 *****************************************************************************/

#ifndef IVIDCPWR_HEADER_OBSOLETE
#define IVIDCPWR_HEADER_OBSOLETE
#include <ivi.h>

    /*- Obsolete Inherent Attributes -*/
#define IVIDCPWR_ATTR_CLASS_DRIVER_MAJOR_VERSION        IVI_ATTR_CLASS_DRIVER_MAJOR_VERSION     /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_CLASS_DRIVER_MINOR_VERSION        IVI_ATTR_CLASS_DRIVER_MINOR_VERSION     /* ViInt32,  read-only */

#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_SPECIFIC_DRIVER_MINOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION  /* ViInt32,  read-only */
#define IVIDCPWR_ATTR_QUERY_INSTR_STATUS                IVI_ATTR_QUERY_INSTR_STATUS             /* ViBoolean */
#define IVIDCPWR_ATTR_RESOURCE_DESCRIPTOR               IVI_ATTR_RESOURCE_DESCRIPTOR            /* ViString, read-only */
#define IVIDCPWR_ATTR_NUM_CHANNELS                      IVI_ATTR_NUM_CHANNELS

#define IVIDCPWR_ATTR_IO_SESSION_TYPE                   IVI_ATTR_IO_SESSION_TYPE
#define IVIDCPWR_ATTR_IO_SESSION                        IVI_ATTR_IO_SESSION

#define IVIDCPWR_ATTR_ATTRIBUTE_CAPABILITIES            IVI_ATTR_ATTRIBUTE_CAPABILITIES        /* ViString, read-only */

    /*- Error Info -*/
#define IVIDCPWR_ATTR_PRIMARY_ERROR                     IVI_ATTR_PRIMARY_ERROR                  /* ViInt32  */
#define IVIDCPWR_ATTR_SECONDARY_ERROR                   IVI_ATTR_SECONDARY_ERROR                /* ViInt32  */
#define IVIDCPWR_ATTR_ERROR_ELABORATION                 IVI_ATTR_ERROR_ELABORATION              /* ViString */

    /*- Error Information Functions -*/
ViStatus _VI_FUNC IviDCPwr_GetErrorInfo (ViSession vi, 
                                         ViStatus *primaryError, 
                                         ViStatus *secondaryError, 
                                         ViChar errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC IviDCPwr_ClearErrorInfo (ViSession vi);

/*****************************************************************************
 *---------------------------- End Include File -----------------------------*
 *****************************************************************************/

#endif /* IVIDCPWR_HEADER_OBSOLETE */
