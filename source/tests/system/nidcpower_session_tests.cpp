#include <gtest/gtest.h>

#include "nidcpower/nidcpower_library.h"
#include "nidcpower/nidcpower_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dcpower = nidcpower_grpc;

const int kInvalidRsrc = -1074118656;
const char* kViErrorResourceNotFoundMessage = "Device was not recognized.  The device is not supported with this driver or version.";
const char* kTestRsrc = "FakeDevice";
const char* kOptionsString = "Simulate=1, DriverSetup=Model:4147; BoardType:PXIe";
const char* kTestSession = "SessionName";
const char* kTestInvalidRsrc = "";

class NiDCPowerSessionTest : public ::testing::Test {
 protected:
  NiDCPowerSessionTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    nidcpower_library_ = std::make_unique<dcpower::NiDCPowerLibrary>();
    nidcpower_service_ = std::make_unique<dcpower::NiDCPowerService>(nidcpower_library_.get(), session_repository_.get());
    builder.RegisterService(nidcpower_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiDCPowerSessionTest() {}

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    nidcpower_stub_ = dcpower::NiDCPower::NewStub(channel_);
  }

  std::unique_ptr<dcpower::NiDCPower::Stub>& GetStub()
  {
    return nidcpower_stub_;
  }

  ::grpc::Status call_initialize_with_independent_channels(const char* resource_name, const char* option_string, const char* session_name, dcpower::InitializeWithIndependentChannelsResponse* response)
  {
    ::grpc::ClientContext context;
    dcpower::InitializeWithIndependentChannelsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset(false);

    ::grpc::Status status = GetStub()->InitializeWithIndependentChannels(&context, request, response);
    return status;
  }

  ::grpc::Status call_initialize_with_channels(const char* resource_name, const char* option_string, const char* session_name, dcpower::InitializeWithChannelsResponse* response)
  {
    ::grpc::ClientContext context;
    dcpower::InitializeWithChannelsRequest request;
    request.set_resource_name(resource_name);
    request.set_option_string(option_string);
    request.set_session_name(session_name);
    request.set_reset(false);
    request.set_channels("");

    ::grpc::Status status = GetStub()->InitializeWithChannels(&context, request, response);
    return status;
  }

private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<dcpower::NiDCPower::Stub> nidcpower_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<dcpower::NiDCPowerLibrary> nidcpower_library_;
  std::unique_ptr<dcpower::NiDCPowerService> nidcpower_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDCPowerSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse response;
  ::grpc::Status status = call_initialize_with_independent_channels(kTestRsrc, kOptionsString, kTestSession, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDCPowerSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse response;
  ::grpc::Status status = call_initialize_with_independent_channels(kTestRsrc, kOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDCPowerSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  dcpower::InitializeWithChannelsResponse response;
  ::grpc::Status status = call_initialize_with_channels(kTestInvalidRsrc, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidRsrc, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiDCPowerSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse initialize_response;
  call_initialize_with_independent_channels(kTestRsrc, kOptionsString, kTestSession, &initialize_response);
  nidevice_grpc::Session session = initialize_response.vi();

  ::grpc::ClientContext context;
  dcpower::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  dcpower::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDCPowerSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  dcpower::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  dcpower::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiDCPowerSessionTest, ErrorFromDriver_ErrorMessage_ReturnsUserErrorMessage)
{
  dcpower::InitializeWithChannelsResponse initialize_response;
  call_initialize_with_channels(kTestInvalidRsrc, "", "", &initialize_response);
  EXPECT_EQ(kInvalidRsrc, initialize_response.status());

  nidevice_grpc::Session session = initialize_response.vi();
  ::grpc::ClientContext context;
  dcpower::ErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kInvalidRsrc);
  dcpower::ErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorResourceNotFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni