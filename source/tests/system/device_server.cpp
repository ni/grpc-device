#include "device_server.h"

#include <grpcpp/grpcpp.h>
#include <register_all_services.h>
#include <server/feature_toggles.h>
#include <session.grpc.pb.h>
#include <session_utilities.grpc.pb.h>

namespace ni {
namespace tests {
namespace system {

using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;

DeviceServerInterface::~DeviceServerInterface() {}

class DeviceServer : public DeviceServerInterface {
 public:
  DeviceServer();
  ~DeviceServer() override;

  // DeviceServerInterface overrides
  void ResetServer() override;
  std::shared_ptr<::grpc::Channel> InProcessChannel() override;

 private:
  grpc::ServerBuilder builder_;
  std::shared_ptr<std::vector<std::shared_ptr<void>>> services_;
  std::unique_ptr<::grpc::Server> server_;
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<nidevice_grpc::SessionUtilities::Stub> session_stub_;
};

DeviceServer::DeviceServer()
    : builder_(),
      services_(
          nidevice_grpc::register_all_services(
              builder_,
              // Tests run with RestrictedNextRelease CodeReadiness.
              nidevice_grpc::FeatureToggles({}, CodeReadiness::kRestrictedNextRelease))),
      server_(builder_.BuildAndStart()),
      channel_(server_->InProcessChannel(::grpc::ChannelArguments())),
      session_stub_(nidevice_grpc::SessionUtilities::NewStub(channel_))
{
}

DeviceServer::~DeviceServer()
{
  // destroy services in reverse order
  while (!services_->empty())
  {
    services_->pop_back();
  }
}

void DeviceServer::ResetServer()
{
  grpc::ClientContext context;
  auto request = nidevice_grpc::ResetServerRequest{};
  auto response = nidevice_grpc::ResetServerResponse{};
  session_stub_->ResetServer(&context, request, &response);
}

std::shared_ptr<::grpc::Channel> DeviceServer::InProcessChannel()
{
  return channel_;
}

DeviceServerInterface* DeviceServerInterface::Singleton()
{
  static auto singleton = std::make_unique<DeviceServer>();
  return singleton.get();
}

}  // namespace system
}  // namespace tests
}  // namespace ni
