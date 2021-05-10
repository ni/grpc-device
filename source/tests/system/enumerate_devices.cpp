#include <optional>
#include <stdexcept>

#include <server/device_enumerator.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>

namespace ni {
namespace tests {
namespace system {

const google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties> EnumerateDevices(bool clear_cache)
{
  static std::optional<google::protobuf::RepeatedPtrField<nidevice_grpc::DeviceProperties>> devices_cache;
  if (!devices_cache || clear_cache) {
    devices_cache.reset();

    ::grpc::ServerBuilder builder;
    ::nidevice_grpc::SessionRepository session_repository;
    ::nidevice_grpc::SysCfgLibrary syscfg_library;
    ::nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_library);
    ::nidevice_grpc::SessionUtilitiesService core_service(&session_repository, &device_enumerator);
    builder.RegisterService(&core_service);

    auto server = builder.BuildAndStart();
    auto channel = server->InProcessChannel(::grpc::ChannelArguments());
    ::nidevice_grpc::SessionUtilities::Stub stub(channel);

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
