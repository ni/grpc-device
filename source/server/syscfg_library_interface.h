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

  virtual NISysCfgStatus FindHardware() = 0;
  // TODO: Additional methods like InitializeSession, CreateFilter etc. will be added in upcoming PRs.
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_DEVICEENUMERATORLIBRARYINTERFACE_H
