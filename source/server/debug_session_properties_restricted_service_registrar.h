#ifndef NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H
#define NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H

#include <memory>

#include "feature_toggles.h"
#include "server_reset_observer_registrar_interface.h"

namespace grpc {
class ServerBuilder;
}

namespace nidevice_restricted_grpc {
using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;

std::shared_ptr<void> register_debug_session_properties_restricted_service(
  grpc::ServerBuilder& server_builder,
  const nidevice_grpc::FeatureToggles& feature_toggles,
  nidevice_grpc::ServerResetObserverRegistrarInterface& serverResetObserverRegistrar);

} // nidevice_restricted_grpc

#endif  // NIDEVICE_GRPC_DEVICE_RESTRICTED_DEBUG_SESSION_PROPERTIES_SERVICE_REGISTRAR_H
