#include <nifake/nifake_service.h>

namespace nifake_grpc {

::grpc::Status NiFakeService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession vi)
{
    std::string description = "In a real service, you'd look up the error message here.";
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nifake_grpc
