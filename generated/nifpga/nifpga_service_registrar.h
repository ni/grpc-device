
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar header for the NI-FPGA Metadata
//---------------------------------------------------------------------
#ifndef NIFPGA_GRPC_SERVICE_REGISTRAR_H
#define NIFPGA_GRPC_SERVICE_REGISTRAR_H
#include <server/feature_toggles.h>
#include <server/session_resource_repository.h>

#include <memory>

#include <NiFpga.h> // for NiFpga_Session

namespace grpc {
class ServerBuilder;
}

namespace nifpga_grpc {
using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& server_builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<NiFpga_Session>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles);

} // nifpga_grpc

#endif  // NIFPGA_GRPC_SERVICE_REGISTRAR_H