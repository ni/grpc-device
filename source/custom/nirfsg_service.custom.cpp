#include <nirfsg/nirfsg_service.h>
#include <nirfsg_restricted/nirfsg_restricted_library.h>

using nidevice_grpc::converters::convert_to_grpc;

namespace nirfsg_grpc {

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }
  
  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFSGService::GetDeembeddingSparameters(::grpc::ServerContext* context, const GetDeembeddingSparametersRequest* request, GetDeembeddingSparametersResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto vi_grpc_session = request->vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.name());
      ViInt32 num_ports {};
      nirfsg_restricted_grpc::NiRFSGRestrictedLibrary restricted_library;
      auto status = restricted_library.GetDeembeddingTableNumberOfPorts(vi, &num_ports);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      ViInt32 sparameters_array_size = num_ports * num_ports;
      std::vector<NIComplexNumber_struct> sparameters(sparameters_array_size, NIComplexNumber_struct());
      ViInt32 number_of_sparameters {};
      ViInt32 number_of_ports {};
      auto status = library_->GetDeembeddingSparameters(vi, sparameters.data(), sparameters_array_size, &number_of_sparameters, &number_of_ports);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
      response->set_status(status);
      convert_to_grpc(sparameters, response->mutable_sparameters());
      response->set_number_of_sparameters(number_of_sparameters);
      response->set_number_of_ports(number_of_ports);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }


::grpc::Status NiRFSGService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 1024, "ErrorMessage expects a minimum buffer size.");
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

}  // namespace nirfsg_grpc