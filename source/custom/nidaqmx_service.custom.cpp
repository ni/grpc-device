#include <nidaqmx/nidaqmx_service.h>
#include <server/async_operation.h>
#include <server/async_processing_loop.h>
#include <server/callback_router.h>

#include <memory>
#include <thread>

namespace nidaqmx_grpc {

using DoneEventCallbackRouter = nidevice_grpc::CallbackRouter<int32, TaskHandle, int32>;

class DoneEventCallbackOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(NiDAQmxService* service, ::grpc::ServerCompletionQueue* completion_queue)
  {
    new DoneEventCallbackOperation(service, completion_queue);
  }

  void process()
  {
    service_->process_RegisterDoneEvent(method_context_);
    register_completion_queue_element(service_, method_context_->completion_queue);
    delete this;
  }

 private:
  DoneEventCallbackOperation(NiDAQmxService* service, ::grpc::ServerCompletionQueue* completion_queue)
      : method_context_(std::make_shared<NiDAQmxService::RegisterDoneEventMethodContext>(completion_queue)),
        service_(service)
  {
    using FinishOperation = nidevice_grpc::FinishCallbackOperation<RegisterDoneEventRequest, RegisterDoneEventResponse>;
    FinishOperation::register_completion_queue_element(method_context_);
    service_->RequestRegisterDoneEvent(
        &method_context_->context,
        &method_context_->request,
        &method_context_->writer,
        method_context_->completion_queue,
        method_context_->completion_queue,
        this);
  }
  NiDAQmxService::RegisterDoneEventMethodContextPtr method_context_;
  NiDAQmxService* service_;
};

void NiDAQmxService::register_async_functions(::grpc::ServerCompletionQueue* completion_queue)
{
  DoneEventCallbackOperation::register_completion_queue_element(this, completion_queue);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status
NiDAQmxService::process_RegisterDoneEvent(const RegisterDoneEventMethodContextPtr& async_method_context)
{
  //if (context->IsCancelled()) {
  //  return ::grpc::Status::CANCELLED;
  //}
  auto& request = async_method_context->request;
  auto& writer = async_method_context->writer;
  try {
    auto task_grpc_session = request.task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    uInt32 options = request.options();

    writer.SendInitialMetadata(nidevice_grpc::NO_TAG);

    async_method_context->registration = DoneEventCallbackRouter::register_handler(
        [async_method_context]  // Copy the shared_ptr to ensure the callback has access to the writer.
        (TaskHandle task, int32 callback_status) {
          RegisterDoneEventResponse callback_response;
          callback_response.set_status(callback_status);
          async_method_context->writer.Write(callback_response, nidevice_grpc::NO_TAG);
          return DAQmxSuccess;
        });

    auto status = library_->RegisterDoneEvent(task, options, DoneEventCallbackRouter::handle_callback, async_method_context->registration->token());

    if (status) {
      RegisterDoneEventResponse failed_to_register_response;
      failed_to_register_response.set_status(status);
      writer.Write(
          failed_to_register_response,
          nidevice_grpc::NO_TAG);
    }

    //while (!context->IsCancelled()) {
    //  std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //}
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    writer.Finish(::grpc::Status(::grpc::NOT_FOUND, ex.what()), nidevice_grpc::NO_TAG);
    return ::grpc::Status::OK;
  }
}
}  // namespace nidaqmx_grpc
