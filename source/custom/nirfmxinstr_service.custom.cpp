#include <nirfmxinstr/nirfmxinstr_service.h>
#include <server/converters.h>

#include <sstream>

namespace nirfmxinstr_grpc {
const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiRFmxInstrService::GetNIRFSASessionArray(::grpc::ServerContext* context, const GetNIRFSASessionArrayRequest* request, GetNIRFSASessionArrayResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto instrument_grpc_session = request->instrument();
    auto instrument = session_repository_->access_session(instrument_grpc_session.id(), instrument_grpc_session.name());
    auto initiating_session_id = session_repository_->access_session_id(instrument_grpc_session.id(), instrument_grpc_session.name());
    auto nirfsa_sessions = std::vector<ViSession>{};

    int32 array_size{};
    int32 actual_array_size{};

    while (true) {
      auto status = library_->GetNIRFSASessionArray(instrument, nullptr, 0, &actual_array_size);
      if (status < 0) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(status, instrument);
      }
      array_size = actual_array_size;
      nirfsa_sessions.resize(array_size);
      status = library_->GetNIRFSASessionArray(instrument, nirfsa_sessions.data(), array_size, &actual_array_size);
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
        // buffer is now too small, try again
        continue;
      }

      if (request->session_names_size() != 0 && request->session_names_size() != array_size) {
        std::stringstream stream;
        stream << "Number of session_names must be zero or match actual array size (" << array_size << ").";
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, stream.str());
      }
      if (status < 0) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(status, instrument);
      }
      response->set_status(status);
      for (auto i = 0; i < array_size; ++i) {
        auto init_lambda = [&]() {
          return std::make_tuple(0, nirfsa_sessions[i]);
        };
        uint32_t session_id = 0;
        const auto session_name = request->session_names_size() ? request->session_names(i) : "";
        int status = vi_session_resource_repository_->add_dependent_session(session_name, init_lambda, initiating_session_id, session_id);
        auto session = response->add_nirfsa_sessions();
        session->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
// BuildPortString is custom implemented to account for a bug in the buffer size returned from the ivi-dance call to BuildPortString2.
// We adjust the resulting size from the ivi-dance call to account for the channel_number input.
// See AB#1835966 for details about the RFmx Instr Bug.
::grpc::Status NiRFmxInstrService::BuildPortString(::grpc::ServerContext* context, const BuildPortStringRequest* request, BuildPortStringResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    char* selector_string = (char*)request->selector_string().c_str();
    char* port_name = (char*)request->port_name().c_str();
    char* device_name = (char*)request->device_name().c_str();
    int32 channel_number = request->channel_number();

    while (true) {
      auto status = library_->BuildPortString(selector_string, port_name, device_name, channel_number, 0, nullptr);
      if (status < 0) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(status, 0);
      }
      int32 selector_string_out_length = status + std::to_string(channel_number).length();  // AB#1835966: RFmx Instr BuildPortString2 Bug.

      std::string selector_string_out;
      if (selector_string_out_length > 0) {
        selector_string_out.resize(selector_string_out_length - 1);
      }
      status = library_->BuildPortString(selector_string, port_name, device_name, channel_number, selector_string_out_length, (char*)selector_string_out.data());
      if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer || status > static_cast<decltype(status)>(selector_string_out_length)) {
        // buffer is now too small, try again
        continue;
      }
      if (status < 0) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(status, 0);
      }
      response->set_status(status);
      response->set_selector_string_out(selector_string_out);
      nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_selector_string_out()));
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

::grpc::Status NiRFmxInstrService::ConvertApiErrorStatusForNiRFmxInstrHandle(google::protobuf::int32 status, niRFmxInstrHandle instrumentHandle)
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

}  // namespace nirfmxinstr_grpc
