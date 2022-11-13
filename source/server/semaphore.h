#ifndef NIDEVICE_GRPC_SEMAPHORE_H
#define NIDEVICE_GRPC_SEMAPHORE_H

#include <shared_mutex>
#include <condition_variable>

namespace nidevice_grpc {

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

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SEMAPHORE_H
