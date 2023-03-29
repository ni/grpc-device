#include "calibration_operations_restricted_service_registrar.h"

#include "calibration_operations_restricted_service.h"
#include "syscfg_library.h"

namespace nidevice_restricted_grpc {
namespace {
struct CalibrationOperationsRestrictedLibraryAndService {
  CalibrationOperationsRestrictedLibraryAndService(
    nidevice_grpc::ServerResetObserverRegistrarInterface& serverResetObserverRegistrar)
      : library(),
        service(&library),
        observerRegistrar(&serverResetObserverRegistrar)
  {
    observerRegistrar->register_observer(&service);
  }

  ~CalibrationOperationsRestrictedLibraryAndService()
  {
    // This code is currently unreachable, but if the call to wait exits, we need to clean up the service here.
    observerRegistrar->unregister_observer(&service);
    service.clear_syscfg_session();
  }

  ::nidevice_grpc::SysCfgLibrary library;
  CalibrationOperationsRestrictedService service;
  nidevice_grpc::ServerResetObserverRegistrarInterface* observerRegistrar;
};
}  // namespace

std::shared_ptr<void> register_calibration_operations_restricted_service(
  grpc::ServerBuilder& server_builder,
  const nidevice_grpc::FeatureToggles& feature_toggles,
  nidevice_grpc::ServerResetObserverRegistrarInterface& serverResetObserverRegistrar)
{
  auto toggles = CalibrationOperationsRestrictedFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library_and_service_ptr = std::make_shared<CalibrationOperationsRestrictedLibraryAndService>(serverResetObserverRegistrar);
    auto& service = library_and_service_ptr->service;
    server_builder.RegisterService(&service);
    return library_and_service_ptr;
  }

  return {};
}
}  // namespace nidevice_restricted_grpc
