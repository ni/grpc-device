#include "core_service_registrar.h"

#include "device_enumerator.h"
#include "session_utilities_service.h"
#include "syscfg_library.h"

namespace nidevice_grpc {
namespace {
struct CoreLibraryAndService {
  CoreLibraryAndService(const std::shared_ptr<SessionRepository>& session_repository)
      : session_repository(session_repository),
        library(),
        device_enumerator(&library),
        service(session_repository.get(), &device_enumerator) {}
  ~CoreLibraryAndService()
  {
    // This code is currently unreachable, but if the call to wait exits, we need to clean up the service here.
    session_repository->reset_server();
    device_enumerator.clear_syscfg_session();
  }
  std::shared_ptr<SessionRepository> session_repository;
  SysCfgLibrary library;
  DeviceEnumerator device_enumerator;
  SessionUtilitiesService service;
};
}  // namespace

std::shared_ptr<void> register_core_service(
    grpc::ServerBuilder& server_builder,
    const std::shared_ptr<nidevice_grpc::SessionRepository>& session_repository)
{
  auto library_and_service = std::make_shared<CoreLibraryAndService>(session_repository);
  auto& service_ref = library_and_service->service;
  server_builder.RegisterService(&service_ref);
  return library_and_service;
}
}  // namespace nidevice_grpc
