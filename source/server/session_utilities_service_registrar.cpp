#include "session_utilities_service_registrar.h"

#include "device_enumerator.h"
#include "session_utilities_service.h"
#include "software_enumerator.h"
#include "syscfg_library.h"

namespace nidevice_grpc {
namespace {
struct SessionUtilitiesLibraryAndService {
  SessionUtilitiesLibraryAndService(
    const std::shared_ptr<SessionRepository>& session_repository,
    ServerResetObserverRegistrarInterface** serverResetObserverRegistrar)
      : session_repository(session_repository),
        library(),
        device_enumerator(&library),
        software_enumerator(&library),
        service(session_repository.get(), &device_enumerator, &software_enumerator)
  {
    service.register_observer(&device_enumerator);
    *serverResetObserverRegistrar = &service;
  }

  ~SessionUtilitiesLibraryAndService()
  {
    // This code is currently unreachable, but if the call to wait exits, we need to clean up the service here.
    session_repository->reset_server();
    service.unregister_observer(&device_enumerator);
    device_enumerator.clear_syscfg_session();
    software_enumerator.clear_syscfg_session();
  }

  std::shared_ptr<SessionRepository> session_repository;
  SysCfgLibrary library;
  DeviceEnumerator device_enumerator;
  SoftwareEnumerator software_enumerator;
  SessionUtilitiesService service;
};
}  // namespace

std::shared_ptr<void> register_session_utilities_service(
    grpc::ServerBuilder& server_builder,
    const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository,
    ServerResetObserverRegistrarInterface** serverResetObserverRegistrar)
{
  auto library_and_service = std::make_shared<SessionUtilitiesLibraryAndService>(session_repository, serverResetObserverRegistrar);
  auto& service_ref = library_and_service->service;
  server_builder.RegisterService(&service_ref);
  return library_and_service;
}
}  // namespace nidevice_grpc
