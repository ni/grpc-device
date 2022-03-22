enums = {
    'BlinkMode': {
        'values': [
            {
                'name': 'BLINK_DISABLE',
                'value': 0
            },
            {
                'name': 'BLINK_ENABLE',
                'value': 1
            }
        ]
    },
    'CopyMode': {
        'values': [
            {
                'name': 'DB_MERGE_COPY_USE_SOURCE',
                'value': 0
            },
            {
                'name': 'DB_MERGE_COPY_USE_TARGET',
                'value': 1
            },
            {
                'name': 'DB_MERGE_MERGE_USE_SOURCE',
                'value': 2
            },
            {
                'name': 'DB_MERGE_MERGE_USE_TARGET',
                'value': 3
            }
        ]
    },
    'CreateSessionMode': {
        'values': [
            {
                'name': 'MODE_SIGNAL_IN_SINGLE_POINT',
                'value': 0
            },
            {
                'name': 'MODE_SIGNAL_IN_WAVEFORM',
                'value': 1
            },
            {
                'name': 'MODE_SIGNAL_IN_XY',
                'value': 2
            },
            {
                'name': 'MODE_SIGNAL_OUT_SINGLE_POINT',
                'value': 3
            },
            {
                'name': 'MODE_SIGNAL_OUT_WAVEFORM',
                'value': 4
            },
            {
                'name': 'MODE_SIGNAL_OUT_XY',
                'value': 5
            },
            {
                'name': 'MODE_FRAME_IN_STREAM',
                'value': 6
            },
            {
                'name': 'MODE_FRAME_IN_QUEUED',
                'value': 7
            },
            {
                'name': 'MODE_FRAME_IN_SINGLE_POINT',
                'value': 8
            },
            {
                'name': 'MODE_FRAME_OUT_STREAM',
                'value': 9
            },
            {
                'name': 'MODE_FRAME_OUT_QUEUED',
                'value': 10
            },
            {
                'name': 'MODE_FRAME_OUT_SINGLE_POINT',
                'value': 11
            },
            {
                'name': 'MODE_SIGNAL_CONVERSION_SINGLE_POINT',
                'value': 12
            }
        ]
    },
    'DBProperty': {
        'generate-mapping-type': True,
        'values': [
            {
                'name': 'DATABASE_CLST_REFS',
                'type': 'db_ref_array',
                'value': 100663298
            },
            {
                'name': 'DATABASE_NAME',
                'type': 'string',
                'value': 50331649
            },
            {
                'name': 'DATABASE_SHOW_INVALID_FROM_OPEN',
                'type': 'boolean',
                'value': 33554435
            },
            {
                'name': 'CLST_BAUD_RATE_64',
                'type': 'u64',
                'value': 151060481
            },
            {
                'name': 'CLST_APPLICATION_PROTOCOL',
                'type': 'u32',
                'value': 65651
            },
            {
                'name': 'CLST_BAUD_RATE',
                'type': 'u32',
                'value': 65537
            },
            {
                'name': 'CLST_CAN_FD_BAUD_RATE_64',
                'type': 'u64',
                'value': 151060497
            },
            {
                'name': 'CLST_CAN_FD_BAUD_RATE',
                'type': 'u32',
                'value': 65553
            },
            {
                'name': 'CLST_CAN_FD_ISO_MODE',
                'type': 'u32',
                'value': 65652
            },
            {
                'name': 'CLST_CAN_IO_MODE',
                'type': 'u32',
                'value': 65552
            },
            {
                'name': 'CLST_COMMENT',
                'type': 'string',
                'value': 50397192
            },
            {
                'name': 'CLST_CONFIG_STATUS',
                'type': 'u32',
                'value': 65545
            },
            {
                'name': 'CLST_DATABASE_REF',
                'type': 'db_ref',
                'value': 83951618
            },
            {
                'name': 'CLST_ECU_REFS',
                'type': 'db_ref_array',
                'value': 100728835
            },
            {
                'name': 'CLST_FLEX_RAY_ACT_PT_OFF',
                'type': 'u32',
                'value': 65568
            },
            {
                'name': 'CLST_FLEX_RAY_ALW_PASS_ACT',
                'type': 'u32',
                'value': 65650
            },
            {
                'name': 'CLST_FLEX_RAY_CAS_RX_L_MAX',
                'type': 'u32',
                'value': 65569
            },
            {
                'name': 'CLST_FLEX_RAY_CHANNELS',
                'type': 'u32',
                'value': 65570
            },
            {
                'name': 'CLST_FLEX_RAY_CLST_DRIFT_DMP',
                'type': 'u32',
                'value': 65571
            },
            {
                'name': 'CLST_FLEX_RAY_COLD_ST_ATS',
                'type': 'u32',
                'value': 65572
            },
            {
                'name': 'CLST_FLEX_RAY_CYCLE',
                'type': 'u32',
                'value': 65573
            },
            {
                'name': 'CLST_FLEX_RAY_DYN_SEG_START',
                'type': 'u32',
                'value': 65574
            },
            {
                'name': 'CLST_FLEX_RAY_DYN_SLOT_IDL_PH',
                'type': 'u32',
                'value': 65575
            },
            {
                'name': 'CLST_FLEX_RAY_LATEST_GUAR_DYN',
                'type': 'u32',
                'value': 65579
            },
            {
                'name': 'CLST_FLEX_RAY_LATEST_USABLE_DYN',
                'type': 'u32',
                'value': 65578
            },
            {
                'name': 'CLST_FLEX_RAY_LIS_NOISE',
                'type': 'u32',
                'value': 65576
            },
            {
                'name': 'CLST_FLEX_RAY_MACRO_PER_CYCLE',
                'type': 'u32',
                'value': 65577
            },
            {
                'name': 'CLST_FLEX_RAY_MACROTICK',
                'type': 'f64',
                'value': 16842800
            },
            {
                'name': 'CLST_FLEX_RAY_MAX_WO_CLK_COR_FAT',
                'type': 'u32',
                'value': 65585
            },
            {
                'name': 'CLST_FLEX_RAY_MAX_WO_CLK_COR_PAS',
                'type': 'u32',
                'value': 65586
            },
            {
                'name': 'CLST_FLEX_RAY_MINISLOT',
                'type': 'u32',
                'value': 65588
            },
            {
                'name': 'CLST_FLEX_RAY_MINISLOT_ACT_PT',
                'type': 'u32',
                'value': 65587
            },
            {
                'name': 'CLST_FLEX_RAY_NIT',
                'type': 'u32',
                'value': 65590
            },
            {
                'name': 'CLST_FLEX_RAY_NIT_START',
                'type': 'u32',
                'value': 65591
            },
            {
                'name': 'CLST_FLEX_RAY_NM_VEC_LEN',
                'type': 'u32',
                'value': 65589
            },
            {
                'name': 'CLST_FLEX_RAY_NUM_MINISLT',
                'type': 'u32',
                'value': 65592
            },
            {
                'name': 'CLST_FLEX_RAY_NUM_STAT_SLT',
                'type': 'u32',
                'value': 65593
            },
            {
                'name': 'CLST_FLEX_RAY_OFF_COR_ST',
                'type': 'u32',
                'value': 65600
            },
            {
                'name': 'CLST_FLEX_RAY_PAYLD_LEN_DYN_MAX',
                'type': 'u32',
                'value': 65601
            },
            {
                'name': 'CLST_FLEX_RAY_PAYLD_LEN_MAX',
                'type': 'u32',
                'value': 65602
            },
            {
                'name': 'CLST_FLEX_RAY_PAYLD_LEN_ST',
                'type': 'u32',
                'value': 65603
            },
            {
                'name': 'CLST_FLEX_RAY_STAT_SLOT',
                'type': 'u32',
                'value': 65605
            },
            {
                'name': 'CLST_FLEX_RAY_SYM_WIN',
                'type': 'u32',
                'value': 65606
            },
            {
                'name': 'CLST_FLEX_RAY_SYM_WIN_START',
                'type': 'u32',
                'value': 65607
            },
            {
                'name': 'CLST_FLEX_RAY_SYNC_NODE_MAX',
                'type': 'u32',
                'value': 65608
            },
            {
                'name': 'CLST_FLEX_RAY_TSS_TX',
                'type': 'u32',
                'value': 65609
            },
            {
                'name': 'CLST_FLEX_RAY_USE_WAKEUP',
                'type': 'boolean',
                'value': 33620053
            },
            {
                'name': 'CLST_FLEX_RAY_WAKE_SYM_RX_IDL',
                'type': 'u32',
                'value': 65616
            },
            {
                'name': 'CLST_FLEX_RAY_WAKE_SYM_RX_LOW',
                'type': 'u32',
                'value': 65617
            },
            {
                'name': 'CLST_FLEX_RAY_WAKE_SYM_RX_WIN',
                'type': 'u32',
                'value': 65618
            },
            {
                'name': 'CLST_FLEX_RAY_WAKE_SYM_TX_IDL',
                'type': 'u32',
                'value': 65619
            },
            {
                'name': 'CLST_FLEX_RAY_WAKE_SYM_TX_LOW',
                'type': 'u32',
                'value': 65620
            },
            {
                'name': 'CLST_FRM_REFS',
                'type': 'db_ref_array',
                'value': 100728836
            },
            {
                'name': 'CLST_LIN_SCHEDULES',
                'type': 'db_ref_array',
                'value': 100728944
            },
            {
                'name': 'CLST_LIN_TICK',
                'type': 'f64',
                'value': 16842865
            },
            {
                'name': 'CLST_NAME',
                'type': 'string',
                'value': 50397189
            },
            {
                'name': 'CLST_PDU_REFS',
                'type': 'db_ref_array',
                'value': 100728840
            },
            {
                'name': 'CLST_PD_US_REQD',
                'type': 'boolean',
                'value': 33619978
            },
            {
                'name': 'CLST_PROTOCOL',
                'type': 'u32',
                'value': 65542
            },
            {
                'name': 'CLST_SIG_REFS',
                'type': 'db_ref_array',
                'value': 100728839
            },
            {
                'name': 'FRM_APPLICATION_PROTOCOL',
                'type': 'u32',
                'value': 131172
            },
            {
                'name': 'FRM_CAN_EXT_ID',
                'type': 'boolean',
                'value': 33685520
            },
            {
                'name': 'FRM_CA_NIO_MODE',
                'type': 'u32',
                'value': 131174
            },
            {
                'name': 'FRM_CAN_TIMING_TYPE',
                'type': 'u32',
                'value': 131089
            },
            {
                'name': 'FRM_CAN_TX_TIME',
                'type': 'f64',
                'value': 16908306
            },
            {
                'name': 'FRM_CLUSTER_REF',
                'type': 'db_ref',
                'value': 84017153
            },
            {
                'name': 'FRM_COMMENT',
                'type': 'string',
                'value': 50462722
            },
            {
                'name': 'FRM_CONFIG_STATUS',
                'type': 'u32',
                'value': 131081
            },
            {
                'name': 'FRM_DEFAULT_PAYLOAD',
                'type': 'u8_array',
                'value': 167903237
            },
            {
                'name': 'FRM_FLEX_RAY_BASE_CYCLE',
                'type': 'u32',
                'value': 131104
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN',
                'type': 'u32',
                'value': 131105
            },
            {
                'name': 'FRM_FLEX_RAY_CYCLE_REP',
                'type': 'u32',
                'value': 131106
            },
            {
                'name': 'FRM_FLEX_RAY_IN_CYC_REP_CH_ASSIGNS',
                'type': 'u32_array',
                'value': 134348850
            },
            {
                'name': 'FRM_FLEX_RAY_IN_CYC_REP_ENABLED',
                'type': 'boolean',
                'value': 33685552
            },
            {
                'name': 'FRM_FLEX_RAY_IN_CYC_REP_I_DS',
                'type': 'u32_array',
                'value': 134348849
            },
            {
                'name': 'FRM_FLEX_RAY_PREAMBLE',
                'type': 'boolean',
                'value': 33685539
            },
            {
                'name': 'FRM_FLEX_RAY_STARTUP',
                'type': 'boolean',
                'value': 33685540
            },
            {
                'name': 'FRM_FLEX_RAY_SYNC',
                'type': 'boolean',
                'value': 33685541
            },
            {
                'name': 'FRM_FLEX_RAY_TIMING_TYPE',
                'type': 'u32',
                'value': 131110
            },
            {
                'name': 'FRM_ID',
                'type': 'u32',
                'value': 131075
            },
            {
                'name': 'FRM_LIN_CHECKSUM',
                'type': 'u32',
                'value': 131152
            },
            {
                'name': 'FRM_MUX_DATA_MUX_SIG_REF',
                'type': 'db_ref',
                'value': 84017217
            },
            {
                'name': 'FRM_MUX_IS_MUXED',
                'type': 'boolean',
                'value': 33685568
            },
            {
                'name': 'FRM_MUX_STATIC_SIG_REFS',
                'type': 'db_ref_array',
                'value': 100794434
            },
            {
                'name': 'FRM_MUX_SUBFRAME_REFS',
                'type': 'db_ref_array',
                'value': 100794435
            },
            {
                'name': 'FRM_NAME',
                'type': 'string',
                'value': 50462724
            },
            {
                'name': 'FRM_PDU_START_BITS',
                'type': 'u32_array',
                'value': 134348897
            },
            {
                'name': 'FRM_PDU_UPDATE_BITS',
                'type': 'u32_array',
                'value': 134348899
            },
            {
                'name': 'FRM_PDU_REFS',
                'type': 'db_ref_array',
                'value': 100794464
            },
            {
                'name': 'FRM_PAYLOAD_LEN',
                'type': 'u32',
                'value': 131079
            },
            {
                'name': 'FRM_SIG_REFS',
                'type': 'db_ref_array',
                'value': 100794376
            },
            {
                'name': 'FRM_VARIABLE_PAYLOAD',
                'type': 'boolean',
                'value': 33685605
            },
            {
                'name': 'SIG_BYTE_ORDR',
                'type': 'u32',
                'value': 196609
            },
            {
                'name': 'SIG_COMMENT',
                'type': 'string',
                'value': 50528258
            },
            {
                'name': 'SIG_CONFIG_STATUS',
                'type': 'u32',
                'value': 196617
            },
            {
                'name': 'SIG_DATA_TYPE',
                'type': 'u32',
                'value': 196611
            },
            {
                'name': 'SIG_DEFAULT',
                'type': 'f64',
                'value': 16973828
            },
            {
                'name': 'SIG_FRAME_REF',
                'type': 'db_ref',
                'value': 84082693
            },
            {
                'name': 'SIG_MAX',
                'type': 'f64',
                'value': 16973830
            },
            {
                'name': 'SIG_MIN',
                'type': 'f64',
                'value': 16973831
            },
            {
                'name': 'SIG_MUX_IS_DATA_MUX',
                'type': 'boolean',
                'value': 33751088
            },
            {
                'name': 'SIG_MUX_IS_DYNAMIC',
                'type': 'boolean',
                'value': 33751089
            },
            {
                'name': 'SIG_MUX_VALUE',
                'type': 'u32',
                'value': 196658
            },
            {
                'name': 'SIG_MUX_SUBFRM_REF',
                'type': 'db_ref',
                'value': 84082739
            },
            {
                'name': 'SIG_NAME',
                'type': 'string',
                'value': 50528264
            },
            {
                'name': 'SIG_NAME_UNIQUE_TO_CLUSTER',
                'type': 'string',
                'value': 50528272
            },
            {
                'name': 'SIG_NUM_BITS',
                'type': 'u32',
                'value': 196626
            },
            {
                'name': 'SIG_PDU_REF',
                'type': 'db_ref',
                'value': 84082705
            },
            {
                'name': 'SIG_SCALE_FAC',
                'type': 'f64',
                'value': 16973843
            },
            {
                'name': 'SIG_SCALE_OFF',
                'type': 'f64',
                'value': 16973844
            },
            {
                'name': 'SIG_START_BIT',
                'type': 'u32',
                'value': 196629
            },
            {
                'name': 'SIG_UNIT',
                'type': 'string',
                'value': 50528278
            },
            {
                'name': 'SUBFRM_CONFIG_STATUS',
                'type': 'u32',
                'value': 262153
            },
            {
                'name': 'SUBFRM_DYN_SIG_REFS',
                'type': 'db_ref_array',
                'value': 100925441
            },
            {
                'name': 'SUBFRM_FRM_REF',
                'type': 'db_ref',
                'value': 84148226
            },
            {
                'name': 'SUBFRM_MUX_VALUE',
                'type': 'u32',
                'value': 262147
            },
            {
                'name': 'SUBFRM_NAME',
                'type': 'string',
                'value': 50593796
            },
            {
                'name': 'SUBFRM_NAME_UNIQUE_TO_CLUSTER',
                'type': 'string',
                'value': 50593799
            },
            {
                'name': 'SUBFRM_PDU_REF',
                'type': 'db_ref',
                'value': 84148229
            },
            {
                'name': 'ECU_CLST_REF',
                'type': 'db_ref',
                'value': 84213761
            },
            {
                'name': 'ECU_COMMENT',
                'type': 'string',
                'value': 50659333
            },
            {
                'name': 'ECU_CONFIG_STATUS',
                'type': 'u32',
                'value': 327689
            },
            {
                'name': 'ECU_FLEX_RAY_IS_COLDSTART',
                'type': 'boolean',
                'value': 33882128
            },
            {
                'name': 'ECU_FLEX_RAY_CONNECTED_CHS',
                'type': 'u32',
                'value': 327700
            },
            {
                'name': 'ECU_FLEX_RAY_STARTUP_FRAME_REF',
                'type': 'db_ref',
                'value': 84213777
            },
            {
                'name': 'ECU_FLEX_RAY_WAKEUP_CHS',
                'type': 'u32',
                'value': 327699
            },
            {
                'name': 'ECU_FLEX_RAY_WAKEUP_PTRN',
                'type': 'u32',
                'value': 327698
            },
            {
                'name': 'ECU_RX_FRM_REFS',
                'type': 'db_ref_array',
                'value': 100990979
            },
            {
                'name': 'ECU_TX_FRM_REFS',
                'type': 'db_ref_array',
                'value': 100990980
            },
            {
                'name': 'ECU_LIN_CONFIG_NAD',
                'type': 'u32',
                'value': 327715
            },
            {
                'name': 'ECU_LIN_FUNCTION_ID',
                'type': 'u32',
                'value': 327717
            },
            {
                'name': 'ECU_LIN_INITIAL_NAD',
                'type': 'u32',
                'value': 327714
            },
            {
                'name': 'ECU_LIN_MASTER',
                'type': 'boolean',
                'value': 33882144
            },
            {
                'name': 'ECU_LINP2MIN',
                'type': 'f64',
                'value': 17104934
            },
            {
                'name': 'ECU_LIN_PROTOCOL_VER',
                'type': 'u32',
                'value': 327713
            },
            {
                'name': 'ECU_LINS_TMIN',
                'type': 'f64',
                'value': 17104935
            },
            {
                'name': 'ECU_LIN_SUPPLIER_ID',
                'type': 'u32',
                'value': 327716
            },
            {
                'name': 'ECU_NAME',
                'type': 'string',
                'value': 50659330
            },
            {
                'name': 'ECU_J1939_NODE_NAME',
                'type': 'u64',
                'value': 151322665
            },
            {
                'name': 'ECU_J1939_PREFERRED_ADDRESS',
                'type': 'u32',
                'value': 327720
            }
        ]
    },
    'DBPropertyValue': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'CA_NIO_MODE_CAN',
                'value': 0
            },
            {
                'name': 'CA_NIO_MODE_CAN_FD',
                'value': 1
            },
            {
                'name': 'CA_NIO_MODE_CAN_FD_BRS',
                'value': 2
            },
            {
                'name': 'PROTOCOL_UNKNOWN',
                'value': 4294967294
            },
            {
                'name': 'PROTOCOL_CAN',
                'value': 0
            },
            {
                'name': 'PROTOCOL_FLEX_RAY',
                'value': 1
            },
            {
                'name': 'PROTOCOL_LIN',
                'value': 2
            },
            {
                'name': 'PROTOCOL_ETHERNET',
                'value': 3
            },
            {
                'name': 'APP_PROTOCOL_NONE',
                'value': 0
            },
            {
                'name': 'APP_PROTOCOL_J1939',
                'value': 1
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_A',
                'value': 1
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_B',
                'value': 2
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_AAND_B',
                'value': 3
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_NONE',
                'value': 4
            },
            {
                'name': 'CLST_FLEX_RAY_SAMP_CLK_PER_P_0125US',
                'value': 0
            },
            {
                'name': 'CLST_FLEX_RAY_SAMP_CLK_PER_P_025US',
                'value': 1
            },
            {
                'name': 'CLST_FLEX_RAY_SAMP_CLK_PER_P_05US',
                'value': 2
            },
            {
                'name': 'SIG_BYTE_ORDR_LITTLE_ENDIAN',
                'value': 0
            },
            {
                'name': 'SIG_BYTE_ORDR_BIG_ENDIAN',
                'value': 1
            },
            {
                'name': 'SIG_DATA_TYPE_SIGNED',
                'value': 0
            },
            {
                'name': 'SIG_DATA_TYPE_UNSIGNED',
                'value': 1
            },
            {
                'name': 'SIG_DATA_TYPE_IEEE_FLOAT',
                'value': 2
            },
            {
                'name': 'SIG_DATA_TYPE_BYTE_ARRAY',
                'value': 3
            },
            {
                'name': 'LIN_PROTOCOL_VER_1_2',
                'value': 2
            },
            {
                'name': 'LIN_PROTOCOL_VER_1_3',
                'value': 3
            },
            {
                'name': 'LIN_PROTOCOL_VER_2_0',
                'value': 4
            },
            {
                'name': 'LIN_PROTOCOL_VER_2_1',
                'value': 5
            },
            {
                'name': 'LIN_PROTOCOL_VER_2_2',
                'value': 6
            },
            {
                'name': 'LIN_SCHED_RUN_MODE_CONTINUOUS',
                'value': 0
            },
            {
                'name': 'LIN_SCHED_RUN_MODE_ONCE',
                'value': 1
            },
            {
                'name': 'LIN_SCHED_RUN_MODE_NULL',
                'value': 2
            },
            {
                'name': 'LIN_SCHED_ENTRY_TYPE_UNCONDITIONAL',
                'value': 0
            },
            {
                'name': 'LIN_SCHED_ENTRY_TYPE_SPORADIC',
                'value': 1
            },
            {
                'name': 'LIN_SCHED_ENTRY_TYPE_EVENT_TRIGGERED',
                'value': 2
            },
            {
                'name': 'LIN_SCHED_ENTRY_TYPE_NODE_CONFIG_SERVICE',
                'value': 3
            }
        ]
    },
    'GetDBCAttributeMode': {
        'values': [
            {
                'name': 'GET_DBC_MODE_ATTRIBUTE',
                'value': 0
            },
            {
                'name': 'GET_DBC_MODE_ENUMERATION_LIST',
                'value': 1
            },
            {
                'name': 'GET_DBC_MODE_ATTRIBUTE_LIST',
                'value': 2
            },
            {
                'name': 'GET_DBC_MODE_VALUE_TABLE_LIST',
                'value': 3
            }
        ]
    },
    'Property': {
        'generate-mapping-type': True,
        'values': [
            {
                'name': 'SESSION_APPLICATION_PROTOCOL',
                'type': 'u32',
                'value': 1048721
            },
            {
                'name': 'SESSION_AUTO_START',
                'type': 'boolean',
                'value': 34603009
            },
            {
                'name': 'SESSION_CLUSTER_NAME',
                'type': 'string',
                'value': 51380234
            },
            {
                'name': 'SESSION_DATABASE_NAME',
                'type': 'string',
                'value': 51380226
            },
            {
                'name': 'SESSION_ENET_FRAME_FILTER',
                'type': 'string',
                'value': 51380468
            },
            {
                'name': 'SESSION_ENET_LOG_ERROR',
                'type': 'boolean',
                'value': 34603197
            },
            {
                'name': 'SESSION_ENET_LOG_FILE',
                'type': 'string',
                'value': 51380410
            },
            {
                'name': 'SESSION_ENET_LOG_MODE',
                'type': 'u32',
                'value': 1048761
            },
            {
                'name': 'SESSION_ENET_LOG_ENABLE_MULTIPLE_FILES',
                'type': 'boolean',
                'value': 34603257
            },
            {
                'name': 'SESSION_ENET_LOG_FILE_SIZE_THRESHOLD',
                'type': 'u64',
                'value': 152043770
            },
            {
                'name': 'SESSION_ENET_LOG_OPERATION',
                'type': 'u32',
                'value': 1048763
            },
            {
                'name': 'SESSION_ENET_NUM_FRAMES_RECEIVED',
                'type': 'u64',
                'value': 152043759
            },
            {
                'name': 'SESSION_ENET_SOURCE_MAC_ADDRESS_AUTO',
                'type': 'boolean',
                'value': 34603177
            },
            {
                'name': 'SESSION_INTF_BAUD_RATE_64',
                'type': 'u64',
                'value': 152043542
            },
            {
                'name': 'SESSION_INTF_ADJUST_LOCAL_TIME',
                'type': 'u64',
                'value': 152043691
            },
            {
                'name': 'SESSION_INTF_BAUD_RATE',
                'type': 'u32',
                'value': 1048598
            },
            {
                'name': 'SESSION_INTF_BUS_ERR_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603029
            },
            {
                'name': 'SESSION_INTF_CAN_FD_BAUD_RATE_64',
                'type': 'u64',
                'value': 152043559
            },
            {
                'name': 'SESSION_INTF_CAN_DISABLE_PROT_EXCEPTION_HANDLING',
                'type': 'boolean',
                'value': 34603172
            },
            {
                'name': 'SESSION_INTF_CAN_EDGE_FILTER',
                'type': 'boolean',
                'value': 34603170
            },
            {
                'name': 'SESSION_INTF_CAN_EXT_TCVR_CONFIG',
                'type': 'u32',
                'value': 1048611
            },
            {
                'name': 'SESSION_INTF_CAN_FD_BAUD_RATE',
                'type': 'u32',
                'value': 1048615
            },
            {
                'name': 'SESSION_INTF_CAN_FD_ISO_MODE',
                'type': 'u32',
                'value': 1048638
            },
            {
                'name': 'SESSION_INTF_CAN_IO_MODE',
                'type': 'u32',
                'value': 1048614
            },
            {
                'name': 'SESSION_INTF_CAN_LSTN_ONLY',
                'type': 'boolean',
                'value': 34603042
            },
            {
                'name': 'SESSION_INTF_CAN_PEND_TX_ORDER',
                'type': 'u32',
                'value': 1048608
            },
            {
                'name': 'SESSION_INTF_CAN_SING_SHOT',
                'type': 'boolean',
                'value': 34603044
            },
            {
                'name': 'SESSION_INTF_CAN_TERM',
                'type': 'u32',
                'value': 1048613
            },
            {
                'name': 'SESSION_INTF_CAN_TCVR_STATE',
                'type': 'u32',
                'value': 1048616
            },
            {
                'name': 'SESSION_INTF_CAN_TCVR_TYPE',
                'type': 'u32',
                'value': 1048617
            },
            {
                'name': 'SESSION_INTF_CAN_TX_IO_MODE',
                'type': 'u32',
                'value': 1048633
            },
            {
                'name': 'SESSION_INTF_CAN_TRANSMIT_PAUSE',
                'type': 'boolean',
                'value': 34603171
            },
            {
                'name': 'SESSION_INTF_ECHO_TX',
                'type': 'boolean',
                'value': 34603024
            },
            {
                'name': 'SESSION_INTF_ENET_EPT_RECEIVE_FILTER',
                'type': 'nxEptRxFilter_Element_t_array',
                'value': 202375356
            },
            {
                'name': 'SESSION_INTF_ENET_EPT_TRANSMIT_BANDWIDTH',
                'type': 'u64',
                'value': 152043711
            },
            {
                'name': 'SESSION_INTF_ENET_IP_V4_ADDRESS',
                'type': 'string',
                'value': 51380459
            },
            {
                'name': 'SESSION_INTF_ENET_JUMBO_FRAMES',
                'type': 'u32',
                'value': 1048819
            },
            {
                'name': 'SESSION_INTF_ENET_LINK_SPEED',
                'type': 'u32',
                'value': 1048818
            },
            {
                'name': 'SESSION_INTF_ENET_LINK_SPEED_CONFIGURED',
                'type': 'u32',
                'value': 1048817
            },
            {
                'name': 'SESSION_INTF_ENET_MAC_ADDRESS',
                'type': 'string',
                'value': 51380392
            },
            {
                'name': 'SESSION_INTF_ENET_OS_NETWORK_ADAPTER_DESCRIPTION',
                'type': 'string',
                'value': 51380461
            },
            {
                'name': 'SESSION_INTF_ENET_OS_NETWORK_ADAPTER_NAME',
                'type': 'string',
                'value': 51380460
            },
            {
                'name': 'SESSION_INTF_ENET_OPERATIONAL_STATUS',
                'type': 'u32',
                'value': 1048746
            },
            {
                'name': 'SESSION_INTF_ENET_OUT_STRM_TIMESCALE',
                'type': 'u32',
                'value': 1048823
            },
            {
                'name': 'SESSION_INTF_ENET_PHY_POWER_MODE',
                'type': 'u32',
                'value': 1048825
            },
            {
                'name': 'SESSION_INTF_ENET_PHY_STATE',
                'type': 'u32',
                'value': 1048743
            },
            {
                'name': 'SESSION_INTF_ENET_PORT_MODE',
                'type': 'u32',
                'value': 1048742
            },
            {
                'name': 'SESSION_INTF_ENET_SIGNAL_QUALITY',
                'type': 'i32',
                'value': 235929846
            },
            {
                'name': 'SESSION_INTF_ENET_SLEEP_CAPABILITY',
                'type': 'u32',
                'value': 1048824
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_COUNTER_NAMES',
                'type': 'string_array',
                'value': 68157612
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_COUNTER_VALUES',
                'type': 'string_array',
                'value': 68157613
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_RX_BAD_FRAMES',
                'type': 'u64',
                'value': 152043702
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_RX_BYTES',
                'type': 'u64',
                'value': 152043694
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_RX_GOOD_FRAMES',
                'type': 'u64',
                'value': 152043695
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_TX_BYTES',
                'type': 'u64',
                'value': 152043703
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_TX_GOOD_FRAMES',
                'type': 'u64',
                'value': 152043704
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_COUNTER_NAMES',
                'type': 'string_array',
                'value': 68157693
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_COUNTER_VALUES',
                'type': 'string_array',
                'value': 68157694
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_LOW_POWER_SLEEP',
                'type': 'u64',
                'value': 152043777
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_SLEEP_FAILURE',
                'type': 'u64',
                'value': 152043779
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_WAKEUP_FAILURE',
                'type': 'u64',
                'value': 152043778
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_WAKEUP_PULSE',
                'type': 'u64',
                'value': 152043775
            },
            {
                'name': 'SESSION_INTF_ENET_STATS_PHY_WAKEUP_REQUEST',
                'type': 'u64',
                'value': 152043776
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_ADJUST_NETWORK_TIME',
                'type': 'u64',
                'value': 152043729
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_BMCA_ENABLED',
                'type': 'boolean',
                'value': 34603202
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_CLK_ACCURACY',
                'type': 'u32',
                'value': 1048774
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_CLK_CLASS',
                'type': 'u32',
                'value': 1048773
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_CLK_ID',
                'type': 'string',
                'value': 51380420
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_CLK_OFFSET_VAR',
                'type': 'u32',
                'value': 1048775
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_CLK_ACCURACY',
                'type': 'u32',
                'value': 1048781
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_CLK_CLASS',
                'type': 'u32',
                'value': 1048780
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_CLK_ID',
                'type': 'string',
                'value': 51380427
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_CLK_OFFSET_VAR',
                'type': 'u32',
                'value': 1048782
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_PRIORITY_1',
                'type': 'u32',
                'value': 1048783
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_GM_PRIORITY_2',
                'type': 'u32',
                'value': 1048784
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_OFFSET_FROM_MASTER',
                'type': 'u64',
                'value': 152043715
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_AS_CAPABLE',
                'type': 'boolean',
                'value': 34603233
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_ANNOUNCE_RECEIPT_TIMEOUT',
                'type': 'u32',
                'value': 1048800
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_ANNOUNCE_TRANSMIT_ENABLED',
                'type': 'boolean',
                'value': 34603231
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_ANNOUNCE_INTERVAL',
                'type': 'u32',
                'value': 1048798
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_ANNOUNCE_INTERVAL_CONFIGURED',
                'type': 'u32',
                'value': 1048797
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_PDELAY_INTERVAL',
                'type': 'u32',
                'value': 1048793
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_PDELAY_INTERVAL_CONFIGURED',
                'type': 'u32',
                'value': 1048792
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_SYNC_INTERVAL',
                'type': 'u32',
                'value': 1048795
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_LOG_SYNC_INTERVAL_CONFIGURED',
                'type': 'u32',
                'value': 1048794
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_PDELAY_ENABLED',
                'type': 'boolean',
                'value': 34603223
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATE',
                'type': 'u32',
                'value': 1048787
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATE_CONFIGURED',
                'type': 'u32',
                'value': 1048786
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_PROP_DELAY',
                'type': 'f64',
                'value': 17826004
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_PROP_DELAY_CONFIGURED',
                'type': 'f64',
                'value': 17826005
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_PROP_DELAY_THRESHOLD',
                'type': 'f64',
                'value': 17826006
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_COUNTER_NAMES',
                'type': 'string_array',
                'value': 68157667
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_COUNTER_VALUES',
                'type': 'string_array',
                'value': 68157668
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_RX_ANNOUNCE',
                'type': 'u64',
                'value': 152043750
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_RX_PDELAY_REQUEST',
                'type': 'u64',
                'value': 152043751
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_RX_SYNC',
                'type': 'u64',
                'value': 152043749
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_TX_ANNOUNCE',
                'type': 'u64',
                'value': 152043753
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_TX_PDELAY_REQUEST',
                'type': 'u64',
                'value': 152043754
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_STATS_TX_SYNC',
                'type': 'u64',
                'value': 152043752
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_SYNC_RECEIPT_TIMEOUT',
                'type': 'u32',
                'value': 1048796
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_SYNC_STATUS',
                'type': 'u32',
                'value': 1048816
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PORT_SYNCED',
                'type': 'boolean',
                'value': 34603234
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PRIORITY_1',
                'type': 'u32',
                'value': 1048776
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PRIORITY_2',
                'type': 'u32',
                'value': 1048777
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PROTOCOL',
                'type': 'u32',
                'value': 1048768
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_PROTOCOL_ENABLED',
                'type': 'boolean',
                'value': 34603201
            },
            {
                'name': 'SESSION_INTF_ENET_TIME_STEPS_TO_GM',
                'type': 'u32',
                'value': 1048778
            },
            {
                'name': 'SESSION_INTF_ENET_TRIGGER_PPS_SYNCED',
                'type': 'boolean',
                'value': 34603268
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_ACC_START_RNG',
                'type': 'u32',
                'value': 1048624
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_ALW_HLT_CLK',
                'type': 'boolean',
                'value': 34603057
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_ALW_PASS_ACT',
                'type': 'u32',
                'value': 1048626
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_AUTO_ASLP_WHN_STP',
                'type': 'boolean',
                'value': 34603066
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_CLST_DRIFT_DMP',
                'type': 'u32',
                'value': 1048627
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_COLDSTART',
                'type': 'boolean',
                'value': 34603060
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_CONNECTED_CHS',
                'type': 'u32',
                'value': 1048636
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_DEC_CORR',
                'type': 'u32',
                'value': 1048629
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_DELAY_COMP_A',
                'type': 'u32',
                'value': 1048630
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_DELAY_COMP_B',
                'type': 'u32',
                'value': 1048631
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_KEY_SLOT_ID',
                'type': 'u32',
                'value': 1048632
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_LATEST_TX',
                'type': 'u32',
                'value': 1048641
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_LIST_TIMO',
                'type': 'u32',
                'value': 1048642
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MAC_INIT_OFF_A',
                'type': 'u32',
                'value': 1048643
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MAC_INIT_OFF_B',
                'type': 'u32',
                'value': 1048644
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MAX_DRIFT',
                'type': 'u32',
                'value': 1048647
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MIC_INIT_OFF_A',
                'type': 'u32',
                'value': 1048645
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MIC_INIT_OFF_B',
                'type': 'u32',
                'value': 1048646
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_MICROTICK',
                'type': 'u32',
                'value': 1048648
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_NULL_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603081
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_OFF_CORR',
                'type': 'u32',
                'value': 1048664
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_OFF_CORR_OUT',
                'type': 'u32',
                'value': 1048656
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_RATE_CORR',
                'type': 'u32',
                'value': 1048665
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_RATE_CORR_OUT',
                'type': 'u32',
                'value': 1048658
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SAMP_PER_MICRO',
                'type': 'u32',
                'value': 1048659
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SING_SLOT_EN',
                'type': 'boolean',
                'value': 34603092
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SLEEP',
                'type': 'u32',
                'value': 1048635
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_STATISTICS_EN',
                'type': 'boolean',
                'value': 34603098
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYM_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603069
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYNC_STATUS',
                'type': 'u32',
                'value': 1048671
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYNC_CH_A_EVEN',
                'type': 'u32_array',
                'value': 135266395
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYNC_CH_A_ODD',
                'type': 'u32_array',
                'value': 135266396
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYNC_CH_B_EVEN',
                'type': 'u32_array',
                'value': 135266397
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_SYNC_CH_B_ODD',
                'type': 'u32_array',
                'value': 135266398
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_TERM',
                'type': 'u32',
                'value': 1048663
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_WAKEUP_CH',
                'type': 'u32',
                'value': 1048661
            },
            {
                'name': 'SESSION_INTF_FLEX_RAY_WAKEUP_PTRN',
                'type': 'u32',
                'value': 1048662
            },
            {
                'name': 'SESSION_INTF_NAME',
                'type': 'string',
                'value': 51380243
            },
            {
                'name': 'SESSION_INTF_LIN_BREAK_DELIMITER_LENGTH',
                'type': 'u32',
                'value': 1048821
            },
            {
                'name': 'SESSION_INTF_LIN_BREAK_LENGTH',
                'type': 'u32',
                'value': 1048688
            },
            {
                'name': 'SESSION_INTF_LIN_CHECKSUM_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603137
            },
            {
                'name': 'SESSION_INTF_LIN_DIAG_P2MIN',
                'type': 'f64',
                'value': 17825911
            },
            {
                'name': 'SESSION_INTF_LIN_DIAG_S_TMIN',
                'type': 'f64',
                'value': 17825910
            },
            {
                'name': 'SESSION_INTF_LIN_MASTER',
                'type': 'boolean',
                'value': 34603122
            },
            {
                'name': 'SESSION_INTF_LIN_NO_RESPONSE_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603136
            },
            {
                'name': 'SESSION_INTF_LINO_STR_SLV_RSP_LST_BY_NAD',
                'type': 'u32_array',
                'value': 135266425
            },
            {
                'name': 'SESSION_INTF_LIN_SCHED_NAMES',
                'type': 'string_array',
                'value': 68157557
            },
            {
                'name': 'SESSION_INTF_LIN_SLEEP',
                'type': 'u32',
                'value': 1048691
            },
            {
                'name': 'SESSION_INTF_LIN_ALW_START_WO_BUS_PWR',
                'type': 'boolean',
                'value': 34603128
            },
            {
                'name': 'SESSION_INTF_LIN_TERM',
                'type': 'u32',
                'value': 1048692
            },
            {
                'name': 'SESSION_INTF_OUT_STRM_LIST',
                'type': 'db_ref_array',
                'value': 101711889
            },
            {
                'name': 'SESSION_INTF_OUT_STRM_LIST_BY_ID',
                'type': 'u32_array',
                'value': 135266337
            },
            {
                'name': 'SESSION_INTF_OUT_STRM_TIMNG',
                'type': 'u32',
                'value': 1048594
            },
            {
                'name': 'SESSION_INTF_SRC_TERM_START_TRIGGER',
                'type': 'string',
                'value': 51380368
            },
            {
                'name': 'SESSION_INTF_START_TRIG_TO_IN_STRM',
                'type': 'boolean',
                'value': 34603028
            },
            {
                'name': 'SESSION_LIST',
                'type': 'string_array',
                'value': 68157443
            },
            {
                'name': 'SESSION_MODE',
                'type': 'u32',
                'value': 1048580
            },
            {
                'name': 'SESSION_NUM_IN_LIST',
                'type': 'u32',
                'value': 1048581
            },
            {
                'name': 'SESSION_NUM_FRAMES',
                'type': 'u32',
                'value': 1048589
            },
            {
                'name': 'SESSION_NUM_PEND',
                'type': 'u32',
                'value': 1048582
            },
            {
                'name': 'SESSION_NUM_UNUSED',
                'type': 'u32',
                'value': 1048587
            },
            {
                'name': 'SESSION_PAYLD_LEN_MAX',
                'type': 'u32',
                'value': 1048585
            },
            {
                'name': 'SESSION_PROTOCOL',
                'type': 'u32',
                'value': 1048584
            },
            {
                'name': 'SESSION_QUEUE_SIZE',
                'type': 'u32',
                'value': 1048588
            },
            {
                'name': 'SESSION_RESAMP_RATE',
                'type': 'f64',
                'value': 17825799
            },
            {
                'name': 'SESSION_J1939_ECU',
                'type': 'db_ref',
                'value': 84934803
            },
            {
                'name': 'SESSION_J1939_ECU_BUSY',
                'type': 'boolean',
                'value': 34603169
            },
            {
                'name': 'SESSION_J1939_FILL_BYTE',
                'type': 'u32',
                'value': 1048735
            },
            {
                'name': 'SESSION_J1939_INCLUDE_DEST_ADDR_IN_PGN',
                'type': 'boolean',
                'value': 34603173
            },
            {
                'name': 'SESSION_J1939_MAX_REPEAT_CTS',
                'type': 'u32',
                'value': 1048734
            },
            {
                'name': 'SESSION_J1939_ADDRESS',
                'type': 'u32',
                'value': 1048722
            },
            {
                'name': 'SESSION_J1939_NAME',
                'type': 'u64',
                'value': 152043668
            },
            {
                'name': 'SESSION_J1939_NUM_PACKETS_RECV',
                'type': 'u32',
                'value': 1048732
            },
            {
                'name': 'SESSION_J1939_NUM_PACKETS_RESP',
                'type': 'u32',
                'value': 1048733
            },
            {
                'name': 'SESSION_J1939_HOLD_TIME_TH',
                'type': 'f64',
                'value': 17825947
            },
            {
                'name': 'SESSION_J1939_RESPONSE_TIME_TR_GD',
                'type': 'f64',
                'value': 17825946
            },
            {
                'name': 'SESSION_J1939_RESPONSE_TIME_TR_SD',
                'type': 'f64',
                'value': 17825945
            },
            {
                'name': 'SESSION_J1939_TIMEOUT_T1',
                'type': 'f64',
                'value': 17825941
            },
            {
                'name': 'SESSION_J1939_TIMEOUT_T2',
                'type': 'f64',
                'value': 17825942
            },
            {
                'name': 'SESSION_J1939_TIMEOUT_T3',
                'type': 'f64',
                'value': 17825943
            },
            {
                'name': 'SESSION_J1939_TIMEOUT_T4',
                'type': 'f64',
                'value': 17825944
            },
            {
                'name': 'SESSION_J1939_WRITE_QUEUE_SIZE',
                'type': 'u32',
                'value': 1048736
            },
            {
                'name': 'SYS_CDAQ_PKT_TIME',
                'type': 'f64',
                'value': 17891340
            },
            {
                'name': 'SYS_DEV_REFS',
                'type': 'u32_array',
                'value': 101777410
            },
            {
                'name': 'SYS_INTF_REFS',
                'type': 'u32_array',
                'value': 101777411
            },
            {
                'name': 'SYS_INTF_REFS_ALL',
                'type': 'u32_array',
                'value': 101777421
            },
            {
                'name': 'SYS_INTF_REFS_CAN',
                'type': 'u32_array',
                'value': 101777412
            },
            {
                'name': 'SYS_INTF_REFS_ETHERNET',
                'type': 'u32_array',
                'value': 101777409
            },
            {
                'name': 'SYS_INTF_REFS_FLEX_RAY',
                'type': 'u32_array',
                'value': 101777413
            },
            {
                'name': 'SYS_INTF_REFS_LIN',
                'type': 'u32_array',
                'value': 101777415
            },
            {
                'name': 'SYS_VER_BUILD',
                'type': 'u32',
                'value': 1114118
            },
            {
                'name': 'SYS_VER_MAJOR',
                'type': 'u32',
                'value': 1114120
            },
            {
                'name': 'SYS_VER_MINOR',
                'type': 'u32',
                'value': 1114121
            },
            {
                'name': 'SYS_VER_PHASE',
                'type': 'u32',
                'value': 1114122
            },
            {
                'name': 'SYS_VER_UPDATE',
                'type': 'u32',
                'value': 1114123
            },
            {
                'name': 'DEV_FORM_FAC',
                'type': 'u32',
                'value': 1179649
            },
            {
                'name': 'DEV_INTF_REFS',
                'type': 'u32_array',
                'value': 101842946
            },
            {
                'name': 'DEV_INTF_REFS_ALL',
                'type': 'u32_array',
                'value': 101842952
            },
            {
                'name': 'DEV_NUM_PORTS',
                'type': 'u32',
                'value': 1179652
            },
            {
                'name': 'DEV_NUM_PORTS_ALL',
                'type': 'u32',
                'value': 1179655
            },
            {
                'name': 'DEV_NAME',
                'type': 'string',
                'value': 51511299
            },
            {
                'name': 'DEV_PRODUCT_NUM',
                'type': 'u32',
                'value': 1179656
            },
            {
                'name': 'DEV_SER_NUM',
                'type': 'u32',
                'value': 1179653
            },
            {
                'name': 'DEV_SLOT_NUM',
                'type': 'u32',
                'value': 1179654
            },
            {
                'name': 'INTF_CAN_TERM_CAP',
                'type': 'u32',
                'value': 1245192
            },
            {
                'name': 'INTF_CAN_TCVR_CAP',
                'type': 'u32',
                'value': 1245191
            },
            {
                'name': 'INTF_DEV_REF',
                'type': 'u32',
                'value': 85131265
            },
            {
                'name': 'INTF_DONGLE_COMPATIBLE_FIRMWARE_VERSION',
                'type': 'u32',
                'value': 1245199
            },
            {
                'name': 'INTF_DONGLE_COMPATIBLE_REVISION',
                'type': 'u32',
                'value': 1245198
            },
            {
                'name': 'INTF_DONGLE_FIRMWARE_VERSION',
                'type': 'u32',
                'value': 1245197
            },
            {
                'name': 'INTF_DONGLE_ID',
                'type': 'u32',
                'value': 1245194
            },
            {
                'name': 'INTF_DONGLE_REVISION',
                'type': 'u32',
                'value': 1245196
            },
            {
                'name': 'INTF_DONGLE_STATE',
                'type': 'u32',
                'value': 1245193
            },
            {
                'name': 'INTF_NAME',
                'type': 'string',
                'value': 51576834
            },
            {
                'name': 'INTF_NUM',
                'type': 'u32',
                'value': 1245187
            },
            {
                'name': 'INTF_PORT_NUM',
                'type': 'u32',
                'value': 1245188
            },
            {
                'name': 'INTF_PROTOCOL',
                'type': 'u32',
                'value': 1245189
            }
        ]
    },
    'PropertyValue': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'CAN_FD_MODE_ISO',
                'value': 0
            },
            {
                'name': 'CAN_FD_MODE_NON_ISO',
                'value': 1
            },
            {
                'name': 'CAN_FD_MODE_ISO_LEGACY',
                'value': 2
            },
            {
                'name': 'CA_NIO_MODE_CAN',
                'value': 0
            },
            {
                'name': 'CA_NIO_MODE_CAN_FD',
                'value': 1
            },
            {
                'name': 'CA_NIO_MODE_CAN_FD_BRS',
                'value': 2
            },
            {
                'name': 'EPT_RX_FILTER_USE_FLAGS_VID',
                'value': 1
            },
            {
                'name': 'EPT_RX_FILTER_USE_FLAGS_PRIORITY',
                'value': 2
            },
            {
                'name': 'EPT_RX_FILTER_USE_FLAGS_DESTINATION_MAC',
                'value': 4
            },
            {
                'name': 'PHASE_DEVELOPMENT',
                'value': 0
            },
            {
                'name': 'PHASE_ALPHA',
                'value': 1
            },
            {
                'name': 'PHASE_BETA',
                'value': 2
            },
            {
                'name': 'PHASE_RELEASE',
                'value': 3
            },
            {
                'name': 'DEV_FORM_PXI',
                'value': 0
            },
            {
                'name': 'DEV_FORM_PCI',
                'value': 1
            },
            {
                'name': 'DEV_FORM_C_SERIES',
                'value': 2
            },
            {
                'name': 'DEV_FORM_PX_IE',
                'value': 3
            },
            {
                'name': 'DEV_FORM_USB',
                'value': 4
            },
            {
                'name': 'DEV_FORM_PC_IE',
                'value': 5
            },
            {
                'name': 'CAN_TERM_CAP_NO',
                'value': 0
            },
            {
                'name': 'CAN_TERM_CAP_YES',
                'value': 1
            },
            {
                'name': 'CAN_TCVR_CAP_HS',
                'value': 0
            },
            {
                'name': 'CAN_TCVR_CAP_LS',
                'value': 1
            },
            {
                'name': 'CAN_TCVR_CAP_XS',
                'value': 3
            },
            {
                'name': 'CAN_TCVR_CAP_XS_HS_LS',
                'value': 4
            },
            {
                'name': 'CAN_TCVR_CAP_UNKNOWN',
                'value': 4294967295
            },
            {
                'name': 'PROTOCOL_UNKNOWN',
                'value': 4294967294
            },
            {
                'name': 'PROTOCOL_CAN',
                'value': 0
            },
            {
                'name': 'PROTOCOL_FLEX_RAY',
                'value': 1
            },
            {
                'name': 'PROTOCOL_LIN',
                'value': 2
            },
            {
                'name': 'PROTOCOL_ETHERNET',
                'value': 3
            },
            {
                'name': 'APP_PROTOCOL_NONE',
                'value': 0
            },
            {
                'name': 'APP_PROTOCOL_J1939',
                'value': 1
            },
            {
                'name': 'DONGLE_STATE_NO_DONGLE_NO_EXT_POWER',
                'value': 1
            },
            {
                'name': 'DONGLE_STATE_NO_DONGLE_EXT_POWER',
                'value': 2
            },
            {
                'name': 'DONGLE_STATE_DONGLE_NO_EXT_POWER',
                'value': 3
            },
            {
                'name': 'DONGLE_STATE_READY',
                'value': 4
            },
            {
                'name': 'DONGLE_STATE_BUSY',
                'value': 5
            },
            {
                'name': 'DONGLE_STATE_COMM_ERROR',
                'value': 13
            },
            {
                'name': 'DONGLE_STATE_OVER_CURRENT',
                'value': 14
            },
            {
                'name': 'DONGLE_ID_LS_CAN',
                'value': 1
            },
            {
                'name': 'DONGLE_ID_HS_CAN',
                'value': 2
            },
            {
                'name': 'DONGLE_ID_SW_CAN',
                'value': 3
            },
            {
                'name': 'DONGLE_ID_XS_CAN',
                'value': 4
            },
            {
                'name': 'DONGLE_ID_LIN',
                'value': 6
            },
            {
                'name': 'DONGLE_ID_DONGLE_LESS',
                'value': 13
            },
            {
                'name': 'DONGLE_ID_UNKNOWN',
                'value': 14
            },
            {
                'name': 'CAN_TERM_OFF',
                'value': 0
            },
            {
                'name': 'CAN_TERM_ON',
                'value': 1
            },
            {
                'name': 'CAN_TCVR_STATE_NORMAL',
                'value': 0
            },
            {
                'name': 'CAN_TCVR_STATE_SLEEP',
                'value': 1
            },
            {
                'name': 'CAN_TCVR_STATE_SW_WAKEUP',
                'value': 2
            },
            {
                'name': 'CAN_TCVR_STATE_SW_HIGH_SPEED',
                'value': 3
            },
            {
                'name': 'CAN_TCVR_TYPE_HS',
                'value': 0
            },
            {
                'name': 'CAN_TCVR_TYPE_LS',
                'value': 1
            },
            {
                'name': 'CAN_TCVR_TYPE_SW',
                'value': 2
            },
            {
                'name': 'CAN_TCVR_TYPE_EXT',
                'value': 3
            },
            {
                'name': 'CAN_TCVR_TYPE_DISC',
                'value': 4
            },
            {
                'name': 'FLEX_RAY_SAMP_PER_MICRO_1',
                'value': 0
            },
            {
                'name': 'FLEX_RAY_SAMP_PER_MICRO_2',
                'value': 1
            },
            {
                'name': 'FLEX_RAY_SAMP_PER_MICRO_4',
                'value': 2
            },
            {
                'name': 'FLEX_RAY_TERM_OFF',
                'value': 0
            },
            {
                'name': 'FLEX_RAY_TERM_ON',
                'value': 1
            },
            {
                'name': 'LIN_SLEEP_REMOTE_SLEEP',
                'value': 0
            },
            {
                'name': 'LIN_SLEEP_REMOTE_WAKE',
                'value': 1
            },
            {
                'name': 'LIN_SLEEP_LOCAL_SLEEP',
                'value': 2
            },
            {
                'name': 'LIN_SLEEP_LOCAL_WAKE',
                'value': 3
            },
            {
                'name': 'LIN_TERM_OFF',
                'value': 0
            },
            {
                'name': 'LIN_TERM_ON',
                'value': 1
            },
            {
                'name': 'OUT_STRM_TIMNG_IMMEDIATE',
                'value': 0
            },
            {
                'name': 'OUT_STRM_TIMNG_REPLAY_EXCLUSIVE',
                'value': 1
            },
            {
                'name': 'OUT_STRM_TIMNG_REPLAY_INCLUSIVE',
                'value': 2
            },
            {
                'name': 'CAN_PEND_TX_ORDER_AS_SUBMITTED',
                'value': 0
            },
            {
                'name': 'CAN_PEND_TX_ORDER_BY_IDENTIFIER',
                'value': 1
            },
            {
                'name': 'FLEX_RAY_SLEEP_LOCAL_SLEEP',
                'value': 0
            },
            {
                'name': 'FLEX_RAY_SLEEP_LOCAL_WAKE',
                'value': 1
            },
            {
                'name': 'FLEX_RAY_SLEEP_REMOTE_WAKE',
                'value': 2
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_NORMAL_SUPPORTED',
                'value': 4
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SLEEP_SUPPORTED',
                'value': 32
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_WAKEUP_SUPPORTED',
                'value': 256
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_HIGH_SPEED_SUPPORTED',
                'value': 2048
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_POWER_ON_SUPPORTED',
                'value': 16384
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_NORMAL_OUTPUT_0_SET',
                'value': 1
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SLEEP_OUTPUT_0_SET',
                'value': 8
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_WAKEUP_OUTPUT_0_SET',
                'value': 64
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_HIGH_SPEED_OUTPUT_0_SET',
                'value': 512
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_POWER_ON_OUTPUT_0_SET',
                'value': 4096
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_NORMAL_OUTPUT_1_SET',
                'value': 2
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SLEEP_OUTPUT_1_SET',
                'value': 16
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_WAKEUP_OUTPUT_1_SET',
                'value': 128
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_SW_HIGH_SPEED_OUTPUT_1_SET',
                'value': 1024
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_POWER_ON_OUTPUT_1_SET',
                'value': 8192
            },
            {
                'name': 'CAN_EXT_TCVR_CONFIG_N_ERR_CONNECTED',
                'value': 2147483648
            },
            {
                'name': 'ENET_PORT_MODE_DIRECT',
                'value': 0
            },
            {
                'name': 'ENET_PORT_MODE_TAP',
                'value': 1
            },
            {
                'name': 'ENET_PHY_STATE_SLAVE',
                'value': 0
            },
            {
                'name': 'ENET_PHY_STATE_MASTER',
                'value': 1
            },
            {
                'name': 'ENET_PHY_STATE_AUTO',
                'value': 2
            },
            {
                'name': 'ENET_LINK_SPEED_LINK_DOWN',
                'value': 0
            },
            {
                'name': 'ENET_LINK_SPEED_100_MBPS',
                'value': 1
            },
            {
                'name': 'ENET_LINK_SPEED_1000_MBPS',
                'value': 2
            },
            {
                'name': 'ENET_JUMBO_FRAMES_DISABLED',
                'value': 0
            },
            {
                'name': 'ENET_JUMBO_FRAMES_9018_BYTES',
                'value': 1
            },
            {
                'name': 'ENET_OPERATIONAL_STATUS_DOWN',
                'value': 0
            },
            {
                'name': 'ENET_OPERATIONAL_STATUS_UP',
                'value': 1
            },
            {
                'name': 'ENET_LOG_MODE_OFF',
                'value': 0
            },
            {
                'name': 'ENET_LOG_MODE_LOG',
                'value': 1
            },
            {
                'name': 'ENET_LOG_OPERATION_CREATE_OR_REPLACE',
                'value': 0
            },
            {
                'name': 'ENET_LOG_OPERATION_CREATE',
                'value': 1
            },
            {
                'name': 'ENET_TIME_PROTOCOL_IEEE8021AS',
                'value': 0
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_25NSEC',
                'value': 32
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_100NSEC',
                'value': 33
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_250NSEC',
                'value': 34
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_1USEC',
                'value': 35
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_2500NSEC',
                'value': 36
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_10USEC',
                'value': 37
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_25USEC',
                'value': 38
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_100USEC',
                'value': 39
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_250USEC',
                'value': 40
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_1MSEC',
                'value': 41
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_2500USEC',
                'value': 42
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_10MSEC',
                'value': 43
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_25MSEC',
                'value': 44
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_100MSEC',
                'value': 45
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_250MSEC',
                'value': 46
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_1SEC',
                'value': 47
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_WITHIN_10SEC',
                'value': 48
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_GREATHER_THAN_10SEC',
                'value': 49
            },
            {
                'name': 'ENET_TIME_CLK_ACCURACY_UNKNOWN',
                'value': 254
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_SYNCED',
                'value': 0
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_ENET_LINK_DOWN',
                'value': 1
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_PROTOCOL_DISABLED',
                'value': 2
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_MEASURING_PROP_DELAY',
                'value': 3
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_MASTER_PENDING_ANNOUNCE',
                'value': 4
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_WAITING_FOR_MASTER',
                'value': 5
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_SYNCING_TO_MASTER',
                'value': 6
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_PEER_NOT_PROTO_CAPABLE',
                'value': 7
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_PROP_DELAY_EXCEEDS_TRESHOLD',
                'value': 8
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_SYNC_RECEIPT_TIMEOUT',
                'value': 9
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_FREQUENCY_OUT_OF_RANGE',
                'value': 10
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_SYNC_INTERVAL_OUT_OF_RANGE',
                'value': 11
            },
            {
                'name': 'ENET_TIME_PORT_SYNC_STATUS_MULTIPLE_MASTERS_DETECTED',
                'value': 12
            },
            {
                'name': 'ENET_TIME_PORT_STATE_DISABLED',
                'value': 3
            },
            {
                'name': 'ENET_TIME_PORT_STATE_MASTER',
                'value': 6
            },
            {
                'name': 'ENET_TIME_PORT_STATE_PASSIVE',
                'value': 7
            },
            {
                'name': 'ENET_TIME_PORT_STATE_SLAVE',
                'value': 9
            },
            {
                'name': 'ENET_TIME_P_DELAY_REQ_INTERVAL_125MS',
                'value': -3
            },
            {
                'name': 'ENET_TIME_P_DELAY_REQ_INTERVAL_250MS',
                'value': -2
            },
            {
                'name': 'ENET_TIME_P_DELAY_REQ_INTERVAL_500MS',
                'value': -1
            },
            {
                'name': 'ENET_TIME_P_DELAY_REQ_INTERVAL_1S',
                'value': 0
            },
            {
                'name': 'ENET_TIME_P_DELAY_REQ_INTERVAL_2S',
                'value': 1
            },
            {
                'name': 'ENET_TIME_SYNC_INTERVAL_125MS',
                'value': -3
            },
            {
                'name': 'ENET_TIME_SYNC_INTERVAL_250MS',
                'value': -2
            },
            {
                'name': 'ENET_TIME_SYNC_INTERVAL_500MS',
                'value': -1
            },
            {
                'name': 'ENET_TIME_SYNC_INTERVAL_1S',
                'value': 0
            },
            {
                'name': 'ENET_TIME_SYNC_INTERVAL_2S',
                'value': 1
            },
            {
                'name': 'ENET_TIME_ANNOUNCE_INTERVAL_125MS',
                'value': -3
            },
            {
                'name': 'ENET_TIME_ANNOUNCE_INTERVAL_250MS',
                'value': -2
            },
            {
                'name': 'ENET_TIME_ANNOUNCE_INTERVAL_500MS',
                'value': -1
            },
            {
                'name': 'ENET_TIME_ANNOUNCE_INTERVAL_1S',
                'value': 0
            },
            {
                'name': 'ENET_TIME_ANNOUNCE_INTERVAL_2S',
                'value': 1
            },
            {
                'name': 'ENET_SLEEP_CAPABILITY_DISABLED_OR_NOT_AVAILABLE',
                'value': 0
            },
            {
                'name': 'ENET_SLEEP_CAPABILITY_ENABLED',
                'value': 1
            },
            {
                'name': 'ENET_PHY_POWER_MODE_NORMAL',
                'value': 0
            },
            {
                'name': 'ENET_PHY_POWER_MODE_SLEEP',
                'value': 1
            }
        ]
    },
    'ReadState': {
        'values': [
            {
                'name': 'STATE_TIME_CURRENT',
                'value': 118685697
            },
            {
                'name': 'STATE_TIME_COMMUNICATING',
                'value': 118685698
            },
            {
                'name': 'STATE_TIME_START',
                'value': 118685699
            },
            {
                'name': 'STATE_SESSION_INFO',
                'value': 1245188
            },
            {
                'name': 'STATE_TIME_CURRENT_2',
                'value': 202571781
            },
            {
                'name': 'STATE_TIME_COMMUNICATING_2',
                'value': 202571782
            },
            {
                'name': 'STATE_TIME_START_2',
                'value': 202571783
            },
            {
                'name': 'STATE_CAN_COMM',
                'value': 1245200
            },
            {
                'name': 'STATE_FLEX_RAY_COMM',
                'value': 1245216
            },
            {
                'name': 'STATE_FLEX_RAY_STATS',
                'value': 135462945
            },
            {
                'name': 'STATE_LIN_COMM',
                'value': 1245232
            },
            {
                'name': 'STATE_J1939_COMM',
                'value': 1245248
            }
        ]
    },
    'StartStopScope': {
        'values': [
            {
                'name': 'START_STOP_NORMAL',
                'value': 0
            },
            {
                'name': 'START_STOP_SESSION_ONLY',
                'value': 1
            },
            {
                'name': 'START_STOP_INTERFACE_ONLY',
                'value': 2
            },
            {
                'name': 'START_STOP_SESSION_ONLY_BLOCKING',
                'value': 3
            }
        ]
    },
    'StateValue': {
        'values': [
            {
                'name': 'SESSION_INFO_STATE_STOPPED',
                'value': 0
            },
            {
                'name': 'SESSION_INFO_STATE_STARTED',
                'value': 1
            },
            {
                'name': 'SESSION_INFO_STATE_MIX',
                'value': 2
            },
            {
                'name': 'CAN_COMM_STATE_ERROR_ACTIVE',
                'value': 0
            },
            {
                'name': 'CAN_COMM_STATE_ERROR_PASSIVE',
                'value': 1
            },
            {
                'name': 'CAN_COMM_STATE_BUS_OFF',
                'value': 2
            },
            {
                'name': 'CAN_COMM_STATE_INIT',
                'value': 3
            },
            {
                'name': 'CAN_LAST_ERR_NONE',
                'value': 0
            },
            {
                'name': 'CAN_LAST_ERR_STUFF',
                'value': 1
            },
            {
                'name': 'CAN_LAST_ERR_FORM',
                'value': 2
            },
            {
                'name': 'CAN_LAST_ERR_ACK',
                'value': 3
            },
            {
                'name': 'CAN_LAST_ERR_BIT_1',
                'value': 4
            },
            {
                'name': 'CAN_LAST_ERR_BIT_0',
                'value': 5
            },
            {
                'name': 'CAN_LAST_ERR_CRC',
                'value': 6
            },
            {
                'name': 'FLEX_RAY_POC_STATE_DEFAULT_CONFIG',
                'value': 0
            },
            {
                'name': 'FLEX_RAY_POC_STATE_READY',
                'value': 1
            },
            {
                'name': 'FLEX_RAY_POC_STATE_NORMAL_ACTIVE',
                'value': 2
            },
            {
                'name': 'FLEX_RAY_POC_STATE_NORMAL_PASSIVE',
                'value': 3
            },
            {
                'name': 'FLEX_RAY_POC_STATE_HALT',
                'value': 4
            },
            {
                'name': 'FLEX_RAY_POC_STATE_MONITOR',
                'value': 5
            },
            {
                'name': 'FLEX_RAY_POC_STATE_CONFIG',
                'value': 15
            },
            {
                'name': 'LIN_COMM_STATE_IDLE',
                'value': 0
            },
            {
                'name': 'LIN_COMM_STATE_ACTIVE',
                'value': 1
            },
            {
                'name': 'LIN_COMM_STATE_INACTIVE',
                'value': 2
            },
            {
                'name': 'LIN_DIAGNOSTIC_SCHEDULE_NULL',
                'value': 0
            },
            {
                'name': 'LIN_DIAGNOSTIC_SCHEDULE_MASTER_REQ',
                'value': 1
            },
            {
                'name': 'LIN_DIAGNOSTIC_SCHEDULE_SLAVE_RESP',
                'value': 2
            },
            {
                'name': 'LIN_LAST_ERR_CODE_NONE',
                'value': 0
            },
            {
                'name': 'LIN_LAST_ERR_CODE_UNKNOWN_ID',
                'value': 1
            },
            {
                'name': 'LIN_LAST_ERR_CODE_FORM',
                'value': 2
            },
            {
                'name': 'LIN_LAST_ERR_CODE_FRAMING',
                'value': 3
            },
            {
                'name': 'LIN_LAST_ERR_CODE_READBACK',
                'value': 4
            },
            {
                'name': 'LIN_LAST_ERR_CODE_TIMEOUT',
                'value': 5
            },
            {
                'name': 'LIN_LAST_ERR_CODE_CRC',
                'value': 6
            }
        ]
    },
    'SubProperty': {
        'generate-mapping-type': True,
        'values': [
            {
                'name': 'SESSION_SUB_CAN_START_TIME_OFF',
                'type': 'f64',
                'value': 17825921
            },
            {
                'name': 'SESSION_SUB_CAN_TX_TIME',
                'type': 'f64',
                'value': 17825922
            },
            {
                'name': 'SESSION_SUB_LIN_TX_N_CORRUPTED_CHKSUMS',
                'type': 'u32',
                'value': 1048709
            },
            {
                'name': 'SESSION_SUB_OUTPUT_QUEUE_UPDATE_FREQ',
                'type': 'u32',
                'value': 1048708
            },
            {
                'name': 'SESSION_SUB_J1939_ADDR_FILTER',
                'type': 'string',
                'value': 51380358
            },
            {
                'name': 'SESSION_SUB_SKIP_N_CYCLIC_FRAMES',
                'type': 'u32',
                'value': 1048707
            }
        ]
    },
    'SubPropertyValue': {
        'values': [
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_A',
                'value': 1
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_B',
                'value': 2
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_AAND_B',
                'value': 3
            },
            {
                'name': 'FRM_FLEX_RAY_CH_ASSIGN_NONE',
                'value': 4
            },
            {
                'name': 'FRM_FLEX_RAY_TIMING_CYCLIC',
                'value': 0
            },
            {
                'name': 'FRM_FLEX_RAY_TIMING_EVENT',
                'value': 1
            },
            {
                'name': 'FRM_CAN_TIMING_CYCLIC_DATA',
                'value': 0
            },
            {
                'name': 'FRM_CAN_TIMING_EVENT_DATA',
                'value': 1
            },
            {
                'name': 'FRM_CAN_TIMING_CYCLIC_REMOTE',
                'value': 2
            },
            {
                'name': 'FRM_CAN_TIMING_EVENT_REMOTE',
                'value': 3
            },
            {
                'name': 'FRM_CAN_TIMING_CYCLIC_EVENT',
                'value': 4
            },
            {
                'name': 'FRM_LIN_CHECKSUM_CLASSIC',
                'value': 0
            },
            {
                'name': 'FRM_LIN_CHECKSUM_ENHANCED',
                'value': 1
            }
        ]
    },
    'TerminalName': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'TERM_PXI_TRIG_0',
                'value': 'PXI_Trig0'
            },
            {
                'name': 'TERM_PXI_TRIG_1',
                'value': 'PXI_Trig1'
            },
            {
                'name': 'TERM_PXI_TRIG_2',
                'value': 'PXI_Trig2'
            },
            {
                'name': 'TERM_PXI_TRIG_3',
                'value': 'PXI_Trig3'
            },
            {
                'name': 'TERM_PXI_TRIG_4',
                'value': 'PXI_Trig4'
            },
            {
                'name': 'TERM_PXI_TRIG_5',
                'value': 'PXI_Trig5'
            },
            {
                'name': 'TERM_PXI_TRIG_6',
                'value': 'PXI_Trig6'
            },
            {
                'name': 'TERM_PXI_TRIG_7',
                'value': 'PXI_Trig7'
            },
            {
                'name': 'TERM_FRONT_PANEL_0',
                'value': 'FrontPanel0'
            },
            {
                'name': 'TERM_FRONT_PANEL_1',
                'value': 'FrontPanel1'
            },
            {
                'name': 'TERM_PXI_STAR',
                'value': 'PXI_Star'
            },
            {
                'name': 'TERM_PXI_CLK_10',
                'value': 'PXI_Clk10'
            },
            {
                'name': 'TERM_10_MHZ_TIMEBASE',
                'value': '10MHzTimebase'
            },
            {
                'name': 'TERM_1_MHZ_TIMEBASE',
                'value': '1MHzTimebase'
            },
            {
                'name': 'TERM_MASTER_TIMEBASE',
                'value': 'MasterTimebase'
            },
            {
                'name': 'TERM_COMM_TRIGGER',
                'value': 'CommTrigger'
            },
            {
                'name': 'TERM_START_TRIGGER',
                'value': 'StartTrigger'
            },
            {
                'name': 'TERM_FLEX_RAY_START_CYCLE',
                'value': 'FlexRayStartCycle'
            },
            {
                'name': 'TERM_FLEX_RAY_MACROTICK',
                'value': 'FlexRayMacrotick'
            },
            {
                'name': 'TERM_LOG_TRIGGER',
                'value': 'LogTrigger'
            },
            {
                'name': 'TERM_TIME_TRIGGER',
                'value': 'TimeTrigger'
            },
            {
                'name': 'TERM_NETWORK_TIME_PPS',
                'value': 'NetworkTimePPS'
            },
            {
                'name': 'TERM_NETWORK_TIME_1_MHZ',
                'value': 'NetworkTime1MHz'
            }
        ]
    },
    'TimeOut': {
        'values': [
            {
                'name': 'TIMEOUT_NONE',
                'value': 0
            },
            {
                'name': 'TIMEOUT_INFINITE',
                'value': -1
            }
        ]
    },
    'TimeScale': {
        'values': [
            {
                'name': 'TIMESCALE_LOCAL_TIME',
                'value': 0
            },
            {
                'name': 'TIMESCALE_NETWORK_TIME',
                'value': 1
            }
        ]
    },
    'WaitCondition': {
        'values': [
            {
                'name': 'CONDITION_TRANSMIT_COMPLETE',
                'value': 32769
            },
            {
                'name': 'CONDITION_INTF_COMMUNICATING',
                'value': 32770
            },
            {
                'name': 'CONDITION_INTF_REMOTE_WAKEUP',
                'value': 32771
            },
            {
                'name': 'CONDITION_ETHERNET_SYNCED',
                'value': 32772
            }
        ]
    },
    'WriteState': {
        'values': [
            {
                'name': 'STATE_LIN_SCHEDULE_CHANGE',
                'value': 1245313
            },
            {
                'name': 'STATE_LIN_DIAGNOSTIC_SCHEDULE_CHANGE',
                'value': 1245315
            },
            {
                'name': 'STATE_FLEX_RAY_SYMBOL',
                'value': 1245314
            },
            {
                'name': 'STATE_ETHERNET_SLEEP',
                'value': 1245316
            },
            {
                'name': 'STATE_ETHERNET_WAKE',
                'value': 1245317
            }
        ]
    },
    'FrameType': {
        'values': [
            {
                'name': 'CAN',
                'value': 1
            },
            {
                'name': 'LIN',
                'value': 2
            },
            {
                'name': 'FLEX_RAY',
                'value': 3
            },
            {
                'name': 'J1939',
                'value': 4
            },
            {
                'name': 'ENET',
                'value': 5
            }
        ]
    }
}
