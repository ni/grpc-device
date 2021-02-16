#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

#include "session_repository.h"
#include "shared_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
class DeviceManagement
{
 public:
  DeviceManagement(internal::SharedLibrary* syscfg_library);

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices);

 private:
  NISysCfgStatus get_list_of_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices);

  internal::SharedLibrary* syscfg_library_;
};

} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni

#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
