#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/callback_router.h>

namespace nifake_non_ivi_grpc {

// Note: this is a contrived callback implementation that depends on the callback being immediately called on register.
// It is used to exercise the other levels of codegen associated with unpacking and forwarding callback params.
::grpc::Status NiFakeNonIviService::RegisterCallback(::grpc::ServerContext* context, const RegisterCallbackRequest* request, RegisterCallbackResponse* response)
{
  using FakeCallbackRouter = nidevice_grpc::CallbackRouter<int32, int32>;

  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto registration = FakeCallbackRouter::register_handler([&](int32 val) { 
      response->set_echo_data(request->input_data());
      return 0; });
    auto status = library_->RegisterCallback(request->input_data(), FakeCallbackRouter::handle_callback, registration->token());
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nifake_non_ivi_grpc
