#include "device_server.h"

#include <server/device_enumerator.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>
#include <niscope/niscope_library.h>
#include <niscope/niscope_service.h>
#include <niswitch/niswitch_library.h>
#include <niswitch/niswitch_service.h>
#include <nisync/nisync_library.h>
#include <nisync/nisync_service.h>
#include <nidcpower/nidcpower_library.h>
#include <nidcpower/nidcpower_service.h>

namespace ni {
namespace tests {
namespace system {

DeviceServerInterface::~DeviceServerInterface() {}

class DeviceServer : public DeviceServerInterface {
 public:
  DeviceServer();
  ~DeviceServer() override {};

  // DeviceServerInterface overrides
  void ResetServer() override;
  std::shared_ptr<::grpc::Channel> InProcessChannel() override;

 private:
  nidevice_grpc::SessionRepository session_repository_;
  nidevice_grpc::SysCfgLibrary syscfg_library_;
  nidevice_grpc::DeviceEnumerator device_enumerator_;
  nidevice_grpc::SessionUtilitiesService core_service_;
  niscope_grpc::NiScopeLibrary niscope_library_;
  niscope_grpc::NiScopeService niscope_service_;
  niswitch_grpc::NiSwitchLibrary niswitch_library_;
  niswitch_grpc::NiSwitchService niswitch_service_;
  nisync_grpc::NiSyncLibrary nisync_library_;
  nisync_grpc::NiSyncService nisync_service_;
  nidcpower_grpc::NiDCPowerLibrary nidcpower_library_;
  nidcpower_grpc::NiDCPowerService nidcpower_service_;

  std::unique_ptr<::grpc::Server> server_;
  std::shared_ptr<::grpc::Channel> channel_;
};

DeviceServer::DeviceServer()
    : session_repository_(),
      syscfg_library_(),
      device_enumerator_(&syscfg_library_),
      core_service_(&session_repository_, &device_enumerator_),
      niscope_library_(),
      niscope_service_(&niscope_library_, &session_repository_),
      niswitch_library_(),
      niswitch_service_(&niswitch_library_, &session_repository_),
      nisync_library_(),
      nisync_service_(&nisync_library_, &session_repository_),
      nidcpower_library_(),
      nidcpower_service_(&nidcpower_library_, &session_repository_)
{
  grpc::ServerBuilder builder;
  builder.RegisterService(&core_service_);
  builder.RegisterService(&niscope_service_);
  builder.RegisterService(&niswitch_service_);
  builder.RegisterService(&nisync_service_);
  builder.RegisterService(&nidcpower_service_);
  server_ = builder.BuildAndStart();
}

void DeviceServer::ResetServer()
{
  session_repository_.reset_server();
}

std::shared_ptr<::grpc::Channel> DeviceServer::InProcessChannel()
{
  if (!channel_) {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
  }
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
