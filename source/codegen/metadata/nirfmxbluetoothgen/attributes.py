attributes = {
    1: {
        'access': 'read-write',
        'enum': 'CarrierMode',
        'name': 'CARRIER_MODE',
        'type': 'int32'
    },
    3: {
        'access': 'read-write',
        'enum': 'AutoHeadroomEnabled',
        'name': 'AUTO_HEADROOM_ENABLED',
        'type': 'int32'
    },
    4: {
        'access': 'read-write',
        'name': 'HEADROOM',
        'type': 'float64'
    },
    5: {
        'access': 'read-write',
        'name': 'IQ_RATE',
        'type': 'float64'
    },
    6: {
        'access': 'read-write',
        'name': 'ACTUAL_HEADROOM',
        'type': 'float64'
    },
    7: {
        'access': 'read-write',
        'enum': 'PacketType',
        'name': 'PACKET_TYPE',
        'type': 'int32'
    },
    8: {
        'access': 'read-write',
        'name': 'BD_ADDRESS_LAP',
        'type': 'int32'
    },
    9: {
        'access': 'read-write',
        'name': 'BD_ADDRESS_UAP',
        'type': 'int32'
    },
    10: {
        'access': 'read-write',
        'name': 'BD_ADDRESS_NAP',
        'type': 'int32'
    },
    11: {
        'access': 'read-write',
        'name': 'PACKET_HEADER_LT_ADDRESS',
        'type': 'int32'
    },
    12: {
        'access': 'read-write',
        'name': 'PACKET_HEADER_FLOW',
        'type': 'int32'
    },
    13: {
        'access': 'read-write',
        'enum': 'PacketHeaderArqn',
        'name': 'PACKET_HEADER_ARQN',
        'type': 'int32'
    },
    14: {
        'access': 'read-write',
        'name': 'PACKET_HEADER_SEQN',
        'type': 'int32'
    },
    15: {
        'access': 'read-write',
        'name': 'PAYLOAD_HEADER_LLID',
        'type': 'int32'
    },
    16: {
        'access': 'read-write',
        'name': 'PAYLOAD_HEADER_FLOW',
        'type': 'int32'
    },
    17: {
        'access': 'read-write',
        'name': 'PAYLOAD_LENGTH',
        'type': 'int32'
    },
    18: {
        'access': 'read-write',
        'enum': 'PayloadDataType',
        'name': 'PAYLOAD_DATA_TYPE',
        'type': 'int32'
    },
    20: {
        'access': 'read-write',
        'name': 'PAYLOAD_USER_DEFINED_BITS',
        'type': 'int32[]'
    },
    21: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_LT_ADDRESS',
        'type': 'int32'
    },
    22: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_DEVICE_CLASS',
        'type': 'int32'
    },
    23: {
        'access': 'read-write',
        'enum': 'AllIQImpairmentsEnabled',
        'name': 'ALL_IQ_IMPAIRMENTS_ENABLED',
        'type': 'int32'
    },
    24: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_SCAN_REPETITION',
        'type': 'int32'
    },
    25: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_PAGE_SCAN_MODE',
        'type': 'int32'
    },
    26: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_DEVICE_CLOCK',
        'type': 'int32'
    },
    27: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_BD_ADDRESS_LAP',
        'type': 'int32'
    },
    28: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_BD_ADDRESS_UAP',
        'type': 'int32'
    },
    29: {
        'access': 'read-write',
        'name': 'FHS_PAYLOAD_BD_ADDRESS_NAP',
        'type': 'int32'
    },
    30: {
        'access': 'read-write',
        'enum': 'DirtyTxEnabled',
        'name': 'DIRTY_TX_ENABLED',
        'type': 'int32'
    },
    31: {
        'access': 'read-write',
        'enum': 'WhiteningEnabled',
        'name': 'WHITENING_ENABLED',
        'type': 'int32'
    },
    32: {
        'access': 'read-write',
        'name': 'WHITENING_CLOCK',
        'type': 'int32'
    },
    33: {
        'access': 'read-write',
        'name': 'IQ_GAIN_IMBALANCE',
        'type': 'float64'
    },
    34: {
        'access': 'read-write',
        'name': 'QUADRATURE_SKEW',
        'type': 'float64'
    },
    35: {
        'access': 'read-write',
        'name': 'I_DC_OFFSET',
        'type': 'float64'
    },
    36: {
        'access': 'read-write',
        'name': 'Q_DC_OFFSET',
        'type': 'float64'
    },
    37: {
        'access': 'read-write',
        'name': 'CARRIER_FREQUENCY_OFFSET',
        'type': 'float64'
    },
    38: {
        'access': 'read-write',
        'enum': 'AwgnEnabled',
        'name': 'AWGN_ENABLED',
        'type': 'int32'
    },
    39: {
        'access': 'read-write',
        'name': 'CARRIER_TO_NOISE_RATIO',
        'type': 'float64'
    },
    40: {
        'access': 'read-write',
        'enum': 'CompatibilityVersion',
        'name': 'TOOLKIT_COMPATIBILITY_VERSION',
        'type': 'int32'
    },
    41: {
        'access': 'read-write',
        'name': 'PAYLOAD_PN_ORDER',
        'type': 'int32'
    },
    42: {
        'access': 'read-write',
        'name': 'PAYLOAD_PN_SEED',
        'type': 'int32'
    },
    43: {
        'access': 'read-write',
        'enum': 'PayloadLengthMode',
        'name': 'PAYLOAD_LENGTH_MODE',
        'type': 'int32'
    },
    44: {
        'access': 'read-write',
        'name': 'ACTUAL_PAYLOAD_LENGTH',
        'type': 'int32'
    },
    45: {
        'access': 'read-write',
        'name': 'IQ_WAVEFORM_SIZE',
        'type': 'int32'
    },
    46: {
        'access': 'read-write',
        'name': 'DV_VOICE_PAYLOAD_PN_ORDER',
        'type': 'int32'
    },
    47: {
        'access': 'read-write',
        'name': 'DV_VOICE_PAYLOAD_PN_SEED',
        'type': 'int32'
    },
    48: {
        'access': 'read-write',
        'name': 'DV_VOICE_PAYLOAD_USER_DEFINED_BITS',
        'type': 'int32[]'
    },
    49: {
        'access': 'read-write',
        'enum': 'DVVoicePayloadDataType',
        'name': 'DV_VOICE_PAYLOAD_DATA_TYPE',
        'type': 'int32'
    },
    50: {
        'access': 'read-write',
        'enum': 'LETPPayloadType',
        'name': 'LE_TP_PAYLOAD_TYPE',
        'type': 'int32'
    },
    51: {
        'access': 'read-write',
        'name': 'NUMBER_OF_UNIQUE_PACKETS',
        'type': 'int32'
    },
    52: {
        'access': 'read-write',
        'name': 'NUMBER_OF_IDLE_SLOTS',
        'type': 'int32'
    },
    54: {
        'access': 'read-write',
        'enum': 'LETPCorruptAlternateCrc',
        'name': 'LE_TP_CORRUPT_ALTERNATE_CRC',
        'type': 'int32'
    },
    55: {
        'access': 'read-write',
        'enum': 'DirtyTxMode',
        'name': 'DIRTY_TX_MODE',
        'type': 'int32'
    },
    56: {
        'access': 'read-write',
        'enum': 'DirtyTxParametersEnabledSet',
        'name': 'DIRTY_TX_PARAMETERS_ENABLED_SET',
        'type': 'int32[]'
    },
    57: {
        'access': 'read-write',
        'name': 'DIRTY_TX_CARRIER_FREQUENCY_OFFSET_SET',
        'type': 'int32[]'
    },
    58: {
        'access': 'read-write',
        'name': 'DIRTY_TX_MODULATION_INDEX_SET',
        'type': 'float64[]'
    },
    59: {
        'access': 'read-write',
        'name': 'DIRTY_TX_SYMBOL_TIMING_ERROR_SET',
        'type': 'int32[]'
    },
    61: {
        'access': 'read-write',
        'name': 'LE_ACCESS_ADDRESS',
        'type': 'int32'
    },
    62: {
        'access': 'read-write',
        'name': 'DIRTY_TX_RESIDUAL_FM_DEVIATION',
        'type': 'float64'
    },
    63: {
        'access': 'read-write',
        'name': 'DIRTY_TX_RESIDUAL_FM_FREQUENCY',
        'type': 'float64'
    },
    64: {
        'access': 'read-write',
        'name': 'CARRIER_FREQUENCY',
        'type': 'float64'
    },
    66: {
        'access': 'read-write',
        'enum': 'PayloadHeaderEnabled',
        'name': 'PAYLOAD_HEADER_ENABLED',
        'type': 'int32'
    },
    67: {
        'access': 'read-write',
        'enum': 'DirtyTxModulationIndexType',
        'name': 'DIRTY_TX_MODULATION_INDEX_TYPE',
        'type': 'int32'
    },
    68: {
        'access': 'read-write',
        'name': 'MODULATION_INDEX',
        'type': 'float64'
    },
    69: {
        'access': 'read-write',
        'name': 'MAXIMUM_HARDWARE_IQ_RATE',
        'type': 'float64'
    },
    70: {
        'access': 'read-write',
        'name': 'OVERSAMPLING_FACTOR',
        'type': 'int32'
    },
    71: {
        'access': 'read-write',
        'name': 'POWER_RAMP_SETTLING_TIME',
        'type': 'float64'
    },
    72: {
        'access': 'read-write',
        'name': 'POWER_RAMP_TIME',
        'type': 'float64'
    },
    73: {
        'access': 'read-write',
        'enum': 'PacketBitSequenceTraceEnabled',
        'name': 'PACKET_BIT_SEQUENCE_TRACE_ENABLED',
        'type': 'int32'
    },
    75: {
        'access': 'read-write',
        'enum': 'DirectionFindingMode',
        'name': 'DIRECTION_FINDING_MODE',
        'type': 'int32'
    },
    77: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_CONSTANT_TONE_EXTENSION_LENGTH',
        'type': 'float64'
    },
    78: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_CONSTANT_TONE_EXTENSION_SLOT_DURATION',
        'type': 'float64'
    },
    79: {
        'access': 'read-write',
        'name': 'RUN_TIME_SCALING',
        'type': 'float64'
    },
    81: {
        'access': 'read-write',
        'enum': 'WaveformFileVersion',
        'name': 'WAVEFORM_FILE_VERSION',
        'type': 'int32'
    },
    82: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_NUMBER_OF_ANTENNAS',
        'type': 'int32'
    },
    85: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_ANTENNA_SWITCHING_PATTERN',
        'type': 'char[]'
    },
    86: {
        'access': 'read-write',
        'enum': 'AntennaSwitchingEnabled',
        'name': 'DIRECTION_FINDING_ANTENNA_SWITCHING_ENABLED',
        'type': 'int32'
    },
    87: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_ANTENNA_SWITCHING_DURATION',
        'type': 'float64'
    },
    88: {
        'access': 'read-write',
        'name': 'DIRECTION_FINDING_ANTENNA_SWITCHING_DURATION_USED',
        'type': 'float64'
    },
    90: {
        'access': 'read-write',
        'name': 'BURST_START_LOCATIONS',
        'type': 'int32[]'
    },
    91: {
        'access': 'read-write',
        'name': 'BURST_STOP_LOCATIONS',
        'type': 'int32[]'
    },
    92: {
        'access': 'read-write',
        'enum': 'CSPacketFormat',
        'name': 'CS_PACKET_FORMAT',
        'type': 'int32'
    },
    93: {
        'access': 'read-write',
        'enum': 'CSSyncSequence',
        'name': 'CS_SYNC_SEQUENCE',
        'type': 'int32'
    },
    94: {
        'access': 'read-write',
        'name': 'CS_PHASE_MEASUREMENT_PERIOD',
        'type': 'float64'
    },
    95: {
        'access': 'read-write',
        'name': 'SOUNDING_SEQUENCE_LENGTH',
        'type': 'int32'
    },
    96: {
        'access': 'read-write',
        'enum': 'SoundingSequenceMarkerSignals',
        'name': 'SOUNDING_SEQUENCE_MARKER_SIGNALS',
        'type': 'int32[]'
    },
    97: {
        'access': 'read-write',
        'name': 'SOUNDING_SEQUENCE_MARKER_POSITIONS',
        'type': 'int32[]'
    },
    98: {
        'access': 'read-write',
        'enum': 'CSToneExtensionSlotEnabled',
        'name': 'CS_TONE_EXTENSION_SLOT_ENABLED',
        'type': 'int32'
    },
    99: {
        'access': 'read-write',
        'name': 'SAMPLE_CLOCK_OFFSET',
        'type': 'float64'
    },
    100: {
        'access': 'read-write',
        'name': 'TIME_DELAY',
        'type': 'float64'
    },
    101: {
        'access': 'read-write',
        'name': 'BANDWIDTH_BIT_PERIOD_PRODUCT',
        'type': 'float64'
    },
    102: {
        'access': 'read-write',
        'enum': 'DataRate',
        'name': 'DATA_RATE',
        'type': 'float64'
    },
    103: {
        'access': 'read-write',
        'enum': 'HdtPacketFormat',
        'name': 'HDT_PACKET_FORMAT',
        'type': 'int32'
    },
    104: {
        'access': 'read-write',
        'name': 'HDT_PHY_INTERVAL',
        'type': 'float64'
    },
    105: {
        'access': 'read-write',
        'name': 'ZADOFF_CHU_INDEX',
        'type': 'int32'
    },
    106: {
        'access': 'read-write',
        'name': 'PHYSICAL_CHANNEL_ADDRESS',
        'type': 'int64'
    },
    107: {
        'access': 'read-write',
        'name': 'VHDT_MODE_ENABLED',
        'type': 'int32'
    },
    108: {
        'access': 'read-write',
        'name': 'NUMBER_OF_BLOCK_REPETITION_SEQUENCES',
        'type': 'int32'
    },
    109: {
        'access': 'read-write',
        'name': 'NUMBER_OF_PAYLOADS',
        'type': 'int32'
    },
    110: {
        'access': 'read-write',
        'enum': 'Format1PayloadZoneConfigurationMode',
        'name': 'FORMAT1_PAYLOAD_ZONE_CONFIGURATION_MODE',
        'type': 'int32'
    },
    111: {
        'access': 'read-write',
        'enum': 'TxlenSequenceNumber',
        'name': 'TXLEN_SEQUENCE_NUMBER',
        'type': 'int32'
    },
    112: {
        'access': 'read-write',
        'name': 'NUMBER_OF_BLOCKS',
        'type': 'int32'
    },
    113: {
        'access': 'read-write',
        'name': 'BLOCK_SIZE',
        'type': 'int32'
    },
    114: {
        'access': 'read-write',
        'name': 'LAST_BLOCK_SIZE',
        'type': 'int32'
    },
    115: {
        'access': 'read-write',
        'name': 'TXBLOCK_MAP',
        'type': 'int32'
    },
    117: {
        'access': 'read-write',
        'name': 'PAYLOAD_ZONE_LENGTH',
        'type': 'int32'
    },
    118: {
        'access': 'read-write',
        'name': 'PAYLOAD_CRC_SEED',
        'type': 'int64'
    }
}
