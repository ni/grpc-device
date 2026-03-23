#include <nirfmxbluetoothgen/nirfmxbluetoothgen_service.h>

namespace nirfmxbluetoothgen_grpc {

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForNiRFmxInstrHandle(::grpc::ServerContextBase* context, int32_t status, niRFmxInstrHandle instrumentHandle)
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

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForNiBTSGSession(::grpc::ServerContextBase* context, int32_t status, niBTGSession session)
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
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, "NI-BluetoothGen error handling not yet implemented");
}

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
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
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, "NI-BluetoothGen error handling not yet implemented");
}

}  // namespace nirfmxbluetoothgen_grpc
