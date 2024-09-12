#include <gtest/gtest.h>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nifpga/nifpga_client.h"

namespace ni {
namespace tests {
namespace system {

namespace nifpga = nifpga_grpc;

constexpr auto NIFPGA_ERROR_DEVICE_NOT_FOUND_MESSAGE = "Error";
static const char* kTestSessionName = "TestSession";
static const char* kEmptySessionName = "";
static const char* kInvalidRsrcName = "InvalidName";

inline static void EXPECT_FPGA_ERROR(const std::string& error_message, const ::grpc::Status& status)
{
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(error_message, status.error_message());
}

class NiFpgaSessionTest : public ::testing::Test {
 protected:
  std::string test_resource_name;

  NiFpgaSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nifpga_stub_(nifpga::NiFpga::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  void SetUp() override
  {
    for (const auto& device : EnumerateDevices()) {
      if ((device.model() == "NI PXIe-7976R")) {
        test_resource_name = device.name();
        break;
      }
    }

    if (test_resource_name.empty()) {
      GTEST_SKIP() << "No device found";
    }
  }

  virtual ~NiFpgaSessionTest() {}

  std::unique_ptr<nifpga::NiFpga::Stub>& GetStub()
  {
    return nifpga_stub_;
  }

  ::grpc::Status call_open(const char* resource_name, const char* session_name, nifpga::OpenResponse* response)
  {
    ::grpc::ClientContext context;
    nifpga::OpenRequest request;
    request.set_session_name(session_name);
    request.set_bitfile("C:\\DemoExample.lvbitx");
    request.set_signature("9A28199F1CEAD0E4DD35AF2730C072A6");
    request.set_resource(resource_name);
    request.set_attribute_raw(0);

    ::grpc::Status status = GetStub()->Open(&context, request, response);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<nifpga::NiFpga::Stub> nifpga_stub_;
};

TEST_F(NiFpgaSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  nifpga::OpenResponse response;
  ::grpc::Status status = call_open(test_resource_name.c_str(), kTestSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiFpgaSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  nifpga::OpenResponse response;
  ::grpc::Status status = call_open(test_resource_name.c_str(), kEmptySessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiFpgaSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  nifpga::OpenResponse response;
  ::grpc::Status status = call_open(kInvalidRsrcName, kTestSessionName, &response);

  EXPECT_FPGA_ERROR(NIFPGA_ERROR_DEVICE_NOT_FOUND_MESSAGE, status);
}

TEST_F(NiFpgaSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  nifpga::OpenResponse response;
  call_open(test_resource_name.c_str(), kTestSessionName, &response);
  nidevice_grpc::Session session = response.session();
  EXPECT_EQ(0, response.status());

  ::grpc::ClientContext context;
  nifpga::CloseRequest close_request;
  close_request.mutable_session()->set_name(session.name());
  close_request.set_attribute_raw(0);
  nifpga::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
