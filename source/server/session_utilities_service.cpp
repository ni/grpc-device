#include "session_utilities_service.h"

#include <algorithm>

namespace nidevice_grpc {

SessionUtilitiesService::SessionUtilitiesService(SessionRepository* session_repository, DeviceEnumerator* device_enumerator, SoftwareEnumerator* software_enumerator)
    : session_repository_(session_repository), device_enumerator_(device_enumerator), software_enumerator_(software_enumerator)
{
}

::grpc::Status SessionUtilitiesService::EnumerateDevices(::grpc::ServerContext* context, const EnumerateDevicesRequest* request, EnumerateDevicesResponse* response)
{
  return device_enumerator_->enumerate_devices(response->mutable_devices());
}

::grpc::Status SessionUtilitiesService::EnumerateInstalledSoftware(::grpc::ServerContext* context, const EnumerateInstalledSoftwareRequest* request, EnumerateInstalledSoftwareResponse* response)
{
  return software_enumerator_->enumerate_installed_software(context, request->include_hidden_packages(), response->mutable_software());
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

  {
    std::unique_lock<std::shared_mutex> lock(observers_mutex_);
    for (auto observer : observers_)
    {
      observer->on_server_reset();
    }
  }

  return ::grpc::Status::OK;
}

void SessionUtilitiesService::register_observer(ServerResetObserverInterface* observer)
{
  std::unique_lock<std::shared_mutex> lock(observers_mutex_);
  if (std::find(observers_.begin(), observers_.end(), observer) == observers_.end())
  {
    observers_.push_back(observer);
  }
}

void SessionUtilitiesService::unregister_observer(ServerResetObserverInterface* observer)
{
  std::unique_lock<std::shared_mutex> lock(observers_mutex_);
  auto i = std::find(observers_.begin(), observers_.end(), observer);
  if (i != observers_.end())
  {
    observers_.erase(i);
  }
}

}  // namespace nidevice_grpc
