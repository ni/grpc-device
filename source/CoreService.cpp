#include <CoreService.h>

grpc::Status CoreService::IsServerRunning(::grpc::ServerContext* context, Core::IsServerRunningResult* status)
{
   status->set_status(true);
   return grpc::Status::OK;
}
