#include "enumerate_software.h"

#include <stdexcept>

#include "device_server.h"

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> EnumerateSoftware(bool clear_cache)
{
  static bool devices_are_cached = false;
  static google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> devices_cache;

  if (!devices_are_cached || clear_cache) {
    devices_are_cached = false;

    ::nidevice_grpc::SessionUtilities::Stub stub(DeviceServerInterface::Singleton()->InProcessChannel());

    nidevice_grpc::EnumerateSoftwareRequest request;
    nidevice_grpc::EnumerateSoftwareResponse response;
    ::grpc::ClientContext context;

    if (::grpc::StatusCode::OK != stub.EnumerateSoftware(&context, request, &response).error_code()) {
      throw std::runtime_error("Failed to enumerate software");
    }

    devices_cache.CopyFrom(response.software());
    devices_are_cached = true;
  }

  return devices_cache;
}

}  // namespace system
}  // namespace tests
}  // namespace ni
