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
  NISysCfgStatus InitializeSession(
    const char*                            targetName,
    const char*                            username,
    const char*                            password,
    NISysCfgLocale                         language,
    NISysCfgBool                           forcePropertyRefresh,
    unsigned int                           connectTimeoutMsec,
    NISysCfgEnumExpertHandle*              expertEnumHandle,
    NISysCfgSessionHandle*                 sessionHandle
    );
  NISysCfgStatus CloseHandle(void* syscfgHandle);
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.

 private:
  using InitializeSessionPtr = NISysCfgStatus (*)(
    const char *                           targetName,
    const char *                           username,
    const char *                           password,
    NISysCfgLocale                         language,
    NISysCfgBool                           forcePropertyRefresh,
    unsigned int                           connectTimeoutMsec,
    NISysCfgEnumExpertHandle *             expertEnumHandle,
    NISysCfgSessionHandle *                sessionHandle
    );
  using CloseHandlePtr = NISysCfgStatus (*)(void* syscfg_handle);
  typedef struct FunctionPointers {
    InitializeSessionPtr InitializeSession;
    CloseHandlePtr CloseHandle;
  };

  SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFG_LIBRARY_H
