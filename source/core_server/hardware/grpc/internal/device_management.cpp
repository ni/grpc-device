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

DeviceManagement::DeviceManagement(internal::SharedLibrary* syscfg_library)
    : syscfg_library_(syscfg_library)
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
  if (cached_syscfg_session == nullptr) {
    syscfg_library_->load();
    if (!syscfg_library_->is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += syscfg_api_library_name;
    }

  std::unique_lock<std::shared_mutex> lock(session_mutex);
  if (!reinitialize && cached_syscfg_session != nullptr) {
    return cached_syscfg_session;
  }
  else {
    
      cached_syscfg_session = get_syscfg_session(true);
      // Need to Initialize syscfg session here by calling NISysCfgInitializeSession. NISysCfgInitializeSession should exist.
      auto niSysCfg_Initialize_Session_function = (NISysCfgSessionHandle*)syscfg_library_->get_function_pointer("NISysCfgInitializeSession");
      if (niSysCfg_Initialize_Session_function == nullptr) {
        return nullptr;
      }
      niSysCfg_Initialize_Session_function("localhost", NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &cached_syscfg_session);
      return cached_syscfg_session;
  }
}

// Provides a list of devices or chassis connected to server under localhost. This internally uses the "NI System Configuration API". If it is not
// currently installed, it can be downloaded from this page: https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status DeviceManagement::enumerate_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices)
{
  syscfg_library_->load();
  if (!syscfg_library_->is_loaded()) {
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

NISysCfgStatus DeviceManagement::get_list_of_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  // This will use syscfg APIs to get a list of devices or chassis under localhost
  // if any syscfg API gives error, it will be stored in status.
  return status;
}

void DeviceManagement::clear_sysconfig_session()
{
  cached_syscfg_session = nullptr;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni