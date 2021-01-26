#include "core_service.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
    ::grpc::Status CoreService::Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
    {
        internal::SessionRepository* session_repository = session_repository->instance();
        session_repository->reserve(context, request, response);
        return ::grpc::Status::OK;
    }

    ::grpc::Status CoreService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
    {
        internal::SessionRepository* session_repository = session_repository->instance();
        session_repository->is_reserved_by_client(context, request, response);
        return ::grpc::Status::OK;
    }

    ::grpc::Status CoreService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
    {
        internal::SessionRepository* session_repository = session_repository->instance();
        session_repository->unreserve(context, request, response);
        return ::grpc::Status::OK;
    }
    
    ::grpc::Status CoreService::ForceCloseAllSessions(::grpc::ServerContext* context, const ForceCloseAllSessionsRequest* request, ForceCloseAllSessionResponse* response)
   {
        internal::SessionRepository* session_repository = session_repository->instance();
        session_repository->force_close_all_sessions(context, request, response);
        return ::grpc::Status::OK;
   }
} // namespace grpc
} // namespace hardware
} // namespace ni
