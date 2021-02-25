#ifndef NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARYINTERFACE_H
#define NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARYINTERFACE_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class SysCfgLibraryInterface {
 public:
  virtual ~SysCfgLibraryInterface() {}

  virtual ::grpc::Status check_library_exists() = 0;
  // TODO: Additional methods like InitializeSession, CreateFilter etc. will be added in upcoming PRs.
  
  virtual NISysCfgStatus FindHardware() = 0;
  virtual NISysCfgStatus NextResource(NISysCfgResourceHandle* resourceHandle) = 0;
  virtual NISysCfgStatus GetResourceProperty(NISysCfgEnumResourceHandle resourceEnumHandle, NISysCfgResourceProperty propertyID, void* value) = 0;
  virtual NISysCfgStatus CloseHandle(void* syscfgHandle) = 0;
  // Note: Since this is just an RFC to get design approved, I have added only few methods with few parameters.
  // When PRs with actual implementation are created, I will add APIs starting from InitializeSession.
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARYINTERFACE_H
