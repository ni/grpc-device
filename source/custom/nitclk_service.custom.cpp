#include <nitclk/nitclk_service.h>
#include <stdexcept>

namespace nitclk_grpc {
const auto kErrorReadBufferTooSmall = -200229;
const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiTClkService::GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      ViSession session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      ViConstString channel_name = request->channel_name().c_str();
      ViAttr attribute_id = request->attribute_id();

      while (true) {
        auto status = library_->GetAttributeViString(session, channel_name, attribute_id, 0, nullptr);
        if (status < 0) {
          response->set_status(status);
          return ::grpc::Status::OK;
        }
        ViInt32 buffer_size = status;

        std::string value(buffer_size, '\0');
        status = library_->GetAttributeViString(session, channel_name, attribute_id, buffer_size, (ViChar*)value.data());
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
        response->set_status(status);
        if (status == 0) {
          response->set_value(value);
        }
        return ::grpc::Status::OK;
      }
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

::grpc::Status NiTClkService::ConvertApiErrorStatusForViSession(google::protobuf::int32 status, ViSession session_number)
{
    std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
    library_->GetExtendedErrorInfo(description.data(), nidevice_grpc::kMaxGrpcErrorDescriptionSize);
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nitclk_grpc
