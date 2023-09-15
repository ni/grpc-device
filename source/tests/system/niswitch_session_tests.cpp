#include <gmock/gmock.h>

#include "device_server.h"
#include "niswitch/niswitch_client.h"
#include "tests/utilities/test_helpers.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = niswitch_grpc;

const int kViErrorRsrcNotFound = -1074118654;
const int kInvalidSwitchSession = -1074130544;
const char* kViErrorRsrcNotFoundMessage = "Invalid resource name.\n\nInvalid Identifier: InvalidName";
const char* kInvalidSwitchSessionMessage = "The session handle is not valid.";
const char* kTestRsrcName = "";
const char* kTestSessName = "SessionName";
const char* kInvalidRsrcName = "InvalidName";
const char* kTopology = "2529/2-Wire Dual 4x16 Matrix";

class NiSwitchSessionTest : public ::testing::Test {
 protected:
  NiSwitchSessionTest()
      : device_server_(DeviceServerInterface::Singleton()),
        niswitch_stub_(niswitch::NiSwitch::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

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
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    return status;
  }

  std::string get_error_message(int error_status)
  {
    niswitch::InitWithTopologyResponse init_response;
    call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &init_response);
    nidevice_grpc::Session session = init_response.vi();

    ::grpc::ClientContext context;
    niswitch::ErrorMessageRequest error_request;
    error_request.mutable_vi()->set_name(session.name());
    error_request.set_error_code(error_status);
    niswitch::ErrorMessageResponse error_response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);
    EXPECT_TRUE(status.ok());
    return error_response.error_message();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
};

TEST_F(NiSwitchSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  niswitch::InitWithTopologyResponse response;
  ::grpc::Status status = call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiSwitchSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  niswitch::InitWithTopologyResponse response;
  ::grpc::Status status = call_init_with_topology(kTestRsrcName, kTopology, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE("", response.vi().name());
  EXPECT_EQ("", response.error_message());
}

TEST_F(NiSwitchSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  niswitch::InitWithTopologyResponse init_response;
  call_init_with_topology(kTestRsrcName, kTopology, kTestSessName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  niswitch::CloseRequest close_request;
  close_request.mutable_vi()->set_name(session.name());
  niswitch::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiSwitchSessionTest, InvalidSession_CloseSession_ReturnsInvalidSessionError)
{
  nidevice_grpc::Session session;
  session.set_name("");

  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    ::grpc::ClientContext context;
    niswitch::CloseRequest request;
    request.mutable_vi()->set_name(session.name());
    niswitch::CloseResponse response;
    auto status = GetStub()->Close(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
  }, kInvalidSwitchSession, kInvalidSwitchSessionMessage);
}

TEST_F(NiSwitchSessionTest, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    niswitch::InitWithTopologyResponse init_response;
    call_init_with_topology(kInvalidRsrcName, "", "", &init_response);
  }, kViErrorRsrcNotFound, kViErrorRsrcNotFoundMessage);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
