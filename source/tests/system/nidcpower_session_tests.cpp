#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "device_server.h"
#include "nidcpower/nidcpower_client.h"

namespace ni {
namespace tests {
namespace system {

namespace dcpower = nidcpower_grpc;
using namespace ::nlohmann;
using namespace ::testing;

const int kInvalidRsrc = -1074118656;
const int kInvalidDCPowerSession = -1074130544;
const char* kViErrorResourceNotFoundMessage = "Device was not recognized. The device is not supported with this driver or version.\n\nInvalid Identifier: ";
const char* kInvalidDCPowerSessionMessage = "The session handle is not valid.";
const char* kTestRsrc = "FakeDevice";
const char* kOptionsString = "Simulate=1, DriverSetup=Model:4147; BoardType:PXIe";
const char* kTestSession = "SessionName";
const char* kTestInvalidRsrc = "";

class NiDCPowerSessionTest : public ::testing::Test {
 protected:
  NiDCPowerSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nidcpower_stub_(dcpower::NiDCPower::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiDCPowerSessionTest() {}

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

  std::string get_error_message(int error_status)
  {
    dcpower::InitializeWithIndependentChannelsResponse init_response;
    call_initialize_with_independent_channels(kTestRsrc, kOptionsString, kTestSession, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    dcpower::ErrorMessageRequest request;
    request.mutable_vi()->set_id(session.id());
    request.set_error_code(error_status);
    dcpower::ErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<dcpower::NiDCPower::Stub> nidcpower_stub_;
};

// InitializeWithIndependentChannels was added in dcpower 20.7.
// To support testing with older versions: skip tests for InitializeWithIndependentChannels if
// it returns an unsupported status.
#define GTEST_SKIP_IF_UNSUPPORTED(status) \
  if (status.error_code() == ::grpc::NOT_FOUND) GTEST_SKIP() << "Function not supported.";

TEST_F(NiDCPowerSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse response;
  auto status = call_initialize_with_independent_channels(kTestRsrc, kOptionsString, kTestSession, &response);

  GTEST_SKIP_IF_UNSUPPORTED(status);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDCPowerSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse response;
  ::grpc::Status status = call_initialize_with_independent_channels(kTestRsrc, kOptionsString, "", &response);

  GTEST_SKIP_IF_UNSUPPORTED(status);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiDCPowerSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  dcpower::InitializeWithChannelsResponse response;
  ::grpc::Status status = call_initialize_with_channels(kTestInvalidRsrc, "", "", &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRsrc, error.value("code", 0));
  EXPECT_NE("", error.value("message", ""));
}

TEST_F(NiDCPowerSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  dcpower::InitializeWithIndependentChannelsResponse initialize_response;
  auto status = call_initialize_with_independent_channels(kTestRsrc, kOptionsString, kTestSession, &initialize_response);
  GTEST_SKIP_IF_UNSUPPORTED(status);
  EXPECT_TRUE(status.ok());
  nidevice_grpc::Session session = initialize_response.vi();

  ::grpc::ClientContext context;
  dcpower::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  dcpower::CloseResponse close_response;
  status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDCPowerSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_id(0UL);

  ::grpc::ClientContext context;
  dcpower::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  dcpower::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidDCPowerSession, error.value("code", 0));
  EXPECT_THAT(error.value("message", "").c_str(), HasSubstr(kInvalidDCPowerSessionMessage));
}

TEST_F(NiDCPowerSessionTest, InitWithErrorFromDriver_ReturnsUserErrorMessage)
{
  dcpower::InitializeWithChannelsResponse initialize_response;
  auto status = call_initialize_with_channels(kTestInvalidRsrc, "", "", &initialize_response);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  auto error = json::parse(status.error_message());
  EXPECT_EQ(kInvalidRsrc, error.value("code", 0));
  EXPECT_STREQ(kViErrorResourceNotFoundMessage, error.value("message", "").c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
