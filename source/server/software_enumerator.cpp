#include "software_enumerator.h"

using namespace std;

namespace nidevice_grpc {

SoftwareEnumerator::SoftwareEnumerator(SysCfgLibraryInterface* library)
    : library_(library), syscfg_session_(nullptr)
{
}

SoftwareEnumerator::~SoftwareEnumerator()
{
  // Caller is expected to close the syscfg session before calling destructor.
}

// Provides a list of installed software on a server under localhost. This internally uses the
// "NI System Configuration API". If it is not currently installed, it can be downloaded from this page:
// https://www.ni.com/en-in/support/downloads/drivers/download.system-configuration.html.
::grpc::Status SoftwareEnumerator::enumerate_software(google::protobuf::RepeatedPtrField<SoftwareProperties>* software)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgEnumSoftwareComponentHandle installedComps = NULL;
  unsigned int numInstalledComps = 0;
  char product_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char package_name[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  char version[NISYSCFG_SIMPLE_STRING_LENGTH] = "";
  NISysCfgBool is_ni_product = NISysCfgBoolFalse;

  try {
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = NISysCfgGetInstalledSoftwareComponents(session, NISysCfgIncludeItemsAllVisible, NISysCfgBoolTrue, &installedComps)))
      {
        NISysCfgResetEnumeratorGetCount(installedComps, &numInstalledComps);
        for (unsigned int index = 0; index < numInstalledComps; ++index)
          {
            NISysCfgNextComponentInfo(installedComps, product_name, version, package_name, NULL, NULL);
            SoftwareProperties* properties = software->Add();
            properties->set_product_name(product_name);
            properties->set_package_name(package_name);
            properties->set_version(version);
          }
        
          library_->CloseHandle(installedComps);
      }
    }
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }

  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kSoftwareEnumerationFailedMessage);
  }

  return ::grpc::Status::OK;
}

// Sets cached NISysCfgSession to passed session handle.
// Sets null to cached session after failed initialization.
// Returns status of getting valid cached_syscfg_session is successful.
NISysCfgStatus SoftwareEnumerator::open_or_get_localhost_syscfg_session(NISysCfgSessionHandle* session)
{
  std::unique_lock<std::shared_mutex> lock(session_mutex_);
  NISysCfgStatus status = NISysCfg_OK;
  if (!syscfg_session_) {
    if (NISysCfg_Failed(status = library_->InitializeSession(kSoftwareEnumerationLocalHostTargetName, NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, kSoftwareEnumerationConnectionTimeoutMilliSec, NULL, &syscfg_session_))) {
      return status;
    }
  }
  *session = syscfg_session_;
  return status;
}

// Calls Closehandle to clear sysconfig session and sets cached_syscfg_session to null.
void SoftwareEnumerator::clear_syscfg_session()
{
  std::unique_lock<std::shared_mutex> lock(session_mutex_);
  if (syscfg_session_) {
    library_->CloseHandle(syscfg_session_);
    syscfg_session_ = nullptr;
  }
}

// Returns status of cached session.
bool SoftwareEnumerator::is_session_open()
{
  return syscfg_session_ != nullptr;
}

}  // namespace nidevice_grpc
