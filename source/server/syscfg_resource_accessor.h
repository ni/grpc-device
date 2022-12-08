#ifndef NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H
#define NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H

#include <shared_mutex>

#include "server_reset_observer_interface.h"
#include "shared_library.h"
#include "syscfg_library_interface.h"

namespace nidevice_grpc {

class SysCfgResourceAccessor : public SysCfgSessionHandler {
 public:
  SysCfgResourceAccessor(SysCfgLibraryInterface* library);
  virtual ~SysCfgSessionHandler();

 protected:
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

};      // namespace nidevice_grpc
#endif  // NIDEVICE_GRPC_SYSCFG_SESSION_HANDLER_H