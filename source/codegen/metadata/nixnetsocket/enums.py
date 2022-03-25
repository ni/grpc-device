enums = {
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
    'GetAddrInfoFlags': {
        'force-include': True,
        'values': [
            {
                'name': 'PASSIVE',
                'value': 1
            },
            {
                'name': 'CANONNAME',
                'value': 2
            },
            {
                'name': 'NUMERICHOST',
                'value': 4
            },
            {
                'name': 'NUMERICSERV',
                'value': 8
            },
            {
                'name': 'V4MAPPED',
                'value': 16
            },
            {
                'name': 'ALL',
                'value': 32
            },
            {
                'name': 'ADDRCONFIG',
                'value': 64
            },
            {
                'name': 'LOCALQUERY',
                'value': 128
            },
            {
                'name': 'PREFER_V4',
                'value': 256
            },
            {
                'name': 'UNICAST_REPLY',
                'value': 512
            },
            {
                'name': 'SHARED_RESET',
                'value': 1024
            },
            {
                'name': 'BYPASS_CACHE',
                'value': 2048
            }
        ]
    },
    'GetNameInfoFlags': {
        'values': [
            {
                'name': 'NOFQDN',
                'value': 1
            },
            {
                'name': 'NUMERICHOST',
                'value': 2
            },
            {
                'name': 'NAMEREQD',
                'value': 4
            },
            {
                'name': 'NUMERICSERV',
                'value': 8
            },
            {
                'name': 'DGRAM',
                'value': 16
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
    'SocketOptionLevel': {
        'values': [
            {
                'name': 'SOCKET',
                'value': 13
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
}
