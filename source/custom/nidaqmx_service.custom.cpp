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
  context->AddTrailingMetadata("ni-samps-per-chan-read", std::to_string(samps_per_chan_read))
  return ConvertApiErrorStatusForTaskHandle(context, status, task);
}

::grpc::Status NiDAQmxService::ConvertApiErrorStatusWithWriteParametersForTaskHandle(::grpc::ServerContext* context, int32_t status, int32_t samps_per_chan_written , TaskHandle task)
{
  context->AddTrailingMetadata("ni-samps-per-chan-written", std::to_string(samps_per_chan_written))
  return ConvertApiErrorStatusForTaskHandle(context, status, task);
}

}  // namespace nidaqmx_grpc
