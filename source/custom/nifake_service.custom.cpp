#include <nifake/nifake_service.h>

namespace nifake_grpc {

::grpc::Status NiFakeService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->error_message(vi, status, description.data());
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nifake_grpc
