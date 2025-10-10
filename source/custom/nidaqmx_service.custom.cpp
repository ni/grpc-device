#include <nidaqmx/nidaqmx_service.h>

namespace nidaqmx_grpc {

::grpc::Status NiDAQmxService::ConvertApiErrorStatusForTaskHandle(::grpc::ServerContextBase* context, int32_t status, TaskHandle task)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiDAQmxService::ReadAnalogWaveforms(::grpc::ServerContext* context, const ReadAnalogWaveformsRequest* request, ReadAnalogWaveformsResponse* response)
{
  // // Validate request parameters
  // if (!request->has_task()) {
  //   return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT, "Task handle is required");
  // }

  // auto task_handle = request->task().id();
  // auto number_of_samples_per_channel = request->number_of_samples_per_channel();
  // auto timeout = request->timeout();
  // auto waveform_attribute_mode = request->waveform_attribute_mode();

  try {
    // TODO: Implement the actual waveform reading logic
    // This will need to:
    // 1. Call the appropriate NI-DAQmx functions to read analog data
    // 2. Convert the raw data into AnalogWaveform proto messages
    // 3. Handle timing and channel information based on waveform_attribute_mode
    // 4. Populate the response with the waveforms array
    
    // For now, return a placeholder implementation
    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "ReadAnalogWaveforms implementation pending");
  }
  catch (const std::exception& ex) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, std::string("Error reading analog waveforms: ") + ex.what());
  }
}

}  // namespace nidaqmx_grpc
