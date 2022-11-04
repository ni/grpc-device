#ifndef NIDEVICE_GRPC_SYSCFG_LIBRARY_INTERFACE_H
#define NIDEVICE_GRPC_SYSCFG_LIBRARY_INTERFACE_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

namespace nidevice_grpc {

class SysCfgLibraryInterface {
 public:
  virtual ~SysCfgLibraryInterface() {}

  virtual NISysCfgStatus InitializeSession(
      const char* target_name,
      const char* username,
      const char* password,
      NISysCfgLocale language,
      NISysCfgBool force_property_refresh,
      unsigned int connect_timeout_msec,
      NISysCfgEnumExpertHandle* expert_enum_handle,
      NISysCfgSessionHandle* session_handle) = 0;
  virtual NISysCfgStatus CloseHandle(
      void* syscfg_handle) = 0;
  virtual NISysCfgStatus CreateFilter(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterHandle* filter_handle) = 0;
  virtual NISysCfgStatus SetFilterProperty(
      NISysCfgFilterHandle filter_handle,
      NISysCfgFilterProperty property_ID,
      ...) = 0;
  virtual NISysCfgStatus FindHardware(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterMode filter_mode,
      NISysCfgFilterHandle filter_handle,
      const char* expert_names,
      NISysCfgEnumResourceHandle* resource_enum_handle) = 0;
  virtual NISysCfgStatus NextResource(
      NISysCfgSessionHandle session_handle,
      NISysCfgEnumResourceHandle resource_enum_handle,
      NISysCfgResourceHandle* resource_handle) = 0;
  virtual NISysCfgStatus GetResourceIndexedProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgIndexedProperty property_ID,
      unsigned int index,
      void* value) = 0;
  virtual NISysCfgStatus GetResourceProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      void* value) = 0;
  virtual NISysCfgStatus SetResourceProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      ...) = 0;
  virtual NISysCfgStatus SaveResourceChanges(
      NISysCfgResourceHandle resource_handle,
      NISysCfgBool* changes_require_restart,
      char** detailed_result) = 0;
  virtual NISysCfgStatus FreeDetailedString(
      char str[]) = 0;
  virtual NISysCfgStatus GetInstalledSoftwareComponents(
      NISysCfgSessionHandle session_handle,
      NISysCfgIncludeComponentTypes item_types,
      NISysCfgBool cached,
      NISysCfgEnumSoftwareComponentHandle* component_enum_handle) = 0;
  virtual NISysCfgStatus ResetEnumeratorGetCount(
      void* enumHandle,
      unsigned int* count) = 0;
  virtual NISysCfgStatus NextComponentInfo(
      NISysCfgEnumSoftwareComponentHandle component_enum_handle,
      char* id,
      char* version,
      char* title,
      NISysCfgComponentType* itemType,
      char** detailedDescription) = 0;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SYSCFG_LIBRARY_INTERFACE_H
