#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CUSTOM_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CUSTOM_H


namespace nidevice_grpc {
namespace converters {

template <>
void convert_to_grpc(const nxFrameVar_t& input, nixnet_grpc::Frame* output);

} // converters
} // nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CUSTOM_H */
