#include "enumerate_devices.h"

#include <optional>
#include <stdexcept>

#include <server/session_utilities_service.h>
#include "device_server.h"

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties> EnumerateDevices(bool clear_cache)
{
  static std::optional<google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties>> devices_cache;
  if (!devices_cache || clear_cache) {
    devices_cache.reset();

    ::nidevice_grpc::SessionUtilities::Stub stub(DeviceServerInterface::Singleton()->InProcessChannel());

    nidevice_grpc::EnumerateDevicesRequest request;
    nidevice_grpc::EnumerateDevicesResponse response;
    ::grpc::ClientContext context;

    if (::grpc::StatusCode::OK != stub.EnumerateDevices(&context, request, &response).error_code()) {
      throw std::runtime_error("Failed to enumerate devices");
    }

    devices_cache = response.devices();
  }

  return devices_cache.value();
}

}  // namespace system
}  // namespace tests
}  // namespace ni
