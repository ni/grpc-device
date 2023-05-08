#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {

::grpc::Status NiDAQmxService::ConvertApiErrorStatusForTaskHandle(::grpc::ServerContext* context, int32_t status, TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiDAQmxService::ConvertApiErrorStatusWithReadParametersForTaskHandle(::grpc::ServerContext* context, int32_t status, int32_t samps_per_chan_read , TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatusForReadMethod(context, status, samps_per_chan_read, description);
}

::grpc::Status NiDAQmxService::ConvertApiErrorStatusWithWriteParametersForTaskHandle(::grpc::ServerContext* context, int32_t status, int32_t samps_per_chan_written , TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatusForWriteMethod(context, status, samps_per_chan_written, description);
}

}  // namespace nidaqmx_grpc
