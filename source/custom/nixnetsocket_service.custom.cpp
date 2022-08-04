#include <nixnetsocket/nixnetsocket_service.h>

namespace nixnetsocket_grpc {

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusFornxSOCKET(google::protobuf::int32 status, nxSOCKET socket)
{
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(description.data(), nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusFornxIpStackRef_t(google::protobuf::int32 status, nxIpStackRef_t socket)
{
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(description.data(), nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nixnetsocket_grpc
