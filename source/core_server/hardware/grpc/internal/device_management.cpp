#include "device_management.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

using NISysCfgInitializeSessionPtr = NISysCfgStatus (*)(
  const char*                            targetName,
  const char*                            username,
  const char*                            password,
  NISysCfgLocale                         language,
  NISysCfgBool                           forcePropertyRefresh,
  unsigned int                           connectTimeoutMsec,
  NISysCfgEnumExpertHandle*              expertEnumHandle,
  NISysCfgSessionHandle*                 sessionHandle
  );
using NISysCfgCreateFilterPtr = NISysCfgStatus(*)(
  NISysCfgSessionHandle                  sessionHandle,
  NISysCfgFilterHandle*                  filterHandle
  );
using NISysCfgSetFilterPropertyPtr = NISysCfgStatus (*)(
  NISysCfgFilterHandle                   filterHandle,
  NISysCfgFilterProperty                 propertyID,
  ...
  );
using NISysCfgFindHardwarePtr = NISysCfgStatus (*)(
  NISysCfgSessionHandle                  sessionHandle,
  NISysCfgFilterMode                     filterMode,
  NISysCfgFilterHandle                   filterHandle,
  const char*                            expertNames,
  NISysCfgEnumResourceHandle*            resourceEnumHandle
  );
using NISysCfgNextResourcePtr = NISysCfgStatus(*)(
  NISysCfgSessionHandle                  sessionHandle,
  NISysCfgEnumResourceHandle             resourceEnumHandle,
  NISysCfgResourceHandle*                resourceHandle
  );
using NISysCfgGetResourceIndexedPropertyPtr = NISysCfgStatus(*)(
  NISysCfgResourceHandle                 resourceHandle,
  NISysCfgIndexedProperty                propertyID,
  unsigned int                           index,
  void *                                 value
  );
using NISysCfgGetResourcePropertyPtr = NISysCfgStatus(*)(
  NISysCfgResourceHandle                 resourceHandle,
  NISysCfgResourceProperty               propertyID,
  void*                                  value
  );
using NISysCfgCloseHandlePtr = NISysCfgStatus(*)(void* syscfgHandle);

DeviceManagement::DeviceManagement()
{
}

NISysCfgStatus DeviceManagement::enumerate_devices(SharedLibrary* shared_library, google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  NISysCfgFilterHandle filter = NULL;
  char name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char serial_number[NISYSCFG_SIMPLE_STRING_LENGTH] = "";

  auto syscfg_initialize_session = reinterpret_cast<NISysCfgInitializeSessionPtr>(shared_library->get_function_pointer("NISysCfgInitializeSession"));
  auto syscfg_create_filter = reinterpret_cast<NISysCfgCreateFilterPtr>(shared_library->get_function_pointer("NISysCfgCreateFilter"));
  auto syscfg_set_filter_property = reinterpret_cast<NISysCfgSetFilterPropertyPtr>(shared_library->get_function_pointer("NISysCfgSetFilterProperty"));
  auto syscfg_find_hardware = reinterpret_cast<NISysCfgFindHardwarePtr>(shared_library->get_function_pointer("NISysCfgFindHardware"));
  auto sysycfg_next_resource = reinterpret_cast<NISysCfgNextResourcePtr>(shared_library->get_function_pointer("NISysCfgNextResource"));
  auto sysycfg_get_resource_indexed_property = reinterpret_cast<NISysCfgGetResourceIndexedPropertyPtr>(shared_library->get_function_pointer("NISysCfgGetResourceIndexedProperty"));
  auto sysycfg_get_resource_property = reinterpret_cast<NISysCfgGetResourcePropertyPtr>(shared_library->get_function_pointer("NISysCfgGetResourceProperty"));
  auto sysycfg_close_handle = reinterpret_cast<NISysCfgCloseHandlePtr>(shared_library->get_function_pointer("NISysCfgCloseHandle"));

  if (NISysCfg_Succeeded(status = syscfg_initialize_session("localhost", NULL, NULL, NISysCfgLocaleEnglish, NISysCfgBoolTrue, 10000, NULL, &session))) {
    if (NISysCfg_Succeeded(status = syscfg_create_filter(session, &filter))) {
      syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
      syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
      if (NISysCfg_Succeeded(status = syscfg_find_hardware(session, NISysCfgFilterModeAny, filter, NULL, &resources_handle))) {
        while (NISysCfg_Succeeded(status) && (status = sysycfg_next_resource(session, resources_handle, &resource)) == NISysCfg_OK) {
          NiDeviceProperties* properties = devices->Add();
          sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertUserAlias, 0, name);
          sysycfg_get_resource_property(resource, NISysCfgResourcePropertyProductName, model);
          sysycfg_get_resource_property(resource, NISysCfgResourcePropertyVendorName, vendor);
          sysycfg_get_resource_property(resource, NISysCfgResourcePropertySerialNumber, serial_number);
          properties->set_name(name);
          properties->set_model(model);
          properties->set_vendor(vendor);
          properties->set_serialnumber(serial_number);
          status = sysycfg_close_handle(resource);
        }
      }
    }
  }
  sysycfg_close_handle(filter);
  sysycfg_close_handle(resources_handle);
  sysycfg_close_handle(session);
  return status;
}

} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
