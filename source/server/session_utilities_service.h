#ifndef NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE
#define NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <list>
#include <session.grpc.pb.h>
#include <shared_mutex>

#include "device_enumerator.h"
#include "server_reset_observer_interface.h"
#include "server_reset_observer_registrar_interface.h"
#include "session_repository.h"
#include "software_enumerator.h"

namespace nidevice_grpc {

class SessionUtilitiesService final : public SessionUtilities::Service, public ServerResetObserverRegistrarInterface {
 public:
  SessionUtilitiesService(SessionRepository* session_repository, DeviceEnumerator* device_enumerator, SoftwareEnumerator* software_enumerator);

  ::grpc::Status EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response) override;
  ::grpc::Status EnumerateInstalledSoftware(::grpc::ServerContext* context, const EnumerateInstalledSoftwareRequest* request, EnumerateInstalledSoftwareResponse* response) override;
  ::grpc::Status Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response) override;
  ::grpc::Status IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response) override;
  ::grpc::Status Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response) override;
  ::grpc::Status ResetServer(::grpc::ServerContext* context, const ResetServerRequest* request, ResetServerResponse* response) override;

  void register_observer(ServerResetObserverInterface* observer) override;
  void unregister_observer(ServerResetObserverInterface* observer) override;

 private:
  SessionRepository* session_repository_;
  DeviceEnumerator* device_enumerator_;
  SoftwareEnumerator* software_enumerator_;
  std::list<ServerResetObserverInterface*> observers_;
  std::shared_mutex observers_mutex_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE
