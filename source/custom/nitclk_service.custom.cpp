#include <nitclk/nitclk_service.h>
#include <stdexcept>

namespace nitclk_grpc {
const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

::grpc::Status NiTClkService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession session_number)
{
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetExtendedErrorInfo(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nitclk_grpc
