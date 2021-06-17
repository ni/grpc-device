#include <gtest/gtest.h>

#include "device_server.h"
#include "nidigitalpattern/nidigitalpattern_service.h"

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
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDigitalSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  digital::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kDigitalResourceName, kDigitalOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDigitalSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  digital::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kDigitalInvalidResourceName, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kDigitalRsrcNotFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiDigitalSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  digital::InitWithOptionsResponse init_response;
  call_init_with_options(kDigitalResourceName, kDigitalOptionsString, kDigitalSessionName, &init_response);
  
  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  digital::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  digital::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDigitalSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  digital::InitWithOptionsResponse init_response;
  call_init_with_options(kDigitalInvalidResourceName, "", "", &init_response);
  EXPECT_EQ(kDigitalRsrcNotFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  digital::ErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kDigitalRsrcNotFound);
  digital::ErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kDigitalRsrcNotFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni