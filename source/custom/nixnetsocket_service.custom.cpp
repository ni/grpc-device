#include <nixnetsocket/nixnetsocket_service.h>

namespace nixnetsocket_grpc {

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxSOCKET(google::protobuf::int32 status, nxSOCKET socket)
{
    // This implementation assumes this method is always called on the same thread where the error occurred.
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(description.data(), nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxIpStackRef_t(google::protobuf::int32 status, nxIpStackRef_t socket)
{
    // This implementation assumes this method is always called on the same thread where the error occurred.
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(description.data(), nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nixnetsocket_grpc
