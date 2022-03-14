#include <nixnet/nixnet_service.h>
#include <server/converters.h>

#include <stdexcept>

#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

void convert_to_grpc(const std::string& input, google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBuffer>* output, u32 number_of_bytes, nixnet_grpc::FrameType frame_type)
{
  auto buffer_ptr = (void*)input.c_str();
  while (buffer_ptr < input.c_str() + number_of_bytes) {
    auto frame_buffer = new FrameBuffer();
    convert_to_grpc<FrameBuffer>(buffer_ptr, frame_buffer, frame_type);
    output->AddAllocated(frame_buffer);
    if (frame_type == nixnet_grpc::FrameType::FRAME_TYPE_ENET) {
      auto enet_frame_ptr = (nxFrameEnet_t*)buffer_ptr;
      buffer_ptr = nxFrameIterateEthernetRead(enet_frame_ptr);
    }
    else {
      buffer_ptr = nxFrameIterate((nxFrameVar_t*)buffer_ptr);
    }
  }
}

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
    nixnet_grpc::FrameType frame_type = request->frame_type();
    std::string buffer(size_of_buffer, '\0');
    u32 number_of_bytes_returned{};
    auto status = library_->ConvertByteArrayToFramesSinglePoint(session_ref, value_buffer, size_of_value_buffer, (void*)buffer.c_str(), size_of_buffer, &number_of_bytes_returned);
    response->set_status(status);
    if (status == 0) {
      convert_to_grpc(buffer, response->mutable_buffer(), number_of_bytes_returned, frame_type);
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
    nixnet_grpc::FrameType frame_type = request->frame_type();
    std::string buffer(size_of_buffer, '\0');
    u32 number_of_bytes_returned;

    auto status = library_->ConvertSignalsToFramesSinglePoint(session_ref, value_buffer, size_of_value_buffer, (void*)buffer.c_str(), size_of_buffer, &number_of_bytes_returned);
    response->set_status(status);
    if (status == 0) {
      convert_to_grpc(buffer, response->mutable_buffer(), number_of_bytes_returned, frame_type);
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
    u32 size_of_value_buffer = request->size_of_value_buffer();
    u32 size_of_timestamp_buffer = request->size_of_timestamp_buffer();
    response->mutable_value_buffer()->Resize(size_of_value_buffer, 0);
    f64* value_buffer = response->mutable_value_buffer()->mutable_data();
    response->mutable_timestamp_buffer()->Resize(size_of_timestamp_buffer, 0);
    nxTimestamp100ns_t* timestamp_buffer = reinterpret_cast<nxTimestamp100ns_t*>(response->mutable_timestamp_buffer()->mutable_data());
    FrameHolder buffer = convert_from_grpc<FrameBuffer>(request->frame_buffer());

    auto status = library_->ConvertFramesToSignalsSinglePoint(session_ref, (void*)buffer, buffer.size(), value_buffer, size_of_value_buffer, timestamp_buffer, size_of_timestamp_buffer);
    response->set_status(status);
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
nixnet_grpc::FrameHolder convert_from_grpc(const pb_::RepeatedPtrField<nixnet_grpc::FrameBuffer>& input)
{
  return nixnet_grpc::FrameHolder(input);
}

template <typename TFrame>
// TODO: Fix to use something like void& for input, we don't know the frame type yet.
// OR
// update caller to call different overrides for enet vs non-enet frames
void convert_to_grpc(const void* input, nixnet_grpc::FrameBuffer* output, nixnet_grpc::FrameType frame_type)
{
  if (frame_type == nixnet_grpc::FrameType::FRAME_TYPE_ENET) {
    nixnet_grpc::EnetFrame* enet_frame = new nixnet_grpc::EnetFrame();
    nxFrameEnet_t* nxEnetFrame = (nxFrameEnet_t*)input;
    enet_frame->set_type(nxEnetFrame->Type);
    enet_frame->set_device_timestamp(nxEnetFrame->DeviceTimestamp);
    enet_frame->set_network_timestamp(nxEnetFrame->NetworkTimestamp);
    enet_frame->set_flags(nxEnetFrame->Flags);
    auto enet_header_length = sizeof(nxFrameEnet_t) - 1;  // last byte in nxFrameEnet_t is u8 FrameData[1]
    auto frame_data_length = nxEnetFrame->Length - enet_header_length;
    enet_frame->mutable_frame_data()->assign((const char*)nxEnetFrame->FrameData, frame_data_length);

    output->set_allocated_enet(enet_frame);
  }
  else {
    nxFrameVar_t* nxFrame = (nxFrameVar_t*)input;
    nixnet_grpc::Frame* frame = new nixnet_grpc::Frame();
    frame->set_timestamp(nxFrame->Timestamp);
    frame->set_identifier(nxFrame->Identifier);
    frame->set_type(nxFrame->Type);
    frame->set_flags(nxFrame->Flags);
    frame->set_info(nxFrame->Info);
    auto payload_length = nxFrameGetPayloadLength(nxFrame);
    frame->mutable_payload()->assign((const char*)nxFrame->Payload, payload_length);

    switch (frame_type) {
      case nixnet_grpc::FrameType::FRAME_TYPE_CAN:
        output->set_allocated_can(frame);
        break;
      case nixnet_grpc::FrameType::FRAME_TYPE_LIN:
        output->set_allocated_lin(frame);
        break;
      case nixnet_grpc::FrameType::FRAME_TYPE_FLEX_RAY:
        output->set_allocated_flex_ray(frame);
        break;
      case nixnet_grpc::FrameType::FRAME_TYPE_J1939:
        output->set_allocated_j1939(frame);
        break;
      default:
        // TODO: error
        break;
    }
  }
}
}  // namespace converters
}  // namespace nidevice_grpc