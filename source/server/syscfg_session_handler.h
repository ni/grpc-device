#ifndef NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H
#define NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H

#include <shared_mutex>

#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace nidevice_grpc {

static const char* kLocalHostTargetName = "localhost";
static const char* kNetworkExpertName = "network";
static const int kConnectionTimeoutMilliSec = 10000;

class SysCfgSessionHandler {
 public:
  SysCfgSessionHandler(SysCfgLibraryInterface* library);
  virtual ~SysCfgSessionHandler();

  virtual NISysCfgStatus open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session);
  virtual void clear_syscfg_session();
  virtual bool is_session_open();

 protected:
  virtual SysCfgLibraryInterface* get_syscfg_library_interface();

 private:
  SysCfgLibraryInterface* library_;
  std::shared_mutex session_mutex_;
  NISysCfgSessionHandle syscfg_session_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H
