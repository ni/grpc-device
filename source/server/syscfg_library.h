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

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

static const char* kSysCfgApiNotInstalledMessage = "The NI System Configuration API is not installed on the server.";

class SysCfgLibrary : public SysCfgLibraryInterface {
 public:
  SysCfgLibrary();
  virtual ~SysCfgLibrary();

  std::string get_library_name() const;
  bool is_library_loaded() const;
  NISysCfgStatus InitializeSession(
    const char* target_name,
    const char* username,
    const char* password,
    NISysCfgLocale language,
    NISysCfgBool force_property_refresh,
    unsigned int connect_timeout_msec,
    NISysCfgEnumExpertHandle* expert_enum_handle,
    NISysCfgSessionHandle* session_handle
    );
  NISysCfgStatus CloseHandle(
    void* syscfg_handle
    );
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.

 private:
  using InitializeSessionPtr = NISysCfgStatus (*)(
    const char* target_name,
    const char* username,
    const char* password,
    NISysCfgLocale language,
    NISysCfgBool force_property_refresh,
    unsigned int connect_timeout_msec,
    NISysCfgEnumExpertHandle* expert_enum_handle,
    NISysCfgSessionHandle* session_handle
    );
  using CloseHandlePtr = NISysCfgStatus (*)(
    void* syscfg_handle
    );

  typedef struct FunctionPointers {
    InitializeSessionPtr InitializeSession;
    CloseHandlePtr CloseHandle;
  } FunctionLoadStatus;

  SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFG_LIBRARY_H
