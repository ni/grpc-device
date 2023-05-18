#ifndef ASYNC_HELPERS
#define ASYNC_HELPERS

#include <grpcpp/grpcpp.h>

typedef std::tuple<void*, bool> Completion;

inline Completion get_next_completion(::grpc::CompletionQueue& completion_queue)
{
  Completion completion;
  if (!completion_queue.Next(&std::get<0>(completion), &std::get<1>(completion))) {
    throw std::runtime_error("Completion queue error");
  }
  return completion;
}

template <typename TDuration>
inline bool try_get_next_completion(::grpc::CompletionQueue& completion_queue, Completion& completion, TDuration timeout)
{
  auto deadline = std::chrono::system_clock::now() + timeout;
  switch (completion_queue.AsyncNext(&std::get<0>(completion), &std::get<1>(completion), deadline)) {
    case ::grpc::CompletionQueue::NextStatus::GOT_EVENT:
      return true;
    case ::grpc::CompletionQueue::NextStatus::TIMEOUT:
      return false;
    case ::grpc::CompletionQueue::NextStatus::SHUTDOWN:
    default:
      throw std::runtime_error("Completion queue error");
  }
}

inline bool try_get_next_completion_without_blocking(::grpc::CompletionQueue& completion_queue, Completion& completion)
{
    return try_get_next_completion(completion_queue, completion, std::chrono::milliseconds(0));
}

inline void* get_completion_tag(const Completion& completion)
{
  return std::get<0>(completion);
}

inline bool is_completion_ok(const Completion& completion)
{
  return std::get<1>(completion);
}

#endif