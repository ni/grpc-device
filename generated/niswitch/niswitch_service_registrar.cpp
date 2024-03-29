
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-SWITCH Metadata
//---------------------------------------------------------------------
#include "niswitch_library.h"

#include <grpcpp/server_builder.h>

#include "niswitch_service.h"
#include "niswitch_service_registrar.h"

namespace niswitch_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiSwitchFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiSwitchLibrary>();
    auto service = std::make_shared<NiSwitchService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // niswitch_grpc
