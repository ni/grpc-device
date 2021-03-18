#include "device_enumerator.h"

#include <shared_mutex>

#include "syscfg_library.h"

namespace grpc {
namespace nidevice {

DeviceEnumerator::DeviceEnumerator(SysCfgLibraryInterface* library)
    : library_(library)
{
  cached_syscfg_session = nullptr;
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
  NISysCfgBool is_ni_product = NISysCfgBoolFalse;

  try {
    if (NISysCfg_Succeeded(status = get_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library_->CreateFilter(session, &filter))) {
        library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
        if (NISysCfg_Succeeded(status = library_->FindHardware(session, NISysCfgFilterModeMatchValuesAny, filter, NULL, &resources_handle))) {
          while (NISysCfg_Succeeded(status) && (status = library_->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library_->GetResourceProperty(resource, NISysCfgResourcePropertyIsNIProduct, &is_ni_product);
            library_->GetResourceIndexedProperty(resource, NISysCfgIndexedPropertyExpertName, 0, expert_name);
            if (is_ni_product && strcmp(expert_name, kNetworkExpertName) != 0) {
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
    }
    else {
      return ::grpc::Status(::grpc::NOT_FOUND, kSysCfgApiNotInstalledMessage);
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

// Returns cached NISysCfgSession.
// This takes an optional reinitialize boolean as input which can be used to enforce initialization when needed.
// Returns null session after failed initialization.
NISysCfgStatus DeviceEnumerator::get_syscfg_session(NISysCfgSessionHandle* session)
{
  std::unique_lock<std::shared_mutex> lock(session_mutex);
  NISysCfgStatus status = NISysCfg_OK;
  if (cached_syscfg_session == nullptr) {
    if (NISysCfg_Failed(status = library_->InitializeSession(kLocalHostTargetName, NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &cached_syscfg_session)))
      return status;
  }
  session = &cached_syscfg_session;
  return status;
}

//Calls Closehandle to clear sysconfig session and sets cached_syscfg_session to null.
void DeviceEnumerator::clear_sysconfig_session()
{
  std::unique_lock<std::shared_mutex> lock(session_mutex);
  library_->CloseHandle(cached_syscfg_session);
  cached_syscfg_session = nullptr;
}

}  // namespace nidevice
}  // namespace grpc