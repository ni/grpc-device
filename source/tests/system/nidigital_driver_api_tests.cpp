#include <gtest/gtest.h>

#include "device_server.h"
#include "nidigitalpattern/nidigitalpattern_service.h"

namespace ni {
namespace tests {
namespace system {

namespace digital = nidigitalpattern_grpc;

const int kDigitalDriverApiSuccess = 0;

class NiDigitalDriverApiTest : public ::testing::Test {
 protected:
  NiDigitalDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nidigital_stub_(digital::NiDigital::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiDigitalDriverApiTest() {}

  void SetUp() override
  {
#ifndef WIN32
    GTEST_SKIP() << "Digital pattern is not supported on Linux.";
#endif
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<digital::NiDigital::Stub>& GetStub()
  {
    return nidigital_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    digital::InitWithOptionsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:6570; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    digital::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    if (!driver_session_) {
      return;
    }
    ::grpc::ClientContext context;
    digital::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    digital::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kDigitalDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  std::string get_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    digital::ErrorMessageRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_error_code(error_status);
    digital::ErrorMessageResponse response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
    return response.error_message();
  }

  void set_bool_attribute(const char* channel_name, digital::NiDigitalAttributes attribute, ViBoolean value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViBooleanRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value(value);
    digital::SetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void set_int32_attribute(const char* channel_name, digital::NiDigitalAttributes attribute, digital::NiDigitalInt32AttributeValues value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value(value);
    digital::SetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void set_int64_attribute(const char* channel_name, digital::NiDigitalAttributes attribute, ViInt64 value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViInt64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value_raw(value);
    digital::SetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void set_string_attribute(const char* channel_name, digital::NiDigitalAttributes attribute, ViString value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value_raw(value);
    digital::SetAttributeViStringResponse response;
    
    ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  ViBoolean get_bool_attribute(const char* channel_name, digital::NiDigitalAttributes attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  ViInt32 get_int32_attribute(const char* channel_name, digital::NiDigitalAttributes attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  ViInt64 get_int64_attribute(const char* channel_name, digital::NiDigitalAttributes attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViInt64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  std::string get_string_attribute(const char* channel_name, digital::NiDigitalAttributes attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  void configure_frequency_counter_measurement_time(const char* channel_list, ViReal64 value)
  {
    ::grpc::ClientContext context;
    digital::FrequencyCounterConfigureMeasurementTimeRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_measurement_time(value);
    digital::FrequencyCounterConfigureMeasurementTimeResponse response;

    ::grpc::Status status = GetStub()->FrequencyCounterConfigureMeasurementTime(&context, request, &response);
    
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void select_function(const char* channel_list, digital::SelectedFunction function_type)
  {
    ::grpc::ClientContext context;
    digital::SelectFunctionRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_function(function_type);
    digital::SelectFunctionResponse response;

    ::grpc::Status status = GetStub()->SelectFunction(&context, request, &response);    

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<digital::NiDigital::Stub> nidigital_stub_;
};

TEST_F(NiDigitalDriverApiTest, PerformReadStatic_CompletesSuccessfully)
{
  const char* channel_name = "";
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  digital::ReadStaticRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_name);
  digital::ReadStaticResponse response;
  ::grpc::Status status = GetStub()->ReadStatic(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status()); 
}

TEST_F(NiDigitalDriverApiTest, PerformWriteStatic_CompletesSuccessfully)
{
  const char* channel_name = "";
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  digital::WriteStaticRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_name);
  request.set_state(digital::WriteStaticPinState::WRITE_STATIC_PIN_STATE_NIDIGITAL_VAL_0);
  digital::WriteStaticResponse response;
  ::grpc::Status status = GetStub()->WriteStatic(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, PerformFrequencyCounterMeasureFrequency_CompletesSuccessfully)
{
  const char* channel_name = "";
  ViReal64 measurement_time = 5.0;
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  configure_frequency_counter_measurement_time(channel_name, measurement_time);
  digital::FrequencyCounterMeasureFrequencyRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_name);
  digital::FrequencyCounterMeasureFrequencyResponse response;
  ::grpc::Status status = GetStub()->FrequencyCounterMeasureFrequency(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status()); 
}

TEST_F(NiDigitalDriverApiTest, SelfTest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  digital::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.test_result());
  EXPECT_LT(0, strlen(response.test_message().c_str()));
}

TEST_F(NiDigitalDriverApiTest, Reset_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  digital::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, SetViInt32Attribute_GetViInt32Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttributes attribute_to_set = digital::NiDigitalAttributes::NIDIGITAL_ATTRIBUTE_SELECTED_FUNCTION;
  auto expected_value = digital::NiDigitalInt32AttributeValues::NIDIGITAL_INT32_SELECTED_FUNCTION_VAL_PPMU;
  set_int32_attribute(channel_name, attribute_to_set, expected_value);

  ViInt32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SetViInt64Attribute_GetViInt64Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttributes attribute_to_set = digital::NiDigitalAttributes::NIDIGITAL_ATTRIBUTE_CYCLE_NUMBER_HISTORY_RAM_TRIGGER_CYCLE_NUMBER;
  const ViInt64 expected_value = 4;
  set_int64_attribute(channel_name, attribute_to_set, expected_value);

  ViInt64 get_attribute_value = get_int64_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SetViStringAttribute_GetViStringAttribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttributes attribute_to_set = digital::NiDigitalAttributes::NIDIGITAL_ATTRIBUTE_DIGITAL_EDGE_START_TRIGGER_SOURCE;
  const ViString expected_value = "Hello world!";
  set_string_attribute(channel_name, attribute_to_set, expected_value);

  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);

  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

TEST_F(NiDigitalDriverApiTest, SetBoolAttribute_GetBoolAttribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttributes attribute_to_set = digital::NiDigitalAttributes::NIDIGITAL_ATTRIBUTE_CACHE;
  const ViBoolean expected_value = true;
  set_bool_attribute(channel_name, attribute_to_set, expected_value);

  ViBoolean get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SelfCalibrate_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::SelfCalibrateRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  digital::SelfCalibrateResponse response;
  ::grpc::Status status = GetStub()->SelfCalibrate(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, ClockGeneratorInitiate_ClockGenerationInitiated)
{
  std::string channel_list = "0";
  ::grpc::ClientContext context;
  digital::ClockGeneratorInitiateRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  digital::ClockGeneratorInitiateResponse response;
  ::grpc::Status status = GetStub()->ClockGeneratorInitiate(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_TRUE(get_bool_attribute("0", digital::NIDIGITAL_ATTRIBUTE_CLOCK_GENERATOR_IS_RUNNING));
}

TEST_F(NiDigitalDriverApiTest, ConfigureSoftwareEdgeStartTrigger_StartTriggerTypeAttributeIsSoftware)
{
  ::grpc::ClientContext context;
  digital::ConfigureSoftwareEdgeStartTriggerRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  digital::ConfigureSoftwareEdgeStartTriggerResponse response;
  ::grpc::Status status = GetStub()->ConfigureSoftwareEdgeStartTrigger(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  int start_trigger_type = get_int32_attribute("", digital::NIDIGITAL_ATTRIBUTE_START_TRIGGER_TYPE);
  EXPECT_EQ(digital::NiDigitalInt32AttributeValues::NIDIGITAL_INT32_TRIGGER_TYPE_VAL_SOFTWARE, start_trigger_type);
}

TEST_F(NiDigitalDriverApiTest, ConfigureStartLabel_StartLabelConfigured)
{
  const char* start_label = "abcde";
  ::grpc::ClientContext context;
  digital::ConfigureStartLabelRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_label(start_label);
  digital::ConfigureStartLabelResponse response;
  ::grpc::Status status = GetStub()->ConfigureStartLabel(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  std::string actual_start_label = get_string_attribute("", digital::NIDIGITAL_ATTRIBUTE_START_LABEL);
  EXPECT_EQ(start_label, actual_start_label);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
