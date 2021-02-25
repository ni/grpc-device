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
  ::grpc::Status library_status = library_->check_library_exists();
  if (!library_status.ok()) {
    return library_status;
  }

  NISysCfgStatus syscfg_status = get_list_of_devices(devices);
  if (NISysCfg_Failed(syscfg_status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "The NI System Configuration API was unable to enumerate the devices.");
  }

  return ::grpc::Status::OK;
}

NISysCfgStatus DeviceEnumerator::get_list_of_devices(google::protobuf::RepeatedPtrField<DeviceProperties>* devices)
{
  NISysCfgStatus status = NISysCfg_OK;
  // Note: Since this is just an RFC PR, I have given simple implementation below. But when actual PR is created,
  // then all steps starting from InitializeSession will be followed correctly.
  NISysCfgResourceHandle resource = NULL;
  char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";

  if (NISysCfg_Succeeded(status = library_->FindHardware())) {
    while (NISysCfg_Succeeded(status) && (status = library_->NextResource(&resource)) == NISysCfg_OK) {
      DeviceProperties* properties = devices->Add();
      library_->GetResourceProperty(resource, NISysCfgResourcePropertyProductName, model);
      library_->GetResourceProperty(resource, NISysCfgResourcePropertyVendorName, vendor);
      properties->set_model(model);
      properties->set_vendor(vendor);
      library_->CloseHandle(resource);
    }
  }

  return status;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
