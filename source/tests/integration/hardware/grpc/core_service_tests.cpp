#include <gtest/gtest.h>

#include "hardware/grpc/core_service.h"

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
        public:
            virtual ~InProcessServerClientTest() {}

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
                stub_ = ::ni::hardware::grpc::ServerUtilities::NewStub(channel_);
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
            std::unique_ptr<::grpc::Server> server_;
            ni::hardware::grpc::CoreService service_;
    };

    TEST_F(InProcessServerClientTest, CoreServiceClient_RequestIsServerRunning_ResponseIsTrue)
    {
        ::ni::hardware::grpc::IsServerRunningRequest request;
        ::ni::hardware::grpc::IsServerRunningResult response;

        ::grpc::ClientContext context;
        ::grpc::Status s = GetStub()->IsServerRunning(&context, request, &response);

        EXPECT_TRUE(response.status());
        EXPECT_TRUE(s.ok());
    }

} // namespace grpc
} // namespace hardware
} // namespace integration
} // namespace tests
} // namespace ni
