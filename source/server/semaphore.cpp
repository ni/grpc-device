#include "semaphore.h"

namespace nidevice_grpc {

Semaphore::Semaphore(int count)
    : count_(count), is_canceled_(false)
{
}

void Semaphore::notify()
{
  std::unique_lock<std::mutex> lock(mtx_);
  ++count_;
  cv_.notify_one();
}

void Semaphore::cancel()
{
  std::unique_lock<std::mutex> lock(mtx_);
  is_canceled_ = true;
  cv_.notify_all();
}

void Semaphore::wait()
{
  std::unique_lock<std::mutex> lock(mtx_);
  while (count_ == 0 && !is_canceled_) {
    cv_.wait(lock);
  }

  if (!is_canceled_) {
    count_--;
  }
}

}  // namespace nidevice_grpc
