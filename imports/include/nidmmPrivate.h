/*
   Copyright (c) 2015
   National Instruments Corporation.
   All rights reserved.
*/

#ifndef NIDMMH_NIDMMPRIVATE_H_
#define NIDMMH_NIDMMPRIVATE_H_

#include "nidmm.h"
#include <IviVisaType.h>

// STRING BASED ROUTING
/******************************************************************************/
/*       Attribute and function headings to support string routing API        */
/******************************************************************************/

// internally used functions in subservient layers
#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

ViStatus _VI_FUNC niDMM_ConfigureDigitalEdgeStartTrigger(
   ViSession      vi,
   ViConstString  trigSource,
   ViReal64       triggerDelay);

ViStatus _VI_FUNC niDMM_ConfigureSoftwareStartTrigger(
   ViSession   vi,
   ViReal64    triggerDelay);

ViStatus _VI_FUNC niDMM_DisableStartTrigger(
   ViSession   vi);

ViStatus _VI_FUNC niDMM_ConfigureDigitalEdgeSampleTrigger(
   ViSession      vi,
   ViConstString  trigSource);

ViStatus _VI_FUNC niDMM_ConfigureSoftwareSampleTrigger(
   ViSession   vi);

ViStatus _VI_FUNC niDMM_DisableSampleTrigger(
   ViSession   vi);

ViStatus _VI_FUNC niDMM_ConfigureIntervalSampleTrigger(
   ViSession   vi,
   ViReal64    sampleInterval);

ViStatus _VI_FUNC niDMM_ConfigureMultiPointAcquisition(
   ViSession   vi,
   ViInt32     triggerCount,
   ViInt32     sampleCount);

ViStatus _VI_FUNC niDMM_ExportSignal(
   ViSession   vi,
   ViInt32     signal,
   ViString    destination);


/******************************************************************************/
/*      Function headings for IVI-required functions, internal use only       */
/******************************************************************************/
ViStatus _VI_FUNC niDMM_IviInit(
      ViRsrc       resourceName,
      ViBoolean    IDQuery,
      ViBoolean    reset,
      ViSession    vi);

ViStatus _VI_FUNC niDMM_IviClose(
      ViSession   vi);


// Function signature this typedef represents: ViStatus _VI_FUNC functionName(Visession vi);
typedef ViStatus (_VI_FUNC *CloseFunctionType)(ViSession vi);
/*!
   Sets the Close function pointer which slid will end up using.  This is only meant to be called on
   the plugins, NOT the DVL.  The close function which you set will be called if and only if you initalize
   a session to a device with an already open session.  Slid will close the previously open session using
   this function pointer first.
   \param[in] closeFunctionPtr : Function pointer that slid will use to close the session if necessary.
 */
ViStatus _VI_FUNC niDMM_SetCloseFunctionPointer (CloseFunctionType closeFunctionPtr);

ViStatus _VI_FUNC niDMM_ReInit(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean reset,
   ViSession vi);

ViStatus _VI_FUNC niDMM_ConvertAbsToDigits(
   ViReal64    range,
   ViReal64    resolution,
   ViReal64    *newResolution);

ViReal64 niDMM_MaxDigits(
   ViSession   vi);

ViStatus _VI_FUNC niDMM_SelfTestPrep(
   ViRsrc      resourceName,
   ViBoolean   IDQuery,
   ViBoolean   reset,
   ViString    password);

ViStatus _VI_FUNC niDMM_SelfTestPrepImpl(
   ViSession   vi,
   ViString    password);

ViStatus _VI_FUNC niDMM_DoCompMeasurement(
   ViSession vi,
   ViInt32 modes[],
   ViInt32 calcModel,
   ViReal64 *real,
   ViReal64 *imaginary);

ViStatus _VI_FUNC niDMM_InternalControl(
   ViSession vi,
   ViInt32 action,
   ViInt32 calledBy);

ViStatus _VI_FUNC niDMM_ResetAttributes(
   ViSession vi);

// Returns information for each session that is open to the device in a JSON object, regardless
// of process.
// If 0 is passed in for bufferSize, the function will not error and will instead return the
// required size in bufferSizeNeededInBytes. Function always returns the bufferSizeNeededInBytes.
// Note that if a new session is opened after calling this to get the bufferSizeNeededInBytes,
// the required buffer size will increase and a subsequent call may fail. Clients must handle
// any errors returned in this case accordingly.
// See https://nitalk.jiveon.com/docs/DOC-417288 for the JSON format.
ViStatus _VI_FUNC niDMM_GetOpenSessionsInformation(
   ViRsrc resourceName,
   ViString infoJSON,
   ViUInt64 bufferSize,
   ViUInt64* bufferSizeNeededInBytes);

//
ViStatus _VI_FUNC niDMM_SetRuntimeEnvironment(
   ViConstString environment,
   ViConstString environmentVersion,
   ViConstString reserved1,
   ViConstString reserved2);

/*****************************************************************************/
/*= Option constants for the niDMM_GetAttributeWithOptionsVi* functions. */
/*= These determine what value type to return for an attribute               */
/*****************************************************************************/
#define NIDMM_VAL_ATTRIBUTE_RETRIEVAL_MODE_COERCED                 0  /* When passed to a GetAttributeWithOptionsVi*() function, the coerced value for the attribute will be returned, which is the same behavior as GetAttributeVi* */
#define NIDMM_VAL_ATTRIBUTE_RETRIEVAL_MODE_DESIRED                 1  /* When passed to a GetAttributeWithOptionsVi*() function, the desired value for the attribute will be returned instead of the coerced value */
#define NIDMM_VAL_ATTRIBUTE_RETRIEVAL_MODE_DEFAULT                 2  /* When passed to a GetAttributeWithOptionsVi*() function, the default value for the attribute will be returned instead of the coerced value */

ViStatus _VI_FUNC  niDMM_GetAttributeWithOptionsViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViInt32 *value);

ViStatus _VI_FUNC  niDMM_GetAttributeWithOptionsViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViReal64 *value);

ViStatus _VI_FUNC  niDMM_GetAttributeWithOptionsViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViInt32 bufSize,
   ViChar value[]);

ViStatus _VI_FUNC  niDMM_GetAttributeWithOptionsViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViSession *value);

ViStatus _VI_FUNC  niDMM_GetAttributeWithOptionsViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViBoolean *value);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

/******************************************************************************/
/*                              END INCLUDE FILE                              */
/******************************************************************************/

#endif // NIDMMH_NIDMMPRIVATE_H_
