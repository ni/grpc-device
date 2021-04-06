#include <gtest/gtest.h>

#include "nisync/nisync_library.h"
#include "nisync/nisync_service.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;

const int kViErrorRsrcNotFound = -1074118654;
const char* kViErrorRsrcNotFoundMessage = "Invalid resource name.";
const char* kTestRsrcName = "";
const char* kTestSessName = "SessionName";
const char* kInvalidRsrcName = "InvalidName";
const char* kTopology = "2529/2-Wire Dual 4x16 Matrix";

class NiSyncSessionTest : public ::testing::Test {
 protected:
  NiSyncSessionTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    nisync_library_ = std::make_unique<nisync::NiSyncLibrary>();
    nisync_service_ = std::make_unique<nisync::NiSyncService>(nisync_library_.get(), session_repository_.get());
    builder.RegisterService(nisync_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiSyncSessionTest() {}

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    nisync_stub_ = nisync::NiSync::NewStub(channel_);
  }

  std::unique_ptr<nisync::NiSync::Stub>& GetStub()
  {
    return nisync_stub_;
  }

  ::grpc::Status call_init(const char* resource_name, const char* session_name, nisync::InitResponse* response)
  {
    ::grpc::ClientContext context;
    nisync::InitRequest request;
    request.set_resource_name(resource_name);
    request.set_session_name(session_name);
    request.set_reset_device(false);
    request.set_simulate(true);

    ::grpc::Status status = GetStub()->InitWithTopology(&context, request, response);
    return status;
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<nisync::NiSync::Stub> nisync_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<nisync::NiSyncLibrary> nisync_library_;
  std::unique_ptr<nisync::NiSyncService> nisync_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiSyncSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kTestRsrcName, kTestSessName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiSyncSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kTestRsrcName, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiSyncSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kInvalidRsrcName, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorRsrcNotFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiSyncSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  nisync::InitResponse init_response;
  call_init(kTestRsrcName, kTestSessName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  nisync::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  nisync::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiSyncSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  nisync::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  nisync::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiSyncSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  nisync::InitResponse init_response;
  call_init(kInvalidRsrcName, "", &init_response);
  EXPECT_EQ(kViErrorRsrcNotFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  nisync::ErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorRsrcNotFound);
  nisync::ErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->ErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorRsrcNotFoundMessage, error_response.error_message().c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni