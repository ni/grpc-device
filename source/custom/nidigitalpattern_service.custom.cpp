#include <nidigitalpattern/nidigitalpattern_service.h>

namespace nidigitalpattern_grpc {
using nidevice_grpc::converters::convert_from_grpc;

const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

::grpc::Status NiDigitalService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 256, "ErrorMessage expects a minimum buffer size.");
  ViStatus error_code{};
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  // Try first to get the most recent error with a dynamic message.
  library_->GetError(vi, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
  if (error_code != status) {
    // Since another thread has changed the status, fall back to the static message lookup.
    description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->ErrorMessage(vi, status, &description[0]);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiDigitalService::FetchCaptureWaveformU32(::grpc::ServerContext* context, const FetchCaptureWaveformU32Request* request, FetchCaptureWaveformU32Response* response)
{
  // This function is modified from the generated code to multiply the two 'ivi-dance' parameters
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    auto site_list_mbcs = convert_from_grpc<std::string>(request->site_list());
    auto site_list = site_list_mbcs.c_str();
    auto waveform_name_mbcs = convert_from_grpc<std::string>(request->waveform_name());
    auto waveform_name = waveform_name_mbcs.c_str();
    ViInt32 samples_to_read = request->samples_to_read();
    ViReal64 timeout = request->timeout();
    ViInt32 actual_num_waveforms{};
    ViInt32 actual_samples_per_waveform{};
    while (true) {
      auto status = library_->FetchCaptureWaveformU32(vi, site_list, waveform_name, samples_to_read, timeout, 0, nullptr, &actual_num_waveforms, &actual_samples_per_waveform);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      auto data_buffer_size = actual_num_waveforms * actual_samples_per_waveform;
      response->mutable_data()->Resize(data_buffer_size, 0);
      ViUInt32* data = reinterpret_cast<ViUInt32*>(response->mutable_data()->mutable_data());
      status = library_->FetchCaptureWaveformU32(vi, site_list, waveform_name, samples_to_read, timeout, data_buffer_size, data, &actual_num_waveforms, &actual_samples_per_waveform);
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // buffer is now too small, try again
        continue;
      }
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      data_buffer_size = actual_num_waveforms * actual_samples_per_waveform;
      response->set_status(status);
      response->mutable_data()->Resize(data_buffer_size, 0);
      response->set_actual_num_waveforms(actual_num_waveforms);
      response->set_actual_samples_per_waveform(actual_samples_per_waveform);
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nidigitalpattern_grpc
