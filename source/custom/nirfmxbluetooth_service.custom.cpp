#include <nirfmxbluetooth/nirfmxbluetooth_service.h>

namespace nirfmxbluetooth_grpc {

::grpc::Status NiRFmxBluetoothService::ConvertApiErrorStatusForNiRFmxInstrHandle(google::protobuf::int32 status, niRFmxInstrHandle instrumentHandle)
{
    ViStatus error_code {};
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    // Try first to get the most recent error with a dynamic message.
    library_->GetError(instrumentHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    if (error_code != status) {
        // Since another thread has changed the status, fall back to the static message lookup.
        description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
        library_->GetErrorString(instrumentHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    }
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nirfmxbluetooth_grpc
