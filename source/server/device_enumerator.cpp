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
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  
  try {
    syscfg_status = library_->InitializeSession("localhost", NULL, NULL, NISysCfgLocaleDefault, NISysCfgBoolTrue, 10000, NULL, &session);
    if (NISysCfg_Succeeded(syscfg_status)) {
      syscfg_status = library_->CreateFilter(session, &filter);
      library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
      library_->SetFilterProperty(filter, NISysCfgFilterPropertyIsChassis, NISysCfgBoolTrue);
    }

    library_->CloseHandle(filter);
    library_->CloseHandle(session);
  }
  catch (LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
  
  if (NISysCfg_Failed(syscfg_status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kSysCfgApiFailedMessage);
  }

  return ::grpc::Status::OK;
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
