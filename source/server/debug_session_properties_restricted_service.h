#ifndef NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE
#define NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <debugsessionproperties_restricted.grpc.pb.h>

#include "shared_library.h"
#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_restricted_grpc {

static const char* kDebugSessionPropertyAccessFailedMessage = "The NI System Configuration API was unable to access the debug session property.";

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
  ::grpc::Status get_bool_property(NISysCfgResourceProperty property_id, uint32_t product_id, const char* serial_number, bool* value);
  ::grpc::Status get_uint_property(NISysCfgResourceProperty property_id, uint32_t product_id, const char* serial_number, uint32_t* value);
  ::grpc::Status set_bool_property(NISysCfgResourceProperty property_id, uint32_t product_id, const char* serial_number, bool value);
  ::grpc::Status set_uint_property(NISysCfgResourceProperty property_id, uint32_t product_id, const char* serial_number, uint32_t value);
};

}  // namespace nidevice_restricted_grpc

#endif  // NIDEVICE_RESTRICTED_GRPC_DEBUG_SESSION_PROPERTIES_RESTRICTED_SERVICE
