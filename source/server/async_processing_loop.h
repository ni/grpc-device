#ifndef NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H
#define NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H

#include <grpcpp/grpcpp.h>

namespace nidevice_grpc {
static void* NO_TAG = nullptr;

class CompletionQueueElement {
 public:
  virtual ~CompletionQueueElement() {}
  virtual void process() = 0;
};

template <typename TService>
void run_async_processing_loop(::grpc::ServerCompletionQueue* completion_queue, TService& service)
{
  void* tag;
  bool ok;
  service.register_async_functions(completion_queue);
  while (completion_queue->Next(&tag, &ok)) {
    if (ok && tag != NO_TAG) {
      ((CompletionQueueElement*)tag)->process();
    }
  }
}
}  // namespace nidevice_grpc
#endif NIDEVICE_GRPC_DEVICE_RUN_ASYNC_LOOP_H
