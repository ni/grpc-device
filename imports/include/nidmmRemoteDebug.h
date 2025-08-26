/*
   Copyright(c) 2015-
   National Instruments Corporation.
   All rights reserved.

   Header file declaring entry points needed for remote debugging
   These are used internally and by the Soft Front Panel, but these
   functions are not exposed to customers.
*/

#ifndef NIDMMH_NIDMMREMOTEDEBUG_H__
#define NIDMMH_NIDMMREMOTEDEBUG_H__

#include "IviVisaType.h"

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/*******************************************************************************/
/* Functions needed by nidmmRemote (needs to be implemented in other plugins): */
/*******************************************************************************/
/* Check if an attribute is currently marked as user-set. This function doesn't
 * return a ViStatus since it's matching the IVI function of the same name. */
ViBoolean _VI_FUNC niDMM_AttributeWasSetByUser(
   ViSession vi,
   ViConstString repCapName,
   ViAttr attributeId);

/* Return the last measurement made by the last call to a Read, Fetch, ReadMultiPoint or
 * FetchMultiPoint. Call CachedReadStatus before calling this as no error will
 * be returned if the cache is empty or invalid. Calling this function repeatedly
 * will return the same result until another one of those 4 calls is performed.
 * Waveform fetches are not cached. */
ViStatus _VI_FUNC niDMM_CachedFetch(
   ViSession vi,
   ViReal64* reading);

/* Check if there is valid data in the cache or not. If there is valid data
 * then acqBacklog will be equal to 1. The cache will be invalid if no fetch
 * has been performed yet or if the measurement function has been changed
 * since the last fetch. */
ViStatus _VI_FUNC niDMM_CachedReadStatus(
   ViSession vi,
   ViInt32* acqBacklog,
   ViInt16* acqStatus);

/*
 * Return the last measurement made by the most recent call to a Read, Fetch, ReadMultiPoint or
 * FetchMultiPoint, as well as metadata about that measurement. FetchWaveForm and ReadWaveform
 * do not cache their measurements.
 *
 * @param acqBacklog Indicates whether there is data in the cache or not. If there's data,
 *    then acqBacklog will be equal to 1. The cache will be invalid if no fetch
 *    has been performed yet.
 *
 * @param changeCounter The value of the data cache's change counter. This counter increments
 * whenever the cache is updated. A value of 0 means the cache is not valid.
 *
 * @param function Return the value of the NIDMM_ATTR_FUNCTION corresponding to the reading.
 *
 * @param reserved Currently Unused. Clients should pass a NULL ptr to avoid potential issues.
 *
 */
ViStatus _VI_FUNC niDMM_GetLastRetrievedMeasurement(
   ViSession vi,
   ViInt32 *acqBacklog,
   ViUInt64 *changeCounter,
   ViReal64 *reading,
   ViInt32 *measFunction,
   void *reserved
);

/* Allow a client to either perform an actual fetch or simply use the cache.
 * This allows the client to not have to decide which one to choose, but
 * rather give whether the client is monitoring instead or not. */
ViStatus _VI_FUNC niDMM_FetchMultiPointWithCaching(
   ViSession vi,
   ViInt32 maxTime,
   ViInt32 arraySize,
   ViReal64 readingArray[],
   ViInt32* actualPts,
   ViBoolean isMonitoring);

/* Check if an attribute exists and thus is valid in a given IVI session. */
ViStatus _VI_FUNC niDMM_IsAttributeValid(
   ViSession vi,
   ViString repCapName,
   ViAttr attributeId,
   ViBoolean* isValid);

/* Check if a device has an open and initialized session in any process. */
ViStatus _VI_FUNC niDMM_IsSessionInitialized(
   ViRsrc resourceName,
   ViBoolean* isInitialized,
   ViBoolean* isCalibrationSession);

/* Save the current values of attributes in this session, to an internal place,
 * to allow a future call to niDMM_RestoreAttributes to restore all attributes
 * to the values they are currently. */
ViStatus _VI_FUNC niDMM_SaveAttributes(
   ViSession vi);

/* Call RestoreAttributes, We keep this function to mantain backwards compatibility. */
ViStatus _VI_FUNC niDMM_RevertAttributes(
   ViSession vi);

/* Restore attribute values to the state previously saved by niDMM_SaveAttributes. */
ViStatus _VI_FUNC niDMM_RestoreAttributes(
   ViSession vi);

/* Initializes a slave server session for an out-of-process client */
ViStatus _VI_FUNC InitializeSessionForServer(
   ViRsrc resourceName,
   ViBoolean idQuery,
   ViBoolean reset,
   ViConstString optionString,
   ViConstString additionalOptions,
   ViSession* newVi);

/* Closes the slave server session used for an out-of-process client */
ViStatus _VI_FUNC ReleaseSessionForServer(
   ViSession vi);

/*****************************************/
/* Functions implemented by nidmmRemote: */
/*****************************************/
/* In the current process, create an RPC server that will handle requests
 * from other processes to call functions in the current process */
ViStatus _VI_FUNC niDMM_AllocateServer(
   ViConstString serverName,
   ViSession vi);

/* Stop the server created by niDMM_AllocateServer. */
ViStatus _VI_FUNC niDMM_FreeServer(
   ViSession vi);

/* For client sessions, request that the session's privilege be changed.
 * Privilege levels determine what functions a client session can call or will
 * receive an error on. See ClientPrivilege.h in niMIRemoteCommon for more
 * information. */
ViStatus _VI_FUNC niDMM_RequestPrivilege(
   ViSession vi,
   ViInt32 privilegeLevel);

/* Allow the server that exists within the current session to revoke the control
 * privilege of all clients down to monitor. However, this won't affect the client
 * with "non-revokable" control. Also if there is no server, this call won't have
 * any effect. */
ViStatus _VI_FUNC niDMM_RevokeControl(
   ViSession vi,
   ViBoolean* clientWasRevoked);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif
