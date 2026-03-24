#include <nirfmxbluetoothgen/nirfmxbluetoothgen_service.h>

namespace nirfmxbluetoothgen_grpc {

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForNiBTSGSession(::grpc::ServerContextBase* context, int32_t status, niBTSGSession session)
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

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
{
  // ViStatus error_code{};
  // std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // if (status < 0) {
  //   // Since another thread has changed the status, fall back to the static message lookup.
  //   description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  //   library_->GetErrorString((unsigned long long *)RFSGHandle, status, &description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  // }
  // return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, "NI-BLUETOOTHGEN error handling for RFSG error is not implemented, call GetError from RFSG driver instead.");
}

}  // namespace nirfmxbluetoothgen_grpc
