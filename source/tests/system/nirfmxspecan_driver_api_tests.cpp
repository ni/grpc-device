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

  const auto iq_data = load_test_iq_data<float>("LTE20MHz Waveform (Two Subframes).json");
  const auto apply_response = client::dpd_apply_digital_predistortion_split(stub(), session, "", iq_data.t0, iq_data.dt, iq_data.I, iq_data.Q, false, 10.0);
  EXPECT_RFMX_ERROR(377652, "Synchronization not found", session, apply_response);
  EXPECT_THAT(apply_response.waveform_out_i(), Not(IsEmpty()));
  EXPECT_THAT(apply_response.waveform_out_q(), Not(IsEmpty()));
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

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
