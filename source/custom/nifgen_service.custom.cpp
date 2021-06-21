#include <nifgen/nifgen_service.h>

#include <stdexcept>

namespace nifgen_grpc {

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiFgenService::CreateAdvancedArbSequence(::grpc::ServerContext* context, const CreateAdvancedArbSequenceRequest* request, CreateAdvancedArbSequenceResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.id(), vi_grpc_session.name());
    ViInt32 sequence_length = request->waveform_handles_array().size();
    auto waveform_handles_array = const_cast<ViInt32*>(reinterpret_cast<const ViInt32*>(request->waveform_handles_array().data()));
    auto loop_counts_array = const_cast<ViInt32*>(reinterpret_cast<const ViInt32*>(request->loop_counts_array().data()));
    auto sample_counts_array = const_cast<ViInt32*>(reinterpret_cast<const ViInt32*>(request->sample_counts_array().data()));
    auto marker_location_array = const_cast<ViInt32*>(reinterpret_cast<const ViInt32*>(request->marker_location_array().data()));

    if (marker_location_array != NULL) {
      response->mutable_coerced_markers_array()->Resize(sequence_length, 0);
    }
    ViInt32* coerced_markers_array = reinterpret_cast<ViInt32*>(response->mutable_coerced_markers_array()->mutable_data());
    ViInt32 sequence_handle{};
    auto status = library_->CreateAdvancedArbSequence(vi, sequence_length, waveform_handles_array, loop_counts_array, sample_counts_array, marker_location_array, coerced_markers_array, &sequence_handle);
    response->set_status(status);
    if (status == 0) {
      response->set_sequence_handle(sequence_handle);
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nifgen_grpc
