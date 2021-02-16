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

DeviceManagement::DeviceManagement()
    : syscfg_library_(syscfg_api_library_name)
{
}

DeviceManagement::DeviceManagement(const char* library_name)
    : syscfg_library_(library_name)
{
}

// Provides a list of devices or chassis connected to server under localhost. This internally uses the "NI System Configuration API". If it is not
// currently installed, it can be downloaded from this page: https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status DeviceManagement::enumerate_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices)
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

NISysCfgStatus DeviceManagement::get_list_of_devices(google::protobuf::RepeatedPtrField<NiDeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  // This will use syscfg APIs to get a list of devices or chassis under localhost
  // if any syscfg API gives error, it will be stored in status.
  return status;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
