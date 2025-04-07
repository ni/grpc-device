#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#include <nixnet.h>
#include <nixnet.pb.h>

#include "server/converters.h"

namespace nixnet_grpc {
namespace converters {
void SetCanCommResponse(const u32 input, nixnet_grpc::CanCommResponse* output);
void SetFlexRayCommResponse(const u32 input, nixnet_grpc::FlexRayCommResponse* output);
void SetLinCommResponse(const u32* input, nixnet_grpc::LinCommResponse* output);
void SetSessionInfoResponse(const u32& input, nixnet_grpc::SessionInfoResponse* output);
}  // namespace converters

constexpr auto ENET_FRAME_HEADER_LENGTH = static_cast<u16>(sizeof(nxFrameEnet_t) - 1);  // last byte in nxFrameEnet_t is u8 FrameData[1]
constexpr auto ENET_FRAME_FCS_SIZE = 4;

u32 get_frame_buffer_size(int32 number_of_frames, u32 max_payload_size, u32 protocol);

struct FrameHolder {
  FrameHolder(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input, std::map<std::int32_t, std::int32_t> enetflags_input_map)
  {
    // all frames in repeated field must be of same type
    switch (input[0].frame_case()) {
      case FrameBufferRequest::kCan:
        InitializeCanFrames(input);
        break;
      case FrameBufferRequest::kLin:
        InitializeLinFrames(input);
        break;
      case FrameBufferRequest::kFlexRay:
        InitializeFlexRayFrames(input);
        break;
      case FrameBufferRequest::kJ1939:
        InitializeJ1939Frames(input);
        break;
      case FrameBufferRequest::kEnet:
        InitializeEnetFrames(input, enetflags_input_map);
        break;
      default:
        throw std::invalid_argument("The value for FrameBufferRequest not specified or not supported");
        break;
    }
  }

  void InitializeCanFrames(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_can()) {
        throw std::invalid_argument("All FrameBufferRequest instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.can(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeLinFrames(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_lin()) {
        throw std::invalid_argument("All FrameBufferRequest instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.lin(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeFlexRayFrames(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_flex_ray()) {
        throw std::invalid_argument("All FrameBufferRequest instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.flex_ray(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeJ1939Frames(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_j1939()) {
        throw std::invalid_argument("All FrameBufferRequest instances in repeated field should have same oneof set for the frame");
      }
      ConvertFrame(grpc_frame.j1939(), frame_data);

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void InitializeEnetFrames(const ::google::protobuf::RepeatedPtrField<FrameBufferRequest>& input, std::map<std::int32_t, std::int32_t> enetflags_input_map)
  {
    std::vector<uint8_t> frame_data;
    for (auto grpc_frame : input) {
      if (!grpc_frame.has_enet()) {
        throw std::invalid_argument("All FrameBufferRequest instances in repeated field should have same oneof set for the frame");
      }

      u32 frame_size = get_frame_buffer_size(1, static_cast<u32>(grpc_frame.enet().frame_data().length()), Protocol::PROTOCOL_ENET);
      frame_data.resize(frame_size, 0);
      nxFrameEnet_t* current_frame = (nxFrameEnet_t*)frame_data.data();
      // The Length field in ENET write frame is big-endian. Typecast to u16 before doing the conversion
      // as lengh field is 16 bits and BigToHostOrder16 works only for 16 bits.
      current_frame->Length = BigToHostOrder16(frame_size);
      switch (grpc_frame.enet().type_enum_case()) {
        case nixnet_grpc::EnetFrameRequest::TypeEnumCase::kType: {
          current_frame->Type = static_cast<u8>(grpc_frame.enet().type());
          break;
        }
        case nixnet_grpc::EnetFrameRequest::TypeEnumCase::kTypeRaw: {
          current_frame->Type = static_cast<u8>(grpc_frame.enet().type_raw());
          break;
        }
        case nixnet_grpc::EnetFrameRequest::TypeEnumCase::TYPE_ENUM_NOT_SET: {
          throw std::invalid_argument("The value for type was not specified or out of range");
        }
      }
      current_frame->DeviceTimestamp = grpc_frame.enet().device_timestamp();
      current_frame->NetworkTimestamp = grpc_frame.enet().network_timestamp();
      current_frame->Flags = 0;
      for (int i = 0; i < grpc_frame.enet().flags_mapped_size(); i++) {
        auto enet_flags_enum_imap_it = enetflags_input_map.find(grpc_frame.enet().flags_mapped()[i]);
        if (enet_flags_enum_imap_it == enetflags_input_map.end()) {
          return throw std::invalid_argument("The value for enet flags was not specified or out of range.");
        }
        current_frame->Flags = current_frame->Flags | enet_flags_enum_imap_it->second;
      }
      std::memcpy(
          current_frame->FrameData,
          grpc_frame.enet().frame_data().data(),
          grpc_frame.enet().frame_data().length());

      frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
    }
  }

  void ConvertFrame(const FrameRequest& input, std::vector<uint8_t>& output)
  {
    auto payload_length = input.payload().length();
    auto frame_size = nxFrameSize(payload_length);

    // We need to clear the output buffer since it is being reused for multiple frames.
    // Not clearing it might result in stale data from the previous frame into this one.
    output.clear();
    output.resize(frame_size, 0);
    nxFrameVar_t* current_frame = (nxFrameVar_t*)output.data();
    current_frame->Timestamp = input.timestamp();
    current_frame->Identifier = input.identifier();
    switch (input.type_enum_case()) {
      case nixnet_grpc::FrameRequest::TypeEnumCase::kType: {
        current_frame->Type = static_cast<u8>(input.type());
        break;
      }
      case nixnet_grpc::FrameRequest::TypeEnumCase::kTypeRaw: {
        current_frame->Type = static_cast<u8>(input.type_raw());
        break;
      }
      case nixnet_grpc::FrameRequest::TypeEnumCase::TYPE_ENUM_NOT_SET: {
        throw std::invalid_argument("The value for type was not specified or out of range");
      }
    }
    current_frame->Flags = 0;
    for (int i = 0; i < input.flags_size(); i++) {
      current_frame->Flags = current_frame->Flags | input.flags()[i];
    }
    current_frame->Info = input.info();
    nxFrameSetPayloadLength(current_frame, payload_length);
    std::memcpy(
        current_frame->Payload,
        input.payload().data(),
        payload_length);
  }

  // Implicit conversion to u8* simplifies codegen because these are passed by pointer to
  // the driver.
  operator u8*()
  {
    return frame_buffer.data();
  }

  operator const u8*() const
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

void convert_to_grpc(std::vector<u8>& input, google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBufferResponse>* output, u32 number_of_bytes, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map);

void convert_to_grpc(const void* input, nixnet_grpc::FrameBufferResponse* output, u32 protocol, std::map<std::int32_t, std::int32_t> enetflags_output_map);

template <typename TFrame>
nixnet_grpc::FrameHolder convert_from_grpc(const ::google::protobuf::RepeatedPtrField<nixnet_grpc::FrameBufferRequest>& input, std::map<std::int32_t, std::int32_t> enetflags_input_map)
{
  return nixnet_grpc::FrameHolder(input, enetflags_input_map);
}

void convert_to_grpc(std::vector<f64>& input, google::protobuf::RepeatedField<double>* output, u32 number_of_values_returned, u32 number_of_signals);
}  // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const _nxFlexRayStats_t& input, nixnet_grpc::FlexRayStats* output);
template <>
void convert_to_grpc(const _nxJ1939CommState_t& input, nixnet_grpc::J1939CommState* output);
template <>
void convert_to_grpc(const nxEptRxFilter_Element_t& input, nixnet_grpc::EptRxFilter* output);
template <>
nxEptRxFilter_Element_t convert_from_grpc(const nixnet_grpc::EptRxFilter& input);
}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */
