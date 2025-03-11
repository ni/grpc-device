#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_COMPATIBILITY_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_COMPATIBILITY_H

#if defined(_WIN32) || defined(_WIN64)
#include <WS2tcpip.h>
#endif

// Unfortunately XNET's Socket API conflicts with defines in the OS's Socket API.
// We must undefine these to prevent conflicts.
#ifdef GetAddrInfo
#undef GetAddrInfo
#endif
#ifdef GetNameInfo
#undef GetNameInfo
#endif
#ifdef FreeAddrInfo
#undef FreeAddrInfo
#endif

#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_COMPATIBILITY_H */
