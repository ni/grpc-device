enums = {
  'OperationalStatus': {
      'enum-value-prefix': 'OPERATIONAL_STATUS',
        'values': [
            {
                'name': 'DOWN',
                'value': 0
            },
            {
                'name': 'UP',
                'value': 1
            }
        ]
    },
     'IPStackInfoStringFormat': {
        'enum-value-prefix': 'IPSTACK_INFO_STR_FORMAT',
        'values': [
            {
                'name': 'JSON',
                'value': 0
            },
            {
                'name': 'TEXT',
                'value': 1
            }
        ]
    },
    'AddressFamily': {
        'values': [
            {
                'name': 'INET',
                'value': 2
            },
            {
                'name': 'INET6',
                'value': 10
            }
        ]
    },
    'ProtocolFamily': {
        'values': [
            {
                'name': 'INET',
                'value': 2
            },
            {
                'name': 'INET6',
                'value': 10
            }
        ]
    },
    'IPProtocol': {
        'values': [
            {
                'name': 'IP',
                'value': 0
            },
            {
                'name': 'TCP',
                'value': 6
            },
            {
                'name': 'UDP',
                'value': 8
            },
            {
                'name': 'IPV6',
                'value': 12
            }
        ]
    },
    'SocketProtocolType': {
        'values': [
            {
                'name': 'STREAM',
                'value': 1
            },
            {
                'name': 'DGRAM',
                'value': 2
            }
        ]
    },
    'SocketOptionLevel': {
        'values': [
            {
                'name': 'SOCKET',
                'value': 13
            }
        ]
    },
    'OptName': {
        'values': [
            {
                'name': 'TCP_NODELAY',
                'value': 1
            },
            {
                'name': 'IP_ADD_MEMBERSHIP',
                'value': 3
            },
            {
                'name': 'IP_DROP_MEMBERSHIP',
                'value': 4
            },
            {
                'name': 'IP_MULTICAST_IF',
                'value': 5
            },
            {
                'name': 'IP_MULTICAST_TTL',
                'value': 6
            },
            {
                'name': 'IPV6_JOIN_GROUP',
                'value': 12
            },
            {
                'name': 'IPV6_LEAVE_GROUP',
                'value': 13
            },
            {
                'name': 'IPV6_ADD_MEMBERSHIP',
                'value': 12
            },
            {
                'name': 'IPV6_DROP_MEMBERSHIP',
                'value': 13
            },
            {
                'name': 'IPV6_MULTICAST_IF',
                'value': 14
            },
            {
                'name': 'IPV6_MULTICAST_HOPS',
                'value': 15
            },
            {
                'name': 'IPV6_V6ONLY',
                'value': 16
            },
            {
                'name': 'SO_RX_DATA',
                'value': 257
            },
            {
                'name': 'SO_RCV_BUF',
                'value': 258
            },
            {
                'name': 'SO_SND_BUF',
                'value': 259
            },
            {
                'name': 'SO_NON_BLOCK',
                'value': 260
            },
            {
                'name': 'SO_BIND_TO_DEVICE',
                'value': 261
            },
            {
                'name': 'SO_ERROR',
                'value': 262
            },
            {
                'name': 'SO_LINGER',
                'value': 263
            },
            {
                'name': 'SO_REUSE_ADDR',
                'value': 264
            },
        ]
    },
    'Shutdown': {
        'values': [
            {
                'name': 'RD',
                'value': 0
            },
            {
                'name': 'WR',
                'value': 1
            },
            {
                'name': 'RDWR',
                'value': 2
            }
        ]
    },
    'GetAddrInfoFlags': {
        'values': [
            {
                'name': 'AI_PASSIVE',
                'value': 1
            },
            {
                'name': 'AI_CANONNAME',
                'value': 2
            },
            {
                'name': 'AI_NUMERICHOST',
                'value': 4
            },
            {
                'name': 'AI_NUMERICSERV',
                'value': 8
            },
            {
                'name': 'AI_V4MAPPED',
                'value': 16
            },
            {
                'name': 'AI_ALL',
                'value': 32
            },
            {
                'name': 'AI_ADDRCONFIG',
                'value': 64
            },
            {
                'name': 'AI_LOCALQUERY',
                'value': 128
            },
            {
                'name': 'AI_PREFER_V4',
                'value': 256
            },
            {
                'name': 'AI_UNICAST_REPLY',
                'value': 512
            },
            {
                'name': 'AI_SHARED_RESET',
                'value': 1024
            },
            {
                'name': 'AI_BYPASS_CACHE',
                'value': 2048
            }
        ]
    },
    'GetNameInfoFlags': {
        'values': [
            {
                'name': 'NI_NOFQDN',
                'value': 1
            },
            {
                'name': 'NI_NUMERICHOST',
                'value': 2
            },
            {
                'name': 'NI_NAMEREQD',
                'value': 4
            },
            {
                'name': 'NI_NUMERICSERV',
                'value': 8
            },
            {
                'name': 'NI_DGRAM',
                'value': 16
            }
        ]
    },
}
