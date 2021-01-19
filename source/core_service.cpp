#include "core_service.h"

::grpc::Status core::Impl::CoreService::IsServerRunning(::grpc::ServerContext* context, const ::core::IsServerRunningRequest* request, ::core::IsServerRunningResult* response)
{
   response->set_status(true);
   return grpc::Status::OK;
}
