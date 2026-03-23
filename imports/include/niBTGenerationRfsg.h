/****************************************************************************
 *          National Instruments BT Generation
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2011.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niBTGenerationRfsg.h
 * Purpose:  National Instruments BT Generator
 *           functions declarations.
 *
 ****************************************************************************/

#ifndef __NIBT_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__
#define __NIBT_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__

#include <niRFSG.h>
#include "niBTGeneration.h"

// Type alias: NIComplexDouble is the same as NIComplexNumber
typedef NIComplexNumber NIComplexDouble;

#ifdef __cplusplus
extern "C"
{
#endif

/*- RFSG Database ---------------------------------------------------------*/
// BTSG Create and download Waveform
int32 __stdcall niBTSG_RFSGCreateAndDownloadWaveform(
	niBTSGSession session, 
	ViSession RFSGHandle, 
    char channelString[],
	char waveformName[]);

// BTSG Store IQ Rate
int32 __stdcall niBTSG_RFSGStoreIQRate(
	ViSession RFSGHandle,
    char channelString[],
	char waveformName[], 
	float64 IQRate);

// BTSG Retrieve IQ Rate
int32 __stdcall niBTSG_RFSGRetrieveIQRate(
	ViSession RFSGHandle, 
    char channelString[],
	char waveformName[], 
	float64 *IQRate);

// BTSG Retrieve IQ Rate All Waveforms
int32 __stdcall niBTSG_RFSGRetrieveIQRateAllWaveforms(
	ViSession RFSGHandle, 
    char channelString[],
	char script[], 
	float64 *IQRate);
	
// BTSG Store Headroom                
int32 __stdcall niBTSG_RFSGStoreHeadroom(
	ViSession RFSGHandle, 
    char channelString[],
	char waveformName[], 
	float64 headroom);

// BTSG Retrieve Headroom
int32 __stdcall niBTSG_RFSGRetrieveHeadroom(
	ViSession RFSGHandle, 
    char channelString[],
	char waveformName[], 
	float64 *headroom);
	
// BTSG niBTSG_RFSGRetrieveMinimumHeadroomAllWaveforms
int32 __stdcall niBTSG_RFSGRetrieveMinimumHeadroomAllWaveforms(
	ViSession RFSGHandle, 
    char channelString[],
	char script[], 
	float64 *headroom);
	
// BTSG Configure Script
int32 __stdcall niBTSG_RFSGConfigureScript(
	ViSession RFSGHandle, 
    char channelString[],
	char script[], 
	float64 powerLevel);

// BTSG RFSG Clear Database	
int32 __stdcall niBTSG_RFSGClearDatabase(
 	ViSession RFSGHandle, 
    char channelString[],
	char waveformName[]);

#ifdef __cplusplus
}
#endif


#endif //__NIBT_TOOLKIT_GENERATION_RFSG_HEADER_DEFINED__