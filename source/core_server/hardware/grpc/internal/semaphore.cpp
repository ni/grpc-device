#include "semaphore.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   Semaphore::Semaphore (int count)
      : count_(count), waiters_(0)
   {
   }

   void Semaphore::notify_one()
   {
      std::unique_lock<std::mutex> lock(mtx_);
      ++count_;
      cv_.notify_one();
   }

   void Semaphore::notify_all()
   {
      std::unique_lock<std::mutex> lock(mtx_);
      count_ = waiters_ + 1;
      cv_.notify_all();
   }
   
   void Semaphore::wait()
   {
      std::unique_lock<std::mutex> lock(mtx_);
      ++waiters_;
      while(count_ == 0) {
         cv_.wait(lock);
      }
      count_--;
      waiters_--;
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
