#include "core_services_registrar.h"

#include "calibration_operations_restricted_service_registrar.h"
#include "data_moniker_service.h"
#include "debug_session_properties_restricted_service_registrar.h"
#include "server_reset_observer_registrar_interface.h"
#include "session_utilities_service_registrar.h"

namespace nidevice_grpc {
void register_core_services(
  std::shared_ptr<std::vector<std::shared_ptr<void>>>& service_vector,
  grpc::ServerBuilder& server_builder,
  const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  ServerResetObserverRegistrarInterface* server_reset_observer_registrar;
  service_vector->push_back(nidevice_grpc::register_session_utilities_service(
    server_builder,
    session_repository,
    &server_reset_observer_registrar));
  service_vector->push_back(nidevice_restricted_grpc::register_calibration_operations_restricted_service(
    server_builder,
    feature_toggles,
    *server_reset_observer_registrar));
  service_vector->push_back(nidevice_restricted_grpc::register_debug_session_properties_restricted_service(
    server_builder,
    feature_toggles,
    *server_reset_observer_registrar));

  if (ni::data_monikers::is_moniker_streaming_enabled(feature_toggles)) {
    auto moniker_service = std::make_shared<ni::data_monikers::DataMonikerService>();
    server_builder.RegisterService(moniker_service.get());
    service_vector->push_back(moniker_service);
  }
}
}  // namespace nidevice_grpc
