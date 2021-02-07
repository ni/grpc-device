#ifndef NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE
#define NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE

#include <shared_mutex>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class Semaphore {
 public:
  Semaphore(int count = 1);
  void notify();
  void wait();

 private:
  int count_;
  std::mutex mtx_;
  std::condition_variable cv_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE
