#ifndef NIDEVICE_GRPC_LINUX_DAEMONIZE_H
#define NIDEVICE_GRPC_LINUX_DAEMONIZE_H

namespace nidevice_grpc {

typedef void (*stop_callback)();

void daemonize(stop_callback stop);

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_LINUX_DAEMONIZE_H

