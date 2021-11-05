#ifndef NIDEVICE_GRPC_DEVICE_CORE_SERVICE_REGISTRAR_H
#define NIDEVICE_GRPC_DEVICE_CORE_SERVICE_REGISTRAR_H

#include <memory>

#include "session_repository.h"
namespace grpc {
class ServerBuilder;
}

namespace nidevice_grpc {
std::shared_ptr<void> register_core_service(
    grpc::ServerBuilder& server_builder,
    const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository);
}
#endif  // NIDEVICE_GRPC_DEVICE_CORE_SERVICE_REGISTRAR_H
