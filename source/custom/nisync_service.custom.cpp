#include <nisync/nisync_service.h>

namespace nisync_grpc {

::grpc::Status NiSyncService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession vi)
{
  static_assert(nidevice_grpc::kMaxGrpcErrorDescriptionSize >= 256, "ErrorMessage expects a minimum buffer size.");
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->ErrorMessage(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nisync_grpc
