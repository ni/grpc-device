#include "syscfg_session_handler.h"

namespace nidevice_grpc {

SysCfgSessionHandler::SysCfgSessionHandler(SysCfgLibraryInterface* library)
    : library_(library), syscfg_session_(nullptr)
{
}

SysCfgSessionHandler::~SysCfgSessionHandler()
{
  // Caller is expected to close the syscfg session before calling destructor.
}

// Sets cached NISysCfgSession to passed session handle.
// Sets null to cached session after failed initialization.
// Returns status of getting valid cached_syscfg_session is successful.
NISysCfgStatus SysCfgSessionHandler::open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session)
{
  std::unique_lock<std::shared_mutex> lock(session_mutex_);
  NISysCfgStatus status = NISysCfg_OK;
  if (!syscfg_session_) {
    if (NISysCfg_Failed(status = library_->InitializeSession(kLocalHostTargetName, NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, kConnectionTimeoutMilliSec, NULL, &syscfg_session_))) {
      return status;
    }
  }
  *session = syscfg_session_;
  return status;
}

// Calls Closehandle to clear sysconfig session and sets cached_syscfg_session to null.
void SysCfgSessionHandler::clear_syscfg_session()
{
  std::unique_lock<std::shared_mutex> lock(session_mutex_);
  if (syscfg_session_) {
    library_->CloseHandle(syscfg_session_);
    syscfg_session_ = nullptr;
  }
}

// Returns status of cached session.
bool SysCfgSessionHandler::is_session_open()
{
  return syscfg_session_ != nullptr;
}

SysCfgLibraryInterface* SysCfgSessionHandler::get_syscfg_library_interface()
{
  return library_;
}

}  // namespace nidevice_grpc
