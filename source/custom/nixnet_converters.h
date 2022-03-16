#ifndef NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H
#include <nixnet.h>
#include <nixnet.pb.h>

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const nxEptRxFilter_Element_t& input, nixnet_grpc::EptRxFilter* output)
{
  output->set_use_flags(input.UseFlags);
  output->set_vid(input.VID);
  output->set_priority(input.Priority);
  output->mutable_destination_mac()->copy((char*)input.DestinationMAC, sizeof(nxMACAddress_t));
}

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIXNET_CONVERTERS_H */