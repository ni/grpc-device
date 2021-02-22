#include "device_management.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

#if defined(_MSC_VER)
static const char* syscfg_api_library_name = "nisyscfg.dll";
#else
static const char* syscfg_api_library_name = "libnisyscfg.so";
#endif

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
    : syscfg_library_(syscfg_api_library_name)
{
}

DeviceManagement::DeviceManagement(const char* library_name)
    : syscfg_library_(library_name)
{
  syscfg_library_->set_library_name(syscfg_api_library_name);
  cached_syscfg_session = get_syscfg_session(false);
  }
}

// This method caches the NISysCfgSession into cached_syscfg_session field.
// This takes an optional reinitialize boolean as input which can be used to enforce initialization when needed.
// This method takes a unique lock to access cached_syscfg_session and returns if its not null otherwise creates a new session
// when reinitialize is true or cached_syscfg_session is null and returns it.
// This method doesn't check for return of null session after failed initialization.
NISysCfgSessionHandle DeviceManagement::get_syscfg_session(bool reinitialize = false)
{
  std::unique_lock<std::shared_mutex> lock(session_mutex);
  if (!reinitialize && cached_syscfg_session != nullptr) {
    return cached_syscfg_session;
  }
  else {

      if (cached_syscfg_session == nullptr) {
      syscfg_library_->load();
      if (!syscfg_library_->is_loaded()) {
        std::string message("The library could not be loaded: ");
        message += syscfg_api_library_name;
      }
    
      // Need to Initialize syscfg session here by calling NISysCfgInitializeSession. NISysCfgInitializeSession should exist.
      /*
      auto niSysCfg_Initialize_Session_function = (NISysCfgSessionHandle*)syscfg_library_->get_function_pointer("NISysCfgInitializeSession");
      if (niSysCfg_Initialize_Session_function == nullptr) {
        return nullptr;
      }
      niSysCfg_Initialize_Session_function("localhost", NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &cached_syscfg_session); */
      return cached_syscfg_session;
  }
}

// Provides a list of devices or chassis connected to server under localhost. This internally uses the "NI System Configuration API". If it is not
// currently installed, it can be downloaded from this page: https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status DeviceManagement::enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  syscfg_library_.load();

  if (!syscfg_library_.is_loaded()) {
    std::string message("The library could not be loaded: ");
    message += syscfg_api_library_name;
    return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, message.c_str());
  }

  NISysCfgStatus status = get_list_of_devices(devices);
  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "The NI System Configuration API was unable to enumerate the devices.");
  }

  return ::grpc::Status::OK;
}

std::string DeviceManagement::get_syscfg_library_name() const
{
  return syscfg_library_.get_library_name();
}

bool DeviceManagement::is_syscfg_library_loaded() const
{
  return syscfg_library_.is_loaded();
}

NISysCfgStatus DeviceManagement::get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  NISysCfgFilterHandle filter = NULL;
  char expert_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char serial_number[NISYSCFG_SIMPLE_STRING_LENGTH] = "";

  auto syscfg_initialize_session = reinterpret_cast<NISysCfgInitializeSessionPtr>(syscfg_library_.get_function_pointer("NISysCfgInitializeSession"));
  auto syscfg_create_filter = reinterpret_cast<NISysCfgCreateFilterPtr>(syscfg_library_.get_function_pointer("NISysCfgCreateFilter"));
  auto syscfg_set_filter_property = reinterpret_cast<NISysCfgSetFilterPropertyPtr>(syscfg_library_.get_function_pointer("NISysCfgSetFilterProperty"));
  auto syscfg_find_hardware = reinterpret_cast<NISysCfgFindHardwarePtr>(syscfg_library_.get_function_pointer("NISysCfgFindHardware"));
  auto sysycfg_next_resource = reinterpret_cast<NISysCfgNextResourcePtr>(syscfg_library_.get_function_pointer("NISysCfgNextResource"));
  auto sysycfg_get_resource_indexed_property = reinterpret_cast<NISysCfgGetResourceIndexedPropertyPtr>(syscfg_library_.get_function_pointer("NISysCfgGetResourceIndexedProperty"));
  auto sysycfg_get_resource_property = reinterpret_cast<NISysCfgGetResourcePropertyPtr>(syscfg_library_.get_function_pointer("NISysCfgGetResourceProperty"));
  auto sysycfg_close_handle = reinterpret_cast<NISysCfgCloseHandlePtr>(syscfg_library_.get_function_pointer("NISysCfgCloseHandle"));

  if (NISysCfg_Succeeded(status = syscfg_initialize_session("localhost", NULL, NULL, NISysCfgLocaleEnglish, NISysCfgBoolTrue, 10000, NULL, &session))) {
    if (NISysCfg_Succeeded(status = syscfg_create_filter(session, &filter))) {
      syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
      syscfg_set_filter_property(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
      if (NISysCfg_Succeeded(status = syscfg_find_hardware(session, NISysCfgFilterModeAny, filter, NULL, &resources_handle))) {
        while (NISysCfg_Succeeded(status) && (status = sysycfg_next_resource(session, resources_handle, &resource)) == NISysCfg_OK) {
          sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertName, 0, expert_name);
          if ((strcmp(expert_name, "network") != 0)) {
            DeviceProperties* properties = devices->Add();
            sysycfg_get_resource_indexed_property(resource, NISysCfgIndexedPropertyExpertUserAlias, 0, name);
            sysycfg_get_resource_property(resource, NISysCfgResourcePropertyProductName, model);
            sysycfg_get_resource_property(resource, NISysCfgResourcePropertyVendorName, vendor);
            sysycfg_get_resource_property(resource, NISysCfgResourcePropertySerialNumber, serial_number);
            properties->set_name(name);
            properties->set_model(model);
            properties->set_vendor(vendor);
            properties->set_serial_number(serial_number);
            status = sysycfg_close_handle(resource);
          }
        }
      }
    }
  }
  sysycfg_close_handle(filter);
  sysycfg_close_handle(resources_handle);
  sysycfg_close_handle(session);
  return status;
}

void DeviceManagement::clear_sysconfig_session()
{
  std::unique_lock<std::shared_mutex> lock(session_mutex);
  cached_syscfg_session = nullptr;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni