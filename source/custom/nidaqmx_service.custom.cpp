#include <nidaqmx/nidaqmx_service.h>
#include <server/callback_router.h>

namespace nidaqmx_grpc {

using DoneEventCallbackRouter = nidevice_grpc::CallbackRouter<int32, TaskHandle, int32>;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status
NiDAQmxService::RegisterDoneEvent(::grpc::ServerContext* context, const RegisterDoneEventRequest* request, ::grpc::ServerWriter<RegisterDoneEventResponse>* writer)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto task_grpc_session = request->task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    uInt32 options = request->options();

    auto registration = DoneEventCallbackRouter::register_handler(
        [writer](TaskHandle task, int32 callback_status) {
          RegisterDoneEventResponse callback_response;
          callback_response.set_status(callback_status);
          writer->Write(callback_response);
          return DAQmxSuccess;
        });

    auto status = library_->RegisterDoneEvent(task, options, DoneEventCallbackRouter::handle_callback, registration.token());

    if (status) {
      RegisterDoneEventResponse failed_to_register_response;
      failed_to_register_response.set_status(status);
      writer->Write(failed_to_register_response);
    }

    while (!context->IsCancelled()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nidaqmx_grpc
