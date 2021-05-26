#include <gtest/gtest.h>

#include "device_server.h"
#include "nidcpower/nidcpower_service.h"

namespace ni {
namespace tests {
namespace system {

namespace dcpower = nidcpower_grpc;

const int kdcpowerDriverApiSuccess = 0;

class NiDCPowerDriverApiTest : public ::testing::Test {
 protected:
  NiDCPowerDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nidcpower_stub_(dcpower::NiDCPower::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiDCPowerDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<dcpower::NiDCPower::Stub>& GetStub()
  {
    return nidcpower_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    dcpower::InitializeWithIndependentChannelsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:4147; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset(false);
    dcpower::InitializeWithIndependentChannelsResponse response;

    ::grpc::Status status = GetStub()->InitializeWithIndependentChannels(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void initiate()
  {
    dcpower::InitiateRequest request;
    dcpower::InitiateResponse response;
    ::grpc::ClientContext context;
    request.mutable_vi()->set_id(GetSessionId());

    ::grpc::Status status = GetStub()->Initiate(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    dcpower::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    dcpower::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void measure_multiple(const char* channel_name, nidcpower_grpc::MeasureMultipleResponse* response)
  {
    ::grpc::ClientContext context;
    dcpower::MeasureMultipleRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);

    ::grpc::Status status = GetStub()->MeasureMultiple(&context, request, response);

    EXPECT_TRUE(status.ok());
  }

  ViBoolean get_bool_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    dcpower::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    dcpower::GetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViInt32 get_int32_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    dcpower::GetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    dcpower::GetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViInt64 get_int64_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    dcpower::GetAttributeViInt64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    dcpower::GetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  ViReal64 get_real64_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    dcpower::GetAttributeViReal64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    dcpower::GetAttributeViReal64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  std::string get_string_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    dcpower::GetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    dcpower::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response.attribute_value();
  }

  void set_int32_attribute(const char* channel_list, dcpower::NiDCPowerAttributes attribute_id, dcpower::NiDCPowerInt32AttributeValues attribute_value)
  {
    ::grpc::ClientContext context;
    const dcpower::NiDCPowerAttributes attribute_to_set = attribute_id;
    dcpower::SetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_to_set);
    request.set_attribute_value(attribute_value);
    dcpower::SetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void configure_output_function(const char* channel_name, dcpower::OutputFunction function)
  {
    ::grpc::ClientContext context;
    dcpower::ConfigureOutputFunctionRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_function(function);
    dcpower::ConfigureOutputFunctionResponse response;

    ::grpc::Status status = GetStub()->ConfigureOutputFunction(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void configure_voltage_level(const char* channel_name, ViReal64 level)
  {
    ::grpc::ClientContext context;
    dcpower::ConfigureVoltageLevelRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_level(level);
    dcpower::ConfigureVoltageLevelResponse response;

    ::grpc::Status status = GetStub()->ConfigureVoltageLevel(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void configure_current_level(const char* channel_name, ViReal64 level)
  {
    ::grpc::ClientContext context;
    dcpower::ConfigureCurrentLevelRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_level(level);
    dcpower::ConfigureCurrentLevelResponse response;

    ::grpc::Status status = GetStub()->ConfigureCurrentLevel(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  dcpower::ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer()
  {
    ::grpc::ClientContext context;
    dcpower::ExportAttributeConfigurationBufferRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    dcpower::ExportAttributeConfigurationBufferResponse response;

    ::grpc::Status status = GetStub()->ExportAttributeConfigurationBuffer(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
    return response;
  }

  void reset_with_channels(const char* channel_name)
  {
    ::grpc::ClientContext context;
    dcpower::ResetWithChannelsRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    dcpower::ResetWithChannelsResponse response;

    ::grpc::Status status = GetStub()->ResetWithChannels(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  }

  void fetch_multiple(const char* channel_name, nidcpower_grpc::FetchMultipleResponse* response)
  {
    ::grpc::ClientContext context;
    dcpower::FetchMultipleRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_timeout(5);
    request.set_count(20);

    ::grpc::Status status = GetStub()->FetchMultiple(&context, request, response);

    EXPECT_TRUE(status.ok());
  }

  void import_attribute_configuration_buffer(dcpower::ExportAttributeConfigurationBufferResponse export_buffer_response)
  {
    ::grpc::ClientContext context;
    dcpower::ImportAttributeConfigurationBufferRequest import_request;
    import_request.mutable_vi()->set_id(GetSessionId());
    auto exported_configuration = export_buffer_response.configuration();
    import_request.mutable_configuration()->Add(exported_configuration.begin(), exported_configuration.end());
    dcpower::ImportAttributeConfigurationBufferResponse import_response;

    ::grpc::Status status = GetStub()->ImportAttributeConfigurationBuffer(&context, import_request, &import_response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kdcpowerDriverApiSuccess, import_response.status());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<dcpower::NiDCPower::Stub> nidcpower_stub_;
};

TEST_F(NiDCPowerDriverApiTest, PerformSelfTest_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  dcpower::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dcpower::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, response.self_test_message().size());
}

TEST_F(NiDCPowerDriverApiTest, PerformReset_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  dcpower::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  dcpower::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
}

TEST_F(NiDCPowerDriverApiTest, SetAttributeViInt32_GetAttributeViInt32ReturnsSameValue)
{
  const char* channel_name = "";
  const dcpower::NiDCPowerAttributes attribute_to_set = dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_WHEN;
  const auto expected_value = dcpower::NiDCPowerInt32AttributeValues::NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE;
  ::grpc::ClientContext context;
  dcpower::SetAttributeViInt32Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  dcpower::SetAttributeViInt32Response response;
  ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  ViInt32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDCPowerDriverApiTest, SetAttributeViReal64_GetAttributeViReal64ReturnsSameValue)
{
  const char* channel_name = "0";
  // Attribute 'NIDCPOWER_ATTRIBUTE_MEASURE_WHEN' must be set to 'MEASURE_WHEN_NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE'
  // before setting attribute 'NIDCPOWER_ATTRIBUTE_SOURCE_DELAY'.
  set_int32_attribute(
      channel_name,
      dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
      dcpower::NiDCPowerInt32AttributeValues::NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE);
  const dcpower::NiDCPowerAttributes attribute_to_set = dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_SOURCE_DELAY;
  const ViReal64 expected_value = 2.516;
  ::grpc::ClientContext context;
  dcpower::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  dcpower::SetAttributeViReal64Response response;
  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  ViReal64 get_attribute_value_sourcedelay = get_real64_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value_sourcedelay);
}

TEST_F(NiDCPowerDriverApiTest, SetAttributeViBoolean_GetAttributeViBooleanReturnsSameValue)
{
  const char* channel_name = "0";
  // Attribute 'NIDCPOWER_ATTRIBUTE_MEASURE_WHEN' must be set to 'MEASURE_WHEN_NIDCPOWER_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE'
  // before setting attribute 'NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE'.
  set_int32_attribute(
      channel_name,
      dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
      dcpower::NiDCPowerInt32AttributeValues::NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE);
  const dcpower::NiDCPowerAttributes attribute_to_set = dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_RECORD_LENGTH_IS_FINITE;
  const ViBoolean expected_value = true;
  ::grpc::ClientContext context;
  dcpower::SetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  dcpower::SetAttributeViBooleanResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  ViBoolean get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDCPowerDriverApiTest, SetAttributeViString_GetAttributeViStringReturnsSameValue)
{
  const char* channel_name = "0";
  const dcpower::NiDCPowerAttributes attribute_to_set = dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL;
  const ViString expected_value = "/Dev1/PXI_Trig0";
  ::grpc::ClientContext context;
  dcpower::SetAttributeViStringRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  dcpower::SetAttributeViStringResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);
  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

TEST_F(NiDCPowerDriverApiTest, SetAttributeViInt64_GetAttributeViInt64ReturnsSameValue)
{
  const char* channel_name = "";
  const dcpower::NiDCPowerAttributes attribute_to_set = dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_ACTIVE_ADVANCED_SEQUENCE_STEP;
  const ViInt64 expected_value = 1;
  ::grpc::ClientContext context;
  dcpower::SetAttributeViInt64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  dcpower::SetAttributeViInt64Response response;
  ::grpc::Status status = GetStub()->SetAttributeViInt64(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
  ViInt64 get_attribute_value = get_int64_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDCPowerDriverApiTest, ConfigureOutputFunctionAndVoltageLevel_ConfiguresSuccessfully)
{
  const char* channel_name = "0";
  ViReal64 expected_voltage_level = 3.0;
  auto expected_output_function_value = dcpower::OutputFunction::OUTPUT_FUNCTION_NIDCPOWER_VAL_DC_VOLTAGE;
  configure_output_function(channel_name, expected_output_function_value);
  configure_voltage_level(channel_name, expected_voltage_level);

  ViReal64 actual_voltage_level = get_real64_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_VOLTAGE_LEVEL);
  ViInt32 actual_output_function_value = get_int32_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_OUTPUT_FUNCTION);
  EXPECT_EQ(expected_voltage_level, actual_voltage_level);
  EXPECT_EQ(expected_output_function_value, actual_output_function_value);
}

TEST_F(NiDCPowerDriverApiTest, ConfigureOutputFunctionAndCurrentLevel_ConfiguresSuccessfully)
{
  const char* channel_name = "0";
  ViReal64 expected_current_level = 3.0;
  auto expected_output_function_value = dcpower::OutputFunction::OUTPUT_FUNCTION_NIDCPOWER_VAL_DC_CURRENT;
  configure_output_function(channel_name, expected_output_function_value);
  configure_current_level(channel_name, expected_current_level);

  ViReal64 actual_current_level = get_real64_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_CURRENT_LEVEL);
  ViInt32 actual_output_function_value = get_int32_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_OUTPUT_FUNCTION);
  EXPECT_EQ(expected_current_level, actual_current_level);
  EXPECT_EQ(expected_output_function_value, actual_output_function_value);
}

TEST_F(NiDCPowerDriverApiTest, SetMeasureWhenAndInitiate_MeasureMultiple_ReturnsSuccess)
{
  const char* channel_name = "";  // all channels in session
  // Attribute 'NIDCPOWER_ATTRIBUTE_MEASURE_WHEN' must be set to On Demand before calling MeasureMultiple
  set_int32_attribute(
      channel_name,
      dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
      dcpower::NiDCPowerInt32AttributeValues::NIDCPOWER_INT32_MEASURE_WHEN_VAL_ON_DEMAND);
  initiate();

  dcpower::MeasureMultipleResponse response;
  measure_multiple(channel_name, &response);

  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
}

TEST_F(NiDCPowerDriverApiTest, SetMeasureWhenAndInitiate_FetchMultiple_FetchesSuccessfully)
{
  const char* channel_name = "0";
  // Attribute 'NIDCPOWER_ATTRIBUTE_MEASURE_WHEN' must be set before calling FetchMultiple
  set_int32_attribute(
      channel_name,
      dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_MEASURE_WHEN,
      dcpower::NiDCPowerInt32AttributeValues::NIDCPOWER_INT32_MEASURE_WHEN_VAL_AUTOMATICALLY_AFTER_SOURCE_COMPLETE);
  initiate();

  dcpower::FetchMultipleResponse response;
  fetch_multiple(channel_name, &response);

  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
}

TEST_F(NiDCPowerDriverApiTest, VoltageLevelConfiguredAndExportedToBuffer_ResetAndImportConfigurationFromBuffer_ConfigurationIsImportedSuccessfully)
{
  const char* channel_name = "0";
  auto expected_output_function = dcpower::OutputFunction::OUTPUT_FUNCTION_NIDCPOWER_VAL_DC_VOLTAGE;
  auto expected_voltage_level = 3.0;
  configure_output_function(channel_name, expected_output_function);
  configure_voltage_level(channel_name, expected_voltage_level);
  auto export_buffer_response = export_attribute_configuration_buffer();

  reset_with_channels(channel_name);
  import_attribute_configuration_buffer(export_buffer_response);

  auto actual_voltage_level = get_real64_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_VOLTAGE_LEVEL);
  auto actual_output_function = get_int32_attribute(channel_name, dcpower::NiDCPowerAttributes::NIDCPOWER_ATTRIBUTE_OUTPUT_FUNCTION);
  EXPECT_EQ(expected_voltage_level, actual_voltage_level);
  EXPECT_EQ(expected_output_function, actual_output_function);
}

TEST_F(NiDCPowerDriverApiTest, CalSelfCalibrate_CompletesSuccessfully)
{
  const char* channel_name = "";
  ::grpc::ClientContext context;
  dcpower::CalSelfCalibrateRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  dcpower::CalSelfCalibrateResponse response;
  ::grpc::Status status = GetStub()->CalSelfCalibrate(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kdcpowerDriverApiSuccess, response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni