#include "core_service.h"

namespace ni {
namespace hardware {
namespace grpc {

#if defined(_MSC_VER)
static const char* syscfg_api_library_name = "nisyscfg.dll";
#else
static const char* syscfg_api_library_name = "libnisyscfg.so";
#endif

CoreService::CoreService(internal::SessionRepository* session_repository, internal::DeviceManagement* device_management, internal::SharedLibrary* shared_library)
    : session_repository_(session_repository), device_management_(device_management), shared_library_(shared_library)
{
  shared_library->set_library_name(syscfg_api_library_name);
}

::grpc::Status CoreService::EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response)
{
  shared_library_->load();
  if (!shared_library_->is_loaded()) {
    std::string message("The library could not be loaded: ");
    message += syscfg_api_library_name;
    return ::grpc::Status(::grpc::StatusCode::NOT_FOUND, message.c_str());
  }
  NISysCfgStatus status = device_management_->enumerate_devices(shared_library_, response->mutable_devices());
  if (NISysCfg_Failed(status)) {
    return ::grpc::Status(::grpc::StatusCode::INTERNAL, "Failed to enumerate devices because of internal syscfg error.");
  }
  return ::grpc::Status::OK;
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
