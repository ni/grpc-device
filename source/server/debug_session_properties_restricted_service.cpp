#include "debug_session_properties_restricted_service.h"

#include "converters.h"

namespace nidevice_restricted_grpc {

DebugSessionPropertiesRestrictedFeatureToggles::DebugSessionPropertiesRestrictedFeatureToggles(
  const nidevice_grpc::FeatureToggles& feature_toggles)
  : is_enabled(
      feature_toggles.is_feature_enabled("debugsessionproperties_restricted", CodeReadiness::kRelease))
{
}

DebugSessionPropertiesRestrictedService::DebugSessionPropertiesRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library)
    : SysCfgResourceAccessor(library)
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
  return access_syscfg_resource_by_device_id_filter(context, device_id, kDebugSessionPropertyAccessFailedMessage, get_bool_lambda);
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
  return access_syscfg_resource_by_device_id_filter(context, device_id, kDebugSessionPropertyAccessFailedMessage, get_uint_lambda);
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
  return access_syscfg_resource_by_device_id_filter(context, device_id, kDebugSessionPropertyAccessFailedMessage, set_bool_lambda);
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
  return access_syscfg_resource_by_device_id_filter(context, device_id, kDebugSessionPropertyAccessFailedMessage, set_uint_lambda);
}

}  // namespace nidevice_restricted_grpc
