/****************************************************************************
 *          National Instruments  BT Generation
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2011.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niBTGeneration.h
 * Purpose:  National Instruments BT Generator
 *           functions declarations.
 *
 ****************************************************************************/

#ifndef __NIBT_TOOLKIT_GENERATION_HEADER_DEFINED__
#define __NIBT_TOOLKIT_GENERATION_HEADER_DEFINED__

#ifdef __cplusplus
extern "C"
{
#endif

// NI-BT Typedefs 
#ifndef _NI_int8_DEFINED_
#define _NI_int8_DEFINED_
    typedef signed char        int8;
#endif
#ifndef _NI_uInt8_DEFINED_
#define _NI_uInt8_DEFINED_
    typedef unsigned char      uInt8;
#endif
#ifndef _NI_int16_DEFINED_
#define _NI_int16_DEFINED_
    typedef signed short       int16;
#endif
#ifndef _NI_uInt16_DEFINED_
#define _NI_uInt16_DEFINED_
    typedef unsigned short     uInt16;
#endif
#ifndef _NI_int32_DEFINED_
#define _NI_int32_DEFINED_
    typedef signed long       int32;
#endif
#ifndef _NI_uInt32_DEFINED_
#define _NI_uInt32_DEFINED_
    typedef unsigned long      uInt32;
#endif
#ifndef _NI_float32_DEFINED_
#define _NI_float32_DEFINED_
    typedef float              float32;
#endif
#ifndef _NI_float64_DEFINED_
#define _NI_float64_DEFINED_
    typedef double             float64;
#endif
#ifndef _NI_int64_DEFINED_
#define _NI_int64_DEFINED_
#ifdef __linux__
    typedef long long int      int64;
#else
    typedef __int64            int64;
#endif
#endif
#ifndef _NI_uInt64_DEFINED_
#define _NI_uInt64_DEFINED_
#ifdef __linux__
    typedef unsigned long long uInt64;
#else
    typedef unsigned __int64   uInt64;
#endif
#endif

#ifndef _NI_BT_GENERATION_SESSION_DEFINED_
#define _NI_BT_GENERATION_SESSION_DEFINED_
    typedef uInt64*            niBTSGSession;
#endif

#ifndef _NI_BT_GENERATION_ATTR_DEFINED_
#define _NI_BT_GENERATION_ATTR_DEFINED_
    typedef int32            niBTSG_Attr;
#endif

typedef uInt32 LVRefNum;
typedef uInt32 ViSession;

#if !defined(_NIComplexNumber)
#define _NIComplexNumber


#pragma pack(push, 8)
typedef struct NIComplexNumber_struct {
    float64 real;
    float64 imaginary;
} NIComplexNumber;
#pragma pack(pop)


#endif

/**********************************************************************************************************************/
/************************************ BT  Generation Attributes *******************************************************/
/**********************************************************************************************************************/

/* -- Properties ----------------------------------------------------------------------*/
#define NIBTSG_CARRIER_MODE										              0x01	/* readwrite, 	int32 */
#define NIBTSG_CARRIER_FREQUENCY                                              0x40    /* readwrite, 	float64 */
#define NIBTSG_OVERSAMPLING_FACTOR                                            0x46    /* readwrite, 	int32 */
#define NIBTSG_WAVEFORM_FILE_VERSION							              0x51    /* readwrite, 	int32 */

/* -- Hardware Settings --------------------------------------------------------------- */	
#define NIBTSG_MAXIMUM_HARDWARE_IQ_RATE                                       0x45	/* readwrite, 	float64 */ 
#define NIBTSG_AUTO_HEADROOM_ENABLED							              0x03	/* readwrite, 	int32 */
#define NIBTSG_HEADROOM											              0x04	/* readwrite, 	float64 */
#define NIBTSG_RUN_TIME_SCALING									              0x4F	/* readwrite, 	float64*/

/* -- Hardware Settings:Recommended Hardware Settings --------------------------------- */		
#define NIBTSG_IQ_RATE											              0x05	/* readonly, 	float64 */
#define NIBTSG_ACTUAL_HEADROOM									              0x06	/* readonly, 	float64 */
			                                                                  
#define NIBTSG_PACKET_TYPE										              0x07	/* readwrite, 	int32 */
#define NIBTSG_MODULATION_INDEX                                               0x44    /* readwrite, 	float64 */
	                                                                          
#define NIBTSG_BD_ADDRESS_LAP									              0x08	/* readwrite, 	int32 */
#define NIBTSG_BD_ADDRESS_UAP									              0x09	/* readwrite, 	int32 */
#define NIBTSG_BD_ADDRESS_NAP									              0x0A	/* readwrite, 	int32 */
			                                                                  
#define NIBTSG_PACKET_HEADER_LT_ADDRESS							              0x0B	/* readwrite, 	int32 */
#define NIBTSG_PACKET_HEADER_FLOW								              0x0C	/* readwrite, 	int32 */
#define NIBTSG_PACKET_HEADER_ARQN								              0x0D	/* readwrite, 	int32 */
#define NIBTSG_PACKET_HEADER_SEQN								              0x0E	/* readwrite, 	int32 */
			
#define NIBTSG_PAYLOAD_HEADER_ENABLED                                         0x42    /* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_HEADER_LLID								              0x0F	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_HEADER_FLOW								              0x10	/* readwrite, 	int32 */
			                                                                  
#define NIBTSG_PAYLOAD_LENGTH_MODE								              0x2B	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_LENGTH									              0x11	/* readwrite, 	int32 */
#define NIBTSG_ACTUAL_PAYLOAD_LENGTH							              0x2C	/* readonly, 	int32 */
#define NIBTSG_PAYLOAD_DATA_TYPE								              0x12	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_PN_ORDER									              0x29	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_PN_SEED									              0x2A	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_USER_DEFINED_BITS						              0x14	/* readwrite, 	int32[] */
			                                                                  
#define NIBTSG_FHS_PAYLOAD_LT_ADDRESS							              0x15	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_DEVICE_CLASS							              0x16	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_SCAN_REPETITION						              0x18	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_PAGE_SCAN_MODE						              0x19	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_DEVICE_CLOCK							              0x1A	/* readwrite, 	int32 */
			                                                                  
#define NIBTSG_FHS_PAYLOAD_BD_ADDRESS_LAP						              0x1B	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_BD_ADDRESS_UAP						              0x1C	/* readwrite, 	int32 */
#define NIBTSG_FHS_PAYLOAD_BD_ADDRESS_NAP						              0x1D	/* readwrite, 	int32 */
			                                                                  
#define NIBTSG_DV_VOICE_PAYLOAD_DATA_TYPE						              0x31	/* readwrite, 	int32 */
#define NIBTSG_DV_VOICE_PAYLOAD_PN_ORDER						              0x2E	/* readwrite, 	int32 */
#define NIBTSG_DV_VOICE_PAYLOAD_PN_SEED							              0x2F	/* readwrite, 	int32 */
#define NIBTSG_DV_VOICE_PAYLOAD_USER_DEFINED_BITS				              0x30	/* readwrite, 	int32[] */
                                                                              
#define NIBTSG_LE_TP_PAYLOAD_TYPE								              0x32	/* readwrite,	int32 */
#define NIBTSG_LE_TP_CORRUPT_ALTERNATE_CRC						              0x36	/* readwrite, 	int32 */

#define NIBTSG_DIRECTION_FINDING_MODE                                         0x4B    /* readwrite, 	int32 */
#define NIBTSG_DIRECTION_FINDING_CONSTANT_TONE_EXTENSION_LENGTH               0x4D    /* readwrite, 	float64*/
#define NIBTSG_DIRECTION_FINDING_CONSTANT_TONE_EXTENSION_SLOT_DURATION        0x4E    /* readwrite, 	float64*/
#define NIBTSG_DIRECTION_FINDING_ANTENNA_SWITCHING_ENABLED                    0x56    /* readwrite, 	int32 */
#define NIBTSG_DIRECTION_FINDING_NUMBER_OF_ANTENNAS                           0x52    /* readwrite, 	int32 */
#define NIBTSG_DIRECTION_FINDING_ANTENNA_SWITCHING_PATTERN                    0x55    /* readwrite, 	string */
#define NIBTSG_DIRECTION_FINDING_ANTENNA_SWITCHING_DURATION			          0x57    /* readwrite, 	float64*/
#define NIBTSG_DIRECTION_FINDING_ANTENNA_SWITCHING_DURATION_USED	          0x58    /* readonly, 	 	float64*/
			
#define NIBTSG_WHITENING_ENABLED								              0x1F	/* readwrite, 	int32 */
#define NIBTSG_WHITENING_CLOCK									              0x20	/* readwrite, 	int32 */
#define NIBTSG_DIRTY_TX_ENABLED									              0x1E	/* readwrite, 	int32 */
#define NIBTSG_DIRTY_TX_MODE									              0x37	/* readwrite, 	int32 */
#define NIBTSG_DIRTY_TX_MODULATION_INDEX_TYPE                                 0x43    /* readwrite, 	int32 */
#define NIBTSG_DIRTY_TX_PARAMETERS_ENABLED_SET					              0x38	/* readwrite, 	int32[] */
#define NIBTSG_DIRTY_TX_CARRIER_FREQUENCY_OFFSET_SET			              0x39	/* readwrite, 	int32[] */
#define NIBTSG_DIRTY_TX_MODULATION_INDEX_SET					              0x3A	/* readwrite, 	float64[] */
#define NIBTSG_DIRTY_TX_SYMBOL_TIMING_ERROR_SET					              0x3B	/* readwrite, 	int32[] */
#define NIBTSG_DIRTY_TX_RESIDUAL_FM_FREQUENCY                                 0x3F    /*readwrite,    float64 */
#define NIBTSG_DIRTY_TX_RESIDUAL_FM_DEVIATION                                 0x3E    /*readwrite,	float64 */
#define NIBTSG_NUMBER_OF_UNIQUE_PACKETS							              0x33	/* readwrite, 	int32 */
#define NIBTSG_NUMBER_OF_IDLE_SLOTS								              0x34	/* readwrite, 	int32 */
#define NIBTSG_PACKET_BIT_SEQUENCE_TRACE_ENABLED                              0x49    /* readwrite, 	int32 */
#define NIBTSG_POWER_RAMP_TIME                                                0x48    /* readwrite,   float64 */
#define NIBTSG_POWER_RAMP_SETTLING_TIME                                       0x47    /* readwrite,   float64 */
			                                                                  
#define NIBTSG_ALL_IQ_IMPAIRMENTS_ENABLED						              0x17	/* readwrite, 	int32 */
#define NIBTSG_IQ_GAIN_IMBALANCE								              0x21	/* readwrite, 	float64 */
#define NIBTSG_QUADRATURE_SKEW									              0x22	/* readwrite, 	float64 */
#define NIBTSG_I_DC_OFFSET										              0x23	/* readwrite, 	float64 */
#define NIBTSG_Q_DC_OFFSET										              0x24	/* readwrite, 	float64 */
#define NIBTSG_CARRIER_FREQUENCY_OFFSET							              0x25	/* readwrite, 	float64 */
#define NIBTSG_SAMPLE_CLOCK_OFFSET						              		  0x63	/* readwrite, 	float64 */
#define NIBTSG_TIME_DELAY							              			  0x64	/* readwrite, 	float64 */
			                                                                  																			  
#define NIBTSG_AWGN_ENABLED										              0x26	/* readwrite, 	int32 */
#define NIBTSG_CARRIER_TO_NOISE_RATIO							              0x27	/* readwrite, 	float64 */
			                                                                  
#define NIBTSG_TOOLKIT_COMPATIBILITY_VERSION					              0x28	/* readonly, 	int32 */
#define NIBTSG_IQ_WAVEFORM_SIZE									              0x2D	/* readonly, 	int32 */

#define NIBTSG_LE_ACCESS_ADDRESS                                              0x3D    /*readwrite,    int32  */

#define NIBTSG_BURST_START_LOCATIONS							              0x5A	/* readonly, 	int32[] */
#define NIBTSG_BURST_STOP_LOCATIONS								              0x5B	/* readonly, 	int32[] */

#define NIBTSG_CS_PACKET_FORMAT									              0x5C	/*readwrite, 	int32 */
#define NIBTSG_CS_SYNC_SEQUENCE									              0x5D	/*readwrite, 	int32 */
#define NIBTSG_CS_PHASE_MEASUREMENT_PERIOD						              0x5E	/*readwrite, 	float64 */
#define NIBTSG_SOUNDING_SEQUENCE_LENGTH							              0x5F	/*readwrite, 	int32 */
#define NIBTSG_SOUNDING_SEQUENCE_MARKER_SIGNALS					              0x60	/*readwrite, 	int32[] */
#define NIBTSG_SOUNDING_SEQUENCE_MARKER_POSITIONS				              0x61	/*readwrite, 	int32[] */
#define NIBTSG_CS_TONE_EXTENSION_SLOT_ENABLED					              0x62	/*readwrite, 	int32 */

#define NIBTSG_BANDWIDTH_BIT_PERIOD_PRODUCT  						          0x65  /* readwrite, 	float64 */

#define NIBTSG_DATA_RATE 					  						          0x66  /* readwrite, 	float64 */

#define NIBTSG_HDT_PACKET_FORMAT									          0x67	/* readwrite, 	int32 */
#define NIBTSG_HDT_PHY_INTERVAL						                          0x68	/* readwrite, 	float64 */
#define NIBTSG_ZADOFF_CHU_INDEX						                          0x69	/* readwrite, 	int32 */
#define NIBTSG_PHYSICAL_CHANNEL_ADDRESS						                  0x6A	/* readwrite, 	int64 */
#define NIBTSG_VHDT_MODE_ENABLED								              0x6B	/* readwrite, 	int32 */
#define NIBTSG_NUMBER_OF_BLOCK_REPETITION_SEQUENCES				              0x6C	/* readwrite, 	int32 */
#define NIBTSG_NUMBER_OF_PAYLOADS											  0x6D	/* readwrite, 	int32 */
#define NIBTSG_FORMAT1_PAYLOAD_ZONE_CONFIGURATION_MODE				   		  0x6E  /* readwrite, 	int32 */
#define NIBTSG_TXLEN_SEQUENCE_NUMBER							  			  0x6F	/* readwrite, 	int32 */
#define NIBTSG_NUMBER_OF_BLOCKS							              		  0x70	/* readwrite, 	int32 */	
#define NIBTSG_BLOCK_SIZE							              		  	  0x71	/* readwrite, 	int32 */
#define NIBTSG_LAST_BLOCK_SIZE						              		  	  0x72	/* readwrite, 	int32 */	
#define NIBTSG_TXBLOCK_MAP					              		  			  0x73	/* readwrite, 	int32 */
#define NIBTSG_PAYLOAD_ZONE_LENGTH								              0x75	/* readonly, 	int32 */
#define NIBTSG_PAYLOAD_CRC_SEED								                  0x76	/* readwrite, 	int64 */
                                                                              
#define NIBTSG_VAL_TOOLKIT_COMPATIBILITY_VERSION_010000			               10000
#define NIBTSG_VAL_TOOLKIT_COMPATIBILITY_VERSION_020000                        20000
                                                                              
#define NIBTSG_VAL_MAX_ERROR_MESSAGE_SIZE						               1024


/* Enum Values */                                                             
#define NIBTSG_VAL_FALSE										               0	
#define NIBTSG_VAL_TRUE											               1
                                                                              
#define NIBTSG_VAL_CARRIER_MODE_BURST							               0
#define NIBTSG_VAL_CARRIER_MODE_CONTINUOUS						               1
                                                                              
#define NIBTSG_VAL_PACKET_TYPE_NULL								               0
#define NIBTSG_VAL_PACKET_TYPE_POLL								               1
#define NIBTSG_VAL_PACKET_TYPE_FHS								               2
#define NIBTSG_VAL_PACKET_TYPE_DM1								               3
#define NIBTSG_VAL_PACKET_TYPE_DH1								               4
#define NIBTSG_VAL_PACKET_TYPE_2DH1								               5
#define NIBTSG_VAL_PACKET_TYPE_HV1								               6
#define NIBTSG_VAL_PACKET_TYPE_HV2								               7
#define NIBTSG_VAL_PACKET_TYPE_2EV3								               8
#define NIBTSG_VAL_PACKET_TYPE_HV3								               9
#define NIBTSG_VAL_PACKET_TYPE_EV3								               10
#define NIBTSG_VAL_PACKET_TYPE_3EV3								               11
#define NIBTSG_VAL_PACKET_TYPE_DV								               12
#define NIBTSG_VAL_PACKET_TYPE_3DH1								               13
#define NIBTSG_VAL_PACKET_TYPE_AUX1								               14
#define NIBTSG_VAL_PACKET_TYPE_DM3								               15
#define NIBTSG_VAL_PACKET_TYPE_2DH3								               16
#define NIBTSG_VAL_PACKET_TYPE_DH3								               17
#define NIBTSG_VAL_PACKET_TYPE_3DH3								               18
#define NIBTSG_VAL_PACKET_TYPE_EV4								               19
#define NIBTSG_VAL_PACKET_TYPE_2EV5								               20
#define NIBTSG_VAL_PACKET_TYPE_EV5								               21
#define NIBTSG_VAL_PACKET_TYPE_3EV5								               22
#define NIBTSG_VAL_PACKET_TYPE_DM5								               23
#define NIBTSG_VAL_PACKET_TYPE_2DH5								               24
#define NIBTSG_VAL_PACKET_TYPE_DH5								               25
#define NIBTSG_VAL_PACKET_TYPE_3DH5								               26
#define NIBTSG_VAL_PACKET_TYPE_LE_TP							               27
#define NIBTSG_VAL_PACKET_TYPE_LE_TP_EXT                                       28
#define NIBTSG_VAL_PACKET_TYPE_LE_ENHANCED                                     29
#define NIBTSG_VAL_PACKET_TYPE_LE_LR_125K                                      30
#define NIBTSG_VAL_PACKET_TYPE_LE_LR_500K                                      31
#define NIBTSG_VAL_PACKET_TYPE_LE_CS_1M							               32
#define NIBTSG_VAL_PACKET_TYPE_LE_CS_2M							               33
#define NIBTSG_VAL_PACKET_TYPE_LE_HDT										   34
#define NIBTSG_VAL_PACKET_TYPE_ID								               254
#define NIBTSG_VAL_PACKET_TYPE_IDLE								               255
                                                                               
#define NIBTSG_VAL_PACKET_HEADER_ARQN_NAK						               0
#define NIBTSG_VAL_PACKET_HEADER_ARQN_ACK						               1
                                                                               
#define NIBTSG_VAL_PAYLOAD_HEADER_ENABLED_FALSE                                0
#define NIBTSG_VAL_PAYLOAD_HEADER_ENABLED_TRUE                                 1
                                                                               
#define NIBTSG_VAL_PAYLOAD_LENGTH_MODE_MAXIMUM_LENGTH			               0
#define NIBTSG_VAL_PAYLOAD_LENGTH_MODE_USER_DEFINED				               1
                                                                               
#define NIBTSG_VAL_PAYLOAD_DATA_TYPE_PN_SEQUENCE				               0
#define NIBTSG_VAL_PAYLOAD_DATA_TYPE_USER_DEFINED_BITS			               1
                                                                               
#define NIBTSG_VAL_DIRTY_TX_MODULATION_INDEX_TYPE_STANDARD                     0
#define NIBTSG_VAL_DIRTY_TX_MODULATION_INDEX_TYPE_STABLE                       1
                                                                               
#define NIBTSG_VAL_DIRTY_TX_MODE_STANDARD						               0
#define NIBTSG_VAL_DIRTY_TX_MODE_USER_DEFINED					               1
#define NIBTSG_VAL_DIRTY_TX_MODE_FREQUENCY_DRIFT				               2
                                                                               
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_PRBS9						               0	
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_11110000					               1
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_10101010					               2
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_PRBS15					               3
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_11111111					               4
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_00000000					               5
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_00001111					               6
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_01010101					               7
#define NIBTSG_VAL_LE_TP_PAYLOAD_TYPE_USER_DEFINED_BITS			               8
                                                                               
#define NIBTSG_FILE_OPERATION_MODE_OPEN							               0
#define NIBTSG_FILE_OPERATION_MODE_OPEN_OR_CREATE				               1
#define NIBTSG_FILE_OPERATION_MODE_CREATE_OR_REPLACE			               2
#define NIBTSG_FILE_OPERATION_MODE_CREATE						               3
                                                                               
#define NIBTSG_STANDARD_BASIC_EDR								               0
#define NIBTSG_STANDARD_LE										               1
#define NIBTSG_STANDARD_LE_CS									               2

#define NIBTSG_VAL_DIRECTION_FINDING_MODE_DISABLED                             0
#define NIBTSG_VAL_DIRECTION_FINDING_MODE_ANGLE_OF_ARRIVAL                     1
#define NIBTSG_VAL_DIRECTION_FINDING_MODE_ANGLE_OF_DEPARTURE                   2

#define NIBTSG_VAL_CS_PACKET_FORMAT_SYNC						               0
#define NIBTSG_VAL_CS_PACKET_FORMAT_CS_TONE						               1
#define NIBTSG_VAL_CS_PACKET_FORMAT_CS_TONE_AFTER_SYNC			               2
#define NIBTSG_VAL_CS_PACKET_FORMAT_CS_TONE_BEFORE_SYNC			               3

#define NIBTSG_VAL_CS_SYNC_SEQUENCE_NONE						               0
#define NIBTSG_VAL_CS_SYNC_SEQUENCE_SOUNDING_SEQUENCE			               1
#define NIBTSG_VAL_CS_SYNC_SEQUENCE_PAYLOAD_PATTERN			               	   2

#define NIBTSG_VAL_SOUNDING_SEQUENCE_MARKER_SIGNALS_1100		               0
#define NIBTSG_VAL_SOUNDING_SEQUENCE_MARKER_SIGNALS_0011		               1

#define NIBTSG_VAL_HDT_PACKET_FORMAT_SHORT_FORMAT                              0
#define NIBTSG_VAL_HDT_PACKET_FORMAT_FORMAT0                            	   1
#define NIBTSG_VAL_HDT_PACKET_FORMAT_FORMAT1                   				   2

/* Waveform File Version */
#define NIBTSG_VAL_WAVEFORM_FILE_VERSION_1_0					               0
#define NIBTSG_VAL_WAVEFORM_FILE_VERSION_2_0					               1

/****************************************************************************
*--------------------- BT Generation Function Declarations --------------*
****************************************************************************/

// BTSG Open Session
int32 __stdcall niBTSG_OpenSession(
	char sessionName[], 
	int32 toolkitCompatibilityVersion, 
	niBTSGSession *session, 
	int32 *isNewSession);

// Set Attribute Functions
int32 __stdcall niBTSG_SetAttributeString(
	niBTSGSession session,
	char channelString[], 
	int32 attributeID, 
	char attributeValue[]);

int32 __stdcall niBTSG_SetScalarAttributeF64(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID,                              
    float64 attributeValue);

int32 __stdcall niBTSG_SetScalarAttributeI32(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID, 
    int32 attributeValue);

int32 __stdcall niBTSG_SetScalarAttributeI64(
	niBTSGSession session,
	char channelString[], 
	niBTSG_Attr attributeID, 
	int64 attributeValue);

int32 __stdcall niBTSG_SetVectorAttributeI32(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID, 
    int32 dataArray[], 
    int32 dataArraySize);
	
int32 __stdcall niBTSG_SetVectorAttributeF64(
	niBTSGSession session,
	char channelString[], 
	niBTSG_Attr attributeID,
	float64 data[],
	int32 dataArraySize);	

// Get Attribute Functions
int32 __stdcall niBTSG_GetAttributeString(
	niBTSGSession session,
	char channelString[],
	int32 attributeID,
	char attributeValue[],
	int32 bufferSize,
	int32 *actualStringSize);

int32 __stdcall niBTSG_GetScalarAttributeF64(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID, 
    float64 *attributeValue);

int32 __stdcall niBTSG_GetScalarAttributeI32(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID, 
    int32 *attributeValue);

int32 __stdcall niBTSG_GetScalarAttributeI64(
	niBTSGSession session,
	char channelString[], 
	niBTSG_Attr attributeID, 
	int64 *attributeValue);
	
int32 __stdcall niBTSG_GetVectorAttributeI32(
    niBTSGSession session,
    char channelString[], 
    niBTSG_Attr attributeID,  
    int32 dataArray[], 
    int32 dataArraySize,
    int32 *actualNumDataArrayElements);
	
int32 __stdcall niBTSG_GetVectorAttributeF64(
	niBTSGSession session,
	char channelString[],
	niBTSG_Attr attributeID,
	float64 data[],
	int32 dataArraySize,
	int32* actualNumDataArrayElements);	

// Reset Attribute
int32 __stdcall niBTSG_ResetAttribute(
    niBTSGSession session,
    char channelString[],
    niBTSG_Attr attributeID);

// BTSG Create Waveform
int32 __stdcall niBTSG_CreateWaveformComplexF64(
	niBTSGSession session,
	int32 reset,
	float64 *t0, 
	float64 *dt, 
	NIComplexNumber waveform[], 
	int32 waveformSize, 
	int32 *actualWaveformSize,
	int32 *generationDone);

// BTSG Reset Session
int32 __stdcall niBTSG_ResetSession(
    niBTSGSession session);	
	
// BTSG Get Error String
int32 __stdcall niBTSG_GetErrorString(	
	niBTSGSession session, 
	int32 errorCode, 
	char errorMessage[], 
	int32 errorMessageLength);

int32 __stdcall niBTSG_SaveConfigurationToFile(
	niBTSGSession session, 
	char filePath[], 
	int32 operation);
	
// Loading and Saving Configuration 
int32 __stdcall niBTSG_LoadConfigurationFromFile(
	niBTSGSession session, 
	char filePath[], 
	int32 reset);

// Reading and Writing Waveforms
int32 __stdcall niBTSG_CreateAndWriteWaveformsToFile(
	niBTSGSession session,
	char filePath[],
	int32 fileOperation);	

int32 __stdcall niBTSG_ReadWaveformFromFile(
	char filePath[],
	char waveformName[],
	int64 offset,
	int64 count,
	float64 *t0, 
    float64 *dt, 
   	NIComplexNumber waveform[], 
   	int32 waveformSize, 
   	int32 *actualNumWaveformSamples,
	float64 *IQRate,
	float64 *headroom,
	int32 *eof);

// BTSG Channel Number To Carrier Frequency
int32 __stdcall niBTSG_ChannelNumberToCarrierFrequency(
	int32 channelNumber,
	int32 standard,
	float64 *carrierFrequency);
	
int32 __stdcall niBTSG_CarrierFrequencyToChannelNumber(
    float64 carrierFrequency,
	int32 standard,
	int32 *channelNumber);	
	
int32 __stdcall niBTSG_GetCurrentIterationPacketBitSequenceTrace(
    niBTSGSession session,
	int32 packetBitSequenceTrace[],
    int32 dataArraySize,
	int32 *actualArraySize); 	
	
// BTSG Close Session
int32 __stdcall niBTSG_CloseSession(
    niBTSGSession session);

// Set/Get Functions

int32 __stdcall niBTSG_SetCarrierFrequency(
	niBTSGSession session, 
	char channelString[],
	float64 value);
	
int32 __stdcall niBTSG_GetCarrierFrequency(
	niBTSGSession session, 
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetCarrierMode(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetCarrierMode(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetOversamplingFactor(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetOversamplingFactor(
	niBTSGSession session,
	char channelString[],
	int32 *value);
		
int32 __stdcall niBTSG_SetMaximumHardwareIQRate(
	niBTSGSession session,
	char channelString[],
	float64 value);
		
int32 __stdcall niBTSG_GetMaximumHardwareIQRate(
	niBTSGSession session,
	char channelString[],
	float64 *value);
			
int32 __stdcall niBTSG_SetAutoHeadroomEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetAutoHeadroomEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetHeadroom(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetHeadroom(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_GetIQRate(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_GetActualHeadroom(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetPacketType(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketType(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetModulationIndex(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetModulationIndex(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetBandwidthBitPeriodProduct(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetBandwidthBitPeriodProduct(
	niBTSGSession session,
	char channelString[],
	float64 *value);	

int32 __stdcall niBTSG_SetDataRate(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDataRate(
	niBTSGSession session,
	char channelString[],
	int32 *value);	
		
int32 __stdcall niBTSG_SetBDAddress(
	niBTSGSession session,
	char channelString[],
	int32 valueLAP,
	int32 valueUAP,
	int32 valueNAP);
	
int32 __stdcall niBTSG_GetBDAddress(
	niBTSGSession session,
	char channelString[],
	int32 *valueLAP,
	int32 *valueUAP,
	int32 *valueNAP);

int32 __stdcall niBTSG_SetPacketHeaderLTAddress(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketHeaderLTAddress(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPacketHeaderFLOW(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketHeaderFLOW(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPacketHeaderARQN(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketHeaderARQN(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPacketHeaderSEQN(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketHeaderSEQN(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadHeaderEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niBTSG_GetPayloadHeaderEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetPayloadHeaderLLID(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadHeaderLLID(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadHeaderFLOW(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadHeaderFLOW(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadLengthMode(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadLengthMode(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadLength(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadLength(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_GetActualPayloadLength(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadDataType(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadDataType(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadPNOrder(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadPNOrder(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadPNSeed(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPayloadPNSeed(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPayloadUserDefinedBits(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);

int32 __stdcall niBTSG_GetPayloadUserDefinedBits(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);

int32 __stdcall niBTSG_SetFHSPayloadLTAddress(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFHSPayloadLTAddress(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetFHSPayloadDeviceClass(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFHSPayloadDeviceClass(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetFHSPayloadScanRepetition(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFHSPayloadScanRepetition(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetFHSPayloadPageScanMode(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFHSPayloadPageScanMode(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetFHSPayloadDeviceClock(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFHSPayloadDeviceClock(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetFHSPayloadBDAddress(
	niBTSGSession session,
	char channelString[],
	int32 valueLAP,
	int32 valueUAP,
	int32 valueNAP);

int32 __stdcall niBTSG_GetFHSPayloadBDAddress(
	niBTSGSession session,
	char channelString[],
	int32 *valueLAP,
	int32 *valueUAP,
	int32 *avlueNAP);
	
int32 __stdcall niBTSG_SetDVVoicePayloadDataType(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDVVoicePayloadDataType(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetDVVoicePayloadPNOrder(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDVVoicePayloadPNOrder(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetDVVoicePayloadPNSeed(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDVVoicePayloadPNSeed(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetDVVoicePayloadUserDefinedBits(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);

int32 __stdcall niBTSG_GetDVVoicePayloadUserDefinedBits(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);
	
int32 __stdcall niBTSG_SetLE_TPPayloadType(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetLE_TPPayloadType(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetDirectionFindingMode(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDirectionFindingMode(
	niBTSGSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niBTSG_SetDirectionFindingConstantToneExtensionLength(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetDirectionFindingConstantToneExtensionLength(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetDirectionFindingConstantToneExtensionSlotDuration(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetDirectionFindingConstantToneExtensionSlotDuration(
	niBTSGSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niBTSG_SetDirectionFindingAntennaSwitchingEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDirectionFindingAntennaSwitchingEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niBTSG_SetDirectionFindingNumberOfAntennas(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDirectionFindingNumberOfAntennas(
	niBTSGSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niBTSG_SetDirectionFindingAntennaSwitchingPattern(
	niBTSGSession session,
	char channelString[],
	char attrVal[]);

int32 __stdcall niBTSG_GetDirectionFindingAntennaSwitchingPattern(
	niBTSGSession session,
	char channelString[],
	int32 arraySize,
	char attrVal[]);
	
int32 __stdcall niBTSG_SetDirectionFindingAntennaSwitchingDuration(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetDirectionFindingAntennaSwitchingDuration(
	niBTSGSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niBTSG_GetDirectionFindingAntennaSwitchingDurationUsed(
	niBTSGSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niBTSG_SetAntennaRelativePhaseAndAmplitude(
    niBTSGSession session,
	char channelString[],
	float64 relativeAmplitudeDB[], 
	float64 relativePhaseDeg[], 
	int32 arraySize);
	
int32 __stdcall niBTSG_SetWhiteningEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetWhiteningEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetWhiteningClock(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetWhiteningClock(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetDirtyTxEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetDirtyTxEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetDirtyTxMode(
	niBTSGSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niBTSG_GetDirtyTxMode(
	niBTSGSession session, 
	char channelString[], 
	int32 *value);
	
int32 __stdcall niBTSG_SetDirtyTxModulationIndexType(
	niBTSGSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niBTSG_GetDirtyTxModulationIndexType(
	niBTSGSession session, 
	char channelString[], 
	int32 *value);

int32 __stdcall niBTSG_SetDirtyTxParametersEnabledSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize);

int32 __stdcall niBTSG_GetDirtyTxParametersEnabledSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);

int32 __stdcall niBTSG_SetDirtyTxCarrierFrequencyOffsetSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize);

int32 __stdcall niBTSG_GetDirtyTxCarrierFrequencyOffsetSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);

int32 __stdcall niBTSG_SetDirtyTxModulationIndexSet(
	niBTSGSession session, 
	char channelString[], 
	float64 dataArray[], 
	int32 dataArraySize);

int32 __stdcall niBTSG_GetDirtyTxModulationIndexSet(
	niBTSGSession session, 
	char channelString[], 
	float64 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);

int32 __stdcall niBTSG_SetDirtyTxSymbolTimingErrorSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize);

int32 __stdcall niBTSG_GetDirtyTxSymbolTimingErrorSet(
	niBTSGSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);	

int32 __stdcall niBTSG_SetNumberOfUniquePackets(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetNumberOfUniquePackets(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetNumberOfIdleSlots(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetNumberOfIdleSlots(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetAllIQImpairmentsEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetPacketBitSequenceTraceEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetPacketBitSequenceTraceEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);	
	
int32 __stdcall niBTSG_SetPowerRampTime(
	niBTSGSession session,
	char channelString[],
	float64 value);	
	
int32 __stdcall niBTSG_GetPowerRampTime(	
	niBTSGSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niBTSG_SetPowerRampSettlingTime(
	niBTSGSession session,
	char channelString[],
	float64 value);	
	
int32 __stdcall niBTSG_GetPowerRampSettlingTime(	
	niBTSGSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niBTSG_GetAllIQImpairmentsEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetIQGainImbalance(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetIQGainImbalance(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetQuadratureSkew(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetQuadratureSkew(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetIDCOffset(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetIDCOffset(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetQDCOffset(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetQDCOffset(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetCarrierFrequencyOffset(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetCarrierFrequencyOffset(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetSampleClockOffset(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetSampleClockOffset(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetTimeDelay(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetTimeDelay(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetAWGNEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetAWGNEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetCarrierToNoiseRatio(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetCarrierToNoiseRatio(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_GetToolkitCompatibilityVersion(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_GetIQWaveformSize(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetDirtyTxResidualFMDeviation(
	niBTSGSession session,
	char channelString[],
	float64 value);
	
int32 __stdcall niBTSG_GetDirtyTxResidualFMDeviation(
	niBTSGSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niBTSG_SetDirtyTxResidualFMFrequency(
	niBTSGSession session,
	char channelString[],
	float64 value);	
	
int32 __stdcall niBTSG_GetDirtyTxResidualFMFrequency(
	niBTSGSession session,
	char channelString[],
	float64 *value);
	
	
int32 __stdcall niBTSG_SetLEAccessAddress(
    niBTSGSession session,
	char channelString[],
	int32 value);	
	
int32 __stdcall niBTSG_GetLEAccessAddress(
    niBTSGSession session,
	char channelString[],
	int32 *value);	
 	
int32 __stdcall niBTSG_GetBurstStartLocations(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);
	
int32 __stdcall niBTSG_GetBurstStopLocations(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);
	
int32 __stdcall niBTSG_SetRunTimeScaling(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetRunTimeScaling(
	niBTSGSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niBTSG_SetWaveformFileVersion(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetWaveformFileVersion(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetCSPacketFormat(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetCSPacketFormat(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetCSSyncSequence(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetCSSyncSequence(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetCSPhaseMeasurementPeriod(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetCSPhaseMeasurementPeriod(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetSoundingSequenceLength(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetSoundingSequenceLength(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetSoundingSequenceMarkerSignals(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);

int32 __stdcall niBTSG_GetSoundingSequenceMarkerSignals(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);
	
int32 __stdcall niBTSG_SetSoundingSequenceMarkerPositions(
	niBTSGSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);
	
int32 __stdcall niBTSG_GetSoundingSequenceMarkerPositions(
    niBTSGSession session,
    char channelString[],
    int32 dataArray[],
    int32 dataArraySize,
    int32* actualNumDataArrayElements);

int32 __stdcall niBTSG_SetCSToneExtensionSlotEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetCSToneExtensionSlotEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetHDTPacketFormat(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetHDTPacketFormat(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetHDTPHYInterval(
	niBTSGSession session,
	char channelString[],
	float64 value);

int32 __stdcall niBTSG_GetHDTPHYInterval(
	niBTSGSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niBTSG_SetZadoffChuIndex(
	niBTSGSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niBTSG_GetZadoffChuIndex(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_SetPhysicalChannelAddress(
	niBTSGSession session,
	char channelString[],
	int64 value);
	
int32 __stdcall niBTSG_GetPhysicalChannelAddress(
	niBTSGSession session,
	char channelString[],
	int64 *value);
	
int32 __stdcall niBTSG_SetVHDTModeEnabled(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetVHDTModeEnabled(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetNumberOfBlockRepetitionSequences(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetNumberOfBlockRepetitionSequences(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetNumberOfPayloads(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetNumberOfPayloads(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetFormat1PayloadZoneConfigurationMode(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetFormat1PayloadZoneConfigurationMode(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetTxLenSequenceNumber(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetTxLenSequenceNumber(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetNumberOfBlocks(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetNumberOfBlocks(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetBlockSize(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetBlockSize(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetLastBlockSize(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetLastBlockSize(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetTxBlockMap(
	niBTSGSession session,
	char channelString[],
	int32 value);

int32 __stdcall niBTSG_GetTxBlockMap(
	niBTSGSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niBTSG_GetPayloadZoneLength(
	niBTSGSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niBTSG_SetPayloadCRCSeed(
	niBTSGSession session,
	char channelString[],
	int64 value);

int32 __stdcall niBTSG_GetPayloadCRCSeed(
	niBTSGSession session,
	char channelString[],
	int64 *value);

	
#ifdef __cplusplus
}
#endif

#endif //__NIBT_TOOLKIT_GENERATION_HEADER_DEFINED__