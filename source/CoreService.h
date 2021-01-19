#include <core.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

namespace core
{
namespace Impl
{
   class CoreService final : public core::CoreService::Service
   {
   public:
      ::grpc::Status IsServerRunning(::grpc::ServerContext* context, const ::core::IsServerRunningRequest* request, ::core::IsServerRunningResult* response) override;
   };
}
}