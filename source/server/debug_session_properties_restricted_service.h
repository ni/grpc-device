#ifndef NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE
#define NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <debugsessionproperties_restricted.grpc.pb.h>

#include "feature_toggles.h"
#include "shared_library.h"
#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_restricted_grpc {

struct DebugSessionPropertiesRestrictedFeatureToggles
{
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  DebugSessionPropertiesRestrictedFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});

  bool is_enabled;
};

class DebugSessionPropertiesRestrictedService final :
  public DebugSessionPropertiesRestricted::Service,
  public ::nidevice_grpc::SysCfgSessionHandler {
 public:
  DebugSessionPropertiesRestrictedService(::nidevice_grpc::SysCfgLibraryInterface* library);

  ::grpc::Status IsDebugSessionSupported(
    ::grpc::ServerContext* context,
    const IsDebugSessionSupportedRequest* request,
    IsDebugSessionSupportedResponse* response) override;
  ::grpc::Status IsDebugSessionEnabled(
    ::grpc::ServerContext* context,
    const IsDebugSessionEnabledRequest* request,
    IsDebugSessionEnabledResponse* response) override;
  ::grpc::Status IsDebugSessionServerOutOfProcess(
    ::grpc::ServerContext* context,
    const IsDebugSessionServerOutOfProcessRequest* request,
    IsDebugSessionServerOutOfProcessResponse* response) override;
  ::grpc::Status SetDebugSessionEnabled(
    ::grpc::ServerContext* context,
    const SetDebugSessionEnabledRequest* request,
    SetDebugSessionEnabledResponse* response) override;
  ::grpc::Status SetDebugSessionServerOutOfProcess(
    ::grpc::ServerContext* context,
    const SetDebugSessionServerOutOfProcessRequest* request,
    SetDebugSessionServerOutOfProcessResponse* response) override;

 private:
  ::grpc::Status access_syscfg_resource_by_device_id_filter(
    ::grpc::ServerContext* context,
    const nidevice_restricted_grpc::DeviceId& device_id,
    std::function<NISysCfgStatus(nidevice_grpc::SysCfgLibraryInterface*, NISysCfgResourceHandle, bool*)> syscfg_resource_action_func);
  ::grpc::Status get_bool_property(
    ::grpc::ServerContext* context,
    NISysCfgResourceProperty property_id,
    const nidevice_restricted_grpc::DeviceId& device_id,
    bool* value);
  ::grpc::Status get_uint_property(
    ::grpc::ServerContext* context,
    NISysCfgResourceProperty property_id,
    const nidevice_restricted_grpc::DeviceId& device_id,
    uint32_t* value);
  ::grpc::Status set_bool_property(
    ::grpc::ServerContext* context,
    NISysCfgResourceProperty property_id,
    const nidevice_restricted_grpc::DeviceId& device_id,
    bool value);
  ::grpc::Status set_uint_property(
    ::grpc::ServerContext* context,
    NISysCfgResourceProperty property_id,
    const nidevice_restricted_grpc::DeviceId& device_id,
    uint32_t value);
};

}  // namespace nidevice_restricted_grpc

#endif  // NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE
