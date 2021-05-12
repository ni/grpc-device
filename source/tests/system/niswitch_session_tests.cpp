#include <gtest/gtest.h>

#include "device_server.h"
#include "niswitch/niswitch_service.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = niswitch_grpc;

const int kViErrorRsrcNotFound = -1074118654;
const int kInvalidSwitchSession = -1074130544;
const char* kViErrorRsrcNotFoundMessage = "Invalid resource name.";
const char* kInvalidSwitchSessionMessage = "The session handle is not valid.";
const char* kTestRsrcName = "";
const char* kTestSessName = "SessionName";
const char* kInvalidRsrcName = "InvalidName";
const char* kTopology = "2529/2-Wire Dual 4x16 Matrix";

class NiSwitchSessionTest : public ::testing::Test {
 protected:
  NiSwitchSessionTest()
      : niswitch_stub_(niswitch::NiSwitch::NewStub(DeviceServerInterface::Singleton()->InProcessChannel()))
  {}

  virtual ~NiSwitchSessionTest() {}

  std::unique_ptr<niswitch::NiSwitch::Stub>& GetStub()
  {
    return niswitch_stub_;
  }

  ::grpc::Status call_init_with_topology(const char* resource_name, const char* topology, const char* session_name, niswitch::InitWithTopologyResponse* response)
  {
    ::grpc::ClientContext context;
    niswitch::InitWithTopologyRequest request;
    request.set_resource_name(resource_name);
    request.set_topology(topology);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_simulate(true);

    ::grpc::Status status = GetStub()->InitWithTopology(&context, request, response);
    return status;
  }

  std::string get_error_message(int error_status)
  {
    niswitch::InitWithTopologyResponse init_response;
    call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    niswitch::ErrorMessageRequest error_request;
    error_request.mutable_vi()->set_id(session.id());
    error_request.set_error_code(error_status);
    niswitch::ErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
};

TEST_F(NiSwitchSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  niswitch::InitWithTopologyResponse response;
  ::grpc::Status status = call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiSwitchSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  niswitch::InitWithTopologyResponse response;
  ::grpc::Status status = call_init_with_topology(kTestRsrcName, kTopology, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiSwitchSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  niswitch::InitWithTopologyResponse response;
  ::grpc::Status status = call_init_with_topology(kInvalidRsrcName, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorRsrcNotFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiSwitchSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  niswitch::InitWithTopologyResponse init_response;
  call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  niswitch::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  niswitch::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiSwitchSessionTest, InvalidSession_CloseSession_ReturnsInvalidSesssionError)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  niswitch::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  niswitch::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kInvalidSwitchSession, response.status());
  std::string error_message = get_error_message(response.status());
  EXPECT_STREQ(kInvalidSwitchSessionMessage, error_message.c_str());
}

TEST_F(NiSwitchSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  niswitch::InitWithTopologyResponse init_response;
  call_init_with_topology(kInvalidRsrcName, "", "", &init_response);
  EXPECT_EQ(kViErrorRsrcNotFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  niswitch::ErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorRsrcNotFound);
  niswitch::ErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorRsrcNotFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni