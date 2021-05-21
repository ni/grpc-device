#include <nisync/nisync_service.h>

namespace nisync_grpc {

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiSyncService::ReadMultipleTriggerTimeStamp(::grpc::ServerContext* context, const ReadMultipleTriggerTimeStampRequest* request, ReadMultipleTriggerTimeStampResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
    ViConstString terminal = request->terminal().c_str();
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
    ViUInt32 timestamps_read {};
    auto status = library_->ReadMultipleTriggerTimeStamp(vi, terminal, timestamps_to_read, timeout, time_seconds_buffer, time_nanoseconds_buffer, time_fractional_nanoseconds_buffer, detected_edge_buffer, &timestamps_read);
    response->set_status(status);
    if (status == VI_SUCCESS || status == NISYNC_ERROR_DRIVER_TIMEOUT) {
      response->set_timestamps_read(timestamps_read);
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nisync_grpc
