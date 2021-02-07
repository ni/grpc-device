#include "semaphore.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

Semaphore::Semaphore(int count)
    : count_(count)
{
}

void Semaphore::notify()
{
  std::unique_lock<std::mutex> lock(mtx_);
  ++count_;
  cv_.notify_one();
}

void Semaphore::wait()
{
  std::unique_lock<std::mutex> lock(mtx_);

  while (count_ == 0) {
    cv_.wait(lock);
  }
  count_--;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
