#include "device_server.h"
#include "nirfmxlte/nirfmxlte_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxlte = nirfmxlte_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxLTESession = -380598;
const char* kRFmxLTETestRsrc = "FakeDevice";
const char* kRFmxLTEOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxLTETestSessionOne = "SessionOneName";
const char* kRFmxLTETestSessionTwo = "SessionTwoName";
const char* kRFmxLTETestInvalidRsrc = "";

class NiRFmxLTESessionTest : public ::testing::Test {
 protected:
  NiRFmxLTESessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxlte_stub_(rfmxlte::NiRFmxLTE::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxLTESessionTest() {}

  std::unique_ptr<rfmxlte::NiRFmxLTE::Stub>& GetStub()
  {
    return nirfmxlte_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxlte::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxlte::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, bool force_destroy, rfmxlte::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxlte::CloseRequest request;
    request.mutable_instrument()->set_name(session.name());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxlte::NiRFmxLTE::Stub> nirfmxlte_stub_;
};

TEST_F(NiRFmxLTESessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxlte::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionOne, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxLTESessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxlte::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.instrument().name());
}

TEST_F(NiRFmxLTESessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  EXPECT_THROW_DRIVER_ERROR({
    rfmxlte::InitializeResponse response;
    call_initialize(kRFmxLTETestInvalidRsrc, "", "", &response);
  }, kInvalidRsrc);
}

TEST_F(NiRFmxLTESessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxlte::InitializeResponse init_response;
  call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionOne, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxlte::CloseRequest close_request;
  close_request.mutable_instrument()->set_name(session.name());
  close_request.set_force_destroy(false);
  rfmxlte::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxLTESessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxlte::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxlte::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxLTESessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxlte::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxLTETestRsrc, kRFmxLTEOptionsString, kRFmxLTETestSessionOne, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().name(), init_response_two.instrument().name());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxlte::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());

  EXPECT_THROW_DRIVER_ERROR({
    // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
    // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
    call_close(session_two, false, &close_response_two);
  }, kInvalidRFmxLTESession);
}

TEST_F(NiRFmxLTESessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR({
    rfmxlte::CloseResponse response;
    call_close(session, false, &response);
  }, kInvalidRFmxLTESession);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
