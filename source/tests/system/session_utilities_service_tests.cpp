#include <gtest/gtest.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>

#include <thread>

namespace ni {
namespace tests {
namespace system {

namespace internal = ni::hardware::grpc::internal;

class SessionUtilitiesServiceTests : public ::testing::Test {
 protected:
  SessionUtilitiesServiceTests()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<internal::SessionRepository>();
    syscfg_library_ = std::make_unique<internal::SysCfgLibrary>();
    device_enumerator_ = std::make_unique<internal::DeviceEnumerator>(syscfg_library_.get());
    service_ = std::make_unique<ni::hardware::grpc::SessionUtilitiesService>(session_repository_.get(), device_enumerator_.get());
    builder.RegisterService(service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~SessionUtilitiesServiceTests() {}

  void ResetStub()
  {
      channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
      stub_ = ni::hardware::grpc::SessionUtilities::NewStub(channel_);
  }

  std::unique_ptr<ni::hardware::grpc::SessionUtilities::Stub>& GetStub()
  {
      return stub_;
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::ni::hardware::grpc::SessionUtilities::Stub> stub_;
  std::unique_ptr<internal::SessionRepository> session_repository_;
  std::unique_ptr<internal::SysCfgLibrary> syscfg_library_;
  std::unique_ptr<internal::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<ni::hardware::grpc::SessionUtilitiesService> service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_ClientCallsEnumerateDevices_ResponseContainsAtLeastOneDevice)
{
  ni::hardware::grpc::EnumerateDevicesRequest request;
  ni::hardware::grpc::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_GE(response.devices_size(), 1);
}

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_ClientCallsEnumerateDevices_DevicePropertiesIncludesNameModelVendorSerialNumber)
{
  ni::hardware::grpc::EnumerateDevicesRequest request;
  ni::hardware::grpc::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  for (auto it : response.devices()) {
    EXPECT_NE(it.name(), "");
    EXPECT_NE(it.model().c_str(), nullptr);
    EXPECT_NE(it.vendor().c_str(), nullptr);
    EXPECT_NE(it.serial_number().c_str(), nullptr);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
