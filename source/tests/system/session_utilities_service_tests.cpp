#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/session_utilities_service.h>

#include "device_server.h"

namespace ni {
namespace tests {
namespace system {

using ::testing::IsEmpty;
using ::testing::Not;

class SessionUtilitiesServiceTests : public ::testing::Test {
 protected:
  SessionUtilitiesServiceTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(nidevice_grpc::SessionUtilities::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~SessionUtilitiesServiceTests() {}

  std::unique_ptr<nidevice_grpc::SessionUtilities::Stub>& GetStub()
  {
    return stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::SessionUtilities::Stub> stub_;
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

TEST_F(SessionUtilitiesServiceTests, SysCfgLibraryPresent_EnumerateDevices_DevicePropertiesIncludesNameModelVendorSerialNumberProductId)
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
    EXPECT_NE(device.product_id(), 0);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
