#include "session_utilities_service.h"

namespace nidevice_grpc {

SessionUtilitiesService::SessionUtilitiesService(SessionRepository* session_repository, DeviceEnumerator* device_enumerator)
    : session_repository_(session_repository), device_enumerator_(device_enumerator)
{
}

::grpc::Status SessionUtilitiesService::EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response)
{
  return device_enumerator_->enumerate_devices(response->mutable_devices());
}

::grpc::Status SessionUtilitiesService::Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ::grpc::Status status;
  bool reserved = session_repository_->reserve(context, request->reservation_id(), request->client_id(), status);
  response->set_is_reserved(reserved);
  return status;
}

::grpc::Status SessionUtilitiesService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_reserved = session_repository_->is_reserved_by_client(request->reservation_id(), request->client_id());
  response->set_is_reserved(is_reserved);
  return ::grpc::Status::OK;
}

::grpc::Status SessionUtilitiesService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_unreserved = session_repository_->unreserve(request->reservation_id(), request->client_id());
  response->set_is_unreserved(is_unreserved);
  return ::grpc::Status::OK;
}

::grpc::Status SessionUtilitiesService::ResetServer(::grpc::ServerContext* context, const ResetServerRequest* request, ResetServerResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  bool is_server_reset = session_repository_->reset_server();
  response->set_is_server_reset(is_server_reset);
  device_enumerator_->clear_syscfg_session();
  return ::grpc::Status::OK;
}

}  // namespace nidevice_grpc
