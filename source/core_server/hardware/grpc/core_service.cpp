#include "hardware/grpc/core_service.h"

namespace ni
{
namespace hardware
{
namespace grpc
{

::grpc::Status CoreService::IsServerRunning(::grpc::ServerContext* context, const IsServerRunningRequest* request, IsServerRunningResult* response)
{
   response->set_status(true);
   return ::grpc::Status::OK;
}

} // namespace grpc
} // namespace hardware
} // namespace ni