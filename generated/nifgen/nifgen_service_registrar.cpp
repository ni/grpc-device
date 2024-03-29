
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-FGEN Metadata
//---------------------------------------------------------------------
#include "nifgen_library.h"

#include <grpcpp/server_builder.h>

#include "nifgen_service.h"
#include "nifgen_service_registrar.h"

namespace nifgen_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiFgenFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiFgenLibrary>();
    auto service = std::make_shared<NiFgenService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // nifgen_grpc
