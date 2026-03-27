/****************************************************************************
*          National Instruments WLAN GENERATOR
*---------------------------------------------------------------------------
*   Copyright (c) National Instruments 2008.  All Rights Reserved.
*---------------------------------------------------------------------------
*
* Title:    niWLANGeneration_Deprecated.h
* Purpose:  National Instruments WLAN Generator deprecated
*           functions declarations.
*
****************************************************************************/


#ifndef __NIWLAN_TOOLKIT_GENERATION_DEPRECATED_HEADER_DEFINED__
#define __NIWLAN_TOOLKIT_GENERATION_DEPRECATED_HEADER_DEFINED__

typedef int32		niWLANGv1_Attr;

#ifndef TRUE
#define TRUE            (1L)
#endif
#ifndef FALSE
#define FALSE           (0L)
#endif
#ifndef NULL
#define NULL            (0L)
#endif

/****************************************************************************
*---------------------------- Attribute Defines ---------------------------*
****************************************************************************/

#define NIWLANGV1_STANDARD									0x1F	/*int32*/
#define NIWLANGV1_CARRIER_FREQUENCY							0x0		/*float64*/
#define NIWLANGV1_POWER_LEVEL								0x1		/*float64*/
#define NIWLANGV1_OVERSAMPLING_FACTOR						0x2		/*int32*/
#define NIWLANGV1_WAVEFORM_SCALING_FACTOR					0x24	/*float64*/
#define NIWLANGV1_OFDM_DATA_RATE							0x20	/*int32*/
#define NIWLANGV1_DSSS_DATA_RATE							0x21	/*int32*/
#define NIWLANGV1_IDLE_INTERVAL								0x3		/*float64*/
#define NIWLANGV1_NUMBER_OF_FRAMES							0x6		/*int32*/
#define NIWLANGV1_DSSS_PREAMBLE_TYPE						0x4		/*int32*/
/*- Payload Attributes ----------------------------------------*/
#define NIWLANGV1_PAYLOAD_DATA_LENGTH						0x5		/*int32*/
#define NIWLANGV1_PAYLOAD_DATA_TYPE							0x7		/*int32*/
#define NIWLANGV1_PAYLOAD_PN_ORDER							0x8		/*int32*/
#define NIWLANGV1_PAYLOAD_PN_SEED							0x9		/*int32*/
#define NIWLANGV1_PAYLOAD_USER_DEFINED_BITS					0xA		/*1D Array of int32*/	
#define NIWLANGV1_MAC_HEADER_ENABLED						0xB		/*int32*/
/*- Coding ---------------------------------------------------*/
#define NIWLANGV1_SUBCARRIER_MASK							0xC		/*1D Array of float64*/		
#define NIWLANGV1_LOCKED_CLOCK_BIT_ENABLED					0xD		/*int32*/
#define NIWLANGV1_HEADER_ENCODER_ENABLED					0xE		/*int32*/
#define NIWLANGV1_HEADER_INTERLEAVER_ENABLED				0xF		/*int32*/	
#define NIWLANGV1_PAYLOAD_SCRAMBLER_ENABLED					0x10	/*int32*/	
#define NIWLANGV1_PAYLOAD_SCRAMBLER_SEED					0x11	/*int32*/	
#define NIWLANGV1_PAYLOAD_ENCODER_ENABLED					0x12	/*int32*/
#define NIWLANGV1_PAYLOAD_INTERLEAVER_ENABLED				0x13	/*int32*/
/*- Impairments ---------------------------------------------*/
#define NIWLANGV1_CARRIER_FREQUENCY_OFFSET					0x14	/*float64*/
#define NIWLANGV1_IQ_GAIN_IMBALANCE							0x15	/*float64*/
#define NIWLANGV1_I_DC_OFFSET								0x16	/*float64*/
#define NIWLANGV1_Q_DC_OFFSET								0x17	/*float64*/
#define NIWLANGV1_QUADRATURE_SKEW							0x18	/*float64*/
#define NIWLANGV1_SAMPLE_CLOCK_OFFSET						0x19	/*float64*/
/*- Spectrum Control -----------------------------------------*/
#define NIWLANGV1_PULSE_SHAPING_FILTER_TYPE					0x1A	/*int32*/
#define NIWLANGV1_PULSE_SHAPING_FILTER_PARAMETER			0x1B	/*float64*/
#define NIWLANGV1_WINDOW_LENGTH								0x1D	/*float64*/
	/*------------------------------------------------------------*/
#define NIWLANGV1_PEAK_TO_AVERAGE_POWER_RATIO				0x1E	/*float64, readonly*/
#define NIWLANGV1_IQ_WAVEFORM_SIZE							0x25	/*int32, readonly*/
#define NIWLANG_HE_LTF_SIZE                                 0x90	/*int32*/
#define NIWLANG_NUMBER_OF_HE_LTF_SYMBOLS                    0xA5    /*int32*/
#define NIWLANG_RU_OFFSET                                   0x85    /*int32*/
#define NIWLANG_OVERSAMPLING_FACTOR							0x2		/*int32*/

#define NIWLANG_EHT_SIG_MCS_INDEX                           0xD4    /*int32*/
#define NIWLANG_EHT_SIG_COMPRESSION_ENABLED                 0xD5    /*int32*/

/****************************************************************************
*------------------------ Attribute Value Defines -------------------------*
****************************************************************************/

/*- Values For WLAN Standards -*/
#define NIWLANGV1_VAL_STANDARD_80211AG_OFDM					0
#define NIWLANGV1_VAL_STANDARD_80211BG_DSSS					1
#define NIWLANGV1_VAL_STANDARD_80211G_DSSS_OFDM				2

/*- Values For Preamble Format attribute -*/
#define NIWLANGV1_VAL_PREAMBLE_TYPE_SHORT_PREAMBLE			0
#define NIWLANGV1_VAL_PREAMBLE_TYPE_LONG_PREAMBLE			1

/*- Values For Payload Data Type attribute -*/
#define NIWLANGV1_VAL_USER_DEFINED							0
#define NIWLANGV1_VAL_PN_SEQUENCE							1

/*- Values For Pulse Shaping Filter attribute -*/
#define NIWLANGV1_VAL_FILTER_NONE							0
#define NIWLANGV1_VAL_FILTER_RAISED_COSINE					1
#define NIWLANGV1_VAL_FILTER_ROOT_RAISED_COSINE				2
#define NIWLANGV1_VAL_FILTER_GAUSSIAN						3

/*- Values For OFDM Data Rate attribute -*/
#define NIWLANGV1_VAL_OFDM_DATA_RATE_6						0
#define NIWLANGV1_VAL_OFDM_DATA_RATE_9						1
#define NIWLANGV1_VAL_OFDM_DATA_RATE_12						2
#define NIWLANGV1_VAL_OFDM_DATA_RATE_18						3
#define NIWLANGV1_VAL_OFDM_DATA_RATE_24						4
#define NIWLANGV1_VAL_OFDM_DATA_RATE_36						5
#define NIWLANGV1_VAL_OFDM_DATA_RATE_48						6
#define NIWLANGV1_VAL_OFDM_DATA_RATE_54						7

/*- Values For DSSS Data Rate attribute -*/
#define NIWLANGV1_VAL_DSSS_DATA_RATE_1						0
#define NIWLANGV1_VAL_DSSS_DATA_RATE_2						1
#define NIWLANGV1_VAL_DSSS_DATA_RATE_5p5_CCK				2
#define NIWLANGV1_VAL_DSSS_DATA_RATE_5p5_PBCC				3
#define NIWLANGV1_VAL_DSSS_DATA_RATE_11_CCK					4
#define NIWLANGV1_VAL_DSSS_DATA_RATE_11_PBCC				5
#define NIWLANGV1_VAL_DSSS_DATA_RATE_22						6
#define NIWLANGV1_VAL_DSSS_DATA_RATE_33						7

/* Data Rate and Frame Format:HE-LTF Size */
#define NIWLANG_VAL_HE_LTF_SIZE_AUTO                        -1
#define NIWLANG_VAL_HE_LTF_SIZE_4X                          0
#define NIWLANG_VAL_HE_LTF_SIZE_2X                          1
#define NIWLANG_VAL_HE_LTF_SIZE_1X                          2

/* Data Rate and Frame Format: EHT-SIG Compression Enabled */
#define NIWLANG_VAL_EHT_SIG_COMPRESSION_ENABLED_FALSE					0
#define NIWLANG_VAL_EHT_SIG_COMPRESSION_ENABLED_TRUE					1

#define NIWLANGV1_VAL_MAX_ERROR_MESSAGE_SIZE				1024

/****************************************************************************
*---------------- WLAN Generator Function Declarations ---------------------*
****************************************************************************/

/*- Open and Close Session Functions ---------------------------------------*/
int32 __stdcall  niWLANGv1_OpenSession(
    niWLANGenerationSession *session);

/*- Set Attribute Functions -----------------------------------------------*/

int32 __stdcall niWLANGv1_SetStandard(
    niWLANGenerationSession session,
    char* channelString,
    int32 standard);
/*--------------------------------------------------------------------------*/

int32 __stdcall niWLANGv1_SetCarrierFrequency(
    niWLANGenerationSession session,
    char* channelString,
    float64 carrierFrequency);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_SetPowerLevel(
    niWLANGenerationSession session,
    char* channelString,
    float64 powerLevel);

int32 __stdcall niWLANGv1_SetOFDMDataRate(
    niWLANGenerationSession session,
    char* channelString,
    int32 ofdmDataRate);
/*--------------------------------------------------------------------------*/

int32 __stdcall niWLANGv1_SetDSSSDataRate(
    niWLANGenerationSession session,
    char* channelString,
    int32 dsssDataRate);
/*--------------------------------------------------------------------------*/

int32 __stdcall niWLANGv1_SetDSSSPreambleType(
    niWLANGenerationSession session,
    char* channelString,
    int32 preambleFormat);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_SetIdleInterval(
    niWLANGenerationSession session,
    char* channelString,
    float64 idleInterval);

/*--------------------------------------------------------------------------*/

int32 __stdcall niWLANGv1_SetNumberOfFrames(
    niWLANGenerationSession session,
    char* channelString,
    int32 numberOfFrames);
/*--------------------------------------------------------------------------*/


/*- Set and Get Attribute Functions ----------------------------------------*/
int32 __stdcall  niWLANGv1_SetScalarAttributeF64(
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,
    float64 attributeValue);

/*--------------------------------------------------------------------------*/
int32 __stdcall  niWLANGv1_SetScalarAttributeI32 (
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,
    int32 attributeValue);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_SetVectorAttributeF64 (
    niWLANGenerationSession session,
    char* channelString, 
    niWLANGv1_Attr attributeID,
    float64* array,
    int32 arraySizeInSamples);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_SetVectorAttributeI32 (
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,
    int32* array,
    int32 arraySizeInSamples);


/*--------------------------------------------------------------------------*/
int32 __stdcall  niWLANGv1_GetScalarAttributeF64(
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,
    float64* attributeValue);

/*--------------------------------------------------------------------------*/
int32 __stdcall  niWLANGv1_GetScalarAttributeI32 (
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID, 
    int32* attributeValue);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_GetVectorAttributeF64(
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,
    float64* array,
    int32 arraySizeInSamples,
    int32* actualArraySizeInSamples);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANGv1_GetVectorAttributeI32(
    niWLANGenerationSession session,
    char* channelString,
    niWLANGv1_Attr attributeID,	
    int32* array,
    int32 arraySizeInSamples, 
    int32* actualArraySizeInSamples);	

/*- Create Waveform Function -----------------------------------------------*/
int32 __stdcall  niWLANGv1_CreateWaveformComplexF64(
    niWLANGenerationSession session,
    int32 reset,
    float64* t0,
    float64* dt,
    NIComplexNumber* waveform,
    int32 waveformSize,
    int32* actualNumWaveformSamples,
    int32* done);

/*- Get Error Function -----------------------------------------------------*/
int32 __stdcall niWLANGv1_GetErrorString(
    int32 errorCode,
    char errorMessage[],
    int32 errorMessageLen);

/*--------------------------------------------------------------------------*/
int32 __stdcall  niWLANGv1_CloseSession(
    niWLANGenerationSession session);

/*--------------------------------------------------------------------------*/
int32 __stdcall niWLANG_SetOFDMHELTFSize(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMHELTFSize(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetNumberOfHELTFSymbols(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNumberOfHELTFSymbols(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetRUOffset(
	niWLANGenerationSession session,
	char channelString[],
	int32 ofdmDataRate);

int32 __stdcall niWLANG_GetRUOffset(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetOverSamplingFactor( 
	niWLANGenerationSession session,
	char channelString[],
	int32 overSamplingFactor);

int32 __stdcall niWLANG_GetOverSamplingFactor( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetEHTSIGMCSIndex(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetEHTSIGMCSIndex(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

#endif //__NIWLAN_TOOLKIT_GENERATION_DEPRECATED_HEADER_DEFINED__
