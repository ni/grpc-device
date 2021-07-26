#include "async_operation.h"

namespace nidevice_grpc {
void FailOperation::register_completion_queue_element(const ::grpc::Status& status, const SharedMethodContextPtr& method_context)
{
  new FailOperation(status, method_context);
}

void FailOperation::process(bool ok)
{
  delete this;
}

FailOperation::FailOperation(const ::grpc::Status& status, const SharedMethodContextPtr& method_context)
    : method_context_(method_context)
{
  method_context_->finish(status, this);
}

void SendInitialMetadataOperation::register_completion_queue_element(const SharedMethodContextPtr& method_context)
{
  new SendInitialMetadataOperation(method_context);
}

void SendInitialMetadataOperation::process(bool ok)
{
  delete this;
}

SendInitialMetadataOperation::SendInitialMetadataOperation(const SharedMethodContextPtr& method_context)
    : method_context_(method_context)
{
  method_context_->send_initial_metadata(this);
}

// Calls writer.Finish and then releases the method_context_.
class CloseCompleteOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const SharedMethodContextPtr& method_context)
  {
    new CloseCompleteOperation(method_context);
  }

  void process(bool ok)
  {
    // Release method_context_.
    delete this;
  }

 private:
  CloseCompleteOperation(const SharedMethodContextPtr& method_context)
      : method_context_(method_context)
  {
    method_context_->finish(::grpc::Status::OK, this);
  }
  SharedMethodContextPtr method_context_;
};

void FinishCallbackOperation::register_completion_queue_element(const SharedMethodContextPtr& method_context)
{
  new FinishCallbackOperation(method_context);
}

void FinishCallbackOperation::process(bool ok)
{
  // Allow any driver code to start cleaning up and release it's references back to the
  // method_context_ (i.e., to access writer.Write).
  method_context_->release_registration();
  CloseCompleteOperation::register_completion_queue_element(method_context_);
  delete this;
}

FinishCallbackOperation::FinishCallbackOperation(const SharedMethodContextPtr& method_context)
    : method_context_(method_context)
{
  method_context->async_notify_when_done(this);
}
}  // namespace nidevice_grpc
