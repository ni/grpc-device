#include "device_server.h"
#include "nirfmxwlan/nirfmxwlan_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxwlan = nirfmxwlan_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxWLANSession = -380598;
const char* kRFmxWLANTestRsrc = "FakeDevice";
const char* kRFmxWLANOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxWLANTestSession = "SessionName";
const char* kRFmxWLANTestSessionTwo = "SessionTwoName";
const char* kRFmxWLANTestInvalidRsrc = "";

class NiRFmxWLANSessionTest : public ::testing::Test {
 protected:
  NiRFmxWLANSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxwlan_stub_(rfmxwlan::NiRFmxWLAN::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxWLANSessionTest() {}

  std::unique_ptr<rfmxwlan::NiRFmxWLAN::Stub>& GetStub()
  {
    return nirfmxwlan_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxwlan::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxwlan::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, bool force_destroy, rfmxwlan::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxwlan::CloseRequest request;
    request.mutable_instrument()->set_name(session.name());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxwlan::NiRFmxWLAN::Stub> nirfmxwlan_stub_;
};

TEST_F(NiRFmxWLANSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxwlan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxWLANSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxwlan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxWLANSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  EXPECT_THROW_DRIVER_ERROR({
    rfmxwlan::InitializeResponse response;
    call_initialize(kRFmxWLANTestInvalidRsrc, "", "", &response);
  }, kInvalidRsrc);
}

TEST_F(NiRFmxWLANSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxwlan::InitializeResponse init_response;
  call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxwlan::CloseRequest close_request;
  close_request.mutable_instrument()->set_name(session.name());
  close_request.set_force_destroy(false);
  rfmxwlan::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxWLANSessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxwlan::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxwlan::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxWLANSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR({
    rfmxwlan::CloseResponse response;
    call_close(session, false, &response);
  }, kInvalidRFmxWLANSession);
}

TEST_F(NiRFmxWLANSessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxwlan::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxwlan::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());

  EXPECT_THROW_DRIVER_ERROR({
    // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
    // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
    call_close(session_two, false, &close_response_two);
  }, kInvalidRFmxWLANSession);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
