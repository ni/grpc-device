#ifndef GRPC_NIDEVICE_SYSCFGLIBRARYINTERFACE_H
#define GRPC_NIDEVICE_SYSCFGLIBRARYINTERFACE_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

namespace grpc {
namespace nidevice {

class SysCfgLibraryInterface {
 public:
  virtual ~SysCfgLibraryInterface() {}

  virtual NISysCfgStatus InitializeSession(
    const char* target_name,
    const char* username,
    const char* password,
    NISysCfgLocale language,
    NISysCfgBool force_property_refresh,
    unsigned int connect_timeout_msec,
    NISysCfgEnumExpertHandle* expert_enum_handle,
    NISysCfgSessionHandle* session_handle
    ) = 0;
  virtual NISysCfgStatus CloseHandle(
    void* syscfg_handle
    ) = 0;
  // Additional methods like CreateFilter, FindHardware etc. will be added in upcoming PRs.
};

} // namespace nidevice
} // namespace grpc

#endif  // GRPC_NIDEVICE_SYSCFGLIBRARYINTERFACE_H
