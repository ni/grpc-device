#include "enumerate_software.h"

#include <stdexcept>

#include "device_server.h"

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> EnumerateInstalledSoftware(bool clear_cache)
{
  static bool software_is_cached = false;
  static google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software_cache;

  if (!software_is_cached || clear_cache) {
    software_is_cached = false;

    ::nidevice_grpc::SessionUtilities::Stub stub(DeviceServerInterface::Singleton()->InProcessChannel());

    nidevice_grpc::EnumerateInstalledSoftwareRequest request;
    nidevice_grpc::EnumerateInstalledSoftwareResponse response;
    ::grpc::ClientContext context;

    if (::grpc::StatusCode::OK != stub.EnumerateInstalledSoftware(&context, request, &response).error_code()) {
      throw std::runtime_error("Failed to enumerate software");
    }

    software_cache.CopyFrom(response.software());
    software_is_cached = true;
  }

  return software_cache;
}

}  // namespace system
}  // namespace tests
}  // namespace ni
