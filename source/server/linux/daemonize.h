#ifndef NIDEVICE_GRPC_LINUX_DAEMONIZE_H
#define NIDEVICE_GRPC_LINUX_DAEMONIZE_H

#include <string>

namespace nidevice_grpc {

typedef void (*stop_callback)();

void daemonize(stop_callback stop, const std::string& identity);

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_LINUX_DAEMONIZE_H

