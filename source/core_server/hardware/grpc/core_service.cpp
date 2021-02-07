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
  bool reserved = session_repository_->reserve(request->reservation_id(), request->client_id());
  response->set_is_reserved(reserved);
  if (!reserved) {
    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "You must specify a non-empty reservation_id and client_id.");
  }
  return ::grpc::Status::OK;
}

::grpc::Status CoreService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
{
  bool is_reserved = session_repository_->is_reserved_by_client(request->reservation_id(), request->client_id());
  response->set_is_reserved(is_reserved);
  return ::grpc::Status::OK;
}

::grpc::Status CoreService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
{
  bool is_unreserved = session_repository_->unreserve(request->reservation_id(), request->client_id());
  response->set_is_unreserved(is_unreserved);
  return ::grpc::Status::OK;
}

}  // namespace grpc
}  // namespace hardware
}  // namespace ni
