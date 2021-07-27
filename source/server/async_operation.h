#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H

#include <grpcpp/grpcpp.h>

#include <memory>

#include "async_method_context.h"
#include "async_processing_loop.h"

using nidevice_grpc::SharedMethodContextPtr;

namespace nidevice_grpc {

class FailOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const ::grpc::Status& status, const SharedMethodContextPtr& method_context);
  void process(bool ok);

 private:
  FailOperation(const ::grpc::Status& status, const SharedMethodContextPtr& method_context);
  SharedMethodContextPtr method_context_;
};

class SendInitialMetadataOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const SharedMethodContextPtr& method_context);
  void process(bool ok);

 private:
  SendInitialMetadataOperation(const SharedMethodContextPtr& method_context);
  SharedMethodContextPtr method_context_;
};

// Calls Write on response.
// Primarily ensures that each write has a unique tag, as required by grpc.
// Also ensures that method_context_ stays in memory until the write completes.
template <typename TRequest, typename TResponse>
class WriteOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  using SharedMethodContextPtrT = nidevice_grpc::SharedMethodContextPtrT<TRequest, TResponse>;
  static void register_completion_queue_element(const TResponse& response, const SharedMethodContextPtrT& method_context)
  {
    new WriteOperation(response, method_context);
  }

  void process(bool ok)
  {
    if (ok) {
      method_context_->finish_write(this);
    }
    delete this;
  }

 private:
  WriteOperation(const TResponse& response, const SharedMethodContextPtrT& method_context)
      : method_context_(method_context)
  {
    method_context_->begin_write(response, this);
  }
  SharedMethodContextPtrT method_context_;
};

// Registered when the listener starts, calls context.AsyncNotifyWhenDone,
// process is called when the client cancels/finishes the stream.
// Ends the response by releasing the AsyncOperationRegistration and calling
// registering CloseCompleteOperation.
class FinishCallbackOperation : public nidevice_grpc::CompletionQueueElement {
 public:
  static void register_completion_queue_element(const SharedMethodContextPtr& method_context);
  void process(bool ok);

 private:
  FinishCallbackOperation(const SharedMethodContextPtr& method_context);
  SharedMethodContextPtr method_context_;
};
}  // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
