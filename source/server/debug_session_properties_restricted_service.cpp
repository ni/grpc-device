#include "debug_session_properties_restricted_service.h"

namespace nidevice_restricted_grpc {

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
  auto status = get_bool_property((NISysCfgResourceProperty)0x10001000, request->product_id(), request->serial_number().c_str(), &supported);
  response->set_supported(supported);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::IsDebugSessionEnabled(
  ::grpc::ServerContext* context,
  const IsDebugSessionEnabledRequest* request,
  IsDebugSessionEnabledResponse* response)
{
  uint32_t enabled = false;
  auto status = get_uint_property((NISysCfgResourceProperty)0x10002000, request->product_id(), request->serial_number().c_str(), &enabled);
  response->set_enabled(enabled != 0);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::IsDebugSessionServerOutOfProcess(
  ::grpc::ServerContext* context,
  const IsDebugSessionServerOutOfProcessRequest* request,
  IsDebugSessionServerOutOfProcessResponse* response)
{
  bool out_of_process = false;
  auto status = get_bool_property((NISysCfgResourceProperty)0x10003000, request->product_id(), request->serial_number().c_str(), &out_of_process);
  response->set_out_of_process(out_of_process);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::SetDebugSessionEnabled(
  ::grpc::ServerContext* context,
  const SetDebugSessionEnabledRequest* request,
  SetDebugSessionEnabledResponse* response)
{
  uint32_t enabled = request->enabled() ? 1 : 0;
  auto status = set_uint_property((NISysCfgResourceProperty)0x10002000, request->product_id(), request->serial_number().c_str(), enabled);
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::SetDebugSessionServerOutOfProcess(
  ::grpc::ServerContext* context,
  const SetDebugSessionServerOutOfProcessRequest* request,
  SetDebugSessionServerOutOfProcessResponse* response)
{
  auto status = set_bool_property((NISysCfgResourceProperty)0x10003000, request->product_id(), request->serial_number().c_str(), request->out_of_process());
  return status;
}

::grpc::Status DebugSessionPropertiesRestrictedService::get_bool_property(
  NISysCfgResourceProperty property_id,
  uint32_t product_id,
  const char* serial_number,
  bool* value)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  NISysCfgBool syscfg_value = NISysCfgBoolFalse;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyProductId, product_id);
        library->SetFilterProperty(filter, NISysCfgFilterPropertySerialNumber, serial_number);
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAll, filter, NULL, &resources_handle))) {
          if (NISysCfg_Succeeded(status) && (status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library->GetResourceProperty(resource, property_id, &syscfg_value);
            *value = syscfg_value != NISysCfgBoolFalse;
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
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDebugSessionPropertyAccessFailedMessage);
  }

  return ::grpc::Status::OK;
}

::grpc::Status DebugSessionPropertiesRestrictedService::get_uint_property(
  NISysCfgResourceProperty property_id,
  uint32_t product_id,
  const char* serial_number,
  uint32_t* value)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyProductId, product_id);
        library->SetFilterProperty(filter, NISysCfgFilterPropertySerialNumber, serial_number);
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAll, filter, NULL, &resources_handle))) {
          if (NISysCfg_Succeeded(status) && (status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library->GetResourceProperty(resource, property_id, value);
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
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDebugSessionPropertyAccessFailedMessage);
  }

  return ::grpc::Status::OK;
}

::grpc::Status DebugSessionPropertiesRestrictedService::set_bool_property(
  NISysCfgResourceProperty property_id,
  uint32_t product_id,
  const char* serial_number,
  bool value)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;
  NISysCfgBool syscfg_value = value ? NISysCfgBoolTrue : NISysCfgBoolFalse;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyProductId, product_id);
        library->SetFilterProperty(filter, NISysCfgFilterPropertySerialNumber, serial_number);
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAll, filter, NULL, &resources_handle))) {
          if (NISysCfg_Succeeded(status) && (status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library->SetResourceProperty(resource, property_id, syscfg_value);
            NISysCfgBool changes_require_restart = NISysCfgBoolFalse;
            char* detailed_changes = nullptr;
            library->SaveResourceChanges(resource, &changes_require_restart, &detailed_changes);
            library->FreeDetailedString(detailed_changes);
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
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDebugSessionPropertyAccessFailedMessage);
  }

  return ::grpc::Status::OK;
}

::grpc::Status DebugSessionPropertiesRestrictedService::set_uint_property(
  NISysCfgResourceProperty property_id,
  uint32_t product_id,
  const char* serial_number,
  uint32_t value)
{
  NISysCfgStatus status = NISysCfg_OK;
  NISysCfgSessionHandle session = NULL;
  NISysCfgFilterHandle filter = NULL;
  NISysCfgEnumResourceHandle resources_handle = NULL;
  NISysCfgResourceHandle resource = NULL;

  try {
    auto library = get_syscfg_library_interface();
    if (NISysCfg_Succeeded(status = open_or_get_localhost_syscfg_session(&session))) {
      if (NISysCfg_Succeeded(status = library->CreateFilter(session, &filter))) {
        library->SetFilterProperty(filter, NISysCfgFilterPropertyIsDevice, NISysCfgBoolTrue);
        library->SetFilterProperty(filter, NISysCfgFilterPropertyProductId, product_id);
        library->SetFilterProperty(filter, NISysCfgFilterPropertySerialNumber, serial_number);
        if (NISysCfg_Succeeded(status = library->FindHardware(session, NISysCfgFilterModeMatchValuesAll, filter, NULL, &resources_handle))) {
          if (NISysCfg_Succeeded(status) && (status = library->NextResource(session, resources_handle, &resource)) == NISysCfg_OK) {
            library->SetResourceProperty(resource, property_id, value);
            NISysCfgBool changes_require_restart = NISysCfgBoolFalse;
            char* detailed_changes = nullptr;
            library->SaveResourceChanges(resource, &changes_require_restart, &detailed_changes);
            library->FreeDetailedString(detailed_changes);
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
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, kDebugSessionPropertyAccessFailedMessage);
  }

  return ::grpc::Status::OK;
}

DebugSessionPropertiesRestrictedFeatureToggles::DebugSessionPropertiesRestrictedFeatureToggles(
  const nidevice_grpc::FeatureToggles& feature_toggles)
  : is_enabled(
      feature_toggles.is_feature_enabled("debugsessionproperties_restricted", CodeReadiness::kRestrictedNextRelease))
{
}

}  // namespace nidevice_restricted_grpc
