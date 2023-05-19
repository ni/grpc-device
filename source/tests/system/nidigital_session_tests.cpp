#include "device_server.h"
#include "nidigitalpattern/nidigitalpattern_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {

namespace digital = nidigitalpattern_grpc;

const int kDigitalRsrcNotFound = -1074098043;
const char* kDigitalRsrcNotFoundMessage = "Specified string is not valid, because it is empty.";
const char* kDigitalResourceName = "FakeDevice";
const char* kDigitalOptionsString = "Simulate=1, DriverSetup=Model:6570; BoardType:PXIe";
const char* kDigitalSessionName = "SessionName";
const char* kDigitalInvalidResourceName = "";

class NiDigitalSessionTest : public ::testing::Test {
 protected:
  NiDigitalSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nidigital_stub_(digital::NiDigital::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiDigitalSessionTest() {}

  void SetUp() override
  {
#ifndef WIN32
    GTEST_SKIP() << "Digital pattern is not supported on Linux.";
#endif
  }

  std::unique_ptr<digital::NiDigital::Stub>& GetStub()
  {
    return nidigital_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, digital::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    digital::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<digital::NiDigital::Stub> nidigital_stub_;
};

TEST_F(NiDigitalSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  digital::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kDigitalResourceName, kDigitalOptionsString, kDigitalSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDigitalSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  digital::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kDigitalResourceName, kDigitalOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDigitalSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  digital::InitWithOptionsResponse init_response;
  call_init_with_options(kDigitalResourceName, kDigitalOptionsString, kDigitalSessionName, &init_response);

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  digital::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  digital::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDigitalSessionTest, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    digital::InitWithOptionsResponse init_response;
    auto status = call_init_with_options(kDigitalInvalidResourceName, "", "", &init_response);
  }, kDigitalRsrcNotFound, kDigitalRsrcNotFoundMessage);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
