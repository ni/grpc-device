
#pragma warning(push)
#pragma warning(disable : 4616)
#pragma warning(disable : 4146)
#pragma warning(disable : 4244)
#include <nifake/nifake_service.h>
#pragma warning(pop)

namespace nifake_grpc {

const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

inline bool status_ok(int32_t status)
{
  return status >= 0;
}

::grpc::Status NiFakeService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->ErrorMessage(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiFakeService::IviDanceWithATwistCalculatedSizeOut(::grpc::ServerContext* context, const IviDanceWithATwistCalculatedSizeOutRequest* request, IviDanceWithATwistCalculatedSizeOutResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViInt32 actual_num_waveforms {};
    ViInt32 actual_samples_per_waveform {};
    while (true) {
      auto status = library_->IviDanceWithATwistCalculatedSizeOut(vi, 0, nullptr, &actual_num_waveforms, &actual_samples_per_waveform);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      response->mutable_data()->Resize(actual_num_waveforms, 0);
      ViUInt32* data = reinterpret_cast<ViUInt32*>(response->mutable_data()->mutable_data());
      auto data_buffer_size = actual_num_waveforms*actual_samples_per_waveform;
      status = library_->IviDanceWithATwistCalculatedSizeOut(vi, data_buffer_size, data, &actual_num_waveforms, &actual_samples_per_waveform);
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // buffer is now too small, try again
        continue;
      }
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      response->set_status(status);
      response->mutable_data()->Resize(actual_num_waveforms, 0);
      response->set_actual_num_waveforms(actual_num_waveforms);
      response->set_actual_samples_per_waveform(actual_samples_per_waveform);
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace nifake_grpc
