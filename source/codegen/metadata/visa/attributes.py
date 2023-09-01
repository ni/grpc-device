attributes = {
    -1073807359: {
        'access': 'read only',
        'documentation': {
            'description': " This attribute specifies the resource class (for example, 'INSTR') as defined by the canonical resource name. "
        },
        'name': 'RSRC_CLASS',
        'type': 'ViString'
    },
    -1073807358: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the unique identifier for a resource compliant with the address structure shown in the following table.  Optional string segments are shown in square brackets. Interface            Syntax GPIB INSTR           GPIB[board]::primary address[::secondary address][::INSTR] GPIB INTFC           GPIB[board]::INTFC GPIB SERVANT         GPIB[board]::SERVANT GPIB-VXI INSTR       GPIB-VXI[board]::VXI logical address[::INSTR] GPIB-VXI BACKPLANE   GPIB-VXI[board][::mainframe logical address]::BACKPLANE GPIB-VXI MEMACC      GPIB-VXI[board]::MEMACC PXI INSTR            PXI[bus]::device[::function][::INSTR] PXI INSTR            PXI[interface]::[bus-]device[.function][::INSTR] PXI BACKPLANE        PXI[interface]::chassis::BACKPLANE PXI MEMACC           PXI[interface]::MEMACC Serial INSTR         ASRL[board][::INSTR] TCPIP INSTR          TCPIP[board]::host address[::LAN device name][::INSTR] TCPIP SOCKET         TCPIP[board]::host address::port::SOCKET VXI INSTR            VXI[board]::VXI logical address[::INSTR] VXI BACKPLANE        VXI[board][::mainframe logical address]::BACKPLANE VXI MEMACC           VXI[board]::MEMACC VXI SERVANT          VXI[board]::SERVANT USB INSTR            USB[board]::vendor id::product id::serial number[::interface number][::INSTR] USB RAW              USB[board]::vendor id::product id::serial number[::interface number]::RAW FIREWIRE INSTR       FIREWIRE[board]::vendor id::chip id::INSTR Remote Access        visa://hostname[:port]/resource '
        },
        'name': 'RSRC_NAME',
        'type': 'ViString'
    },
    -1073807246: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is a human-readable string representation of the local controller associated with this session. '
        },
        'name': 'MANF_NAME',
        'type': 'ViString'
    },
    -1073807241: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is a human-readable string representation of the device model. '
        },
        'name': 'MODEL_NAME',
        'type': 'ViString'
    },
    -1073807127: {
        'access': 'read only',
        'documentation': {
            'description': ' Human-readable text describing the given interface. '
        },
        'name': 'INTF_INST_NAME',
        'type': 'ViString'
    },
    -1073806988: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the name of the manufacturer that created the VISA implementation. '
        },
        'name': 'RSRC_MANF_NAME',
        'type': 'ViString'
    },
    -1073806955: {
        'access': 'read only',
        'documentation': {
            'description': ' This is the TCPIP address of the device to which the session is connected. This string is formatted in dot notation. '
        },
        'name': 'TCPIP_ADDR',
        'type': 'ViString'
    },
    -1073806954: {
        'access': 'read only',
        'documentation': {
            'description': ' This specifies the host name of the device. If no host name is available, this attribute returns an empty string. '
        },
        'name': 'TCPIP_HOSTNAME',
        'type': 'ViString'
    },
    -1073806951: {
        'access': 'read only',
        'documentation': {
            'description': ' This specifies the LAN device name used by the VXI-11 protocol during connection. This attribute is valid only on TCPIP INSTR sessions. '
        },
        'name': 'TCPIP_DEVICE_NAME',
        'type': 'ViString'
    },
    -1073806944: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the USB serial number of this device. '
        },
        'name': 'USB_SERIAL_NUM',
        'type': 'ViString'
    },
    -1073806841: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the slot path of this device. '
        },
        'name': 'PXI_SLOTPATH',
        'type': 'ViString'
    },
    -1073790910: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the name of the operation generating this event. This is valid for the VI_EVENT_IO_COMPLETION and VI_EVENT_EXCEPTION events. '
        },
        'name': 'OPER_NAME',
        'type': 'ViString'
    },
    -1073790568: {
        'access': 'read only',
        'documentation': {
            'description': ' This is the TCP/IP address of the device from which the session received a connection. '
        },
        'name': 'RECV_TCPIP_ADDR',
        'type': 'ViString'
    },
    -1073790543: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the actual received data from the USB Interrupt. The passed in data buffer must be of size at least equal to the Usb Received Interrupt Size Attribute (VI_ATTR_USB_RECV_INTR_SIZE). This is valid for the VI_EVENT_USB_INTR event. '
        },
        'name': 'USB_RECV_INTR_DATA',
        'type': 'ViUInt8 []'
    },
    1073676291: {
        'access': 'read only',
        'documentation': {
            'description': ' This attributes returns the implementation version of the object. The version value has a hexadecimal format 0xXXXYYYZZ, where XXX is the major version, YYY is the minor version, and ZZ is the subminor version. The subminor version is usually 0 for releases. Other values are used to indicate a patch or beta version. '
        },
        'name': 'RSRC_IMPL_VERSION',
        'type': 'ViVersion'
    },
    1073676292: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute indicates the current locking state of the resource. The resource can be unlocked, locked with an exclusive lock, or locked with a shared lock. '
        },
        'enum': 'LockState',
        'name': 'RSRC_LOCK_STATE',
        'type': 'ViAccessMode'
    },
    1073676293: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the maximum number of events that can be queued at any time on the given session. Events that occur after the queue has become full will be discarded. This is a Read/Write attribute until the first time viEnableEvent() is called on a session. Thereafter, this attribute is Read Only. '
        },
        'name': 'MAX_QUEUE_LENGTH',
        'type': 'ViUInt32'
    },
    1073676295: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute value is the data used privately by the application for a particular session. This data is not used by VISA for any purposes. It is provided to the application for its own use. '
        },
        'name': 'USER_DATA',
        'type': 'ViAddr'
    },
    1073676301: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute determines which FDC channel will be used to transfer the buffer. '
        },
        'name': 'FDC_CHNL',
        'type': 'ViUInt16'
    },
    1073676303: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies which FDC mode to use (either normal or stream mode). '
        },
        'enum': 'FdcMode',
        'name': 'FDC_MODE',
        'type': 'ViUInt16'
    },
    1073676307: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies specifies whether to use a channel pair (VI_TRUE) or a single channel (VI_FLASE) for transferring data. '
        },
        'name': 'FDC_USE_PAIR',
        'type': 'ViBoolean'
    },
    1073676310: {
        'access': 'read-write',
        'documentation': {
            'description': " This attribute specifies whether to assert END during the transfer of the last byte of the buffer. This attribute is relevant only in viWrite and related operations. On Serial INSTR sessions, if this attribute is set to VI_FALSE, the write will transmit the exact contents of the user buffer, without modifying it and without appending anything to the data being written. If this attribute is set to VI_TRUE, VISA will perform the behavior described in VI_ATTR_ASRL_END_OUT. On GPIB, VXI, GPIB-VXI, TCP/IP INSTR, and USB INSTR sessions, if this attribute is set to VI_TRUE, VISA will include the 488.2 defined 'end of message' terminator. "
        },
        'name': 'SEND_END_EN',
        'type': 'ViBoolean'
    },
    1073676312: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute represents the termination character. When the termination character is read and VI_ATTR_TERMCHAR_EN is enabled during a read operation, the read operation terminates. '
        },
        'name': 'TERMCHAR',
        'type': 'ViUInt8'
    },
    1073676314: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the minimum timeout value to use (in milliseconds) when accessing the device associated with the given session. A timeout value of VI_TMO_IMMEDIATE means that operations should never wait for the device to respond. A timeout value of VI_TMO_INFINITE disables the timeout mechanism. ',
            'note': 'that the actual timeout used may be higher than the one requested.'
        },
        'enum': 'TmoValue',
        'name': 'TMO_VALUE',
        'type': 'ViUInt32'
    },
    1073676315: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether the device is to be readdressed before every transfer. '
        },
        'name': 'GPIB_READDR_EN',
        'type': 'ViBoolean'
    },
    1073676316: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies which protocol to use. In VXI systems, for example, you can choose between normal word serial or Fast Data Channel (FDC). In GPIB, you can choose between normal and high-speed (HS488) data transfers. In Serial, you can choose between normal and 488.2 modes.  The 488.2 mode adds the ability to use viAssertTrigger(), viReadSTB(), and viClear() by sending the corresponding 488.2-defined command strings. '
        },
        'enum': 'IoProt',
        'name': 'IO_PROT',
        'type': 'ViUInt16'
    },
    1073676318: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether I/O accesses should use DMA or PIO (Programmed I/O). '
        },
        'name': 'DMA_ALLOW_EN',
        'type': 'ViBoolean'
    },
    1073676321: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is the baud rate of the interface. It is represented as an unsigned 32-bit integer so that any baud rate can be used, but it usually requires a commonly used rate such as 300, 1200, 2400, or 9600 baud. '
        },
        'name': 'ASRL_BAUD',
        'type': 'ViUInt32'
    },
    1073676322: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is the number of data bits contained in each frame (from 5 to 8). The data bits for each frame are located in the low-order bits of every byte stored in memory. '
        },
        'name': 'ASRL_DATA_BITS',
        'type': 'ViUInt16'
    },
    1073676323: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is the parity used with every frame transmitted and received. '
        },
        'enum': 'AsrlParity',
        'name': 'ASRL_PARITY',
        'type': 'ViUInt16'
    },
    1073676324: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is the number of stop bits used to indicate the end of a frame. '
        },
        'enum': 'AsrlStop',
        'name': 'ASRL_STOP_BITS',
        'type': 'ViUInt16'
    },
    1073676325: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute indicates the type of flow control used by the transfer mechanism. '
        },
        'enum': 'AsrlFlow',
        'name': 'ASRL_FLOW_CNTRL',
        'type': 'ViUInt16'
    },
    1073676330: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the operational mode of the formatted I/O read buffer. When the operational mode is set to VI_FLUSH_DISABLE (default), the buffer is flushed only on explicit calls to viFlush(). If the operational mode is set to VI_FLUSH_ON_ACCESS, the buffer is flushed every time a viScanf() operation completes. '
        },
        'enum': 'RdOperMode',
        'name': 'RD_BUF_OPER_MODE',
        'type': 'ViUInt16'
    },
    1073676331: {
        'access': 'read only',
        'documentation': {
            'description': ' This is the current size of the formatted I/O input buffer for this session. '
        },
        'name': 'RD_BUF_SIZE',
        'type': 'ViUInt32'
    },
    1073676333: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the operational mode of the formatted I/O write buffer. When the operational mode is set to VI_FLUSH_WHEN_FULL (default), the buffer is flushed when an END indicator is written to the buffer, or when the buffer fills up. If the operational mode is set to VI_FLUSH_ON_ACCESS, the write buffer is flushed under the same conditions, and also every time a viPrintf() operation completes. '
        },
        'enum': 'WrOperMode',
        'name': 'WR_BUF_OPER_MODE',
        'type': 'ViUInt16'
    },
    1073676334: {
        'access': 'read only',
        'documentation': {
            'description': ' This is the current size of the formatted I/O output buffer for this session. '
        },
        'name': 'WR_BUF_SIZE',
        'type': 'ViUInt32'
    },
    1073676342: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is relevant only in viRead and related operations. For all session types on which this attribute is supported, if this attribute is set to VI_TRUE, read will not terminate due to an END condition. However, a read may still terminate successfully if VI_ATTR_TERMCHAR_EN is set to VI_TRUE. Otherwise, read will not terminate until all of the requested data is received (or an error occurs). On Serial INSTR sessions, if this attribute is set to VI_FALSE, VISA will perform the behavior described in VI_ATTR_ASRL_END_IN. On USB RAW sessions, if this attribute is set to VI_FALSE, VISA will perform the behavior described in VI_ATTR_USB_END_IN. On TCP/IP SOCKET sessions, if this attribute is set to VI_FALSE, if NI-VISA reads some data and then detects a pause in the arrival of data packets, it will terminate the read operation. On TCP/IP SOCKET sessions, this attribute defaults to VI_TRUE in NI-VISA. On VXI INSTR sessions, if this attribute is set to VI_FALSE, the END bit terminates read operations. '
        },
        'name': 'SUPPRESS_END_EN',
        'type': 'ViBoolean'
    },
    1073676344: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute determines whether the read operation should terminate when a termination character is received. '
        },
        'name': 'TERMCHAR_EN',
        'type': 'ViBoolean'
    },
    1073676345: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the address modifier to be used in high-level access operations, such as viOutXX() and viMoveOutXX(), when writing to the destination. '
        },
        'enum': 'AccessPriv',
        'name': 'DEST_ACCESS_PRIV',
        'type': 'ViUInt16'
    },
    1073676346: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the byte order to be used in high-level access operations, such as viOutXX() and viMoveOutXX(), when writing to the destination. '
        },
        'enum': 'ByteOrder',
        'name': 'DEST_BYTE_ORDER',
        'type': 'ViUInt16'
    },
    1073676348: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the address modifier to be used in high-level access operations, such as viInXX() and viMoveInXX(), when reading from the source. '
        },
        'enum': 'AccessPriv',
        'name': 'SRC_ACCESS_PRIV',
        'type': 'ViUInt16'
    },
    1073676349: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the byte order to be used in high-level access operations, such as viInXX() and viMoveInXX(), when reading from the source. '
        },
        'enum': 'ByteOrder',
        'name': 'SRC_BYTE_ORDER',
        'type': 'ViUInt16'
    },
    1073676352: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is used in the viMoveInXX() operations to specify by how many elements the source offset is to be incremented after every transfer. The default value of this attribute is 1 (that is, the source address will be incremented by the access width after each transfer), and the viMoveInXX() operations move from consecutive elements. If this attribute is set to 0, the viMoveInXX() operations will always read from the same element, essentially treating the source as a FIFO register. '
        },
        'name': 'SRC_INCREMENT',
        'type': 'ViInt32'
    },
    1073676353: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is used in the viMoveOutXX() operations to specify by how many elements the destination offset is to be incremented after every transfer. The default value of this attribute is 1 (that is, the destination address will be incremented by the access width after each transfer), and the viMoveOutXX() operations move into consecutive elements. If this attribute is set to 0, the viMoveOutXX() operations will always write to the same element, essentially treating the destination as a FIFO register. '
        },
        'name': 'DEST_INCREMENT',
        'type': 'ViInt32'
    },
    1073676357: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the address modifier to be used in low-level access operations, such as viMapAddress(), viPeekXX() and viPokeXX(), when accessing the mapped window. '
        },
        'enum': 'AccessPriv',
        'name': 'WIN_ACCESS_PRIV',
        'type': 'ViUInt16'
    },
    1073676359: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the byte order to be used in low-level access operations, such as viMapAddress(), viPeekXX() and viPokeXX(), when accessing the mapped window. '
        },
        'enum': 'ByteOrder',
        'name': 'WIN_BYTE_ORDER',
        'type': 'ViUInt16'
    },
    1073676375: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the GPIB ATN (ATentioN) interface line. '
        },
        'enum': 'LineState',
        'name': 'GPIB_ATN_STATE',
        'type': 'ViInt16'
    },
    1073676380: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows whether the specified GPIB interface is currently addressed to talk or listen, or is not addressed. '
        },
        'enum': 'GpibAddr',
        'name': 'GPIB_ADDR_STATE',
        'type': 'ViUInt16'
    },
    1073676382: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows whether the specified GPIB interface is currently CIC (Controller In Charge). '
        },
        'name': 'GPIB_CIC_STATE',
        'type': 'ViBoolean'
    },
    1073676386: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the GPIB NDAC (Not Data ACcepted) interface line. '
        },
        'enum': 'LineState',
        'name': 'GPIB_NDAC_STATE',
        'type': 'ViInt16'
    },
    1073676391: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the GPIB SRQ (Service ReQuest) interface line. '
        },
        'enum': 'LineState',
        'name': 'GPIB_SRQ_STATE',
        'type': 'ViInt16'
    },
    1073676392: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute shows whether the specified GPIB interface is currently the system controller. '
        },
        'name': 'GPIB_SYS_CNTRL_STATE',
        'type': 'ViBoolean'
    },
    1073676393: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the total number of meters of GPIB cable used in the specified GPIB interface. '
        },
        'enum': 'GpibHighSpeedCableLen',
        'name': 'GPIB_HS488_CBL_LEN',
        'type': 'ViInt16'
    },
    1073676395: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is the unique logical address of the commander of the VXI device used by the given session. '
        },
        'name': 'CMDR_LA',
        'type': 'ViInt16'
    },
    1073676396: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute represents the VXI-defined device class to which the resource belongs. '
        },
        'enum': 'VxiDevClass',
        'name': 'VXI_DEV_CLASS',
        'type': 'ViUInt16'
    },
    1073676400: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the lowest logical address in the mainframe. If the logical address is not known, VI_UNKNOWN_LA is returned. '
        },
        'name': 'MAINFRAME_LA',
        'type': 'ViInt16'
    },
    1073676427: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the VXI/VME interrupt lines. This is a bit vector with bits 0-6 corresponding to interrupt lines 1-7. '
        },
        'name': 'VXI_VME_INTR_STATUS',
        'type': 'ViUInt16'
    },
    1073676429: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the VXI trigger lines. This is a bit vector with bits 0-9 corresponding to VI_TRIG_TTL0 through VI_TRIG_ECL1. '
        },
        'name': 'VXI_TRIG_STATUS',
        'type': 'ViUInt32'
    },
    1073676436: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the VXI SYSFAIL (SYStem FAILure) backplane line. '
        },
        'enum': 'LineState',
        'name': 'VXI_VME_SYSFAIL_STATE',
        'type': 'ViInt16'
    },
    1073676440: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the base address of the interface bus to which this window is mapped. If the value of VI_ATTR_WIN_ACCESS is VI_NMAPPED, the value of this attribute is meaningless. '
        },
        'name': 'WIN_BASE_ADDR',
        'type': 'ViBusAddress'
    },
    1073676442: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the size of the region mapped to this window. If the value of VI_ATTR_WIN_ACCESS is VI_NMAPPED, the value of this attribute is meaningless. '
        },
        'name': 'WIN_SIZE',
        'type': 'ViBusSize'
    },
    1073676460: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the number of bytes available in the global receive buffer. '
        },
        'name': 'ASRL_AVAIL_NUM',
        'type': 'ViUInt32'
    },
    1073676461: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the base address of the device in VXIbus memory address space. This base address is applicable to A24 or A32 address space. If the value of VI_ATTR_MEM_SPACE is VI_A16_SPACE, the value of this attribute is meaningless for VXI devices. '
        },
        'name': 'MEM_BASE',
        'type': 'ViBusAddress'
    },
    1073676462: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the Clear To Send (CTS) input signal. '
        },
        'enum': 'LineState',
        'name': 'ASRL_CTS_STATE',
        'type': 'ViInt16'
    },
    1073676463: {
        'access': 'read-write',
        'documentation': {
            'description': " This attribute represents the current state of the Data Carrier Detect (DCD) input signal. The DCD signal is often used by modems to indicate the detection of a carrier (remote modem) on the telephone line. The DCD signal is also known as 'Receive Line Signal Detect (RLSD).' This attribute is Read Only except when the VI_ATTR_ASRL_WIRE_MODE attribute is set to VI_ASRL_WIRE_232_DCE, or VI_ASRL_WIRE_232_AUTO with the hardware currently in the DCE state. "
        },
        'enum': 'LineState',
        'name': 'ASRL_DCD_STATE',
        'type': 'ViInt16'
    },
    1073676464: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute indicates the method used to terminate write operations. '
        },
        'name': 'ASRL_DISCARD_NULL',
        'type': 'ViBoolean'
    },
    1073676465: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the Data Set Ready (DSR) input signal. '
        },
        'enum': 'LineState',
        'name': 'ASRL_DSR_STATE',
        'type': 'ViInt16'
    },
    1073676466: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is used to manually assert or unassert the Data Terminal Ready (DTR) output signal. '
        },
        'enum': 'LineState',
        'name': 'ASRL_DTR_STATE',
        'type': 'ViInt16'
    },
    1073676467: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute indicates the method used to terminate read operations. '
        },
        'enum': 'AsrlEndIn',
        'name': 'ASRL_END_IN',
        'type': 'ViUInt16'
    },
    1073676468: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute indicates the method used to terminate write operations. '
        },
        'enum': 'AsrlEndOut',
        'name': 'ASRL_END_OUT',
        'type': 'ViUInt16'
    },
    1073676478: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the character to be placed in the user buffer when an error is detected (such as parity error). '
        },
        'name': 'ASRL_REPLACE_CHAR',
        'type': 'ViUInt8'
    },
    1073676479: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute represents the current state of the Ring Indicator (RI) input signal. The RI signal is often used by modems to indicate that the telephone line is ringing. This attribute is Read Only except when the VI_ATTR_ASRL_WIRE_MODE attribute is set to VI_ASRL_WIRE_232_DCE, or VI_ASRL_WIRE_232_AUTO with the hardware currently in the DCE state. '
        },
        'enum': 'LineState',
        'name': 'ASRL_RI_STATE',
        'type': 'ViInt16'
    },
    1073676480: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is used to manually assert or unassert the Request To Send (RTS) output signal. When the VI_ATTR_ASRL_FLOW_CNTRL attribute is set to VI_ASRL_FLOW_RTS_CTS, this attribute is ignored when changed, but can be read to determine whether the background flow control is asserting or unasserting the signal. '
        },
        'enum': 'LineState',
        'name': 'ASRL_RTS_STATE',
        'type': 'ViInt16'
    },
    1073676481: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the character used to restart data flow when the flow control is set to VI_ASRL_FLOW_XON_XOFF. '
        },
        'name': 'ASRL_XON_CHAR',
        'type': 'ViUInt8'
    },
    1073676482: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the character used to temporarily pause data flow when the flow control is set to VI_ASRL_FLOW_XON_XOFF. '
        },
        'name': 'ASRL_XOFF_CHAR',
        'type': 'ViUInt8'
    },
    1073676483: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the modes in which the current window may be accessed. If VI_NMAPPED, the window is not currently mapped. If VI_USE_OPERS, the window can be accessed through the viPeekXX() and viPokeXX() operations only. VI_DEREF_ADDR specifies that you can either use operations or directly dereference the mapped address as a pointer. VI_DEREF_ADDR_BYTE_SWAP specifies that you can either use operations or dereference the mapped address as a pointer. If the mapped address is dereferenced as a pointer, the host byte order does not match the device byte order, byte-swapping is required. '
        },
        'enum': 'WinAccess',
        'name': 'WIN_ACCESS',
        'type': 'ViUInt16'
    },
    1073676484: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the session of the Resource Manager that was used to open this session. '
        },
        'name': 'RM_SESSION',
        'type': 'ViSession'
    },
    1073676501: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the logical address of the VXI or VME device used by the given session. For a VME device, the logical address is actually a pseudo-address in the range 256 to 511. For MEMACC sessions, this is the logical address of the local controller. '
        },
        'name': 'VXI_LA',
        'type': 'ViInt16'
    },
    1073676505: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is the manufacturer identification number of the device. '
        },
        'name': 'MANF_ID',
        'type': 'ViUInt16'
    },
    1073676509: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the size of memory requested by the device in VXIbus address space. If the value of VI_ATTR_MEM_SPACE is VI_A16_SPACE, the value of this attribute is meaningless for VXI devices. '
        },
        'name': 'MEM_SIZE',
        'type': 'ViBusSize'
    },
    1073676510: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the VXIbus address space used by the device. The three types are A16 only, A16/A24, or A16/A32 memory address space. '
        },
        'enum': 'MemSpace',
        'name': 'MEM_SPACE',
        'type': 'ViUInt16'
    },
    1073676511: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the model code for the device. '
        },
        'name': 'MODEL_CODE',
        'type': 'ViUInt16'
    },
    1073676520: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the physical slot location of the device. If the slot number is not known, VI_UNKNOWN_SLOT is returned. '
        },
        'name': 'SLOT',
        'type': 'ViInt16'
    },
    1073676544: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies whether the device associated with this session is an immediate servant of the controller running VISA. '
        },
        'name': 'IMMEDIATE_SERV',
        'type': 'ViBoolean'
    },
    1073676545: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the board number of the GPIB board to which the GPIB-VXI is attached. '
        },
        'name': 'INTF_PARENT_NUM',
        'type': 'ViUInt16'
    },
    1073676656: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute returns the VISA specification version to which the object complies. The version value has a hexadecimal format 0xXXXYYYZZ, where XXX is the major version, YYY is the minor version, and ZZ is the subminor version. The subminor version is usually 0 for the specification version. '
        },
        'name': 'RSRC_SPEC_VERSION',
        'type': 'ViVersion'
    },
    1073676657: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the interface type of the given session. '
        },
        'name': 'INTF_TYPE',
        'type': 'ViUInt16'
    },
    1073676658: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the primary address of the GPIB device used by the given session. '
        },
        'name': 'GPIB_PRIMARY_ADDR',
        'type': 'ViUInt16'
    },
    1073676659: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the secondary address of the GPIB device used by the given session. If the device does not have a secondary address, the value of this attribute will be VI_NO_SEC_ADDR. '
        },
        'name': 'GPIB_SECONDARY_ADDR',
        'type': 'ViUInt16'
    },
    1073676661: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value corresponds to the VXI manufacturer ID of the manufacturer that created the VISA implementation. '
        },
        'name': 'RSRC_MANF_ID',
        'type': 'ViUInt16'
    },
    1073676662: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the board number for the given interface. '
        },
        'name': 'INTF_NUM',
        'type': 'ViUInt16'
    },
    1073676663: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute is the identifier for the current triggering mechanism. This is a Read/Write attribute when the corresponding session is not enabled to receive trigger events. When the session is enabled to receive trigger events, this attribute is Read Only. This attribute is not available for all interfaces (such as serial). '
        },
        'enum': 'TrigId',
        'name': 'TRIG_ID',
        'type': 'ViInt16'
    },
    1073676673: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows the current state of the REN (Remote ENable) line. '
        },
        'enum': 'LineState',
        'name': 'GPIB_REN_STATE',
        'type': 'ViInt16'
    },
    1073676676: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether to unaddress the device (UNT and UNL) after each read or write operation. '
        },
        'name': 'GPIB_UNADDR_EN',
        'type': 'ViBoolean'
    },
    1073676681: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the 488 status byte of the local controller associated with this session. '
        },
        'name': 'DEV_STATUS_BYTE',
        'type': 'ViUInt8'
    },
    1073676690: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether viReadToFile() will overwrite (truncate) or append when opening a file. '
        },
        'name': 'FILE_APPEND_EN',
        'type': 'ViBoolean'
    },
    1073676692: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute shows which VXI trigger lines this implementation supports. This is a bit vector with bits 0-9 corresponding to VI_TRIG_TTL0 through VI_TRIG_ECL1. '
        },
        'name': 'VXI_TRIG_SUPPORT',
        'type': 'ViUInt32'
    },
    1073676695: {
        'access': 'read only',
        'documentation': {
            'description': ' This specifies the port number for a given TCPIP address. For a TCPIP SOCKET Resource, this is a required part of the address string. This attribute is valid only on TCPIP SOCKET sessions. '
        },
        'name': 'TCPIP_PORT',
        'type': 'ViUInt16'
    },
    1073676698: {
        'access': 'read-write',
        'documentation': {
            'description': ' The Nagle algorithm is disabled when this attribute is enabled (and vice versa). The Nagle algorithm improves network performance by buffering send data until a full-size packet can be sent. This attribute is enabled by default in VISA to verify that synchronous writes get flushed immediately. This attribute is valid only on TCPIP SOCKET sessions. '
        },
        'name': 'TCPIP_NODELAY',
        'type': 'ViBoolean'
    },
    1073676699: {
        'access': 'read-write',
        'documentation': {
            'description': ' Setting this attribute to VI_TRUE requests that a TCP/IP provider enable the use of keep-alive packets on TCP connections. After the system detects that a connection was dropped, VISA will return a lost connection error code VI_ERROR_CONN_LOST on subsequent I/O calls on the session. The time required for the system to detect that the connection was dropped is dependent on the system and is not settable. '
        },
        'name': 'TCPIP_KEEPALIVE',
        'type': 'ViBoolean'
    },
    1073676703: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies whether the device is 488.2 compliant. This attribute is valid only on VXI INSTR, GPIB-VXI INSTR, and USB INSTR sessions. '
        },
        'name': '4882_COMPLIANT',
        'type': 'ViBoolean'
    },
    1073676705: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the USB interface number used by the given session. '
        },
        'name': 'USB_INTFC_NUM',
        'type': 'ViInt16'
    },
    1073676706: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the endpoint number of the USB bulk-out or interrupt-out pipe used by the given session. This endpoint is used in viWrite and related operations. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_BULK_OUT_PIPE',
        'type': 'ViInt16'
    },
    1073676707: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the endpoint number of the USB bulk-in pipe used by the given session. This endpoint is used in viRead and related operations. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_BULK_IN_PIPE',
        'type': 'ViInt16'
    },
    1073676708: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the endpoint number of the USB interrupt-in pipe used by the given session. This endpoint is used in viEnableEvent for VI_EVENT_USB_INTR. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_INTR_IN_PIPE',
        'type': 'ViInt16'
    },
    1073676709: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the USB class used by the given session. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_CLASS',
        'type': 'ViInt16'
    },
    1073676710: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the USB subclass used by the given session. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_SUBCLASS',
        'type': 'ViInt16'
    },
    1073676711: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the USB protocol used by the given session. '
        },
        'name': 'USB_PROTOCOL',
        'type': 'ViInt16'
    },
    1073676712: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the USB alternate setting used by the given session. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_ALT_SETTING',
        'type': 'ViInt16'
    },
    1073676713: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute indicates the method used to terminate read operations. '
        },
        'enum': 'UsbEndIn',
        'name': 'USB_END_IN',
        'type': 'ViUInt16'
    },
    1073676714: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the number of interfaces supported by this USB device. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_NUM_INTFCS',
        'type': 'ViInt16'
    },
    1073676715: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the number of pipes supported by this USB interface. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_NUM_PIPES',
        'type': 'ViInt16'
    },
    1073676716: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether the USB bulk-out or interrupt-out pipe used by the given session is stalled or ready. This attribute is valid only on USB RAW sessions. '
        },
        'enum': 'UsbPipeState',
        'name': 'USB_BULK_OUT_STATUS',
        'type': 'ViInt16'
    },
    1073676717: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether the USB bulk-in pipe used by the given session is stalled or ready. This attribute is valid only on USB RAW sessions. '
        },
        'enum': 'UsbPipeState',
        'name': 'USB_BULK_IN_STATUS',
        'type': 'ViInt16'
    },
    1073676718: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies whether the USB interrupt-in pipe used by the given session is stalled or ready. This attribute is valid only on USB RAW sessions. '
        },
        'enum': 'UsbPipeState',
        'name': 'USB_INTR_IN_STATUS',
        'type': 'ViInt16'
    },
    1073676719: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the maximum size of data that will be stored by any given USB interrupt. If a USB interrupt contains more data than this size, the data in excess of this size will be lost. '
        },
        'name': 'USB_MAX_INTR_SIZE',
        'type': 'ViUInt16'
    },
    1073676720: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the endpoint address of the USB control pipe used by the given session. A value of 0 signifies that the default control pipe will be used. This endpoint is used in viUsbControlIn and viUsbControlOut operations. This attribute is valid only on USB RAW sessions. '
        },
        'name': 'USB_CTRL_PIPE',
        'type': 'ViInt16'
    },
    1073676731: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute indicates whether the port is properly connected to another port or device. This attribute is valid only with serial drivers developed by National Instruments and documented to support this feature with the corresponding National Instruments hardware. '
        },
        'name': 'ASRL_CONNECTED',
        'type': 'ViBoolean'
    },
    1073676732: {
        'access': 'read-write',
        'documentation': {
            'description': " This attribute lets you manually control the serial port's break state.  If asserted, it suspends character transmission and places the transmission line in a break state until this attribute is unasserted. If you want VISA to send a break signal after each write operation automatically, use the Break Len and ASRL End Out properties instead. "
        },
        'enum': 'LineState',
        'name': 'ASRL_BREAK_STATE',
        'type': 'ViInt16'
    },
    1073676733: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute controls the duration (in milliseconds) of the break signal asserted when ASRL End Out is set to Break(3). Valid values are 1-500. '
        },
        'name': 'ASRL_BREAK_LEN',
        'type': 'ViInt16'
    },
    1073676734: {
        'access': 'read-write',
        'documentation': {
            'description': ' If disabled (VI_FALSE), the serial port suspends transmission as if an XOFF character has been received. If enabled (VI_TRUE), it resumes transmission as if an XON character has been received.  If XON/XOFF flow control (software handshaking) is not being used, it is invalid to disable this attribute. '
        },
        'name': 'ASRL_ALLOW_TRANSMIT',
        'type': 'ViBoolean'
    },
    1073676735: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute represents the current wire/transceiver mode. For RS-485 hardware, this attribute is valid only with the RS-485 serial driver developed by National Instruments. For RS-232 hardware, the values RS232/DCE and RS232/AUTO are valid only with RS-232 serial drivers developed by National Instruments and documented to support this feature with the corresponding National Instruments hardware. When this feature is not supported, RS232/DTE is the only valid value. '
        },
        'enum': 'AsrlWireMode',
        'name': 'ASRL_WIRE_MODE',
        'type': 'ViInt16'
    },
    1073676784: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the upper 16 bits of the 48-bit destination address for a Firewire device. '
        },
        'name': 'FIREWIRE_DEST_UPPER_OFFSET',
        'type': 'ViUInt16'
    },
    1073676785: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the upper 16 bits of the 48-bit source address for a Firewire device. '
        },
        'name': 'FIREWIRE_SRC_UPPER_OFFSET',
        'type': 'ViUInt16'
    },
    1073676786: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the upper 16 bits of the 48-bit address for a Firewire device when a window is mapped. '
        },
        'name': 'FIREWIRE_WIN_UPPER_OFFSET',
        'type': 'ViUInt16'
    },
    1073676787: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the vendor identification of a Firewire device. '
        },
        'name': 'FIREWIRE_VENDOR_ID',
        'type': 'ViUInt32'
    },
    1073676788: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the lower chip ID of a Firewire device. '
        },
        'name': 'FIREWIRE_LOWER_CHIP_ID',
        'type': 'ViUInt32'
    },
    1073676789: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the upper chip ID of a Firewire device. '
        },
        'name': 'FIREWIRE_UPPER_CHIP_ID',
        'type': 'ViUInt8'
    },
    1073676801: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the device number of the PCI device used by the given session. '
        },
        'name': 'PXI_DEV_NUM',
        'type': 'ViUInt16'
    },
    1073676802: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the function number of the PCI device used by the given session. For most devices this will be 0, but a multifunction device may have a function number up to 7. The meaning of a function number other than 0 is device-specific. '
        },
        'name': 'PXI_FUNC_NUM',
        'type': 'ViUInt16'
    },
    1073676805: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the PCI bus number of this device. '
        },
        'name': 'PXI_BUS_NUM',
        'type': 'ViUInt16'
    },
    1073676806: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the PXI chassis number of this device. '
        },
        'name': 'PXI_CHASSIS',
        'type': 'ViInt16'
    },
    1073676808: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the slot number or special feature connected to the local bus left lines of this device. '
        },
        'name': 'PXI_SLOT_LBUS_LEFT',
        'type': 'ViInt16'
    },
    1073676809: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the slot number or special feature connected to the local bus right lines of this device. '
        },
        'name': 'PXI_SLOT_LBUS_RIGHT',
        'type': 'ViInt16'
    },
    1073676810: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the trigger bus number of this device. '
        },
        'name': 'PXI_TRIG_BUS',
        'type': 'ViInt16'
    },
    1073676811: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the star trigger bus number of this device. '
        },
        'name': 'PXI_STAR_TRIG_BUS',
        'type': 'ViInt16'
    },
    1073676812: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the PXI_STAR line connected to this device. '
        },
        'name': 'PXI_STAR_TRIG_LINE',
        'type': 'ViInt16'
    },
    1073676813: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the segment to use to qualify trigSrc in viMapTrigger. '
        },
        'name': 'PXI_SRC_TRIG_BUS',
        'type': 'ViInt16'
    },
    1073676814: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the segment to use to qualify trigDest in viMapTrigger. '
        },
        'name': 'PXI_DEST_TRIG_BUS',
        'type': 'ViInt16'
    },
    1073676817: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR0',
        'type': 'ViUInt16'
    },
    1073676818: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR1',
        'type': 'ViUInt16'
    },
    1073676819: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR2',
        'type': 'ViUInt16'
    },
    1073676820: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR3',
        'type': 'ViUInt16'
    },
    1073676821: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR4',
        'type': 'ViUInt16'
    },
    1073676822: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies what type of address requirements (memory or I/O) the device has for this Base Address Register. If the device does not request addresses in this space, the value will be VI_PXI_ADDR_NONE. '
        },
        'enum': 'PxiMemType',
        'name': 'PXI_MEM_TYPE_BAR5',
        'type': 'ViUInt16'
    },
    1073676833: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR0',
        'type': 'ViUInt32'
    },
    1073676834: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR1',
        'type': 'ViUInt32'
    },
    1073676835: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR2',
        'type': 'ViUInt32'
    },
    1073676836: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR3',
        'type': 'ViUInt32'
    },
    1073676837: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR4',
        'type': 'ViUInt32'
    },
    1073676838: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the system-assigned base this device uses in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. '
        },
        'name': 'PXI_MEM_BASE_BAR5',
        'type': 'ViUInt32'
    },
    1073676849: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR0',
        'type': 'ViUInt32'
    },
    1073676850: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR1',
        'type': 'ViUInt32'
    },
    1073676851: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR2',
        'type': 'ViUInt32'
    },
    1073676852: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR3',
        'type': 'ViUInt32'
    },
    1073676853: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR4',
        'type': 'ViUInt32'
    },
    1073676854: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the requested address size of this device in the given space. If the device does not request addresses in this space, the value of this attribute is meaningless. If this value cannot be safely determined, the value of this attribute will be 0xFFFFFFFF. '
        },
        'name': 'PXI_MEM_SIZE_BAR5',
        'type': 'ViUInt32'
    },
    1073676864: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies whether the device is PXI/PCI or PXI/PCI Express. '
        },
        'name': 'PXI_IS_EXPRESS',
        'type': 'ViBoolean'
    },
    1073676865: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the PCI Express link width of the PXI Express peripheral slot in which the device resides. '
        },
        'name': 'PXI_SLOT_LWIDTH',
        'type': 'ViInt16'
    },
    1073676866: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the maximum PCI Express link width of the device. '
        },
        'name': 'PXI_MAX_LWIDTH',
        'type': 'ViInt16'
    },
    1073676867: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the PCI Express link width negotiated between the PCI Express host controller and the device. '
        },
        'name': 'PXI_ACTUAL_LWIDTH',
        'type': 'ViInt16'
    },
    1073676868: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the differential star bus number of this device. A value of -1 means that the chassis is unidentified or does not have a timing slot. '
        },
        'name': 'PXI_DSTAR_BUS',
        'type': 'ViInt16'
    },
    1073676869: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies the set of differential star lines connected to this device. A value of -1 means that the chassis is unidentified or does not have a timing slot. '
        },
        'name': 'PXI_DSTAR_SET',
        'type': 'ViInt16'
    },
    1073676870: {
        'access': 'read-write',
        'documentation': {
            'description': ' Specifies whether the implementation should attempt to combine bus write transfers into a larger transfer before bursting over the PCI bus. '
        },
        'name': 'PXI_ALLOW_WRITE_COMBINE',
        'type': 'ViBoolean'
    },
    1073677056: {
        'access': 'read-write',
        'documentation': {
            'description': " This enables HiSLIP 'Overlap' mode and its value defaults to the mode suggested by the instrument on HiSLIP connection. If disabled, the connection uses 'Synchronous' mode to detect and recover from interrupted errors. If enabled, the connection uses 'Overlapped' mode to allow overlapped responses. If changed, VISA will do a Device Clear operation to change the mode. "
        },
        'name': 'TCPIP_HISLIP_OVERLAP_EN',
        'type': 'ViBoolean'
    },
    1073677057: {
        'access': 'read only',
        'documentation': {
            'description': ' This is the HiSLIP protocol version used for a particular HiSLIP connetion. Currently, HiSLIP version 1.0 would return a ViVersion value of 0x00100000. '
        },
        'name': 'TCPIP_HISLIP_VERSION',
        'type': 'ViVersion'
    },
    1073677058: {
        'access': 'read-write',
        'documentation': {
            'description': ' This is the maximum HiSLIP message size VISA will accept from a HiSLIP system in units of kilobytes (1024 bytes). This defaults to 1024 (a 1 MB maximum message size). '
        },
        'name': 'TCPIP_HISLIP_MAX_MESSAGE_KB',
        'type': 'ViUInt32'
    },
    1073677059: {
        'access': 'read only',
        'documentation': {
            'description': ' Specifies whether this resource uses the HiSLIP protocol. '
        },
        'name': 'TCPIP_IS_HISLIP',
        'type': 'ViBoolean'
    },
    1073692678: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the job ID of the asynchronous operation that has completed. This is valid for the VI_EVENT_IO_COMPLETION only. '
        },
        'name': 'JOB_ID',
        'type': 'ViJobId'
    },
    1073692688: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is the unique logical identifier for the event type of the specified event. '
        },
        'name': 'EVENT_TYPE',
        'type': 'ViEventType'
    },
    1073692689: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute is the 16-bit Status/ID value retrieved during the IACK cycle or from the Signal register. This is valid for the VI_EVENT_VXI_SIGP only. '
        },
        'name': 'SIGP_STATUS_ID',
        'type': 'ViUInt16'
    },
    1073692690: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute identifies the triggering mechanism on which the specified trigger event was received. This is valid for the VI_EVENT_TRIG only. '
        },
        'enum': 'TrigId',
        'name': 'RECV_TRIG_ID',
        'type': 'ViInt16'
    },
    1073692707: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the 32-bit status/ID retrieved during the IACK cycle. This is valid for the VI_EVENT_VXI_VME_INTR only. '
        },
        'name': 'INTR_STATUS_ID',
        'type': 'ViUInt32'
    },
    1073692709: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the return code of the operation generating this event. This is valid for the VI_EVENT_IO_COMPLETION, VI_EVENT_EXCEPTION, and VI_EVENT_USB_INTR events. '
        },
        'name': 'STATUS',
        'type': 'ViStatus'
    },
    1073692710: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the actual number of elements that were asynchronously transferred. This is valid for the VI_EVENT_IO_COMPLETION only. '
        },
        'name': 'RET_COUNT',
        'type': 'ViUInt32'
    },
    1073692711: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute contains the address of a buffer that was used in an asynchronous operation. This is valid for the VI_EVENT_IO_COMPLETION only. '
        },
        'name': 'BUFFER',
        'type': 'ViAddr'
    },
    1073692737: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the VXI interrupt level on which the interrupt was received. This is valid for the VI_EVENT_VXI_VME_INTR only. '
        },
        'name': 'RECV_INTR_LEVEL',
        'type': 'ViInt16'
    },
    1073692739: {
        'access': 'read-write',
        'documentation': {
            'description': " This attribute specifies which VXI TLL triggers have mappings. This is a bit vector where bits 0-7 represent TTL triggers 0-7 respectively. A bit value of 0 means the corresponding trigger line is unmapped, and 1 means a mapping exists. Use VI_ATTR_VXI_TRIG_DIR to set an enabled line's direction. Bits 8 and 9 are reserved for future use. This attribute only applies to VXI INSTR Resources. "
        },
        'name': 'VXI_TRIG_LINES_EN',
        'type': 'ViUInt16'
    },
    1073692740: {
        'access': 'read-write',
        'documentation': {
            'description': ' This attribute specifies the directions of the mapped TTL triggers lines. This is a bit vector where bits 0-7 represent TTL triggers 0-7 respectively. A bit value of 0 means the corresponding line is routed out of the frame, and a value of 1 means the line is routed into the frame. Lines must be enabled using VI_ATTR_VXI_TRIG_LINES_EN. Bits 8 and 9 are reserved for future use. This attribute only applies to VXI INSTR Resources. '
        },
        'name': 'VXI_TRIG_DIR',
        'type': 'ViUInt16'
    },
    1073693075: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute specifies whether the local controller has gained or lost CIC status. This is valid for the VI_EVENT_GPIB_CIC event. '
        },
        'name': 'GPIB_RECV_CIC_STATE',
        'type': 'ViBoolean'
    },
    1073693104: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the number of bytes of USB interrupt data that is stored. This is valid for the VI_EVENT_USB_INTR event. '
        },
        'name': 'USB_RECV_INTR_SIZE',
        'type': 'ViUInt16'
    },
    1073693248: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the index of the interrupt sequence that detected the interrupt condition. This is valid for the VI_EVENT_PXI_INTR event. '
        },
        'name': 'PXI_RECV_INTR_SEQ',
        'type': 'ViInt16'
    },
    1073693249: {
        'access': 'read only',
        'documentation': {
            'description': ' This attribute value is the first PXI/PCI register that was read in the successful interrupt detection sequence. This is valid for the VI_EVENT_PXI_INTR event. '
        },
        'name': 'PXI_RECV_INTR_DATA',
        'type': 'ViUInt32'
    }
}
