#include <gtest/gtest.h>
#include "../source/hardware/grpc/core_service.h"

namespace ni
{
namespace tests
{
namespace integration
{
namespace hardware
{
namespace grpc
{
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
            stub_ = ::ni::hardware::grpc::CoreService::NewStub(channel_);
        }

        std::shared_ptr<::grpc::Channel> channel_;
        std::unique_ptr<::ni::hardware::grpc::CoreService::Stub> stub_;
        std::unique_ptr<::grpc::Server> server_;
        ::ni::hardware::grpc::impl::CoreService service_;
    };

    TEST_F(InProcessServerClientTest, CoreServiceClient_RequestIsServerRunning_ResponseIsTrue) 
    {
        ::ni::hardware::grpc::IsServerRunningRequest request;
        ::ni::hardware::grpc::IsServerRunningResult response;

        ::grpc::ClientContext context;
        ::grpc::Status s = stub_->IsServerRunning(&context, request, &response);

        EXPECT_TRUE(response.status());
        EXPECT_TRUE(s.ok());
    } 
}
}
}
}
}
