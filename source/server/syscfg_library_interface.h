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

  // Adding a dummy method below which will be updated in upcoming PR with corresponding gmock tests.
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.
  virtual NISysCfgStatus InitializeSession() = 0;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFGLIBRARYINTERFACE_H
