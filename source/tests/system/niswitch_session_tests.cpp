#include <gtest/gtest.h>
#include <server/session_utilities_service.h>

#include "niswitch/niswitch_library.h"
#include "niswitch/niswitch_service.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = grpc::niswitch;

const int kViErrorRsrcNotFound = -1074118654;
const char* kViErrorRsrcNotFoundMessage = "Invalid resource name.";
const char* kTestRsrcName = "FakeDevice";
const char* kTestSessName = "SessionName";
const char* kInvalidRsrcName = "";
const char* kTopology = "2529/2-Wire Dual 4x16 Matrix";

class NiSwitchSessionTest : public ::testing::Test {
 protected:
  NiSwitchSessionTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    niswitch_library_ = std::make_unique<niswitch::NiSwitchLibrary>();
    niswitch_service_ = std::make_unique<niswitch::NiSwitchService>(niswitch_library_.get(), session_repository_.get());
    builder.RegisterService(niswitch_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiSwitchSessionTest() {}

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niswitch_stub_ = niswitch::NiSwitch::NewStub(channel_);
  }

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

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<niswitch::NiSwitchLibrary> niswitch_library_;
  std::unique_ptr<niswitch::NiSwitchService> niswitch_service_;
  std::unique_ptr<::grpc::Server> server_;
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
  grpc::nidevice::Session session = init_response.vi();

  ::grpc::ClientContext context;
  niswitch::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  niswitch::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiSwitchSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  grpc::nidevice::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  niswitch::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  niswitch::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiSwitchSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  niswitch::InitWithTopologyResponse init_response;
  call_init_with_topology(kInvalidRsrcName, "", "", &init_response);
  EXPECT_EQ(kViErrorRsrcNotFound, init_response.status());

  grpc::nidevice::Session session = init_response.vi();
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