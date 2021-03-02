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
  function_pointers_.InitializeSession = reinterpret_cast<InitializeSessionPtr>(shared_library_.get_function_pointer("NISysCfgInitializeSession"));
  function_pointers_.CloseHandle  = reinterpret_cast<CloseHandlePtr>(shared_library_.get_function_pointer("NISysCfgCloseHandle"));
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
  const char*                            target_name,
  const char*                            username,
  const char*                            password,
  NISysCfgLocale                         language,
  NISysCfgBool                           force_property_refresh,
  unsigned int                           connect_timeout_msec,
  NISysCfgEnumExpertHandle*              expert_enum_handle,
  NISysCfgSessionHandle*                 session_handle
  )
{
  if (!function_pointers_.InitializeSession) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
#if defined(_MSC_VER)
  return NISysCfgInitializeSession(
    target_name,
    username,
    password,
    language,
    force_property_refresh,
    connect_timeout_msec,
    expert_enum_handle,
    session_handle
  );
#else
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
#endif
}

NISysCfgStatus SysCfgLibrary::CloseHandle(void* syscfg_handle)
{
  if (!function_pointers_.CloseHandle) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
#if defined(_MSC_VER)
  return NISysCfgCloseHandle(syscfg_handle);
#else
  return function_pointers_.CloseHandle(syscfg_handle);
#endif
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
