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
  NISysCfgResourceHandle resource = NULL;
  char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  
  try {
    // Providing dummy implementation below which will be updated in upcoming PRs 
    // to use syscfg APIs properly to enumerate devices.
    if (NISysCfg_Succeeded(syscfg_status = library_->FindHardware())) {
      while (NISysCfg_Succeeded(syscfg_status) && (syscfg_status = library_->NextResource(&resource)) == NISysCfg_OK) {
        DeviceProperties* properties = devices->Add();
        library_->GetResourceProperty(resource, NISysCfgResourcePropertyProductName, model);
        library_->GetResourceProperty(resource, NISysCfgResourcePropertyVendorName, vendor);
        properties->set_model(model);
        properties->set_vendor(vendor);
        library_->CloseHandle(resource);
      }
    }
  }
  catch (ni::hardware::grpc::internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
  
  if (NISysCfg_Failed(syscfg_status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "The NI System Configuration API was unable to enumerate the devices.");
  }

  return ::grpc::Status::OK;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
