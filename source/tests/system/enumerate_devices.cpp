#include "enumerate_devices.h"

#include <stdexcept>

#include "device_server.h"

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties> EnumerateDevices(bool clear_cache)
{
  static bool devices_are_cached = false;
  static google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties> devices_cache;

  if (!devices_are_cached || clear_cache) {
    devices_are_cached = false;

    ::nidevice_grpc::SessionUtilities::Stub stub(DeviceServerInterface::Singleton()->InProcessChannel());

    nidevice_grpc::EnumerateDevicesRequest request;
    nidevice_grpc::EnumerateDevicesResponse response;
    ::grpc::ClientContext context;

    if (::grpc::StatusCode::OK != stub.EnumerateDevices(&context, request, &response).error_code()) {
      throw std::runtime_error("Failed to enumerate devices");
    }

    devices_cache.CopyFrom(response.devices());
    devices_are_cached = true;
  }

  return devices_cache;
}

}  // namespace system
}  // namespace tests
}  // namespace ni
