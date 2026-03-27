/****************************************************************************
 *          National Instruments WLAN GENERATOR
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2010.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niWLANGenerationRfsg.h
 * Purpose:  National Instruments WLAN Generator
 *           functions declarations.
 *
 ****************************************************************************/



#ifndef __NIWLAN_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__
#define __NIWLAN_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__


#include <niRFSG.h>
#include "niWLANGeneration.h"
#include "niWLANGenerationRfsg_Deprecated.h"

#ifdef __cplusplus
extern "C"
{
#endif
	
/*- Configure Functions ---------------------------------------*/
int32 __stdcall  niWLANG_RFSGConfigure(
	niWLANGenerationSession session,
	char wlanChannelString[],
	ViSession rfsgSession,
	char hwChannelString[]);
	
int32 __stdcall niWLANG_RFSGConfigureMultipleDeviceSynchronization(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
	int32 noOfChannels, 
	char masterReferenceClockSource[], 
	int32 triggerLines[], 
	int32 noOfTriggerLines);
	
int32 __stdcall niWLANG_RFSGConfigureSampleClockDelay(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
	float64 sampleClockDelay[], 
	int32 noOfChannels);	

int32 __stdcall niWLANG_RFSGForceTClkSynchronization(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
	int32 numberOfRFSGSessions, 
	int32 forceSync
);	

int32 __stdcall niWLANG_RFSGMultipleDeviceInitiate(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
	int32 numberOfRFSGSessions
);	

int32 __stdcall niWLANG_RFSGConfigureFrequencySingleLO(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
    int32 numberOfRFSGSessions,
	int32 LOSource,
	ViSession externalLOHandle,
    float64 carrierFrequency, 
	int32 rfsgLODaisyChainEnabled,
    int32 LOExportToExternalDevicesEnabled); 	
	
int32 __stdcall niWLANG_RFSGConfigureFrequencyMultipleLO(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[],
	int32 numberOfRFSGSessions,	
	int32 LOSource,
	ViSession externalLOHandles[],
	int32 numberOfexteralLOHandles,
	float64 carrierFrequency[],
	int32 dataArraySize,
	int32 rfsgLODaisyChainEnabled,
    int32 LOExportToExternalDevicesEnabled); 			
	
/*-------------------- ---------------------------------------*/
int32 __stdcall  niWLANG_RFSGConfigureWaveform(
	niWLANGenerationSession session,
	char wlanChannelString[],
	ViSession rfsgSession,
	char hwChannelString[],
	int32 resetHardware,
	int32* waveformSize);
	
/*- RFSG Database ---------------------------------------------------------*/

int32 __stdcall niWLANG_RFSGStorePAPR(
	ViSession rfsgSession, 
	char channelString[],
	char waveformName[], 
	float64 PAPR);
	
int32 __stdcall niWLANG_RFSGStoreIQRate(
	ViSession rfsgSession, 
	char channelString[],
	char waveformName[], 
	float64 IQRate);
	
int32 __stdcall niWLANG_RFSGStoreBurstStartLocations(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 burstStartLocations[],
    int32 dataArraySize);	
	
int32 __stdcall niWLANG_RFSGStoreBurstStopLocations(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 burstStopLocations[],
	int32 dataArraySize);	
	
int32 __stdcall niWLANG_RFSGRetrievePAPR(
	ViSession rfsgSession, 
	char channelString[],
	char waveformName[], 
	float64 *PAPR);
	
int32 __stdcall niWLANG_RFSGRetrieveMinimumPAPRAllWaveforms(
	ViSession rfsgSession, 
	char channelString[],
	char script[], 
	float64 *PAPR);
	
int32 __stdcall niWLANG_RFSGRetrieveIQRate(
	ViSession rfsgSession, 
	char channelString[],
	char waveformName[], 
	float64 *IQRate);
	
int32 __stdcall niWLANG_RFSGRetrieveIQRateAllWaveforms(
	ViSession rfsgSession, 
	char channelString[],
	char script[], 
	float64 *IQRate);

int32 __stdcall niWLANG_RFSGRetrieveRFBlankingMarkerPositions(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 rfBlankingMarkerPositions[], 
	int32 rfBlankingMarkerPositionsArraySize, 
	int32 *actualRFBlankingMarkerPositionsArraySize);	

int32 __stdcall niWLANG_RFSGRetrieveBurstStartLocations(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 burstStartLocations[],
	int32 dataArraySize,
	int32* actualDataArraySize);
	
int32 __stdcall niWLANG_RFSGRetrieveBurstStopLocations(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 burstStopLocations[],
	int32 dataArraySize,
	int32* actualDataArraySize);
	
int32 __stdcall niWLANG_RFSGRetrieveWaveformSize(
	ViSession rfsgSession, 
	char waveformName[], 
	int32* waveformSize);
	
int32 __stdcall niWLANG_RFSGCreateAndDownloadWaveform(
	niWLANGenerationSession session, 
	ViSession rfsgSession, 
	char hwChannelString[],
	char waveformName[]);	
	
int32 __stdcall niWLANG_RFSGCreateAndDownloadMIMOWaveforms(
	niWLANGenerationSession session, 
	ViSession rfsgSessions[], 
	char hwChannelStrings[],
	int32 numberOfTxChains, 
	char waveformName[]);
	
int32 __stdcall niWLANG_RFSGConfigureScript(
	ViSession rfsgSession, 
	char channelString[],
	char script[], 
	float64 powerLevel);
	
int32 __stdcall niWLANG_RFSGConfigurePowerLevel(
	ViSession rfsgSession, 
	char channelString[],
	char script[], 
	float64 powerLevel);
	
int32 __stdcall niWLANG_RFSGClearDatabase(
	ViSession rfsgSession, 
	char channelString[],
	char waveformName[]);
	
int32 __stdcall niWLANG_RFSGReadAndDownloadWaveformsFromFile(
	ViSession rfsgSessions[], 
	int32 numberOfChannels, 
	char waveformName[], 
	char filePath[]);	
	
int32 __stdcall niWLANG_RFSGStoreRFBlankingMarkerPositions(
	ViSession rfsgSession, 
	char waveformName[], 
	int32 rfBlankingMarkerPositions[], 
	int32 rfBlankingMarkerPositionsArraySize);

int32 __stdcall niWLANG_RFSGInsertRFBlankingMarkerPositions(
	ViSession rfsgSession, 
	char script[], 
	char scriptOut[], 
	int32 lenOfScriptOut, 
	int32 *actualLenOfScriptOut);
	
/*- Obsolete ---------------------------------------------------------*/	
int32 __stdcall niWLANG_RFSGAutoTriggerRoute(
	ViSession rfsgHandles[], 
	int32 noOfChannels, 
	char triggerLine[], 
	int32 lenOfTrigLine, 
	char reference[], 
	int32 lenOfReference, 
	int32 *isInSameBus, 
	int32 busNumber[], 
	int32 sizeOfBusNo, 
	int32 *isDefaultLineSelected);
	
int32 __stdcall niWLANG_RFSGTriggerUnroute(
	char triggerLine[], 
	char reference[], 
	int32 isInSameBus, 
	int32 busNumber[], 
	int32 sizeOfBusNo, 
	int32 isDefaultLineSelected);	
	
#ifdef __cplusplus
}
#endif

#endif //__NIWLAN_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__
