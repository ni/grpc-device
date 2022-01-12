#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxbt/nirfmxbt_service.h"

namespace ni {
namespace tests {
namespace system {

namespace rfmxbt = nirfmxbt_grpc;

const int kInvalidRsrc = -200220;
const int kInvalidRFmxBTSession = -380598;
const char* kRFmxBTTestRsrc = "FakeDevice";
const char* kRFmxBTOptionsString = "Simulate=1, DriverSetup=Model:5663E";
const char* kRFmxBTTestSession = "SessionName";
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

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfmxbt::NiRFmxBT::Stub> nirfmxbt_stub_;
};

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.handle_out().id());
}

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.handle_out().id());
}

TEST_F(NiRFmxBTSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  rfmxbt::InitializeResponse response;
  ::grpc::Status status = call_initialize(kRFmxBTTestInvalidRsrc, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRsrc, response.status());
  EXPECT_EQ(0, response.handle_out().id());
}

TEST_F(NiRFmxBTSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfmxbt::InitializeResponse init_response;
  call_initialize(kRFmxBTTestRsrc, kRFmxBTOptionsString, kRFmxBTTestSession, &init_response);

  nidevice_grpc::Session session = init_response.handle_out();
  ::grpc::ClientContext context;
  rfmxbt::CloseRequest close_request;
  close_request.mutable_instrument_handle()->set_id(session.id());
  close_request.set_force_destroy(nirfmxbt_grpc::Boolean::BOOLEAN_FALSE);
  rfmxbt::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFmxBTSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  rfmxbt::CloseRequest request;
  request.mutable_instrument_handle()->set_id(session.id());
  request.set_force_destroy(nirfmxbt_grpc::Boolean::BOOLEAN_FALSE);
  rfmxbt::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRFmxBTSession, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni