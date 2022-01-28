#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxbt/nirfmxbt_service.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxbt = nirfmxbt_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxBTSession = -380598;
const char* kRFmxBTTestRsrc = "FakeDevice";
const char* kRFmxBTOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxBTTestSessionOne = "SessionOneName";
const char* kRFmxBTTestSessionTwo = "SessionTwoName";
const char* kRFmxBTTestInvalidRsrc = "";

class NiRFmxBTSessionTest : public ::testing::Test {
 protected:
  NiRFmxBTSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxbt_stub_(rfmxbt::NiRFmxBT::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxBTSessionTest() {}

  std::unique_ptr<rfmxbt::NiRFmxBT::Stub>& GetStub()
  {
    return nirfmxbt_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxbt::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxbt::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, nirfmxbt_grpc::Boolean force_destroy, rfmxbt::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxbt::CloseRequest request;
    request.mutable_instrument()->set_id(session.id());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxbt::NiRFmxBT::Stub> nirfmxbt_stub_;
};

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionOne, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestInvalidRsrc, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRsrc, response.status());
  EXPECT_EQ(0, response.instrument().id());
}

TEST_F(NiRFmxBTSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxbt::InitializeResponse init_response;
  call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionOne, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxbt::CloseRequest close_request;
  close_request.mutable_instrument()->set_id(session.id());
  close_request.set_force_destroy(nirfmxbt_grpc::Boolean::BOOLEAN_FALSE);
  rfmxbt::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxBTSessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxbt::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().id(), init_response_two.instrument().id());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxbt::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, nirfmxbt_grpc::Boolean::BOOLEAN_FALSE, &close_response_one);
  status_two = call_close(session_two, nirfmxbt_grpc::Boolean::BOOLEAN_FALSE, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxBTSessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxbt::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSessionOne, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().id(), init_response_two.instrument().id());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxbt::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, nirfmxbt_grpc::Boolean::BOOLEAN_FALSE, &close_response_one);
  status_two = call_close(session_two, nirfmxbt_grpc::Boolean::BOOLEAN_FALSE, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
  // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
  EXPECT_EQ(kInvalidRFmxBTSession, close_response_two.status());
}

TEST_F(NiRFmxBTSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  rfmxbt::CloseRequest request;
  request.mutable_instrument()->set_id(session.id());
  request.set_force_destroy(nirfmxbt_grpc::Boolean::BOOLEAN_FALSE);
  rfmxbt::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRFmxBTSession, response.status());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
