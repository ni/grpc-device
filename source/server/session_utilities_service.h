#ifndef NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE
#define NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <session.grpc.pb.h>

#include "device_enumerator.h"
#include "session_repository.h"

namespace nidevice_grpc {

class SessionUtilitiesService final : public SessionUtilities::Service {
 public:
  SessionUtilitiesService(SessionRepository* session_repository, DeviceEnumerator* device_enumerator);

  ::grpc::Status EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response) override;
  ::grpc::Status Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response) override;
  ::grpc::Status IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response) override;
  ::grpc::Status Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response) override;
  ::grpc::Status ResetServer(::grpc::ServerContext* context, const ResetServerRequest* request, ResetServerResponse* response) override;

 private:
  SessionRepository* session_repository_;
  DeviceEnumerator* device_enumerator_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SESSION_UTILITIES_SERVICE
