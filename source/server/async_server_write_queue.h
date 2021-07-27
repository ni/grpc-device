#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_SERVER_WRITE_QUEUE_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_SERVER_WRITE_QUEUE_H
#include <grpcpp/grpcpp.h>

#include <deque>
#include <mutex>
#include <queue>

namespace nidevice_grpc {
// Ensures that only one Write is pending at a time, as required by grpc:
// https://github.com/grpc/grpc/issues/7659
// All calls to begin_write should call finish_write when processed by grpc's
// completion queue.
template <typename TResponse>
class AsyncServerWriteQueue {
  using LockGuard = std::lock_guard<std::mutex>;

 public:
  AsyncServerWriteQueue(::grpc::ServerAsyncWriter<TResponse>& writer)
      : writer_(writer) {}

  void begin_write(const TResponse& response, void* tag)
  {
    LockGuard guard(mutex_);
    if (write_ready) {
      write_ready = false;
      writer_.Write(response, tag);
    }
    else {
      pending_send_.push({response, tag});
    }
  }

  void finish_write(void* tag)
  {
    LockGuard guard(mutex_);
    if (!pending_send_.empty()) {
      auto next_element = pending_send_.front();
      writer_.Write(next_element.response, next_element.tag);
      pending_send_.pop();
    }
    else {
      write_ready = true;
    }
  }

 private:
  struct PendingReponse {
    TResponse response;
    void* tag;
  };
  ::grpc::ServerAsyncWriter<TResponse>& writer_;
  std::mutex mutex_;
  std::queue<PendingReponse> pending_send_;
  bool write_ready = true;
};
}  // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_SERVER_WRITE_QUEUE_H
