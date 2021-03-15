#include "device_enumerator.h"

namespace grpc {
namespace nidevice {

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

  try {
      session = get_syscfg_session(false);
    // All parameters of InitializeSession other than the first are System Configuration default values.
    if (session != nullptr) {
      if (NISysCfg_Succeeded(status = library_->CreateFilter(session, &filter))) {
        library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
        library_->SetFilterProperty(filter, NISysCfgFilterPropertyServiceType, NISysCfgServiceTypeLocalSystem);
        if (NISysCfg_Succeeded(status = library_->FindHardware(session, NISysCfgFilterModeMatchValuesAny, filter, NULL, &resources_handle))) {
          while (NISysCfg_Succeeded(status) && (status = library_->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library_->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyExpertName, 0, expert_name);
            if (strcmp(expert_name, kNetworkExpertName) != 0) {
              DeviceProperties* properties = devices->Add();
              // Note that we don't check for status of GetResourceIndexedProperty and GetResourceProperty APIs because
              // we want to return empty string when any of the property does not exist for any resource.
              library_->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyExpertUserAlias, 0, name);
              library_->GetResourceProperty(resource, NISysCfgResourcePropertyProductName, model);
              library_->GetResourceProperty(resource, NISysCfgResourcePropertyVendorName, vendor);
              library_->GetResourceProperty(resource, NISysCfgResourcePropertySerialNumber, serial_number);
              properties->set_name(name);
              properties->set_model(model);
              properties->set_vendor(vendor);
              properties->set_serial_number(serial_number);
            }
            library_->CloseHandle(resource);
          }
          library_->CloseHandle(resources_handle);
        }
        library_->CloseHandle(filter);
      }
      library_->CloseHandle(session);
    }
    else {
        return ::grpc::Status(::grpc::NOT_FOUND, kSysCfgLibraryLoadFailedMessage);
    }
  }
  catch (LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }

  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDeviceEnumerationFailedMessage);
  }

  return ::grpc::Status::OK;
}

// This method caches the NISysCfgSession into cached_syscfg_session field.
// This takes an optional reinitialize boolean as input which can be used to enforce initialization when needed.
// This method takes a unique lock to access cached_syscfg_session and returns if its not null.
// If cached_syscfg_session is null or reinitialize is true then it creates a new session closing the previous session.
// This method returns null session after failed initialization.
NISysCfgSessionHandle DeviceEnumerator::get_syscfg_session(bool reinitialize)
{
    std::unique_lock<std::shared_mutex> lock(session_mutex);
    NISysCfgStatus status = NISysCfg_OK;
    if (!reinitialize && cached_syscfg_session != nullptr) {
        return cached_syscfg_session;
    }
    else {
        if (cached_syscfg_session != nullptr) {
            library_->CloseHandle(cached_syscfg_session);
        }
        
        try {
            if (NISysCfg_Succeeded(status = library_->InitializeSession(kLocalHostTargetName, NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &cached_syscfg_session)))
                return cached_syscfg_session;
        }
        catch (LibraryLoadException& ex) {
            ::grpc::Status(::grpc::NOT_FOUND, ex.what());
            return nullptr;
        }
        // if InitializeSession doesn't throw an exception but status is not OK.
        return nullptr;
    }
}

//Calls Closehandle to clear sysconfig session.
void DeviceEnumerator::clear_sysconfig_session()
{
    std::unique_lock<std::shared_mutex> lock(session_mutex);
    library_->CloseHandle(cached_syscfg_session);
}

}  // namespace nidevice
}  // namespace grpc
