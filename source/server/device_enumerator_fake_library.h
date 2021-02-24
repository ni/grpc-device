#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H

#include "device_enumerator_library_interface.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumeratorFakeLibrary : public DeviceEnumeratorLibraryInterface {
 public:
  ::grpc::Status check_library_exists();
  NISysCfgStatus FindHardware();
  NISysCfgStatus NextResource(NISysCfgResourceHandle* resourceHandle);
  NISysCfgStatus GetResourceProperty(NISysCfgEnumResourceHandle resourceEnumHandle, void* value);
  NISysCfgStatus CloseHandle(void* sysCfgHandle) override;

 private:
  struct Resource {
    std::string name;
    Resource(std::string name)
    {
      this->name = name;
    }
  };
  typedef Resource* r_handle;

  std::vector<Resource> resources{};
  std::vector<Resource>::iterator it;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORFAKELIBRARY_H
