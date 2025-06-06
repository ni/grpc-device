#include <gtest/gtest.h>

#include "device_server.h"
#include "nifgen/nifgen_client.h"
#include "tests/utilities/test_helpers.h"
#include "waveform_helpers.h"

namespace ni {
namespace tests {
namespace system {

namespace fgen = nifgen_grpc;

typedef ::google::protobuf::int16 int16;
typedef ::google::protobuf::int32 int32;
typedef ::google::protobuf::int64 int64;
typedef ::google::protobuf::uint32 uint32;
typedef ::google::protobuf::uint16 uint16;

const int kFgenDriverApiSuccess = 0;

class NiFgenDriverApiTest : public ::testing::Test {
 protected:
  NiFgenDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nifgen_stub_(fgen::NiFgen::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiFgenDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<fgen::NiFgen::Stub>& GetStub()
  {
    return nifgen_stub_;
  }

  std::string GetSessionName()
  {
    return driver_session_->name();
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kFgenDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    fgen::InitializeWithChannelsRequest request;
    request.set_channel_name("");
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5441;BoardType:PXI");
    request.set_reset_device(false);
    fgen::InitializeWithChannelsResponse response;

    ::grpc::Status status = GetStub()->InitializeWithChannels(&context, request, &response);
    nidevice_grpc::experimental::client::raise_if_error(status, context);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void initiate()
  {
    fgen::InitiateGenerationRequest request;
    fgen::InitiateGenerationResponse response;
    ::grpc::ClientContext context;
    request.mutable_vi()->set_name(GetSessionName());

    ::grpc::Status status = GetStub()->InitiateGeneration(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void close_driver_session()
  {
    if (!driver_session_) {
      return;
    }

    ::grpc::ClientContext context;
    fgen::CloseRequest request;
    request.mutable_vi()->set_name(driver_session_->name());
    fgen::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  std::string get_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    fgen::ErrorHandlerRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_error_code(error_status);
    fgen::ErrorHandlerResponse response;
    ::grpc::Status status = GetStub()->ErrorHandler(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kFgenDriverApiSuccess, response.status());

    return response.error_message();
  }

  bool get_bool_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViBooleanRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  int32 get_int32_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViInt32Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  int64 get_int64_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViInt64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViInt64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViInt64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  double get_real64_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViReal64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViReal64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  std::string get_string_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id)
  {
    ::grpc::ClientContext context;
    fgen::GetAttributeViStringRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    fgen::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  void set_int32_attribute(const char* channel_list, fgen::NiFgenAttribute attribute_id, fgen::NiFgenInt32AttributeValues attribute_value)
  {
    ::grpc::ClientContext context;
    fgen::SetAttributeViInt32Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_list);
    request.set_attribute_id(attribute_id);
    request.set_attribute_value(attribute_value);
    fgen::SetAttributeViInt32Response response;

    ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void set_bool_attribute(const char* channel_name, fgen::NiFgenAttribute attribute, bool value)
  {
    ::grpc::ClientContext context;
    fgen::SetAttributeViBooleanRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute);
    request.set_attribute_value(value);
    fgen::SetAttributeViBooleanResponse response;

    ::grpc::Status status = GetStub()->SetAttributeViBoolean(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void configure_trigger_mode(const char* channel_name, fgen::TriggerMode trigger_mode)
  {
    ::grpc::ClientContext context;
    fgen::ConfigureTriggerModeRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_trigger_mode(trigger_mode);
    fgen::ConfigureTriggerModeResponse response;

    ::grpc::Status status = GetStub()->ConfigureTriggerMode(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  fgen::ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer()
  {
    ::grpc::ClientContext context;
    fgen::ExportAttributeConfigurationBufferRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    fgen::ExportAttributeConfigurationBufferResponse response;

    ::grpc::Status status = GetStub()->ExportAttributeConfigurationBuffer(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response;
  }

  void import_attribute_configuration_buffer(fgen::ExportAttributeConfigurationBufferResponse export_buffer_response)
  {
    ::grpc::ClientContext context;
    fgen::ImportAttributeConfigurationBufferRequest import_request;
    import_request.mutable_vi()->set_name(GetSessionName());
    auto exported_configuration = export_buffer_response.configuration();
    import_request.mutable_configuration()->append(exported_configuration.begin(), exported_configuration.end());
    fgen::ImportAttributeConfigurationBufferResponse import_response;

    ::grpc::Status status = GetStub()->ImportAttributeConfigurationBuffer(&context, import_request, &import_response);

    EXPECT_TRUE(status.ok());
    expect_api_success(import_response.status());
  }

  void reset()
  {
    ::grpc::ClientContext context;
    fgen::ResetRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    fgen::ResetResponse response;

    ::grpc::Status status = GetStub()->Reset(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void configure_output_mode(const char* channel_name, fgen::OutputMode output_mode)
  {
    ::grpc::ClientContext context;
    fgen::ConfigureOutputModeRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_output_mode(output_mode);
    fgen::ConfigureOutputModeResponse response;

    ::grpc::Status status = GetStub()->ConfigureOutputMode(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  int32 create_arb_waveform(const char* channel_name)
  {
    ::grpc::ClientContext context;
    fgen::CreateWaveformF64Request request;
    const double waveform_data_array[] = {1, 0, 0, 1};
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    for (double waveform_data : waveform_data_array) {
      request.add_waveform_data_array(waveform_data);
    }
    fgen::CreateWaveformF64Response response;

    ::grpc::Status status = GetStub()->CreateWaveformF64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.waveform_handle();
  }

  int create_advanced_arb_sequence(int32 sequence_length, int32* waveform_handles_array, int32* loop_counts_array, int32* marker_location_array)
  {
    ::grpc::ClientContext context;
    fgen::CreateAdvancedArbSequenceRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.mutable_waveform_handles_array()->Add(waveform_handles_array, waveform_handles_array + sequence_length);
    request.mutable_loop_counts_array()->Add(loop_counts_array, loop_counts_array + sequence_length);
    request.mutable_marker_location_array()->Add(marker_location_array, marker_location_array + sequence_length);
    fgen::CreateAdvancedArbSequenceResponse response;

    ::grpc::Status status = GetStub()->CreateAdvancedArbSequence(&context, request, &response);

    EXPECT_TRUE(status.ok());
    return response.status();
  }

  void allocate_named_waveform(std::string channel_name, std::string waveform_name, int waveform_size)
  {
    ::grpc::ClientContext context;
    fgen::AllocateNamedWaveformRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_waveform_name(waveform_name);
    request.set_waveform_size(waveform_size);
    fgen::AllocateNamedWaveformResponse response;

    ::grpc::Status status = GetStub()->AllocateNamedWaveform(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  int32 write_named_waveform_f64(std::string channel_name, std::string waveform_name, int waveform_size, double waveform[])
  {
    ::grpc::ClientContext context;
    fgen::WriteNamedWaveformF64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_waveform_name(waveform_name);
    request.mutable_data()->CopyFrom(google::protobuf::RepeatedField<double>(waveform, waveform + waveform_size));
    fgen::WriteNamedWaveformF64Response response;

    ::grpc::Status status = GetStub()->WriteNamedWaveformF64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    return response.status();
  }

  int32 allocate_waveform(std::string channel_name, int waveform_size)
  {
    ::grpc::ClientContext context;
    fgen::AllocateWaveformRequest request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_waveform_size(waveform_size);
    fgen::AllocateWaveformResponse response;

    ::grpc::Status status = GetStub()->AllocateWaveform(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.waveform_handle();
  }

  int32 write_waveform_complexf64(std::string channel_name, int waveform_size, int waveform_handle, std::vector<nidevice_grpc::NIComplexNumber> waveform)
  {
    ::grpc::ClientContext context;
    fgen::WriteWaveformComplexF64Request request;
    request.mutable_vi()->set_name(GetSessionName());
    request.set_channel_name(channel_name);
    request.set_waveform_handle(waveform_handle);
    for (int i = 0; i < waveform_size; i++) {
      request.mutable_data()->Add();
      request.mutable_data(i)->set_imaginary(waveform[i].imaginary());
      request.mutable_data(i)->set_real(waveform[i].real());
    }
    fgen::WriteWaveformComplexF64Response response;

    ::grpc::Status status = GetStub()->WriteWaveformComplexF64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    return response.status();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<fgen::NiFgen::Stub> nifgen_stub_;
};

std::vector<nidevice_grpc::NIComplexNumber> complex_number_array(
    std::vector<double> reals,
    std::vector<double> imaginaries)
{
  return complex_array<double, nidevice_grpc::NIComplexNumber>(reals, imaginaries);
}

TEST_F(NiFgenDriverApiTest, PerformSelfTest_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  fgen::SelfTestRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  fgen::SelfTestResponse response;
  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_EQ("", response.self_test_message());
}

TEST_F(NiFgenDriverApiTest, PerformReset_CompletesSuccessfuly)
{
  ::grpc::ClientContext context;
  fgen::ResetRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  fgen::ResetResponse response;
  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiFgenDriverApiTest, SetAttributeViInt32_GetAttributeViInt32_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttribute attribute_to_set = fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_OUTPUT_MODE;
  const auto expected_value = fgen::NiFgenInt32AttributeValues::NIFGEN_INT32_OUTPUT_MODE_VAL_OUTPUT_ARB;
  ::grpc::ClientContext context;
  fgen::SetAttributeViInt32Request request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value(expected_value);
  fgen::SetAttributeViInt32Response response;
  ::grpc::Status status = GetStub()->SetAttributeViInt32(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  int32 get_attribute_value = get_int32_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiFgenDriverApiTest, SetAttributeViReal64_GetAttributeViReal64_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttribute attribute_to_set = fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_DIGITAL_GAIN;
  const double expected_value = -1.0;
  ::grpc::ClientContext context;
  fgen::SetAttributeViReal64Request request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  fgen::SetAttributeViReal64Response response;
  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  double get_attribute_value_sourcedelay = get_real64_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value_sourcedelay);
}

TEST_F(NiFgenDriverApiTest, SetAttributeViBoolean_GetAttributeViBoolean_ValueMatches)
{
  const char* channel_name = "0";
  const fgen::NiFgenAttribute attribute_to_set = fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_OUTPUT_ENABLED;
  const bool expected_value = true;
  set_bool_attribute(channel_name, attribute_to_set, expected_value);

  bool get_attribute_value = get_bool_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiFgenDriverApiTest, SetAttributeViString_GetAttributeViString_ValueMatches)
{
  const char* channel_name = "";
  const fgen::NiFgenAttribute attribute_to_set = fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_MARKER_EVENT_OUTPUT_TERMINAL;
  const std::string expected_value = "sample";
  ::grpc::ClientContext context;
  fgen::SetAttributeViStringRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  fgen::SetAttributeViStringResponse response;
  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);
  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());

  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);

  EXPECT_STREQ(expected_value.c_str(), get_attribute_value.c_str());
}

TEST_F(NiFgenDriverApiTest, ConfigureTriggerMode_ConfiguresSuccessfully)
{
  const char* channel_name = "0";
  int32 expected_value = 2;  // NIFGEN_VAL_CONTINUOUS
  configure_trigger_mode(channel_name, fgen::TriggerMode::TRIGGER_MODE_NIFGEN_VAL_CONTINUOUS);

  int32 actual_trigger_mode = get_int32_attribute(channel_name, fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_TRIGGER_MODE);
  EXPECT_EQ(expected_value, actual_trigger_mode);
}

TEST_F(NiFgenDriverApiTest, ResetInterchangeCheck_ResetsSuccessfully)
{
  const char* channel_name = "0";
  double expected_current_level = 3.0;
  ::grpc::ClientContext context;
  fgen::ResetInterchangeCheckRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  fgen::ResetInterchangeCheckResponse response;
  ::grpc::Status status = GetStub()->ResetInterchangeCheck(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiFgenDriverApiTest, SendSoftwareEdgeTrigger_TriggersSuccessfully)
{
  ::grpc::ClientContext context;
  fgen::SendSoftwareEdgeTriggerRequest request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_trigger(fgen::Trigger::TRIGGER_NIFGEN_VAL_SCRIPT_TRIGGER);
  request.set_trigger_id("ScriptTrigger0");
  fgen::SendSoftwareEdgeTriggerResponse response;
  ::grpc::Status status = GetStub()->SendSoftwareEdgeTrigger(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiFgenDriverApiTest, AllocateNamedWaveform_WriteNamedWaveformF64_WaveformWrittenSuccessfully)
{
  std::string channel_name = "0";
  std::string waveform_name = "TestWaveform";
  int waveform_size = 5;
  configure_output_mode(channel_name.c_str(), fgen::OutputMode::OUTPUT_MODE_NIFGEN_VAL_OUTPUT_SCRIPT);
  allocate_named_waveform(channel_name, waveform_name, waveform_size);

  double waveform[] = {1.55, 40.4, 21.6, 0.7, 15.89};
  int32 status = write_named_waveform_f64(channel_name, waveform_name, waveform_size, waveform);

  expect_api_success(status);
}

TEST_F(NiFgenDriverApiTest, ExportTriggerMode_ResetAndImportConfiguration_TriggerModeConfigurationIsImported)
{
  const char* channel_name = "0";
  int32 expected_trigger_mode = 1;  // NIFGEN_VAL_SINGLE
  configure_trigger_mode(channel_name, fgen::TriggerMode::TRIGGER_MODE_NIFGEN_VAL_SINGLE);
  auto exported_configuration_response = export_attribute_configuration_buffer();

  reset();
  import_attribute_configuration_buffer(exported_configuration_response);

  double set_trigger_mode = get_int32_attribute(channel_name, fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_TRIGGER_MODE);
  EXPECT_EQ(expected_trigger_mode, set_trigger_mode);
}

TEST_F(NiFgenDriverApiTest, AllocateWaveform_WriteWaveformComplexF64_WaveformWrittenSuccessfully)
{
#ifndef WIN32
  GTEST_SKIP() << "The Onboard Signal Processing (OSP) functionality of the PXI-5441 is not supported on Linux.";
#endif
  std::string channel_name = "0";
  int waveform_size = 5;
  configure_output_mode(channel_name.c_str(), fgen::OutputMode::OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB);
  int waveform_handle = allocate_waveform(channel_name, waveform_size);

  set_bool_attribute(channel_name.c_str(), fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_OSP_ENABLED, true);
  set_int32_attribute(channel_name.c_str(), fgen::NiFgenAttribute::NIFGEN_ATTRIBUTE_OSP_DATA_PROCESSING_MODE, fgen::NiFgenInt32AttributeValues::NIFGEN_INT32_DATA_PROCESSING_MODE_VAL_OSP_COMPLEX);
  int32 status = write_waveform_complexf64(channel_name, waveform_size, waveform_handle, complex_number_array({1.55, 40.4, 21.6, 0.7, 15.89}, {2.3, -20.4, 112.4, -100.3, 0.0}));

  expect_api_success(status);
}

TEST_F(NiFgenDriverApiTest, OutputModeConfiguredToSeq_CreateAdvancedArbSequenceForArbitraryWaveform_CreatesSuccessfully)
{
  const char* channel_name = "0";
  int32 sequence_length = 1;
  int32 waveform_handles_array[1];
  int32 loop_counts_array[] = {1};
  int32 marker_location_array[] = {-1};
  configure_output_mode(channel_name, fgen::OutputMode::OUTPUT_MODE_NIFGEN_VAL_OUTPUT_SEQ);

  waveform_handles_array[0] = create_arb_waveform(channel_name);
  int status = create_advanced_arb_sequence(sequence_length, waveform_handles_array, loop_counts_array, marker_location_array);

  expect_api_success(status);
}

TEST_F(NiFgenDriverApiTest, OutputModeConfiguredToArb_CreateWaveformI16_CreatesSuccessfully)
{
  const char* channel_name = "0";
  const int16 waveform_data_array[] = {0, 1, 0, 1};
  configure_output_mode(channel_name, fgen::OutputMode::OUTPUT_MODE_NIFGEN_VAL_OUTPUT_ARB);

  ::grpc::ClientContext context;
  fgen::CreateWaveformI16Request request;
  request.mutable_vi()->set_name(GetSessionName());
  request.set_channel_name(channel_name);
  for (auto waveform_data : waveform_data_array) {
    request.add_waveform_data_array(waveform_data);
  }
  fgen::CreateWaveformI16Response response;
  ::grpc::Status status = GetStub()->CreateWaveformI16(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
