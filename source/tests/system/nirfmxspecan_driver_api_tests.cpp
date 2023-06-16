#include <gmock/gmock.h>

#include <nlohmann/json.hpp>
#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "rfmx_macros.h"
#include "tests/utilities/test_helpers.h"
#include "waveform_helpers.h"

using namespace nirfmxspecan_grpc;
namespace client = nirfmxspecan_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663 = "5663";
constexpr auto INVALID_SESSION_HANDLE_ERROR = -380598;
constexpr auto DEVICE_IN_USE_ERROR = -380489;
constexpr auto IQ_FETCH_DELETED_RECORD_ERROR = -379451;
constexpr auto IQ_FETCH_DELETED_RECORD_ERROR_STR = "The requested record number is invalid";
constexpr auto READ_ONLY_ATTRIBUTE_ERROR = -380231;
constexpr auto READ_ONLY_ATTRIBUTE_ERROR_STR = "This attribute is read-only and cannot be written";
constexpr auto SYNCHRONIZATION_WARNING = 377652;
constexpr auto SYNCHRONIZATION_WARNING_STR = "Synchronization not found";
constexpr auto TYPE_MISMATCH_ERROR = -380251;
constexpr auto TYPE_MISMATCH_ERROR_STR = "Incorrect data type specified";

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

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxSpecAn::Stub>& stub()
  {
    return nirfmxspecan_stub_;
  }

  bool is_driver_session_valid(const instr_client::StubPtr& stub, const nidevice_grpc::Session& session)
  {
    try {
      auto response = instr_client::get_attribute_string(stub, session, "", nirfmxinstr_grpc::NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_INSTRUMENT_MODEL);
      EXPECT_EQ(0, response.status());
      return true;
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      const auto& error = ex.Trailers().find("ni-error")->second;
      return std::stoi(error) != INVALID_SESSION_HANDLE_ERROR;
    }
  }

  void config_dpd_reference_waveform(const nidevice_grpc::Session& session)
  {
    EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_DPD, true));
    auto waveform = load_test_waveform_data<float, nidevice_grpc::NIComplexNumberF32>("LTE20MHz Waveform (Two Subframes).json");
    EXPECT_SUCCESS(session, client::dpd_cfg_reference_waveform(stub(), session, "", waveform.t0, waveform.dt, waveform.data, false, DpdSignalType::DPD_SIGNAL_TYPE_MODULATED));
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxSpecAn::Stub> nirfmxspecan_stub_;
};

#define EXPECT_VALID_DRIVER_SESSION(session) \
  EXPECT_TRUE(is_driver_session_valid(create_stub<nirfmxinstr_grpc::NiRFmxInstr>(), session));

#define EXPECT_INVALID_DRIVER_SESSION(session) \
  EXPECT_FALSE(is_driver_session_valid(create_stub<nirfmxinstr_grpc::NiRFmxInstr>(), session));

InitializeResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, resource_name, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto response = init(stub, model, resource_name);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
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

TEST_F(NiRFmxSpecAnDriverApiTests, SpectrumBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0, 0));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1e6));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", true, 100e3, SpectrumRbwFilterType::SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", false, 10, SpectrumAveragingType::SPECTRUM_AVERAGING_TYPE_RMS));

  auto read_response = EXPECT_SUCCESS(session, client::spectrum_read(stub(), session, "", 10.0));

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
  EXPECT_SUCCESS(session, client::acp_cfg_offset_array(stub(), session, "", {1.0e6, 2.0e6}, {}, {}));

  const auto read_response = EXPECT_SUCCESS(session, client::acp_read(stub(), session, "", 10.0));

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

  const auto read_response = EXPECT_SUCCESS(session, client::f_cnt_read(stub(), session, "", 10.0));

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

  const auto fetch_response = EXPECT_SUCCESS(session, client::spur_fetch_measurement_status(stub(), session, "", 10.0));
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

  const auto fetch_thd_response = EXPECT_SUCCESS(session, client::harm_fetch_thd(stub(), session, "", 10.0));
  const auto fetch_measurement_response = EXPECT_SUCCESS(session, client::harm_fetch_harmonic_measurement_array(stub(), session, "", 10.0));
  for (auto i = 0; i < NUMBER_OF_HARMONICS; ++i) {
    const auto harmonic_string_response = EXPECT_SUCCESS(session, client::build_harmonic_string(stub(), "", i));
    const auto power_trace_response = EXPECT_SUCCESS(session, client::harm_fetch_harmonic_power_trace(stub(), session, harmonic_string_response.selector_string_out(), 10.0));
  }
}

TEST_F(NiRFmxSpecAnDriverApiTests, AMPMFromExample_NoError)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(
      session,
      client::cfg_digital_edge_trigger(stub(), session, "", DigitalEdgeTriggerSource::DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DigitalEdgeTriggerEdge::DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, true));
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

  const auto dut_char_response = EXPECT_SUCCESS(session, client::ampm_fetch_dut_characteristics(stub(), session, "", 10.0));
  const auto error_response = EXPECT_SUCCESS(session, client::ampm_fetch_error(stub(), session, "", 10.0));
  const auto curve_fit_response = EXPECT_SUCCESS(session, client::ampm_fetch_curve_fit_residual(stub(), session, "", 10.0));
  const auto am_to_am_response = EXPECT_SUCCESS(session, client::ampm_fetch_am_to_am_trace(stub(), session, "", 10.0));
}

TEST_F(NiRFmxSpecAnDriverApiTests, LutDpdFromExample_ReturnsSynchronizationNotFoundWarningWithData)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DigitalEdgeTriggerSource::DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DigitalEdgeTriggerEdge::DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, true));
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
  EXPECT_WARNING(SYNCHRONIZATION_WARNING, SYNCHRONIZATION_WARNING_STR, session, apply_response);
  EXPECT_THAT(apply_response.waveform_out(), Not(IsEmpty()));
}

// Note: there aren't any complex attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeComplex_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_ERROR(
      READ_ONLY_ATTRIBUTE_ERROR, READ_ONLY_ATTRIBUTE_ERROR_STR, session,
      client::set_attribute_ni_complex_double_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_SEM_RESULTS_CARRIER_FREQUENCY, complex_number_array({1.2, 2.2}, {1e6, 1.01e6})));
}

// Note: there aren't any i8 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeInt8_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i8(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, 1));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_u8(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, 1));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i8_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, {1, 0, -1, 0}));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_u8_array(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, {1, 0, 1, 0}));
}

// Note: there aren't any i16 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxSpecAnDriverApiTests, SetAttributeInt16_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663);

  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i16(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, -400));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
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

  const auto nf_external_preamp_present = GET_ATTR_I32(session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT);

  EXPECT_EQ(NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_NF_EXTERNAL_PREAMP_PRESENT_TRUE, nf_external_preamp_present);
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

  const auto digital_edge_trigger_source = GET_ATTR_STR(session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_DIGITAL_EDGE_TRIGGER_SOURCE);

  EXPECT_EQ("PFI0", digital_edge_trigger_source);
}

TEST_F(NiRFmxSpecAnDriverApiTests, BuildSpurString_ReturnsSpurString)
{
  auto session = init_session(stub(), PXI_5663);
  const auto spur_string_response = EXPECT_SUCCESS(session, client::build_spur_string(stub(), "", 0));

  EXPECT_EQ(spur_string_response.selector_string_out(), "spur0");
}

TEST_F(NiRFmxSpecAnDriverApiTests, BuildIntermodString_ReturnsIntermodString)
{
  auto session = init_session(stub(), PXI_5663);

  const auto intermod_string_response = client::build_intermod_string(stub(), "channel", 10);
  EXPECT_SUCCESS(session, intermod_string_response);

  EXPECT_EQ(intermod_string_response.selector_string_out(), "channel/intermod10");
}

TEST_F(NiRFmxSpecAnDriverApiTests, DefaultConfiguration_IQFetchData_RecordIsDeleted)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_IQ, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000);
  EXPECT_SUCCESS(session, fetch_response);
  EXPECT_THAT(fetch_response.data(), Not(IsEmpty()));

  EXPECT_ERROR(
      IQ_FETCH_DELETED_RECORD_ERROR, IQ_FETCH_DELETED_RECORD_ERROR_STR, session,
      client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000));
}

TEST_F(NiRFmxSpecAnDriverApiTests, DefaultConfiguration_IQFetchDataFetchAllAvailable_DataIsFetched)
{
  constexpr auto FETCH_ALL_AVAILABLE = -1;
  constexpr auto EXPECTED_RECORD_COUNT = 50000;
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_IQ, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = client::iq_fetch_data(stub(), session, "", 10.0, 0, FETCH_ALL_AVAILABLE);
  EXPECT_SUCCESS(session, fetch_response);

  EXPECT_THAT(fetch_response.data(), Not(IsEmpty()));
  EXPECT_EQ(EXPECTED_RECORD_COUNT, fetch_response.data().size());
}

TEST_F(NiRFmxSpecAnDriverApiTests, DisableDeleteRecordOnFetch_IQFetchData_RecordIsStillAvailable)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_IQ, true));
  EXPECT_SUCCESS(
      session,
      client::set_attribute_i32(
          stub(),
          session,
          "",
          NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_IQ_DELETE_RECORD_ON_FETCH,
          NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_IQ_DELETE_RECORD_ON_FETCH_FALSE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000);
  EXPECT_SUCCESS(session, fetch_response);
  EXPECT_THAT(fetch_response.data(), Not(IsEmpty()));
  const auto fetch_response_2 = client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000);
  EXPECT_SUCCESS(session, fetch_response_2);

  EXPECT_THAT(fetch_response_2.data(), Not(IsEmpty()));
}

TEST_F(NiRFmxSpecAnDriverApiTests, ConfigureDPDLookupTableWithNoComplexGains_Initiate_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663);
  config_dpd_reference_waveform(session);
  EXPECT_SUCCESS(session, client::dpd_cfg_apply_dpd_user_lookup_table(stub(), session, "", {1.23f, 4.56f, 7.89f}, {}));

  const auto initiate_response = client::initiate(stub(), session, "", "");

  EXPECT_SUCCESS(session, initiate_response);
}

TEST_F(NiRFmxSpecAnDriverApiTests, ConfigureDPDLookupTableWithNoInputPowers_Initiate_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663);
  config_dpd_reference_waveform(session);
  EXPECT_SUCCESS(
      session,
      client::dpd_cfg_apply_dpd_user_lookup_table(
          stub(),
          session,
          "",
          {},
          complex_f32_array({0.7f, 0.5f, 0.0f, -0.5f, -0.7f}, {-1.5f, -1.7f, -2.0f, -2.3f, -2.5f})));

  const auto initiate_response = client::initiate(stub(), session, "", "");

  EXPECT_SUCCESS(session, initiate_response);
}

TEST_F(NiRFmxSpecAnDriverApiTests, ConfigureDPDLookupTableWithBothInputs_Initiate_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663);
  config_dpd_reference_waveform(session);
  EXPECT_SUCCESS(
      session,
      client::dpd_cfg_apply_dpd_user_lookup_table(
          stub(),
          session,
          "",
          {1.23f, 4.56f, 7.89f},
          complex_f32_array({0.7f, 0.5f, 0.0f}, {-1.5f, -1.7f, -2.0f})));

  const auto initiate_response = client::initiate(stub(), session, "", "");

  EXPECT_SUCCESS(session, initiate_response);
}

void close_session(const client::StubPtr& stub, const nidevice_grpc::Session& session)
{
  EXPECT_RESPONSE_SUCCESS(client::close(stub, session, false));
}

void force_close_session(const client::StubPtr& stub, const nidevice_grpc::Session& session)
{
  EXPECT_RESPONSE_SUCCESS(client::close(stub, session, true));
}

class NiRFmxSpecAnDriverApiResourceInitTests : public NiRFmxSpecAnDriverApiTests,
                                               public ::testing::WithParamInterface<std::tuple<std::string, std::string>> {
};

// Implements a function object that can be used as the name generator
// for parameterized test suites instantiated from NiRFmxSpecAnDriverApiResourceInitTests.
class ResourceTuplePrinter {
 public:
  using ParamType = NiRFmxSpecAnDriverApiResourceInitTests::ParamType;
  std::string operator()(const TestParamInfo<ParamType>& info)
  {
    return sanitize_param<0>(info.param) + "__" + sanitize_param<1>(info.param);
  }

 private:
  // The parameterized test string can only have alphanumeric characters
  // and "_". Replace ","" with "_".
  template <size_t I>
  static std::string sanitize_param(const ParamType& param)
  {
    auto param_value = std::get<I>(param);
    auto pos = std::size_t{};
    while ((pos = param_value.find(",", pos)) != std::string::npos) {
      param_value.replace(pos, 1, "_");
    }

    if (param_value.empty()) {
      param_value = "NONAME";
    }

    return param_value;
  }
};

using ResourcePair = std::tuple<std::string, std::string>;

template <typename T>
inline std::vector<T> vector_concat(const std::vector<T>& first, const std::vector<T>& second)
{
  auto result = std::vector<T>(first);
  result.insert(result.end(), second.cbegin(), second.cend());
  return result;
}

// These will initialize as separate driver resource handles.
const auto INDEPENDENT_RESOURCES = std::vector<ResourcePair>{
    {"specan1", "specan2"},
    {"specan1,specan2", "specan3,specan4"},
    {"", ""},
    {"specan1", ""},
};

// These will initialize as the same driver resource handle, the second
// session will increment that resource's ref count.
const auto DUPLICATE_RESOURCES = std::vector<ResourcePair>{
    {"specan1", "specan1"},
    {"specan1,specan2", "specan2,specan1"},
    {"specan1,specan2", "specan1,specan2"},
    {"specan1,specan2,specan3", "specan3,specan1,specan2"},
};

// All of these are valid to initialize as separate grpc-device sessions at the same time.
// Internally, they may or may not be separate driver handles, but they will each have their
// own ref count.
const auto COMPATIBLE_RESOURCES = vector_concat(INDEPENDENT_RESOURCES, DUPLICATE_RESOURCES);

// These are conflicting because the second set overlaps the first set but IS NOT IDENTICAL.
const auto CONFLICTING_RESOURCES = std::vector<ResourcePair>{
    {"specan1", "specan1,specan2"},
    {"specan1,specan2", "specan1"},
    {"specan1,specan2", "specan1,specan2,specan3"},
};

using NiRFmxSpecAnDriverApiCompatibleResourceInitTests = NiRFmxSpecAnDriverApiResourceInitTests;
INSTANTIATE_TEST_SUITE_P(
    CompatibleResourceInitTestCases,
    NiRFmxSpecAnDriverApiCompatibleResourceInitTests,
    ValuesIn(COMPATIBLE_RESOURCES),
    ResourceTuplePrinter{});

TEST_P(NiRFmxSpecAnDriverApiCompatibleResourceInitTests, InitializeTwoCompatibleResourcesAsSeparateSessions_CloseEachSession_EachIsClosedIndependently)
{
  const auto session1 = init_session(stub(), PXI_5663, std::get<0>(GetParam()));
  const auto session2 = init_session(stub(), PXI_5663, std::get<1>(GetParam()));
  EXPECT_NE(session1.name(), session2.name());
  EXPECT_VALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);

  close_session(stub(), session1);
  EXPECT_INVALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);
  close_session(stub(), session2);
  EXPECT_INVALID_DRIVER_SESSION(session2);
}

// Same as NiRFmxSpecAnDriverApiSuccessfulResourceInitTests, but with 3 sessions instead of the standard 2.
TEST_F(NiRFmxSpecAnDriverApiTests, InitializeThreeIdenticalResourcesAsSeparateSessions_CloseEachSession_EachIsClosedIndependently)
{
  const auto session1 = init_session(stub(), PXI_5663, "specan1,specan2");
  const auto session2 = init_session(stub(), PXI_5663, "specan2,specan1");
  const auto session3 = init_session(stub(), PXI_5663, "specan1,specan2");
  EXPECT_NE(session1.name(), session2.name());
  EXPECT_NE(session1.name(), session3.name());
  EXPECT_NE(session2.name(), session3.name());
  EXPECT_VALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);
  EXPECT_VALID_DRIVER_SESSION(session3);

  close_session(stub(), session1);
  EXPECT_INVALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);
  EXPECT_VALID_DRIVER_SESSION(session3);
  close_session(stub(), session2);
  EXPECT_INVALID_DRIVER_SESSION(session2);
  EXPECT_VALID_DRIVER_SESSION(session3);
  close_session(stub(), session3);
  EXPECT_INVALID_DRIVER_SESSION(session3);
}

using NiRFmxSpecAnDriverApiIndependentResourceInitTests = NiRFmxSpecAnDriverApiResourceInitTests;
INSTANTIATE_TEST_SUITE_P(
    IndependentResourceInitTestCases,
    NiRFmxSpecAnDriverApiIndependentResourceInitTests,
    ValuesIn(INDEPENDENT_RESOURCES),
    ResourceTuplePrinter{});

TEST_P(NiRFmxSpecAnDriverApiIndependentResourceInitTests, InitializeTwoSessionsWithDifferentResources_ForceCloseOne_OtherIsStillValid)
{
  const auto session1 = init_session(stub(), PXI_5663, std::get<0>(GetParam()));
  const auto session2 = init_session(stub(), PXI_5663, std::get<1>(GetParam()));
  EXPECT_NE(session1.name(), session2.name());
  EXPECT_VALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);

  force_close_session(stub(), session1);

  EXPECT_INVALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);
}

using NiRFmxSpecAnDriverApiSameUnderlyingResourceInitTests = NiRFmxSpecAnDriverApiResourceInitTests;
INSTANTIATE_TEST_SUITE_P(
    SameUnderlyingResourceInitTestCases,
    NiRFmxSpecAnDriverApiSameUnderlyingResourceInitTests,
    ValuesIn(DUPLICATE_RESOURCES),
    ResourceTuplePrinter{});

TEST_P(NiRFmxSpecAnDriverApiSameUnderlyingResourceInitTests, InitializeTwoSessionsWithSameUnderlyingResource_ForceCloseOne_BothAreInvalid)
{
  const auto session1 = init_session(stub(), PXI_5663, std::get<0>(GetParam()));
  const auto session2 = init_session(stub(), PXI_5663, std::get<1>(GetParam()));
  EXPECT_NE(session1.name(), session2.name());
  EXPECT_VALID_DRIVER_SESSION(session1);
  EXPECT_VALID_DRIVER_SESSION(session2);

  force_close_session(stub(), session1);

  EXPECT_INVALID_DRIVER_SESSION(session1);
  EXPECT_INVALID_DRIVER_SESSION(session2);
}

using NiRFmxSpecAnDriverApiConflictingResourceInitTests = NiRFmxSpecAnDriverApiResourceInitTests;
INSTANTIATE_TEST_SUITE_P(
    ConflictingTestCases,
    NiRFmxSpecAnDriverApiConflictingResourceInitTests,
    ValuesIn(CONFLICTING_RESOURCES),
    ResourceTuplePrinter{});

TEST_P(NiRFmxSpecAnDriverApiConflictingResourceInitTests, InitializeResource_InitializeConflictingResourceSet_FailsWithDeviceInUseError)
{
  const auto session1 = init_session(stub(), PXI_5663, std::get<0>(GetParam()));
  EXPECT_VALID_DRIVER_SESSION(session1);

  EXPECT_THROW_DRIVER_ERROR({
    init(stub(), PXI_5663, std::get<1>(GetParam()));
  }, DEVICE_IN_USE_ERROR);
}

TEST_P(NiRFmxSpecAnDriverApiConflictingResourceInitTests, InitializeAndCloseResource_InitializeResourceThatWouldHaveConflicted_Succeeds)
{
  const auto session1 = init_session(stub(), PXI_5663, std::get<0>(GetParam()));
  EXPECT_VALID_DRIVER_SESSION(session1);
  close_session(stub(), session1);

  const auto second_init_response = init(stub(), PXI_5663, std::get<1>(GetParam()));

  EXPECT_SUCCESS(second_init_response.instrument(), second_init_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
