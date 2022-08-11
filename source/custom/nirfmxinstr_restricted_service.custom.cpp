#include <nirfmxinstr_restricted/nirfmxinstr_restricted_service.h>

namespace nirfmxinstr_restricted_grpc {

::grpc::Status NiRFmxInstrRestrictedService::ConvertApiErrorStatusForNiRFmxInstrHandle(google::protobuf::int32 status, niRFmxInstrHandle instrumentHandle)
{
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    // TODO: How do we get access to a library that can return a useful string?
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nirfmxinstr_restricted_grpc
