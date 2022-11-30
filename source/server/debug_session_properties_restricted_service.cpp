#include "debug_session_properties_restricted_service.h"

#include "converters.h"

namespace nidevice_restricted_grpc {

DebugSessionPropertiesRestrictedFeatureToggles::DebugSessionPropertiesRestrictedFeatureToggles(
  const nidevice_grpc::FeatureToggles& feature_toggles)
  : is_enabled(
      feature_toggles.is_feature_enabled("debugsessionproperties_restricted", CodeReadiness::kRestrictedRelease))
{
}

DebugSessionPropertiesRestrictedService::DebugSessionPropertiesRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library)
    : SysCfgSessionHandler(library)
{
}

::grpc::Status DebugSessionPropertiesRestrictedService::IsDebugSessionSupported(
  ::grpc::ServerContext* context,
  const IsDebugSessionSupportedRequest* request,
  IsDebugSessionSupportedResponse* response)
{
  bool supported = false;
  auto status = get_bool_property(context, kDebugSessionSupportedPropertyId, request->device_id(), &supported);
  response->set_supported(supported);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::IsDebugSessionEnabled(
  ::grpc::ServerContext* context,
  const IsDebugSessionEnabledRequest* request,
  IsDebugSessionEnabledResponse* response)
{
  uint32_t enabled = false;
  auto status = get_uint_property(context, kDebugSessionEnabledPropertyId, request->device_id(), &enabled);
  response->set_enabled(enabled != 0);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::IsDebugSessionServerOutOfProcess(
  ::grpc::ServerContext* context,
  const IsDebugSessionServerOutOfProcessRequest* request,
  IsDebugSessionServerOutOfProcessResponse* response)
{
  bool out_of_process = false;
  auto status = get_bool_property(context, kDebugSessionServerOutOfProcessPropertyId, request->device_id(), &out_of_process);
  response->set_out_of_process(out_of_process);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::SetDebugSessionEnabled(
  ::grpc::ServerContext* context,
  const SetDebugSessionEnabledRequest* request,
  SetDebugSessionEnabledResponse* response)
{
  uint32_t enabled = request->enabled() ? 1 : 0;
  return set_uint_property(context, kDebugSessionEnabledPropertyId, request->device_id(), enabled);
}

::grpc::Status DebugSessionPropertiesRestrictedService::SetDebugSessionServerOutOfProcess(
  ::grpc::ServerContext* context,
  const SetDebugSessionServerOutOfProcessRequest* request,
  SetDebugSessionServerOutOfProcessResponse* response)
{
  return set_bool_property(context, kDebugSessionServerOutOfProcessPropertyId, request->device_id(), request->out_of_process());
}

::grpc::Status DebugSessionPropertiesRestrictedService::access_syscfg_resource_by_device_id_filter(
  ::grpc::ServerContext* context,
  const nidevice_restricted_grpc::DeviceId& device_id,
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
          else{
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
    std::string description(kDebugSessionPropertyAccessFailedMessage);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
  }

  if (no_hardware_found) {
    return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, kDebugSessionPropertyAccessFailedMessage);
  }

  return ::grpc::Status::OK;
}

::grpc::Status DebugSessionPropertiesRestrictedService::get_bool_property(
  ::grpc::ServerContext* context,
  NISysCfgResourceProperty property_id,
  const nidevice_restricted_grpc::DeviceId& device_id,
  bool* value)
{
  auto get_bool_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    NISysCfgBool syscfg_value = NISysCfgBoolFalse;
    auto status = library->GetResourceProperty(resource, property_id, &syscfg_value);
    *value = syscfg_value != NISysCfgBoolFalse;
    return status;
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, get_bool_lambda);
}

::grpc::Status DebugSessionPropertiesRestrictedService::get_uint_property(
  ::grpc::ServerContext* context,
  NISysCfgResourceProperty property_id,
  const nidevice_restricted_grpc::DeviceId& device_id,
  uint32_t* value)
{
  auto get_uint_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
      return library->GetResourceProperty(resource, property_id, value);
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, get_uint_lambda);
}

::grpc::Status DebugSessionPropertiesRestrictedService::set_bool_property(
  ::grpc::ServerContext* context,
  NISysCfgResourceProperty property_id,
  const nidevice_restricted_grpc::DeviceId& device_id,
  bool value)
{
  NISysCfgBool syscfg_value = value ? NISysCfgBoolTrue : NISysCfgBoolFalse;
  auto set_bool_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    *save_changes = true;
    return library->SetResourceProperty(resource, property_id, syscfg_value);
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, set_bool_lambda);
}

::grpc::Status DebugSessionPropertiesRestrictedService::set_uint_property(
  ::grpc::ServerContext* context,
  NISysCfgResourceProperty property_id,
  const nidevice_restricted_grpc::DeviceId& device_id,
  uint32_t value)
{
  auto set_uint_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
    *save_changes = true;
    return library->SetResourceProperty(resource, property_id, value);
  };
  return access_syscfg_resource_by_device_id_filter(context, device_id, set_uint_lambda);
}

}  // namespace nidevice_restricted_grpc
