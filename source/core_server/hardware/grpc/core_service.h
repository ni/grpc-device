#include <server_utilities.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

namespace ni
{
namespace hardware
{
namespace grpc
{

   class CoreService final : public ServerUtilities::Service
   {
   public:
      ::grpc::Status IsServerRunning(::grpc::ServerContext* context, const IsServerRunningRequest* request, IsServerRunningResult* response) override;
   };

} // namespace grpc
} // namespace hardware
} // namespace ni
