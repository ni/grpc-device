#ifndef NIDEVICE_GRPC_SYSCFG_RESOURCE_ACCESSOR_H
#define NIDEVICE_GRPC_SYSCFG_RESOURCE_ACCESSOR_H

#include <shared_mutex>

#include "deviceid_restricted.grpc.pb.h"
#include "server_reset_observer_interface.h"
#include "shared_library.h"
#include "syscfg_library_interface.h"
#include "syscfg_session_handler.h"

namespace nidevice_restricted_grpc {

class SysCfgResourceAccessor : public nidevice_grpc::SysCfgSessionHandler {
 public:
  SysCfgResourceAccessor(nidevice_grpc::SysCfgLibraryInterface* library);
  virtual ~SysCfgResourceAccessor();

 protected:
  ::grpc::Status access_syscfg_resource_by_device_id_filter(
      ::grpc::ServerContext* context,
      const DeviceId& device_id,
      const char* access_failed_message,
      std::function<NISysCfgStatus(nidevice_grpc::SysCfgLibraryInterface*, NISysCfgResourceHandle, bool*)> syscfg_resource_action_func);
};

};      // namespace nidevice_restricted_grpc
#endif  // NIDEVICE_GRPC_SYSCFG_RESOURCE_ACCESSOR_H
