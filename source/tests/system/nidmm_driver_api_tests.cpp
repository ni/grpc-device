#include <gtest/gtest.h>

#include "nidmm/nidmm_library.h"
#include "nidmm/nidmm_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dmm = nidmm_grpc;

const int kDMMDriverApiSuccess = 0;

class NiDmmDriverApiTest : public ::testing::Test {
 protected:
  NiDmmDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    using ResourceRepository = nidevice_grpc::SessionResourceRepository<ViSession>;
    auto resource_repository = std::make_shared<ResourceRepository>(session_repository_.get());
    nidmm_library_ = std::make_unique<dmm::NiDmmLibrary>();
    nidmm_service_ = std::make_unique<dmm::NiDmmService>(nidmm_library_.get(), resource_repository);
    builder.RegisterService(nidmm_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  virtual ~NiDmmDriverApiTest() {}

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
    nidmm_stub_ = dmm::NiDmm::NewStub(channel_);
  }

  std::unique_ptr<dmm::NiDmm::Stub>& GetStub()
  {
    return nidmm_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kDMMDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    dmm::InitWithOptionsRequest request;
    request.set_resource_name("SimulatedDMM");
    request.set_option_string("Simulate=1, DriverSetup=Model:4080; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    dmm::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
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

  ViBoolean get_bool_attribute(const char* channel_name, dmm::NiDmmAttributes attribute_id)
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

  ViInt32 get_int32_attribute(const char* channel_name, dmm::NiDmmAttributes attribute_id)
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

  ViReal64 get_real64_attribute(const char* channel_name, dmm::NiDmmAttributes attribute_id)
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

  void configure_current_source(double value)
  {
    ::grpc::ClientContext context;
    dmm::ConfigureCurrentSourceRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_current_source(value);
    dmm::ConfigureCurrentSourceResponse response;
    ::grpc::Status status = GetStub()->ConfigureCurrentSource(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  dmm::ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer()
  {
    ::grpc::ClientContext context;
    dmm::ExportAttributeConfigurationBufferRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    dmm::ExportAttributeConfigurationBufferResponse response;
    ::grpc::Status status = GetStub()->ExportAttributeConfigurationBuffer(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());

    return response;
  }

  void reset()
  {
    ::grpc::ClientContext context;
    dmm::ResetRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    dmm::ResetResponse response;
    ::grpc::Status status = GetStub()->Reset(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void import_attribute_configuration_buffer(dmm::ExportAttributeConfigurationBufferResponse exported_configuration_response)
  {
    ::grpc::ClientContext context;
    dmm::ImportAttributeConfigurationBufferRequest import_request;
    import_request.mutable_vi()->set_id(GetSessionId());
    auto exported_configuration = exported_configuration_response.configuration();
    import_request.mutable_configuration()->append(exported_configuration.begin(), exported_configuration.end());
    dmm::ImportAttributeConfigurationBufferResponse import_response;
    ::grpc::Status status = GetStub()->ImportAttributeConfigurationBuffer(&context, import_request, &import_response);

    EXPECT_TRUE(status.ok());
    expect_api_success(import_response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<dmm::NiDmm::Stub> nidmm_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<dmm::NiDmmLibrary> nidmm_library_;
  std::unique_ptr<dmm::NiDmmService> nidmm_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiDmmDriverApiTest, SelfTest_CompletesSuccessfully)
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

TEST_F(NiDmmDriverApiTest, Reset_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dmm::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDmmDriverApiTest, SetViReal64Attribute_GetViReal64Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const dmm::NiDmmAttributes attribute_to_set = dmm::NiDmmAttributes::NIDMM_ATTRIBUTE_TRIGGER_DELAY;
  const ViReal64 expected_value = 42.24;
  ::grpc::ClientContext context;
  dmm::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  dmm::SetAttributeViReal64Response response;
  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);
  ViReal64 get_attribute_value = get_real64_attribute(channel_name, attribute_to_set);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDmmDriverApiTest, SetViInt32Attribute_GetViInt32Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const dmm::NiDmmAttributes attribute_to_set = dmm::NiDmmAttributes::NIDMM_ATTRIBUTE_SAMPLE_COUNT;
  const ViInt32 expected_value = 4;
  ::grpc::ClientContext context;
  dmm::SetAttributeViInt32Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  dmm::SetAttributeViInt32Response response;
  ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);
  ViInt32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDmmDriverApiTest, SetViBooleanAttribute_GetViBooleanAttribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const dmm::NiDmmAttributes attribute_to_set = dmm::NiDmmAttributes::NIDMM_ATTRIBUTE_SIMULATE;
  const ViBoolean expected_value = true;
  ::grpc::ClientContext context;
  dmm::SetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  dmm::SetAttributeViBooleanResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);
  ViBoolean get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDmmDriverApiTest, ConfigureMeasurementAbsolute_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::ConfigureMeasurementAbsoluteRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_measurement_function(dmm::Function::FUNCTION_NIDMM_VAL_DC_VOLTS);
  request.set_range(10);
  request.set_resolution_absolute(5.5);
  dmm::ConfigureMeasurementAbsoluteResponse response;
  ::grpc::Status status = GetStub()->ConfigureMeasurementAbsolute(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDmmDriverApiTest, ConfigureCurrentSourse_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::ConfigureCurrentSourceRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_current_source(0.0001);
  dmm::ConfigureCurrentSourceResponse response;
  ::grpc::Status status = GetStub()->ConfigureCurrentSource(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDmmDriverApiTest, ExportConfiguredCurrentSource_ResetAndImportConfiguration_CurrentSourceConfigurationIsImported)
{
  double expected_value = 0.0001;
  configure_current_source(expected_value);
  auto exported_configuration_response = export_attribute_configuration_buffer();

  reset();
  import_attribute_configuration_buffer(exported_configuration_response);

  double set_value = get_real64_attribute("", dmm::NiDmmAttributes::NIDMM_ATTRIBUTE_CURRENT_SOURCE);
  EXPECT_EQ(expected_value, set_value);
}

TEST_F(NiDmmDriverApiTest, ConfiguredTrigger_ConfiguresSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::ConfigureTriggerRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_trigger_source(dmm::TriggerSource::TRIGGER_SOURCE_NIDMM_VAL_SOFTWARE_TRIG);
  request.set_trigger_delay(dmm::TriggerDelays::TRIGGER_DELAYS_NIDMM_VAL_AUTO_DELAY_ON);
  dmm::ConfigureTriggerResponse response;
  ::grpc::Status status = GetStub()->ConfigureTrigger(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDmmDriverApiTest, AcquireMeasurement_CompletesSuccesfully)
{
  ::grpc::ClientContext context;
  dmm::ReadRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_maximum_time_raw(1000);
  dmm::ReadResponse response;
  ::grpc::Status status = GetStub()->Read(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_NE(0, response.reading());
}

TEST_F(NiDmmDriverApiTest, SelfCalibrate_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  dmm::SelfCalRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dmm::SelfCalResponse response;
  ::grpc::Status status = GetStub()->SelfCal(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
