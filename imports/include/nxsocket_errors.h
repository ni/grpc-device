/*
   \file nxsocket_errors.h
   \brief NI-XNET BSD Socket API Errors

   Copyright (c) 2020 National Instruments Corporation.
   All rights reserved.
*/

#ifndef ___nxsocket_errors_h___
#define ___nxsocket_errors_h___


#define nxIpStackErrSuccess                                         ((int32_t)0x00000000)

/******************************************************************************
 * IP Stack Error Codes
 *****************************************************************************/

// nxIpStackErrInternalError: -13000 (0xFFFFCD38)
//
//  An internal error occurred in the NI-XNET IP Stack. Contact National
//  Instruments for support.
#define nxIpStackErrInternalError                                   ((int32_t)0xFFFFCD38)

// nxIpStackErrInvalidPropertyId: -13001 (0xFFFFCD37)
//
//  The property ID you specified is not valid.
#define nxIpStackErrInvalidPropertyId                               ((int32_t)0xFFFFCD37)

// nxIpStackErrInvalidPropertySize: -13002 (0xFFFFCD36)
//
//  The content of the property are bigger than the specified size. Be
//  sure to pass in a buffer large enough for the given property.
#define nxIpStackErrInvalidPropertySize                             ((int32_t)0xFFFFCD36)

// nxIpStackErrInvalidInterface: -13003 (0xFFFFCD35)
//
//  The specified interface name or index could not be found.
#define nxIpStackErrInvalidInterface                                ((int32_t)0xFFFFCD35)

// nxIpStackErrInvalidMtuSize: -13004 (0xFFFFCD34)
//
//  The specified MTU value is too large for the current device. Lower the
//  MTU to a value less than the maximum or set it to 0 to automatically
//  configure.
#define nxIpStackErrInvalidMtuSize                                  ((int32_t)0xFFFFCD34)

// nxIpStackErrStackIsStopping: -13005 (0xFFFFCD33)
//
//  The operation cannot be performed because the IP Stack is currently
//  shutting down.
#define nxIpStackErrStackIsStopping                                 ((int32_t)0xFFFFCD33)

// nxIpStackErrIpStackMismatch: -13006 (0xFFFFCD32)
//
//  The specified operation requires that all sockets are running on the
//  same IP Stack.
#define nxIpStackErrIpStackMismatch                                 ((int32_t)0xFFFFCD32)

// nxIpStackErrInvalidParameter: -13007 (0xFFFFCD31)
//
//  A parameter of the specified operation is either missing or otherwise
//  invalid. Refer to the NI-XNET IP Stack documentation regarding this
//  operation.
#define nxIpStackErrInvalidParameter                                ((int32_t)0xFFFFCD31)

// nxIpStackErrInvalidSocket: -13008 (0xFFFFCD30)
//
//  The specified socket could not be found.
#define nxIpStackErrInvalidSocket                                   ((int32_t)0xFFFFCD30)

// nxIpStackErrInvalidIpStack: -13009 (0xFFFFCD2F)
//
//  The specified IP Stack could not be found.
#define nxIpStackErrInvalidIpStack                                  ((int32_t)0xFFFFCD2F)

// nxIpStackErrDefaultIpStackInUse: -13010 (0xFFFFCD2E)
//
//  The default IP Stack cannot be disabled while a client is using it.
//  Disconnect all clients and retry the operation.
#define nxIpStackErrDefaultIpStackInUse                             ((int32_t)0xFFFFCD2E)

// nxIpStackErrVersionMismatch: -13011 (0xFFFFCD2D)
//
//  The IP Stack API in use does not support the version of the installed
//  driver.
#define nxIpStackErrVersionMismatch                                 ((int32_t)0xFFFFCD2D)

// nxIpStackErrBufferTooLarge: -13012 (0xFFFFCD2C)
//
//  The specified buffer is too large for the current operation. Reduce
//  the size of the buffer.
#define nxIpStackErrBufferTooLarge                                  ((int32_t)0xFFFFCD2C)

// nxIpStackErrLibraryCouldNotLoad: -13019 (0xFFFFCD25)
//
//  A shared library was unable to load a dependency. Uninstall NI-XNET
//  and then reinstall.
#define nxIpStackErrLibraryCouldNotLoad                             ((int32_t)0xFFFFCD25)

// nxIpStackErrStackAlreadyExists: -13020 (0xFFFFCD24)
//
//  An IP Stack with the specified name already exists. The name provided
//  to IP Stack create must be a system-wide unique name.
#define nxIpStackErrStackAlreadyExists                              ((int32_t)0xFFFFCD24)

// nxIpStackErrZeroSizedSocketOperationUnsupported: -13021 (0xFFFFCD23)
//
//  Sending or receiving 0 bytes over a socket is not supported.
#define nxIpStackErrZeroSizedSocketOperationUnsupported             ((int32_t)0xFFFFCD23)

// nxIpStackErrBufferInvalid: -13022 (0xFFFFCD22)
//
//  The provided buffer was either invalid or too small.
#define nxIpStackErrBufferInvalid                                   ((int32_t)0xFFFFCD22)

// nxIpStackErrErrorDescriptionTruncated: -13023 (0xFFFFCD21)
//
//  The error description was truncated because the provided buffer was
//  too small.
#define nxIpStackErrErrorDescriptionTruncated                       ((int32_t)0xFFFFCD21)

// nxIpStackErrTooManyInterfaces: -13024 (0xFFFFCD20)
//
//  The IP Stack does not support the number of virtual interfaces for
//  this configuration. Reduce the number of virtual interfaces or create
//  a second IP Stack instance.
#define nxIpStackErrTooManyInterfaces                               ((int32_t)0xFFFFCD20)

// nxIpStackErrInvalidStackName: -13025 (0xFFFFCD1F)
//
//  Ensure the stack name consists of valid characters and that the length
//  is less than or equal to 105 characters. Invalid characters include
//  forward slash (/), backslash (\), period (.), and tab (\t).
#define nxIpStackErrInvalidStackName                                ((int32_t)0xFFFFCD1F)

// nxIpStackErrTooManyIpAddresses: -13026 (0xFFFFCD1E)
//
//  The IP Stack does not support the number of IP addresses for this
//  configuration. Reduce the number of IP addresses or create a second IP
//  Stack instance.
#define nxIpStackErrTooManyIpAddresses                              ((int32_t)0xFFFFCD1E)

// nxIpStackErrInterfaceNameTooLong: -13027 (0xFFFFCD1D)
//
//  The VLAN Interface name must be 15 characters or less and unique
//  across the IP Stack. In the IP Stack configuration, ensure that VLAN
//  names are a maximum of 15 characters; and if a name is not provided
//  for a parent VLAN (therefore, automatically assigned by NI-XNET), MAC
//  names are limited to 10 characters.
#define nxIpStackErrInterfaceNameTooLong                            ((int32_t)0xFFFFCD1D)

// nxIpStackErrCannotCommunicateWithStack: -13028 (0xFFFFCD1C)
//
//  A general failure occurred while communicating with the IP Stack. This
//  can occur when OS resource limits are reached or if the IP Stack
//  encountered some other unexpected failure. Recreate the IP Stack and
//  reduce the overall load on the system. If the problem persists,
//  contact National Instruments for support.
#define nxIpStackErrCannotCommunicateWithStack                      ((int32_t)0xFFFFCD1C)

// nxIpStackErrTooManyRoutes: -13029 (0xFFFFCD1B)
//
//  The IP Stack does not support the number of routes necessary for this
//  configuration. Reduce the number of gateway addresses or other
//  configured routes.
#define nxIpStackErrTooManyRoutes                                   ((int32_t)0xFFFFCD1B)

// nxIpStackErrFormatNotSupported: -13030 (0xFFFFCD1A)
//
//  The specified format is not supported for this operation. Verify the
//  available formats in the API documentation.
#define nxIpStackErrFormatNotSupported                              ((int32_t)0xFFFFCD1A)

/******************************************************************************
 * JSON Parsing Error Codes
 *****************************************************************************/

// nxIpStackErrJsonSyntaxError: -13013 (0xFFFFCD2B)
//
//  A syntax error was encountered when parsing the IP Stack
//  configuration.
#define nxIpStackErrJsonSyntaxError                                 ((int32_t)0xFFFFCD2B)

// nxIpStackErrJsonInvalid: -13014 (0xFFFFCD2A)
//
//  An unsupported unicode sequence was encountered when parsing the IP
//  Stack configuration.
#define nxIpStackErrJsonInvalid                                     ((int32_t)0xFFFFCD2A)

// nxIpStackErrJsonGenericError: -13015 (0xFFFFCD29)
//
//  An unknown error occurred while parsing the IP Stack configuration.
#define nxIpStackErrJsonGenericError                                ((int32_t)0xFFFFCD29)

// nxIpStackErrJsonIncorrectDataType: -13016 (0xFFFFCD28)
//
//  An object in the IP Stack configuration has an unexpected data type.
//  Refer to the IP Stack configuration schema for the expected type.
#define nxIpStackErrJsonIncorrectDataType                           ((int32_t)0xFFFFCD28)

// nxIpStackErrJsonObjectMissingValue: -13017 (0xFFFFCD27)
//
//  An object in the IP Stack configuration is missing a required member.
//  Refer to the IP Stack configuration schema for the expected members.
#define nxIpStackErrJsonObjectMissingValue                          ((int32_t)0xFFFFCD27)

// nxIpStackErrJsonInvalidValue: -13018 (0xFFFFCD26)
//
//  An object in the IP Stack configuration does not match the expected
//  value. Refer to the IP Stack configuration schema for the expected
//  values.
#define nxIpStackErrJsonInvalidValue                                ((int32_t)0xFFFFCD26)

/******************************************************************************
 * POSIX Error Codes
 *****************************************************************************/

// nxIpStackErrOperationNotPermitted: -13801 (0xFFFFCA17)
//                           nxEPERM:  13801 (0x000035E9)
//
//  Operation not permitted
#define nxIpStackErrOperationNotPermitted                           ((int32_t)0xFFFFCA17)
#define nxEPERM                                                     ((int32_t)0x000035E9)

// nxIpStackErrFileNotFound: -13802 (0xFFFFCA16)
//                 nxENOENT:  13802 (0x000035EA)
//
//  No such file or directory
#define nxIpStackErrFileNotFound                                    ((int32_t)0xFFFFCA16)
#define nxENOENT                                                    ((int32_t)0x000035EA)

// nxIpStackErrNoSuchProcess: -13803 (0xFFFFCA15)
//                   nxESRCH:  13803 (0x000035EB)
//
//  No such process
#define nxIpStackErrNoSuchProcess                                   ((int32_t)0xFFFFCA15)
#define nxESRCH                                                     ((int32_t)0x000035EB)

// nxIpStackErrInterruptedCall: -13804 (0xFFFFCA14)
//                     nxEINTR:  13804 (0x000035EC)
//
//  Interrupted system call
#define nxIpStackErrInterruptedCall                                 ((int32_t)0xFFFFCA14)
#define nxEINTR                                                     ((int32_t)0x000035EC)

// nxIpStackErrIOError: -13805 (0xFFFFCA13)
//               nxEIO:  13805 (0x000035ED)
//
//  I/O Error
#define nxIpStackErrIOError                                         ((int32_t)0xFFFFCA13)
#define nxEIO                                                       ((int32_t)0x000035ED)

// nxIpStackErrNoSuchDeviceOrAddress: -13806 (0xFFFFCA12)
//                           nxENXIO:  13806 (0x000035EE)
//
//  No such device or address
#define nxIpStackErrNoSuchDeviceOrAddress                           ((int32_t)0xFFFFCA12)
#define nxENXIO                                                     ((int32_t)0x000035EE)

// nxIpStackErrArgumentListTooLong: -13807 (0xFFFFCA11)
//                         nxE2BIG:  13807 (0x000035EF)
//
//  Argument list too long
#define nxIpStackErrArgumentListTooLong                             ((int32_t)0xFFFFCA11)
#define nxE2BIG                                                     ((int32_t)0x000035EF)

// nxIpStackErrExecFormatError: -13808 (0xFFFFCA10)
//                   nxENOEXEC:  13808 (0x000035F0)
//
//  Exec format error
#define nxIpStackErrExecFormatError                                 ((int32_t)0xFFFFCA10)
#define nxENOEXEC                                                   ((int32_t)0x000035F0)

// nxIpStackErrBadFile: -13809 (0xFFFFCA0F)
//             nxEBADF:  13809 (0x000035F1)
//
//  Bad file number
#define nxIpStackErrBadFile                                         ((int32_t)0xFFFFCA0F)
#define nxEBADF                                                     ((int32_t)0x000035F1)

// nxIpStackErrNoChildren: -13810 (0xFFFFCA0E)
//               nxECHILD:  13810 (0x000035F2)
//
//  No child processes
#define nxIpStackErrNoChildren                                      ((int32_t)0xFFFFCA0E)
#define nxECHILD                                                    ((int32_t)0x000035F2)

// nxIpStackErrTryAgain: -13811 (0xFFFFCA0D)
//             nxEAGAIN:  13811 (0x000035F3)
//
//  Try again
#define nxIpStackErrTryAgain                                        ((int32_t)0xFFFFCA0D)
#define nxEAGAIN                                                    ((int32_t)0x000035F3)

// nxIpStackErrMemoryFull: -13812 (0xFFFFCA0C)
//               nxENOMEM:  13812 (0x000035F4)
//
//  Out of memory
#define nxIpStackErrMemoryFull                                      ((int32_t)0xFFFFCA0C)
#define nxENOMEM                                                    ((int32_t)0x000035F4)

// nxIpStackErrPermissionDenied: -13813 (0xFFFFCA0B)
//                     nxEACCES:  13813 (0x000035F5)
//
//  Permission denied
#define nxIpStackErrPermissionDenied                                ((int32_t)0xFFFFCA0B)
#define nxEACCES                                                    ((int32_t)0x000035F5)

// nxIpStackErrBadPointer: -13814 (0xFFFFCA0A)
//               nxEFAULT:  13814 (0x000035F6)
//
//  Bad address
#define nxIpStackErrBadPointer                                      ((int32_t)0xFFFFCA0A)
#define nxEFAULT                                                    ((int32_t)0x000035F6)

// nxIpStackErrBlockDeviceRequired: -13815 (0xFFFFCA09)
//                       nxENOTBLK:  13815 (0x000035F7)
//
//  Block device required
#define nxIpStackErrBlockDeviceRequired                             ((int32_t)0xFFFFCA09)
#define nxENOTBLK                                                   ((int32_t)0x000035F7)

// nxIpStackErrResourceBusy: -13816 (0xFFFFCA08)
//                  nxEBUSY:  13816 (0x000035F8)
//
//  Device or resource busy
#define nxIpStackErrResourceBusy                                    ((int32_t)0xFFFFCA08)
#define nxEBUSY                                                     ((int32_t)0x000035F8)

// nxIpStackErrFileExists: -13817 (0xFFFFCA07)
//               nxEEXIST:  13817 (0x000035F9)
//
//  File exists
#define nxIpStackErrFileExists                                      ((int32_t)0xFFFFCA07)
#define nxEEXIST                                                    ((int32_t)0x000035F9)

// nxIpStackErrCrossDeviceLink: -13818 (0xFFFFCA06)
//                     nxEXDEV:  13818 (0x000035FA)
//
//  Cross-device link
#define nxIpStackErrCrossDeviceLink                                 ((int32_t)0xFFFFCA06)
#define nxEXDEV                                                     ((int32_t)0x000035FA)

// nxIpStackErrNoSuchDevice: -13819 (0xFFFFCA05)
//                 nxENODEV:  13819 (0x000035FB)
//
//  No such device
#define nxIpStackErrNoSuchDevice                                    ((int32_t)0xFFFFCA05)
#define nxENODEV                                                    ((int32_t)0x000035FB)

// nxIpStackErrNotADirectory: -13820 (0xFFFFCA04)
//                 nxENOTDIR:  13820 (0x000035FC)
//
//  Not a directory
#define nxIpStackErrNotADirectory                                   ((int32_t)0xFFFFCA04)
#define nxENOTDIR                                                   ((int32_t)0x000035FC)

// nxIpStackErrIsADirectory: -13821 (0xFFFFCA03)
//                 nxEISDIR:  13821 (0x000035FD)
//
//  Is a directory
#define nxIpStackErrIsADirectory                                    ((int32_t)0xFFFFCA03)
#define nxEISDIR                                                    ((int32_t)0x000035FD)

// nxIpStackErrInvalidArgument: -13822 (0xFFFFCA02)
//                    nxEINVAL:  13822 (0x000035FE)
//
//  Invalid argument
#define nxIpStackErrInvalidArgument                                 ((int32_t)0xFFFFCA02)
#define nxEINVAL                                                    ((int32_t)0x000035FE)

// nxIpStackErrFileTableOverflow: -13823 (0xFFFFCA01)
//                      nxENFILE:  13823 (0x000035FF)
//
//  File table overflow
#define nxIpStackErrFileTableOverflow                               ((int32_t)0xFFFFCA01)
#define nxENFILE                                                    ((int32_t)0x000035FF)

// nxIpStackErrTooManyOpenFiles: -13824 (0xFFFFCA00)
//                     nxEMFILE:  13824 (0x00003600)
//
//  Too many open files
#define nxIpStackErrTooManyOpenFiles                                ((int32_t)0xFFFFCA00)
#define nxEMFILE                                                    ((int32_t)0x00003600)

// nxIpStackErrNoTTY: -13825 (0xFFFFC9FF)
//          nxENOTTY:  13825 (0x00003601)
//
//  Not a typewriter
#define nxIpStackErrNoTTY                                           ((int32_t)0xFFFFC9FF)
#define nxENOTTY                                                    ((int32_t)0x00003601)

// nxIpStackErrTextFileBusy: -13826 (0xFFFFC9FE)
//                nxETXTBSY:  13826 (0x00003602)
//
//  Text file busy
#define nxIpStackErrTextFileBusy                                    ((int32_t)0xFFFFC9FE)
#define nxETXTBSY                                                   ((int32_t)0x00003602)

// nxIpStackErrFileTooLarge: -13827 (0xFFFFC9FD)
//                  nxEFBIG:  13827 (0x00003603)
//
//  File too large
#define nxIpStackErrFileTooLarge                                    ((int32_t)0xFFFFC9FD)
#define nxEFBIG                                                     ((int32_t)0x00003603)

// nxIpStackErrNoSpace: -13828 (0xFFFFC9FC)
//            nxENOSPC:  13828 (0x00003604)
//
//  No space left on device
#define nxIpStackErrNoSpace                                         ((int32_t)0xFFFFC9FC)
#define nxENOSPC                                                    ((int32_t)0x00003604)

// nxIpStackErrIllegalSeek: -13829 (0xFFFFC9FB)
//                nxESPIPE:  13829 (0x00003605)
//
//  Illegal seek
#define nxIpStackErrIllegalSeek                                     ((int32_t)0xFFFFC9FB)
#define nxESPIPE                                                    ((int32_t)0x00003605)

// nxIpStackErrTooManyLinks: -13830 (0xFFFFC9FA)
//                 nxEMLINK:  13830 (0x00003606)
//
//  Too many links
#define nxIpStackErrTooManyLinks                                    ((int32_t)0xFFFFC9FA)
#define nxEMLINK                                                    ((int32_t)0x00003606)

// nxIpStackErrBrokenPipe: -13831 (0xFFFFC9F9)
//                nxEPIPE:  13831 (0x00003607)
//
//  Broken pipe
#define nxIpStackErrBrokenPipe                                      ((int32_t)0xFFFFC9F9)
#define nxEPIPE                                                     ((int32_t)0x00003607)

// nxIpStackErrOutOfDomain: -13832 (0xFFFFC9F8)
//                  nxEDOM:  13832 (0x00003608)
//
//  Math argument out of domain of func
#define nxIpStackErrOutOfDomain                                     ((int32_t)0xFFFFC9F8)
#define nxEDOM                                                      ((int32_t)0x00003608)

// nxIpStackErrNotRepresentable: -13833 (0xFFFFC9F7)
//                     nxERANGE:  13833 (0x00003609)
//
//  Math result not representable
#define nxIpStackErrNotRepresentable                                ((int32_t)0xFFFFC9F7)
#define nxERANGE                                                    ((int32_t)0x00003609)

// nxIpStackErrNoMessage: -13834 (0xFFFFC9F6)
//              nxENOMSG:  13834 (0x0000360A)
//
//  No message of desired type
#define nxIpStackErrNoMessage                                       ((int32_t)0xFFFFC9F6)
#define nxENOMSG                                                    ((int32_t)0x0000360A)

// nxIpStackErrIdentifierRemoved: -13835 (0xFFFFC9F5)
//                       nxEIDRM:  13835 (0x0000360B)
//
//  Identifier removed
#define nxIpStackErrIdentifierRemoved                               ((int32_t)0xFFFFC9F5)
#define nxEIDRM                                                     ((int32_t)0x0000360B)

// nxIpStackErrWouldDeadlock: -13836 (0xFFFFC9F4)
//               nxEDEADLOCK:  13836 (0x0000360C)
//
//  Resource deadlock would occur
#define nxIpStackErrWouldDeadlock                                   ((int32_t)0xFFFFC9F4)
#define nxEDEADLOCK                                                 ((int32_t)0x0000360C)

// nxIpStackErrWouldBlock: -13837 (0xFFFFC9F3)
//          nxEWOULDBLOCK:  13837 (0x0000360D)
//
//  Operation would block
#define nxIpStackErrWouldBlock                                      ((int32_t)0xFFFFC9F3)
#define nxEWOULDBLOCK                                               ((int32_t)0x0000360D)

// nxIpStackErrNowInProgress: -13838 (0xFFFFC9F2)
//             nxEINPROGRESS:  13838 (0x0000360E)
//
//  Operation now in progress
#define nxIpStackErrNowInProgress                                   ((int32_t)0xFFFFC9F2)
#define nxEINPROGRESS                                               ((int32_t)0x0000360E)

// nxIpStackErrAlreadyInProgress: -13839 (0xFFFFC9F1)
//                    nxEALREADY:  13839 (0x0000360F)
//
//  Operation already in progress
#define nxIpStackErrAlreadyInProgress                               ((int32_t)0xFFFFC9F1)
#define nxEALREADY                                                  ((int32_t)0x0000360F)

// nxIpStackErrNotSock: -13840 (0xFFFFC9F0)
//          nxENOTSOCK:  13840 (0x00003610)
//
//  Socket operation on non-socket
#define nxIpStackErrNotSock                                         ((int32_t)0xFFFFC9F0)
#define nxENOTSOCK                                                  ((int32_t)0x00003610)

// nxIpStackErrDestAddrRequired: -13841 (0xFFFFC9EF)
//               nxEDESTADDRREQ:  13841 (0x00003611)
//
//  Destination address required
#define nxIpStackErrDestAddrRequired                                ((int32_t)0xFFFFC9EF)
#define nxEDESTADDRREQ                                              ((int32_t)0x00003611)

// nxIpStackErrMessageSize: -13842 (0xFFFFC9EE)
//              nxEMSGSIZE:  13842 (0x00003612)
//
//  Message too long
#define nxIpStackErrMessageSize                                     ((int32_t)0xFFFFC9EE)
#define nxEMSGSIZE                                                  ((int32_t)0x00003612)

// nxIpStackErrWrongProtocol: -13843 (0xFFFFC9ED)
//              nxEPROTOTYPE:  13843 (0x00003613)
//
//  Protocol wrong type for socket
#define nxIpStackErrWrongProtocol                                   ((int32_t)0xFFFFC9ED)
#define nxEPROTOTYPE                                                ((int32_t)0x00003613)

// nxIpStackErrProtocolNotAvail: -13844 (0xFFFFC9EC)
//                nxENOPROTOOPT:  13844 (0x00003614)
//
//  Protocol not available
#define nxIpStackErrProtocolNotAvail                                ((int32_t)0xFFFFC9EC)
#define nxENOPROTOOPT                                               ((int32_t)0x00003614)

// nxIpStackErrProtocolNotSupported: -13845 (0xFFFFC9EB)
//                nxEPROTONOSUPPORT:  13845 (0x00003615)
//
//  Protocol not supported
#define nxIpStackErrProtocolNotSupported                            ((int32_t)0xFFFFC9EB)
#define nxEPROTONOSUPPORT                                           ((int32_t)0x00003615)

// nxIpStackErrSocketTypeNotSupported: -13846 (0xFFFFC9EA)
//                  nxESOCKTNOSUPPORT:  13846 (0x00003616)
//
//  Socket type not supported
#define nxIpStackErrSocketTypeNotSupported                          ((int32_t)0xFFFFC9EA)
#define nxESOCKTNOSUPPORT                                           ((int32_t)0x00003616)

// nxIpStackErrOpNotSupportedOnTransport: -13847 (0xFFFFC9E9)
//                          nxEOPNOTSUPP:  13847 (0x00003617)
//
//  Operation not supported on transport endpoint
#define nxIpStackErrOpNotSupportedOnTransport                       ((int32_t)0xFFFFC9E9)
#define nxEOPNOTSUPP                                                ((int32_t)0x00003617)

// nxIpStackErrAddressFamilyNotSupported: -13848 (0xFFFFC9E8)
//                        nxEAFNOSUPPORT:  13848 (0x00003618)
//
//  Address family not supported by protocol
#define nxIpStackErrAddressFamilyNotSupported                       ((int32_t)0xFFFFC9E8)
#define nxEAFNOSUPPORT                                              ((int32_t)0x00003618)

// nxIpStackErrAddressInUse: -13849 (0xFFFFC9E7)
//             nxEADDRINUSE:  13849 (0x00003619)
//
//  Address already in use
#define nxIpStackErrAddressInUse                                    ((int32_t)0xFFFFC9E7)
#define nxEADDRINUSE                                                ((int32_t)0x00003619)

// nxIpStackErrAddressNotAvail: -13850 (0xFFFFC9E6)
//             nxEADDRNOTAVAIL:  13850 (0x0000361A)
//
//  Cannot assign requested address
#define nxIpStackErrAddressNotAvail                                 ((int32_t)0xFFFFC9E6)
#define nxEADDRNOTAVAIL                                             ((int32_t)0x0000361A)

// nxIpStackErrNetworkDown: -13851 (0xFFFFC9E5)
//              nxENETDOWN:  13851 (0x0000361B)
//
//  Network is down
#define nxIpStackErrNetworkDown                                     ((int32_t)0xFFFFC9E5)
#define nxENETDOWN                                                  ((int32_t)0x0000361B)

// nxIpStackErrNetworkUnreachable: -13852 (0xFFFFC9E4)
//                  nxENETUNREACH:  13852 (0x0000361C)
//
//  Network is unreachable
#define nxIpStackErrNetworkUnreachable                              ((int32_t)0xFFFFC9E4)
#define nxENETUNREACH                                               ((int32_t)0x0000361C)

// nxIpStackErrNetworkReset: -13853 (0xFFFFC9E3)
//              nxENETRESET:  13853 (0x0000361D)
//
//  Network dropped connection because of reset
#define nxIpStackErrNetworkReset                                    ((int32_t)0xFFFFC9E3)
#define nxENETRESET                                                 ((int32_t)0x0000361D)

// nxIpStackErrConnectionAborted: -13854 (0xFFFFC9E2)
//                nxECONNABORTED:  13854 (0x0000361E)
//
//  Software caused connection abort
#define nxIpStackErrConnectionAborted                               ((int32_t)0xFFFFC9E2)
#define nxECONNABORTED                                              ((int32_t)0x0000361E)

// nxIpStackErrConnectionReset: -13855 (0xFFFFC9E1)
//                nxECONNRESET:  13855 (0x0000361F)
//
//  Connection reset by peer
#define nxIpStackErrConnectionReset                                 ((int32_t)0xFFFFC9E1)
#define nxECONNRESET                                                ((int32_t)0x0000361F)

// nxIpStackErrNoBuffers: -13856 (0xFFFFC9E0)
//             nxENOBUFS:  13856 (0x00003620)
//
//  No buffer space available
#define nxIpStackErrNoBuffers                                       ((int32_t)0xFFFFC9E0)
#define nxENOBUFS                                                   ((int32_t)0x00003620)

// nxIpStackErrAlreadyConnected: -13857 (0xFFFFC9DF)
//                    nxEISCONN:  13857 (0x00003621)
//
//  Transport endpoint is already connected
#define nxIpStackErrAlreadyConnected                                ((int32_t)0xFFFFC9DF)
#define nxEISCONN                                                   ((int32_t)0x00003621)

// nxIpStackErrNotConnected: -13858 (0xFFFFC9DE)
//               nxENOTCONN:  13858 (0x00003622)
//
//  Transport endpoint is not connected
#define nxIpStackErrNotConnected                                    ((int32_t)0xFFFFC9DE)
#define nxENOTCONN                                                  ((int32_t)0x00003622)

// nxIpStackErrTransportShutdown: -13859 (0xFFFFC9DD)
//                   nxESHUTDOWN:  13859 (0x00003623)
//
//  Cannot send after transport endpoint shutdown
#define nxIpStackErrTransportShutdown                               ((int32_t)0xFFFFC9DD)
#define nxESHUTDOWN                                                 ((int32_t)0x00003623)

// nxIpStackErrTimeout: -13860 (0xFFFFC9DC)
//         nxETIMEDOUT:  13860 (0x00003624)
//
//  Operation timed out
#define nxIpStackErrTimeout                                         ((int32_t)0xFFFFC9DC)
#define nxETIMEDOUT                                                 ((int32_t)0x00003624)

// nxIpStackErrConnectionRefused: -13861 (0xFFFFC9DB)
//                nxECONNREFUSED:  13861 (0x00003625)
//
//  Connection refused
#define nxIpStackErrConnectionRefused                               ((int32_t)0xFFFFC9DB)
#define nxECONNREFUSED                                              ((int32_t)0x00003625)

// nxIpStackErrProtocolFamilyNotSupported: -13862 (0xFFFFC9DA)
//                         nxEPFNOSUPPORT:  13862 (0x00003626)
//
//  Protocol family not supported
#define nxIpStackErrProtocolFamilyNotSupported                      ((int32_t)0xFFFFC9DA)
#define nxEPFNOSUPPORT                                              ((int32_t)0x00003626)

// nxIpStackErrHostDown: -13863 (0xFFFFC9D9)
//          nxEHOSTDOWN:  13863 (0x00003627)
//
//  Host is down
#define nxIpStackErrHostDown                                        ((int32_t)0xFFFFC9D9)
#define nxEHOSTDOWN                                                 ((int32_t)0x00003627)

// nxIpStackErrHostUnreachable: -13864 (0xFFFFC9D8)
//              nxEHOSTUNREACH:  13864 (0x00003628)
//
//  No route to host
#define nxIpStackErrHostUnreachable                                 ((int32_t)0xFFFFC9D8)
#define nxEHOSTUNREACH                                              ((int32_t)0x00003628)

// nxIpStackErrNoUrgentData: -13865 (0xFFFFC9D7)
//          nxENOURGENTDATA:  13865 (0x00003629)
//
//  No high priority data are available
#define nxIpStackErrNoUrgentData                                    ((int32_t)0xFFFFC9D7)
#define nxENOURGENTDATA                                             ((int32_t)0x00003629)

// nxIpStackErrNoOOBData: -13866 (0xFFFFC9D6)
//          nxENOOOBDATA:  13866 (0x0000362A)
//
//  No out of band data available
#define nxIpStackErrNoOOBData                                       ((int32_t)0xFFFFC9D6)
#define nxENOOOBDATA                                                ((int32_t)0x0000362A)

// nxIpStackErrTooManyReferences: -13867 (0xFFFFC9D5)
//                nxETOOMANYREFS:  13867 (0x0000362B)
//
//  Too many references: cannot splice
#define nxIpStackErrTooManyReferences                               ((int32_t)0xFFFFC9D5)
#define nxETOOMANYREFS                                              ((int32_t)0x0000362B)

// nxIpStackErrProtocolDriverUnattached: -13868 (0xFFFFC9D4)
//                            nxEUNATCH:  13868 (0x0000362C)
//
//  Protocol driver not attached
#define nxIpStackErrProtocolDriverUnattached                        ((int32_t)0xFFFFC9D4)
#define nxEUNATCH                                                   ((int32_t)0x0000362C)

// nxIpStackErrLinkNumRange: -13869 (0xFFFFC9D3)
//                 nxELNRNG:  13869 (0x0000362D)
//
//  Link number out of range
#define nxIpStackErrLinkNumRange                                    ((int32_t)0xFFFFC9D3)
#define nxELNRNG                                                    ((int32_t)0x0000362D)

// nxIpStackErrTryLookupAgain: -13870 (0xFFFFC9D2)
//                nxEAI_AGAIN:  13870 (0x0000362E)
//
//  The name could not be resolved at this time. Try again later.
#define nxIpStackErrTryLookupAgain                                  ((int32_t)0xFFFFC9D2)
#define nxEAI_AGAIN                                                 ((int32_t)0x0000362E)

// nxIpStackErrBadFlags: -13871 (0xFFFFC9D1)
//       nxEAI_BADFLAGS:  13871 (0x0000362F)
//
//  The flags argument has an invalid value.
#define nxIpStackErrBadFlags                                        ((int32_t)0xFFFFC9D1)
#define nxEAI_BADFLAGS                                              ((int32_t)0x0000362F)

// nxIpStackErrNoSocketArg: -13872 (0xFFFFC9D0)
//          nxEAI_NOSOCKET:  13872 (0x00003630)
//
//  The sockaddr argument has an invalid value.
#define nxIpStackErrNoSocketArg                                     ((int32_t)0xFFFFC9D0)
#define nxEAI_NOSOCKET                                              ((int32_t)0x00003630)

// nxIpStackErrFamily: -13873 (0xFFFFC9CF)
//       nxEAI_FAMILY:  13873 (0x00003631)
//
//  The requested address family is not supported.
#define nxIpStackErrFamily                                          ((int32_t)0xFFFFC9CF)
#define nxEAI_FAMILY                                                ((int32_t)0x00003631)

// nxIpStackErrAddrinfoMemoryFull: -13874 (0xFFFFC9CE)
//                   nxEAI_MEMORY:  13874 (0x00003632)
//
//  Memory is full
#define nxIpStackErrAddrinfoMemoryFull                              ((int32_t)0xFFFFC9CE)
#define nxEAI_MEMORY                                                ((int32_t)0x00003632)

// nxIpStackErrNameNotResolved: -13875 (0xFFFFC9CD)
//                nxEAI_NONAME:  13875 (0x00003633)
//
//  getaddrinfo: The node or service is not known; or both node and
//  service are NULL; or AI_NUMERICSERV was specified in hints.ai_flags
//  and service was not a numeric port number string. getnameinfo: The
//  name does not resolve for the supplied arguments. NI_NAMEREQD is set
//  and the host's name cannot be located, or neither hostname nor service
//  name were requested.
#define nxIpStackErrNameNotResolved                                 ((int32_t)0xFFFFC9CD)
#define nxEAI_NONAME                                                ((int32_t)0x00003633)

// nxIpStackErrServiceNotAvail: -13876 (0xFFFFC9CC)
//               nxEAI_SERVICE:  13876 (0x00003634)
//
//  The requested service is not available for the requested socket type.
//  It may be available through another socket type.
#define nxIpStackErrServiceNotAvail                                 ((int32_t)0xFFFFC9CC)
#define nxEAI_SERVICE                                               ((int32_t)0x00003634)

// nxIpStackErrAddrinfoSocketTypeNotSupported: -13877 (0xFFFFC9CB)
//                             nxEAI_SOCKTYPE:  13877 (0x00003635)
//
//  The requested socket type is not supported. This could occur if
//  hints.ai_socktype and hints.ai_protocol are inconsistent.
#define nxIpStackErrAddrinfoSocketTypeNotSupported                  ((int32_t)0xFFFFC9CB)
#define nxEAI_SOCKTYPE                                              ((int32_t)0x00003635)

// nxIpStackErrAddrinfoBufferOverflow: -13878 (0xFFFFC9CA)
//                     nxEAI_OVERFLOW:  13878 (0x00003636)
//
//  The buffer pointed to by host or serv was too small.
#define nxIpStackErrAddrinfoBufferOverflow                          ((int32_t)0xFFFFC9CA)
#define nxEAI_OVERFLOW                                              ((int32_t)0x00003636)

// nxIpStackErrOperationFailed: -13879 (0xFFFFC9C9)
//                  nxEAI_FAIL:  13879 (0x00003637)
//
//  A nonrecoverable error occurred.
#define nxIpStackErrOperationFailed                                 ((int32_t)0xFFFFC9C9)
#define nxEAI_FAIL                                                  ((int32_t)0x00003637)

// nxIpStackErrSystemError: -13880 (0xFFFFC9C8)
//            nxEAI_SYSTEM:  13880 (0x00003638)
//
//  A system error occurred.
#define nxIpStackErrSystemError                                     ((int32_t)0xFFFFC9C8)
#define nxEAI_SYSTEM                                                ((int32_t)0x00003638)

// nxIpStackErrNoKnownAddrs: -13881 (0xFFFFC9C7)
//             nxEAI_NODATA:  13881 (0x00003639)
//
//  The specified network host exists, but does not have any network
//  addresses defined.
#define nxIpStackErrNoKnownAddrs                                    ((int32_t)0xFFFFC9C7)
#define nxEAI_NODATA                                                ((int32_t)0x00003639)

// nxIpStackErrDNSNotAvailable: -13882 (0xFFFFC9C6)
//        nxRSLV_NOT_AVAILABLE:  13882 (0x0000363A)
//
//  DNS resolver is disabled.
#define nxIpStackErrDNSNotAvailable                                 ((int32_t)0xFFFFC9C6)
#define nxRSLV_NOT_AVAILABLE                                        ((int32_t)0x0000363A)

#endif