#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {

::grpc::Status NiDAQmxService::ConvertApiErrorStatusForTaskHandle(google::protobuf::int32 status, TaskHandle task)
{
    // This implementation assumes this method is always called on the same thread where the error occurred.
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nidaqmx_grpc
