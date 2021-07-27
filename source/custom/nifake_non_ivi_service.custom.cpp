#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/async_operation.h>
#include <server/async_processing_loop.h>
#include <server/callback_router.h>

#include <memory>
#include <thread>
namespace nifake_non_ivi_grpc {

class ReadStreamOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(NiFakeNonIviService* service, ::grpc::ServerCompletionQueue* completion_queue)
  {
    new ReadStreamOperation(service, completion_queue);
  }

  void process(bool ok)
  {
    if (ok) {
      service_->process_ReadStream(method_context_);
      // Start another ReadStreamOperation listener.
      register_completion_queue_element(service_, method_context_->completion_queue());
    }
    delete this;
  }

 private:
  ReadStreamOperation(NiFakeNonIviService* service, ::grpc::ServerCompletionQueue* completion_queue)
      : method_context_(std::make_shared<NiFakeNonIviService::ReadStreamMethodContext>(completion_queue)),
        service_(service)
  {
    nidevice_grpc::FinishCallbackOperation::register_completion_queue_element(method_context_);
    service_->RequestReadStream(
        method_context_->context_ptr(),
        method_context_->request_ptr(),
        method_context_->writer_ptr(),
        method_context_->completion_queue(),
        method_context_->completion_queue(),
        this);
  }
  NiFakeNonIviService::ReadStreamMethodContextPtr method_context_;
  NiFakeNonIviService* service_;
};

void NiFakeNonIviService::register_async_functions(::grpc::ServerCompletionQueue* completion_queue)
{
  ReadStreamOperation::register_completion_queue_element(this, completion_queue);
}

class AsyncFakeStreamProducer : public nidevice_grpc::AsyncOperationRegistration {
 public:
  using MethodContextPtr = NiFakeNonIviService::ReadStreamMethodContextPtr;
  AsyncFakeStreamProducer(int32 start, int32 stop, const MethodContextPtr& async_method_context)
      : thread_(start_thread(start, stop, async_method_context))
  {
  }

  ~AsyncFakeStreamProducer()
  {
    thread_.join();
  }

 private:
  std::thread start_thread(int32 start, int32 stop, const MethodContextPtr& async_method_context)
  {
    using WriteOperation = nidevice_grpc::WriteOperation<ReadStreamRequest, ReadStreamResponse>;
    return std::thread([=]() {
      ReadStreamResponse response;
      for (auto i = start; i <= stop; ++i) {
        response.set_value(i);
        WriteOperation::register_completion_queue_element(response, async_method_context);
      }
    });
  }
  std::thread thread_;
};

void NiFakeNonIviService::process_ReadStream(const ReadStreamMethodContextPtr& async_method_context)
{
  if (async_method_context->is_cancelled()) {
    return;
  }
  using SendInitialMetadataOperation = nidevice_grpc::SendInitialMetadataOperation;
  SendInitialMetadataOperation::register_completion_queue_element(async_method_context);

  const auto& request = async_method_context->request();

  async_method_context->track_registration(
      std::make_unique<AsyncFakeStreamProducer>(request.start(), request.stop(), async_method_context));
}

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
