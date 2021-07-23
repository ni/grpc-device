#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H

#include <grpcpp/grpcpp.h>

#include <memory>

#include "async_method_context.h"
#include "async_processing_loop.h"

using nidevice_grpc::SharedMethodContextPtr;

namespace nidevice_grpc {
// Calls writer.Finish and then releases the method_context_.
template <typename TRequest, typename TResponse>
class CloseCompleteOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const SharedMethodContextPtr<TRequest, TResponse>& method_context)
  {
    new CloseCompleteOperation(method_context);
  }

  void process()
  {
    // Release method_context_.
    delete this;
  }

 private:
  CloseCompleteOperation(const SharedMethodContextPtr<TRequest, TResponse>& method_context)
      : method_context_(method_context)
  {
    method_context_->writer.Finish(::grpc::Status::OK, this);
  }
  SharedMethodContextPtr<TRequest, TResponse> method_context_;
};

// Registered when the listener starts, calls context.AsyncNotifyWhenDone,
// process is called when the client cancels/finishes the stream.
// Ends the response by releasing the AsyncOperationRegistration and calling
// registering CloseCompleteOperation.
template <typename TRequest, typename TResponse>
class FinishCallbackOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const SharedMethodContextPtr<TRequest, TResponse>& method_context)
  {
    new FinishCallbackOperation(method_context);
  }

  void process()
  {
    // Allow any driver code to start cleaning up and release it's references back to the
    // method_context_ (i.e., to access writer.Write).
    method_context_->registration.reset();
    CloseCompleteOperation<TRequest, TResponse>::register_completion_queue_element(method_context_);
    delete this;
  }

 private:
  FinishCallbackOperation(const SharedMethodContextPtr<TRequest, TResponse>& method_context)
      : method_context_(method_context)
  {
    method_context->context.AsyncNotifyWhenDone(this);
  }
  SharedMethodContextPtr<TRequest, TResponse> method_context_;
};
}  // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
