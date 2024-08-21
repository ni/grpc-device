enums = {
    'CloseAttribute': {
        'values': [
            {
                'name': 'NO_RESET_IF_LAST_SESSION',
                'value': 1
            }
        ]
    },
    'FifoFlowControl': {
        'force-include': True,
        'values': [
            {
                'name': 'DISABLED',
                'value': 1
            },
            {
                'name': 'ENABLED',
                'value': 2
            }
        ]
    },
    'FifoProperty': {
        'values': [
            {
                'name': 'BYTES_PER_ELEMENT',
                'value': 1
            },
            {
                'name': 'HOST_BUFFER_ALLOCATION_GRANULARITY',
                'value': 2
            },
            {
                'name': 'HOST_BUFFER_SIZE',
                'value': 3
            },
            {
                'name': 'HOST_BUFFER_MIRROR_SIZE',
                'value': 4
            },
            {
                'name': 'HOST_BUFFER_TYPE',
                'value': 5
            },
            {
                'name': 'HOST_BUFFER',
                'value': 6
            },
            {
                'name': 'FLOW_CONTROL',
                'value': 7
            },
            {
                'name': 'ELEMENTS_CURRENTLY_ACQUIRED',
                'value': 8
            },
            {
                'name': 'PREFERRED_NUMA_NODE',
                'value': 9
            },
            {
                'name': 'NUMBER_OF_ZERO_COPY_REGIONS',
                'value': 10
            },
            {
                'name': 'NOT_SUPPORTED',
                'value': 0
            }
        ]
    },
    'FpgaViState': {
        'values': [
            {
                'name': 'NOT_RUNNING',
                'value': 0
            },
            {
                'name': 'INVALID',
                'value': 1
            },
            {
                'name': 'RUNNING',
                'value': 2
            },
            {
                'name': 'NATURALLY_STOPPED',
                'value': 3
            }
        ]
    },
    'HostBufferType': {
        'force-include': True,
        'values': [
            {
                'name': 'ALLOCATED_BY_RIO',
                'value': 1
            },
            {
                'name': 'ALLOCATED_BY_USER',
                'value': 2
            }
        ]
    },
    'Irq': {
        'force-include': True,
        'generate-mappings': True,
        'values': [
            {
                'name': 'Irq_0',
                'value': 1
            },
            {
                'name': 'Irq_1',
                'value': 2
            },
            {
                'name': 'Irq_2',
                'value': 4
            },
            {
                'name': 'Irq_3',
                'value': 8
            },
            {
                'name': 'Irq_4',
                'value': 16
            },
            {
                'name': 'Irq_5',
                'value': 32
            },
            {
                'name': 'Irq_6',
                'value': 64
            },
            {
                'name': 'Irq_7',
                'value': 128
            },
            {
                'name': 'Irq_8',
                'value': 256
            },
            {
                'name': 'Irq_9',
                'value': 512
            },
            {
                'name': 'Irq_10',
                'value': 1024
            },
            {
                'name': 'Irq_11',
                'value': 2048
            },
            {
                'name': 'Irq_12',
                'value': 4096
            },
            {
                'name': 'Irq_13',
                'value': 8192
            },
            {
                'name': 'Irq_14',
                'value': 16384
            },
            {
                'name': 'Irq_15',
                'value': 32768
            },
            {
                'name': 'Irq_16',
                'value': 65536
            },
            {
                'name': 'Irq_17',
                'value': 131072
            },
            {
                'name': 'Irq_18',
                'value': 262144
            },
            {
                'name': 'Irq_19',
                'value': 524288
            },
            {
                'name': 'Irq_20',
                'value': 1048576
            },
            {
                'name': 'Irq_21',
                'value': 2097152
            },
            {
                'name': 'Irq_22',
                'value': 4194304
            },
            {
                'name': 'Irq_23',
                'value': 8388608
            },
            {
                'name': 'Irq_24',
                'value': 16777216
            },
            {
                'name': 'Irq_25',
                'value': 33554432
            },
            {
                'name': 'Irq_26',
                'value': 67108864
            },
            {
                'name': 'Irq_27',
                'value': 134217728
            },
            {
                'name': 'Irq_28',
                'value': 268435456
            },
            {
                'name': 'Irq_29',
                'value': 536870912
            },
            {
                'name': 'Irq_30',
                'value': 1073741824
            },
            {
                'name': 'Irq_31',
                'value': 2147483648
            }
        ]
    },
    'OpenAttribute': {
        'generate-mappings': True,
        'values': [
            {
                'name': 'NO_RUN',
                'value': 1
            },
            {
                'name': 'BITFILE_PATH_IS_UTF8',
                'value': 2
            },
            {
                'name': 'BITFILE_CONTENTS_NOT_PATH',
                'value': 1073741824
            },
            {
                'name': 'IGNORE_SIGNATURE_ARGUMENT',
                'value': 2147483648
            }
        ]
    },
    'RunAttribute': {
        'values': [
            {
                'name': 'WAIT_UNTIL_DONE',
                'value': 1
            }
        ]
    }
}
