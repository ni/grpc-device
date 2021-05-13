#include <gtest/gtest.h>

#include "device_server.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = niscope_grpc;

const int kViErrorRsrcNFound = -1073807343;
const int kInvalidScopeSession = -1074130544;
const char* kViErrorRsrcNFoundMessage = "VISA:  (Hex 0xBFFF0011) Insufficient location information or the device or resource is not present in the system.";
const char* kInvalidScopeSessionMessage = "The session handle is not valid.";
const char* kTestResourceName = "FakeDevice";
const char* kSimulatedOptionsString = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe";
const char* kTestSessionName = "SessionName";
const char* kInvalidResourceName = "";

class NiScopeSessionTest : public ::testing::Test {
 protected:
  NiScopeSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        niscope_stub_(scope::NiScope::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiScopeSessionTest() {}

  std::unique_ptr<scope::NiScope::Stub>& GetStub()
  {
    return niscope_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, scope::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    return status;
  }

  std::string get_error_message(int error_status)
  {
    scope::InitWithOptionsResponse init_response;
    call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    scope::GetErrorMessageRequest request;
    request.mutable_vi()->set_id(session.id());
    request.set_error_code(error_status);
    scope::GetErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->GetErrorMessage(&context, request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
};

TEST_F(NiScopeSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  scope::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiScopeSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  scope::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestResourceName, kSimulatedOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiScopeSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  scope::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kInvalidResourceName, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorRsrcNFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiScopeSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  scope::InitWithOptionsResponse init_response;
  call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  scope::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  scope::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiScopeSessionTest, InvalidSession_CloseSession_ReturnsInvalidSesssionError)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  scope::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  scope::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidScopeSession, response.status());
  std::string error_message = get_error_message(response.status());
  EXPECT_STREQ(kInvalidScopeSessionMessage, error_message.c_str());
}

TEST_F(NiScopeSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  scope::InitWithOptionsResponse init_response;
  call_init_with_options(kInvalidResourceName, "", "", &init_response);
  EXPECT_EQ(kViErrorRsrcNFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  scope::GetErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorRsrcNFound);
  scope::GetErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->GetErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorRsrcNFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni