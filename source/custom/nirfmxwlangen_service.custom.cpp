#include <nirfmxwlangen/nirfmxwlangen_service.h>

namespace nirfmxwlangen_grpc {

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForNiWLANGenerationSession(::grpc::ServerContextBase* context, int32_t status, niWLANGenerationSession session)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  if (status < 0) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorString(session, status, &description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  if (status < 0) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorString((unsigned long long*)RFSGHandle, status, &description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nirfmxwlangen_grpc