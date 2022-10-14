#ifndef NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H
#define NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H

#include <memory>

namespace grpc {
class ServerBuilder;
}

namespace nidevice_restricted_grpc {
std::shared_ptr<void> register_debug_session_properties_restricted_service(grpc::ServerBuilder& server_builder);
}
#endif  // NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H
