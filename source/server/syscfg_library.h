#ifndef NI_HARDWARE_GRPC_INTERNAL_SYSCFG_LIBRARY_H
#define NI_HARDWARE_GRPC_INTERNAL_SYSCFG_LIBRARY_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

#include "syscfg_library_interface.h"
#include "shared_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class SysCfgLibrary : public SysCfgLibraryInterface {
 public:
  SysCfgLibrary();
  virtual ~SysCfgLibrary();

  std::string get_library_name() const;
  bool is_library_loaded() const;
  // Adding a dummy InitializeSession here which will be updated in future.
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.
  NISysCfgStatus InitializeSession();

 private:
  SharedLibrary shared_library_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFG_LIBRARY_H
