#ifndef NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H
#define NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H

#include <grpcpp/grpcpp.h>

namespace nidevice_grpc {
class CompletionQueueElement {
 public:
  virtual ~CompletionQueueElement() {}
  virtual void process(bool ok) = 0;
};

template <typename TService>
void run_async_processing_loop(::grpc::ServerCompletionQueue* completion_queue, TService& service)
{
  void* tag;
  bool ok;
  service.register_async_functions(completion_queue);
  while (completion_queue->Next(&tag, &ok)) {
    ((CompletionQueueElement*)tag)->process(ok);
  }
}
}  // namespace nidevice_grpc
#endif NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H
