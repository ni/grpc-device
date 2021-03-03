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
    const char*                            target_name,
    const char*                            username,
    const char*                            password,
    NISysCfgLocale                         language,
    NISysCfgBool                           force_property_refresh,
    unsigned int                           connect_timeout_msec,
    NISysCfgEnumExpertHandle*              expert_enum_handle,
    NISysCfgSessionHandle*                 session_handle
    ) = 0;
  virtual NISysCfgStatus CloseHandle(void* syscfg_handle) = 0;
  virtual NISysCfgStatus CreateFilter(
    NISysCfgSessionHandle                  session_handle,
    NISysCfgFilterHandle*                  filter_handle
    ) = 0;
  virtual NISysCfgStatus SetFilterProperty(
   NISysCfgFilterHandle                    filter_handle,
   NISysCfgFilterProperty                  property_ID,
   ...
   ) = 0;
  // Additional methods like FindHardware, NextResource etc. will be added in upcoming PRs.
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SYSCFGLIBRARYINTERFACE_H
