#include <gtest/gtest.h>

#include "nidmm/nidmm_library.h"
#include "nidmm/nidmm_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dmm = nidmm_grpc;

const int kDMMDriverApiSuccess = 0;

class NiDMMDriverApiTest : public ::testing::Test {
    protected:
        NiDMMDriverApiTest()
        {
            ::grpc::ServerBuilder builder;
            session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
            nidmm_library_ = std::make_unique<dmm::NiDMMLibrary>();
            nidmm_service_ = std::make_unique<dmm::NiDMMService>(nidmm_library_.get(), session_repository_.get());
            builder.RegisterService(nidmm_service_.get());

            server_ = builder.BuildAndStart();
            ResetStub();
        }

        virtual ~NiDMMDriverApiTest() {}

        void SetUp() override
        {
            initialize_driver_session();
        }

        void TearDown() override
        {
            close_driver_session();
        }

        void ResetStub()
        {
            channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
            nidmm_stub_ = dmm::NiDMM::NewStub(channel_);
        }

        std::unique_ptr<dmm::NiDMM::Stub>& GetStub()
        {
            return nidmm_stub_;
        }

        int GetSessionId()
        {
            return driver_session_->id();
        }

        void initialize_driver_session()
        {
            ::grpc::ClientContext context;
            dmm::InitWithOptionsRequest request;
            request.set_resource_name("FakeDevice");
            request.set_option_string("Simulate=1, DriverSetup=Model:4065; BoardType:PCI");
            request.set_session_name("");
            request.set_reset_device(false);
            request.set_id_query(false);
            dmm::InitWithOptionsResponse response;

            ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
            driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

            ASSERT_TRUE(status.ok());
            ASSERT_EQ(kDMMDriverApiSuccess, response.status());
        }

        void close_driver_session()
        {
            ::grpc::ClientContext context;
            dmm::CloseRequest request;
            request.mutable_vi()->set_id(driver_session_->id());
            dmm::CloseResponse response;

            ::grpc::Status status = GetStub()->Close(&context, request, &response);

            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
        }

        void initiate_acquisition()
        {
            ::grpc::ClientContext context;
            dmm::InitiateRequest request;
            request.mutable_vi()->set_id(GetSessionId());
            dmm::InitiateResponse response;
            auto status = GetStub()->Initiate(&context, request, &response);
            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
        }

        void expect_api_success(int error_status)
        {
            EXPECT_EQ(kDMMDriverApiSuccess, error_status) << get_error_message(error_status);
        }

        std::string get_error_message(int error_status)
        {
            ::grpc::ClientContext context;
            dmm::GetErrorMessageRequest request;
            request.mutable_vi()->set_id(GetSessionId());
            request.set_error_code(error_status);
            dmm::GetErrorMessageResponse response;

            ::grpc::Status status = GetStub()->GetErrorMessage(&context, request, &response);
            EXPECT_TRUE(status.ok());
            EXPECT_EQ(kDMMDriverApiSuccess, response.status());
            return response.error_message();
        }

        ViBoolean get_bool_attribute(const char* channel_name, dmm::NiDMMAttributes attribute_id)
        {
            ::grpc::ClientContext context;
            dmm::GetAttributeViBooleanRequest request;
            request.mutable_vi()->set_id(GetSessionId());
            request.set_channel_name(channel_name);
            request.set_attribute_id(attribute_id);
            dmm::GetAttributeViBooleanResponse response;
            ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);
            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
            return response.attribute_value();
        }

        ViInt32 get_int32_attribute(const char* channel_name, dmm::NiDMMAttributes attribute_id)
        {
            ::grpc::ClientContext context;
            dmm::GetAttributeViInt32Request request;
            request.mutable_vi()->set_id(GetSessionId());
            request.set_channel_name(channel_name);
            request.set_attribute_id(attribute_id);
            dmm::GetAttributeViInt32Response response;
            ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);
            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
            return response.attribute_value();
        }

        ViReal64 get_real64_attribute(const char* channel_name, dmm::NiDMMAttributes attribute_id)
        {
            ::grpc::ClientContext context;
            dmm::GetAttributeViReal64Request request;
            request.mutable_vi()->set_id(GetSessionId());
            request.set_channel_name(channel_name);
            request.set_attribute_id(attribute_id);
            dmm::GetAttributeViReal64Response response;
            ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);
            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
            return response.attribute_value();
        }

        std::string get_string_attribute(const char* channel_name, dmm::NiDMMAttributes attribute_id)
        {
            ::grpc::ClientContext context;
            dmm::GetAttributeViStringRequest request;
            request.mutable_vi()->set_id(GetSessionId());
            request.set_channel_name(channel_name);
            request.set_attribute_id(attribute_id);
            dmm::GetAttributeViStringResponse response;
            ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);
            EXPECT_TRUE(status.ok());
            expect_api_success(response.status());
            return response.attribute_value();
        }

    private:
        std::shared_ptr<::grpc::Channel> channel_;
        std::unique_ptr<::nidevice_grpc::Session> driver_session_;
        std::unique_ptr<dmm::NiDMM::Stub> nidmm_stub_;
        std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
        std::unique_ptr<dmm::NiDMMLibrary> nidmm_library_;
        std::unique_ptr<dmm::NiDMMService> nidmm_service_;
        std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDMMDriverApiTest, NiDMMSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dmm::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiDMMDriverApiTest, NiDMMReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dmm::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDMMDriverApiTest, NiDMMSetViReal64Attribute_SendRequest_GetViReal64AttributeMatches)
{
  const char* channel_name = "";
  const dmm::NiDMMAttributes attribute_to_set = dmm::NiDMMAttributes::NIDMM_ATTRIBUTE_TRIGGER_DELAY;
  const ViReal64 expected_value = 42.24;
  ::grpc::ClientContext context;
  dmm::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  dmm::SetAttributeViReal64Response response;

  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);
  
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  ViReal64 get_attribute_value = get_real64_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDMMDriverApiTest, NiDMMSetViStringAttribute_SendRequest_GetViStringAttributeMatches)
{
  const char* channel_name = "";
  const dmm::NiDMMAttributes attribute_to_set = dmm::NiDMMAttributes::NIDMM_ATTRIBUTE_DRIVER_SETUP;
  const ViString expected_value = "Simulate=1, DriverSetup=Model:4065; BoardType:PCI";
  ::grpc::ClientContext context;
  dmm::SetAttributeViStringRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  dmm::SetAttributeViStringResponse response;

  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);
  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}



}
}
}

