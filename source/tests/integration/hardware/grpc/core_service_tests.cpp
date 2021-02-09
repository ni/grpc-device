#include <gtest/gtest.h>

#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/semaphore.h"

namespace ni {
namespace tests {
namespace integration {
namespace hardware {
namespace grpc {

class InProcessServerClientTest : public ::testing::Test {
 public:
  virtual ~InProcessServerClientTest() {}

  void SetUp() override
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<ni::hardware::grpc::internal::SessionRepository>();
    service_ = std::make_unique<ni::hardware::grpc::CoreService>(session_repository_.get());
    builder.RegisterService(service_.get());
    server_ = builder.BuildAndStart();
    ResetStub();
  }

  void TearDown() override
  {
    server_->Shutdown();
  }

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    stub_ = ni::hardware::grpc::ServerUtilities::NewStub(channel_);
  }

  std::unique_ptr<ni::hardware::grpc::ServerUtilities::Stub>& GetStub()
  {
    return stub_;
  }

 protected:
  InProcessServerClientTest() {}

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::ni::hardware::grpc::ServerUtilities::Stub> stub_;
  std::unique_ptr<ni::hardware::grpc::internal::SessionRepository> session_repository_;
  std::unique_ptr<ni::hardware::grpc::CoreService> service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(InProcessServerClientTest, CoreServiceClient_RequestIsServerRunning_ResponseIsTrue)
{
  ni::hardware::grpc::IsReservedByClientRequest request;
  ni::hardware::grpc::IsReservedByClientResponse response;

  ::grpc::ClientContext context;
  ::grpc::Status s = GetStub()->IsReservedByClient(&context, request, &response);

  EXPECT_FALSE(response.is_reserved());
  EXPECT_TRUE(s.ok());
}

}  // namespace grpc
}  // namespace hardware
}  // namespace integration
}  // namespace tests
}  // namespace ni
