#ifndef NI_HARDWARE_GRPC_INTERNAL_SYSCFGLIBRARYINTERFACE_H
#define NI_HARDWARE_GRPC_INTERNAL_SYSCFGLIBRARYINTERFACE_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class SysCfgLibraryInterface {
 public:
  virtual ~SysCfgLibraryInterface() {}

  virtual NISysCfgStatus InitializeSession(
    const char*                            targetName,
    const char*                            username,
    const char*                            password,
    NISysCfgLocale                         language,
    NISysCfgBool                           forcePropertyRefresh,
    unsigned int                           connectTimeoutMsec,
    NISysCfgEnumExpertHandle*              expertEnumHandle,
    NISysCfgSessionHandle*                 sessionHandle
    ) = 0;
  virtual NISysCfgStatus CloseHandle(void* syscfgHandle) = 0;
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFGLIBRARYINTERFACE_H
