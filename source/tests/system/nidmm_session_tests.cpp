#include <gtest/gtest.h>

#include "nidmm/nidmm_library.h"
#include "nidmm/nidmm_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dmm = nidmm_grpc;

const int kViErrorRsrcNFound = -1073807343;
const char* kViErrorRsrcNFoundMessage = "VISA:  (Hex 0xBFFF0011) Insufficient location information or the device or resource is not present in the system.";
const char* kTestResourceName = "FakeDevice";
const char* kSimulatedOptionsString = "Simulate=1, DriverSetup=Model:4065; BoardType:PCI";
const char* kTestSessionName = "SessionName";
const char* kInvalidResourceName = "";

class NiDMMSessionTest : public ::testing::Test{
    protected:
        NiDMMSessionTest()
        {
            ::grpc::ServerBuilder builder;
            session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
            nidmm_library_ = std::make_unique<dmm::NiDMMLibrary>();
            nidmm_service_ = std::make_unique<dmm::NiDMMService>(nidmm_library_.get(), session_repository_.get());
            builder.RegisterService(nidmm_service_.get());

            server_ = builder.BuildAndStart();
            ResetStubs();
        }

        virtual ~NiDMMSessionTest();

        void ResetStubs()
        {
            channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
            nidmm_stub_ = dmm::NiDMM::NewStub(channel_);
        }

        std::unique_ptr<dmm::NiDMM::Stub>& GetStub()
        {
            return nidmm_stub_;
        }

        ::grpc::Status call_init_with_options(const char* resource_name, const char* option_string, const char* session_name, dmm::InitWithOptionsResponse* response)
        {
            ::grpc::ClientContext context;
            dmm::InitWithOptionsRequest request;
            request.set_resource_name(resource_name);
            request.set_option_string(option_string);
            request.set_session_name(session_name);
            request.set_reset_device(false);
            request.set_id_query(false);

            ::grpc::Status status = GetStub()->InitWithOptions(&context, request, response);
            return status;
        }

    private:
        std::shared_ptr<::grpc::Channel> channel_;
        std::unique_ptr<dmm::NiDMM::Stub> nidmm_stub_;
        std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
        std::unique_ptr<dmm::NiDMMLibrary> nidmm_library_;
        std::unique_ptr<dmm::NiDMMService> nidmm_service_;
        std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDMMSessionTest, InitializeSessionWithDeviceAndSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDMMSessionTest, InitializeSessionWithDeviceAndNoSessionName_CreatesDriverSession)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kTestResourceName, kSimulatedOptionsString, "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

TEST_F(NiDMMSessionTest, InitializeSessionWithoutDevice_ReturnsDriverError)
{
  dmm::InitWithOptionsResponse response;
  ::grpc::Status status = call_init_with_options(kInvalidResourceName, "", "", &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kViErrorRsrcNFound, response.status());
  EXPECT_EQ(0, response.vi().id());
}

TEST_F(NiDMMSessionTest, InitializedSession_CloseSession_ClosesDriverSession)
{
  dmm::InitWithOptionsResponse init_response;
  call_init_with_options(kTestResourceName, kSimulatedOptionsString, kTestSessionName, &init_response);
  nidevice_grpc::Session session = init_response.vi();

  ::grpc::ClientContext context;
  dmm::CloseRequest close_request;
  close_request.mutable_vi()->set_id(session.id());
  dmm::CloseResponse close_response;
  ::grpc::Status status = GetStub()->Close(&context, close_request, &close_response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, close_response.status());
}

TEST_F(NiDMMSessionTest, InvalidSession_CloseSession_NoErrorReported)
{
  nidevice_grpc::Session session;
  session.set_id(NULL);

  ::grpc::ClientContext context;
  dmm::CloseRequest request;
  request.mutable_vi()->set_id(session.id());
  dmm::CloseResponse response;
  ::grpc::Status status = GetStub()->Close(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(0, response.status());
}

TEST_F(NiDMMSessionTest, ErrorFromDriver_GetErrorMessage_ReturnsUserErrorMessage)
{
  dmm::InitWithOptionsResponse init_response;
  call_init_with_options(kInvalidResourceName, "", "", &init_response);
  EXPECT_EQ(kViErrorRsrcNFound, init_response.status());

  nidevice_grpc::Session session = init_response.vi();
  ::grpc::ClientContext context;
  dmm::GetErrorMessageRequest error_request;
  error_request.mutable_vi()->set_id(session.id());
  error_request.set_error_code(kViErrorRsrcNFound);
  dmm::GetErrorMessageResponse error_response;
  ::grpc::Status status = GetStub()->GetErrorMessage(&context, error_request, &error_response);

  EXPECT_TRUE(status.ok());
  EXPECT_STREQ(kViErrorRsrcNFoundMessage, error_response.error_message().c_str());
}

} // namespace system
} // namespace tests 
} // namespace ni