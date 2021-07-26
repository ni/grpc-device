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

  void process(bool ok)
  {
    if (ok) {
      service_->process_RegisterDoneEvent(method_context_);
      // Start another DoneEventCallbackOperation listener.
      register_completion_queue_element(service_, method_context_->completion_queue());
    }
    delete this;
  }

 private:
  DoneEventCallbackOperation(NiDAQmxService* service, ::grpc::ServerCompletionQueue* completion_queue)
      : method_context_(std::make_shared<NiDAQmxService::RegisterDoneEventMethodContext>(completion_queue)),
        service_(service)
  {
    nidevice_grpc::FinishCallbackOperation::register_completion_queue_element(method_context_);
    service_->RequestRegisterDoneEvent(
        method_context_->context_ptr(),
        method_context_->request_ptr(),
        method_context_->writer_ptr(),
        method_context_->completion_queue(),
        method_context_->completion_queue(),
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
void NiDAQmxService::process_RegisterDoneEvent(const RegisterDoneEventMethodContextPtr& async_method_context)
{
  if (async_method_context->is_cancelled()) {
    return;
  }
  using WriteOperation = nidevice_grpc::WriteOperation<RegisterDoneEventRequest, RegisterDoneEventResponse>;
  using FailOperation = nidevice_grpc::FailOperation;
  using SendInitialMetadataOperation = nidevice_grpc::SendInitialMetadataOperation;

  auto& request = async_method_context->request();
  try {
    auto task_grpc_session = request.task();
    TaskHandle task = session_repository_->access_session(task_grpc_session.id(), task_grpc_session.name());
    uInt32 options = request.options();

    SendInitialMetadataOperation::register_completion_queue_element(async_method_context);

    async_method_context->track_registration(DoneEventCallbackRouter::register_handler(
        [async_method_context]  // Copy the shared_ptr to ensure the callback has access to the writer.
        (TaskHandle task, int32 callback_status) {
          RegisterDoneEventResponse callback_response;
          callback_response.set_status(callback_status);
          WriteOperation::register_completion_queue_element(callback_response, async_method_context);
          return DAQmxSuccess;
        }));

    auto status = library_->RegisterDoneEvent(task, options, DoneEventCallbackRouter::handle_callback, async_method_context->registration_token());

    if (status) {
      RegisterDoneEventResponse failed_to_register_response;
      failed_to_register_response.set_status(status);
      WriteOperation::register_completion_queue_element(failed_to_register_response, async_method_context);
    }
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    FailOperation::register_completion_queue_element(::grpc::Status(::grpc::NOT_FOUND, ex.what()), async_method_context);
  }
}
}  // namespace nidaqmx_grpc
