#include "device_server.h"
#include "nirfmxdemod/nirfmxdemod_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxdemod = nirfmxdemod_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxDemodSession = -380598;
const char* kRFmxDemodTestRsrc = "FakeDevice";
const char* kRFmxDemodOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxDemodTestSessionOne = "SessionOneName";
const char* kRFmxDemodTestSessionTwo = "SessionTwoName";
const char* kRFmxDemodTestInvalidRsrc = "";

class NiRFmxDemodSessionTest : public ::testing::Test {
 protected:
  NiRFmxDemodSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxdemod_stub_(rfmxdemod::NiRFmxDemod::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxDemodSessionTest() {}

  std::unique_ptr<rfmxdemod::NiRFmxDemod::Stub>& GetStub()
  {
    return nirfmxdemod_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxdemod::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxdemod::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, bool force_destroy, rfmxdemod::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxdemod::CloseRequest request;
    request.mutable_instrument()->set_name(session.name());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxdemod::NiRFmxDemod::Stub> nirfmxdemod_stub_;
};

TEST_F(NiRFmxDemodSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxdemod::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionOne, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxDemodSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxdemod::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxDemodSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  try {
    rfmxdemod::InitializeResponse response;
    call_initialize(kRFmxDemodTestInvalidRsrc, "", "", &response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, kInvalidRsrc);
  }
}

TEST_F(NiRFmxDemodSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxdemod::InitializeResponse init_response;
  call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionOne, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxdemod::CloseRequest close_request;
  close_request.mutable_instrument()->set_name(session.name());
  close_request.set_force_destroy(false);
  rfmxdemod::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxDemodSessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxdemod::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxdemod::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxDemodSessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxdemod::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxDemodTestRsrc, kRFmxDemodOptionsString, kRFmxDemodTestSessionOne, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxdemod::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());

  try {
    // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
    // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
    call_close(session_two, false, &close_response_two);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, kInvalidRFmxDemodSession);
  }
}

TEST_F(NiRFmxDemodSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  try {
    rfmxdemod::CloseResponse response;
    call_close(session, false, &response);
    FAIL() << "We shouldn't get here.";
  }
  catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
    expect_driver_error(ex, kInvalidRFmxDemodSession);
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
