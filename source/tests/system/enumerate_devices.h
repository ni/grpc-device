#ifndef NIDEVICE_GRPC_TESTS_ENUMERATE_DEVICES
#define NIDEVICE_GRPC_TESTS_ENUMERATE_DEVICES

#include <server/device_enumerator.h>

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties> EnumerateDevices(bool clear_cache = false);

}  // namespace system
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_TESTS_ENUMERATE_DEVICES
