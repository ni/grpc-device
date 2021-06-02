/****************************************************************************
 *              National Instruments DC Power Supplies and SMUs
 *--------------------------------------------------------------------------*
 *      Copyright (c) National Instruments 2016.  All Rights Reserved.      *
 *--------------------------------------------------------------------------*
 *
 * Title:    nidcpowerObsolete.h
 * Purpose:  National Instruments DC Power Supplies and SMUs Instrument
 *           Driver declarations that are now obsolete.
 *           They are defined here to maintain backward compatibility with
 *           previous versions of the driver. New applications should not use
 *           any of the definitions in this file. Instead, they must
 *           use definitions from the nidcpower.h header file.
 ****************************************************************************/

#ifndef __NIDCPOWER_OBSOLETE_HEADER
#define __NIDCPOWER_OBSOLETE_HEADER

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <ivi.h>
#include <IviDCPwr.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/*- Obsoleted Functions -*/
ViStatus _VI_FUNC  niDCPower_init(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViSession *vi);

ViStatus _VI_FUNC  niDCPower_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession *vi);

ViStatus _VI_FUNC  niDCPower_ConfigureOutputRange(
   ViSession vi,
   ViConstString channelName,
   ViInt32 rangeType,
   ViReal64 range);

/*- Unsupported Functions -*/
ViStatus _VI_FUNC  niDCPower_ResetOutputProtection(
   ViSession vi,
   ViConstString channelName);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NIDCPOWER_OBSOLETE_HEADER */