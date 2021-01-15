#include <core.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

class CoreService final : public Core::CoreService::Service
{
public:
   grpc::Status IsServerRunning(::grpc::ServerContext* context, ::Core::IsServerRunningResponse* status);
};
