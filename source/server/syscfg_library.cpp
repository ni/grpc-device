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
  function_pointers_.CreateFilter = GET_POINTER(function_pointers_, shared_library_, CreateFilter);
  function_pointers_.SetFilterProperty = GET_POINTER(function_pointers_, shared_library_, SetFilterProperty);
  function_pointers_.FindHardware = GET_POINTER(function_pointers_, shared_library_, FindHardware);
  function_pointers_.NextResource = GET_POINTER(function_pointers_, shared_library_, NextResource);
  function_pointers_.GetResourceIndexedProperty = GET_POINTER(function_pointers_, shared_library_, GetResourceIndexedProperty);
  function_pointers_.GetResourceProperty = GET_POINTER(function_pointers_, shared_library_, GetResourceProperty);
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

NISysCfgStatus SysCfgLibrary::CreateHardwareFilter(
  NISysCfgSessionHandle session_handle,
  NISysCfgFilterHandle* filter_handle
  )
{
  if (!function_pointers_.CreateFilter) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  NISysCfgStatus status;
  if (NISysCfg_Succeeded(status = function_pointers_.CreateFilter(session_handle, filter_handle))) {
    function_pointers_.SetFilterProperty(*filter_handle, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
    function_pointers_.SetFilterProperty(*filter_handle, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
  }
  return status;
}

NISysCfgStatus SysCfgLibrary::FindHardware(
  NISysCfgSessionHandle session_handle,
  NISysCfgFilterMode filter_mode,
  NISysCfgFilterHandle filter_handle,
  const char* expert_names,
  NISysCfgEnumResourceHandle* resource_enum_handle
  )
{
  if (!function_pointers_.FindHardware) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.FindHardware(session_handle, filter_mode, filter_handle, expert_names, resource_enum_handle);
}

NISysCfgStatus SysCfgLibrary::NextResource(
  NISysCfgSessionHandle session_handle,
  NISysCfgEnumResourceHandle resource_enum_handle,
  NISysCfgResourceHandle* resource_handle
  )
{
  if (!function_pointers_.NextResource) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.NextResource(session_handle, resource_enum_handle, resource_handle);
}

NISysCfgStatus SysCfgLibrary::GetResourceIndexedProperty(
  NISysCfgResourceHandle resource_handle,
  NISysCfgIndexedProperty property_ID,
  unsigned int index,
  void* value
  )
{
  if (!function_pointers_.GetResourceIndexedProperty) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.GetResourceIndexedProperty(resource_handle, property_ID, index, value);
}

NISysCfgStatus SysCfgLibrary::GetResourceProperty(
  NISysCfgResourceHandle resource_handle,
  NISysCfgResourceProperty property_ID,
  void* value
  )
{
  if (!function_pointers_.GetResourceProperty) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.GetResourceProperty(resource_handle, property_ID, value);
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
