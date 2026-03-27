/****************************************************************************
*          National Instruments WLAN Signal Generator
*---------------------------------------------------------------------------
*   Copyright (c) National Instruments 2016.  All Rights Reserved.
*---------------------------------------------------------------------------
*
* Title:    niWLANGeneration.h
* Purpose:  National Instruments WLAN Generator
*           functions declarations.
*
****************************************************************************/


#ifndef __NIWLAN_TOOLKIT_GENERATION_HEADER_DEFINED__
#define __NIWLAN_TOOLKIT_GENERATION_HEADER_DEFINED__

#ifdef __cplusplus
extern "C"
{
#endif

	//	 NI-WLAN Typedefs
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
	typedef signed long        int32;
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

#ifndef _NI_WLAN_GENERATION_SESSION_DEFINED_
#define _NI_WLAN_GENERATION_SESSION_DEFINED_
	typedef uInt64*      niWLANGenerationSession;
#endif

#ifndef _NI_WLAN_GENERATION_ATTR_DEFINED_
#define _NI_WLAN_GENERATION_ATTR_DEFINED_
	typedef int32		niWLANG_Attr;
#endif

/****************************************************************************
*---------------------------- Attribute Defines ---------------------------*
****************************************************************************/
#define NIWLANG_COMPATIBILITY_VERSION						0x38    /*int32,readonly*/

#define NIWLANG_STANDARD									0x1F	/*int32*/
#define NIWLANG_OVERSAMPLING_RATIO							0xD3	/*int32*/
#define NIWLANG_CARRIER_FREQUENCY							0x0		/*float64*/
#define NIWLANG_PPDU_TYPE									0x5F	/*int32*/
#define NIWLANG_RU_SIZE                                     0x84    /*int32*/
#define NIWLANG_RU_OFFSET_MRU_INDEX                         0x85    /*int32*/
#define NIWLANG_RU_TYPE                                     0xDE    /*int32*/
#define NIWLANG_DISTRIBUTION_BANDWIDTH                      0xE3    /*float64*/
#define NIWLANG_RU_ALLOCATION_MODE                          0xCD	/*int32*/
#define NIWLANG_RU_ALLOCATION                               0xCE    /*1D Array of int32*/
#define NIWLANG_USER_ENABLED                                0xCF	/*int32*/
#define NIWLANG_RELATIVE_POWER                              0x88    /*float64*/
#define NIWLANG_POWER_BOOST_FACTOR                          0xA4    /*float64*/
#define NIWLANG_NON_HT_MODULATION_MODE                      0x7F    /*int32*/
#define NIWLANG_OFDM_DATA_RATE								0x20	/*int32*/
#define NIWLANG_DSSS_DATA_RATE								0x21	/*int32*/
#define NIWLANG_IDLE_INTERVAL								0x3		/*float64*/
#define NIWLANG_IDLE_INTERVAL_MODE                          0xC7    /*int32*/
#define NIWLANG_NUMBER_OF_FRAMES							0x6		/*int32*/
#define NIWLANG_FRAME_DURATION								0xD1	/*float64*/
#define NIWLANG_UNFRAMED_DATA_MODULATION_ENABLED			0xD2	/*int32*/
#define NIWLANG_DSSS_PREAMBLE_TYPE							0x4		/*int32*/
#define NIWLANG_STA_ID                                      0xA3    /*int32*/
#define NIWLANG_DUAL_CARRIER_MODULATION_ENABLED             0x9A    /*int32*/
#define NIWLANG_2XLDPC_ENABLED                              0xE4    /*int32*/
#define NIWLANG_UNEQUAL_MODULATION_ENABLED                  0xE5    /*int32*/
#define NIWLANG_UNEQUAL_MODULATION_PATTERN_INDEX            0xE6    /*int32*/
#define NIWLANG_BSS_COLOR                                   0xB8    /*int32*/
#define NIWLANG_WAVEFORM_FILE_VERSION                       0xCA    /*int32*/
#define NIWLANG_CHANNELIZATION                              0xE7    /*int32*/

/*- Payload Attributes ----------------------------------------*/
#define NIWLANG_PAYLOAD_AUTO_NUMBER_OF_MPDUS                0xB2	/*int32*/
#define NIWLANG_PAYLOAD_MAC_FRAME_TYPE                      0xBC    /*int32*/
#define NIWLANG_AUTO_PAYLOAD_DATA_LENGTH_MODE               0xB3    /*int32*/
#define NIWLANG_PAYLOAD_NUMBER_OF_MPDUS                     0x68	/*int32*/
#define NIWLANG_PAYLOAD_DATA_LENGTH							0x5		/*int32*/
#define NIWLANG_PAYLOAD_DATA_TYPE							0x7		/*int32*/
#define NIWLANG_PAYLOAD_PN_ORDER							0x8		/*int32*/
#define NIWLANG_PAYLOAD_PN_SEED								0x9		/*int32*/
#define NIWLANG_PAYLOAD_USER_DEFINED_BITS					0xA		/*1D Array of int32*/
#define NIWLANG_MAC_FRAME_FORMAT							0x78	/*int32*/
#define NIWLANG_MAC_HEADER_ENABLED							0xB		/*int32*/
#define NIWLANG_MAC_FRAME_CONTROL							0x39	/*int32*/
#define NIWLANG_MAC_DURATION_OR_ID							0x3A    /*int32*/
#define NIWLANG_MAC_ADDRESS1_ENABLED						0x3B    /*int32*/
#define NIWLANG_MAC_ADDRESS1_LENGTH							0x79	/*int32*/
#define NIWLANG_MAC_ADDRESS1								0x3C    /*int64*/
#define NIWLANG_MAC_ADDRESS2_ENABLED						0x3D    /*int32*/
#define NIWLANG_MAC_ADDRESS2_LENGTH							0x7A	/*int32*/
#define NIWLANG_MAC_ADDRESS2								0x3E    /*int64*/
#define NIWLANG_MAC_ADDRESS3_ENABLED						0x3F    /*int32*/
#define NIWLANG_MAC_ADDRESS3								0x40    /*int64*/
#define NIWLANG_MAC_SEQUENCE_CONTROL_ENABLED				0x41    /*int32*/
#define NIWLANG_MAC_SEQUENCE_CONTROL						0x42    /*int32*/
#define NIWLANG_MAC_ADDRESS4_ENABLED						0x43    /*int32*/
#define NIWLANG_MAC_ADDRESS4								0x44    /*int64*/
#define NIWLANG_MAC_QOS_CONTROL_ENABLED						0x35    /*int32*/
#define NIWLANG_MAC_QOS_CONTROL								0x47    /*int32*/
#define NIWLANG_MAC_HT_CONTROL_ENABLED						0x48    /*int32*/
#define NIWLANG_MAC_HT_CONTROL								0x49    /*int32*/
#define NIWLANG_MAC_SEQUENCE_NUMBER_INCREMENT_ENABLED		0x50    /*int32*/
#define NIWLANG_MAC_SEQUENCE_NUMBER_INCREMENT_INTERVAL		0x51    /*int32*/
#define NIWLANG_MAC_FRAGMENT_NUMBER_INCREMENT_ENABLED		0x52    /*int32*/
#define NIWLANG_MPDU_LENGTH									0x53    /*int32,readonly*/
#define NIWLANG_MAC_FCS_ENABLED                             0x64	/*int32*/
#define NIWLANG_TRIGGER_FRAME_AID12                         0xC4    /*int32*/
#define NIWLANG_TRIGGER_FRAME_CS_REQUIRED                   0xBE    /*int32*/
#define NIWLANG_TRIGGER_FRAME_AP_TX_POWER                   0xAC    /*int32*/
#define NIWLANG_TRIGGER_FRAME_TARGET_RSSI                   0xAD    /*int32*/
#define NIWLANG_TRIGGER_FRAME_MAC_PADDING_DURATION          0xBD    /*int32*/
#define NIWLANG_NUMBER_OF_DATA_SYMBOLS                      0x5E	/*int32*/
#define NIWLANG_AMPDU_ENABLED                             	0x67	/*int32*/
/*- Coding ---------------------------------------------------*/
#define NIWLANG_SUBCARRIER_MASK								0xC		/*1D Array of float64*/		
#define NIWLANG_LOCKED_CLOCK_BIT_ENABLED					0xD		/*int32*/
#define NIWLANG_HEADER_ENCODER_ENABLED						0xE		/*int32*/
#define NIWLANG_HEADER_INTERLEAVER_ENABLED					0xF		/*int32*/	
#define NIWLANG_PAYLOAD_SCRAMBLER_ENABLED					0x10	/*int32*/	
#define NIWLANG_PAYLOAD_SCRAMBLER_SEED						0x11	/*int32*/	
#define NIWLANG_PAYLOAD_ENCODER_ENABLED						0x12	/*int32*/
#define NIWLANG_FEC_CODING_TYPE								0x46	/*int32*/
#define NIWLANG_PAYLOAD_INTERLEAVER_ENABLED					0x13	/*int32*/
/*- Impairments ---------------------------------------------*/
#define NIWLANG_CARRIER_FREQUENCY_OFFSET					0x14	/*float64*/
#define NIWLANG_IQ_GAIN_IMBALANCE							0x15	/*float64*/
#define NIWLANG_I_DC_OFFSET									0x16	/*float64*/
#define NIWLANG_Q_DC_OFFSET									0x17	/*float64*/
#define NIWLANG_QUADRATURE_SKEW								0x18	/*float64*/
#define NIWLANG_TIMING_SKEW									0x4F	/*float64*/
#define NIWLANG_SAMPLE_CLOCK_OFFSET							0x19	/*float64*/
#define NIWLANG_ALL_IQ_IMPAIRMENTS_ENABLED					0x60    /*int32*/
#define NIWLANG_AWGN_ENABLED								0x61	/*int32*/
#define NIWLANG_TIME_DELAY                                  0x87	/*float64*/
#define NIWLANG_CARRIER_TO_NOISE_RATIO						0x62    /*float64*/
/*- Spectrum Control -----------------------------------------*/
#define NIWLANG_PULSE_SHAPING_FILTER_ENABLED				0x36	/*int32*/
#define NIWLANG_PULSE_SHAPING_FILTER_TYPE					0x1A	/*int32*/
#define NIWLANG_PULSE_SHAPING_FILTER_PARAMETER				0x1B	/*float64*/
#define NIWLANG_DSSS_WINDOW_LENGTH							0x1D	/*float64*/
#define NIWLANG_WINDOWING_METHOD							0x4A	/*int32*/ 
#define NIWLANG_PULSE_SHAPING_FILTER_LENGTH					0x70	/*int32*/
#define NIWLANG_OFDM_WINDOW_LENGTH							0x7D	/*int32*/

	/*------------------------------------------------------------*/
#define NIWLANG_IQ_WAVEFORM_SIZE							0x25	/*int32, readonly*/

/* 802.11n Attributes*/
#define NIWLANG_NUMBER_OF_TRANSMIT_CHANNELS					0x2F	/*int32*/
#define NIWLANG_MCS_INDEX									0x29	/*int32*/
#define NIWLANG_HE_SIG_B_MCS_INDEX                          0xA1    /*int32*/
#define NIWLANG_HE_SIG_B_DUAL_CARRIER_MODULATION_ENABLED    0xA2	/*int32*/
#define NIWLANG_CHANNEL_BANDWIDTH							0x2A	/*float64*/
#define NIWLANG_80211N_PLCP_FRAME_FORMAT					0x2B	/*int32*/
#define NIWLANG_NUMBER_OF_EXTENSION_SPATIAL_STREAMS			0x2E	/*int32*/
#define NIWLANG_NUMBER_OF_USERS								0x73	/*int32*/
#define NIWLANG_MAPPING_MATRIX_TYPE							0x37	/*int32*/
#define NIWLANG_STBC_INDEX									0x31	/*int32*/
#define NIWLANG_80211AH_PREAMBLE_TYPE						0x77	/*int32*/
#define NIWLANG_TRANSMISSION_MODE                           0x7C	/*int32*/
#define NIWLANG_PREAMBLE_PUNCTURING_ENABLED                 0xBF    /*int32*/
#define NIWLANG_PRIMARY_20MHZ_CHANNEL_INDEX                 0xC0    /*int32*/
#define NIWLANG_PREAMBLE_PUNCTURING_MASK                    0xC1    /*int32*/
/*-Hardware Settings----------------------------------------------*/
#define NIWLANG_AUTO_HEADROOM_ENABLED						0x57    /*int32*/
#define NIWLANG_HEADROOM									0x28	/*float64*/
#define NIWLANG_FULLSCALE_BACKOFF                           0xA8    /*float64*/
#define NIWLANG_AVERAGE_POWER_REFERENCE                     0xAA    /*int32*/
#define NIWLANG_MAXIMUM_HARDWARE_IQ_RATE					0x66	/*float64*/
#define NIWLANG_IQ_RATE										0x23    /*float64,readonly*/
#define NIWLANG_ACTUAL_HEADROOM								0x58    /*float64,readonly*/
#define NIWLANG_RF_BLANKING_ENABLED							0x5A    /*int32*/
#define NIWLANG_LO_SHARING_ENABLED							0x76    /*int32*/
#define NIWLANG_HYBRID_LO_SHARING_MODE				        0xDF    /*int32*/
#define NIWLANG_LO_SPLITTER_LOSS                            0XE1    /*1D Array of float64*/
#define NIWLANG_LO_SPLITTER_LOSS_FREQUENCY                  0XE2    /*1D Array of float64*/
#define NIWLANG_LO_FREQUENCY_OFFSET_MODE                    0xB0    /*int32*/
#define NIWLANG_LO_FREQUENCY_OFFSET                         0xB1    /*float64*/
#define NIWLANG_MULTI_CHASSIS_TCLK_SYNCHRONIZATION_MODE     0xE0    /*int32*/
#define NIWLANG_MULTI_SEGMENT_GENERATION_MODE               0x86    /*int32*/
#define NIWLANG_SPATIAL_MAPPING_MODE                        0xB9    /*int32*/
#define NIWLANG_RF_BLANKING_MARKER_POSITIONS				0x5B    /*1D Array of int32*/
#define NIWLANG_BURST_START_LOCATIONS                       0xAE    /*1D Array of int32*/
#define NIWLANG_BURST_STOP_LOCATIONS                        0xAF    /*1D Array of int32*/
#define NIWLANG_SIGNAL_BANDWIDTH                            0xC2    /*float64,readonly*/
#define NIWLANG_RUN_TIME_SCALING                            0xC9    /*float64*/
/*-Data Rate and Frame Format-------------------------------------*/
#define NIWLANG_ACTUAL_OFDM_DATA_RATE						0x59    /*float64,readonly*/
#define NIWLANG_NOT_SOUNDING_BIT							0x56    /*int32*/

/* 802.11ac Attributes*/
#define NIWLANG_NUMBER_OF_SEGMENTS							0x4B	/*int32*/
#define NIWLANG_NUMBER_OF_SPACE_TIME_STREAMS				0x4C	/*int32*/
#define NIWLANG_SPACE_TIME_STREAM_OFFSET                    0xBB    /*int32*/
#define NIWLANG_NUMBER_OF_LTF_SYMBOLS                       0xA5    /*int32*/
#define NIWLANG_MU_MIMO_LTF_MODE_ENABLED                    0xBA    /*int32*/
#define NIWLANG_STBC_ALL_STREAMS_ENABLED					0x4D	/*int32*/
/*-Advanced-------------------------------------------------------*/
#define NIWLANG_SWAP_I_AND_Q_ENABLED						0x4E	/*int32*/
#define NIWLANG_SAMPLE_CLOCK_RATE_FACTOR					0x6B	/*float64*/
/*-Data Rate and Frame Format-------------------------------------*/
#define NIWLANG_GUARD_INTERVAL_TYPE							0x7B	/*int32*/
#define NIWLANG_LTF_SIZE                                    0x90	/*int32*/
#define NIWLANG_MIDAMBLE_PERIODICITY                        0xCC    /*int32*/
#define NIWLANG_L_SIG_LENGTH                                0xB4    /*int32*/
#define NIWLANG_PRE_FEC_PADDING_FACTOR                      0xB5    /*int32*/
#define NIWLANG_PE_DISAMBIGUITY                             0xB6    /*int32*/
#define NIWLANG_LDPC_EXTRA_SYMBOL_SEGMENT                   0xB7    /*int32*/
#define NIWLANG_NOMINAL_PACKET_PADDING                      0xC3    /*int32*/
#define NIWLANG_PACKET_EXTENSION_DURATION                   0x9F    /*float64, readonly*/
#define NIWLANG_SIG_MCS_INDEX                               0xD4    /*int32*/
#define NIWLANG_HE_SIG_B_COMPRESSION_MODE                   0xE8	/*int32*/
#define NIWLANG_INTERFERENCE_MITIGATION_PILOTS_ENABLED      0xE9	/*int32*/
#define NIWLANG_SIG_COMPRESSION_ENABLED                     0xD5    /*int32*/
#define NIWLANG_PHASE_ROTATION_COEFFICIENT_1                0xD6    /*int32*/
#define NIWLANG_PHASE_ROTATION_COEFFICIENT_2                0xD7    /*int32*/
#define NIWLANG_PHASE_ROTATION_COEFFICIENT_3                0xD8    /*int32*/
#define NIWLANG_CYCLIC_TIME_SHIFT                           0xD9    /*float64*/

/*-Obsolete--------------------------------------------------------*/
#define NIWLANG_WINDOW_LENGTH								0x1D	/*float64*/
#define NIWLANG_OFDM_LEGACY_SCALING_ENABLED					0x65	/*int32*/
#define NIWLANG_POWER_LEVEL									0x1		/*float64*/
#define NIWLANG_WAVEFORM_SCALING_FACTOR						0x24	/*float64*/
#define NIWLANG_PEAK_TO_AVERAGE_POWER_RATIO					0x1E	/*float64, readonly*/
#define NIWLANG_MAPPING_MATRIX								0x2D	/*int32, readonly*/
#define NIWLANG_GUARD_INTERVAL								0x2C	/*float64*/
#define NIWLANG_80211AH_UPLINK_INDICATION					0x7C	/*int32*/
#define NIWLANG_MAX_EXPECTED_PAPR							0x28	/*float64*/
#define NIWLANG_PAYLOAD_AUTO_DATA_LENGTH                    0xB3    /*int32*/

/****************************************************************************
*------------------------ Attribute Value Defines -------------------------*
****************************************************************************/

/*- Values for WLAN Generation Toolkit Version -*/
#define NIWLANG_VAL_COMPATIBILITY_VERSION_010000			           10000
#define NIWLANG_VAL_COMPATIBILITY_VERSION_020000			           20000
#define NIWLANG_VAL_COMPATIBILITY_VERSION_030000			           30000
#define NIWLANG_VAL_COMPATIBILITY_VERSION_040000			           40000
#define NIWLANG_VAL_COMPATIBILITY_VERSION_050000                       50000
#define NIWLANG_VAL_COMPATIBILITY_VERSION_060000                       60000  
                                                                       
/*- Values For WLAN Standards -*/                                      
#define NIWLANG_VAL_STANDARD_80211AG_OFDM					           0
#define NIWLANG_VAL_STANDARD_80211J_OFDM                               7
#define NIWLANG_VAL_STANDARD_80211P_OFDM                               8
#define NIWLANG_VAL_STANDARD_80211BG_DSSS					           1
#define NIWLANG_VAL_STANDARD_80211G_DSSS_OFDM				           2
#define NIWLANG_VAL_STANDARD_80211N_MIMO_OFDM				           3
#define NIWLANG_VAL_STANDARD_80211AC_MIMO_OFDM				           4
#define NIWLANG_VAL_STANDARD_80211AH_MIMO_OFDM				           5
#define NIWLANG_VAL_STANDARD_80211AF_MIMO_OFDM                         6
#define NIWLANG_VAL_STANDARD_80211AX_MIMO_OFDM                         9
#define NIWLANG_VAL_STANDARD_80211BE_MIMO_OFDM                         10
#define NIWLANG_VAL_STANDARD_80211BN_MIMO_OFDM                         11
                                                                                                                                       
/*- Values For Preamble Format attribute -*/                           
#define NIWLANG_VAL_PREAMBLE_TYPE_SHORT_PREAMBLE			           0
#define NIWLANG_VAL_PREAMBLE_TYPE_LONG_PREAMBLE				           1

/*- Values For Average Power Reference attribute -*/
#define NIWLANG_VAL_AVERAGE_POWER_REFERENCE_NON_BOOSTED_FIELDS         0
#define NIWLANG_VAL_AVERAGE_POWER_REFERENCE_POWER_BOOSTED_FIELDS       1
#define NIWLANG_VAL_AVERAGE_POWER_REFERENCE_ENTIRE_PACKET              2    

/*- Values For Payload Data Type attribute -*/
#define NIWLANG_VAL_USER_DEFINED							           0
#define NIWLANG_VAL_PN_SEQUENCE								           1
                                                                       
/*- Values For Pulse Shaping Filter attribute -*/                      
#define NIWLANG_VAL_FILTER_RECTANGULAR						           0
#define NIWLANG_VAL_FILTER_RAISED_COSINE					           1	
#define NIWLANG_VAL_FILTER_ROOT_RAISED_COSINE				           2
#define NIWLANG_VAL_FILTER_GAUSSIAN							           3
                                                                       
/*- Values For Windowing Method -*/                                    
#define NIWLANG_VAL_WIN_METHOD_CENTERED_AT_SYMBOL_BOUNDARY	           0
#define NIWLANG_VAL_WIN_METHOD_STARTING_AT_SYMBOL_BOUNDARY	           1	
                                                                       
/*- Values For OFDM Data Rate attribute -*/                            
#define NIWLANG_VAL_OFDM_DATA_RATE_6						           0
#define NIWLANG_VAL_OFDM_DATA_RATE_9						           1
#define NIWLANG_VAL_OFDM_DATA_RATE_12						           2
#define NIWLANG_VAL_OFDM_DATA_RATE_18						           3
#define NIWLANG_VAL_OFDM_DATA_RATE_24						           4
#define NIWLANG_VAL_OFDM_DATA_RATE_36						           5
#define NIWLANG_VAL_OFDM_DATA_RATE_48						           6
#define NIWLANG_VAL_OFDM_DATA_RATE_54						           7

/*- Values For RU Size -*/                            
#define NIWLANG_VAL_RU_SIZE_26                                         26
#define NIWLANG_VAL_RU_SIZE_52                                         52
#define NIWLANG_VAL_RU_SIZE_106                                        106
#define NIWLANG_VAL_RU_SIZE_242                                        242
#define NIWLANG_VAL_RU_SIZE_484                                        484
#define NIWLANG_VAL_RU_SIZE_996                                        996
#define NIWLANG_VAL_RU_SIZE_2x996                                      1992
#define NIWLANG_VAL_RU_SIZE_4x996                                      3984
#define NIWLANG_VAL_RU_SIZE_52_PLUS_26                                 78
#define NIWLANG_VAL_RU_SIZE_106_PLUS_26                                132
#define NIWLANG_VAL_RU_SIZE_484_PLUS_242                               726
#define NIWLANG_VAL_RU_SIZE_996_PLUS_484                               1480
#define NIWLANG_VAL_RU_SIZE_996_PLUS_484_PLUS_242                      1722
#define NIWLANG_VAL_RU_SIZE_2x996_PLUS_484                             2476
#define NIWLANG_VAL_RU_SIZE_3x996                                      2988
#define NIWLANG_VAL_RU_SIZE_3x996_PLUS_484                             3472

/*- Values For DSSS Data Rate attribute -*/                            
#define NIWLANG_VAL_DSSS_DATA_RATE_1						           0
#define NIWLANG_VAL_DSSS_DATA_RATE_2						           1
#define NIWLANG_VAL_DSSS_DATA_RATE_5p5_CCK					           2
#define NIWLANG_VAL_DSSS_DATA_RATE_5p5_PBCC					           3
#define NIWLANG_VAL_DSSS_DATA_RATE_11_CCK					           4
#define NIWLANG_VAL_DSSS_DATA_RATE_11_PBCC					           5
#define NIWLANG_VAL_DSSS_DATA_RATE_22						           6
#define NIWLANG_VAL_DSSS_DATA_RATE_33						           7

/*- Data Rate and Frame Format:Transmission Mode -*/                            
#define NIWLANG_VAL_TRANSMISSION_MODE_DOWNLINK 			               0  
#define NIWLANG_VAL_TRANSMISSION_MODE_UPLINK             	           1
                                                                       
/*- Values for 80211n PLCP frame Format -*/                            
#define NIWLANG_VAL_80211N_PLCP_FRAME_FORMAT_MIXED			           0  
#define NIWLANG_VAL_80211N_PLCP_FRAME_FORMAT_GREENFIELD 	           1
                                                                       
/*- Values for Multi-segment Generation Mode -*/                       
#define NIWLANG_VAL_SINGLE_GENERATOR                                   0
#define NIWLANG_VAL_MULTIPLE_GENERATORS                                1
                                                                       
/*- Values for 80211n Mapping Matrix Type -*/                          
#define NIWLANG_VAL_MAPPING_MATRIX_TYPE_DIRECT                         0
#define NIWLANG_VAL_MAPPING_MATRIX_TYPE_HADAMARD                       1
#define NIWLANG_VAL_MAPPING_MATRIX_TYPE_FOURIER                        2
#define NIWLANG_VAL_MAPPING_MATRIX_TYPE_USER_DEFINED                   3
                                                                       
/* Values for TVHT Mode -*/                                            
#define NIWLANG_VAL_TVHT_MODE_1                                        0
#define NIWLANG_VAL_TVHT_MODE_2C                                       1
#define NIWLANG_VAL_TVHT_MODE_2N                                       2
#define NIWLANG_VAL_TVHT_MODE_4C                                       3
#define NIWLANG_VAL_TVHT_MODE_4N                                       4

/* Values for RU Allocation Mode -*/                                            
#define NIWLANG_VAL_RU_ALLOCATION_MODE_INDIVIDUAL                      0
#define NIWLANG_VAL_RU_ALLOCATION_MODE_GROUP                           1

                                                                       
/*- Values for binary attributes */                                    
#define NIWLANG_VAL_FALSE									           0
#define NIWLANG_VAL_TRUE									           1

/*- Values for FEC Coding Type attributes */
#define NIWLANG_VAL_FEC_CODING_TYPE_BCC						           0
#define NIWLANG_VAL_FEC_CODING_TYPE_LDPC					           1
                                                                       
/*- Values for PPDU Type */                                            
#define NIWLANG_VAL_PPDU_TYPE_SU_PPDU						           0
#define NIWLANG_VAL_PPDU_TYPE_MU_PPDU						           1
#define NIWLANG_VAL_PPDU_TYPE_EXTENDED_RANGE_SU_PPDU                   2
#define NIWLANG_VAL_PPDU_TYPE_TRIGGER_BASED_PPDU                       3
#define NIWLANG_VAL_PPDU_TYPE_ELR_PPDU                				   4

/*- Values for Non-HT Modulation Mode */
#define NIWLANG_VAL_NON_HT_MODULATION_MODE_OFF                         0
#define NIWLANG_VAL_NON_HT_MODULATION_MODE_ON                          1

/*- File IO Open Flags */
#define NIWLANG_VAL_FILE_OPERATION_MODE_OPEN				           0
#define NIWLANG_VAL_FILE_OPERATION_MODE_OPEN_OR_CREATE		           1
#define NIWLANG_VAL_FILE_OPERATION_MODE_CREATE_OR_REPLACE	           2
#define NIWLANG_VAL_FILE_OPERATION_MODE_CREATE				           3
                                                                       
/*- Frequency Band for Channel Number to Carrier Frequency  */
#define NIWLANG_VAL_FREQUENCY_BAND_2p4GHZ				               0
#define NIWLANG_VAL_FREQUENCY_BAND_5GHZ					               1

/* LO Source */
#define NIWLANG_VAL_LO_SOURCE_EXTERNAL                                 0
#define NIWLANG_VAL_LO_SOURCE_ONBOARD                                  2
#define NIWLANG_VAL_LO_SOURCE_SG_SA_Shared                             3
                                                                       
#define NIWLANG_VAL_MAX_ERROR_MESSAGE_SIZE					           1024
                                                                       
                                                                       
/*-MAC Frame Format---*/                                               
#define	NIWLANG_VAL_MAC_FRAME_FORMAT_LONG					           0
#define NIWLANG_VAL_MAC_FRAME_FORMAT_SHORT					           1
                                                                       
/* 80211AH Preamble Type */                                            
#define NIWLANG_VAL_80211AH_PREAMBLE_TYPE_SHORT				           0
#define	NIWLANG_VAL_80211AH_PREAMBLE_TYPE_LONG				           1

/* Data Rate and Frame Format : Guard Interval Type */
#define NIWLANG_VAL_GUARD_INTERVAL_TYPE_ONE_BY_FOUR                    0
#define NIWLANG_VAL_GUARD_INTERVAL_TYPE_ONE_BY_EIGHT                   1
#define NIWLANG_VAL_GUARD_INTERVAL_TYPE_ONE_BY_SIXTEEN                 2

/* Data Rate and Frame Format:LTF Size */
#define NIWLANG_VAL_LTF_SIZE_AUTO                                     -1
#define NIWLANG_VAL_LTF_SIZE_4X                                        0
#define NIWLANG_VAL_LTF_SIZE_2X                                        1
#define NIWLANG_VAL_LTF_SIZE_1X                                        2

/* LO Frequency Offset Mode */
#define NIWLANG_VAL_LO_FREQUENCY_OFFSET_MODE_AUTO                      0
#define NIWLANG_VAL_LO_FREQUENCY_OFFSET_MODE_USER_DEFINED              1 
#define NIWLANG_VAL_LO_FREQUENCY_OFFSET_MODE_DISABLED                  2

/* Payload Frame Type */
#define NIWLANG_VAL_PAYLOAD_MAC_FRAME_TYPE_GENERAL_FRAME               0
#define NIWLANG_VAL_PAYLOAD_MAC_FRAME_TYPE_DATA_FRAME                  1
#define NIWLANG_VAL_PAYLOAD_MAC_FRAME_TYPE_TRIGGER_FRAME               2

/* Payload Trigger Frame Maximum Padding Duration */
#define NIWLANG_VAL_PADDING_DURATION_0US                               0
#define NIWLANG_VAL_PADDING_DURATION_8US                               1
#define NIWLANG_VAL_PADDING_DURATION_16US                              2

/* Spatial Mapping Mode */
#define NIWLANG_VAL_SPATIAL_MAPPING_MODE_COMMON                        0
#define NIWLANG_VAL_SPATIAL_MAPPING_MODE_USER_SPECIFIC                 1

/* Nominal Packet Padding */
#define NIWLANG_VAL_NOMINAL_PACKET_PADDING_AUTO                        -1
#define NIWLANG_VAL_NOMINAL_PACKET_PADDING_0US                          0
#define NIWLANG_VAL_NOMINAL_PACKET_PADDING_8US                          1
#define NIWLANG_VAL_NOMINAL_PACKET_PADDING_16US                         2
#define NIWLANG_VAL_NOMINAL_PACKET_PADDING_20US                         3

/* Idle Interval Mode */
#define NIWLANG_VAL_IDLE_INTERVAL_MODE_SPLIT                            0
#define NIWLANG_VAL_IDLE_INTERVAL_MODE_POST_BURST                       1

/* Midamble Periodicity */
#define NIWLANG_VAL_MIDAMBLE_PERIODICITY_NONE                           0
#define NIWLANG_VAL_MIDAMBLE_PERIODICITY_TEN_SYMBOLS                    1
#define NIWLANG_VAL_MIDAMBLE_PERIODICITY_TWENTY_SYMBOLS                 2

/* Auto Payload Data Length Mode */
#define NIWLANG_VAL_AUTO_PAYLOAD_DATA_LENGTH_MODE_DISABLED				0
#define NIWLANG_VAL_AUTO_PAYLOAD_DATA_LENGTH_MODE_L_SIG_LENGTH			1
#define NIWLANG_VAL_AUTO_PAYLOAD_DATA_LENGTH_MODE_FRAME_DURATION		2

/* Obsolete */
#define NIWLANG_VAL_STANDARD_80211AGJP_OFDM								0

/* Data Rate and Frame Format : Guard Interval Type */
#define NIWLANG_VAL_GUARD_INTERVAL_TYPE_LONG							0
#define NIWLANG_VAL_GUARD_INTERVAL_TYPE_SHORT							1

/* Data Rate and Frame Format: HE-SIG-B Compression Mode */
#define NIWLANG_VAL_HE_SIG_B_COMPRESSION_MODE_AUTO					    0
#define NIWLANG_VAL_HE_SIG_B_COMPRESSION_MODE_MANUAL					1

/* Data Rate and Frame Format: SIG Compression Enabled */
#define NIWLANG_VAL_SIG_COMPRESSION_ENABLED_FALSE					    0
#define NIWLANG_VAL_SIG_COMPRESSION_ENABLED_TRUE					    1

/* Data Rate and Frame Format: Phase Rotation: Coefficient 1 */
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_1_PLUS_ONE				0
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_1_MINUS_ONE				1

/* Data Rate and Frame Format: Phase Rotation: Coefficient 2 */
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_2_PLUS_ONE				0
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_2_MINUS_ONE				1

/* Data Rate and Frame Format: Phase Rotation: Coefficient 3 */
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_3_PLUS_ONE				0
#define NIWLANG_VAL_PHASE_ROTATION_COEFFICIENT_3_MINUS_ONE				1

/* Waveform File Version */
#define NIWLANG_VAL_WAVEFORM_FILE_VERSION_1_0                     		0
#define NIWLANG_VAL_WAVEFORM_FILE_VERSION_2_0                     		1

/* Hardware Settings: Hybrid LO Sharing Mode */
#define NIWLANG_VAL_HYBRID_LO_SHARING_MODE_DISABLED                   	0
#define NIWLANG_VAL_HYBRID_LO_SHARING_MODE_MODE_0                     	1

/* Hardware Settings: Multi-chassis TClk Synchronization Mode */
#define NIWLANG_VAL_MULTI_CHASSIS_TCLK_SYNCHRONIZATION_MODE_AUTO           0
#define NIWLANG_VAL_MULTI_CHASSIS_TCLK_SYNCHRONIZATION_MODE_TIMING_MODULE  1

/* Data Rate and Frame Format: RU Allocation Settings */
#define NIWLANG_VAL_RU_TYPE_RRU				                            0
#define NIWLANG_VAL_RU_TYPE_DRU				                            1

/* Channelization */
#define NIWLANG_VAL_CHANNEL_320MHZ_1			                        0
#define NIWLANG_VAL_CHANNEL_320MHZ_2			                        1

/* Data Rate and Frame Format: Interference Mitigation Pilots Enabled*/
#define NIWLANG_VAL_INTERFERENCE_MITIGATION_PILOTS_ENABLED_FALSE	    0
#define NIWLANG_VAL_INTERFERENCE_MITIGATION_PILOTS_ENABLED_TRUE			1

/**************************************************************************** 
*---------------- WLAN Generator struct definititions  --------------------* 
****************************************************************************/

#if !defined(_NIComplexNumber)
#define _NIComplexNumber

#pragma pack(push, 8)
typedef struct NIComplexNumber_struct {
   float64 real;
   float64 imaginary;
} NIComplexNumber;
#pragma pack(pop)

#endif

#include "niWLANGeneration_Deprecated.h"
/****************************************************************************
*---------------- WLAN Generator Function Declarations ---------------------*
****************************************************************************/

/*- Open and Close Session Functions ---------------------------------------*/
int32 __stdcall  niWLANG_OpenSession(
	char sessionName[],
	int32 compatibilityVersion,
	niWLANGenerationSession *session,
	int32 *isNewSession);

/*- Set and Get Attribute Functions ----------------------------------------*/
int32 __stdcall niWLANG_GetToolkitCompatibilityVersion(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetStandard(
	niWLANGenerationSession session,
	char channelString[],
	int32 standard);

int32 __stdcall niWLANG_GetStandard(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetCarrierFrequency( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);
	
int32 __stdcall niWLANG_GetCarrierFrequency(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetOverSamplingRatio( 
	niWLANGenerationSession session,
	char channelString[],
	float64 overSamplingRatio);

int32 __stdcall niWLANG_GetOverSamplingRatio( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetOFDMDataRate( 
	niWLANGenerationSession session,
	char channelString[],
	int32 ofdmDataRate);

int32 __stdcall niWLANG_GetOFDMDataRate( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall  niWLANG_SetNonHTModulationMode(
    niWLANGenerationSession session,
	char channelString[],
	int32 nonHTDuplicateModulationMode);
	
int32 __stdcall  niWLANG_GetNonHTModulationMode(
    niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetPPDUType(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 ofdmDataRate);
	
int32 __stdcall niWLANG_GetPPDUType(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);
	
int32 __stdcall niWLANG_SetRUSize(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetRUSize(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	

int32 __stdcall niWLANG_SetRUOffsetMRUIndex(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetRUOffsetMRUIndex(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);		
	
int32 __stdcall niWLANG_SetRUAllocationMode(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetRUAllocationMode(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);			
	
int32 __stdcall niWLANG_SetUserEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetUserEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	
	
int32 __stdcall niWLANG_SetRUAllocation( 
	niWLANGenerationSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);

int32 __stdcall niWLANG_GetRUAllocation( 
	niWLANGenerationSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);	
	
int32 __stdcall niWLANG_SetRelativePower( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);
	
int32 __stdcall niWLANG_GetRelativePower(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	

int32 __stdcall niWLANG_SetPowerBoostFactor( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);
	
int32 __stdcall niWLANG_GetPowerBoostFactor(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niWLANG_SetDSSSDataRate( 
	niWLANGenerationSession session,
	char channelString[],
	int32 dsssDataRate);

int32 __stdcall niWLANG_GetDSSSDataRate( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetIdleInterval( 
	niWLANGenerationSession session,
	char channelString[],
	float64 idleInterval);

int32 __stdcall niWLANG_GetIdleInterval( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetIdleIntervalMode( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetIdleIntervalMode( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetNumberOfFrames( 
	niWLANGenerationSession session,
	char channelString[],
	int32 numberOfFrames);

int32 __stdcall niWLANG_GetNumberOfFrames( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetFrameDuration( 
	niWLANGenerationSession session,
	char channelString[],
	float64 frameDuration);

int32 __stdcall niWLANG_GetFrameDuration( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetUnframedDataModulationEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetUnframedDataModulationEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);

int32 __stdcall niWLANG_SetDSSSPreambleType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetDSSSPreambleType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *preambleFormat);

int32 __stdcall niWLANG_SetNumberOfMPDUs(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNumberOfMPDUs(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetAutoNumberOfMPDUs(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAutoNumberOfMPDUs(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACFrameType(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACFrameType(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
	
int32 __stdcall niWLANG_SetAutoPayloadDataLengthMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAutoPayloadDataLengthMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
	
int32 __stdcall niWLANG_SetPayloadDataLength( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadDataLength( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadDataType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadDataType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadPNOrder( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadPNOrder( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadPNSeed( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadPNSeed( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadUserDefinedBits( 
	niWLANGenerationSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize);

int32 __stdcall niWLANG_GetPayloadUserDefinedBits( 
	niWLANGenerationSession session,
	char channelString[],
	int32 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);

int32 __stdcall niWLANG_SetMACFrameFormat( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACFrameFormat( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACHeaderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACHeaderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetAMPDUEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAMPDUEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetSubcarrierMask( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize);

int32 __stdcall niWLANG_GetSubcarrierMask( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);

int32 __stdcall niWLANG_SetLockedClockBitEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetLockedClockBitEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetHeaderEncoderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetHeaderEncoderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetHeaderInterleaverEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetHeaderInterleaverEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadScramblerEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadScramblerEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadScramblerSeed( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadScramblerSeed( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadEncoderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadEncoderEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetFECCodingType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetFECCodingType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPayloadInterleaverEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPayloadInterleaverEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetCarrierFrequencyOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetCarrierFrequencyOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetIQGainImbalance( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetIQGainImbalance( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetIDCOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetIDCOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetQDCOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetQDCOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetQuadratureSkew( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetQuadratureSkew( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetTimingSkew( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetTimingSkew( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	

int32 __stdcall niWLANG_SetSampleClockOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetSampleClockOffset( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetPulseShapingFilterEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPulseShapingFilterEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPulseShapingFilterType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetPulseShapingFilterType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetPulseShapingFilterParameter( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetPulseShapingFilterParameter( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetDSSSWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetDSSSWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetOFDMWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetWindowingMethod(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetWindowingMethod(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_SetPulseShapingFilterLength(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);	

int32 __stdcall niWLANG_GetPulseShapingFilterLength(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	

int32 __stdcall niWLANG_GetIQWaveformSize( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetSwapIAndQEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetSwapIAndQEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	

int32 __stdcall niWLANG_SetNumberOfTransmitChannels( 
	niWLANGenerationSession session,
	char channelString[],
	int32 numberOfTransmitChannels);

int32 __stdcall niWLANG_GetNumberOfTransmitChannels( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetNumberOfSegments( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNumberOfSegments( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetNumberOfSpaceTimeStreams( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNumberOfSpaceTimeStreams( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetSpaceTimeStreamOffset( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetSpaceTimeStreamOffset( 
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

int32 __stdcall niWLANG_SetMUMIMOLTFModeEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMUMIMOLTFModeEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
	
int32 __stdcall niWLANG_SetSTBCAllStreamsEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);	

int32 __stdcall niWLANG_GetSTBCAllStreamsEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_SetMCSIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 MCSIndex);

int32 __stdcall niWLANG_GetMCSIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetSTAID( 
	niWLANGenerationSession session,
	char channelString[],
	int32 STAID);

int32 __stdcall niWLANG_GetSTAID( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetHESIGBMCSIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 HESIGBMCSIndex);

int32 __stdcall niWLANG_GetHESIGBMCSIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_SetHESIGBDualCarrierModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 HESIGBMCSIndex);

int32 __stdcall niWLANG_GetHESIGBDualCarrierModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetDualCarrierModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 DCMEanbled);

int32 __stdcall niWLANG_GetDualCarrierModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetBSSColor( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetBSSColor( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
	
int32 __stdcall niWLANG_SetChannelBandwidth( 
	niWLANGenerationSession session,
	char channelString[],
	float64 channelBandwidth);

int32 __stdcall niWLANG_GetChannelBandwidth( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_Set80211nPLCPFrameFormat( 
	niWLANGenerationSession session,
	char channelString[],
	int32 frameFormat);

int32 __stdcall niWLANG_Get80211nPLCPFrameFormat( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_Set80211ahPreambleType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 frameFormat);

int32 __stdcall niWLANG_Get80211ahPreambleType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetTransmissionMode( 
	niWLANGenerationSession session,
	char channelString[],
	int32 transmissionMode);

int32 __stdcall niWLANG_GetTransmissionMode( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetPreamblePuncturingEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 transmissionMode);

int32 __stdcall niWLANG_GetPreamblePuncturingEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetPrimary20MHzChannelIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 transmissionMode);

int32 __stdcall niWLANG_GetPrimary20MHzChannelIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		

int32 __stdcall niWLANG_SetPreamblePuncturingMask( 
	niWLANGenerationSession session,
	char channelString[],
	int32 transmissionMode);

int32 __stdcall niWLANG_GetPreamblePuncturingMask( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);			
	
int32 __stdcall niWLANG_Set80211ahUplinkIndication( 
	niWLANGenerationSession session,
	char channelString[],
	int32 frameFormat);

int32 __stdcall niWLANG_Get80211ahUplinkIndication( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetNumberOfExtensionSpatialStreams( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNumberOfExtensionSpatialStreams( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetNumberOfUsers(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
int32 __stdcall niWLANG_GetNumberOfUsers(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	
	
int32 __stdcall niWLANG_SetMappingMatrixType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 mappingMatrixType);

int32 __stdcall niWLANG_GetMappingMatrixType( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetMultiSegmentGenerationMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niWLANG_GetMultiSegmentGenerationMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
   
int32 __stdcall niWLANG_SetSpatialMappingMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niWLANG_GetSpatialMappingMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);   
   
int32 __stdcall niWLANG_SetSTBCIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 STBCIndex);

int32 __stdcall niWLANG_GetSTBCIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMappingMatrix( 
	niWLANGenerationSession session,
	char channelString[],
	NIComplexNumber* mappingMatrix,
	int32 numMappingMatrixRows,
	int32 numMappingMatrixColumns);

int32 __stdcall niWLANG_GetMappingMatrix( 
	niWLANGenerationSession session,
	char channelString[],
	NIComplexNumber* mappingMatrix,
	int32 numMappingMatrixRows,
	int32 numMappingMatrixColumns);

int32 __stdcall  niWLANG_SetScalarAttributeF64(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	float64 attributeValue);

int32 __stdcall  niWLANG_SetScalarAttributeI32(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	int32 attributeValue);

int32 __stdcall niWLANG_SetVectorAttributeF64(
	niWLANGenerationSession session,
	char channelString[], 
	niWLANG_Attr attributeID,
	float64 data[],
	int32 dataArraySize);

int32 __stdcall niWLANG_SetVectorAttributeI32(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	int32 data[],
	int32 dataArraySize);

int32 __stdcall  niWLANG_GetScalarAttributeF64(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	float64* attributeValue);

int32 __stdcall  niWLANG_GetScalarAttributeI32(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID, 
	int32* attributeValue);

int32 __stdcall niWLANG_GetVectorAttributeF64(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	float64 data[],
	int32 dataArraySize,
	int32* actualNumDataArrayElements);

int32 __stdcall niWLANG_GetVectorAttributeI32(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,	
	int32 data[],
	int32 dataArraySize, 
	int32* actualNumDataArrayElements);	

int32 __stdcall  niWLANG_SetScalarAttributeI64(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID,
	int64 attributeValue);

int32 __stdcall  niWLANG_GetScalarAttributeI64(
	niWLANGenerationSession session,
	char channelString[],
	niWLANG_Attr attributeID, 
	int64* attributeValue);

int32 __stdcall niWLANG_SetSampleClockRateFactor(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 value);

int32 __stdcall niWLANG_GetSampleClockRateFactor(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 *value);

int32 __stdcall niWLANG_SetPhaseRotationCoefficient1(
	niWLANGenerationSession session,
	char channelString[],
	int32 phaseRotationCoefficient1);

int32 __stdcall niWLANG_GetPhaseRotationCoefficient1(
	niWLANGenerationSession session,
	char channelString[],
	int32 *phaseRotationCoefficient1);

int32 __stdcall niWLANG_SetPhaseRotationCoefficient2(
	niWLANGenerationSession session,
	char channelString[],
	int32 phaseRotationCoefficient2);

int32 __stdcall niWLANG_GetPhaseRotationCoefficient2(
	niWLANGenerationSession session,
	char channelString[],
	int32 *phaseRotationCoefficient2);

int32 __stdcall niWLANG_SetPhaseRotationCoefficient3(
	niWLANGenerationSession session,
	char channelString[],
	int32 phaseRotationCoefficient3);

int32 __stdcall niWLANG_GetPhaseRotationCoefficient3(
	niWLANGenerationSession session,
	char channelString[],
	int32 *phaseRotationCoefficient3);

int32 __stdcall niWLANG_SetCyclicTimeShift(
	niWLANGenerationSession session,
	char channelString[],
	float64 CyclicTimeShift);
	
int32 __stdcall niWLANG_GetCyclicTimeShift(
	niWLANGenerationSession session,
	char channelString[],
	float64 *CyclicTimeShift);

int32 __stdcall niWLANG_SetHybridLOSharingMode(
   niWLANGenerationSession session, 
   char channelString[], 
   int32 value);  

int32 __stdcall niWLANG_GetHybridLOSharingMode(
   niWLANGenerationSession session, 
   char channelString[], 
   int32 *value);
   
int32 __stdcall niWLANG_SetMultiChassisTClkSynchronizationMode(
   niWLANGenerationSession session, 
   char channelString[], 
   int32 value);

int32 __stdcall niWLANG_GetMultiChassisTClkSynchronizationMode(
   niWLANGenerationSession session, 
   char channelString[], 
   int32 *value);

int32 __stdcall niWLANG_SetLOSplitterLoss( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize); 

int32 __stdcall niWLANG_GetLOSplitterLoss( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);	

int32 __stdcall niWLANG_SetLOSplitterLossFrequency( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize); 

int32 __stdcall niWLANG_GetLOSplitterLossFrequency( 
	niWLANGenerationSession session,
	char channelString[],
	float64 dataArray[],
	int32 dataArraySize,
	int32 *actualNumDataArrayElements);

int32 __stdcall niWLANG_SetRUType(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);
	
int32 __stdcall niWLANG_GetRUType(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);		
	
int32 __stdcall niWLANG_SetDistributionBandwidth( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetDistributionBandwidth( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_Set2xLDPCEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_Get2xLDPCEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetUnequalModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetUnequalModulationEnabled( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetUnequalModulationPatternIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetUnequalModulationPatternIndex( 
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_SetChannelization(
   niWLANGenerationSession session,
   char channelString[],
   int32 value);

int32 __stdcall niWLANG_GetChannelization(
   niWLANGenerationSession session,
   char channelString[],
   int32 *value);

/*- Create Waveform Function -----------------------------------------------*/
int32 __stdcall  niWLANG_CreateWaveformComplexF64(
	niWLANGenerationSession session,
	int32 reset,
	float64* t0,
	float64* dt,
	NIComplexNumber waveform[],
	int32 waveformSize,
	int32* actualNumWaveformSamples,
	int32* done);

int32 __stdcall  niWLANG_CreateMIMOWaveformsComplexF64(
	niWLANGenerationSession session,
	int32 reset,
	float64 t0[],
	float64 dt[],
	NIComplexNumber *waveforms,
	int32 numberOfTxChains,
	int32 individualWaveformSize,
	int32* actualNumSamplesInEachWfm,
	int32* done);

int32 __stdcall niWLANG_SetAutoHeadroomEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 enable);

int32 __stdcall niWLANG_GetAutoHeadroomEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetHeadroom(
	niWLANGenerationSession session,
	char channelString[],
	float64 headroom);

int32 __stdcall niWLANG_GetHeadroom(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetFullscaleBackoff(
	niWLANGenerationSession session,
	char channelString[],
	float64 fullscaleBackoff);

int32 __stdcall niWLANG_GetFullscaleBackoff(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niWLANG_SetAveragePowerReference(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetAveragePowerReference(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	
	
int32 __stdcall niWLANG_SetMaximumHardwareIQRate(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 hardwareIQRate);

int32 __stdcall niWLANG_GetMaximumHardwareIQRate(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 *value);	
	
int32 __stdcall niWLANG_SetRFBlankingEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetRFBlankingEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);

int32 __stdcall niWLANG_SetLOSharingEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetLOSharingEnabled(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);

int32 __stdcall niWLANG_SetLOFrequencyOffset(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 value);

int32 __stdcall niWLANG_GetLOFrequencyOffset(
	niWLANGenerationSession session, 
	char channelString[], 
	float64 *value);
	
int32 __stdcall niWLANG_SetLOFrequencyOffsetMode(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 value);

int32 __stdcall niWLANG_GetLOFrequencyOffsetMode(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 *value);	

int32 __stdcall niWLANG_GetRFBlankingMarkerPositions(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);	

int32 __stdcall niWLANG_GetBurstStartLocations(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);	

int32 __stdcall niWLANG_GetBurstStopLocations(
	niWLANGenerationSession session, 
	char channelString[], 
	int32 dataArray[], 
	int32 dataArraySize, 
	int32 *actualNumDataArrayElements);		
	
int32 __stdcall niWLANG_GetIQRate(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_GetSignalBandwidth(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	
	
int32 __stdcall niWLANG_GetActualHeadroom(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetMACFrameControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACFrameControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACDurationOrID(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACDurationOrID(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress1Length(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress1Length(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress1Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress1Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress2Length(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress2Length(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress2Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress2Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress3Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress3Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACSequenceControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACSequenceControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACSequenceControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMacSequenceControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACCurrentSequenceControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACCurrentSequenceControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACAddress4Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACAddress4Enabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACQOSControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACQOSControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACQOSControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACQOSControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACHTControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACHTControlEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACHTControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACHTControl(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACSequenceNumberIncrementEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACSequenceNumberIncrementEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACSequenceNumberIncrementInterval(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACSequenceNumberIncrementInterval(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACFragmentNumberIncrementEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACFragmentNumberIncrementEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_GetMPDULength(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_GetMACOverheadLength(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetMACFCSEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACFCSEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetAID12(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAID12(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
	
int32 __stdcall niWLANG_SetMACPaddingDuration(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetMACPaddingDuration(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	
	
int32 __stdcall niWLANG_SetCSRequired(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetCSRequired(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetAPTXPower(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAPTXPower(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
		
int32 __stdcall niWLANG_SetTargetRSSI(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetTargetRSSI(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
		
		
int32 __stdcall niWLANG_SetNumberOfDataSymbols(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);
int32 __stdcall niWLANG_GetNumberOfDataSymbols(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
	

int32 __stdcall niWLANG_GetActualOFDMDataRate(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetNotSoundingBit(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetNotSoundingBit(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetAllIQImpairmentsEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAllIQImpairmentsEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetAWGNEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAWGNEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetTimeDelay(
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetTimeDelay(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);	

int32 __stdcall niWLANG_SetCarrierToNoiseRatio(
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetCarrierToNoiseRatio(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);

int32 __stdcall niWLANG_SetMACAddress1(
	niWLANGenerationSession session,
	char channelString[],
	int64 value);

int32 __stdcall niWLANG_GetMACAddress1(
	niWLANGenerationSession session,
	char channelString[],
	int64 *value);

int32 __stdcall niWLANG_SetMACAddress2(
	niWLANGenerationSession session,
	char channelString[],
	int64 value);

int32 __stdcall niWLANG_GetMACAddress2(
	niWLANGenerationSession session,
	char channelString[],
	int64 *value);

int32 __stdcall niWLANG_SetMACAddress3(
	niWLANGenerationSession session,
	char channelString[],
	int64 value);

int32 __stdcall niWLANG_GetMACAddress3(
	niWLANGenerationSession session,
	char channelString[],
	int64 *value);

int32 __stdcall niWLANG_SetMACAddress4(
	niWLANGenerationSession session,
	char channelString[],
	int64 value);

int32 __stdcall niWLANG_GetMACAddress4(
	niWLANGenerationSession session,
	char channelString[],
	int64 *value);

	
int32 __stdcall niWLANG_SaveConfigurationToFile(
	niWLANGenerationSession session,
	char filePath[],
	int32 operation);

int32 __stdcall niWLANG_LoadConfigurationFromFile(
	niWLANGenerationSession session,
	char filePath[],
	int32 resetSession);

int32 __stdcall niWLANG_CreateAndWriteWaveformsToFile(
	niWLANGenerationSession session,
	char filePath[],
	int32 fileOperation);

int32 __stdcall niWLANG_SetOFDMGuardIntervalType(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMGuardIntervalType(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		

int32 __stdcall niWLANG_SetLTFSize(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetLTFSize(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetOFDMMidamblePeriodicity(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMMidamblePeriodicity(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_SetOFDMLSIGLength(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMLSIGLength(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetOFDMPreFECPaddingFactor(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMPreFECPaddingFactor(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetOFDMPEDisambiguity(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMPEDisambiguity(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
int32 __stdcall niWLANG_SetOFDMLDPCExtraSymbolsUsed(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMLDPCExtraSymbolsUsed(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);	

int32 __stdcall niWLANG_GetOFDMPacketExtensionDuration(
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetOFDMNominalPacketPadding(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMNominalPacketPadding(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);		
	
	
int32 __stdcall niWLANG_SetOFDMPacketExtensionThresholds(
	niWLANGenerationSession session,
	char channelString[],
	int32 PPET16[],
    int32 PPET8[],
    int32 numberOfSpaceTimeStreams[],
    int32 RUSize[],
    int32 PPET16ArraySize,
    int32 PPET8ArraySize,
    int32 numberOfSpaceTimeStreamsArraySize,
    int32 RUArraySize);
	

int32 __stdcall niWLANG_GetNumberOfUsersFromRUAllocation(
    niWLANGenerationSession session,
	char channelString[],
	int32* numberOfUsers);
	

int32 __stdcall niWLANG_CreateTriggerFrameMSDU(	
	niWLANGenerationSession session,
	char channelString[],
	int32 *generationDone,
	int32 triggerFrameMSDUBits[],
	int32 dataArraySize,
	int32 *actualDataArraySize);
	
int32 __stdcall niWLANG_ReadWaveformFromFile(
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
	
int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency80211abgjpn(
	float64 channelStartingFrequency, 
	float64 channelBandwidth, 
	int32 channelNumber, 
	int32 secondaryFactor, 
	float64 *carrierFrequency);

int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency80211ac(
	float64 channelStartingFrequency, 
	int32 channelNumber, 
	float64 *carrierFrequency);

int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency80211ah(
	float64 channelStartingFrequency, 
	int32 channelNumber, 
	float64 *carrierFrequency);

int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency80211af (
    float64	channelStartingFrequency,
	float64	channelBandwidth,
	int32 channelNumber,
    int32 TVHTMode,
	float64 *carrierFrequency);	

int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency80211ax(
	float64 channelStartingFrequency, 
	int32 channelNumber, 
	float64 *carrierFrequency);
	
/*- Utility Functions -----------------------------------------------------*/
int32 __stdcall niWLANG_GetErrorString(
	niWLANGenerationSession session,
	int32 errorCode,
	char errorMessage[],
	int32 errorMessageLen);

int32 __stdcall  niWLANG_ResetSession(
	niWLANGenerationSession session);

int32 __stdcall niWLANG_ReadBurstStartLocationsFromFile(
	char filePath[],
	char waveformName[],
	int32 burstStartLocations[],
	int32 dataArraySize,
	int32 *actualDataArraySize);
	
int32 __stdcall niWLANG_ReadBurstStopLocationsFromFile(
    char filePath[],
	char waveformName[],
	int32 burstStopLocations[],
	int32 dataArraySize,
	int32 *actualdataArraySize);		
	
/*--------------------------------------------------------------------------*/
int32 __stdcall  niWLANG_CloseSession(
	niWLANGenerationSession session);
	
int32 __stdcall niWLANG_DeallocateMemory(void);	


/*-Obsolete Functions --------------------------------------------------------*/
int32 __stdcall niWLANG_SetAutoDataLength(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetAutoDataLength(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);

int32 __stdcall niWLANG_GetWindowLength( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	
int32 __stdcall niWLANG_SetOFDMLegacyScalingEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetOFDMLegacyScalingEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
int32 __stdcall niWLANG_SetGuardInterval( 
	niWLANGenerationSession session,
	char channelString[],
	float64 guardInterval);

int32 __stdcall niWLANG_GetGuardInterval( 
	niWLANGenerationSession session,
	char channelString[],
	float64 *value);
	 
int32 __stdcall niWLANG_SetPowerLevel( 
	niWLANGenerationSession session,
	char channelString[],
	float64 value);
	
int32 __stdcall niWLANG_ChannelNumberToCarrierFrequency(
	int32 frequencyBand,
	float64 channelBandwidth,
	int32 channelNumber,
	int32 secondaryFactor, 
	float64 channelStartingFactor,
	float64 *carrierFrequency);

int32 __stdcall niWLANG_SetSIGMCSIndex(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetSIGMCSIndex(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetHESIGBCompressionMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);
	
int32 __stdcall niWLANG_GetHESIGBCompressionMode(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetSIGCompressionEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetSIGCompressionEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);
	
int32 __stdcall niWLANG_SetInterferenceMitigationPilotsEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 value);

int32 __stdcall niWLANG_GetInterferenceMitigationPilotsEnabled(
	niWLANGenerationSession session,
	char channelString[],
	int32 *value);

int32 __stdcall niWLANG_SetWaveformFileVersion(
   niWLANGenerationSession session,
   char channelString[],
   int32 value);

int32 __stdcall niWLANG_GetWaveformFileVersion(
   niWLANGenerationSession session,
   char channelString[],
   int32 *value);

int32 __stdcall niWLANG_SetRunTimeScaling(
   niWLANGenerationSession session,
   char channelString[],
   float64 value);

int32 __stdcall niWLANG_GetRunTimeScaling(
   niWLANGenerationSession session,
   char channelString[],
   float64 *value);
	   
#ifdef __cplusplus
}
#endif

#endif //__NIWLAN_TOOLKIT_GENERATION_HEADER_DEFINED__
