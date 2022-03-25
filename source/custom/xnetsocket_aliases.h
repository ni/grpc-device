#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ALIASES_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ALIASES_H

#include <nixnetsocket.pb.h>
#include <nixnetsocket/nixnetsocket_library_interface.h>
#include <nxsocket.h>
#include <server/converters.h>

#include <algorithm>
#include <cstring>

namespace nixnetsocket_grpc {
// Aliasing these particular usages allow us to use a custom converter
// that calls the paired nxIpStackFreeAllStacksInfoStr.
using IpStackInfoString = char*;
}  // namespace nixnetsocket_grpc
using nixnetsocket_grpc::IpStackInfoString;

#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ALIASES_H */
