
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-RFSG Metadata
//---------------------------------------------------------------------
#include "nirfsg_library.h"

#include <grpcpp/server_builder.h>

#include "nirfsg_service.h"
#include "nirfsg_service_registrar.h"

namespace nirfsg_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiRFSGFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiRFSGLibrary>();
    auto service = std::make_shared<NiRFSGService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());
    return service;
  }

  return {};
}

} // nirfsg_grpc
