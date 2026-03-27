#include <nirfmxbluetoothgen/nirfmxbluetoothgen_service.h>
#include <nirfsg/nirfsg_library.h>

namespace nirfmxbluetoothgen_grpc {

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForNiBTSGSession(::grpc::ServerContextBase* context, int32_t status, niBTSGSession session)
{
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetErrorString(session, status, &description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiRFmxBluetoothGenService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession RFSGHandle)
{
  auto library = std::make_shared<nirfsg_grpc::NiRFSGLibrary>();

  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library->GetError(RFSGHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library->ErrorMessage(RFSGHandle, status, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nirfmxbluetoothgen_grpc
