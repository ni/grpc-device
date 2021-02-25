#include "device_enumerator.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

DeviceEnumerator::DeviceEnumerator(SysCfgLibraryInterface* library)
    : library_(library)
{
}

DeviceEnumerator::~DeviceEnumerator()
{
}

// Provides a list of devices or chassis connected to server under localhost. This internally uses the
// "NI System Configuration API". If it is not currently installed, it can be downloaded from this page:
// https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status DeviceEnumerator::enumerate_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  NISysCfgStatus syscfg_status = NISysCfg_OK;
  
  try {
    // Providing dummy implementation below which will be updated in upcoming PRs 
    // to use syscfg APIs properly to enumerate devices.
    syscfg_status = library_->FindHardware(); 
  }
  catch (ni::hardware::grpc::internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
  
  if (NISysCfg_Failed(syscfg_status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "The NI System Configuration API was unable to enumerate the devices.");
  }

  return ::grpc::Status::OK;
}

NISysCfgStatus DeviceEnumerator::get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  // This will use syscfg APIs to get a list of devices or chassis under localhost
  // if any syscfg API gives error, it will be stored in status.
  status = library_->FindHardware();
  return status;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
