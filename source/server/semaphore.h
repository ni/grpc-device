#ifndef NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE
#define NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE

#include <shared_mutex>

namespace grpc {
namespace nidevice {

class Semaphore {
 public:
  Semaphore(int count = 1);
  void notify();
  void cancel();
  void wait();

 private:
  int count_;
  bool is_canceled_;
  std::mutex mtx_;
  std::condition_variable cv_;
};

}  // namespace nidevice
}  // namespace grpc

#endif  // NI_HARDWARE_GRPC_INTERNAL_SEMAPHORE
