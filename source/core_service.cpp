#include "core_service.h"

::grpc::Status ni::hardware::grpc::Impl::CoreService::IsServerRunning(::grpc::ServerContext* context, const ::ni::hardware::grpc::IsServerRunningRequest* request, ::ni::hardware::grpc::IsServerRunningResult* response)
{
   response->set_status(true);
   return ::grpc::Status::OK;
}
