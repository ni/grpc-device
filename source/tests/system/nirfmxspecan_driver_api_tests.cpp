#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfmxspecan/nirfmxspecan_service.h"

using namespace nirfmxspecan_grpc;
namespace client = nirfmxspecan_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663 = "5663";

const int krfmxSpecAnDriverApiSuccess = 0;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfmxSpecAnDriverApiSuccess, response.status());
}

template <typename TResponse>
void EXPECT_RFMX_ERROR(pb::int32 expected_error, const TResponse& response)
{
  EXPECT_EQ(expected_error, response.status());
}

class NiRFmxSpecAnDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxSpecAnDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxspecan_stub_(NiRFmxSpecAn::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxSpecAnDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<NiRFmxSpecAn::Stub>& stub()
  {
    return nirfmxspecan_stub_;
  }

  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
    if (response.status() != krfmxSpecAnDriverApiSuccess) {
      auto error_message_response = client::get_error_string(stub(), session, response.status());
      EXPECT_EQ("", error_message_response.error_description());
    }
    check_error(session);
  }

  template <typename TResponse>
  void EXPECT_RFMX_ERROR(pb::int32 expected_error, const std::string& message_substring, const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_RFMX_ERROR(expected_error, response);
    const auto error = client::get_error(stub(), session);
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring));
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxSpecAn::Stub> nirfmxspecan_stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, resource_name, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto response = init(stub, model, resource_name);
  auto session = response.instrument();
  EXPECT_SUCCESS(response);
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
}

template <typename TFloat, typename TComplex>
TComplex complex(TFloat real, TFloat imaginary)
{
  auto c = TComplex{};
  c.set_real(real);
  c.set_imaginary(imaginary);
  return c;
}

template <typename TComplex>
struct TestWaveform {
  double t0;
  double dt;
  std::vector<TComplex> data;
};

template <typename TFloat>
struct TestIQData {
  double t0;
  double dt;
  std::vector<TFloat> I;
  std::vector<TFloat> Q;
};

template <typename TFloat, typename TComplex>
std::vector<TComplex> complex_array(
    std::vector<TFloat> reals,
    std::vector<TFloat> imaginaries)
{
  auto c = std::vector<TComplex>{};
  c.reserve(reals.size());
  std::transform(
      reals.begin(),
      reals.end(),
      imaginaries.begin(),
      std::back_inserter(c),
      [](TFloat real, TFloat imaginary) { return complex<TFloat, TComplex>(real, imaginary); });
  return c;
}

std::vector<nidevice_grpc::NIComplexNumberF32> complex_f32_array(
    std::vector<float> reals,
    std::vector<float> imaginaries)
{
  return complex_array<float, nidevice_grpc::NIComplexNumberF32>(reals, imaginaries);
}

std::vector<nidevice_grpc::NIComplexNumber> complex_number_array(
    std::vector<double> reals,
    std::vector<double> imaginaries)
{
  return complex_array<double, nidevice_grpc::NIComplexNumber>(reals, imaginaries);
}

template <typename TFloat>
TestIQData<TFloat> load_test_iq_data(const std::string& file_name)
{
  std::ifstream input_stream(file_name);
  auto json = nlohmann::json::parse(input_stream);
  auto t0 = json.find("t0")->get<double>();
  auto dt = json.find("dt")->get<double>();
  auto reals = json.find("reals")->get<std::vector<TFloat>>();
  auto imaginaries = json.find("imaginaries")->get<std::vector<TFloat>>();
  return {t0, dt, reals, imaginaries};
}

template <typename TFloat, typename TComplex>
TestWaveform<TComplex> load_test_waveform_data(const std::string& file_name)
{
  const auto iq_data = load_test_iq_data<TFloat>(file_name);
  return {iq_data.t0, iq_data.dt, complex_array<TFloat, TComplex>(iq_data.I, iq_data.Q)};
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpectrumBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0, 0));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1e6));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", true, 100e3, SpectrumRbwFilterType::SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", false, 10, SpectrumAveragingType::SPECTRUM_AVERAGING_TYPE_RMS));

  auto read_response = client::spectrum_read(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, read_response);
  // Make sure the data looks roughly correct
  EXPECT_EQ(1005, read_response.actual_array_size());
  EXPECT_EQ(1005, read_response.spectrum_size());
  EXPECT_EQ(1005, read_response.spectrum().size());
  int midpoint_x = 1005 / 2;
  EXPECT_LT(read_response.spectrum(0), read_response.spectrum(midpoint_x));
  EXPECT_LT(read_response.spectrum(1004), read_response.spectrum(midpoint_x));
}

TEST_F(NiRFmxSpecAnDriverApiTests, AcpBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string("")));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", false, 10, AcpAveragingType::ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_carrier_and_offsets(stub(), session, "", 1e6, 2, 1e6));

  const auto read_response = client::acp_read(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, read_response);

  EXPECT_GT(read_response.carrier_absolute_power(), 0.0);
  EXPECT_LT(read_response.offset_ch0_lower_relative_power(), 0.0);
  EXPECT_LT(read_response.offset_ch0_upper_relative_power(), 0.0);
  EXPECT_LT(read_response.offset_ch1_lower_relative_power(), 0.0);
  EXPECT_LT(read_response.offset_ch1_upper_relative_power(), 0.0);
}

TEST_F(NiRFmxSpecAnDriverApiTests, FcntBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_averaging(stub(), session, "", false, 10, FcntAveragingType::FCNT_AVERAGING_TYPE_MEAN));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_rbw_filter(stub(), session, "", 100e3, FcntRbwFilterType::FCNT_RBW_FILTER_TYPE_NONE, 0.1));

  const auto read_response = client::f_cnt_read(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, read_response);

  EXPECT_GT(read_response.average_relative_frequency(), 0.0);
  EXPECT_GT(read_response.average_absolute_frequency(), read_response.average_relative_frequency());
  EXPECT_GT(read_response.mean_phase(), 0.0);
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpurBasicFromExample_ReturnsMeasurementStatusFail)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_SPUR, true));
  EXPECT_SUCCESS(session, client::spur_cfg_number_of_ranges(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::spur_cfg_range_frequency_array(stub(), session, "", {1e9}, {1.5e9}, {true}));
  EXPECT_SUCCESS(session, client::spur_cfg_range_rbw_array(stub(), session, "", {false}, {30e3}, {SpurRbwFilterType::SPUR_RBW_FILTER_TYPE_GAUSSIAN}));
  EXPECT_SUCCESS(session, client::spur_cfg_range_absolute_limit_array(stub(), session, "", {}, {-10.0}, {}));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = client::spur_fetch_measurement_status(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, fetch_response);
  EXPECT_EQ(SpurMeasurementStatus::SPUR_MEASUREMENT_STATUS_FAIL, fetch_response.measurement_status());
}

TEST_F(NiRFmxSpecAnDriverApiTests, HarmFromExample_NoError)
{
  constexpr auto NUMBER_OF_HARMONICS = 3;
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_HARMONICS, true));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_rbw(stub(), session, "", 100e3, HarmRbwFilterType::HARM_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::harm_cfg_auto_harmonics(stub(), session, "", true));
  EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", NUMBER_OF_HARMONICS));
  EXPECT_SUCCESS(session, client::harm_cfg_averaging(stub(), session, "", false, 10, HarmAveragingType::HARM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_thd_response = client::harm_fetch_thd(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, fetch_thd_response);
  const auto fetch_measurement_response = client::harm_fetch_harmonic_measurement_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, fetch_measurement_response);
  for (auto i = 0; i < NUMBER_OF_HARMONICS; ++i) {
    const auto harmonic_string_response = client::build_harmonic_string(stub(), "", i);
    EXPECT_SUCCESS(session, harmonic_string_response);
    const auto power_trace_response = client::harm_fetch_harmonic_power_trace(stub(), session, harmonic_string_response.selector_string_out(), 10.0);
    EXPECT_SUCCESS(session, power_trace_response);
  }
}

TEST_F(NiRFmxSpecAnDriverApiTests, AMPMFromExample_NoError)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(
      session,
      client::cfg_digital_edge_trigger(stub(), session, "", DigitalEdgeTriggerSource::DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DigitalEdgeTriggerEdge::DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, true));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_AMPM, true));
  EXPECT_SUCCESS(session, client::dpd_cfg_dut_average_input_power(stub(), session, "", -20.0));
  EXPECT_SUCCESS(
      session,
      client::ampm_cfg_reference_waveform(
          stub(),
          session,
          "",
          0.0,
          0.1,
          // Note: this is random data.
          complex_f32_array({0.7f, 0.5f, 0.0f, -0.5f, -0.7f}, {-1.5f, -1.7f, -2.0f, -2.3f, -2.5f}),
          false,
          AmpmSignalType::AMPM_SIGNAL_TYPE_MODULATED));
  EXPECT_SUCCESS(session, client::ampm_cfg_measurement_sample_rate(stub(), session, "", AmpmMeasurementSampleRateMode::AMPM_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM, 120e6));
  EXPECT_SUCCESS(session, client::ampm_cfg_measurement_interval(stub(), session, "", 100e-6));
  EXPECT_SUCCESS(session, client::ampm_cfg_threshold(stub(), session, "", true, -20.0, AmpmThresholdType::AMPM_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::ampm_cfg_reference_power_type(stub(), session, "", AmpmReferencePowerType::AMPM_REFERENCE_POWER_TYPE_INPUT));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 20e6, 100e-6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto dut_char_response = client::ampm_fetch_dut_characteristics(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, dut_char_response);
  const auto error_response = client::ampm_fetch_error(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, error_response);
  const auto curve_fit_response = client::ampm_fetch_curve_fit_residual(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, curve_fit_response);
  const auto am_to_am_response = client::ampm_fetch_am_to_am_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, am_to_am_response);
}

TEST_F(NiRFmxSpecAnDriverApiTests, LutDpdFromExample_ReturnsSynchronizationNotFoundWarningWithData)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DigitalEdgeTriggerSource::DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DigitalEdgeTriggerEdge::DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, true));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_DPD, true));
  auto waveform = load_test_waveform_data<float, nidevice_grpc::NIComplexNumberF32>("LTE20MHz Waveform (Two Subframes).json");
  EXPECT_SUCCESS(session, client::dpd_cfg_reference_waveform(stub(), session, "", waveform.t0, waveform.dt, waveform.data, false, DpdSignalType::DPD_SIGNAL_TYPE_MODULATED));
  EXPECT_SUCCESS(session, client::dpd_cfg_dut_average_input_power(stub(), session, "", 1e9));
  EXPECT_SUCCESS(session, client::dpd_cfg_dpd_model(stub(), session, "", DpdModel::DPD_MODEL_LOOKUP_TABLE));
  EXPECT_SUCCESS(session, client::dpd_cfg_lookup_table_threshold(stub(), session, "", true, -20.0, DpdLookupTableThresholdType::DPD_LOOKUP_TABLE_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::dpd_cfg_lookup_table_step_size(stub(), session, "", 0.1));
  EXPECT_SUCCESS(session, client::dpd_cfg_measurement_interval(stub(), session, "", 100e-6));
  EXPECT_SUCCESS(session, client::dpd_cfg_measurement_sample_rate(stub(), session, "", DpdMeasurementSampleRateMode::DPD_MEASUREMENT_SAMPLE_RATE_MODE_REFERENCE_WAVEFORM, 120e6));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", -14.00));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  EXPECT_SUCCESS(session, client::dpd_cfg_apply_dpd_lookup_table_correction_type(stub(), session, "", DpdApplyDpdLookupTableCorrectionType::DPD_APPLY_DPD_LOOKUP_TABLE_CORRECTION_TYPE_MAGNITUDE_AND_PHASE));

  const auto apply_response = client::dpd_apply_digital_predistortion(stub(), session, "", waveform.t0, waveform.dt, waveform.data, false, 10.0);
  EXPECT_RFMX_ERROR(377652, "Synchronization not found", session, apply_response);
  EXPECT_THAT(apply_response.waveform_out(), Not(IsEmpty()));
}

// Note: there aren't any complex attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeComplex_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_RFMX_ERROR(
      -380231, "This attribute is read-only and cannot be written", session,
      client::set_attribute_ni_complex_double_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_SEM_RESULTS_CARRIER_FREQUENCY, complex_number_array({1.2, 2.2}, {1e6, 1.01e6})));
}

// Note: there aren't any i8 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeInt8_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_i8(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, 1));
  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_u8(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, 1));
  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_i8_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, {1, 0, -1, 0}));
  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_u8_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, {1, 0, 1, 0}));
}

// Note: there aren't any i16 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeInt16_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_i16(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, -400));
  EXPECT_RFMX_ERROR(
      -380251, "Incorrect data type specified", session,
      client::set_attribute_u16(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, 400));
}

TEST_F(NiRFmxSpecAnDriverApiTests, SetAndGetAttributeInt32_Succeeds)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(
      session,
      client::set_attribute_i32(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_NF_EXTERNAL_PREAMP_PRESENT_TRUE));
  // This is one way to get the driver in a state where we can get attributes
  EXPECT_SUCCESS(session, client::spectrum_read(stub(), session, "", 10.0));

  auto get_response = client::get_attribute_i32(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT);

  EXPECT_SUCCESS(session, get_response);
  EXPECT_EQ(NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_NF_EXTERNAL_PREAMP_PRESENT_TRUE, get_response.attr_val());
}

TEST_F(NiRFmxSpecAnDriverApiTests, SetAndGetAttributeString_Succeeds)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(
      session,
      client::set_attribute_string(
          stub(),
          session,
          "",
          NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_DIGITAL_EDGE_TRIGGER_SOURCE,
          NiRFmxSpecAnStringAttributeValuesMapped::NIRFMXSPECAN_STRING_DIGITAL_EDGE_TRIGGER_SOURCE_PFI0));
  // This is one way to get the driver in a state where we can get attributes
  EXPECT_SUCCESS(session, client::spectrum_read(stub(), session, "", 10.0));

  auto get_response = client::get_attribute_string(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_DIGITAL_EDGE_TRIGGER_SOURCE);

  EXPECT_SUCCESS(session, get_response);
  EXPECT_EQ("PFI0", get_response.attr_val());
}

TEST_F(NiRFmxSpecAnDriverApiTests, BuildSpurString_ReturnsSpurString)
{
  auto session = init_session(stub(), PXI_5663);
  const auto spur_string_response = client::build_spur_string(stub(), "", 0);
  EXPECT_EQ(spur_string_response.selector_string_out(), "spur0");

  EXPECT_SUCCESS(session, spur_string_response);
}


/**************************** Basic ****************************/


// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_AcpFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "niRFSA_init" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_AcpAnalysisOnlyFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, AcpBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored acp_read_response.offset_ch1_upper_relative_power
  // TODO: Conversion process ignored acp_read_response.offset_ch1_lower_relative_power
  // TODO: Conversion process ignored acp_read_response.offset_ch0_upper_relative_power
  // TODO: Conversion process ignored acp_read_response.offset_ch0_lower_relative_power
  // TODO: Conversion process ignored acp_read_response.carrier_absolute_power
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_carrier_and_offsets(stub(), session, "", 1.0e+6, 2, 1.0e+6));

  EXPECT_SUCCESS(session, client::acp_read(stub(), session, "", 10));
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_AcpDynamicRangeFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, AcpFromConfigurationFileFromExample_FetchData_DataLooksReasonable)
{
  char configurationFilePath[] = "..\\Support\\SpecAn_Configurations.tdms";
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::load_all_configurations(instr_stub, session, configurationFilePath, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 x0 = 0.0;
  float64 dx = 0.0;
  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  const auto acp_fetch_carrier_measurement_response = client::acp_fetch_carrier_measurement(stub(), session, "", 10.0);
  x0 = 0.0;
  dx = 0.0;
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.total_relative_power());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.carrier_offset());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.integration_bandwidth());
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.spectrum(0));
}

// NOTE: disabled due to "ReadFromTDMSFile" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_AmpmFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, CcdfFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CCDF, true));
  EXPECT_SUCCESS(session, client::ccdf_cfg_number_of_records(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::ccdf_cfg_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::ccdf_cfg_rbw_filter(stub(), session, "", 100.0e+3, CCDF_RBW_FILTER_TYPE_NONE, 0.010));
  EXPECT_SUCCESS(session, client::ccdf_cfg_threshold(stub(), session, "", CCDF_THRESHOLD_ENABLED_FALSE, -20.00, CCDF_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 x0 = 0.0;
  float64 dx = 0.0;
  const auto ccdf_fetch_power_response = client::ccdf_fetch_power(stub(), session, "", 10.0);
  const auto ccdf_fetch_basic_power_probabilities_response = client::ccdf_fetch_basic_power_probabilities(stub(), session, "", 10.0);
  const auto ccdf_fetch_gaussian_probabilities_trace_response = client::ccdf_fetch_gaussian_probabilities_trace(stub(), session, "", 10.0);
  x0 = 0.0;
  dx = 0.0;
  const auto ccdf_fetch_probabilities_trace_response = client::ccdf_fetch_probabilities_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ccdf_fetch_power_response);
  EXPECT_EQ(0.0, ccdf_fetch_power_response.mean_power());
  EXPECT_EQ(0.0, ccdf_fetch_power_response.mean_power_percentile());
  EXPECT_EQ(0.0, ccdf_fetch_power_response.peak_power());
  EXPECT_EQ(0, ccdf_fetch_power_response.measured_samples_count());
  EXPECT_SUCCESS(session, ccdf_fetch_basic_power_probabilities_response);
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.ten_percent_power());
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.one_percent_power());
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.one_tenth_percent_power());
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.one_hundredth_percent_power());
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.one_thousandth_percent_power());
  EXPECT_EQ(0.0, ccdf_fetch_basic_power_probabilities_response.one_ten_thousandth_percent_power());
  EXPECT_SUCCESS(session, ccdf_fetch_gaussian_probabilities_trace_response);
  EXPECT_EQ(0.0, ccdf_fetch_gaussian_probabilities_trace_response.x0());
  EXPECT_EQ(0.0, ccdf_fetch_gaussian_probabilities_trace_response.dx());
  EXPECT_EQ(999, ccdf_fetch_gaussian_probabilities_trace_response.gaussian_probabilities_size());
  EXPECT_EQ(999, ccdf_fetch_gaussian_probabilities_trace_response.gaussian_probabilities().size());
  EXPECT_EQ(0.0, ccdf_fetch_gaussian_probabilities_trace_response.gaussian_probabilities(0));
  EXPECT_SUCCESS(session, ccdf_fetch_probabilities_trace_response);
  EXPECT_EQ(0.0, ccdf_fetch_probabilities_trace_response.x0());
  EXPECT_EQ(0.0, ccdf_fetch_probabilities_trace_response.dx());
  EXPECT_EQ(999, ccdf_fetch_probabilities_trace_response.probabilities_size());
  EXPECT_EQ(999, ccdf_fetch_probabilities_trace_response.probabilities().size());
  EXPECT_EQ(0.0, ccdf_fetch_probabilities_trace_response.probabilities(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, CcdfBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored ccdf_read_response.measured_samples_count
  // TODO: Conversion process ignored ccdf_read_response.peak_power
  // TODO: Conversion process ignored ccdf_read_response.mean_power_percentile
  // TODO: Conversion process ignored ccdf_read_response.mean_power
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CCDF, true));
  EXPECT_SUCCESS(session, client::ccdf_cfg_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_CCDF_RBW_FILTER_BANDWIDTH, 100.0e+3));

  EXPECT_SUCCESS(session, client::ccdf_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, ChpFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_integration_bandwidth(stub(), session, "", 1.0e+6));
  EXPECT_SUCCESS(session, client::chp_cfg_span(stub(), session, "", 1.0e+6));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.00e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::chp_cfg_rbw_filter(stub(), session, "", CHP_RBW_AUTO_BANDWIDTH_TRUE, 10.0e+3, CHP_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::chp_cfg_fft(stub(), session, "", CHP_FFT_WINDOW_FLAT_TOP, -1.0));
  EXPECT_SUCCESS(session, client::chp_cfg_rrc_filter(stub(), session, "", CHP_CARRIER_RRC_FILTER_ENABLED_FALSE, 0.220));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);
  const auto chp_fetch_carrier_measurement_response = client::chp_fetch_carrier_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, chp_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, chp_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_carrier_measurement_response.psd());
  EXPECT_EQ(0.0, chp_fetch_carrier_measurement_response.relative_power());
}

TEST_F(NiRFmxSpecAnDriverApiTests, ChpBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored chp_read_response.psd
  // TODO: Conversion process ignored chp_read_response.absolute_power
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::chp_cfg_integration_bandwidth(stub(), session, "", 1.0e+6));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));

  EXPECT_SUCCESS(session, client::chp_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, FcntFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_FCNT, true));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_rbw_filter(stub(), session, "", 100e+3, FCNT_RBW_FILTER_TYPE_NONE, 0.10));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_averaging(stub(), session, "", FCNT_AVERAGING_ENABLED_FALSE, 10, FCNT_AVERAGING_TYPE_MEAN));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_threshold(stub(), session, "", FCNT_THRESHOLD_ENABLED_FALSE, -20.00, FCNT_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto f_cnt_fetch_frequency_trace_response = client::f_cnt_fetch_frequency_trace(stub(), session, "", 10.0);
  const auto f_cnt_fetch_measurement_response = client::f_cnt_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, f_cnt_fetch_frequency_trace_response);
  EXPECT_EQ(0.0, f_cnt_fetch_frequency_trace_response.x0());
  EXPECT_EQ(0.0, f_cnt_fetch_frequency_trace_response.dx());
  EXPECT_EQ(999, f_cnt_fetch_frequency_trace_response.frequency_trace_size());
  EXPECT_EQ(999, f_cnt_fetch_frequency_trace_response.frequency_trace().size());
  EXPECT_EQ(0.0, f_cnt_fetch_frequency_trace_response.frequency_trace(0));
  EXPECT_SUCCESS(session, f_cnt_fetch_measurement_response);
  EXPECT_EQ(0.0, f_cnt_fetch_measurement_response.average_relative_frequency());
  EXPECT_EQ(0.0, f_cnt_fetch_measurement_response.average_absolute_frequency());
  EXPECT_EQ(0.0, f_cnt_fetch_measurement_response.mean_phase());
}

TEST_F(NiRFmxSpecAnDriverApiTests, FcntBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored f_cnt_read_response.mean_phase
  // TODO: Conversion process ignored f_cnt_read_response.average_absolute_frequency
  // TODO: Conversion process ignored f_cnt_read_response.average_relative_frequency
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_averaging(stub(), session, "", FCNT_AVERAGING_ENABLED_FALSE, 10, FCNT_AVERAGING_TYPE_MEAN));
  EXPECT_SUCCESS(session, client::f_cnt_cfg_rbw_filter(stub(), session, "", 100e+3, FCNT_RBW_FILTER_TYPE_NONE, 0.1));

  EXPECT_SUCCESS(session, client::f_cnt_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, HarmFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_HARMONICS = 3;
  int32 autoHarmonicsSetup = RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE;
  int32 numberOfHormonics = NUMBER_OF_HARMONICS;
  std::vector<int> enabledArray(NUMBER_OF_HARMONICS);
  std::vector<int> harmonicOrderArray(NUMBER_OF_HARMONICS);
  std::vector<float64> bandwidthArray(NUMBER_OF_HARMONICS);
  std::vector<float64> measurementIntervalArray(NUMBER_OF_HARMONICS);
  for (i = 0; i < numberOfHormonics; i++)
  {
    enabledArray[i] = NIRFMXSPECAN_INT32_HARM_HARMONIC_ENABLED_TRUE;
    harmonicOrderArray[i] = i + 1;
    bandwidthArray[i] = 100.0e+3;
    measurementIntervalArray[i] = 1.0e-3;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.0e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_HARMONICS, true));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_rbw(stub(), session, "", 100.0e+3, HARM_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::harm_cfg_auto_harmonics(stub(), session, "", HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE));
  if (autoHarmonicsSetup == NIRFMXSPECAN_INT32_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE)
  {
    EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", NUMBER_OF_HARMONICS));
  }
  else
  {
    EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", NUMBER_OF_HARMONICS));
    EXPECT_SUCCESS(session, client::harm_cfg_harmonic_array(stub(), session, "", harmonicOrderArray, bandwidthArray, enabledArray, measurementIntervalArray));
  }
  EXPECT_SUCCESS(session, client::harm_cfg_averaging(stub(), session, "", HARM_AVERAGING_ENABLED_FALSE, 10, HARM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<float64> x0(NUMBER_OF_HARMONICS, 0);
  std::vector<float64> dx(NUMBER_OF_HARMONICS, 0);
  std::vector<float32*> power(NUMBER_OF_HARMONICS, 0);
  HarmFetchHarmonicPowerTraceResponse harm_fetch_harmonic_power_trace_response;
  const auto harm_fetch_thd_response = client::harm_fetch_thd(stub(), session, "", 10.0);
  const auto harm_fetch_harmonic_measurement_array_response = client::harm_fetch_harmonic_measurement_array(stub(), session, "", 10.0);
  for (int i = 0; i < numberOfHormonics; i++)
  {
    auto harmonic_string_response = client::build_harmonic_string(stub(), "", i);
    EXPECT_SUCCESS(session, harmonic_string_response);
    power[i] = (float32 *)NULL;
    x0[i] = 0.0;
    dx[i] = 0.0;
    harm_fetch_harmonic_power_trace_response = client::harm_fetch_harmonic_power_trace(stub(), session, harmonic_string_response.selector_string_out(), 10.0);
  }

  EXPECT_SUCCESS(session, harm_fetch_thd_response);
  EXPECT_EQ(0.0, harm_fetch_thd_response.total_harmonic_distortion());
  EXPECT_EQ(0.0, harm_fetch_thd_response.average_fundamental_power());
  EXPECT_EQ(0.0, harm_fetch_thd_response.fundamental_frequency());
  EXPECT_SUCCESS(session, harm_fetch_harmonic_measurement_array_response);
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_relative_power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_relative_power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.average_relative_power(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_absolute_power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_absolute_power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.average_absolute_power(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.rbw_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.rbw().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.rbw(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.frequency_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.frequency().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.frequency(0));
  EXPECT_SUCCESS(session, harm_fetch_harmonic_power_trace_response);
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.x0());
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.dx());
  EXPECT_EQ(999, harm_fetch_harmonic_power_trace_response.power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_power_trace_response.power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.power(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, HarmBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored harm_read_response.average_fundamental_power
  // TODO: Conversion process ignored harm_read_response.total_harmonic_distortion
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_rbw(stub(), session, "", 100e+3, HARM_RBW_FILTER_TYPE_GAUSSIAN, 0.1));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", 3));
  EXPECT_SUCCESS(session, client::harm_cfg_averaging(stub(), session, "", HARM_AVERAGING_ENABLED_FALSE, 10, HARM_AVERAGING_TYPE_RMS));

  EXPECT_SUCCESS(session, client::harm_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, HarmDynamicRangeFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_HARMONICS = 3;
  int32 autoHarmonicsSetup = RFMXSPECAN_VAL_HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE;
  int32 numberOfHarmonics = NUMBER_OF_HARMONICS;
  std::vector<int> harmonicEnabled(NUMBER_OF_HARMONICS);
  std::vector<int> harmonicOrder(NUMBER_OF_HARMONICS);
  std::vector<float64> harmonicBandwidth(NUMBER_OF_HARMONICS);
  std::vector<float64> harmonicMeasurementInterval(NUMBER_OF_HARMONICS);
  for (i = 0; i < numberOfHarmonics; i++)
  {
    harmonicEnabled[i] = NIRFMXSPECAN_INT32_HARM_HARMONIC_ENABLED_TRUE;
    harmonicOrder[i] = i + 1;
    harmonicBandwidth[i] = 100.0e+3;
    harmonicMeasurementInterval[i] = 1.0e-3;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_HARMONICS, true));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_rbw(stub(), session, "", 100e+3, HARM_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::harm_cfg_fundamental_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::harm_cfg_auto_harmonics(stub(), session, "", HARM_AUTO_HARMONICS_SETUP_ENABLED_TRUE));
  if (autoHarmonicsSetup)
  {
    EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", NUMBER_OF_HARMONICS));
  }
  else
  {
    EXPECT_SUCCESS(session, client::harm_cfg_number_of_harmonics(stub(), session, "", NUMBER_OF_HARMONICS));
    EXPECT_SUCCESS(session, client::harm_cfg_harmonic_array(stub(), session, "", harmonicOrder, harmonicBandwidth, harmonicEnabled, harmonicMeasurementInterval));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_HARM_MEASUREMENT_METHOD, NIRFMXSPECAN_INT32_HARM_MEASUREMENT_METHOD_DYNAMIC_RANGE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_HARM_NOISE_COMPENSATION_ENABLED, NIRFMXSPECAN_INT32_HARM_NOISE_COMPENSATION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::harm_cfg_averaging(stub(), session, "", HARM_AVERAGING_ENABLED_FALSE, 10, HARM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<float64> x0(NUMBER_OF_HARMONICS, 0);
  std::vector<float64> dx(NUMBER_OF_HARMONICS, 0);
  std::vector<float32*> power(NUMBER_OF_HARMONICS, 0);
  HarmFetchHarmonicPowerTraceResponse harm_fetch_harmonic_power_trace_response;
  const auto harm_fetch_thd_response = client::harm_fetch_thd(stub(), session, "", 10.0);
  const auto harm_fetch_harmonic_measurement_array_response = client::harm_fetch_harmonic_measurement_array(stub(), session, "", 10.0);
  int32 actualArraySize = harm_fetch_harmonic_measurement_array_response.average_relative_power_size();
  for (int i = 0; i < numberOfHarmonics; i++)
  {
    auto harmonic_string_response = client::build_harmonic_string(stub(), "", i);
    EXPECT_SUCCESS(session, harmonic_string_response);
    power[i] = (float32 *)NULL;
    x0[i] = 0.0;
    dx[i] = 0.0;
    harm_fetch_harmonic_power_trace_response = client::harm_fetch_harmonic_power_trace(stub(), session, harmonic_string_response.selector_string_out(), 10.0);
  }

  EXPECT_SUCCESS(session, harm_fetch_thd_response);
  EXPECT_EQ(0.0, harm_fetch_thd_response.total_harmonic_distortion());
  EXPECT_EQ(0.0, harm_fetch_thd_response.average_fundamental_power());
  EXPECT_EQ(0.0, harm_fetch_thd_response.fundamental_frequency());
  EXPECT_SUCCESS(session, harm_fetch_harmonic_measurement_array_response);
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_relative_power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_relative_power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.average_relative_power(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_absolute_power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.average_absolute_power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.average_absolute_power(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.rbw_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.rbw().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.rbw(0));
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.frequency_size());
  EXPECT_EQ(999, harm_fetch_harmonic_measurement_array_response.frequency().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_measurement_array_response.frequency(0));
  EXPECT_SUCCESS(session, harm_fetch_harmonic_power_trace_response);
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.x0());
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.dx());
  EXPECT_EQ(999, harm_fetch_harmonic_power_trace_response.power_size());
  EXPECT_EQ(999, harm_fetch_harmonic_power_trace_response.power().size());
  EXPECT_EQ(0.0, harm_fetch_harmonic_power_trace_response.power(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, IQFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", -20.0, IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_IQ, false));
  EXPECT_SUCCESS(session, client::iq_cfg_acquisition(stub(), session, "", 10e+6, 1, 0.001, 0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 meanPower = 0.0;
  nidevice_grpc::NIComplexNumberF32* data = NULL;
  int32 arraySize = 0;
  float64 powerInDbm = 0.0;
  float64 sampleRate = 10e+6;
  float64 acquisitionTime = 0.001;
  int32 actualArraySize = 0;
  float64 sum = 0.0;
  IQFetchDataResponse iq_fetch_data_response;
  arraySize = (int32)ceil(sampleRate * acquisitionTime) + 10;
  if (arraySize > 0)
  {
    data = (NIComplexSingle *)malloc(sizeof(NIComplexSingle) * arraySize);
    if (data)
    {
      iq_fetch_data_response = client::iq_fetch_data(stub(), session, "", 10.0, 0, -1);
      actualArraySize = iq_fetch_data_response.data_size();
    }
    else
    {
    }
  }
  for (int i = 0; i < actualArraySize; i++)
  {
    sum += (float64)((data[i].real * data[i].real) + (data[i].imaginary * data[i].imaginary));
  }
  meanPower = sum / (float64)actualArraySize;
  powerInDbm = 10 * log10((meanPower / (2 * 50)) / 0.001);

  EXPECT_SUCCESS(session, iq_fetch_data_response);
  EXPECT_EQ(0.0, iq_fetch_data_response.t0());
  EXPECT_EQ(0.0, iq_fetch_data_response.dt());
  EXPECT_EQ(0.0, iq_fetch_data_response.data(0).real());
  EXPECT_EQ(0.0, iq_fetch_data_response.data(0).imaginary());
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_ListModeWithSGSAHandshakingFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_ListModeWithTimeBasedSynchronizationFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "ReadFromTDMSFile" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_LutDpdFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, MarkerFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored marker_peak_search_response.number_of_peaks
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SPECTRUM, true));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", SPECTRUM_RBW_AUTO_BANDWIDTH_FALSE, 10.0e+3, SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1.0e+6));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", SPECTRUM_AVERAGING_ENABLED_FALSE, 10, SPECTRUM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int ch = 0;
  int menuBrkFlg = 0;
  int donotFetchFlg = 0;
  int32 peakToFetch = 0;
  int32 error = 0;
  int32 peakFound = 0;
  niRFmxInstrHandle instrumentHandle = NULL;
  int32 numberOfPeaks = 0;
  float64 markerXLocation = 0;
  float64 markerYLocation = 0;
  const auto spectrum_fetch_spectrum_response = client::spectrum_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, client::marker_cfg_threshold(stub(), session, "", MARKER_THRESHOLD_ENABLED_FALSE, -90));
  EXPECT_SUCCESS(session, client::marker_cfg_peak_excursion(stub(), session, "", MARKER_PEAK_EXCURSION_ENABLED_FALSE, 6));
  EXPECT_SUCCESS(session, client::marker_cfg_type(stub(), session, "marker0", MARKER_TYPE_NORMAL));
  EXPECT_SUCCESS(session, client::marker_cfg_trace(stub(), session, "marker0", MARKER_TRACE_SPECTRUM));
  EXPECT_SUCCESS(session, client::marker_peak_search(stub(), session, "marker0"));
  const auto marker_fetch_xy_response = client::marker_fetch_xy(stub(), session, "marker0");
  displayMarkerData(numberOfPeaks, peakFound, markerXLocation, markerYLocation);
  displayMarkerMenu();
  menuBrkFlg = 0;
  while (1)
  {
    ch = _getch();
    donotFetchFlg = 0;
    switch (ch)
    {
    case 'l':
    case 'L':
      peakToFetch = NIRFMXSPECAN_INT32_MARKER_NEXT_PEAK_NEXT_LEFT;
      break;
    case 'r':
    case 'R':
      peakToFetch = NIRFMXSPECAN_INT32_MARKER_NEXT_PEAK_NEXT_RIGHT;
      break;
    case 'h':
    case 'H':
      peakToFetch = NIRFMXSPECAN_INT32_MARKER_NEXT_PEAK_NEXT_HIGHEST;
      break;
    case 's':
    case 'S':
      menuBrkFlg = 1;
      donotFetchFlg = 1;
      break;
    default:
      donotFetchFlg = 1;
      displayMarkerMenu();
      break;
    }
    if (donotFetchFlg == 0)
    {
      error = RFmxSpecAn_MarkerNextPeak(instrumentHandle, "marker0", peakToFetch, &peakFound);
      if (error == 0)
      {
        error = RFmxSpecAn_MarkerFetchXY(instrumentHandle, "marker0", &markerXLocation, &markerYLocation);
        if (error == 0)
          displayMarkerData(numberOfPeaks, peakFound, markerXLocation, markerYLocation);
        else
          menuBrkFlg = 1;
      }
      else
        menuBrkFlg = 1;
    }

  EXPECT_SUCCESS(session, spectrum_fetch_spectrum_response);
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.dx());
  EXPECT_EQ(999, spectrum_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, spectrum_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, marker_fetch_xy_response);
  EXPECT_EQ(0.0, marker_fetch_xy_response.marker_x_location());
  EXPECT_EQ(0.0, marker_fetch_xy_response.marker_y_location());
}

// NOTE: disabled due to "ReadFromTDMSFile" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_MemoryDpdFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, NFColdSourceFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_POINTS = 10;
  const auto RFMXSPECAN_VAL_STEP = 0;
  int32 configureFrequencyList = RFMXSPECAN_VAL_STEP;
  int32 recommend = RFMXSPECAN_VAL_FALSE;
  // TODO: Conversion process ignored nf_recommend_reference_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_NF, false));
  EXPECT_SUCCESS(session, client::nf_cfg_measurement_method(stub(), session, "", NF_MEASUREMENT_METHOD_COLD_SOURCE));
  switch (configureFrequencyList)
  {
  case NIRFMXSPECAN_INT32_STEP:
    EXPECT_SUCCESS(session, client::nf_cfg_frequency_list_start_stop_step(stub(), session, "", 1E+9, 2E+9, 100E6));
    break;
  case NIRFMXSPECAN_INT32_POINTS:
    EXPECT_SUCCESS(session, client::nf_cfg_frequency_list_start_stop_points(stub(), session, "", 1E+9, 2E+9, NUMBER_OF_POINTS));
    break;
  case NIRFMXSPECAN_INT32_LIST:
    EXPECT_SUCCESS(session, client::nf_cfg_frequency_list(stub(), session, "", NULL));
    break;
  default:
    EXPECT_SUCCESS(session, client::nf_cfg_frequency_list_start_stop_step(stub(), session, "", 1E+9, 2E+9, 100E6));
  }
  EXPECT_SUCCESS(session, client::nf_cfg_measurement_bandwidth(stub(), session, "", 100E+3));
  EXPECT_SUCCESS(session, client::nf_cfg_measurement_interval(stub(), session, "", 1E-3));
  EXPECT_SUCCESS(session, client::nf_cfg_averaging(stub(), session, "", NF_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::nf_cfg_calibration_loss(stub(), session, "", NF_CALIBRATION_LOSS_COMPENSATION_ENABLED_FALSE, NULL, NULL, 297));
  EXPECT_SUCCESS(session, client::nf_cfg_dut_input_loss(stub(), session, "", NF_DUT_INPUT_LOSS_COMPENSATION_ENABLED_FALSE, NULL, NULL, 297));
  EXPECT_SUCCESS(session, client::nf_cfg_dut_output_loss(stub(), session, "", NF_DUT_OUTPUT_LOSS_COMPENSATION_ENABLED_FALSE, NULL, NULL, 297));
  EXPECT_SUCCESS(session, client::nf_cfg_cold_source_mode(stub(), session, "", NF_COLD_SOURCE_MODE_MEASURE));
  EXPECT_SUCCESS(session, client::nf_cfg_cold_source_duts_parameters(stub(), session, "", NULL, NULL, NULL, NULL, NULL));
  if (recommend)
  {
    EXPECT_SUCCESS(session, client::nf_recommend_reference_level(stub(), session, "", 0.00, 0.00));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", -55));
  }
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto nf_fetch_cold_source_power_response = client::nf_fetch_cold_source_power(stub(), session, "", 10.0);
  int32 actualArraySize = nf_fetch_cold_source_power_response.cold_source_power_size();
  const auto nf_fetch_analyzer_noise_figure_response = client::nf_fetch_analyzer_noise_figure(stub(), session, "", 10.0);
  actualArraySize = nf_fetch_analyzer_noise_figure_response.analyzer_noise_figure_size();
  const auto nf_fetch_dut_noise_figure_and_gain_response = client::nf_fetch_dut_noise_figure_and_gain(stub(), session, "", 10.0);
  actualArraySize = nf_fetch_dut_noise_figure_and_gain_response.dut_noise_figure_size();

  EXPECT_SUCCESS(session, nf_fetch_cold_source_power_response);
  EXPECT_EQ(999, nf_fetch_cold_source_power_response.cold_source_power_size());
  EXPECT_EQ(999, nf_fetch_cold_source_power_response.cold_source_power().size());
  EXPECT_EQ(0.0, nf_fetch_cold_source_power_response.cold_source_power(0));
  EXPECT_SUCCESS(session, nf_fetch_analyzer_noise_figure_response);
  EXPECT_EQ(999, nf_fetch_analyzer_noise_figure_response.analyzer_noise_figure_size());
  EXPECT_EQ(999, nf_fetch_analyzer_noise_figure_response.analyzer_noise_figure().size());
  EXPECT_EQ(0.0, nf_fetch_analyzer_noise_figure_response.analyzer_noise_figure(0));
  EXPECT_SUCCESS(session, nf_fetch_dut_noise_figure_and_gain_response);
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_figure_size());
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_figure().size());
  EXPECT_EQ(0.0, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_figure(0));
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_temperature_size());
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_temperature().size());
  EXPECT_EQ(0.0, nf_fetch_dut_noise_figure_and_gain_response.dut_noise_temperature(0));
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_gain_size());
  EXPECT_EQ(999, nf_fetch_dut_noise_figure_and_gain_response.dut_gain().size());
  EXPECT_EQ(0.0, nf_fetch_dut_noise_figure_and_gain_response.dut_gain(0));
}

// NOTE: disabled because not trivial
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_NFYFactorFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, ObwFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_bandwidth_percentage(stub(), session, "", 99.00));
  EXPECT_SUCCESS(session, client::obw_cfg_span(stub(), session, "", 1e+6));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1e-3));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::obw_cfg_rbw_filter(stub(), session, "", OBW_RBW_AUTO_BANDWIDTH_TRUE, 10e+3, OBW_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::obw_cfg_fft(stub(), session, "", OBW_FFT_WINDOW_FLAT_TOP, -1.00));
  EXPECT_SUCCESS(session, client::obw_cfg_power_units(stub(), session, "", OBW_POWER_UNITS_DBM));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_spectrum_trace_response = client::obw_fetch_spectrum_trace(stub(), session, "", 10.0);
  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, obw_fetch_spectrum_trace_response);
  EXPECT_EQ(0.0, obw_fetch_spectrum_trace_response.x0());
  EXPECT_EQ(0.0, obw_fetch_spectrum_trace_response.dx());
  EXPECT_EQ(999, obw_fetch_spectrum_trace_response.spectrum_size());
  EXPECT_EQ(999, obw_fetch_spectrum_trace_response.spectrum().size());
  EXPECT_EQ(0.0, obw_fetch_spectrum_trace_response.spectrum(0));
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_EQ(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.average_power());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.frequency_resolution());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.stop_frequency());
}

TEST_F(NiRFmxSpecAnDriverApiTests, ObwBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored obw_read_response.stop_frequency
  // TODO: Conversion process ignored obw_read_response.start_frequency
  // TODO: Conversion process ignored obw_read_response.frequency_resolution
  // TODO: Conversion process ignored obw_read_response.average_power
  // TODO: Conversion process ignored obw_read_response.occupied_bandwidth
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::obw_cfg_span(stub(), session, "", 1e+6));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));

  EXPECT_SUCCESS(session, client::obw_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, PAVTFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SEGMENTS = 1;
  const auto MEASUREMENT_START_TIME_TYPE_STEP = 0;
  int32 measurementLocationType = RFMXSPECAN_VAL_PAVT_MEASUREMENT_LOCATION_TYPE_TIME;
  std::vector<float64> segmentStartTime(, 0.0);
  int32 measurementStartTimeType = MEASUREMENT_START_TIME_TYPE_STEP;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.0e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PAVT, true));
  EXPECT_SUCCESS(session, client::pavt_cfg_measurement_location_type(stub(), session, "", PAVT_MEASUREMENT_LOCATION_TYPE_TIME));
  if (measurementLocationType == NIRFMXSPECAN_INT32_PAVT_MEASUREMENT_LOCATION_TYPE_TIME)
  {
    if (measurementStartTimeType == MEASUREMENT_START_TIME_TYPE_STEP)
    {
      EXPECT_SUCCESS(session, client::pavt_cfg_segment_start_time_step(stub(), session, "", NUMBER_OF_SEGMENTS, 0.0, 1.0e-3));
    }
    else
    {
      EXPECT_SUCCESS(session, client::pavt_cfg_number_of_segments(stub(), session, "", 1));
      EXPECT_SUCCESS(session, client::pavt_cfg_segment_start_time_list(stub(), session, "", segmentStartTime));
    }
  }
  else
  {
    EXPECT_SUCCESS(session, client::pavt_cfg_number_of_segments(stub(), session, "", NUMBER_OF_SEGMENTS));
  }
  EXPECT_SUCCESS(session, client::pavt_cfg_measurement_bandwidth(stub(), session, "", 10.0e6));
  EXPECT_SUCCESS(session, client::pavt_cfg_measurement_interval(stub(), session, "", 0.0, 1.0e-3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  PAVTFetchPhaseTraceResponse pavt_fetch_phase_trace_response;
  PAVTFetchAmplitudeTraceResponse pavt_fetch_amplitude_trace_response;
  const auto pavt_fetch_phase_and_amplitude_array_response = client::pavt_fetch_phase_and_amplitude_array(stub(), session, "", 10.0);
  for (int i = 0; i < NUMBER_OF_SEGMENTS; i++)
  {
    pavt_fetch_phase_trace_response = client::pavt_fetch_phase_trace(stub(), session, "", 10.0, i);
    pavt_fetch_amplitude_trace_response = client::pavt_fetch_amplitude_trace(stub(), session, "", 10.0, i);
  }

  EXPECT_SUCCESS(session, pavt_fetch_phase_and_amplitude_array_response);
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_relative_phase_size());
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_relative_phase().size());
  EXPECT_EQ(0.0, pavt_fetch_phase_and_amplitude_array_response.mean_relative_phase(0));
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_relative_amplitude_size());
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_relative_amplitude().size());
  EXPECT_EQ(0.0, pavt_fetch_phase_and_amplitude_array_response.mean_relative_amplitude(0));
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_phase_size());
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_phase().size());
  EXPECT_EQ(0.0, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_phase(0));
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_amplitude_size());
  EXPECT_EQ(999, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_amplitude().size());
  EXPECT_EQ(0.0, pavt_fetch_phase_and_amplitude_array_response.mean_absolute_amplitude(0));
  EXPECT_SUCCESS(session, pavt_fetch_phase_trace_response);
  EXPECT_EQ(0.0, pavt_fetch_phase_trace_response.x0());
  EXPECT_EQ(0.0, pavt_fetch_phase_trace_response.dx());
  EXPECT_EQ(999, pavt_fetch_phase_trace_response.phase_size());
  EXPECT_EQ(999, pavt_fetch_phase_trace_response.phase().size());
  EXPECT_EQ(0.0, pavt_fetch_phase_trace_response.phase(0));
  EXPECT_SUCCESS(session, pavt_fetch_amplitude_trace_response);
  EXPECT_EQ(0.0, pavt_fetch_amplitude_trace_response.x0());
  EXPECT_EQ(0.0, pavt_fetch_amplitude_trace_response.dx());
  EXPECT_EQ(999, pavt_fetch_amplitude_trace_response.amplitude_size());
  EXPECT_EQ(999, pavt_fetch_amplitude_trace_response.amplitude().size());
  EXPECT_EQ(0.0, pavt_fetch_amplitude_trace_response.amplitude(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, PhaseNoiseBasicFromExample_FetchData_DataLooksReasonable)
{
  int32 autolevel = RFMXSPECAN_VAL_TRUE;
  // TODO: Conversion process ignored auto_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.00));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  if (autolevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 2.0e+5, 10e-3));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PHASENOISE, true));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_auto_range(stub(), session, "", 1e+3, 1e+6, 10.00));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_averaging_multiplier(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_smoothing(stub(), session, "", PHASE_NOISE_SMOOTHING_TYPE_LOGARITHMIC, 2.00));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto phase_noise_fetch_carrier_measurement_response = client::phase_noise_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto phase_noise_fetch_integrated_noise_response = client::phase_noise_fetch_integrated_noise(stub(), session, "", 10.0);
  const auto phase_noise_fetch_measured_log_plot_trace_response = client::phase_noise_fetch_measured_log_plot_trace(stub(), session, "", 10.0);
  const auto phase_noise_fetch_smoothed_log_plot_trace_response = client::phase_noise_fetch_smoothed_log_plot_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, phase_noise_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, phase_noise_fetch_carrier_measurement_response.carrier_frequency());
  EXPECT_EQ(0.0, phase_noise_fetch_carrier_measurement_response.carrier_power());
  EXPECT_SUCCESS(session, phase_noise_fetch_integrated_noise_response);
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.integrated_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.integrated_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.integrated_phase_noise(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_fm_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_fm().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_fm(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.jitter_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.jitter().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.jitter(0));
  EXPECT_SUCCESS(session, phase_noise_fetch_measured_log_plot_trace_response);
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.frequency_size());
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.frequency().size());
  EXPECT_EQ(0.0, phase_noise_fetch_measured_log_plot_trace_response.frequency(0));
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise(0));
  EXPECT_SUCCESS(session, phase_noise_fetch_smoothed_log_plot_trace_response);
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.frequency_size());
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.frequency().size());
  EXPECT_EQ(0.0, phase_noise_fetch_smoothed_log_plot_trace_response.frequency(0));
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, SemFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 2;
  int32 i = 0;
  int32 numberOfOffsets = NUMBER_OF_OFFSETS;
  std::vector<int> offsetEnabled(NUMBER_OF_OFFSETS, 0);
  std::vector<int> offsetFrequencySideband(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetStartFrequency(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetStopFrequency(NUMBER_OF_OFFSETS, 0);
  std::vector<int> offsetRBWAuto(NUMBER_OF_OFFSETS, 0);
  std::vector<int> offsetRBWFilterType(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetRBW(NUMBER_OF_OFFSETS, 0);
  std::vector<int> offsetAbsoluteLimitMode(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetAbsoluteStartLimit(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetAbsoluteStopLimit(NUMBER_OF_OFFSETS, 0);
  std::vector<int> offsetRelativeLimitMode(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetRelativeStartLimit(NUMBER_OF_OFFSETS, 0);
  std::vector<float64> offsetRelativeStopLimit(NUMBER_OF_OFFSETS, 0);
  for (i = 0; i < numberOfOffsets; i++)
  {
    offsetEnabled[i] = NIRFMXSPECAN_INT32_SEM_OFFSET_ENABLED_TRUE;
    offsetFrequencySideband[i] = NIRFMXSPECAN_INT32_SEM_OFFSET_SIDEBAND_BOTH;
    if (i == 0)
    {
      offsetStartFrequency[i] = 1.0e+6;
      offsetStopFrequency[i] = 2.0e+6;
      offsetRelativeLimitMode[i] = NIRFMXSPECAN_INT32_SEM_OFFSET_RELATIVE_LIMIT_MODE_MANUAL;
      offsetRelativeStartLimit[i] = -10.00;
      offsetRelativeStopLimit[i] = -30.00;
    }
    else if (i == 1)
    {
      offsetStartFrequency[i] = 2.0e+6;
      offsetStopFrequency[i] = 3.0e+6;
      offsetRelativeLimitMode[i] = NIRFMXSPECAN_INT32_SEM_OFFSET_RELATIVE_LIMIT_MODE_COUPLE;
      offsetRelativeStartLimit[i] = -30.00;
      offsetRelativeStopLimit[i] = -30.00;
    }
    offsetRBWAuto[i] = NIRFMXSPECAN_INT32_SEM_RBW_AUTO_TRUE;
    offsetRBWFilterType[i] = NIRFMXSPECAN_INT32_SEM_RBW_FILTER_TYPE_GAUSSIAN;
    offsetRBW[i] = 10.0e+3;
    offsetAbsoluteLimitMode[i] = NIRFMXSPECAN_INT32_SEM_OFFSET_ABSOLUTE_LIMIT_MODE_COUPLE;
    offsetAbsoluteStartLimit[i] = -10.00;
    offsetAbsoluteStopLimit[i] = -10.00;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_power_units(stub(), session, "", SEM_POWER_UNITS_DBM));
  EXPECT_SUCCESS(session, client::sem_cfg_reference_type(stub(), session, "", SEM_REFERENCE_TYPE_INTEGRATION));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_carrier_integration_bandwidth(stub(), session, "", 2.0e+6));
  EXPECT_SUCCESS(session, client::sem_cfg_carrier_rbw_filter(stub(), session, "", SEM_CARRIER_RBW_AUTO_BANDWIDTH_FALSE, 10.0e+3, SEM_CARRIER_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::sem_cfg_carrier_rrc_filter(stub(), session, "", SEM_CARRIER_RRC_FILTER_ENABLED_FALSE, 0.220));
  EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, "", offsetStartFrequency, offsetStopFrequency, offsetEnabled, offsetFrequencySideband));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_absolute_limit_array(stub(), session, "", offsetAbsoluteLimitMode, offsetAbsoluteStartLimit, offsetAbsoluteStopLimit));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_relative_limit_array(stub(), session, "", offsetRelativeLimitMode, offsetRelativeStartLimit, offsetRelativeStopLimit));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_rbw_filter_array(stub(), session, "", offsetRBWAuto, offsetRBW, offsetRBWFilterType));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_limit_fail_mask(stub(), session, "offset::all", SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 x0 = 0.0;
  float64 dx = 0.0;
  const auto sem_fetch_lower_offset_power_array_response = client::sem_fetch_lower_offset_power_array(stub(), session, "", 10.0);
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_upper_offset_power_array_response = client::sem_fetch_upper_offset_power_array(stub(), session, "", 10.0);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_absolute_mask_trace_response = client::sem_fetch_absolute_mask_trace(stub(), session, "", 10.0);
  x0 = 0;
  dx = 0;
  const auto sem_fetch_relative_mask_trace_response = client::sem_fetch_relative_mask_trace(stub(), session, "", 10.0);
  x0 = 0;
  dx = 0;
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);
  const auto sem_fetch_composite_measurement_status_response = client::sem_fetch_composite_measurement_status(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_lower_offset_power_array_response);
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.total_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.total_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_power_array_response.total_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.total_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.total_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_power_array_response.total_relative_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_power_array_response.peak_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_frequency_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_power_array_response.peak_frequency(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_power_array_response.peak_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_power_array_response.peak_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_power_array_response);
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.total_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.total_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_power_array_response.total_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.total_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.total_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_power_array_response.total_relative_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_power_array_response.peak_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_frequency_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_power_array_response.peak_frequency(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_power_array_response.peak_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_power_array_response.peak_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.peak_absolute_power());
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.peak_frequency());
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.total_relative_power());
  EXPECT_SUCCESS(session, sem_fetch_absolute_mask_trace_response);
  EXPECT_EQ(0.0, sem_fetch_absolute_mask_trace_response.x0());
  EXPECT_EQ(0.0, sem_fetch_absolute_mask_trace_response.dx());
  EXPECT_EQ(999, sem_fetch_absolute_mask_trace_response.absolute_mask_size());
  EXPECT_EQ(999, sem_fetch_absolute_mask_trace_response.absolute_mask().size());
  EXPECT_EQ(0.0, sem_fetch_absolute_mask_trace_response.absolute_mask(0));
  EXPECT_SUCCESS(session, sem_fetch_relative_mask_trace_response);
  EXPECT_EQ(0.0, sem_fetch_relative_mask_trace_response.x0());
  EXPECT_EQ(0.0, sem_fetch_relative_mask_trace_response.dx());
  EXPECT_EQ(999, sem_fetch_relative_mask_trace_response.relative_mask_size());
  EXPECT_EQ(999, sem_fetch_relative_mask_trace_response.relative_mask().size());
  EXPECT_EQ(0.0, sem_fetch_relative_mask_trace_response.relative_mask(0));
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, sem_fetch_composite_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_composite_measurement_status_response.composite_measurement_status());
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpectrumFromExample_FetchData_DataLooksReasonable)
{
  const auto CONFIGURE_START_STOP_FREQ_OFF = 0;
  int32 isCfgStartStopFreqValid = CONFIGURE_START_STOP_FREQ_OFF;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  if (isCfgStartStopFreqValid)
  {
    EXPECT_SUCCESS(session, client::spectrum_cfg_frequency_start_stop(stub(), session, "", 9.95e+8, 1.005e+9));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
    EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1.0e+6));
  }
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SPECTRUM, true));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", SPECTRUM_RBW_AUTO_BANDWIDTH_TRUE, 10.0e+3, SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_power_units(stub(), session, "", SPECTRUM_POWER_UNITS_DBM));
  EXPECT_SUCCESS(session, client::spectrum_cfg_sweep_time(stub(), session, "", SPECTRUM_SWEEP_TIME_AUTO_TRUE, 1.00e-3));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", SPECTRUM_AVERAGING_ENABLED_FALSE, 10, SPECTRUM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::spectrum_cfg_fft(stub(), session, "", SPECTRUM_FFT_WINDOW_FLAT_TOP, -1.0));
  EXPECT_SUCCESS(session, client::spectrum_cfg_noise_compensation_enabled(stub(), session, "", SPECTRUM_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::spectrum_cfg_detector(stub(), session, "", SPECTRUM_DETECTOR_TYPE_NONE, 1001));
  EXPECT_SUCCESS(session, client::spectrum_cfg_vbw_filter(stub(), session, "", SPECTRUM_VBW_FILTER_AUTO_BANDWIDTH_TRUE, 30.0e3, 3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto spectrum_fetch_spectrum_response = client::spectrum_fetch_spectrum(stub(), session, "", 10.0);
  const auto spectrum_fetch_measurement_response = client::spectrum_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, spectrum_fetch_spectrum_response);
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.dx());
  EXPECT_EQ(999, spectrum_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, spectrum_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, spectrum_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, spectrum_fetch_measurement_response);
  EXPECT_EQ(0.0, spectrum_fetch_measurement_response.peak_amplitude());
  EXPECT_EQ(0.0, spectrum_fetch_measurement_response.peak_frequency());
  EXPECT_EQ(0.0, spectrum_fetch_measurement_response.frequency_resolution());
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpectrumBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1.0e+6));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", SPECTRUM_RBW_AUTO_BANDWIDTH_TRUE, 100.0e+3, SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", SPECTRUM_AVERAGING_ENABLED_FALSE, 10, SPECTRUM_AVERAGING_TYPE_RMS));

  const auto spectrum_read_response = client::spectrum_read(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, spectrum_read_response);
  EXPECT_EQ(0.0, spectrum_read_response.x0());
  EXPECT_EQ(0.0, spectrum_read_response.dx());
  EXPECT_EQ(999, spectrum_read_response.spectrum_size());
  EXPECT_EQ(999, spectrum_read_response.spectrum().size());
  EXPECT_EQ(0.0, spectrum_read_response.spectrum(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpurFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_RANGE_LIST = 1;
  const auto NUMBER_OF_SPURS_TO_REPORT = 10;
  std::vector<int> rangeEnabledArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> startFrequencyArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> stopFrequencyArray(NUMBER_OF_RANGE_LIST);
  std::vector<int> RBWFilterTypeArray(NUMBER_OF_RANGE_LIST);
  std::vector<int> RBWFilterAutoBandwidthArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> RBWFilterBandwidthArray(NUMBER_OF_RANGE_LIST);
  std::vector<int> VBWAuto(NUMBER_OF_RANGE_LIST);
  std::vector<float64> VBW(NUMBER_OF_RANGE_LIST);
  std::vector<float64> VBWToRBWRatio(NUMBER_OF_RANGE_LIST);
  std::vector<int> detectorType(NUMBER_OF_RANGE_LIST);
  std::vector<int> detectorPoints(NUMBER_OF_RANGE_LIST);
  std::vector<int> absLimitModeArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> absStartLimitArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> absStopLimitArray(NUMBER_OF_RANGE_LIST);
  std::vector<float64> peakThreashold(NUMBER_OF_RANGE_LIST);
  std::vector<float64> peakExcursion(NUMBER_OF_RANGE_LIST);
  std::vector<int> numOfSpursToReportArray(NUMBER_OF_RANGE_LIST);
  int32 rangeListSize = NUMBER_OF_RANGE_LIST;
  for (i = 0; i < rangeListSize; i++)
  {
    rangeEnabledArray[i] = NIRFMXSPECAN_INT32_SPUR_RANGE_ENABLED_TRUE;
    startFrequencyArray[i] = 1e+9;
    stopFrequencyArray[i] = 1.5e+9;
    RBWFilterTypeArray[i] = NIRFMXSPECAN_INT32_SPUR_RBW_FILTER_TYPE_GAUSSIAN;
    RBWFilterAutoBandwidthArray[i] = NIRFMXSPECAN_INT32_SPUR_RBW_AUTO_TRUE;
    RBWFilterBandwidthArray[i] = 30e+3;
    VBWAuto[i] = NIRFMXSPECAN_INT32_SPUR_RANGE_VBW_FILTER_AUTO_BANDWIDTH_TRUE;
    VBW[i] = 30.0e3;
    VBWToRBWRatio[i] = 3;
    detectorType[i] = NIRFMXSPECAN_INT32_SPUR_RANGE_DETECTOR_TYPE_NONE;
    detectorPoints[i] = 1001;
    absLimitModeArray[i] = NIRFMXSPECAN_INT32_SPUR_ABSOLUTE_LIMIT_MODE_COUPLE;
    absStartLimitArray[i] = -10.00;
    absStopLimitArray[i] = -10.00;
    peakThreashold[i] = -200;
    peakExcursion[i] = 0.00;
    numOfSpursToReportArray[i] = NUMBER_OF_SPURS_TO_REPORT;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SPUR, true));
  EXPECT_SUCCESS(session, client::spur_cfg_averaging(stub(), session, "", SPUR_AVERAGING_ENABLED_FALSE, 10, SPUR_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::spur_cfg_number_of_ranges(stub(), session, "", NUMBER_OF_RANGE_LIST));
  EXPECT_SUCCESS(session, client::spur_cfg_range_frequency_array(stub(), session, "", startFrequencyArray, stopFrequencyArray, rangeEnabledArray));
  EXPECT_SUCCESS(session, client::spur_cfg_range_rbw_array(stub(), session, "", RBWFilterAutoBandwidthArray, RBWFilterBandwidthArray, RBWFilterTypeArray));
  EXPECT_SUCCESS(session, client::spur_cfg_range_absolute_limit_array(stub(), session, "", absLimitModeArray, absStartLimitArray, absStopLimitArray));
  EXPECT_SUCCESS(session, client::spur_cfg_range_number_of_spurs_to_report_array(stub(), session, "", numOfSpursToReportArray));
  EXPECT_SUCCESS(session, client::spur_cfg_range_peak_criteria_array(stub(), session, "", peakThreashold, peakExcursion));
  EXPECT_SUCCESS(session, client::spur_cfg_range_detector_array(stub(), session, "", detectorType, detectorPoints));
  EXPECT_SUCCESS(session, client::spur_cfg_range_vbw_filter_array(stub(), session, "", VBWAuto, VBW, VBWToRBWRatio));
  EXPECT_SUCCESS(session, client::spur_cfg_trace_range_index(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 z0 = 0.0;
  float64 dz = 0.0;
  int32 rangeNumber;
  int32 totalSpur = 0;
  float64* spurFrequency = (float64*)NULL;
  float64* spurAmplitude = (float64*)NULL;
  float64* spurAbsoluteLimit = (float64*)NULL;
  float64* spurMargin = (float64*)NULL;
  int32* spurRangeIndex = (int32*)NULL;
  std::vector<int> rangeDetectedSpurs(NUMBER_OF_RANGE_LIST);
  int32 traceRangeIndex = 0;
  SpurFetchAllSpursResponse spur_fetch_all_spurs_response;
  const auto spur_fetch_range_status_array_response = client::spur_fetch_range_status_array(stub(), session, "", 10.0);
  int32 actualArraySize = spur_fetch_range_status_array_response.range_status_size();
  totalSpur = 0;
  for (int i = 0; i < rangeListSize; i++)
  {
    totalSpur += rangeDetectedSpurs[i];
  }
  if (totalSpur > 0)
  {
    spurFrequency = (float64*)malloc(sizeof(float64)*totalSpur);
    spurAmplitude = (float64*)malloc(sizeof(float64)*totalSpur);
    spurMargin = (float64*)malloc(sizeof(float64)*totalSpur);
    spurAbsoluteLimit = (float64*)malloc(sizeof(float64)*totalSpur);
    spurRangeIndex = (int32*)malloc(sizeof(int32)*totalSpur);
    if (spurFrequency && spurAmplitude && spurMargin && spurAbsoluteLimit && spurRangeIndex)
    {
      spur_fetch_all_spurs_response = client::spur_fetch_all_spurs(stub(), session, "", 10.0);
      actualArraySize = spur_fetch_all_spurs_response.spur_frequency_size();
    }
    else
    {
    }
  }
  rangeNumber = (traceRangeIndex == -1) ? 0 : traceRangeIndex;
  auto range_string_response = client::build_range_string(stub(), "", rangeNumber);
  EXPECT_SUCCESS(session, range_string_response);
  const auto spur_fetch_range_absolute_limit_trace_response = client::spur_fetch_range_absolute_limit_trace(stub(), session, range_string_response.selector_string_out(), 10.0);
  actualArraySize = 0, z0 = 0.0;
  dz = 0.0;
  const auto spur_fetch_range_spectrum_trace_response = client::spur_fetch_range_spectrum_trace(stub(), session, range_string_response.selector_string_out(), 10.0);
  const auto spur_fetch_measurement_status_response = client::spur_fetch_measurement_status(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, spur_fetch_range_status_array_response);
  EXPECT_EQ(999, spur_fetch_range_status_array_response.range_status_size());
  EXPECT_EQ(999, spur_fetch_range_status_array_response.range_status().size());
  EXPECT_EQ(0, spur_fetch_range_status_array_response.range_status(0));
  EXPECT_EQ(999, spur_fetch_range_status_array_response.number_of_detected_spurs_size());
  EXPECT_EQ(999, spur_fetch_range_status_array_response.number_of_detected_spurs().size());
  EXPECT_EQ(0, spur_fetch_range_status_array_response.number_of_detected_spurs(0));
  EXPECT_SUCCESS(session, spur_fetch_all_spurs_response);
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_frequency_size());
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_frequency().size());
  EXPECT_EQ(0.0, spur_fetch_all_spurs_response.spur_frequency(0));
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_amplitude_size());
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_amplitude().size());
  EXPECT_EQ(0.0, spur_fetch_all_spurs_response.spur_amplitude(0));
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_margin_size());
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_margin().size());
  EXPECT_EQ(0.0, spur_fetch_all_spurs_response.spur_margin(0));
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_absolute_limit_size());
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_absolute_limit().size());
  EXPECT_EQ(0.0, spur_fetch_all_spurs_response.spur_absolute_limit(0));
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_range_index_size());
  EXPECT_EQ(999, spur_fetch_all_spurs_response.spur_range_index().size());
  EXPECT_EQ(0, spur_fetch_all_spurs_response.spur_range_index(0));
  EXPECT_SUCCESS(session, spur_fetch_range_absolute_limit_trace_response);
  EXPECT_EQ(0.0, spur_fetch_range_absolute_limit_trace_response.x0());
  EXPECT_EQ(0.0, spur_fetch_range_absolute_limit_trace_response.dx());
  EXPECT_EQ(999, spur_fetch_range_absolute_limit_trace_response.absolute_limit_size());
  EXPECT_EQ(999, spur_fetch_range_absolute_limit_trace_response.absolute_limit().size());
  EXPECT_EQ(0.0, spur_fetch_range_absolute_limit_trace_response.absolute_limit(0));
  EXPECT_SUCCESS(session, spur_fetch_range_spectrum_trace_response);
  EXPECT_EQ(0.0, spur_fetch_range_spectrum_trace_response.x0());
  EXPECT_EQ(0.0, spur_fetch_range_spectrum_trace_response.dx());
  EXPECT_EQ(999, spur_fetch_range_spectrum_trace_response.range_spectrum_size());
  EXPECT_EQ(999, spur_fetch_range_spectrum_trace_response.range_spectrum().size());
  EXPECT_EQ(0.0, spur_fetch_range_spectrum_trace_response.range_spectrum(0));
  EXPECT_SUCCESS(session, spur_fetch_measurement_status_response);
  EXPECT_EQ(0, spur_fetch_measurement_status_response.measurement_status());
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpurBasicFromExample_FetchData_DataLooksReasonable)
{
  const auto NUM_OF_RANGES = 1;
  int32 i = 0;
  int32 rangeListSize = NUM_OF_RANGES;
  std::vector<float64> startFrequency(NUM_OF_RANGES);
  std::vector<float64> stopFrequency(NUM_OF_RANGES);
  std::vector<int> rangeEnabled(NUM_OF_RANGES);
  std::vector<int> RBWFilterAutoBandwidth(NUM_OF_RANGES);
  std::vector<float64> RBWFilterBandwidth(NUM_OF_RANGES);
  std::vector<int> RBWFilterType(NUM_OF_RANGES);
  std::vector<float64> limit(NUM_OF_RANGES);
  for (i = 0; i < rangeListSize; i++)
  {
    startFrequency[i] = 1e+9;
    stopFrequency[i] = 1.5e+9;
    rangeEnabled[i] = NIRFMXSPECAN_INT32_SPUR_RANGE_ENABLED_TRUE;
    RBWFilterAutoBandwidth[i] = NIRFMXSPECAN_INT32_SPUR_RBW_AUTO_FALSE;
    RBWFilterBandwidth[i] = 30e+3;
    RBWFilterType[i] = NIRFMXSPECAN_INT32_SPUR_RBW_FILTER_TYPE_GAUSSIAN;
    limit[i] = -10.00;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SPUR, true));
  EXPECT_SUCCESS(session, client::spur_cfg_number_of_ranges(stub(), session, "", NUM_OF_RANGES));
  EXPECT_SUCCESS(session, client::spur_cfg_range_frequency_array(stub(), session, "", startFrequency, stopFrequency, rangeEnabled));
  EXPECT_SUCCESS(session, client::spur_cfg_range_rbw_array(stub(), session, "", RBWFilterAutoBandwidth, RBWFilterBandwidth, RBWFilterType));
  EXPECT_SUCCESS(session, client::spur_cfg_range_absolute_limit_array(stub(), session, "", NULL, limit, NULL));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto spur_fetch_measurement_status_response = client::spur_fetch_measurement_status(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, spur_fetch_measurement_status_response);
  EXPECT_EQ(0, spur_fetch_measurement_status_response.measurement_status());
}

TEST_F(NiRFmxSpecAnDriverApiTests, TOIFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_IM, true));
  EXPECT_SUCCESS(session, client::im_cfg_averaging(stub(), session, "", IM_AVERAGING_ENABLED_FALSE, 10, IM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::im_cfg_rbw_filter(stub(), session, "", IM_RBW_FILTER_AUTO_BANDWIDTH_TRUE, 10.0e+3, IM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::im_cfg_sweep_time(stub(), session, "", IM_SWEEP_TIME_AUTO_TRUE, 1.00e-3));
  EXPECT_SUCCESS(session, client::im_cfg_fft(stub(), session, "", IM_FFT_WINDOW_FLAT_TOP, -1.0));
  EXPECT_SUCCESS(session, client::im_cfg_measurement_method(stub(), session, "", IM_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::im_cfg_fundamental_tones(stub(), session, "", -1e+6, 1e+6));
  EXPECT_SUCCESS(session, client::im_cfg_auto_intermods_setup(stub(), session, "", IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE, 3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto MAXIMUM_NUMBER_OF_SPECTRUMS = 4;
  int32 numberOfSpectrums = MAXIMUM_NUMBER_OF_SPECTRUMS;
  int32 measurementMethod = RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_NORMAL;
  IMFetchSpectrumResponse im_fetch_spectrum_response;
  const auto im_fetch_fundamental_measurement_response = client::im_fetch_fundamental_measurement(stub(), session, "", 10.0);
  const auto im_fetch_intermod_measurement_response = client::im_fetch_intermod_measurement(stub(), session, "", 10.0);
  const auto im_fetch_intercept_power_response = client::im_fetch_intercept_power(stub(), session, "", 10.0);
  if (measurementMethod == NIRFMXSPECAN_INT32_IM_MEASUREMENT_METHOD_NORMAL)
    numberOfSpectrums = 1;
  for (int i = 0; i < numberOfSpectrums; i++)
  {
    im_fetch_spectrum_response = client::im_fetch_spectrum(stub(), session, "", 10.0, i);
  }

  EXPECT_SUCCESS(session, im_fetch_fundamental_measurement_response);
  EXPECT_EQ(0.0, im_fetch_fundamental_measurement_response.lower_tone_power());
  EXPECT_EQ(0.0, im_fetch_fundamental_measurement_response.upper_tone_power());
  EXPECT_SUCCESS(session, im_fetch_intermod_measurement_response);
  EXPECT_EQ(0, im_fetch_intermod_measurement_response.intermod_order());
  EXPECT_EQ(0.0, im_fetch_intermod_measurement_response.lower_intermod_power());
  EXPECT_EQ(0.0, im_fetch_intermod_measurement_response.upper_intermod_power());
  EXPECT_SUCCESS(session, im_fetch_intercept_power_response);
  EXPECT_EQ(0, im_fetch_intercept_power_response.intermod_order());
  EXPECT_EQ(0.0, im_fetch_intercept_power_response.worst_case_output_intercept_power());
  EXPECT_EQ(0.0, im_fetch_intercept_power_response.lower_output_intercept_power());
  EXPECT_EQ(0.0, im_fetch_intercept_power_response.upper_output_intercept_power());
  EXPECT_SUCCESS(session, im_fetch_spectrum_response);
  EXPECT_EQ(0.0, im_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, im_fetch_spectrum_response.dx());
  EXPECT_EQ(999, im_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, im_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, im_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, TxpFromExample_FetchData_DataLooksReasonable)
{
  int32 IQPowerEdgeEnabled = 0;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  if (IQPowerEdgeEnabled)
  {
    EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", -20.00, IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL, 0.00, BOOLEAN_TRUE));
  }
  else
  {
    EXPECT_SUCCESS(session, client::disable_trigger(stub(), session, ""));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, "", 100e+3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::txp_cfg_vbw_filter(stub(), session, "", TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE, 30.0e3, 3));
  EXPECT_SUCCESS(session, client::txp_cfg_threshold(stub(), session, "", TXP_THRESHOLD_ENABLED_FALSE, -20.00, TXP_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_mean_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_to_average_ratio());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.maximum_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.minimum_power());
}

TEST_F(NiRFmxSpecAnDriverApiTests, TxpBasicFromExample_FetchData_DataLooksReasonable)
{
  // TODO: Conversion process ignored txp_read_response.minimum_power
  // TODO: Conversion process ignored txp_read_response.maximum_power
  // TODO: Conversion process ignored txp_read_response.peak_to_average_ratio
  // TODO: Conversion process ignored txp_read_response.average_mean_power
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, "", 100e3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.1));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));

  EXPECT_SUCCESS(session, client::txp_read(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, TxpIQDeviceFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", -20.00, IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, "", 100e+3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::txp_cfg_threshold(stub(), session, "", TXP_THRESHOLD_ENABLED_FALSE, -20.00, TXP_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::txp_cfg_vbw_filter(stub(), session, "", TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE, 30.0e3, 3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_mean_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_to_average_ratio());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.maximum_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.minimum_power());
}

TEST_F(NiRFmxSpecAnDriverApiTests, ZeroSpanFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SPECTRUM, true));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", SPECTRUM_RBW_AUTO_BANDWIDTH_FALSE, 10.0e+3, SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::spectrum_cfg_sweep_time(stub(), session, "", SPECTRUM_SWEEP_TIME_AUTO_FALSE, 1.0e-3));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", SPECTRUM_AVERAGING_ENABLED_FALSE, 10, SPECTRUM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto spectrum_fetch_power_trace_response = client::spectrum_fetch_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, spectrum_fetch_power_trace_response);
  EXPECT_EQ(0.0, spectrum_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, spectrum_fetch_power_trace_response.dx());
  EXPECT_EQ(999, spectrum_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, spectrum_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, spectrum_fetch_power_trace_response.power(0));
}


/**************************** Advanced ****************************/


// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_AcpAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, AcpTxpCompositeFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", (MEASUREMENT_TYPES_ACP | MEASUREMENT_TYPES_TXP), true));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_carrier_and_offsets(stub(), session, "", 1.0e+6, 2, 1.0e+6));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, "", 1.0e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, "", 100.00e+3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.100));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto acp_fetch_carrier_measurement_response = client::acp_fetch_carrier_measurement(stub(), session, "", 10);
  const auto acp_fetch_offset_measurement_response = client::acp_fetch_offset_measurement(stub(), session, "offset0", 10);
  const auto acp_fetch_offset_measurement_response = client::acp_fetch_offset_measurement(stub(), session, "offset1", 10);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10);

  EXPECT_SUCCESS(session, acp_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.total_relative_power());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.carrier_offset());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.integration_bandwidth());
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.lower_relative_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.upper_relative_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.lower_absolute_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.upper_absolute_power());
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.lower_relative_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.upper_relative_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.lower_absolute_power());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_response.upper_absolute_power());
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_mean_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_to_average_ratio());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.maximum_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.minimum_power());
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_ChpAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled because not trivial
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_ExternalAttenuationTableFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, IMAdvancedFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_INTERMODS = 1;
  int32 autoIntermodSetupEnabled = RFMXSPECAN_VAL_IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE;
  int32 numberOfIntermods = NUMBER_OF_INTERMODS;
  std::vector<int> intermodEnabled(NUMBER_OF_INTERMODS);
  std::vector<int> intermodSide(NUMBER_OF_INTERMODS);
  std::vector<int> order(NUMBER_OF_INTERMODS, 0);
  std::vector<float64> lowerIntermodFrequency(NUMBER_OF_INTERMODS);
  std::vector<float64> upperIntermodFrequency(NUMBER_OF_INTERMODS);
  for (i = 0; i < numberOfIntermods; i++)
  {
    intermodEnabled[i] = NIRFMXSPECAN_INT32_IM_INTERMOD_ENABLED_TRUE;
    order[i] = 3;
    intermodSide[i] = NIRFMXSPECAN_INT32_IM_INTERMOD_SIDE_BOTH;
    lowerIntermodFrequency[i] = -3.0e+6;
    upperIntermodFrequency[i] = 3.0e+6;
  }
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_IM, true));
  EXPECT_SUCCESS(session, client::im_cfg_averaging(stub(), session, "", IM_AVERAGING_ENABLED_FALSE, 10, IM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::im_cfg_rbw_filter(stub(), session, "", IM_RBW_FILTER_AUTO_BANDWIDTH_TRUE, 10.0e+3, IM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::im_cfg_sweep_time(stub(), session, "", IM_SWEEP_TIME_AUTO_TRUE, 1.00e-3));
  EXPECT_SUCCESS(session, client::im_cfg_fft(stub(), session, "", IM_FFT_WINDOW_FLAT_TOP, -1.0));
  EXPECT_SUCCESS(session, client::im_cfg_frequency_definition(stub(), session, "", IM_FREQUENCY_DEFINITION_RELATIVE));
  EXPECT_SUCCESS(session, client::im_cfg_measurement_method(stub(), session, "", IM_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::im_cfg_fundamental_tones(stub(), session, "", -1e+6, 1e+6));
  EXPECT_SUCCESS(session, client::im_cfg_auto_intermods_setup(stub(), session, "", IM_AUTO_INTERMODS_SETUP_ENABLED_TRUE, 3));
  if (autoIntermodSetupEnabled == NIRFMXSPECAN_INT32_IM_AUTO_INTERMODS_SETUP_ENABLED_FALSE)
  {
    EXPECT_SUCCESS(session, client::im_cfg_number_of_intermods(stub(), session, "", NUMBER_OF_INTERMODS));
    EXPECT_SUCCESS(session, client::im_cfg_intermod_array(stub(), session, "", order, lowerIntermodFrequency, upperIntermodFrequency, intermodSide, intermodEnabled));
  }
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 intermodSize = 0;
  int32 numberOfSpectrums = 0;
  int32* intermodOrder = NULL;
  float64* lowerIntermodPower = NULL;
  float64* upperIntermodPower = NULL;
  float64* worstCaseOutputInterceptPower = NULL;
  float64* lowerOutputInterceptPower = NULL;
  float64* upperOutputInterceptPower = NULL;
  float64* x0 = NULL;
  float64* dx = NULL;
  float32** spectrum = NULL;
  int32 measurementMethod = RFMXSPECAN_VAL_IM_MEASUREMENT_METHOD_NORMAL;
  IMFetchSpectrumResponse im_fetch_spectrum_response;
  numberOfIntermods = GET_ATTR_I32(session, "", NIRFMXSPECAN_ATTRIBUTE_IM_NUMBER_OF_INTERMODS);
  intermodSize = numberOfIntermods;
  if (measurementMethod == NIRFMXSPECAN_INT32_IM_MEASUREMENT_METHOD_NORMAL)
    numberOfSpectrums = 1;
  else
    numberOfSpectrums = 2 * numberOfIntermods + 2;
  x0 = (float64 *)malloc(sizeof(float64)*numberOfSpectrums);
  dx = (float64 *)malloc(sizeof(float64)*numberOfSpectrums);
  spectrum = (float32 **)malloc(sizeof(float32 *)*numberOfSpectrums);
  intermodOrder = (int32 *)malloc(sizeof(int32)*intermodSize);
  lowerIntermodPower = (float64 *)malloc(sizeof(float64)*intermodSize);
  upperIntermodPower = (float64 *)malloc(sizeof(float64)*intermodSize);
  worstCaseOutputInterceptPower = (float64 *)malloc(sizeof(float64)*intermodSize);
  lowerOutputInterceptPower = (float64 *)malloc(sizeof(float64)*intermodSize);
  upperOutputInterceptPower = (float64 *)malloc(sizeof(float64)*intermodSize);
  const auto im_fetch_fundamental_measurement_response = client::im_fetch_fundamental_measurement(stub(), session, "", 10.0);
  const auto im_fetch_intermod_measurement_array_response = client::im_fetch_intermod_measurement_array(stub(), session, "", 10.0);
  int32 actualArraySize = im_fetch_intermod_measurement_array_response.intermod_order_size();
  const auto im_fetch_intercept_power_array_response = client::im_fetch_intercept_power_array(stub(), session, "", 10.0);
  actualArraySize = im_fetch_intercept_power_array_response.intermod_order_size();
  for (int i = 0; i < numberOfSpectrums; i++)
  {
    spectrum[i] = (float32 *)NULL;
    x0[i] = 0.0;
    dx[i] = 0.0;
    im_fetch_spectrum_response = client::im_fetch_spectrum(stub(), session, "", 10.0, i);
  }

  EXPECT_EQ(0, numberOfIntermods);
  EXPECT_SUCCESS(session, im_fetch_fundamental_measurement_response);
  EXPECT_EQ(0.0, im_fetch_fundamental_measurement_response.lower_tone_power());
  EXPECT_EQ(0.0, im_fetch_fundamental_measurement_response.upper_tone_power());
  EXPECT_SUCCESS(session, im_fetch_intermod_measurement_array_response);
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.intermod_order_size());
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.intermod_order().size());
  EXPECT_EQ(0, im_fetch_intermod_measurement_array_response.intermod_order(0));
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.lower_intermod_power_size());
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.lower_intermod_power().size());
  EXPECT_EQ(0.0, im_fetch_intermod_measurement_array_response.lower_intermod_power(0));
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.upper_intermod_power_size());
  EXPECT_EQ(999, im_fetch_intermod_measurement_array_response.upper_intermod_power().size());
  EXPECT_EQ(0.0, im_fetch_intermod_measurement_array_response.upper_intermod_power(0));
  EXPECT_SUCCESS(session, im_fetch_intercept_power_array_response);
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.intermod_order_size());
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.intermod_order().size());
  EXPECT_EQ(0, im_fetch_intercept_power_array_response.intermod_order(0));
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.worst_case_output_intercept_power_size());
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.worst_case_output_intercept_power().size());
  EXPECT_EQ(0.0, im_fetch_intercept_power_array_response.worst_case_output_intercept_power(0));
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.lower_output_intercept_power_size());
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.lower_output_intercept_power().size());
  EXPECT_EQ(0.0, im_fetch_intercept_power_array_response.lower_output_intercept_power(0));
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.upper_output_intercept_power_size());
  EXPECT_EQ(999, im_fetch_intercept_power_array_response.upper_output_intercept_power().size());
  EXPECT_EQ(0.0, im_fetch_intercept_power_array_response.upper_output_intercept_power(0));
  EXPECT_SUCCESS(session, im_fetch_spectrum_response);
  EXPECT_EQ(0.0, im_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, im_fetch_spectrum_response.dx());
  EXPECT_EQ(999, im_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, im_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, im_fetch_spectrum_response.spectrum(0));
}

// NOTE: disabled due to "ReadFromTDMSFile" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_MemoryDpdAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled because not trivial
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_MultipleAcpOverlappedFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_MultipleSignalsAcpFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled because not trivial
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_NFYFactorAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, PhaseNoiseAdvancedFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_RANGES = 1;
  int32 autolevel = RFMXSPECAN_VAL_TRUE;
  int32 rangeDefinition = RFMXSPECAN_VAL_PHASENOISE_RANGE_DEFINITION_AUTO;
  std::vector<float64> rangeStartFrequency { 1.0e+3 };
  std::vector<float64> rangeStopFrequency { 1.0e+6 };
  std::vector<float64> rangeRBWPercentage { 10.00 };
  std::vector<int> rangeAveragingCount { 10 };
  // TODO: Conversion process ignored auto_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.00));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  if (autolevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 2.0e+5, 10e-3));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PHASENOISE, true));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_range_definition(stub(), session, "", PHASE_NOISE_RANGE_DEFINITION_AUTO));
  if (rangeDefinition == NIRFMXSPECAN_INT32_PHASENOISE_RANGE_DEFINITION_AUTO)
  {
    EXPECT_SUCCESS(session, client::phase_noise_cfg_auto_range(stub(), session, "", 1e+3, 1e+6, 10.00));
  }
  else
  {
    EXPECT_SUCCESS(session, client::phase_noise_cfg_number_of_ranges(stub(), session, "", NUMBER_OF_RANGES));
    EXPECT_SUCCESS(session, client::phase_noise_cfg_range_array(stub(), session, "", rangeStartFrequency, rangeStopFrequency, rangeRBWPercentage, rangeAveragingCount));
  }
  EXPECT_SUCCESS(session, client::phase_noise_cfg_averaging_multiplier(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_smoothing(stub(), session, "", PHASE_NOISE_SMOOTHING_TYPE_LOGARITHMIC, 2.00));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_spot_noise_frequency_list(stub(), session, "", NULL));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_integrated_noise(stub(), session, "", PHASE_NOISE_INTEGRATED_NOISE_RANGE_DEFINITION_MEASUREMENT, NULL, NULL));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_spur_removal(stub(), session, "", PHASE_NOISE_SPUR_REMOVAL_ENABLED_FALSE, 6.00));
  EXPECT_SUCCESS(session, client::phase_noise_cfg_cancellation(stub(), session, "", PHASE_NOISE_CANCELLATION_ENABLED_FALSE, 0.01, NULL, NULL));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto phase_noise_fetch_carrier_measurement_response = client::phase_noise_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto phase_noise_fetch_spot_noise_response = client::phase_noise_fetch_spot_noise(stub(), session, "", 10.0);
  const auto phase_noise_fetch_integrated_noise_response = client::phase_noise_fetch_integrated_noise(stub(), session, "", 10.0);
  const auto phase_noise_fetch_measured_log_plot_trace_response = client::phase_noise_fetch_measured_log_plot_trace(stub(), session, "", 10.0);
  const auto phase_noise_fetch_smoothed_log_plot_trace_response = client::phase_noise_fetch_smoothed_log_plot_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, phase_noise_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, phase_noise_fetch_carrier_measurement_response.carrier_frequency());
  EXPECT_EQ(0.0, phase_noise_fetch_carrier_measurement_response.carrier_power());
  EXPECT_SUCCESS(session, phase_noise_fetch_spot_noise_response);
  EXPECT_EQ(999, phase_noise_fetch_spot_noise_response.spot_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_spot_noise_response.spot_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_spot_noise_response.spot_phase_noise(0));
  EXPECT_SUCCESS(session, phase_noise_fetch_integrated_noise_response);
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.integrated_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.integrated_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.integrated_phase_noise(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_pm_in_radian(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_pm_in_degree(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_fm_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.residual_fm().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.residual_fm(0));
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.jitter_size());
  EXPECT_EQ(999, phase_noise_fetch_integrated_noise_response.jitter().size());
  EXPECT_EQ(0.0, phase_noise_fetch_integrated_noise_response.jitter(0));
  EXPECT_SUCCESS(session, phase_noise_fetch_measured_log_plot_trace_response);
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.frequency_size());
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.frequency().size());
  EXPECT_EQ(0.0, phase_noise_fetch_measured_log_plot_trace_response.frequency(0));
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_measured_log_plot_trace_response.measured_phase_noise(0));
  EXPECT_SUCCESS(session, phase_noise_fetch_smoothed_log_plot_trace_response);
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.frequency_size());
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.frequency().size());
  EXPECT_EQ(0.0, phase_noise_fetch_smoothed_log_plot_trace_response.frequency(0));
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise_size());
  EXPECT_EQ(999, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise().size());
  EXPECT_EQ(0.0, phase_noise_fetch_smoothed_log_plot_trace_response.smoothed_phase_noise(0));
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_SemAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, SParameterExternalAttenuationTableFromExample_FetchData_DataLooksReasonable)
{
  char* selectedPorts = "";
  std::vector<float64> frequencyArray { 997.0e+6, 1.0e+9, 1.003e+9 };
  std::vector<NIComplexDouble> sParameters { { 1.00, 0.00 },{ 1.00, 0.10 },{ 1.00, 0.10 },{ 1.00, 0.00 }, { 0.80, 0.10 },{ 0.80, 0.25 },{ 0.80, 0.25 },{ 0.80, 0.10 }, { 1.00, 0.25 },{ 1.00, 0.50 },{ 1.00, 0.50 },{ 1.00, 0.25 } };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  auto port_string_response = instr_client::build_port_string(instr_stub, "", selectedPorts, "", 0);
  EXPECT_SUCCESS(session, port_string_response);
  EXPECT_SUCCESS(session, instr_client::cfg_s_parameter_external_attenuation_table(instr_stub, session, port_string_response.selector_string_out(), "", frequencyArray, sParameters, 2, S_PARAMETER_ORIENTATION_PORT1_TOWARDS_DUT));
  EXPECT_SUCCESS(session, instr_client::cfg_external_attenuation_interpolation_linear(instr_stub, session, port_string_response.selector_string_out(), "", LINEAR_INTERPOLATION_FORMAT_REAL_AND_IMAGINARY));
  EXPECT_SUCCESS(session, instr_client::cfg_s_parameter_external_attenuation_type(instr_stub, session, port_string_response.selector_string_out(), S_PARAMETER_TYPE_SCALAR));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1e+9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", -20.00, IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_MANUAL, 0.00, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, "", 100e+3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.010));
  EXPECT_SUCCESS(session, client::txp_cfg_threshold(stub(), session, "", TXP_THRESHOLD_ENABLED_FALSE, -20.00, TXP_THRESHOLD_TYPE_RELATIVE));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::txp_cfg_vbw_filter(stub(), session, "", TXP_VBW_FILTER_AUTO_BANDWIDTH_TRUE, 30.0e3, 3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_mean_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_to_average_ratio());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.maximum_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.minimum_power());
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_SpurAdvancedFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxSpecAnDriverApiTests, DISABLED_TxpMultipleResultNamesFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxSpecAnDriverApiTests, TxpWithSignalAndResultNameFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  auto signal_string_response = client::build_signal_string(stub(), "TxP_Signal", "");
  EXPECT_SUCCESS(session, signal_string_response);
  EXPECT_SUCCESS(session, client::create_signal_configuration(stub(), session, signal_string_response.selector_string_out()));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, signal_string_response.selector_string_out(), NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, signal_string_response.selector_string_out(), 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, signal_string_response.selector_string_out(), MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_measurement_interval(stub(), session, signal_string_response.selector_string_out(), 1.0e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_rbw_filter(stub(), session, signal_string_response.selector_string_out(), 100.00e+3, TXP_RBW_FILTER_TYPE_GAUSSIAN, 0.100));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, signal_string_response.selector_string_out(), TXP_AVERAGING_ENABLED_FALSE, 10, TXP_AVERAGING_TYPE_RMS));
  auto signal_string_response = client::build_signal_string(stub(), signal_string_response.selector_string_out(), "TxP_Result");
  EXPECT_SUCCESS(session, signal_string_response);
  EXPECT_SUCCESS(session, client::initiate(stub(), session, signal_string_response.selector_string_out(), ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, signal_string_response.selector_string_out(), 10);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, signal_string_response.selector_string_out(), 10);

  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_mean_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_to_average_ratio());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.maximum_power());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.minimum_power());
}


}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
