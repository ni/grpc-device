#include "device_enumerator.h"

namespace nidevice_grpc {

DeviceEnumerator::DeviceEnumerator(SysCfgLibraryInterface* library)
    : SysCfgSessionHandler(library)
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
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  char expert_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char model[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char vendor[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char serial_number[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  uint32_t product_id = 0;
  NISysCfgBool is_ni_product = NISysCfgBoolFalse;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAny, filter, NULL, &resources_handle))) {
          while (NISysCfg_Succeeded(status) && (status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library->GetResourceProperty(resource, NISysCfgResourcePropertyIsNIProduct, &is_ni_product);
            library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyExpertName, 0, expert_name);
            if (is_ni_product && strcmp(expert_name, kNetworkExpertName) != 0) {
              DeviceProperties* properties = devices->Add();
              // Note that we don't check for status of GetResourceIndexedProperty and GetResourceProperty APIs because
              // we want to return empty string when any of the property does not exist for any resource.
              library->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyExpertUserAlias, 0, name);
              library->GetResourceProperty(resource, NISysCfgResourcePropertyProductName, model);
              library->GetResourceProperty(resource, NISysCfgResourcePropertyVendorName, vendor);
              library->GetResourceProperty(resource, NISysCfgResourcePropertySerialNumber, serial_number);
              library->GetResourceProperty(resource, NISysCfgResourcePropertyProductId, &product_id);
              properties->set_name(name);
              properties->set_model(model);
              properties->set_vendor(vendor);
              properties->set_serial_number(serial_number);
              properties->set_product_id(product_id);
            }
            library->CloseHandle(resource);
          }
          library->CloseHandle(resources_handle);
        }
        library->CloseHandle(filter);
      }
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }

  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDeviceEnumerationFailedMessage);
  }

  return ::grpc::Status::OK;
}

}  // namespace nidevice_grpc
