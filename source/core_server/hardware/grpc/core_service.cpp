#include "core_service.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
   CoreService::CoreService(internal::SessionRepository* session_repository, internal::DeviceManagement* device_management)
      : session_repository_(session_repository), device_management_(device_management)
   {
   }

   ::grpc::Status CoreService::EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response)
   {
       device_management_->enumerate_devices(context, request, response);
       return ::grpc::Status::OK;
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
