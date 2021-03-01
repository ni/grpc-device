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
  // Delay loading of nisyscfg dll and initializing function pointers will be implemented in upcoming PRs.
}

SysCfgLibrary::~SysCfgLibrary()
{
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
  NISysCfgSessionHandle session = NULL;
  bool is_syscfg_api_installed = false;

#if defined(_MSC_VER)
  NISysCfgStatus status = NISysCfgInitializeSession(
    targetName,
    username,
    password,
    language,
    forcePropertyRefresh,
    connectTimeoutMsec,
    expertEnumHandle,
    sessionHandle);
  is_syscfg_api_installed = status != NISysCfg_SysConfigAPINotInstalled;
#else
  is_syscfg_api_installed = shared_library_.is_loaded();
#endif

  if (!is_syscfg_api_installed) {
    throw ni::hardware::grpc::internal::LibraryLoadException("The NI System Configuration API is not installed on the server.");
  }

  return status;
}

NISysCfgStatus SysCfgLibrary::CloseHandle(void* syscfg_handle)
{
  bool is_syscfg_api_installed = false;

#if defined(_MSC_VER)
  NISysCfgStatus status = NISysCfgCloseHandle(syscfg_handle);
  is_syscfg_api_installed = status != NISysCfg_SysConfigAPINotInstalled;
#else
  is_syscfg_api_installed = shared_library_.is_loaded();
#endif

  if (!is_syscfg_api_installed) {
    throw ni::hardware::grpc::internal::LibraryLoadException("The NI System Configuration API is not installed on the server.");
  }

  return status;
}

std::string SysCfgLibrary::get_library_name() const
{
  return shared_library_.get_library_name();
}

bool SysCfgLibrary::is_library_loaded() const
{
  return shared_library_.is_loaded();
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
