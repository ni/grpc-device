#include <nixnetsocket/nixnetsocket_service.h>

namespace nixnetsocket_grpc {

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxSOCKET(google::protobuf::int32 status, nxSOCKET socket)
{
    // This implementation assumes this method is always called on the same thread where the error occurred.
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    // XNET sockets have special behavior that returns both the API error code and the sockets error number.
    int errorNumber = library_->GetLastErrorNum();
    nlohmann::json jsonError{{"errorNumber", errorNumber}};
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description, jsonError);
}

::grpc::Status NiXnetSocketService::ConvertApiErrorStatusForNxIpStackRef_t(google::protobuf::int32 status, nxIpStackRef_t socket)
{
    // This implementation assumes this method is always called on the same thread where the error occurred.
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetLastErrorStr(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    // XNET sockets have special behavior that returns both the API error code and the sockets error number.
    int errorNumber = library_->GetLastErrorNum();
    nlohmann::json jsonError{{"errorNumber", errorNumber}};
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description, jsonError);
}

}  // namespace nixnetsocket_grpc
