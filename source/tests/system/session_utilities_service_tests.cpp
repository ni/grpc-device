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
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    syscfg_library_ = std::make_unique<grpc::nidevice::SysCfgLibrary>();
    device_enumerator_ = std::make_unique<grpc::nidevice::DeviceEnumerator>(syscfg_library_.get());
    service_ = std::make_unique<grpc::nidevice::SessionUtilitiesService>(session_repository_.get(), device_enumerator_.get());
    builder.RegisterService(service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~SessionUtilitiesServiceTests() {}

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    stub_ = grpc::nidevice::SessionUtilities::NewStub(channel_);
  }

  std::unique_ptr<grpc::nidevice::SessionUtilities::Stub>& GetStub()
  {
    return stub_;
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::grpc::nidevice::SessionUtilities::Stub> stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<grpc::nidevice::SysCfgLibrary> syscfg_library_;
  std::unique_ptr<grpc::nidevice::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<grpc::nidevice::SessionUtilitiesService> service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_EnumerateDevices_ResponseContainsAtLeastOneDevice)
{
  grpc::nidevice::EnumerateDevicesRequest request;
  grpc::nidevice::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_GE(response.devices_size(), 1);
}

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_EnumerateDevices_DevicePropertiesIncludesNameModelVendorSerialNumber)
{
  grpc::nidevice::EnumerateDevicesRequest request;
  grpc::nidevice::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  for (auto device : response.devices()) {
    EXPECT_THAT(device.name(), Not(IsEmpty()));
    EXPECT_NE(device.model().c_str(), nullptr);
    EXPECT_NE(device.vendor().c_str(), nullptr);
    EXPECT_NE(device.serial_number().c_str(), nullptr);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
