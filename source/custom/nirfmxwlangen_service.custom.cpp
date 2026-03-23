#include <nirfmxwlangen/nirfmxwlangen_service.h>

namespace nirfmxwlangen_grpc {

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForNiRFmxInstrHandle(::grpc::ServerContextBase* context, int32_t status, niRFmxInstrHandle instrumentHandle)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(instrumentHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetErrorString(instrumentHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForNiWLANGenerationSession(::grpc::ServerContextBase* context, int32_t status, niWLANGenerationSession session)
{
  // ViStatus error_code{};
  // std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // // Try first to get the most recent error with a dynamic message.
  // library_->GetError(session, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  // if (error_code != status) {
  //   // Since another thread has changed the status, fall back to the static message lookup.
  //   description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  //   library_->GetErrorString(session, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  // }
  // return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, "NI-WLANGen error handling not yet implemented");
}

::grpc::Status NiRFmxWLANGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
{
  // ViStatus error_code{};
  // std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // // Try first to get the most recent error with a dynamic message.
  // library_->GetError(RFSGHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  // if (error_code != status) {
  //   // Since another thread has changed the status, fall back to the static message lookup.
  //   description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  //   library_->GetErrorString(RFSGHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  // }
  // return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, "NI-WLANGen error handling not yet implemented");
}

}  // namespace nirfmxwlangen_grpc