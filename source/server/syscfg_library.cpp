#include "syscfg_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

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
  const char *                           targetName,
  const char *                           username,
  const char *                           password,
  NISysCfgLocale                         language,
  NISysCfgBool                           forcePropertyRefresh,
  unsigned int                           connectTimeoutMsec,
  NISysCfgEnumExpertHandle *             expertEnumHandle,
  NISysCfgSessionHandle *                sessionHandle
  )
{
  if (!function_pointers_.InitializeSession) {
    throw ni::hardware::grpc::internal::LibraryLoadException("The NI System Configuration API is not installed on the server.");
  }
#if defined(_MSC_VER)
  return NISysCfgInitializeSession(
    targetName,
    username,
    password,
    language,
    forcePropertyRefresh,
    connectTimeoutMsec,
    expertEnumHandle,
    sessionHandle
  );
#else
  return function_pointers_.InitializeSession(
    targetName,
    username,
    password,
    language,
    forcePropertyRefresh,
    connectTimeoutMsec,
    expertEnumHandle,
    sessionHandle
  );
#endif
}

NISysCfgStatus SysCfgLibrary::CloseHandle(void* syscfg_handle)
{
  if (!function_pointers_.CloseHandle) {
    throw ni::hardware::grpc::internal::LibraryLoadException("The NI System Configuration API is not installed on the server.");
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
