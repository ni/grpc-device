#include "device_enumerator_library.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

DeviceEnumeratorLibrary::DeviceEnumeratorLibrary()
    : shared_library_(kSysCfgApiLibraryName)
{
  // Delay loading of nisyscfg dll and initializing function pointers will be implemented in upcoming PRs.
}

DeviceEnumeratorLibrary::~DeviceEnumeratorLibrary()
{
}

::grpc::Status DeviceEnumeratorLibrary::check_library_exists()
{
  if (!shared_library_.is_loaded()) {
    std::string message("Could not load the library: ");
    message += kSysCfgApiLibraryName;
    return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, message.c_str());
  }
  return ::grpc::Status::OK;
}

std::string DeviceEnumeratorLibrary::get_library_name() const
{
  return shared_library_.get_library_name();
}

bool DeviceEnumeratorLibrary::is_library_loaded() const
{
  return shared_library_.is_loaded();
}

NISysCfgStatus DeviceEnumeratorLibrary::FindHardware()
{
  // Implementation will be added in upcoming PRs.
  return NISysCfg_OK;
}

NISysCfgStatus DeviceEnumeratorLibrary::NextResource(NISysCfgResourceHandle* resourceHandle)
{
  // Implementation will be added in upcoming PRs.
  return NISysCfg_OK;
}

NISysCfgStatus DeviceEnumeratorLibrary::GetResourceProperty(NISysCfgEnumResourceHandle resourceEnumHandle, NISysCfgResourceProperty propertyID, void* value)
{
  // Implementation will be added in upcoming PRs.
  return NISysCfg_OK;
}

NISysCfgStatus DeviceEnumeratorLibrary::CloseHandle(void* syscfgHandle)
{
  // Implementation will be added in upcoming PRs.
  return NISysCfg_OK;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
