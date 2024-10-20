
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-rfmxpulse Metadata
//---------------------------------------------------------------------
#ifndef NIRFMXPULSE_GRPC_SERVICE_H
#define NIRFMXPULSE_GRPC_SERVICE_H

#include <nirfmxpulse.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/converters.h>
#include <server/feature_toggles.h>
#include <server/session_resource_repository.h>
#include <server/shared_library.h>
#include <server/exceptions.h>

#include "nirfmxpulse_library_interface.h"

namespace nirfmxpulse_grpc {

struct NiRFmxPulseFeatureToggles
{
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  NiRFmxPulseFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});

  bool is_enabled;
};

class NiRFmxPulseService final : public NiRFmxPulse::Service {
public:
  using LibrarySharedPtr = std::shared_ptr<NiRFmxPulseLibraryInterface>;
  using ResourceRepositorySharedPtr = std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>;

  NiRFmxPulseService(
    LibrarySharedPtr library,
    ResourceRepositorySharedPtr resource_repository,
    const NiRFmxPulseFeatureToggles& feature_toggles = {});
  virtual ~NiRFmxPulseService();

  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status GetError(::grpc::ServerContext* context, const GetErrorRequest* request, GetErrorResponse* response) override;
  ::grpc::Status GetErrorString(::grpc::ServerContext* context, const GetErrorStringRequest* request, GetErrorStringResponse* response) override;
  ::grpc::Status Initialize(::grpc::ServerContext* context, const InitializeRequest* request, InitializeResponse* response) override;
private:
  LibrarySharedPtr library_;
  ResourceRepositorySharedPtr session_repository_;
  ::grpc::Status ConvertApiErrorStatusForNiRFmxInstrHandle(::grpc::ServerContextBase* context, int32_t status, niRFmxInstrHandle instrumentHandle);

  NiRFmxPulseFeatureToggles feature_toggles_;
};

} // namespace nirfmxpulse_grpc

#endif  // NIRFMXPULSE_GRPC_SERVICE_H
