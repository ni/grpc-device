#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H

#include <grpcpp/grpcpp.h>

#include <memory>

#include "async_server_write_queue.h"

namespace nidevice_grpc {
using AsyncOperationToken = void*;
// Type erasing abstract base class to allow managing driver-specific operation
// registration in an AsyncMethodContext.
struct AsyncOperationRegistration {
  virtual ~AsyncOperationRegistration() {}
  virtual AsyncOperationToken token() { return reinterpret_cast<AsyncOperationToken>(0); }
};

struct AsyncMethodContext {
  virtual ~AsyncMethodContext() {}
  virtual bool is_cancelled() const { return false; }
  virtual void async_notify_when_done(void* tag) {}

  virtual void send_initial_metadata(void* tag) {}
  virtual void finish(const ::grpc::Status& status, void* tag) {}

  virtual ::grpc::ServerCompletionQueue* completion_queue() { return nullptr; }

  virtual void track_registration(std::unique_ptr<AsyncOperationRegistration>&& registration) {}
  virtual void release_registration() {}
  virtual AsyncOperationToken registration_token() const { return reinterpret_cast<AsyncOperationToken>(0); }
};

// Holds all the objects needed for the various stages of an async streaming response method call.
// Managed as a shared object with SharedMethodContextPtr.
template <typename TRequest, typename TResponse>
class AsyncMethodContextT : public AsyncMethodContext {
 public:
  AsyncMethodContextT(::grpc::ServerCompletionQueue* completion_queue)
      : context_(),
        request_(),
        writer_(&context_),
        write_queue_(writer_),
        completion_queue_(completion_queue)
  {
  }

  ::grpc::ServerContext* context_ptr() { return &context_; }
  TRequest* request_ptr() { return &request_; }
  ::grpc::ServerAsyncWriter<TResponse>* writer_ptr() { return &writer_; }

  bool is_cancelled() const override { return context_.IsCancelled(); }
  void async_notify_when_done(void* tag) override { return context_.AsyncNotifyWhenDone(tag); }

  const TRequest& request() const { return request_; }
  TRequest& mutable_request() { return request_; }

  void send_initial_metadata(void* tag) override { writer_.SendInitialMetadata(tag); }
  void begin_write(const TResponse& response, void* tag) { write_queue_.begin_write(response, tag); }
  void finish_write(void* tag) { write_queue_.finish_write(tag); }
  void finish(const ::grpc::Status& status, void* tag) override { writer_.Finish(status, tag); }

  ::grpc::ServerCompletionQueue* completion_queue() override { return completion_queue_; }

  void track_registration(std::unique_ptr<AsyncOperationRegistration>&& registration) override { registration_ = std::move(registration); }
  void release_registration() override { registration_.reset(); }
  AsyncOperationToken registration_token() const override { return registration_->token(); }

 private:
  ::grpc::ServerContext context_;
  TRequest request_;
  ::grpc::ServerAsyncWriter<TResponse> writer_;
  AsyncServerWriteQueue<TResponse> write_queue_;
  ::grpc::ServerCompletionQueue* completion_queue_;
  std::unique_ptr<AsyncOperationRegistration> registration_{};
};

using SharedMethodContextPtr = std::shared_ptr<nidevice_grpc::AsyncMethodContext>;
template <typename TRequest, typename TResponse>
using SharedMethodContextPtrT = std::shared_ptr<nidevice_grpc::AsyncMethodContextT<TRequest, TResponse>>;
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_METHOD_CONTEXT_H
