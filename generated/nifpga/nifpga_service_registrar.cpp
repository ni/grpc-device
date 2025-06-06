
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-FPGA Metadata
//---------------------------------------------------------------------
#include "nifpga_library.h"

#include <grpcpp/server_builder.h>

#include "nifpga_service.h"
#include "nifpga_service_registrar.h"
#include <server/data_moniker_service.h>

namespace nifpga_grpc {

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder,
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<NiFpga_Session>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiFpgaFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library = std::make_shared<NiFpgaLibrary>();
    auto service = std::make_shared<NiFpgaService>(
      library,
      resource_repository,
      toggles);
    builder.RegisterService(service.get());

    if (ni::data_monikers::is_moniker_streaming_enabled(feature_toggles)) {
      nifpga_grpc::RegisterMonikerEndpoints();
    }

    return service;
  }

  return {};
}

} // nifpga_grpc
