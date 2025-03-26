#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_WINSOCK2_COMPATIBILITY_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_WINSOCK2_COMPATIBILITY_H

// Unfortunately XNET's Socket API conflicts with defines in the winsock2 API.
// We must undefine these to prevent winsock2 from replacing them.
#if defined(_WIN32) || defined(_WIN64)
// Ensure the problematic header is included before we undef.
#include <WS2tcpip.h>

// Undef problematic defines.
#ifdef FreeAddrInfo
#undef FreeAddrInfo
#endif
#ifdef GetAddrInfo
#undef GetAddrInfo
#endif
#ifdef GetNameInfo
#undef GetNameInfo
#endif
#ifdef InetNToP
#undef InetNToP
#endif
#ifdef InetPToN
#undef InetPToN
#endif

#endif

#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_WINSOCK2_COMPATIBILITY_H */
