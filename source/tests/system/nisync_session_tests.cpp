#include <gtest/gtest.h>

#include "nisync/nisync_library.h"
#include "nisync/nisync_service.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;

static const int kSyncDeviceNotFound = -1074118634;
static const char* kTestRsrcName = "";
static const char* kInvalidRsrcName = "InvalidName";

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

  ::grpc::Status call_init(const char* resource_name, nisync::InitResponse* response)
  {
    ::grpc::ClientContext context;
    nisync::InitRequest request;
    request.set_resource_name(resource_name);
    request.set_reset_device(false);

    ::grpc::Status status = GetStub()->Init(&context, request, response);
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

TEST_F(NiSyncSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kTestRsrcName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiSyncSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  nisync::InitResponse response;
  ::grpc::Status status = call_init(kInvalidRsrcName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kSyncDeviceNotFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiSyncSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  nisync::InitResponse init_response;
  call_init(kTestRsrcName, &init_response);
  nidevice_grpc::Session session = init_response.vi();
  EXPECT_EQ(0, init_response.status());

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

}  // namespace system
}  // namespace tests
}  // namespace ni