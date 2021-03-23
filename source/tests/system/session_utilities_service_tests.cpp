#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>

namespace ni {
namespace tests {
namespace system {

using ::testing::IsEmpty;
using ::testing::Not;

class SessionUtilitiesServiceTests : public ::testing::Test {
 protected:
  SessionUtilitiesServiceTests()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    syscfg_library_ = std::make_unique<nidevice_grpc::SysCfgLibrary>();
    device_enumerator_ = std::make_unique<nidevice_grpc::DeviceEnumerator>(syscfg_library_.get());
    service_ = std::make_unique<nidevice_grpc::SessionUtilitiesService>(session_repository_.get(), device_enumerator_.get());
    builder.RegisterService(service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~SessionUtilitiesServiceTests() {}

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    stub_ = nidevice_grpc::SessionUtilities::NewStub(channel_);
  }

  std::unique_ptr<nidevice_grpc::SessionUtilities::Stub>& GetStub()
  {
    return stub_;
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::SessionUtilities::Stub> stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<nidevice_grpc::SysCfgLibrary> syscfg_library_;
  std::unique_ptr<nidevice_grpc::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<nidevice_grpc::SessionUtilitiesService> service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_EnumerateDevices_ResponseContainsAtLeastOneDevice)
{
  nidevice_grpc::EnumerateDevicesRequest request;
  nidevice_grpc::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_GE(response.devices_size(), 1);
}

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_EnumerateDevices_DevicePropertiesIncludesNameModelVendorSerialNumber)
{
  nidevice_grpc::EnumerateDevicesRequest request;
  nidevice_grpc::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  for (auto device : response.devices()) {
    EXPECT_THAT(device.name(), Not(IsEmpty()));
    EXPECT_NE(device.model().c_str(), nullptr);
    EXPECT_THAT(device.vendor(), Not(IsEmpty()));
    EXPECT_NE(device.serial_number().c_str(), nullptr);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
