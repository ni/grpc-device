#include <nirfmxlte/nirfmxlte_service.h>

namespace nirfmxlte_grpc {

::grpc::Status NiRFmxLTEService::ConvertApiErrorStatusForniRFmxInstrHandle(google::protobuf::int32 status, niRFmxInstrHandle instrumentHandle)
{
    const ViInt32 buffer_size = 4096;
    ViStatus error_code {};
    std::string description(buffer_size, '\0');
    // Try first to get the most recent error with a dynamic message.
    library_->GetError(instrumentHandle, &error_code, buffer_size, description.data());
    if (error_code != status) {
        // Since another thread has changed the status, fall back to the static message lookup.
        library_->GetErrorString(instrumentHandle, status, buffer_size, description.data());
    }
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nirfmxlte_grpc
