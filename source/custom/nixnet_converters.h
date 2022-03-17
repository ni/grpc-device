#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#include <nixnet.h>
#include <nixnet.pb.h>

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const _nxFlexRayStats_t& input, nixnet_grpc::FlexRayStats *output);
template <>
void convert_to_grpc(const _nxJ1939CommState_t& input, nixnet_grpc::J1939CommState *output);
} // namespace converters
} // namespace nidevice_grpc


#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */