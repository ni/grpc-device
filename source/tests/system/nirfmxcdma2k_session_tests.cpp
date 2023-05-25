#include "device_server.h"
#include "nirfmxcdma2k/nirfmxcdma2k_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxcdma2k = nirfmxcdma2k_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxCDMA2kSession = -380598;
const char* kRFmxCDMA2kTestRsrc = "FakeDevice";
const char* kRFmxCDMA2kOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxCDMA2kTestSessionOne = "SessionOneName";
const char* kRFmxCDMA2kTestSessionTwo = "SessionTwoName";
const char* kRFmxCDMA2kTestInvalidRsrc = "";

class NiRFmxCDMA2kSessionTest : public ::testing::Test {
 protected:
  NiRFmxCDMA2kSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxcdma2k_stub_(rfmxcdma2k::NiRFmxCDMA2k::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxCDMA2kSessionTest() {}

  std::unique_ptr<rfmxcdma2k::NiRFmxCDMA2k::Stub>& GetStub()
  {
    return nirfmxcdma2k_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxcdma2k::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxcdma2k::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, bool force_destroy, rfmxcdma2k::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxcdma2k::CloseRequest request;
    request.mutable_instrument()->set_name(session.name());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxcdma2k::NiRFmxCDMA2k::Stub> nirfmxcdma2k_stub_;
};

TEST_F(NiRFmxCDMA2kSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxcdma2k::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionOne, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxCDMA2kSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxcdma2k::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxCDMA2kSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  EXPECT_THROW_DRIVER_ERROR({
    rfmxcdma2k::InitializeResponse response;
    call_initialize(kRFmxCDMA2kTestInvalidRsrc, "", "", &response);
  }, kInvalidRsrc);
}

TEST_F(NiRFmxCDMA2kSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxcdma2k::InitializeResponse init_response;
  call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionOne, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxcdma2k::CloseRequest close_request;
  close_request.mutable_instrument()->set_name(session.name());
  close_request.set_force_destroy(false);
  rfmxcdma2k::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxCDMA2kSessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxcdma2k::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxcdma2k::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxCDMA2kSessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxcdma2k::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxCDMA2kTestRsrc, kRFmxCDMA2kOptionsString, kRFmxCDMA2kTestSessionOne, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxcdma2k::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());

  EXPECT_THROW_DRIVER_ERROR({
    // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
    // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
    call_close(session_two, false, &close_response_two);
  }, kInvalidRFmxCDMA2kSession);

}

TEST_F(NiRFmxCDMA2kSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR({
    rfmxcdma2k::CloseResponse response;
    call_close(session, false, &response);
  }, kInvalidRFmxCDMA2kSession);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
