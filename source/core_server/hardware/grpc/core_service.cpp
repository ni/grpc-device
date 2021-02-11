#include "core_service.h"

namespace ni {
namespace hardware {
namespace grpc {

CoreService::CoreService(internal::SessionRepository* session_repository)
    : session_repository_(session_repository)
{
}

::grpc::Status CoreService::Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ::grpc::Status status;
  bool reserved = session_repository_->reserve(context, request->reservation_id(), request->client_id(), status);
  response->set_is_reserved(reserved);
  return status;
}

::grpc::Status CoreService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_reserved = session_repository_->is_reserved_by_client(request->reservation_id(), request->client_id());
  response->set_is_reserved(is_reserved);
  return ::grpc::Status::OK;
}

::grpc::Status CoreService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_unreserved = session_repository_->unreserve(request->reservation_id(), request->client_id());
  response->set_is_unreserved(is_unreserved);
  return ::grpc::Status::OK;
}

::grpc::Status CoreService::ResetServer(::grpc::ServerContext* context, const ResetServerRequest* request, ResetServerResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_server_reset = session_repository_->reset_server();
  response->set_is_server_reset(is_server_reset);
  return ::grpc::Status::OK;
}

}  // namespace grpc
}  // namespace hardware
}  // namespace ni
