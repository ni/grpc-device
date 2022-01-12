#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxwlan/nirfmxwlan_service.h"

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
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxWLANSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxwlan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.instrument().id());
}

TEST_F(NiRFmxWLANSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  rfmxwlan::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxWLANTestInvalidRsrc, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRsrc, response.status());
  EXPECT_EQ(0, response.instrument().id());
}

TEST_F(NiRFmxWLANSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxwlan::InitializeResponse init_response;
  call_initialize(kRFmxWLANTestRsrc, kRFmxWLANOptionsString, kRFmxWLANTestSession, &init_response);

  nidevice_grpc::Session session = init_response.instrument();
  ::grpc::ClientContext context;
  rfmxwlan::CloseRequest close_request;
  close_request.mutable_instrument()->set_id(session.id());
  close_request.set_force_destroy(nirfmxwlan_grpc::Boolean::BOOLEAN_FALSE);
  rfmxwlan::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxWLANSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  rfmxwlan::CloseRequest request;
  request.mutable_instrument()->set_id(session.id());
  request.set_force_destroy(nirfmxwlan_grpc::Boolean::BOOLEAN_FALSE);
  rfmxwlan::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRFmxWLANSession, response.status());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni