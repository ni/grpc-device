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
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.name());

    auto number_of_samples_per_channel = request->number_of_samples_per_channel();
    auto timeout = request->timeout();
    auto waveform_attribute_mode = request->waveform_attribute_mode();

    // TODO: Implement the actual waveform reading logic, similar to read_analog_waveforms() in nidaqmx-python\generated\nidaqmx\_library_interpreter.py 

    // library_->InternalReadAnalogWaveformPerChan(
    //     task,
    //     number_of_samples_per_channel,
    //     timeout,
    //     nullptr,  // t0Array
    //     nullptr,  // dtArray
    //     0,        // timingArraySize
    //     nullptr,  // setWfmAttrCallback
    //     nullptr,  // setWfmAttrCallbackData
    //     nullptr,  // readArrayPtrs
    //     0,        // readArrayCount
    //     0,        // arraySizeInSampsPerChan
    //     nullptr,  // sampsPerChanRead
    //     nullptr   // reserved
    // );

    // For now, just return UNIMPLEMENTED status.
    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "ReadAnalogWaveforms implementation pending");
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidaqmx_grpc
