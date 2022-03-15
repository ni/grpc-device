#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#include <nixnet.h>
#include <nixnet.pb.h>

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;

namespace nixnet_grpc {

struct FrameHolder {
  FrameHolder(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    // all frames in repeated field must be of same type
    switch (input[0].frame_case()) {
      case FrameBuffer::kCan:
        InitializeCanFrames(input);
        break;
      case FrameBuffer::kLin:
        InitializeLinFrames(input);
        break;
      case FrameBuffer::kFlexRay:
        InitializeFlexRayFrames(input);
        break;
      case FrameBuffer::kJ1939:
        InitializeJ1939Frames(input);
        break;
      case FrameBuffer::kEnet:
        InitializeEnetFrames(input);
        break;
      default:
        throw std::invalid_argument("The value for FrameBuffer not specified or not supported");
        break;
    }
  }

  void InitializeCanFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_can()) {
        throw std::invalid_argument("All FrameBuffer instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.can(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeLinFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_lin()) {
        throw std::invalid_argument("All FrameBuffer instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.lin(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeFlexRayFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_flex_ray()) {
        throw std::invalid_argument("All FrameBuffer instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.flex_ray(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeJ1939Frames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_j1939()) {
        throw std::invalid_argument("All FrameBuffer instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.j1939(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeEnetFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    const u16 EnetHeaderLength = sizeof(nxFrameEnet_t) - 1;  // last byte in nxFrameEnet_t is u8 FrameData[1]
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_enet()) {
        throw std::invalid_argument("All FrameBuffer instances in repeated field should have same oneof set for the frame");
      }

      u16 frame_size = EnetHeaderLength + grpc_frame.enet().frame_data().length();
      frame_data.resize(frame_size, 0);
      nxFrameEnet_t* current_frame = (nxFrameEnet_t*)frame_data.data();
      // The Length field in ENET write frame is big-endian. Typecast to u16 before doing the conversion
      // as lengh field is 16 bits and BigToHostOrder16 works only for 16 bits.
      current_frame->Length = BigToHostOrder16(frame_size);
      current_frame->Type = grpc_frame.enet().type();
      current_frame->DeviceTimestamp = grpc_frame.enet().device_timestamp();
      current_frame->NetworkTimestamp = grpc_frame.enet().network_timestamp();
      current_frame->Flags = grpc_frame.enet().flags();
      std::memcpy(
          current_frame->FrameData,
          grpc_frame.enet().frame_data().data(),
          grpc_frame.enet().frame_data().length());

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void ConvertFrame(const Frame& input, std::vector<uint8_t>& output)
  {
    auto payload_length = input.payload().length();
    auto frame_size = nxFrameSize(payload_length);
    output.resize(frame_size, 0);
    nxFrameVar_t* current_frame = (nxFrameVar_t*)output.data();
    current_frame->Timestamp = input.timestamp();
    current_frame->Identifier = input.identifier();
    current_frame->Type = input.type();
    current_frame->Flags = input.flags();
    current_frame->Info = input.info();
    nxFrameSetPayloadLength(current_frame, payload_length);
    std::memcpy(
        current_frame->Payload,
        input.payload().data(),
        payload_length);
  }

  void* data()
  {
    return frame_buffer.data();
  }

  // size() method is used to simplify codegen calculating the size of the
  // selected frame buffer.
  uint32_t size() const
  {
    // size_of_buffer param for all frame APIs is uint32, we can't possibly exceed that.
    return (uint32_t)frame_buffer.size();
  }

  std::vector<uint8_t> frame_buffer;
};

// template <>
void convert_to_grpc(std::vector<u8>& input, google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBuffer>* output, u32 number_of_bytes, u32 frame_type);

// template <>
void convert_to_grpc(const void* input, nixnet_grpc::FrameBuffer* output, u32 frame_type);

template <typename TFrame>
nixnet_grpc::FrameHolder convert_from_grpc(const pb_::RepeatedPtrField<nixnet_grpc::FrameBuffer>& input)
{
  return nixnet_grpc::FrameHolder(input);
}
}  // namespace nixnet_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */