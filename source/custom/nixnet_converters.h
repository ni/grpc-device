#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#include <nixnet.h>
#include <nixnet.pb.h>

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;

namespace nixnet_grpc {

// This class allows us to have something allocated on the stack that can be used as an
// nxsockaddr* and initialized from a grpc SockAddr using standard codegen and copy convert routines.
struct FrameHolder {
  FrameHolder(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    // TODO: pending verification of copy operation
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
        // TODO: error
        break;
    }
  }

  void InitializeCanFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_can()) {
        // TODO: return error, frames inconsistent
      }
      ConvertFrame(grpc_frame.can(), frame_data);

      // TODO: optimize to use single vector instead of copying every frame to main vector
      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeLinFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_lin()) {
        // TODO: return error, frames inconsistent
      }
      ConvertFrame(grpc_frame.lin(), frame_data);

      // TODO: optimize to use single vector instead of copying every frame to main vector
      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeFlexRayFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_flex_ray()) {
        // TODO: return error, frames inconsistent
      }
      ConvertFrame(grpc_frame.flex_ray(), frame_data);

      // TODO: optimize to use single vector instead of copying every frame to main vector
      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeJ1939Frames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_j1939()) {
        // TODO: return error, frames inconsistent
      }
      ConvertFrame(grpc_frame.j1939(), frame_data);

      // TODO: optimize to use single vector instead of copying every frame to main vector
      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeEnetFrames(const pb_::RepeatedPtrField<FrameBuffer>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_enet()) {
        // TODO: return error, frames inconsistent
      }

      auto enet_header_length = sizeof(nxFrameEnet_t) - 1;  // last byte in nxFrameEnet_t is u8 FrameData[1]
      u16 frame_size = enet_header_length + grpc_frame.enet().frame_data().length();
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

      // TODO: optimize to use single vector instead of copying every frame to main vector
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

  // Implicit conversion to nxsockaddr* simplifies codegen because these are passed by pointer to
  // the driver.
  operator void*()
  {
    return frame_buffer.data();
  }

  operator const void*() const
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
}  // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {

template <typename TFrame>
nixnet_grpc::FrameHolder convert_from_grpc(const pb_::RepeatedPtrField<nixnet_grpc::FrameBuffer>& input);
template <typename TFrame>
void convert_to_grpc(const void* input, nixnet_grpc::FrameBuffer* output, nixnet_grpc::FrameType frame_type);

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */