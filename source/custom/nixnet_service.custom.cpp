#include <nixnet/nixnet_service.h>
#include <server/converters.h>
#include <stdexcept>

#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
  using nidevice_grpc::converters::convert_to_grpc;
  using nidevice_grpc::converters::convert_from_grpc;

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
      u32 size_of_value_buffer = static_cast<u32>(request->value_buffer().size()) * sizeof(u32);
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

          convert_to_grpc<nxFrameVar_t>(*l_Frame, frame);

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
      u32 number_of_bytes_returned;

      void* property_value = &number_of_bytes_returned;
      auto status = library_->ConvertSignalsToFramesSinglePoint(session_ref, value_buffer, size_of_value_buffer, (void*)buffer.c_str(), size_of_buffer, &number_of_bytes_returned);
      response->set_status(status);
      if (status == 0) {
        auto buffer_ptr = (void*)buffer.c_str();
        while(buffer_ptr < buffer.c_str() + number_of_bytes_returned) {
          auto l_Frame = (nxFrameVar_t*)buffer_ptr;
          auto frame = new Frame();

          convert_to_grpc<nxFrameVar_t>(*l_Frame, frame);

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
  ::grpc::Status NiXnetService::ConvertFramesToSignalsSinglePoint(::grpc::ServerContext* context, const ConvertFramesToSignalsSinglePointRequest* request, ConvertFramesToSignalsSinglePointResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_ref_grpc_session = request->session_ref();
      nxSessionRef_t session_ref = session_repository_->access_session(session_ref_grpc_session.id(), session_ref_grpc_session.name());
      // auto frame_buffer = const_cast<void*>(request->frame_buffer().data());
      // u32 number_of_bytes_for_frames = static_cast<u32>(request->frame_buffer().size());
      u32 size_of_value_buffer = request->size_of_value_buffer();
      u32 size_of_timestamp_buffer = request->size_of_timestamp_buffer();
      response->mutable_value_buffer()->Resize(size_of_value_buffer, 0);
      f64* value_buffer = response->mutable_value_buffer()->mutable_data();
      response->mutable_timestamp_buffer()->Resize(size_of_timestamp_buffer, 0);
      nxTimestamp100ns_t* timestamp_buffer = reinterpret_cast<nxTimestamp100ns_t*>(response->mutable_timestamp_buffer()->mutable_data());

      FrameHolder buffer = convert_from_grpc<Frame>(request->frame_buffer());

  //     auto output = std::vector<char>();
  //     output.reserve(request->frame_buffer_size());
  //     std::transform(
  //       request->frame_buffer().begin(),
  //       request->frame_buffer().end(),
  //       std::back_inserter(output),
  //       [&](GrpcType x) { return convert_from_grpc<CType>(x); });
  // return nullable_vector<CType>(std::move(output));


      auto status = library_->ConvertFramesToSignalsSinglePoint(session_ref, (void*)buffer, buffer.size(), value_buffer, size_of_value_buffer, timestamp_buffer, size_of_timestamp_buffer);
      response->set_status(status);
      // if (status == 0) {
      // }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }
}  // namespace nixnet_grpc


namespace nidevice_grpc {
namespace converters {
template <typename TFrame>
nixnet_grpc::FrameHolder convert_from_grpc(const pb_::RepeatedPtrField<nixnet_grpc::Frame>& input)
{
  return nixnet_grpc::FrameHolder(input);
}

template <typename TFrame>
void convert_to_grpc(const nxFrameVar_t& input, nixnet_grpc::Frame* output) 
{
  auto payloadLength = nxFrameGetPayloadLength(&input);
  output->set_timestamp(input.Timestamp);
  output->set_identifier(input.Identifier);
  output->set_type(input.Type);
  output->set_flags(input.Flags);
  output->set_info(input.Info);
  output->set_payload_length(payloadLength);
  output->mutable_payload()->resize(payloadLength, '\0');
  output->mutable_payload()->assign((const char*)input.Payload, payloadLength);
}
} // converters
} // nidevice_grpc 