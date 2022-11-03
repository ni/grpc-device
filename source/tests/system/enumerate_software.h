#ifndef NIDEVICE_GRPC_TESTS_ENUMERATE_SOFTWARE
#define NIDEVICE_GRPC_TESTS_ENUMERATE_SOFTWARE

#include <server/software_enumerator.h>

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> EnumerateInstalledSoftware(bool clear_cache = false);

}  // namespace system
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_TESTS_ENUMERATE_SOFTWARE
