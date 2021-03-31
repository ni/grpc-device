#ifndef NIDEVICE_GRPC_SYSCFG_LIBRARY_H
#define NIDEVICE_GRPC_SYSCFG_LIBRARY_H

#include <grpcpp/grpcpp.h>
#include <nisyscfg.h>

#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace nidevice_grpc {

#if defined(_MSC_VER)
static const char* kSysCfgApiLibraryName = "nisyscfg.dll";
#else
static const char* kSysCfgApiLibraryName = "libnisyscfg.so";
#endif

static const char* kSysCfgApiNotInstalledMessage = "The NI System Configuration API is not installed on the server.";

class SysCfgLibrary : public SysCfgLibraryInterface {
 public:
  SysCfgLibrary();
  virtual ~SysCfgLibrary();

  std::string get_library_name() const;
  bool is_library_loaded() const;
  NISysCfgStatus InitializeSession(
      const char* target_name,
      const char* username,
      const char* password,
      NISysCfgLocale language,
      NISysCfgBool force_property_refresh,
      unsigned int connect_timeout_msec,
      NISysCfgEnumExpertHandle* expert_enum_handle,
      NISysCfgSessionHandle* session_handle);
  NISysCfgStatus CloseHandle(
      void* syscfg_handle);
  NISysCfgStatus CreateFilter(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterHandle* filter_handle);
  NISysCfgStatus SetFilterProperty(
      NISysCfgFilterHandle filter_handle,
      NISysCfgFilterProperty property_ID,
      ...);
  NISysCfgStatus FindHardware(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterMode filter_mode,
      NISysCfgFilterHandle filter_handle,
      const char* expert_names,
      NISysCfgEnumResourceHandle* resource_enum_handle);
  NISysCfgStatus NextResource(
      NISysCfgSessionHandle session_handle,
      NISysCfgEnumResourceHandle resource_enum_handle,
      NISysCfgResourceHandle* resource_handle);
  NISysCfgStatus GetResourceIndexedProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgIndexedProperty property_ID,
      unsigned int index,
      void* value);
  NISysCfgStatus GetResourceProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      void* value);

 private:
  using InitializeSessionPtr = NISysCfgStatus (*)(
      const char* target_name,
      const char* username,
      const char* password,
      NISysCfgLocale language,
      NISysCfgBool force_property_refresh,
      unsigned int connect_timeout_msec,
      NISysCfgEnumExpertHandle* expert_enum_handle,
      NISysCfgSessionHandle* session_handle);
  using CloseHandlePtr = NISysCfgStatus (*)(
      void* syscfg_handle);
  using CreateFilterPtr = NISysCfgStatus (*)(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterHandle* filter_handle);
  using SetFilterPropertyVPtr = NISysCfgStatus (*)(
      NISysCfgFilterHandle filter_handle,
      NISysCfgFilterProperty property_ID,
      va_list args);
  using FindHardwarePtr = NISysCfgStatus (*)(
      NISysCfgSessionHandle session_handle,
      NISysCfgFilterMode filter_mode,
      NISysCfgFilterHandle filter_handle,
      const char* expert_names,
      NISysCfgEnumResourceHandle* resource_enum_handle);
  using NextResourcePtr = NISysCfgStatus (*)(
      NISysCfgSessionHandle session_handle,
      NISysCfgEnumResourceHandle resource_enum_handle,
      NISysCfgResourceHandle* resource_handle);
  using GetResourceIndexedPropertyPtr = NISysCfgStatus (*)(
      NISysCfgResourceHandle resource_handle,
      NISysCfgIndexedProperty property_ID,
      unsigned int index,
      void* value);
  using GetResourcePropertyPtr = NISysCfgStatus (*)(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      void* value);

  typedef struct FunctionPointers {
    InitializeSessionPtr InitializeSession;
    CloseHandlePtr CloseHandle;
    CreateFilterPtr CreateFilter;
    SetFilterPropertyVPtr SetFilterPropertyV;
    FindHardwarePtr FindHardware;
    NextResourcePtr NextResource;
    GetResourceIndexedPropertyPtr GetResourceIndexedProperty;
    GetResourcePropertyPtr GetResourceProperty;
  } FunctionLoadStatus;

  SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SYSCFG_LIBRARY_H
