#include <gtest/gtest.h>
#include "../source/core_service.h"

class InProcessServerClientTest : public ::testing::Test
{
    protected:
        InProcessServerClientTest() {}

    void SetUp() override 
    {
        ::grpc::ServerBuilder builder;
        builder.RegisterService(&service_);
        server_ = builder.BuildAndStart();
        ResetStub();
    }

    void TearDown() override { server_->Shutdown(); }

    void ResetStub() 
    {
        channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
        stub_ = ::core::CoreService::NewStub(channel_);
    }

    std::shared_ptr<::grpc::Channel> channel_;
    std::unique_ptr<::core::CoreService::Stub> stub_;
    std::unique_ptr<::grpc::Server> server_;
    ::core::Impl::CoreService service_;
};

TEST_F(InProcessServerClientTest, CoreService_RequestIsServerRunning_ResponseIsTrue) 
{
    ::core::IsServerRunningRequest request;
    ::core::IsServerRunningResult response;

    ::grpc::ClientContext context;
    ::grpc::Status s = stub_->IsServerRunning(&context, request, &response);

    EXPECT_TRUE(response.status());
    EXPECT_TRUE(s.ok());
}