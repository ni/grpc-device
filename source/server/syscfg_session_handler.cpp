#include "syscfg_session_handler.h"

#include "converters.h"

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

// Creates a ::grpc::Status from status parameter
::grpc::Status SysCfgSessionHandler::convert_api_error_status_for_syscfg_session(
  ::grpc::ServerContext* context,
  NISysCfgStatus status,
  NISysCfgSessionHandle session)
{
  std::string empty_description;
  return convert_api_error_status_for_syscfg_session(context, status, empty_description, session);
}

// Creates a ::grpc::Status from status and description parameters
// If description parameter is empty, calls GetStatusDescription on NISysCfg
// session parameter can be NULL
::grpc::Status SysCfgSessionHandler::convert_api_error_status_for_syscfg_session(
  ::grpc::ServerContext* context,
  NISysCfgStatus status,
  const std::string& description,
  NISysCfgSessionHandle session)
{
  std::string local_description(description);
  if (local_description.empty()) {
    char* detailed_description = nullptr;
    library_->GetStatusDescription(session, status, &detailed_description);
    if (detailed_description != nullptr) {
      local_description = detailed_description;
      library_->FreeDetailedString(detailed_description);
    }
  }
  if (local_description.length() > nidevice_grpc::kMaxGrpcErrorDescriptionSize) {
    local_description.resize(nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, local_description);
}

void SysCfgSessionHandler::on_server_reset()
{
  clear_syscfg_session();
}

SysCfgLibraryInterface* SysCfgSessionHandler::get_syscfg_library_interface()
{
  return library_;
}

}  // namespace nidevice_grpc
