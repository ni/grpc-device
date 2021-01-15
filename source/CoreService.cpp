#include <CoreService.h>

grpc::Status CoreService::IsServerRunning(::grpc::ServerContext* context, Core::IsServerRunningResponse* status)
{
   status->set_status(true);
   return grpc::Status::OK;
}
