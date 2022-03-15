#include <nixnet/nixnet_service.h>
#include <server/converters.h>

#include <stdexcept>

#include "custom/nixnet_converters.h"

namespace nixnet_grpc {
// template <>
void convert_to_grpc(std::vector<u8>& input, google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBuffer>* output, u32 number_of_bytes, u32 frame_type)
{
  auto buffer_ptr = (void*)input.data();
  while (buffer_ptr < input.data() + number_of_bytes) {
    auto frame_buffer = new FrameBuffer();
    convert_to_grpc(buffer_ptr, frame_buffer, frame_type);
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

// template <>
void convert_to_grpc(const void* input, nixnet_grpc::FrameBuffer* output, u32 frame_type)
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
        throw std::invalid_argument("The value for frame_type was not specified or out of range");
        break;
    }
  }
}
}  // namespace nixnet_grpc
