#include <core.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace Impl
{
   class CoreService final : public ni::hardware::grpc::CoreService::Service
   {
   public:
      ::grpc::Status IsServerRunning(::grpc::ServerContext* context, const ::ni::hardware::grpc::IsServerRunningRequest* request, ::ni::hardware::grpc::IsServerRunningResult* response) override;
   };
}
}
}
}