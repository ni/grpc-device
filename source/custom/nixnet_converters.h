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
    FrameHolder(const pb_::RepeatedPtrField<Frame>& input)
    {
        // TODO: pending verification of copy operation
        std::vector<uint8_t> frame_data;
        for(auto grpc_frame : input) {

            auto frame_size = nxFrameSize(grpc_frame.payload_length());
            frame_data.resize(frame_size, 0);
            nxFrameVar_t* current_frame = (nxFrameVar_t*)frame_data.data();
            current_frame->Timestamp = grpc_frame.timestamp();
            current_frame->Identifier = grpc_frame.identifier();
            current_frame->Type = grpc_frame.type();
            current_frame->Flags = grpc_frame.flags();
            current_frame->Info = grpc_frame.info();
            nxFrameSetPayloadLength(current_frame, grpc_frame.payload_length());
            for(uint32_t i=0; i<grpc_frame.payload_length(); i++) {
                current_frame->Payload[i] = grpc_frame.payload().c_str()[i];
                std::cout << (u8)grpc_frame.payload().c_str()[i] << "-";
            } 

            // TODO: optimize to use single vector instead of copying every frame to main vector
            frame_buffer.insert(frame_buffer.end(), frame_data.begin(), frame_data.end());
        }
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
} // namespace nixnet_grpc

namespace nidevice_grpc {
namespace converters {

template <typename TFrame>
nixnet_grpc::FrameHolder convert_from_grpc(const pb_::RepeatedPtrField<nixnet_grpc::Frame>& input);
template <typename TFrame>
void convert_to_grpc(const nxFrameVar_t& input, nixnet_grpc::Frame* output);

} // namespace converters
} // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */ 