#ifndef NIDEVICE_GRPC_DEVICE_SESSION_UTILITIES_SERVICE_REGISTRAR_H
#define NIDEVICE_GRPC_DEVICE_SESSION_UTILITIES_SERVICE_REGISTRAR_H

#include <memory>

#include "server_reset_observer_registrar_interface.h"
#include "session_repository.h"

namespace grpc {
class ServerBuilder;
}

namespace nidevice_grpc {
std::shared_ptr<void> register_session_utilities_service(
    grpc::ServerBuilder& server_builder,
    const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository,
    ServerResetObserverRegistrarInterface** serverResetObserverRegistrar);
}
#endif  // NIDEVICE_GRPC_DEVICE_SESSION_UTILITIES_SERVICE_REGISTRAR_H
