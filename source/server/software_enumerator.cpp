#include "software_enumerator.h"

namespace nidevice_grpc {

SoftwareEnumerator::SoftwareEnumerator(SysCfgLibraryInterface* library)
    : SysCfgSessionHandler(library)
{
}

SoftwareEnumerator::~SoftwareEnumerator()
{
}

// Provides a list of installed software on a server under localhost. This internally uses the
// "NI System Configuration API". If it is not currently installed, it can be downloaded from this page:
// https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status SoftwareEnumerator::enumerate_installed_software(
    ::grpc::ServerContext* context,
    bool include_hidden_packages,
    google::protobuf::RepeatedPtrField<SoftwareProperties>* software)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgEnumSoftwareComponentHandle installedComps = NULL;
  unsigned int numInstalledComps = 0;
  char package_id[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char package_version[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char product_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      auto item_types = include_hidden_packages ? NISysCfgIncludeItemsAllVisibleAndHidden : NISysCfgIncludeItemsAllVisible;
      if (NISysCfg_Succeeded(status = library->GetInstalledSoftwareComponents(session, item_types, NISysCfgBoolFalse, &installedComps))) {
        if (NISysCfg_Succeeded(status = library->ResetEnumeratorGetCount(installedComps, &numInstalledComps)) && numInstalledComps > 0) {
          while (NISysCfg_Succeeded(status) && (status = library->NextComponentInfo(installedComps, package_id, package_version, product_name, NULL, NULL)) == NISysCfg_OK) {
            SoftwareProperties* properties = software->Add();
            properties->set_package_id(package_id);
            properties->set_package_version(package_version);
            properties->set_product_name(product_name);
          }
        }

        library->CloseHandle(installedComps);
      }
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }

  if (NISysCfg_Failed(status)) {
    std::string description(kSoftwareEnumerationFailedMessage);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  }

  return ::grpc::Status::OK;
}

}  // namespace nidevice_grpc
