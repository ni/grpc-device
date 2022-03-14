#include "nixnet\nixnet_service.h"

namespace nixnet_grpc {
    ::grpc::Status NiXnetService::WriteSignalSinglePoint(::grpc::ServerContext* context, const WriteSignalSinglePointRequest* request, WriteSignalSinglePointResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_ref_grpc_session = request->session_ref();
      nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
      auto value_buffer = const_cast<f64*>(request->value_buffer().data());
      u32 size_of_value_buffer = static_cast<u32>(request->value_buffer().size() * sizeof(f64));
      auto status = library_->WriteSignalSinglePoint(session_ref, value_buffer, size_of_value_buffer);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }
}  // namespace nixnet_grpc