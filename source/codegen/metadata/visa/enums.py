enums = {
    'AccessPriv': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies supervisory (privileged) data accesses'
                },
                'name': 'DATA_PRIV',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies user (nonprivileged) data accesses'
                },
                'name': 'DATA_NPRIV',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies supervisory (privileged) program accesses'
                },
                'name': 'PROG_PRIV',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Specifies user (nonprivileged) program accesses'
                },
                'name': 'PROG_NPRIV',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Specifies supervisory (privileged) block accesses'
                },
                'name': 'BLCK_PRIV',
                'value': 4
            },
            {
                'documentation': {
                    'description': 'Specifies user (nonprivileged) block accesses'
                },
                'name': 'BLCK_NPRIV',
                'value': 5
            },
            {
                'documentation': {
                    'description': 'Specifies supervisory (privileged) D64 accesses'
                },
                'name': 'D64_PRIV',
                'value': 6
            },
            {
                'documentation': {
                    'description': 'Specifies user (nonprivileged) D64 accesses'
                },
                'name': 'D64_NPRIV',
                'value': 7
            }
        ]
    },
    'AddressSpace': {
        'values': [
            {
                'name': 'LOCAL_SPACE',
                'value': 0
            },
            {
                'name': 'A16_SPACE',
                'value': 1
            },
            {
                'name': 'A24_SPACE',
                'value': 2
            },
            {
                'name': 'A32_SPACE',
                'value': 3
            },
            {
                'name': 'A64_SPACE',
                'value': 4
            },
            {
                'name': 'PXI_ALLOC_SPACE',
                'value': 9
            },
            {
                'name': 'PXI_CFG_SPACE',
                'value': 10
            },
            {
                'name': 'PXI_BAR0_SPACE',
                'value': 11
            },
            {
                'name': 'PXI_BAR1_SPACE',
                'value': 12
            },
            {
                'name': 'PXI_BAR2_SPACE',
                'value': 13
            },
            {
                'name': 'PXI_BAR3_SPACE',
                'value': 14
            },
            {
                'name': 'PXI_BAR4_SPACE',
                'value': 15
            },
            {
                'name': 'PXI_BAR5_SPACE',
                'value': 16
            },
            {
                'name': 'OPAQUE_SPACE',
                'value': 65535
            }
        ]
    },
    'AsrlEndIn': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that there is no END indicator for read operations, so reads will not terminate until all of the requested data is received (or an error occurs)'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that any byte with the highest bit set is to be treated as an END indicator'
                },
                'name': 'LAST_BIT',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that the termination character (specified by VI_ATTR_TERMCHAR) is to be treated as an END indicator (VI_ATTR_TERMCHAR_EN is ignored)'
                },
                'name': 'TERMCHAR',
                'value': 2
            }
        ]
    },
    'AsrlEndOut': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that there is no END indicator for write operations, so writes will not append anything to the data being written'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that the last byte (and only the last byte) be sent with the highest bit set'
                },
                'name': 'LAST_BIT',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that the termination character (specified by VI_ATTR_TERMCHAR) is to be appended to each buffer written when VI_SEND_END_EN is true'
                },
                'name': 'TERMCHAR',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Specifies that a BREAK be sent after the last byte of each write operation'
                },
                'name': 'BREAK',
                'value': 3
            }
        ]
    },
    'AsrlFlow': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that no flow control is to be used, and buffers on both sides of the connection are assumed to be large enough to hold all data transferred'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that software handshaking is to be used (XON and XOFF)'
                },
                'name': 'XON_XOFF',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that hardware handshaking is to be used (RTS output signal and CTS input signal)'
                },
                'name': 'RTS_CTS',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Specifies that hardware handshaking is to be used (DTR output signal and DSR input signal)'
                },
                'name': 'DTR_DSR',
                'value': 4
            }
        ]
    },
    'AsrlParity': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that no parity bit exists'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that odd parity should be used'
                },
                'name': 'ODD',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that even parity should be used'
                },
                'name': 'EVEN',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Specifies that the parity bit exists and is always 1'
                },
                'name': 'MARK',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Specifies that the parity bit exists and is always 0'
                },
                'name': 'SPACE',
                'value': 4
            }
        ]
    },
    'AsrlStop': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that 1 stop bit is used per frame'
                },
                'name': 'ONE',
                'value': 10
            },
            {
                'documentation': {
                    'description': 'Specifies that 1.5 (one and one-half) stop bits are used per frame'
                },
                'name': 'ONE5',
                'value': 15
            },
            {
                'documentation': {
                    'description': 'Specifies that 2 stop bits are used per frame'
                },
                'name': 'TWO',
                'value': 20
            }
        ]
    },
    'AsrlWireMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that the RS-485 wire mode is 4-wire mode'
                },
                'name': 'WIRE_485_4',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-485 wire mode is 2-wire DTR mode controlled with echo'
                },
                'name': 'WIRE_485_2_DTR_ECHO',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-485 wire mode is 2-wire DTR mode controlled without echo'
                },
                'name': 'WIRE_485_2_DTR_CTRL',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-485 wire mode is 2-wire auto mode controlled with TXRDY'
                },
                'name': 'WIRE_485_2_AUTO',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-232 wire mode is DTE mode'
                },
                'name': 'WIRE_232_DTE',
                'value': 128
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-232 wire mode is DCE mode'
                },
                'name': 'WIRE_232_DCE',
                'value': 129
            },
            {
                'documentation': {
                    'description': 'Specifies that the RS-232 wire mode is automatically detected by the hardware'
                },
                'name': 'WIRE_232_AUTO',
                'value': 130
            }
        ]
    },
    'AssertInterruptSignalMode': {
        'values': [
            {
                'name': 'ASSERT_IRQ1',
                'value': 1
            },
            {
                'name': 'ASSERT_IRQ2',
                'value': 2
            },
            {
                'name': 'ASSERT_IRQ3',
                'value': 3
            },
            {
                'name': 'ASSERT_IRQ4',
                'value': 4
            },
            {
                'name': 'ASSERT_IRQ5',
                'value': 5
            },
            {
                'name': 'ASSERT_IRQ6',
                'value': 6
            },
            {
                'name': 'ASSERT_IRQ7',
                'value': 7
            },
            {
                'name': 'ASSERT_SIGNAL',
                'value': -1
            },
            {
                'name': 'ASSERT_USE_ASSIGNED',
                'value': 0
            }
        ]
    },
    'AssertUtilSignalMode': {
        'values': [
            {
                'name': 'UTIL_ASSERT_SYSRESET',
                'value': 1
            },
            {
                'name': 'UTIL_ASSERT_SYSFAIL',
                'value': 2
            },
            {
                'name': 'UTIL_DEASSERT_SYSFAIL',
                'value': 3
            }
        ]
    },
    'BufferMask': {
        'values': [
            {
                'name': 'IO_IN_BUF',
                'value': 16
            },
            {
                'name': 'IO_OUT_BUF',
                'value': 32
            },
            {
                'name': 'IO_IN_BUF_DISCARD',
                'value': 64
            },
            {
                'name': 'IO_OUT_BUF_DISCARD',
                'value': 128
            }
        ]
    },
    'ByteOrder': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies Big Endian (Motorola) byte order accesses'
                },
                'name': 'BIG_ENDIAN',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies Little Endian (Intel) byte order accesses'
                },
                'name': 'LITTLE_ENDIAN',
                'value': 1
            }
        ]
    },
    'EventMechanism': {
        'values': [
            {
                'name': 'QUEUE',
                'value': 1
            },
            {
                'name': 'HNDLR',
                'value': 2
            },
            {
                'name': 'SUSPEND_HNDLR',
                'value': 4
            },
            {
                'name': 'ALL_MECH',
                'value': 65535
            }
        ]
    },
    'EventType': {
        'values': [
            {
                'name': 'ALL_ENABLED_EVENTS',
                'value': 1073709055
            },
            {
                'name': 'EVENT_ASRL_BREAK',
                'value': 1073684515
            },
            {
                'name': 'EVENT_ASRL_CTS',
                'value': 1073684521
            },
            {
                'name': 'EVENT_ASRL_DSR',
                'value': 1073684522
            },
            {
                'name': 'EVENT_ASRL_DCD',
                'value': 1073684524
            },
            {
                'name': 'EVENT_ASRL_RI',
                'value': 1073684526
            },
            {
                'name': 'EVENT_ASRL_CHAR',
                'value': 1073684533
            },
            {
                'name': 'EVENT_ASRL_TERMCHAR',
                'value': 1073684516
            },
            {
                'name': 'EVENT_IO_COMPLETION',
                'value': 1073684489
            },
            {
                'name': 'EVENT_TRIG',
                'value': 3221168138
            },
            {
                'name': 'EVENT_SERVICE_REQ',
                'value': 1073684491
            },
            {
                'name': 'EVENT_CLEAR',
                'value': 1073684493
            },
            {
                'name': 'EVENT_EXCEPTION',
                'value': 3221168142
            },
            {
                'name': 'EVENT_GPIB_CIC',
                'value': 1073684498
            },
            {
                'name': 'EVENT_GPIB_TALK',
                'value': 1073684499
            },
            {
                'name': 'EVENT_GPIB_LISTEN',
                'value': 1073684500
            },
            {
                'name': 'EVENT_VXI_VME_SYSFAIL',
                'value': 1073684509
            },
            {
                'name': 'EVENT_VXI_VME_SYSRESET',
                'value': 1073684510
            },
            {
                'name': 'EVENT_VXI_SIGP',
                'value': 1073684512
            },
            {
                'name': 'EVENT_VXI_VME_INTR',
                'value': 3221168161
            },
            {
                'name': 'EVENT_PXI_INTR',
                'value': 1073684514
            },
            {
                'name': 'EVENT_TCPIP_CONNECT',
                'value': 1073684534
            },
            {
                'name': 'EVENT_USB_INTR',
                'value': 1073684535
            }
        ]
    },
    'FdcMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Uses normal FDC transfers'
                },
                'name': 'NORMAL',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Uses FDC stream transfers'
                },
                'name': 'STREAM',
                'value': 2
            }
        ]
    },
    'GpibAddr': {
        'values': [
            {
                'documentation': {
                    'description': 'The GPIB controller is not addressed'
                },
                'name': 'UNADDRESSED',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'The GPIB controller is addressed to talk'
                },
                'name': 'TALKER',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'The GPIB controller is addressed to listen'
                },
                'name': 'LISTENER',
                'value': 2
            }
        ]
    },
    'GpibControlAtnMode': {
        'values': [
            {
                'name': 'ATN_DEASSERT',
                'value': 0
            },
            {
                'name': 'ATN_ASSERT',
                'value': 1
            },
            {
                'name': 'ATN_DEASSERT_HANDSHAKE',
                'value': 2
            },
            {
                'name': 'ATN_ASSERT_IMMEDIATE',
                'value': 3
            }
        ]
    },
    'GpibControlRenMode': {
        'values': [
            {
                'name': 'REN_DEASSERT',
                'value': 0
            },
            {
                'name': 'REN_ASSERT',
                'value': 1
            },
            {
                'name': 'REN_DEASSERT_GTL',
                'value': 2
            },
            {
                'name': 'REN_ASSERT_ADDRESS',
                'value': 3
            },
            {
                'name': 'REN_ASSERT_LLO',
                'value': 4
            },
            {
                'name': 'REN_ASSERT_ADDRESS_LLO',
                'value': 5
            },
            {
                'name': 'REN_ADDRESS_GTL',
                'value': 6
            }
        ]
    },
    'GpibHighSpeedCableLen': {
        'values': [
            {
                'documentation': {
                    'description': 'Not implemented'
                },
                'name': 'HS488_NIMPL',
                'value': -1
            },
            {
                'documentation': {
                    'description': 'Disabled'
                },
                'name': 'HS488_DISABLED',
                'value': 0
            }
        ]
    },
    'IoProt': {
        'values': [
            {
                'documentation': {
                    'description': 'Normal protocol (meaning depends on interface type)'
                },
                'name': 'PROT_NORMAL',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Fast Data Channel (requires FDC-capable device)'
                },
                'name': 'PROT_FDC',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'High-Speed 488 transfers (valid for GPIB only)'
                },
                'name': 'PROT_HS488',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Use 488.2 commands for a Serial or Ethernet device (valid for ASRL, TCPIP, and USB only)'
                },
                'name': 'PROT_4882_STRS',
                'value': 4
            },
            {
                'documentation': {
                    'description': 'Vendor-specific transfers (valid for USB-TMC only)'
                },
                'name': 'PROT_USBTMC_VENDOR',
                'value': 5
            }
        ]
    },
    'LineState': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that the line is currently asserted (for viGetAttribute) or should be asserted (for viSetAttribute)'
                },
                'name': 'ASSERTED',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Specifies that the line is currently unasserted (for viGetAttribute) or should be unasserted (for viSetAttribute)'
                },
                'name': 'UNASSERTED',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that the state of the line is currently unknown'
                },
                'name': 'UNKNOWN',
                'value': -1
            }
        ]
    },
    'LockState': {
        'values': [
            {
                'documentation': {
                    'description': 'The resource is not currently locked'
                },
                'name': 'NO_LOCK',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'The resource has an exclusive lock (one session only)'
                },
                'name': 'EXCLUSIVE_LOCK',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'The resource has a lock that can be shared by multiple sessions'
                },
                'name': 'SHARED_LOCK',
                'value': 2
            }
        ]
    },
    'MemSpace': {
        'values': [
            {
                'documentation': {
                    'description': 'Device has memory in A16 space only'
                },
                'name': 'A16_SPACE',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Device has memory in A24 space (for a VXI device, this is in addition to the A16 registers)'
                },
                'name': 'A24_SPACE',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Device has memory in A32 space (for a VXI device, this is in addition to the A16 registers)'
                },
                'name': 'A32_SPACE',
                'value': 3
            }
        ]
    },
    'PxiMemType': {
        'values': [
            {
                'documentation': {
                    'description': 'The device has no address requirements in this space'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'The device has memory address requirements in this space'
                },
                'name': 'MEM',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'The device has I/O address requirements in this space'
                },
                'name': 'IO',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'The device has configuration registers in this space'
                },
                'name': 'CFG',
                'value': 3
            }
        ]
    },
    'RdOperMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Flushes formatted input buffer after each read operation'
                },
                'name': 'ON_ACCESS',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Disables flushing of the formatted input buffer'
                },
                'name': 'DISABLE',
                'value': 3
            }
        ]
    },
    'TmoValue': {
        'generate-mappings': True,
        'values': [
            {
                'documentation': {
                    'description': 'Specifies never to wait for the device to respond'
                },
                'name': 'IMMEDIATE',
                'value': '0x0'
            },
            {
                'documentation': {
                    'description': 'Specifies never to timeout (disables the timeout mechanism)'
                },
                'name': 'INFINITE',
                'value': '0xFFFFFFFF'
            }
        ]
    },
    'TrigId': {
        'values': [
            {
                'documentation': {
                    'description': 'Selects software (Word Serial) triggering'
                },
                'name': 'SW',
                'value': -1
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 0'
                },
                'name': 'TTL0',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 1'
                },
                'name': 'TTL1',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 2'
                },
                'name': 'TTL2',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 3'
                },
                'name': 'TTL3',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 4'
                },
                'name': 'TTL4',
                'value': 4
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 5'
                },
                'name': 'TTL5',
                'value': 5
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 6'
                },
                'name': 'TTL6',
                'value': 6
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on TTL line 7'
                },
                'name': 'TTL7',
                'value': 7
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on ECL line 0'
                },
                'name': 'ECL0',
                'value': 8
            },
            {
                'documentation': {
                    'description': 'Selects hardware triggering on ECL line 1'
                },
                'name': 'ECL1',
                'value': 9
            }
        ]
    },
    'TriggerLine': {
        'values': [
            {
                'name': 'ALL',
                'value': -2
            },
            {
                'name': 'SW',
                'value': -1
            },
            {
                'name': 'TTL0',
                'value': 0
            },
            {
                'name': 'TTL1',
                'value': 1
            },
            {
                'name': 'TTL2',
                'value': 2
            },
            {
                'name': 'TTL3',
                'value': 3
            },
            {
                'name': 'TTL4',
                'value': 4
            },
            {
                'name': 'TTL5',
                'value': 5
            },
            {
                'name': 'TTL6',
                'value': 6
            },
            {
                'name': 'TTL7',
                'value': 7
            },
            {
                'name': 'ECL0',
                'value': 8
            },
            {
                'name': 'ECL1',
                'value': 9
            },
            {
                'name': 'ECL2',
                'value': 10
            },
            {
                'name': 'ECL3',
                'value': 11
            },
            {
                'name': 'ECL4',
                'value': 12
            },
            {
                'name': 'ECL5',
                'value': 13
            },
            {
                'name': 'STAR_SLOT1',
                'value': 14
            },
            {
                'name': 'STAR_SLOT2',
                'value': 15
            },
            {
                'name': 'STAR_SLOT3',
                'value': 16
            },
            {
                'name': 'STAR_SLOT4',
                'value': 17
            },
            {
                'name': 'STAR_SLOT5',
                'value': 18
            },
            {
                'name': 'STAR_SLOT6',
                'value': 19
            },
            {
                'name': 'STAR_SLOT7',
                'value': 20
            },
            {
                'name': 'STAR_SLOT8',
                'value': 21
            },
            {
                'name': 'STAR_SLOT9',
                'value': 22
            },
            {
                'name': 'STAR_SLOT10',
                'value': 23
            },
            {
                'name': 'STAR_SLOT11',
                'value': 24
            },
            {
                'name': 'STAR_SLOT12',
                'value': 25
            },
            {
                'name': 'STAR_INSTR',
                'value': 26
            },
            {
                'name': 'PANEL_IN',
                'value': 27
            },
            {
                'name': 'PANEL_OUT',
                'value': 28
            },
            {
                'name': 'STAR_VXI0',
                'value': 29
            },
            {
                'name': 'STAR_VXI1',
                'value': 30
            },
            {
                'name': 'STAR_VXI2',
                'value': 31
            },
            {
                'name': 'TTL8',
                'value': 32
            },
            {
                'name': 'TTL9',
                'value': 33
            },
            {
                'name': 'TTL10',
                'value': 34
            },
            {
                'name': 'TTL11',
                'value': 35
            }
        ]
    },
    'TriggerProtocol': {
        'values': [
            {
                'name': 'PROT_DEFAULT',
                'value': 0
            },
            {
                'name': 'PROT_OFF',
                'value': 1
            },
            {
                'name': 'PROT_ON',
                'value': 2
            },
            {
                'name': 'PROT_SYNC',
                'value': 5
            },
            {
                'name': 'PROT_RESERVE',
                'value': 6
            },
            {
                'name': 'PROT_UNRESERVE',
                'value': 7
            }
        ]
    },
    'UsbEndIn': {
        'values': [
            {
                'documentation': {
                    'description': 'Specifies that short packets are ignored for read operations, so reads will not terminate until all of the requested data is received (or an error occurs)'
                },
                'name': 'NONE',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Specifies that the read operation will terminate on a short packet; use this if the device will terminate all read transfers with a short packet, including sending a zero (short) packet when the last data packet is full'
                },
                'name': 'SHORT',
                'value': 4
            },
            {
                'documentation': {
                    'description': 'Specifies that the read operation will terminate on a short packet or when it receives the requested count of data bytes; use this if the device does not send zero packets'
                },
                'name': 'SHORT_OR_COUNT',
                'value': 5
            }
        ]
    },
    'UsbPipeState': {
        'values': [
            {
                'documentation': {
                    'description': 'Unknown pipe state'
                },
                'name': 'STATE_UNKNOWN',
                'value': -1
            },
            {
                'documentation': {
                    'description': 'Pipe ready'
                },
                'name': 'READY',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'Pipe stalled'
                },
                'name': 'STALLED',
                'value': 1
            }
        ]
    },
    'VxiCmdType': {
        'values': [
            {
                'name': 'VXI_RESP16',
                'value': 2
            },
            {
                'name': 'VXI_RESP32',
                'value': 4
            },
            {
                'name': 'VXI_CMD16',
                'value': 512
            },
            {
                'name': 'VXI_CMD16_RESP16',
                'value': 514
            },
            {
                'name': 'VXI_CMD32',
                'value': 1024
            },
            {
                'name': 'VXI_CMD32_RESP16',
                'value': 1026
            },
            {
                'name': 'VXI_CMD32_RESP32',
                'value': 1028
            }
        ]
    },
    'VxiDevClass': {
        'values': [
            {
                'documentation': {
                    'description': 'The VXI device is of type Memory class and supports register-based accesses'
                },
                'name': 'MEMORY',
                'value': 0
            },
            {
                'documentation': {
                    'description': 'The VXI device is of type Extended class and supports register-based accesses'
                },
                'name': 'EXTENDED',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'The VXI device is of type Message class and supports both register-based and message-based accesses'
                },
                'name': 'MESSAGE',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'The VXI device is of type Register class and supports register-based accesses'
                },
                'name': 'REGISTER',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'The type of the VXI or VME device is unknown, but it supports register-based accesses'
                },
                'name': 'OTHER',
                'value': 4
            }
        ]
    },
    'WinAccess': {
        'values': [
            {
                'documentation': {
                    'description': 'Window is not currently mapped'
                },
                'name': 'NMAPPED',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Low level accesses must use the viPeekXX/viPokeXX operations'
                },
                'name': 'USE_OPERS',
                'value': 2
            },
            {
                'documentation': {
                    'description': 'Low level accesses can dereference the address pointer directly'
                },
                'name': 'DEREF_ADDR',
                'value': 3
            },
            {
                'documentation': {
                    'description': 'Low level accesses can dereference the address pointer; byte-swapping is required'
                },
                'name': 'DEREF_ADDR_BYTE_SWAP',
                'value': 4
            }
        ]
    },
    'WrOperMode': {
        'values': [
            {
                'documentation': {
                    'description': 'Flushes formatted output buffer after each write operation'
                },
                'name': 'ON_ACCESS',
                'value': 1
            },
            {
                'documentation': {
                    'description': 'Flushes formatted output buffer only when it becomes full'
                },
                'name': 'WHEN_FULL',
                'value': 2
            }
        ]
    }
}
