#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H

#include <grpcpp/grpcpp.h>

#include <memory>

namespace nidevice_grpc {
using AsyncOperationToken = void*;
// Type erasing abstract base class to allow managing driver-specific operation
// registration in an AsyncMethodContext.
struct AsyncOperationRegistration {
  virtual ~AsyncOperationRegistration() {}
  virtual AsyncOperationToken token() { return reinterpret_cast<AsyncOperationToken>(0); }
};

// Holds all the objects needed for the various stages of an async streaming response method call.
// Managed as a shared object with SharedMethodContextPtr.
template <typename TRequest, typename TResponse>
struct AsyncMethodContext {
  AsyncMethodContext(::grpc::ServerCompletionQueue* completion_queue)
      : context(),
        request(),
        writer(&context),
        completion_queue(completion_queue)
  {
  }

  ::grpc::ServerContext context;
  TRequest request;
  ::grpc::ServerAsyncWriter<TResponse> writer;
  ::grpc::ServerCompletionQueue* completion_queue;
  std::unique_ptr<AsyncOperationRegistration> registration{};
};

template <typename TRequest, typename TResponse>
using SharedMethodContextPtr = std::shared_ptr<nidevice_grpc::AsyncMethodContext<TRequest, TResponse>>;
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H
