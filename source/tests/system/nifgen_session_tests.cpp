#include <gmock/gmock.h>

#include "device_server.h"
#include "nifgen/nifgen_client.h"
#include "tests/utilities/test_helpers.h"

using namespace ::testing;

namespace ni {
namespace tests {
namespace system {

namespace fgen = nifgen_grpc;

const int kInvalidFgenRsrc = -1074134944;
const int kInvalidFgenSession = -1074130544;
const char* kViErrorFgenResourceNotFoundMessage = "Insufficient location information or resource not present in the system.\n\nInvalid Identifier: ";
const char* kInvalidFgenSessionMessage = "The session handle is not valid.";
const char* kTestFgenRsrc = "FakeDevice";
const char* kFgenOptionsString = "Simulate=1, DriverSetup=Model:5421; BoardType:PXI";
const char* kFgenTestSession = "SessionName";
const char* kTestInvalidFgenRsrc = "";

class NiFgenSessionTest : public ::testing::Test {
 protected:
  NiFgenSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nifgen_stub_(fgen::NiFgen::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiFgenSessionTest() {}

  std::unique_ptr<fgen::NiFgen::Stub>& GetStub()
  {
    return nifgen_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, fgen::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    fgen::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  std::string get_error_message(int error_status)
  {
    fgen::InitWithOptionsResponse init_response;
    call_init_with_options(kTestFgenRsrc, kFgenOptionsString, kFgenTestSession, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    fgen::ErrorMessageRequest request;
    request.mutable_vi()->set_name(session.name());
    request.set_error_code(error_status);
    fgen::ErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<fgen::NiFgen::Stub> nifgen_stub_;
};

TEST_F(NiFgenSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  fgen::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestFgenRsrc, kFgenOptionsString, kFgenTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiFgenSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  fgen::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestFgenRsrc, kFgenOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiFgenSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  fgen::InitWithOptionsResponse initialize_response;
  call_init_with_options(kTestFgenRsrc, kFgenOptionsString, kFgenTestSession, &initialize_response);
  nidevice_grpc::Session session = initialize_response.vi();

  ::grpc::ClientContext context;
  fgen::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  fgen::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiFgenSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    ::grpc::ClientContext context;
    fgen::CloseRequest request;
    request.mutable_vi()->set_name(session.name());
    fgen::CloseResponse response;
    auto status = GetStub()->Close(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
  }, kInvalidFgenSession, kInvalidFgenSessionMessage);
}

TEST_F(NiFgenSessionTest, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    fgen::InitWithOptionsResponse initialize_response;
    call_init_with_options(kTestInvalidFgenRsrc, "", "", &initialize_response);
  }, kInvalidFgenRsrc, kViErrorFgenResourceNotFoundMessage);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
