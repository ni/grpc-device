#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "device_server.h"
#include "nirfmxnr/nirfmxnr_client.h"

namespace ni {
namespace tests {
namespace system {
namespace {

namespace rfmxnr = nirfmxnr_grpc;
using namespace ::nlohmann;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxNRSession = -380598;
const char* kRFmxNRTestRsrc = "FakeDevice";
const char* kRFmxNROptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxNRTestSessionOne = "SessionOne";
const char* kRFmxNRTestSessionTwo = "SessionTwo";
const char* kRFmxNRTestInvalidRsrc = "";

class NiRFmxNRSessionTest : public ::testing::Test {
 protected:
  NiRFmxNRSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxnr_stub_(rfmxnr::NiRFmxNR::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxNRSessionTest() {}

  std::unique_ptr<rfmxnr::NiRFmxNR::Stub>& GetStub()
  {
    return nirfmxnr_stub_;
  }

  ::grpc::Status call_initialize(const char* resource_name, const char* option_string, const char* session_name, rfmxnr::InitializeResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxnr::InitializeRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);

    ::grpc::Status status = GetStub()->Initialize(&context, request, response);
    return status;
  }

  ::grpc::Status call_close(nidevice_grpc::Session session, bool force_destroy, rfmxnr::CloseResponse* response)
  {
    ::grpc::ClientContext context;
    rfmxnr::CloseRequest request;
    request.mutable_instrument()->set_id(session.id());
    request.set_force_destroy(force_destroy);

    ::grpc::Status status = GetStub()->Close(&context, request, response);
    return status;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxnr::NiRFmxNR::Stub> nirfmxnr_stub_;
};

TEST_F(NiRFmxNRSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxnr::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionOne, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxNRSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxnr::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxNRSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  rfmxnr::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxNRTestInvalidRsrc, "", "", &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRsrc, error.value("code", 0));
}

TEST_F(NiRFmxNRSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxnr::InitializeResponse init_response;
  call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionOne, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxnr::CloseRequest close_request;
  close_request.mutable_instrument()->set_id(session.id());
  close_request.set_force_destroy(false);
  rfmxnr::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxNRSessionTest, TwoInitializedSessionsOnSameDevice_CloseSessions_ClosesDriverSessions)
{
  rfmxnr::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionTwo, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_NE(init_response_one.instrument().id(), init_response_two.instrument().id());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxnr::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, close_response_two.status());
}

TEST_F(NiRFmxNRSessionTest, CallInitializeTwiceWithSameSessionNameOnSameDevice_CloseSessionTwice_SecondCloseReturnsInvalidSessionError)
{
  rfmxnr::InitializeResponse init_response_one, init_response_two;
  ::grpc::Status status_one = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionOne, &init_response_one);
  ::grpc::Status status_two = call_initialize(kRFmxNRTestRsrc, kRFmxNROptionsString, kRFmxNRTestSessionOne, &init_response_two);
  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, init_response_one.status());
  EXPECT_TRUE(status_two.ok());
  EXPECT_EQ(0, init_response_two.status());
  EXPECT_EQ(init_response_one.instrument().id(), init_response_two.instrument().id());

  nidevice_grpc::Session session_one = init_response_one.instrument();
  nidevice_grpc::Session session_two = init_response_two.instrument();
  rfmxnr::CloseResponse close_response_one, close_response_two;
  status_one = call_close(session_one, false, &close_response_one);
  status_two = call_close(session_two, false, &close_response_two);

  EXPECT_TRUE(status_one.ok());
  EXPECT_EQ(0, close_response_one.status());
  // Initialize was only called once in the driver since the second init call to the service found the Session by the same name and returned it.
  // Therefore if we try to close the session again the driver will respond that it's not a valid session (it's already been closed).
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status_two.error_code());
  auto error = json::parse(status_two.error_message());
  EXPECT_EQ(kInvalidRFmxNRSession, error.value("code", 0));
}

TEST_F(NiRFmxNRSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  rfmxnr::CloseRequest request;
  request.mutable_instrument()->set_id(session.id());
  request.set_force_destroy(false);
  rfmxnr::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRFmxNRSession, error.value("code", 0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
