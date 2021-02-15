#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT

#include <grpcpp/grpcpp.h>

#include "session_repository.h"
#include "shared_library.h"
#include "nisyscfg.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
class DeviceManagement
{
 public:
  DeviceManagement();
  ~DeviceManagement();

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices);
  void set_syscfg_library_name(const char* library_name);
  std::string get_syscfg_library_name() const;
  bool is_syscfg_library_loaded() const;

 private:
  internal::SharedLibrary* syscfg_library_;
  NISysCfgStatus get_list_of_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices);
};

} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni

#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
