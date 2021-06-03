#include <gtest/gtest.h>

#include "nifgen/nifgen_library.h"
#include "nifgen/nifgen_service.h"

namespace ni {
namespace tests {
namespace system {

namespace fgen = nifgen_grpc;

const int kfgenDriverApiSuccess = 0;

class nifgenDriverApiTest : public ::testing::Test {
 protected:
  nifgenDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    nifgen_library_ = std::make_unique<fgen::NiFgenLibrary>();
    nifgen_service_ = std::make_unique<fgen::NiFgenService>(nifgen_library_.get(), session_repository_.get());
    builder.RegisterService(nifgen_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~nifgenDriverApiTest() {}

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
    nifgen_stub_ = fgen::NiFgen::NewStub(channel_);
  }

  std::unique_ptr<fgen::NiFgen::Stub>& GetStub()
  {
    return nifgen_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    fgen::InitializeWithChannelsRequest request;
    request.set_channel_name("");
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5421;BoardType:PXI");
    request.set_reset_device(false);
    fgen::InitializeWithChannelsResponse response;

    ::grpc::Status status = GetStub()->InitializeWithChannels(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kfgenDriverApiSuccess, response.status());
  }

  void initiate()
  {
    fgen::InitiateGenerationRequest request;
    fgen::InitiateGenerationResponse response;
    ::grpc::ClientContext context;
    request.mutable_vi()->set_id(GetSessionId());

    ::grpc::Status status = GetStub()->InitiateGeneration(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    fgen::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    fgen::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
  }

  ViBoolean get_bool_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViInt32 get_int32_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViInt64 get_int64_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViInt64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViReal64 get_real64_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViReal64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViReal64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  std::string get_string_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  void set_int32_attribute(const char* channel_list, fgen::NiFgenAttributes attribute_id, ViInt32 attribute_value)
  {
    ::grpc::ClientContext context;
    fgen::SetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    request.set_attribute_value(attribute_value);
    fgen::SetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

     EXPECT_TRUE(status.ok());
     EXPECT_EQ(kfgenDriverApiSuccess, response.status());
  }

  void configure_trigger_mode(const char* channel_name, fgen::TriggerMode triggerMode)
  {
    ::grpc::ClientContext context;
    fgen::ConfigureTriggerModeRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_trigger_mode(triggerMode);
    fgen::ConfigureTriggerModeResponse response;

    ::grpc::Status status = GetStub()->ConfigureTriggerMode(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
  }

  fgen::ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer()
  {
    ::grpc::ClientContext context;
    fgen::ExportAttributeConfigurationBufferRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    fgen::ExportAttributeConfigurationBufferResponse response;

    ::grpc::Status status = GetStub()->ExportAttributeConfigurationBuffer(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, response.status());
    return response;
  }

  void import_attribute_configuration_buffer(fgen::ExportAttributeConfigurationBufferResponse export_buffer_response)
  {
    ::grpc::ClientContext context;
    fgen::ImportAttributeConfigurationBufferRequest import_request;
    import_request.mutable_vi()->set_id(GetSessionId());
    auto exported_configuration = export_buffer_response.configuration();
    import_request.mutable_configuration()->Add(exported_configuration.begin(), exported_configuration.end());
    fgen::ImportAttributeConfigurationBufferResponse import_response;

    ::grpc::Status status = GetStub()->ImportAttributeConfigurationBuffer(&context, import_request, &import_response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kfgenDriverApiSuccess, import_response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<fgen::NiFgen::Stub> nifgen_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<fgen::NiFgenLibrary> nifgen_library_;
  std::unique_ptr<fgen::NiFgenService> nifgen_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(nifgenDriverApiTest, PerformSelfTest_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  fgen::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  fgen::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, response.self_test_message().size());
}

TEST_F(nifgenDriverApiTest, PerformReset_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  fgen::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  fgen::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());
}

TEST_F(nifgenDriverApiTest, SetAttributeViInt32_GetAttributeViInt32_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttributes attribute_to_set = fgen::NiFgenAttributes::NIFGEN_ATTRIBUTE_OUTPUT_MODE;
  const ViInt32 expected_value = fgen::OutputMode::OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB;
  ::grpc::ClientContext context;
  fgen::SetAttributeViInt32Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  fgen::SetAttributeViInt32Response response;
  ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());

  ViInt32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(nifgenDriverApiTest, SetAttributeViReal64_GetAttributeViReal64_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttributes attribute_to_set = fgen::NiFgenAttributes::NIFGEN_ATTRIBUTE_DIGITAL_GAIN;
  const ViReal64 expected_value = -1.0;
  ::grpc::ClientContext context;
  fgen::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  fgen::SetAttributeViReal64Response response;
  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());

  ViReal64 get_attribute_value_sourcedelay = get_real64_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value_sourcedelay);
}

TEST_F(nifgenDriverApiTest, SetAttributeViBoolean_GetAttributeViBoolean_ValueMatches)
{
  const char* channel_name = "0";
  const fgen::NiFgenAttributes attribute_to_set = fgen::NiFgenAttributes::NIFGEN_ATTRIBUTE_OUTPUT_ENABLED;
  const ViBoolean expected_value = true;
  ::grpc::ClientContext context;
  fgen::SetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  fgen::SetAttributeViBooleanResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());

  ViBoolean get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(nifgenDriverApiTest, SetAttributeViString_GetAttributeViString_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttributes attribute_to_set = fgen::NiFgenAttributes::NIFGEN_ATTRIBUTE_MARKER_EVENT_OUTPUT_TERMINAL;
  const ViString expected_value = "sample";
  ::grpc::ClientContext context;
  fgen::SetAttributeViStringRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  fgen::SetAttributeViStringResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);
  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());

  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);

  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

TEST_F(nifgenDriverApiTest, ConfigureTriggerMode_ConfiguresSuccessfully)
{
  const char* channel_name = "0";
  fgen::TriggerMode expected_value = fgen::TriggerMode::TRIGGER_MODE_NIFGEN_VAL_CONTINUOUS;
  configure_trigger_mode(channel_name, expected_value);

  ViInt32 actual_trigger_mode = get_int32_attribute(channel_name, fgen::NiFgenAttributes::NIFGEN_ATTRIBUTE_TRIGGER_MODE);
  EXPECT_EQ(expected_value, actual_trigger_mode);
}

TEST_F(nifgenDriverApiTest, SendSoftwareTrigger_TriggersSuccessfully)
{
  const char* channel_name = "0";
  ViReal64 expected_current_level = 3.0;
  ::grpc::ClientContext context;
  fgen::SendSoftwareTriggerRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  fgen::SendSoftwareTriggerResponse response;
  ::grpc::Status status = GetStub()->SendSoftwareTrigger(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());
}

TEST_F(nifgenDriverApiTest, ResetInterchangeCheck_ResetsSuccessfully)
{
  const char* channel_name = "0";
  ViReal64 expected_current_level = 3.0;
  ::grpc::ClientContext context;
  fgen::ResetInterchangeCheckRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  fgen::ResetInterchangeCheckResponse response;
  ::grpc::Status status = GetStub()->ResetInterchangeCheck(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kfgenDriverApiSuccess, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni