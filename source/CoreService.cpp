#include "CoreService.h"

::grpc::Status CoreService::IsServerRunning(::grpc::ServerContext* context, const ::Core::IsServerRunningRequest* request, ::Core::IsServerRunningResult* response)
{
   response->set_status(true);
   return grpc::Status::OK;
}
