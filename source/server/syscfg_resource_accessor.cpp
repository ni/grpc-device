#include "syscfg_resource_accessor.h"

#include "converters.h"

namespace nidevice_restricted_grpc {

SysCfgResourceAccessor::SysCfgResourceAccessor(nidevice_grpc::SysCfgLibraryInterface* library)
    : SysCfgSessionHandler(library) {}

SysCfgResourceAccessor::~SysCfgResourceAccessor()
{
}

::grpc::Status SysCfgResourceAccessor::access_syscfg_resource_by_device_id_filter(
    ::grpc::ServerContext* context,
    const DeviceId& device_id,
    const char* access_failed_message,
    std::function<NISysCfgStatus(nidevice_grpc::SysCfgLibraryInterface*, NISysCfgResourceHandle, bool*)> syscfg_resource_action_func)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  bool no_hardware_found = false;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyUserAlias, device_id.name().c_str());
        library->SetFilterProperty(filter, NISysCfgFilterPropertySerialNumber, device_id.serial_number().c_str());
        library->SetFilterProperty(filter, NISysCfgFilterPropertyProductId, device_id.product_id());
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAll, filter, NULL, &resources_handle))) {
          if ((status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            bool save_changes = false;
            if (NISysCfg_Succeeded(status = syscfg_resource_action_func(library, resource, &save_changes))) {
              if (save_changes) {
                NISysCfgBool changes_require_restart = NISysCfgBoolFalse;
                char* detailed_changes = nullptr;
                status = library->SaveResourceChanges(resource, &changes_require_restart, &detailed_changes);
                library->FreeDetailedString(detailed_changes);
              }
            }
            library->CloseHandle(resource);
          }
          else {
            no_hardware_found = true;
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
    std::string description(access_failed_message);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  }

  if (no_hardware_found) {
    return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, access_failed_message);
  }

  return ::grpc::Status::OK;
}
}  // namespace nidevice_restricted_grpc
