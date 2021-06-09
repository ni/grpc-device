#include <gtest/gtest.h>

#include "device_server.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = niscope_grpc;

const int kScopeDriverApiSuccess = 0;

class NiScopeDriverApiTest : public ::testing::Test {
 protected:
  NiScopeDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        niscope_stub_(scope::NiScope::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiScopeDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<scope::NiScope::Stub>& GetStub()
  {
    return niscope_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    scope::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kScopeDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    scope::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    scope::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  int get_actual_num_wfms(const char* channel_list)
  {
    ::grpc::ClientContext context;
    scope::ActualNumWfmsRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    scope::ActualNumWfmsResponse response;
    auto status = GetStub()->ActualNumWfms(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    EXPECT_EQ(1, response.num_wfms());
    return response.num_wfms();
  }

  int get_actual_measurement_waveform_size(niscope_grpc::ArrayMeasurement array_measurement)
  {
    ::grpc::ClientContext context;
    scope::ActualMeasWfmSizeRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_array_meas_function(array_measurement);
    scope::ActualMeasWfmSizeResponse response;
    auto status = GetStub()->ActualMeasWfmSize(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.meas_waveform_size();
  }

  void initiate_acquisition()
  {
    ::grpc::ClientContext context;
    scope::InitiateAcquisitionRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    scope::InitiateAcquisitionResponse response;
    auto status = GetStub()->InitiateAcquisition(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kScopeDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  std::string get_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    scope::GetErrorMessageRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_error_code(error_status);
    scope::GetErrorMessageResponse response;

    ::grpc::Status status = GetStub()->GetErrorMessage(&context, request, &response);
    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
    return response.error_message();
  }

  void auto_setup()
  {
    ::grpc::ClientContext context;
    scope::AutoSetupRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    scope::AutoSetupResponse response;

    ::grpc::Status status = GetStub()->AutoSetup(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  ViBoolean get_bool_attribute(const char* channel_list, scope::NiScopeAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    scope::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_attribute_id(attribute_id);
    scope::GetAttributeViBooleanResponse response;
    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  ViInt32 get_int32_attribute(const char* channel_list, scope::NiScopeAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    scope::GetAttributeViInt32Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_attribute_id(attribute_id);
    scope::GetAttributeViInt32Response response;
    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  ViInt64 get_int64_attribute(const char* channel_list, scope::NiScopeAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    scope::GetAttributeViInt64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_attribute_id(attribute_id);
    scope::GetAttributeViInt64Response response;
    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  ViReal64 get_real64_attribute(const char* channel_list, scope::NiScopeAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    scope::GetAttributeViReal64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_attribute_id(attribute_id);
    scope::GetAttributeViReal64Response response;
    ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

  std::string get_string_attribute(const char* channel_list, scope::NiScopeAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    scope::GetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_list(channel_list);
    request.set_attribute_id(attribute_id);
    scope::GetAttributeViStringResponse response;
    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);
    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.value();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
};

TEST_F(NiScopeDriverApiTest, NiScopeSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiScopeDriverApiTest, NiScopeReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  scope::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiScopeDriverApiTest, NiScopeRead_SendRequest_ReadCompletesWithCorrectSizes)
{
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::ReadRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::ReadResponse response;

  ::grpc::Status status = GetStub()->Read(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_num_samples * expected_num_waveforms, response.waveform_size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchArrayMeasurement_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  const niscope_grpc::ArrayMeasurement measurement_func = niscope_grpc::ArrayMeasurement::ARRAY_MEASUREMENT_NISCOPE_VAL_INVERSE;
  const ViInt32 expected_waveform_size = get_actual_measurement_waveform_size(measurement_func);
  ::grpc::ClientContext context;
  scope::FetchArrayMeasurementRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_array_meas_function(measurement_func);
  scope::FetchArrayMeasurementResponse response;

  ::grpc::Status status = GetStub()->FetchArrayMeasurement(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_waveform_size, response.meas_wfm_size());
  EXPECT_EQ(expected_waveform_size, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchBinary16_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::FetchBinary16Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::FetchBinary16Response response;

  ::grpc::Status status = GetStub()->FetchBinary16(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_num_samples, response.waveform_size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeFetchBinary8_SendRequest_FetchCompletesWithCorrectSizes)
{
  auto_setup();
  initiate_acquisition();
  const ViInt32 expected_num_samples = 100000;
  const char* channel_list = "0";
  const ViInt32 expected_num_waveforms = get_actual_num_wfms(channel_list);
  ::grpc::ClientContext context;
  scope::FetchBinary8Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_timeout(10000);
  request.set_num_samples(expected_num_samples);
  scope::FetchBinary8Response response;

  ::grpc::Status status = GetStub()->FetchBinary8(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(expected_num_waveforms * expected_num_samples, response.waveform().size());
  EXPECT_EQ(expected_num_waveforms, response.wfm_info_size());
}

TEST_F(NiScopeDriverApiTest, NiScopeSetViInt32Attribute_SendRequest_GetViInt32AttributeMatches)
{
  const char* channel_list = "";
  const scope::NiScopeAttributes attribute_to_set = scope::NiScopeAttributes::NISCOPE_ATTRIBUTE_HORZ_NUM_RECORDS;
  const ViInt32 expected_value = 4;
  ::grpc::ClientContext context;
  scope::SetAttributeViInt32Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_attribute_id(attribute_to_set);
  request.set_value_raw(expected_value);
  scope::SetAttributeViInt32Response response;

  ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  ViInt32 get_attribute_value = get_int32_attribute(channel_list, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiScopeDriverApiTest, NiScopeSetViInt64Attribute_SendRequest_GetViInt64AttributeMatches)
{
  const char* channel_list = "";
  // The ViInt64 attributes in niScope.h (p2p ones) can't be used on a simulated device. So
  // we'll just set a ViInt32 attribute to still exercise the get and set ViInt64 methods.
  const scope::NiScopeAttributes attribute_to_set = scope::NiScopeAttributes::NISCOPE_ATTRIBUTE_FETCH_NUM_RECORDS;
  const ViInt64 expected_value = 4;
  ::grpc::ClientContext context;
  scope::SetAttributeViInt64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_attribute_id(attribute_to_set);
  request.set_value_raw(expected_value);
  scope::SetAttributeViInt64Response response;

  ::grpc::Status status = GetStub()->SetAttributeViInt64(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  ViInt64 get_attribute_value = get_int64_attribute(channel_list, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiScopeDriverApiTest, NiScopeSetViReal64Attribute_SendRequest_GetViReal64AttributeMatches)
{
  const char* channel_list = "";
  const scope::NiScopeAttributes attribute_to_set = scope::NiScopeAttributes::NISCOPE_ATTRIBUTE_REF_CLK_RATE;
  const ViReal64 expected_value = 42.24;
  ::grpc::ClientContext context;
  scope::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_attribute_id(attribute_to_set);
  request.set_value_raw(expected_value);
  scope::SetAttributeViReal64Response response;

  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  ViReal64 get_attribute_value = get_real64_attribute(channel_list, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiScopeDriverApiTest, NiScopeSetViStringAttribute_SendRequest_GetViStringAttributeMatches)
{
  const char* channel_list = "";
  const scope::NiScopeAttributes attribute_to_set = scope::NiScopeAttributes::NISCOPE_ATTRIBUTE_TRIGGER_SOURCE;
  const ViString expected_value = "Hello world!";
  ::grpc::ClientContext context;
  scope::SetAttributeViStringRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_attribute_id(attribute_to_set);
  request.set_value_raw(expected_value);
  scope::SetAttributeViStringResponse response;

  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  std::string get_attribute_value = get_string_attribute(channel_list, attribute_to_set);
  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

TEST_F(NiScopeDriverApiTest, NiScopeSetBoolAttribute_SendRequest_GetBoolAttributeMatches)
{
  const char* channel_list = "0";
  const scope::NiScopeAttributes attribute_to_set = scope::NiScopeAttributes::NISCOPE_ATTRIBUTE_CHANNEL_ENABLED;
  const ViBoolean expected_value = true;
  ::grpc::ClientContext context;
  scope::SetAttributeViBooleanRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list(channel_list);
  request.set_attribute_id(attribute_to_set);
  request.set_value(expected_value);
  scope::SetAttributeViBooleanResponse response;

  ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  ViBoolean get_attribute_value = get_bool_attribute(channel_list, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiScopeDriverApiTest, NiScopeConfigureHorizontalTiming_SendRequest_ConfigureCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::ConfigureHorizontalTimingRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_min_sample_rate(1000000);
  request.set_min_num_pts(100000);
  request.set_ref_position(50);
  request.set_num_records(1);
  request.set_enforce_realtime(true);
  scope::ConfigureHorizontalTimingResponse response;

  ::grpc::Status status = GetStub()->ConfigureHorizontalTiming(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiScopeDriverApiTest, NiScopeConfigureVertical_SendRequest_ConfigureCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  scope::ConfigureVerticalRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list("0");
  request.set_range(30.0);
  request.set_offset(0);
  request.set_coupling(scope::VerticalCoupling::VERTICAL_COUPLING_NISCOPE_VAL_DC);
  request.set_enabled(true);
  request.set_probe_attenuation(1);
  scope::ConfigureVerticalResponse response;

  ::grpc::Status status = GetStub()->ConfigureVertical(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiScopeDriverApiTest, NiScopeGetScalingCoefficients_SendRequest_NonZeroCoefficientsReturned)
{
  auto_setup();
  ::grpc::ClientContext context;
  scope::GetScalingCoefficientsRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list("0, 1");
  scope::GetScalingCoefficientsResponse response;

  ::grpc::Status status = GetStub()->GetScalingCoefficients(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(2, response.coefficient_info_size());
  EXPECT_EQ(0, response.coefficient_info(0).offset());
  EXPECT_NE(0, response.coefficient_info(0).gain());
  EXPECT_EQ(0, response.coefficient_info(0).reserved1());
  EXPECT_EQ(0, response.coefficient_info(0).reserved2());
}

TEST_F(NiScopeDriverApiTest, NiScopeGetNormalizationCoefficients_SendRequest_NonZeroCoefficientsReturned)
{
  auto_setup();
  ::grpc::ClientContext context;
  scope::GetNormalizationCoefficientsRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_list("0, 1");
  scope::GetNormalizationCoefficientsResponse response;

  ::grpc::Status status = GetStub()->GetNormalizationCoefficients(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(2, response.coefficient_info_size());
  EXPECT_EQ(0, response.coefficient_info(0).offset());
  EXPECT_NE(0, response.coefficient_info(0).gain());
  EXPECT_EQ(0, response.coefficient_info(0).reserved1());
  EXPECT_EQ(0, response.coefficient_info(0).reserved2());
}

}  // namespace system
}  // namespace tests
}  // namespace ni