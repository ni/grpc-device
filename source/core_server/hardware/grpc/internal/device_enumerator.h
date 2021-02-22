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
  
class DeviceEnumerator
{
 public:
  DeviceEnumerator();
  DeviceEnumerator(const char* library_name);

  ::grpc::Status enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);
  std::string get_syscfg_library_name() const;
  bool is_syscfg_library_loaded() const;

  NISysCfgSessionHandle DeviceEnumerator::get_syscfg_session(bool reinitialize = false);
  void DeviceEnumerator::clear_sysconfig_session();

 private:
  NISysCfgStatus get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices);

  internal::SharedLibrary syscfg_library_;

  std::shared_mutex session_mutex;
  NISysCfgSessionHandle cached_syscfg_session;
};

} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni

#endif // NI_HARDWARE_GRPC_INTERNAL_DEVICEMANAGEMENT
