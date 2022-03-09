#include "nixnet/nixnet_service.h"

#include "custom/nixnet_custom.h"
// #include <server/converters.h>

namespace nixnet_grpc {
  using nidevice_grpc::converters::convert_to_grpc;

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiXnetService::ConvertByteArrayToFramesSinglePoint(::grpc::ServerContext* context, const ConvertByteArrayToFramesSinglePointRequest* request, ConvertByteArrayToFramesSinglePointResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_ref_grpc_session = request->session_ref();
      nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
      auto value_buffer = (u8*)(request->value_buffer().c_str());
      u32 size_of_value_buffer = static_cast<u32>(request->value_buffer().size());
      u32 size_of_buffer = request->size_of_buffer();
      std::string buffer(size_of_buffer, '\0');
      u32 number_of_bytes_returned {};
      auto status = library_->ConvertByteArrayToFramesSinglePoint(session_ref, value_buffer, size_of_value_buffer, (void*)buffer.c_str(), size_of_buffer, &number_of_bytes_returned);
      response->set_status(status);
      if (status == 0) {
        auto buffer_ptr = (void*)buffer.c_str();
        while(buffer_ptr < buffer.c_str() + number_of_bytes_returned) {
          auto l_Frame = (nxFrameVar_t*)buffer_ptr;
          auto frame = new Frame();

          convert_to_grpc(*l_Frame, frame);

          response->mutable_buffer()->AddAllocated(frame);
          buffer_ptr = nxFrameIterate(l_Frame);
        }
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiXnetService::ConvertSignalsToFramesSinglePoint(::grpc::ServerContext* context, const ConvertSignalsToFramesSinglePointRequest* request, ConvertSignalsToFramesSinglePointResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_ref_grpc_session = request->session_ref();
      nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
      auto value_buffer = const_cast<f64*>(request->value_buffer().data());
      u32 size_of_value_buffer = static_cast<u32>(request->value_buffer().size());
      u32 size_of_buffer = request->size_of_buffer();
      std::string buffer(size_of_buffer, '\0');
      u32 number_of_bytes_returned {};
      auto status = library_->ConvertSignalsToFramesSinglePoint(session_ref, value_buffer, size_of_value_buffer, (void*)buffer.c_str(), size_of_buffer, &number_of_bytes_returned);
      response->set_status(status);
      if (status == 0) {
        auto buffer_ptr = (void*)buffer.c_str();
        while(buffer_ptr < buffer.c_str() + number_of_bytes_returned) {
          auto l_Frame = (nxFrameVar_t*)buffer_ptr;
          auto frame = new Frame();

          convert_to_grpc(*l_Frame, frame);

          response->mutable_buffer()->AddAllocated(frame);
          buffer_ptr = nxFrameIterate(l_Frame);
        }
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }
}  // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {

template <>
void convert_to_grpc(const nxFrameVar_t& input, nixnet_grpc::Frame* output) 
{
  output->set_timestamp(input.Timestamp);
  output->set_identifier(input.Identifier);
  output->set_type(input.Type);
  output->set_flags(input.Flags);
  output->set_info(input.Info);
  output->set_payload_length(input.PayloadLength);
  output->mutable_payload()->resize(input.PayloadLength, '\0'); // TODO: Should this be PayloadLength+1 to accomodate null termination?
  output->mutable_payload()->assign((const char*)input.Payload, input.PayloadLength);
}

} // converters
} // nidevice_grpc
