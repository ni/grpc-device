#include <nisync/nisync_service.h>

namespace nisync_grpc {
using nidevice_grpc::converters::convert_from_grpc;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiSyncService::ReadMultipleTriggerTimeStamp(::grpc::ServerContext* context, const ReadMultipleTriggerTimeStampRequest* request, ReadMultipleTriggerTimeStampResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    auto terminal_mbcs = convert_from_grpc<std::string>(request->terminal());
    ViConstString terminal = terminal_mbcs.c_str();
    ViUInt32 timestamps_to_read = request->timestamps_to_read();
    ViReal64 timeout = request->timeout();
    response->mutable_time_seconds_buffer()->Resize(timestamps_to_read, 0);
    ViUInt32* time_seconds_buffer = reinterpret_cast<ViUInt32*>(response->mutable_time_seconds_buffer()->mutable_data());
    response->mutable_time_nanoseconds_buffer()->Resize(timestamps_to_read, 0);
    ViUInt32* time_nanoseconds_buffer = reinterpret_cast<ViUInt32*>(response->mutable_time_nanoseconds_buffer()->mutable_data());
    response->mutable_time_fractional_nanoseconds_buffer()->Resize(timestamps_to_read, 0);
    ViUInt16* time_fractional_nanoseconds_buffer = reinterpret_cast<ViUInt16*>(response->mutable_time_fractional_nanoseconds_buffer()->mutable_data());
    response->mutable_detected_edge_buffer()->Resize(timestamps_to_read, 0);
    ViInt32* detected_edge_buffer = reinterpret_cast<ViInt32*>(response->mutable_detected_edge_buffer()->mutable_data());
    ViUInt32 timestamps_read{};
    auto status = library_->ReadMultipleTriggerTimeStamp(vi, terminal, timestamps_to_read, timeout, time_seconds_buffer, time_nanoseconds_buffer, time_fractional_nanoseconds_buffer, detected_edge_buffer, &timestamps_read);
    if (status < VI_SUCCESS && status != NISYNC_ERROR_DRIVER_TIMEOUT) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_timestamps_read(timestamps_read);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

::grpc::Status NiSyncService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 256, "ErrorMessage expects a minimum buffer size.");
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->ErrorMessage(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nisync_grpc
