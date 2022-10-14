#include "debug_session_properties_restricted_service_registrar.h"

#include "debug_session_properties_restricted_service.h"
#include "syscfg_library.h"

namespace nidevice_restricted_grpc {
namespace {
struct DebugSessionPropertiesRestrictedLibraryAndService {
  DebugSessionPropertiesRestrictedLibraryAndService()
      : library(),
        service(&library) {}
  ~DebugSessionPropertiesRestrictedLibraryAndService()
  {
    // This code is currently unreachable, but if the call to wait exits, we need to clean up the service here.
    service.clear_syscfg_session();
  }
  ::nidevice_grpc::SysCfgLibrary library;
  DebugSessionPropertiesRestrictedService service;
};
}  // namespace

std::shared_ptr<void> register_debug_session_properties_restricted_service(grpc::ServerBuilder& server_builder)
{
  auto library_and_service = std::make_shared<DebugSessionPropertiesRestrictedLibraryAndService>();
  auto& service_ref = library_and_service->service;
  server_builder.RegisterService(&service_ref);
  return library_and_service;
}
}  // namespace nidevice_restricted_grpc
