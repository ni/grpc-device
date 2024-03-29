
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-SCOPE Metadata
//---------------------------------------------------------------------
#include "niscope_library.h"

#include <grpcpp/server_builder.h>

#include "niscope_service.h"
#include "niscope_service_registrar.h"

namespace niscope_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiScopeFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiScopeLibrary>();
    auto service = std::make_shared<NiScopeService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // niscope_grpc
