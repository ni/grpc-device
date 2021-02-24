#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATOR
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATOR

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>
#include <session.grpc.pb.h>

#include "device_enumerator_library_interface.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumerator {
 public:
  DeviceEnumerator(DeviceEnumeratorLibraryInterface* library);
  virtual ~DeviceEnumerator();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

 private:
  NISysCfgStatus get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

  DeviceEnumeratorLibraryInterface* library_;
};

} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni

#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATOR
