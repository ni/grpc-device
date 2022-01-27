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
        response->set_status(status);
        return ::grpc::Status::OK;
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
      response->set_status(status);
      if (status == 0) {
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
      }
      return ::grpc::Status::OK;
    }
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nirfmxinstr_grpc
