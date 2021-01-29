#include "core_service.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
   CoreService::CoreService(internal::SessionRepository* session_repository)
      : session_repository_(session_repository)
   {
   }

   ::grpc::Status CoreService::Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
   {
      session_repository_->reserve(context, request, response);
      return ::grpc::Status::OK;
   }

   ::grpc::Status CoreService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
   {
      session_repository_->is_reserved_by_client(context, request, response);
      return ::grpc::Status::OK;
   }

   ::grpc::Status CoreService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
   {
      session_repository_->unreserve(context, request, response);
      return ::grpc::Status::OK;
   }
} // namespace grpc
} // namespace hardware
} // namespace ni
