#include "syscfg_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

SysCfgLibrary::SysCfgLibrary()
    : shared_library_(kSysCfgApiLibraryName)
{
  shared_library_.load();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!shared_library_.is_loaded()) {
    return;
  }
  function_pointers_.InitializeSession = GET_POINTER(function_pointers_, shared_library_, InitializeSession);
  function_pointers_.CloseHandle = GET_POINTER(function_pointers_, shared_library_, CloseHandle);
}

SysCfgLibrary::~SysCfgLibrary()
{
}

std::string SysCfgLibrary::get_library_name() const
{
  return shared_library_.get_library_name();
}

bool SysCfgLibrary::is_library_loaded() const
{
  return shared_library_.is_loaded();
}

NISysCfgStatus SysCfgLibrary::InitializeSession(
  const char* target_name,
  const char* username,
  const char* password,
  NISysCfgLocale language,
  NISysCfgBool force_property_refresh,
  unsigned int connect_timeout_msec,
  NISysCfgEnumExpertHandle* expert_enum_handle,
  NISysCfgSessionHandle* session_handle
  )
{
  if (!function_pointers_.InitializeSession) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.InitializeSession(
    target_name,
    username,
    password,
    language,
    force_property_refresh,
    connect_timeout_msec,
    expert_enum_handle,
    session_handle
  );
}

NISysCfgStatus SysCfgLibrary::CloseHandle(void* syscfg_handle)
{
  if (!function_pointers_.CloseHandle) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.CloseHandle(syscfg_handle);
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
