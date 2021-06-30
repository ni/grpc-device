#include "device_server.h"

#include <nidaqmx/nidaqmx_library.h>
#include <nidaqmx/nidaqmx_service.h>
#include <nidcpower/nidcpower_library.h>
#include <nidcpower/nidcpower_service.h>
#include <nidigitalpattern/nidigitalpattern_library.h>
#include <nidigitalpattern/nidigitalpattern_service.h>
#include <nifgen/nifgen_library.h>
#include <nifgen/nifgen_service.h>
#include <niscope/niscope_library.h>
#include <niscope/niscope_service.h>
#include <niswitch/niswitch_library.h>
#include <niswitch/niswitch_service.h>
#include <nisync/nisync_library.h>
#include <nisync/nisync_service.h>
#include <nitclk/nitclk_library.h>
#include <nitclk/nitclk_service.h>
#include <server/device_enumerator.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>

namespace ni {
namespace tests {
namespace system {

DeviceServerInterface::~DeviceServerInterface() {}

class DeviceServer : public DeviceServerInterface {
 public:
  DeviceServer();
  ~DeviceServer() override{};

  // DeviceServerInterface overrides
  void ResetServer() override;
  std::shared_ptr<::grpc::Channel> InProcessChannel() override;

 private:
  using MIResourceRepository = nidevice_grpc::SessionResourceRepository<ViSession>;
  using DAQmxResourceRepository = nidevice_grpc::SessionResourceRepository<TaskHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<MIResourceRepository> mi_shared_resource_repository_;
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
  nidigitalpattern_grpc::NiDigitalLibrary nidigital_library_;
  nidigitalpattern_grpc::NiDigitalService nidigital_service_;
  nifgen_grpc::NiFgenLibrary nifgen_library_;
  nifgen_grpc::NiFgenService nifgen_service_;
  nitclk_grpc::NiTClkLibrary nitclk_library_;
  nitclk_grpc::NiTClkService nitclk_service_;
  nidaqmx_grpc::NiDAQmxLibrary nidaqmx_library_;
  nidaqmx_grpc::NiDAQmxService nidaqmx_service_;

  std::unique_ptr<::grpc::Server> server_;
  std::shared_ptr<::grpc::Channel> channel_;
};

DeviceServer::DeviceServer()
    : session_repository_(),
      mi_shared_resource_repository_(std::make_shared<MIResourceRepository>(&session_repository_)),
      syscfg_library_(),
      device_enumerator_(&syscfg_library_),
      core_service_(&session_repository_, &device_enumerator_),
      niscope_library_(),
      niscope_service_(&niscope_library_, mi_shared_resource_repository_),
      niswitch_library_(),
      niswitch_service_(&niswitch_library_, mi_shared_resource_repository_),
      nisync_library_(),
      nisync_service_(&nisync_library_, mi_shared_resource_repository_),
      nidcpower_library_(),
      nidcpower_service_(&nidcpower_library_, mi_shared_resource_repository_),
      nidigital_library_(),
      nidigital_service_(&nidigital_library_, mi_shared_resource_repository_),
      nifgen_library_(),
      nifgen_service_(&nifgen_library_, mi_shared_resource_repository_),
      nitclk_library_(),
      nitclk_service_(&nitclk_library_, mi_shared_resource_repository_),
      nidaqmx_library_(),
      nidaqmx_service_(&nidaqmx_library_, std::make_shared<DAQmxResourceRepository>(&session_repository_))
{
  grpc::ServerBuilder builder;
  builder.RegisterService(&core_service_);
  builder.RegisterService(&niscope_service_);
  builder.RegisterService(&niswitch_service_);
  builder.RegisterService(&nisync_service_);
  builder.RegisterService(&nidcpower_service_);
  builder.RegisterService(&nidigital_service_);
  builder.RegisterService(&nifgen_service_);
  builder.RegisterService(&nitclk_service_);
  builder.RegisterService(&nidaqmx_service_);
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
