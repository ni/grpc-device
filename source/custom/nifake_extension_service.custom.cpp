#include <nifake_extension/nifake_extension_service.h>

namespace nifake_extension_grpc {

::grpc::Status NiFakeExtensionService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession vi)
{
    std::string description = "In a real service, you'd look up the error message here.";
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nifake_extension_grpc
