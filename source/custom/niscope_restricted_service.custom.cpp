#include <niscope_restricted/niscope_restricted_service.h>

namespace niscope_restricted_grpc {

::grpc::Status NiScopeRestrictedService::ConvertApiErrorStatusForViSession(::grpc::ServerContext* context, int32_t status, ViSession vi)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(vi, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorMessage(vi, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace niscope_restricted_grpc
