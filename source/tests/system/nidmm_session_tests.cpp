#include <gmock/gmock.h>

#include "device_server.h"
#include "nidmm/nidmm_client.h"
#include "nidmm/nidmm_library.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {

namespace dmm = nidmm_grpc;
using namespace ::testing;

const int kViErrorDmmRsrcNFound = -1074118656;
const int kInvalidDmmSession = -1074130544;
const char* kViErrorDmmRsrcNFoundMessage = "Device was not recognized. The device is not supported with this driver or version.\n\nInvalid Identifier: ";
const char* kInvalidDmmSessionMessage = "The session handle is not valid.";
const char* kResourceName = "FakeDevice";
const char* kDmmOptionsString = "Simulate=1, DriverSetup=Model:4080; BoardType:PXIe";
const char* kSessionName = "SessionName";
const char* kInvalidRsrc = "";

class NiDmmSessionTest : public ::testing::Test {
 protected:
  NiDmmSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nidmm_stub_(dmm::NiDmm::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiDmmSessionTest() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<dmm::NiDmm::Stub>& GetStub()
  {
    return nidmm_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, dmm::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    dmm::InitWithOptionsRequest request;
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
    dmm::InitWithOptionsResponse init_response;
    call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    dmm::GetErrorMessageRequest error_request;
    error_request.mutable_vi()->set_name(session.name());
    error_request.set_error_code(error_status);
    dmm::GetErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->GetErrorMessage(&context, error_request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<dmm::NiDmm::Stub> nidmm_stub_;
};

TEST_F(NiDmmSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDmmSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kResourceName, kDmmOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDmmSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  dmm::InitWithOptionsResponse init_response;
  call_init_with_options(kResourceName, kDmmOptionsString, kSessionName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  dmm::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  dmm::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDmmSessionTest, InvalidSession_CloseSession_ReturnsInvalidSesssionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    ::grpc::ClientContext context;
    dmm::CloseRequest request;
    request.mutable_vi()->set_name(session.name());
    dmm::CloseResponse response;
    ::grpc::Status status = GetStub()->Close(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
  }, kInvalidDmmSession, kInvalidDmmSessionMessage);
}

TEST_F(NiDmmSessionTest, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    dmm::InitWithOptionsResponse init_response;
    call_init_with_options(kInvalidRsrc, "", "", &init_response);
  }, kViErrorDmmRsrcNFound, kViErrorDmmRsrcNFoundMessage);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
