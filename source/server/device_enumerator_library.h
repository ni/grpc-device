#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARY_H
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARY_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

#include "device_enumerator_library_interface.h"
#include "shared_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class DeviceEnumeratorLibrary : public DeviceEnumeratorLibraryInterface {
 public:
  DeviceEnumeratorLibrary();
  virtual ~DeviceEnumeratorLibrary();

  ::grpc::Status check_library_exists();
  std::string get_library_name() const;
  bool is_library_loaded() const;
  // TODO: Additional methods like InitializeSession, CreateFilter etc. will be added in upcoming PRs.
  NISysCfgStatus FindHardware();
  NISysCfgStatus NextResource(NISysCfgResourceHandle* resourceHandle);
  NISysCfgStatus GetResourceProperty(NISysCfgEnumResourceHandle resourceEnumHandle, void* value);
  NISysCfgStatus CloseHandle(void* syscfgHandle);

 private:
  SharedLibrary shared_library_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARY_H
