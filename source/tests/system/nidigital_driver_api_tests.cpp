#include <gtest/gtest.h>

#ifdef FS_EXPERIMENTAL
  #include <experimental/filesystem>
#else
  #include <filesystem>
#endif

#include "device_server.h"
#include "nidigitalpattern/nidigitalpattern_client.h"

#define EXPECT_SUCCESS(status)               \
  EXPECT_TRUE((status).ok());                \
  if (!(status).ok()) {                      \
    EXPECT_EQ(0, (status).error_code());     \
    EXPECT_EQ("", (status).error_message()); \
  }

namespace ni {
namespace tests {
namespace system {

namespace digital = nidigitalpattern_grpc;
namespace pb = ::google::protobuf;
#ifdef FS_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

typedef pb::int32 int32;
typedef pb::int64 int64;

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
    initialize_multi_instrument_driver_session();
  }

  void TearDown() override
  {
    close_multi_instrument_driver_session();
    close_driver_session();
  }

  std::unique_ptr<digital::NiDigital::Stub>& GetStub()
  {
    return nidigital_stub_;
  }

  std::string GetSessionName()
  {
    return driver_session_->name();
  }

  std::string GetMultiInstrumentSessionName()
  {
    return multi_instrument_driver_session_->name();
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

  void initialize_multi_instrument_driver_session()
  {
    ::grpc::ClientContext context;
    digital::InitWithOptionsRequest request;
    request.set_resource_name("PXI1Slot2,PXI1Slot5");
    request.set_option_string("Simulate=1, DriverSetup=Model:6570; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    digital::InitWithOptionsResponse response;

    ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);
    multi_instrument_driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

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
    request.mutable_vi()->set_name(driver_session_->name());
    digital::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  void close_multi_instrument_driver_session()
  {
    if (!multi_instrument_driver_session_) {
      return;
    }
    ::grpc::ClientContext context;
    digital::CloseRequest request;
    request.mutable_vi()->set_name(multi_instrument_driver_session_->name());
    digital::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_SUCCESS(status);
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
    request.mutable_vi()->set_name(GetSessionName());
    request.set_error_code(error_status);
    digital::ErrorMessageResponse response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &response);
    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
    return response.error_message();
  }

  void load_pin_map(const std::string& session_name, const fs::path& file_path)
  {
    ::grpc::ClientContext context;
    digital::LoadPinMapRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_file_path(file_path.string());
    digital::LoadPinMapResponse response;

    ::grpc::Status status = GetStub()->LoadPinMap(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void load_specifications(const std::string& session_name, const fs::path& file_path)
  {
    ::grpc::ClientContext context;
    digital::LoadSpecificationsRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_file_path(file_path.string());
    digital::LoadSpecificationsResponse response;

    ::grpc::Status status = GetStub()->LoadSpecifications(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void load_levels(const std::string & session_name, const fs::path& file_path)
  {
    ::grpc::ClientContext context;
    digital::LoadLevelsRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_file_path(file_path.string());
    digital::LoadLevelsResponse response;

    ::grpc::Status status = GetStub()->LoadLevels(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void load_timing(const std::string& session_name, const fs::path& file_path)
  {
    ::grpc::ClientContext context;
    digital::LoadTimingRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_file_path(file_path.string());
    digital::LoadTimingResponse response;

    ::grpc::Status status = GetStub()->LoadTiming(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void apply_levels_and_timing(const std::string & session_name, const char* levels_sheet, const char* timing_sheet)
  {
    ::grpc::ClientContext context;
    digital::ApplyLevelsAndTimingRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_levels_sheet(levels_sheet);
    request.set_timing_sheet(timing_sheet);
    digital::ApplyLevelsAndTimingResponse response;

    ::grpc::Status status = GetStub()->ApplyLevelsAndTiming(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void configure_session(const std::string & session_name)
  {
    load_pin_map(session_name, fs::absolute("test_create_capture_waveform_serial/pin_map.pinmap"));
    load_specifications(session_name, fs::absolute("test_create_capture_waveform_serial/specifications.specs"));
    load_levels(session_name, fs::absolute("test_create_capture_waveform_serial/pin_levels.digilevels"));
    load_timing(session_name, fs::absolute("test_create_capture_waveform_serial/timing.digitiming"));
    apply_levels_and_timing(session_name, "pin_levels", "timing");
  }

  void load_pattern(const std::string & session_name, const fs::path& file_path)
  {
    ::grpc::ClientContext context;
    digital::LoadPatternRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_file_path(file_path.string());
    digital::LoadPatternResponse response;

    ::grpc::Status status = GetStub()->LoadPattern(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void create_capture_waveform_serial(
      const std::string & session_name,
      const char* pin_list,
      const char* waveform_name,
      int sample_width,
      digital::BitOrder bit_order)
  {
    ::grpc::ClientContext context;
    digital::CreateCaptureWaveformSerialRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_pin_list(pin_list);
    request.set_waveform_name(waveform_name);
    request.set_sample_width(sample_width);
    request.set_bit_order(bit_order);
    digital::CreateCaptureWaveformSerialResponse response;

    ::grpc::Status status = GetStub()->CreateCaptureWaveformSerial(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void create_source_waveform_serial(
      const std::string & session_name,
      const char* pin_list,
      const char* waveform_name,
      digital::SourceDataMapping data_mapping,
      int sample_width,
      digital::BitOrder bit_order)
  {
    ::grpc::ClientContext context;
    digital::CreateSourceWaveformSerialRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_pin_list(pin_list);
    request.set_waveform_name(waveform_name);
    request.set_data_mapping(data_mapping);
    request.set_sample_width(sample_width);
    request.set_bit_order(bit_order);
    digital::CreateSourceWaveformSerialResponse response;

    ::grpc::Status status = GetStub()->CreateSourceWaveformSerial(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void write_source_waveform_broadcast_u32(const std::string & session_name, const char* waveform_name, unsigned int* waveform_data, int num_samples)
  {
    ::grpc::ClientContext context;
    digital::WriteSourceWaveformBroadcastU32Request request;
    request.mutable_vi()->set_name(session_name);
    request.set_waveform_name(waveform_name);
    for (int i = 0; i < num_samples; ++i) {
      request.add_waveform_data(waveform_data[i]);
    }
    digital::WriteSourceWaveformBroadcastU32Response response;

    ::grpc::Status status = GetStub()->WriteSourceWaveformBroadcastU32(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void burst_pattern(const std::string & session_name, const char* start_label)
  {
    ::grpc::ClientContext context;
    digital::BurstPatternRequest request;
    request.mutable_vi()->set_name(session_name);
    request.set_start_label(start_label);
    digital::BurstPatternResponse response;

    ::grpc::Status status = GetStub()->BurstPattern(&context, request, &response);

    EXPECT_SUCCESS(status);
    EXPECT_EQ(kDigitalDriverApiSuccess, response.status());
  }

  void fetch_capture_waveform(
      const std::string & session_name,
      const char* site_list,
      const char* waveform_name,
      int samples_to_read,
      digital::FetchCaptureWaveformU32Response* response)
  {
    ::grpc::ClientContext context;
    digital::FetchCaptureWaveformU32Request request;
    request.mutable_vi()->set_name(session_name);
    request.set_site_list(site_list);
    request.set_waveform_name(waveform_name);
    request.set_samples_to_read(samples_to_read);
    request.set_timeout(2.0);

    ::grpc::Status status = GetStub()->FetchCaptureWaveformU32(&context, request, response);

    EXPECT_SUCCESS(status);
  }

  void set_bool_attribute(const char* channel_name, digital::NiDigitalAttribute attribute, bool value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViBooleanRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value(value);
    digital::SetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  void set_int32_attribute(const char* channel_name, digital::NiDigitalAttribute attribute, digital::NiDigitalInt32AttributeValues value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViInt32Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value(value);
    digital::SetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  void set_int64_attribute(const char* channel_name, digital::NiDigitalAttribute attribute, int64 value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViInt64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value_raw(value);
    digital::SetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt64(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  void set_string_attribute(const char* channel_name, digital::NiDigitalAttribute attribute, const std::string& value)
  {
    ::grpc::ClientContext context;
    digital::SetAttributeViStringRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    request.set_value_raw(value);
    digital::SetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  bool get_bool_attribute(const char* channel_name, digital::NiDigitalAttribute attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
    return response.value();
  }

  int32 get_int32_attribute(const char* channel_name, digital::NiDigitalAttribute attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViInt32Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
    return response.value();
  }

  int64 get_int64_attribute(const char* channel_name, digital::NiDigitalAttribute attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViInt64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
    return response.value();
  }

  std::string get_string_attribute(const char* channel_name, digital::NiDigitalAttribute attribute)
  {
    ::grpc::ClientContext context;
    digital::GetAttributeViStringRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute(attribute);
    digital::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
    return response.value();
  }

  void configure_frequency_counter_measurement_time(const char* channel_list, double value)
  {
    ::grpc::ClientContext context;
    digital::FrequencyCounterConfigureMeasurementTimeRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_list(channel_list);
    request.set_measurement_time(value);
    digital::FrequencyCounterConfigureMeasurementTimeResponse response;

    ::grpc::Status status = GetStub()->FrequencyCounterConfigureMeasurementTime(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

  void select_function(const char* channel_list, digital::SelectedFunction function_type)
  {
    ::grpc::ClientContext context;
    digital::SelectFunctionRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_list(channel_list);
    request.set_function(function_type);
    digital::SelectFunctionResponse response;

    ::grpc::Status status = GetStub()->SelectFunction(&context, request, &response);

    EXPECT_SUCCESS(status);
    expect_api_success(response.status());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<::nidevice_grpc::Session> multi_instrument_driver_session_;
  std::unique_ptr<digital::NiDigital::Stub> nidigital_stub_;
};

TEST_F(NiDigitalDriverApiTest, PerformReadStatic_CompletesSuccessfully)
{
  const char* channel_name = "";
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  digital::ReadStaticRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_list(channel_name);
  digital::ReadStaticResponse response;
  ::grpc::Status status = GetStub()->ReadStatic(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, PerformWriteStatic_CompletesSuccessfully)
{
  const char* channel_name = "";
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  digital::WriteStaticRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_list(channel_name);
  request.set_state(digital::WriteStaticPinState::WRITE_STATIC_PIN_STATE_NIDIGITAL_VAL_0);
  digital::WriteStaticResponse response;
  ::grpc::Status status = GetStub()->WriteStatic(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, PerformFrequencyCounterMeasureFrequency_CompletesSuccessfully)
{
  const char* channel_name = "";
  double measurement_time = 5.0;
  ::grpc::ClientContext context;
  select_function(channel_name, digital::SelectedFunction::SELECTED_FUNCTION_NIDIGITAL_VAL_DIGITAL);
  configure_frequency_counter_measurement_time(channel_name, measurement_time);
  digital::FrequencyCounterMeasureFrequencyRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_list(channel_name);
  digital::FrequencyCounterMeasureFrequencyResponse response;
  ::grpc::Status status = GetStub()->FrequencyCounterMeasureFrequency(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, CreateCaptureWaveformSerial_FetchCaptureWaveform_ReturnsReasonableData)
{
  const std::string& session_name = GetMultiInstrumentSessionName();
  configure_session(session_name);
  load_pattern(session_name, fs::absolute("test_create_capture_waveform_serial/pattern.digipat"));
  auto bit_order = digital::BitOrder::BIT_ORDER_NIDIGITAL_VAL_LSB_FIRST;
  create_capture_waveform_serial(session_name, "HI0", "capt_wfm", 2, bit_order);
  // The pattern references a wfm "src_wfm", so we have to load it before we can burst
  auto source_data_mapping = digital::SourceDataMapping::SOURCE_DATA_MAPPING_NIDIGITAL_VAL_BROADCAST;
  create_source_waveform_serial(session_name, "LO0", "src_wfm", source_data_mapping, 2, bit_order);
  unsigned int waveform_data[] = {1, 2};
  write_source_waveform_broadcast_u32(session_name, "src_wfm", waveform_data, sizeof(waveform_data) / sizeof(unsigned int));
  burst_pattern(session_name, "new_pattern");

  int num_samples = 2;
  digital::FetchCaptureWaveformU32Response response;
  fetch_capture_waveform(session_name, "site0,site1", "capt_wfm", num_samples, &response);

  int num_sites = 2;
  expect_api_success(response.status());
  EXPECT_EQ(num_sites * num_samples, response.data_size());
}

TEST_F(NiDigitalDriverApiTest, SelfTest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::SelfTestRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  digital::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
  EXPECT_EQ(0, response.test_result());
  EXPECT_LT(0, strlen(response.test_message().c_str()));
}

TEST_F(NiDigitalDriverApiTest, Reset_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::ResetRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  digital::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, SetViInt32Attribute_GetViInt32Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttribute attribute_to_set = digital::NiDigitalAttribute::NIDIGITAL_ATTRIBUTE_SELECTED_FUNCTION;
  auto expected_value = digital::NiDigitalInt32AttributeValues::NIDIGITAL_INT32_SELECTED_FUNCTION_VAL_PPMU;
  set_int32_attribute(channel_name, attribute_to_set, expected_value);

  int32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SetViInt64Attribute_GetViInt64Attribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttribute attribute_to_set = digital::NiDigitalAttribute::NIDIGITAL_ATTRIBUTE_CYCLE_NUMBER_HISTORY_RAM_TRIGGER_CYCLE_NUMBER;
  const int64 expected_value = 4;
  set_int64_attribute(channel_name, attribute_to_set, expected_value);

  int64 get_attribute_value = get_int64_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SetViStringAttribute_GetViStringAttribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttribute attribute_to_set = digital::NiDigitalAttribute::NIDIGITAL_ATTRIBUTE_DIGITAL_EDGE_START_TRIGGER_SOURCE;
  const std::string expected_value = "Hello world!";
  set_string_attribute(channel_name, attribute_to_set, expected_value);

  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);

  EXPECT_STREQ(expected_value.c_str(), get_attribute_value.c_str());
}

TEST_F(NiDigitalDriverApiTest, SetBoolAttribute_GetBoolAttribute_ValueMatchesSetValue)
{
  const char* channel_name = "";
  const digital::NiDigitalAttribute attribute_to_set = digital::NiDigitalAttribute::NIDIGITAL_ATTRIBUTE_CACHE;
  const bool expected_value = true;
  set_bool_attribute(channel_name, attribute_to_set, expected_value);

  bool get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiDigitalDriverApiTest, SelfCalibrate_CompletesSuccessfully)
{
  ::grpc::ClientContext context;
  digital::SelfCalibrateRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  digital::SelfCalibrateResponse response;
  ::grpc::Status status = GetStub()->SelfCalibrate(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
}

TEST_F(NiDigitalDriverApiTest, ClockGeneratorInitiate_ClockGenerationInitiated)
{
  std::string channel_list = "0";
  ::grpc::ClientContext context;
  digital::ClockGeneratorInitiateRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_list(channel_list);
  digital::ClockGeneratorInitiateResponse response;
  ::grpc::Status status = GetStub()->ClockGeneratorInitiate(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
  EXPECT_TRUE(get_bool_attribute("0", digital::NIDIGITAL_ATTRIBUTE_CLOCK_GENERATOR_IS_RUNNING));
}

TEST_F(NiDigitalDriverApiTest, ConfigureSoftwareEdgeStartTrigger_StartTriggerTypeAttributeIsSoftware)
{
  ::grpc::ClientContext context;
  digital::ConfigureSoftwareEdgeStartTriggerRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  digital::ConfigureSoftwareEdgeStartTriggerResponse response;
  ::grpc::Status status = GetStub()->ConfigureSoftwareEdgeStartTrigger(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
  int start_trigger_type = get_int32_attribute("", digital::NIDIGITAL_ATTRIBUTE_START_TRIGGER_TYPE);
  EXPECT_EQ(digital::NiDigitalInt32AttributeValues::NIDIGITAL_INT32_TRIGGER_TYPE_VAL_SOFTWARE, start_trigger_type);
}

TEST_F(NiDigitalDriverApiTest, ConfigureStartLabel_StartLabelConfigured)
{
  const char* start_label = "abcde";
  ::grpc::ClientContext context;
  digital::ConfigureStartLabelRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_label(start_label);
  digital::ConfigureStartLabelResponse response;
  ::grpc::Status status = GetStub()->ConfigureStartLabel(&context, request, &response);

  EXPECT_SUCCESS(status);
  expect_api_success(response.status());
  std::string actual_start_label = get_string_attribute("", digital::NIDIGITAL_ATTRIBUTE_START_LABEL);
  EXPECT_EQ(start_label, actual_start_label);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
