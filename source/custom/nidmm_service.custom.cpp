#include <nidmm/nidmm_service.h>

namespace nidmm_grpc {

::grpc::Status NiDmmService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession vi)
{
    const ViInt32 buffer_size = 4096;
    ViStatus error_code {};
    std::string description(buffer_size, '\0');
    // Try first to get the most recent error with a dynamic message.
    library_->GetError(vi, &error_code, buffer_size, description.data());
    if (error_code != status) {
        // Since another thread has changed the status, fall back to the static message lookup.
        library_->GetErrorMessage(vi, status, buffer_size, description.data());
    }
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nidmm_grpc
