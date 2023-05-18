#ifndef NIDEVICE_GRPC_DEVICE_SERVER_REACTOR_H
#define NIDEVICE_GRPC_DEVICE_SERVER_REACTOR_H

#include <grpcpp/alarm.h>
#include <grpcpp/grpcpp.h>

#include <deque>
#include <memory>
#include <mutex>
#include <queue>

namespace nidevice_grpc {

// ServerWriteReactor implementation to support async response streaming.
template <typename TResponse, typename TProducer>
class ServerWriterReactor : public grpc::ServerWriteReactor<TResponse> {
  using LockGuard = std::lock_guard<std::recursive_mutex>;

 public:
  virtual ~ServerWriterReactor()
  {
  }

  void OnDone() override
  {
    delete this;
  }

  void OnWriteDone(bool write_succeeded) override
  {
    LockGuard lock(mutex_);
    write_ready_ = true;
    pending_send_.pop();
    if (write_succeeded) {
      next_write();
    }
  }

  void OnCancel() override
  {
    try_finish(::grpc::Status::OK);
  }

 protected:
  void queue_write(const TResponse& response)
  {
    LockGuard lock(mutex_);
    pending_send_.push(response);
    next_write();
  }

  void set_producer(std::unique_ptr<TProducer>&& producer)
  {
    producer_ = std::move(producer);
  }

  // Try to immediately finish the RPC. If called multiple times, the first call wins.
  // This method does not wait until the pending send queue is empty.
  bool try_finish(::grpc::Status status)
  {
    LockGuard lock(mutex_);
    if (!done_) {
      done_ = true;
      this->Finish(std::move(status));
      return true;
    }
    return false;
  }

 private:
  void next_write()
  {
    LockGuard lock(mutex_);

    if (!done_ && write_ready_ && !pending_send_.empty()) {
      write_ready_ = false;
      auto& response = pending_send_.front();
      this->StartWrite(&response);
    }
  }

  std::recursive_mutex mutex_;
  // This class relies on: std::deque does not invalidate on push/pop.
  std::queue<TResponse, std::deque<TResponse>> pending_send_;
  bool write_ready_{true};
  bool done_{false};
  std::unique_ptr<TProducer> producer_;
};
}  // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_DEVICE_SERVER_REACTOR_H
