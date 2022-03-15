#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ERRORS_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ERRORS_H

#include <nixnetsocket.pb.h>
#include <nixnetsocket/nixnetsocket_library_interface.h>
#include <nxsocket.h>
#include <server/converters.h>

#include <algorithm>
#include <cstring>

namespace nixnetsocket_grpc {
constexpr auto ERROR_BUFFER_SIZE = 4096;
std::string get_last_error_message(NiXnetSocketLibraryInterface* library)
{
  auto buffer = std::vector<char>(ERROR_BUFFER_SIZE);
  library->GetLastErrorStr(buffer.data(), ERROR_BUFFER_SIZE);
  return std::string(buffer.data());
}

int32_t get_last_error_num(NiXnetSocketLibraryInterface* library)
{
  return library->GetLastErrorNum();
}
}  // namespace nixnetsocket_grpc
#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_ERRORS_H */
