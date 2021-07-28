#ifndef NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
#define NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H

#include <grpcpp/alarm.h>
#include <grpcpp/grpcpp.h>

#include <deque>
#include <memory>
#include <mutex>
#include <queue>

namespace nidevice_grpc {

template <typename TResponse, typename TJoinable>
class ServerWriterReactor : public grpc::ServerWriteReactor<TResponse> {
  using LockGuard = std::lock_guard<std::recursive_mutex>;

 public:
  virtual ~ServerWriterReactor() {}

  void OnDone() override
  {
    delete this;
  }

  void OnWriteDone(bool /*ok*/) override
  {
    LockGuard lock(mutex_);
    write_ready = true;
    pending_send_.pop();
    next_write();
  }

  void OnCancel() override
  {
    Finish(::grpc::Status::OK);
  }

  void queue_write(const TResponse& response)
  {
    LockGuard lock(mutex_);
    pending_send_.push(response);
    next_write();
  }

  std::unique_ptr<TJoinable> thread_;

 private:
  void next_write()
  {
    LockGuard lock(mutex_);
    if (write_ready && !pending_send_.empty()) {
      write_ready = false;
      auto& response = pending_send_.front();
      StartWrite(&response);
    }
  }

  std::recursive_mutex mutex_;
  // This class relies on: std::deque does not invalidate on push/pop.
  std::queue<TResponse, std::deque<TResponse>> pending_send_;
  bool write_ready = true;
};
}  // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_DEVICE_ASYNC_OPERATION_H
