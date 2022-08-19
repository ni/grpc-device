#include <nirfmxinstr_restricted/nirfmxinstr_restricted_service.h>

namespace nirfmxinstr_restricted_grpc {

::grpc::Status NiRFmxInstrRestrictedService::ConvertApiErrorStatusForNiRFmxInstrHandle(google::protobuf::int32 status, niRFmxInstrHandle instrumentHandle)
{
    int32 error_code {};
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    // Try first to get the most recent error with a dynamic message.
    library_->GetError(instrumentHandle, &error_code, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    if (error_code != status) {
        // Since another thread has changed the status, fall back to the static message lookup.
        description.assign(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
        library_->GetErrorString(instrumentHandle, status, nidevice_grpc::kMaxGrpcErrorDescriptionSize, &description[0]);
    }
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

::grpc::Status NiRFmxInstrRestrictedService::LoadConfigurationsFromJSON(::grpc::ServerContext* context, const LoadConfigurationsFromJSONRequest* request, LoadConfigurationsFromJSONResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto grpc_session = request->instrument();
    niRFmxInstrHandle instrument = session_repository_->access_session(grpc_session.id(), grpc_session.name());
    auto jsonString = request->json_string();
    int32 arraySize = jsonString.length();

    auto status = library_->LoadConfigurationsFromJSON(instrument, (char*)jsonString.c_str(), arraySize);
    if (status < 0) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(status, 0);
    }

    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nirfmxinstr_restricted_grpc
