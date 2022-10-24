#ifndef NIDEVICE_GRPC_DEVICE_CORE_SERVICES_REGISTRAR_H
#define NIDEVICE_GRPC_DEVICE_CORE_SERVICES_REGISTRAR_H

#include <memory>

#include "feature_toggles.h"
#include "session_repository.h"

namespace grpc {
class ServerBuilder;
}

namespace nidevice_grpc {
void register_core_services(
  std::shared_ptr<std::vector<std::shared_ptr<void>>>& service_vector,
  grpc::ServerBuilder& server_builder,
  const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles);
}
#endif  // NIDEVICE_GRPC_DEVICE_CORE_SERVICES_REGISTRAR_H
