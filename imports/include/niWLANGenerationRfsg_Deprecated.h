/****************************************************************************
 *          National Instruments WLAN GENERATOR
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2008.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niWLANGenerationRfsg_Deprecated.h
 * Purpose:  National Instruments WLAN Generator deprecated
 *           functions declarations.
 *
 ****************************************************************************/



#ifndef __NIWLAN_TOOLKIT_GENERATION_RFSG_DEPRECATED_HEADER_DEFINED__
#define __NIWLAN_TOOLKIT_GENERATION_RFSG_DEPRECATED_HEADER_DEFINED__

#ifdef __cplusplus
extern "C"
{
#endif

	
/*- Configure Functions ---------------------------------------*/
int32 __stdcall  niWLANGv1_ConfigureRFSG(
	niWLANGenerationSession session,
	ViSession rfsgSession,
	char* channelString);

/*-------------------- ---------------------------------------*/
int32 __stdcall  niWLANGv1_ConfigureWaveform(
	niWLANGenerationSession session,
	ViSession rfsgSession,
	char* channelString,
	int32 resetHardware,
	int32* waveformSize);
	
	
#ifdef __cplusplus
}
#endif

#endif //__NIWLAN_TOOLKIT_GENERATION_RFSG_DEPRECATED_HEADER_DEFINED__
