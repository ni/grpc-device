#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"

namespace ni {
namespace tests {
namespace system {

namespace rfsg = nirfsg_grpc;
using namespace ::nlohmann;

const int kInvalidRsrc = -200220;
const int kInvalidRFSGSession = -1074130544;
const char* kRFSGErrorResourceNotFoundMessage = "Device identifier is invalid.";
const char* kRFSGTestRsrc = "FakeDevice";
const char* kRFSGOptionsString = "Simulate=1, DriverSetup=Model:5652; BoardType:PXI";
const char* kRFSGTestSession = "SessionName";
const char* kRFSGTestInvalidRsrc = "";

class NiRFSGSessionTest : public ::testing::Test {
 protected:
  NiRFSGSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfsg_stub_(rfsg::NiRFSG::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFSGSessionTest() {}

  std::unique_ptr<rfsg::NiRFSG::Stub>& GetStub()
  {
    return nirfsg_stub_;
  }

  ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, rfsg::InitWithOptionsResponse* response)
  {
    ::grpc::ClientContext context;
    rfsg::InitWithOptionsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_id_query(false);

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
    return status;
  }

  void expect_error_string(nidevice_grpc::Session& session, google::protobuf::int32 error_code, const char* expected_error_string)
  {
    ::grpc::ClientContext context;
    rfsg::GetErrorRequest error_request;
    error_request.mutable_vi()->set_id(session.id());
    rfsg::GetErrorResponse error_response;
    ::grpc::Status status = GetStub()->GetError(&context, error_request, &error_response);
    EXPECT_TRUE(status.ok());
    EXPECT_STREQ(expected_error_string, error_response.error_description().c_str());
    EXPECT_EQ(error_code, error_response.error_code());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<rfsg::NiRFSG::Stub> nirfsg_stub_;
};

TEST_F(NiRFSGSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  rfsg::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kRFSGTestRsrc, kRFSGOptionsString, kRFSGTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiRFSGSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  rfsg::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kRFSGTestRsrc, kRFSGOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiRFSGSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  rfsg::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kRFSGTestInvalidRsrc, "", "", &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRsrc, error.value("code", 0));
  EXPECT_NE("", error.value("message", ""));
}

TEST_F(NiRFSGSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  rfsg::InitWithOptionsResponse init_response;
  call_init_with_options(kRFSGTestRsrc, kRFSGOptionsString, kRFSGTestSession, &init_response);

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  rfsg::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  rfsg::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiRFSGSessionTest, InitWithErrorFromDriver_ReturnsUserErrorMessage)
{
  rfsg::InitWithOptionsResponse init_response;
  auto status = call_init_with_options(kRFSGTestInvalidRsrc, "", "", &init_response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRsrc, error.value("code", 0));
  EXPECT_STREQ(kRFSGErrorResourceNotFoundMessage, error.value("message", "").c_str());
}

TEST_F(NiRFSGSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  rfsg::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  rfsg::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRFSGSession, error.value("code", 0));
}

}  // namespace system
}  // namespace tests
}  // namespace ni
