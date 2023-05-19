#include <nixnetsocket/nixnetsocket_service.h>

namespace nixnetsocket_grpc {

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxSOCKET(::grpc::ServerContextBase* context, int32_t status, nxSOCKET socket)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetLastErrorStr(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  // XNET sockets have special behavior that returns both the API error code and the sockets error number.
  int errorNumber = library_->GetLastErrorNum();
  context->AddTrailingMetadata("ni-socket-error", std::to_string(errorNumber));
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxIpStackRef_t(::grpc::ServerContextBase* context, int32_t status, nxIpStackRef_t socket)
{
  // This implementation assumes this method is always called on the same thread where the error occurred.
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetLastErrorStr(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  // XNET sockets have special behavior that returns both the API error code and the sockets error number.
  int errorNumber = library_->GetLastErrorNum();
  context->AddTrailingMetadata("ni-socket-error", std::to_string(errorNumber));
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nixnetsocket_grpc
