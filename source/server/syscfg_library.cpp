#include "syscfg_library.h"

#define GET_POINTER(ptrs, lib, name) \
  ptrs.name = reinterpret_cast<name##Ptr>(lib.get_function_pointer("NISysCfg" #name));

namespace nidevice_grpc {

SysCfgLibrary::SysCfgLibrary()
    : shared_library_(kSysCfgApiLibraryName)
{
  shared_library_.load();
  memset(&function_pointers_, 0, sizeof(function_pointers_));
  if (!shared_library_.is_loaded()) {
    return;
  }
  GET_POINTER(function_pointers_, shared_library_, InitializeSession);
  GET_POINTER(function_pointers_, shared_library_, CloseHandle);
  GET_POINTER(function_pointers_, shared_library_, CreateFilter);
  GET_POINTER(function_pointers_, shared_library_, SetFilterPropertyV);
  GET_POINTER(function_pointers_, shared_library_, FindHardware);
  GET_POINTER(function_pointers_, shared_library_, NextResource);
  GET_POINTER(function_pointers_, shared_library_, GetResourceIndexedProperty);
  GET_POINTER(function_pointers_, shared_library_, GetResourceProperty);
  GET_POINTER(function_pointers_, shared_library_, SetResourcePropertyV);
  GET_POINTER(function_pointers_, shared_library_, SaveResourceChanges);
  GET_POINTER(function_pointers_, shared_library_, FreeDetailedString);
  GET_POINTER(function_pointers_, shared_library_, GetInstalledSoftwareComponents);
  GET_POINTER(function_pointers_, shared_library_, ResetEnumeratorGetCount);
  GET_POINTER(function_pointers_, shared_library_, NextComponentInfo);
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
    NISysCfgSessionHandle* session_handle)
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
      session_handle);
}

NISysCfgStatus SysCfgLibrary::CloseHandle(void* syscfg_handle)
{
  if (!function_pointers_.CloseHandle) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.CloseHandle(syscfg_handle);
}

NISysCfgStatus SysCfgLibrary::CreateFilter(
    NISysCfgSessionHandle session_handle,
    NISysCfgFilterHandle* filter_handle)
{
  if (!function_pointers_.CreateFilter) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.CreateFilter(session_handle, filter_handle);
}

NISysCfgStatus SysCfgLibrary::SetFilterProperty(
    NISysCfgFilterHandle filter_handle,
    NISysCfgFilterProperty property_ID,
    ...)
{
  if (!function_pointers_.SetFilterPropertyV) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  va_list args;
  NISysCfgStatus status;
  va_start(args, property_ID);
  status = function_pointers_.SetFilterPropertyV(filter_handle, property_ID, args);
  va_end(args);
  return status;
}

NISysCfgStatus SysCfgLibrary::FindHardware(
    NISysCfgSessionHandle session_handle,
    NISysCfgFilterMode filter_mode,
    NISysCfgFilterHandle filter_handle,
    const char* expert_names,
    NISysCfgEnumResourceHandle* resource_enum_handle)
{
  if (!function_pointers_.FindHardware) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.FindHardware(session_handle, filter_mode, filter_handle, expert_names, resource_enum_handle);
}

NISysCfgStatus SysCfgLibrary::NextResource(
    NISysCfgSessionHandle session_handle,
    NISysCfgEnumResourceHandle resource_enum_handle,
    NISysCfgResourceHandle* resource_handle)
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
    void* value)
{
  if (!function_pointers_.GetResourceIndexedProperty) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.GetResourceIndexedProperty(resource_handle, property_ID, index, value);
}

NISysCfgStatus SysCfgLibrary::GetResourceProperty(
    NISysCfgResourceHandle resource_handle,
    NISysCfgResourceProperty property_ID,
    void* value)
{
  if (!function_pointers_.GetResourceProperty) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.GetResourceProperty(resource_handle, property_ID, value);
}

NISysCfgStatus SysCfgLibrary::SetResourceProperty(
    NISysCfgResourceHandle resource_handle,
    NISysCfgResourceProperty property_ID,
    ...)
{
  if (!function_pointers_.SetResourcePropertyV) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  va_list args;
  NISysCfgStatus status;
  va_start(args, property_ID);
  status = function_pointers_.SetResourcePropertyV(resource_handle, property_ID, args);
  va_end(args);
  return status;
}

NISysCfgStatus SysCfgLibrary::SaveResourceChanges(
    NISysCfgResourceHandle resource_handle,
    NISysCfgBool* changes_require_restart,
    char** detailed_result)
{
  if (!function_pointers_.SaveResourceChanges) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.SaveResourceChanges(resource_handle, changes_require_restart, detailed_result);
}

NISysCfgStatus SysCfgLibrary::FreeDetailedString(char str[])
{
  if (!function_pointers_.FreeDetailedString) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.FreeDetailedString(str);
}

NISysCfgStatus SysCfgLibrary::GetInstalledSoftwareComponents(
    NISysCfgSessionHandle session_handle,
    NISysCfgIncludeComponentTypes item_types,
    NISysCfgBool cached,
    NISysCfgEnumSoftwareComponentHandle* component_enum_handle)
{
  if (!function_pointers_.GetInstalledSoftwareComponents) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.GetInstalledSoftwareComponents(session_handle, item_types, cached, component_enum_handle);
}

NISysCfgStatus SysCfgLibrary::ResetEnumeratorGetCount(
    void* enum_handle,
    unsigned int* count)
{
  if (!function_pointers_.ResetEnumeratorGetCount) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.ResetEnumeratorGetCount(enum_handle, count);
}

NISysCfgStatus SysCfgLibrary::NextComponentInfo(
    NISysCfgEnumSoftwareComponentHandle component_enum_handle,
    char* id,
    char* version,
    char* title,
    NISysCfgComponentType* itemType,
    char** detailedDescription)
{
  if (!function_pointers_.NextComponentInfo) {
    throw LibraryLoadException(kSysCfgApiNotInstalledMessage);
  }
  return function_pointers_.NextComponentInfo(component_enum_handle, id, version, title, itemType, detailedDescription);
}

}  // namespace nidevice_grpc
