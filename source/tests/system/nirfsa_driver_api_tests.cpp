#include <gmock/gmock.h>

#include <algorithm>
#include <nlohmann/json.hpp>

#include "device_server.h"
#include "niRFSAErrors.h"
#include "nirfsa/nirfsa_client.h"
#include "niscope/niscope_client.h"
#include "nitclk/nitclk_client.h"
#include "tests/utilities/test_helpers.h"

using namespace ::testing;
using namespace nirfsa_grpc;
namespace client = nirfsa_grpc::experimental::client;
namespace nitclk_client = nitclk_grpc::experimental::client;
namespace niscope_client = niscope_grpc::experimental::client;
namespace pb = google::protobuf;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";
const auto PXI_5603 = "5603";
const auto IVI_ATTRIBUTE_NOT_SUPPORTED_ERROR = 0xBFFA0012;
const auto REF_OUT_STR = "RefOut";

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

class NiRFSADriverApiTests : public Test {
 protected:
  NiRFSADriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFSA::NewStub(device_server_->InProcessChannel()))
  {
  }

  virtual ~NiRFSADriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFSA::Stub>& stub() const
  {
    return stub_;
  }

  std::unique_ptr<nitclk_grpc::NiTClk::Stub> create_tclk_stub() const
  {
    return nitclk_grpc::NiTClk::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<niscope_grpc::NiScope::Stub> create_scope_stub() const
  {
    return niscope_grpc::NiScope::NewStub(device_server_->InProcessChannel());
  }

  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }

  void clear_error(const nidevice_grpc::Session& session)
  {
    auto response = client::clear_error(stub(), session);
    ni::tests::system::EXPECT_SUCCESS(response);
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
    check_error(session);
  }

  void EXPECT_RFSA_ERROR(int32_t expected_error, const std::string& message_substring, const nidevice_grpc::experimental::client::grpc_driver_error& ex, const nidevice_grpc::Session& session)
  {
    EXPECT_DRIVER_ERROR_WITH_SUBSTR(ex, expected_error, message_substring);
    clear_error(session);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFSA::Stub> stub_;
};

InitWithOptionsResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::init_with_options(stub, "FakeDevice", false, false, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.vi();
  EXPECT_SUCCESS(response);
  return session;
}

TEST_F(NiRFSADriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.vi();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session);

  EXPECT_SUCCESS(session, close_response);
}

TEST_F(NiRFSADriverApiTests, InitWithErrorFromDriver_ReturnsDriverErrorWithUserErrorMessage)
{
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR({
    client::init_with_options(stub(), "", false, false, "");
  }, -200220, "Device identifier is invalid.");
}

MATCHER(IsNonDefaultComplexArray, "")
{
  return std::all_of(
      arg.cbegin(),
      arg.cend(),
      [](const auto& val) { return (val.real() != 0 && val.imaginary() != 0); });
}

TEST_F(NiRFSADriverApiTests, ConfigureGettingStartedIQ_FetchIQSingleRecordComplexF64_ReturnsData)
{
  const auto NUMBER_OF_SAMPLES = 1000;
  auto session = init_session(stub(), PXI_5663E);
  auto configure_clock = client::configure_ref_clock(stub(), session, RefClockSource::REF_CLOCK_SOURCE_ONBOARD_CLOCK, 10e6);
  auto configure_reference_level = client::configure_reference_level(stub(), session, "", 0);
  auto configure_acquisition_type = client::configure_acquisition_type(stub(), session, AcquisitionType::ACQUISITION_TYPE_IQ);
  auto configure_number_of_samples = client::configure_number_of_samples(stub(), session, "", true, 1000);
  auto configure_iq_rate = client::configure_iq_rate(stub(), session, "", 1e6);
  EXPECT_SUCCESS(session, configure_clock);
  EXPECT_SUCCESS(session, configure_reference_level);
  EXPECT_SUCCESS(session, configure_acquisition_type);
  EXPECT_SUCCESS(session, configure_number_of_samples);
  EXPECT_SUCCESS(session, configure_iq_rate);

  auto fetch_record = client::read_iq_single_record_complex_f64(stub(), session, "", 10.0, NUMBER_OF_SAMPLES);

  EXPECT_SUCCESS(session, fetch_record);
  EXPECT_EQ(NUMBER_OF_SAMPLES, fetch_record.data().size());
  EXPECT_THAT(fetch_record.data(), IsNonDefaultComplexArray());
  EXPECT_EQ(0, fetch_record.wfm_info().absolute_initial_x());
  EXPECT_EQ(NUMBER_OF_SAMPLES, fetch_record.wfm_info().actual_samples());
  EXPECT_EQ(1, fetch_record.wfm_info().gain());
  EXPECT_NEAR(1e-06, fetch_record.wfm_info().x_increment(), 1e-08);
}

TEST_F(NiRFSADriverApiTests, ConfigureGettingStartedIQ_FetchIQMultiRecordComplexF32_ReturnsData)
{
  const auto NUMBER_OF_SAMPLES = 10;
  const auto NUMBER_OF_RECORDS = 2;
  auto session = init_session(stub(), PXI_5663E);
  auto configure_acquisition_type = client::configure_acquisition_type(stub(), session, AcquisitionType::ACQUISITION_TYPE_IQ);
  auto configure_number_of_samples = client::configure_number_of_samples(stub(), session, "", true, NUMBER_OF_SAMPLES);
  auto configure_number_of_records = client::configure_number_of_records(stub(), session, "", true, NUMBER_OF_RECORDS);
  EXPECT_SUCCESS(session, configure_acquisition_type);
  EXPECT_SUCCESS(session, configure_number_of_samples);
  EXPECT_SUCCESS(session, configure_number_of_records);

  auto initiate = client::initiate(stub(), session);
  auto fetch_record = client::fetch_iq_multi_record_complex_f32(stub(), session, "", 0, NUMBER_OF_RECORDS, NUMBER_OF_SAMPLES, 10.0);

  EXPECT_SUCCESS(session, fetch_record);
  EXPECT_EQ(NUMBER_OF_SAMPLES * NUMBER_OF_RECORDS, fetch_record.data().size());
  EXPECT_THAT(fetch_record.data(), IsNonDefaultComplexArray());
  EXPECT_EQ(NUMBER_OF_RECORDS, fetch_record.wfm_info().size());
}

TEST_F(NiRFSADriverApiTests, ConfigureGettingStartedIQ_FetchIQSingleRecordComplexI16_ReturnsData)
{
  const auto NUMBER_OF_SAMPLES = 10;
  auto session = init_session(stub(), PXI_5663E);
  auto configure_acquisition_type = client::configure_acquisition_type(stub(), session, AcquisitionType::ACQUISITION_TYPE_IQ);
  auto configure_number_of_samples = client::configure_number_of_samples(stub(), session, "", true, NUMBER_OF_SAMPLES);
  EXPECT_SUCCESS(session, configure_acquisition_type);
  EXPECT_SUCCESS(session, configure_number_of_samples);

  auto initiate = client::initiate(stub(), session);
  auto fetch_record = client::fetch_iq_single_record_complex_i16(stub(), session, "", 0, NUMBER_OF_SAMPLES, 10.0);

  EXPECT_SUCCESS(session, fetch_record);
  EXPECT_EQ(NUMBER_OF_SAMPLES, fetch_record.data().size());
  EXPECT_THAT(fetch_record.data(), IsNonDefaultComplexArray());
}

TEST_F(NiRFSADriverApiTests, ConfigureGettingStartedSpectrum_ReadPowerSpectrumF64_ReturnsSpectrumData)
{
  auto session = init_session(stub(), PXI_5663E);
  auto configure_clock = client::configure_ref_clock(stub(), session, std::string("OnboardClock"), 10e6);
  auto configure_reference_level = client::configure_reference_level(stub(), session, "", 0);
  auto configure_acquisition_type = client::configure_acquisition_type(stub(), session, AcquisitionType::ACQUISITION_TYPE_SPECTRUM);
  auto configure_frequency_start_stop = client::configure_spectrum_frequency_start_stop(stub(), session, "", 990e6, 1010e6);
  auto configure_resolution_bandwidth = client::configure_resolution_bandwidth(stub(), session, "", 10e3);
  auto number_of_spectral_lines = client::get_number_of_spectral_lines(stub(), session, "");
  EXPECT_SUCCESS(session, configure_clock);
  EXPECT_SUCCESS(session, configure_reference_level);
  EXPECT_SUCCESS(session, configure_acquisition_type);
  EXPECT_SUCCESS(session, configure_frequency_start_stop);
  EXPECT_SUCCESS(session, configure_resolution_bandwidth);
  EXPECT_SUCCESS(session, number_of_spectral_lines);
  EXPECT_EQ(4974, number_of_spectral_lines.number_of_spectral_lines());

  auto power_spectrum = client::read_power_spectrum_f64(
      stub(),
      session,
      "",
      10.0,
      number_of_spectral_lines.number_of_spectral_lines());
  EXPECT_SUCCESS(session, power_spectrum);
  auto max_power_iter = std::max_element(
      power_spectrum.power_spectrum_data().cbegin(),
      power_spectrum.power_spectrum_data().cend());
  EXPECT_NE(0.0, *max_power_iter);
  EXPECT_THAT(power_spectrum.power_spectrum_data(), Each(Ne(0.0)));
  EXPECT_EQ(
      power_spectrum.spectrum_info().number_of_spectral_lines(),
      number_of_spectral_lines.number_of_spectral_lines());
  EXPECT_NE(0.0, power_spectrum.spectrum_info().initial_frequency());
  EXPECT_NE(0.0, power_spectrum.spectrum_info().frequency_increment());
}

TEST_F(NiRFSADriverApiTests, GetDeviceResponse_ReturnsResponseData)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::get_device_response(stub(), session, "", DeviceResponse::DEVICE_RESPONSE_DOWNCONVERTER_IF_RESPONSE);

  const auto EXPECTED_SIZE = 81;
  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(response.frequencies(), Each(Not(Eq(0))));
  EXPECT_THAT(response.phase_response(), Each(Eq(0)));
  EXPECT_THAT(response.magnitude_response(), Each(Eq(0)));
  EXPECT_EQ(EXPECTED_SIZE, response.frequencies().size());
  EXPECT_EQ(EXPECTED_SIZE, response.phase_response().size());
  EXPECT_EQ(EXPECTED_SIZE, response.magnitude_response().size());
}

// TODO: AB#1639825. This currently fails because of an off-by-one error.
TEST_F(NiRFSADriverApiTests, GetRelayName_ReturnsRelayName)
{
  auto session = init_session(stub(), PXI_5603);
  auto response = client::get_relay_name(stub(), session, "", 1);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ("Cal Tone Path Switch", response.name());
}

TEST_F(NiRFSADriverApiTests, GetRelayOperationsCount_ReturnsOperationCounts)
{
  const auto EXPECTED = std::vector<pb::int32>{0, 0, 0, 0};
  auto session = init_session(stub(), PXI_5603);
  auto response = client::get_relay_operations_count(stub(), session, "");

  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(
      response.operations_count(),
      ElementsAreArray(EXPECTED.cbegin(), EXPECTED.cend()));
}

TEST_F(NiRFSADriverApiTests, ConfigureDigitalEdgeRefTrigger_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::configure_digital_edge_ref_trigger(
      stub(),
      session,
      DigitalEdgeTriggerSource::DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0,
      DigitalEdge::DIGITAL_EDGE_RISING_EDGE,
      10);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSADriverApiTests, ReconfigureExportedRefClockOutTerminal_UpdatesRefClockSuccessfully)
{
  auto session = init_session(stub(), PXI_5663E);
  auto initial_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);
  auto set_response = client::set_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL,
      NiRFSAStringAttributeValuesMapped::NIRFSA_STRING_REF_CLOCK_OUT_TERMINAL_REF_OUT);
  auto get_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(REF_OUT_STR, get_response.value());
}

TEST_F(NiRFSADriverApiTests, ReconfigureFFTWindowType_UpdatesFFTWindowSuccessfully)
{
  auto session = init_session(stub(), PXI_5663E);
  auto initial_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FFT_WINDOW_TYPE);
  auto set_response = client::set_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FFT_WINDOW_TYPE,
      NiRFSAInt32AttributeValues::NIRFSA_INT32_FFT_WINDOW_TYPE_GAUSSIAN);
  auto get_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FFT_WINDOW_TYPE);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(
      NiRFSAInt32AttributeValues::NIRFSA_INT32_FFT_WINDOW_TYPE_GAUSSIAN,
      get_response.value());
}

TEST_F(NiRFSADriverApiTests, ExportSignal_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::export_signal(
      stub(),
      session,
      Signal::SIGNAL_START_TRIGGER,
      "",
      ExportTerminal::EXPORT_TERMINAL_REF_OUT);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSADriverApiTests, DisableFractionalResampling_FractionalResamplingIsDisabled)
{
  auto session = init_session(stub(), PXI_5663E);
  auto initial_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_ENABLE_FRACTIONAL_RESAMPLING);
  auto set_response = client::set_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_ENABLE_FRACTIONAL_RESAMPLING,
      false);
  auto get_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_ENABLE_FRACTIONAL_RESAMPLING);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_FALSE(get_response.value());
}

TEST_F(NiRFSADriverApiTests, ReconfigureIQRate_UpdatesIQRateSuccessfully)
{
  auto NEW_RATE = 1.2e6;
  auto session = init_session(stub(), PXI_5663E);
  auto initial_response = client::get_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_IQ_RATE);
  auto set_response = client::set_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_IQ_RATE,
      NEW_RATE);
  auto get_response = client::get_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_IQ_RATE);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_NEAR(NEW_RATE, get_response.value(), .0001);
}

TEST_F(NiRFSADriverApiTests, ReconfigureFetchOffset_UpdatesFetchOffsetSuccessfully)
{
  const auto NEW_OFFSET = 100ULL;
  auto session = init_session(stub(), PXI_5663E);
  auto initial_response = client::get_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FETCH_OFFSET);
  auto set_response = client::set_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FETCH_OFFSET,
      NEW_OFFSET);
  auto get_response = client::get_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_FETCH_OFFSET);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(NEW_OFFSET, get_response.value());
}

// NOTE: disabled because this test requires a 58XX device. Simulating a 58XX hangs on shutdown.
// FIXED in RFSA 21.5 (in development as of this comment).
TEST_F(NiRFSADriverApiTests, DISABLED_ReconfigureDowncoverterMode_UpdatesDownconverterModeSuccessfully)
{
  constexpr auto USER_DEFINED = NiRFSAInt32AttributeValues::NIRFSA_INT32_DOWNCONVERTER_FREQUENCY_OFFSET_MODE_USER_DEFINED;
  constexpr auto ENABLED = NiRFSAInt32AttributeValues::NIRFSA_INT32_DOWNCONVERTER_FREQUENCY_OFFSET_MODE_ENABLED;
  const auto session = init_session(stub(), "5841");
  // Per nirfsa.sub: "NOTE: You must set this attribute to enable the NIRFSA_ATTR_DOWNCONVERTER_FREQUENCY_OFFSET_MODE attribute."
  const auto bandwidth_response = client::set_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_SIGNAL_BANDWIDTH,
      1e4);
  const auto initial_response = client::get_attribute_vi_int32(stub(), session, "", NiRFSAAttribute::NIRFSA_ATTRIBUTE_DOWNCONVERTER_FREQUENCY_OFFSET_MODE);
  // Toggle the mode since it persists between sessions.
  const auto new_mode = (initial_response.value() == USER_DEFINED) ? ENABLED : USER_DEFINED;
  const auto set_response = client::set_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_DOWNCONVERTER_FREQUENCY_OFFSET_MODE,
      new_mode);
  const auto get_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_DOWNCONVERTER_FREQUENCY_OFFSET_MODE);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(new_mode, get_response.value());
}

TEST_F(NiRFSADriverApiTests, CreateConfigurationList_Succeeds)
{
  const auto LIST_NAME = "MyList";
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::create_configuration_list(
      stub(),
      session,
      LIST_NAME,
      {NiRFSAAttribute::NIRFSA_ATTRIBUTE_EXTERNAL_GAIN, NiRFSAAttribute::NIRFSA_ATTRIBUTE_DEVICE_INSTANTANEOUS_BANDWIDTH},
      true);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSADriverApiTests, CreateConfigurationListWithInvalidAttribute_ReportsError)
{
  const auto LIST_NAME = "MyList";
  auto session = init_session(stub(), PXI_5663E);

  EXPECT_THROW({
    try {
      client::create_configuration_list(
          stub(),
          session,
          LIST_NAME,
          {NiRFSAAttribute::NIRFSA_ATTRIBUTE_EXTERNAL_GAIN, NiRFSAAttribute::NIRFSA_ATTRIBUTE_NOTCH_FILTER_ENABLED},
          true);
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      EXPECT_RFSA_ERROR(IVI_ATTRIBUTE_NOT_SUPPORTED_ERROR, "Attribute or property not supported.", ex, session);
      throw;
    }
  }, nidevice_grpc::experimental::client::grpc_driver_error);
}

TEST_F(NiRFSADriverApiTests, GetScalingCoefficients_ReturnsCoefficients)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::get_scaling_coefficients(
      stub(),
      session,
      "");

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(1, response.coefficient_info().size());
  EXPECT_NE(0.0, response.coefficient_info()[0].gain());
  EXPECT_EQ(0.0, response.coefficient_info()[0].offset());
}

TEST_F(NiRFSADriverApiTests, GetNormalizationCoefficients_ReturnsCoefficients)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::get_normalization_coefficients(
      stub(),
      session,
      "");

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(1, response.coefficient_info().size());
  EXPECT_NE(0.0, response.coefficient_info()[0].gain());
  EXPECT_EQ(0.0, response.coefficient_info()[0].offset());
}

TEST_F(NiRFSADriverApiTests, ConfiguredSpectrumAcquisition_GetSpectralInfoForSmt_ReturnsSpectralInforForSmt)
{
  auto session = init_session(stub(), PXI_5663E);
  auto spectral_lines = client::get_number_of_spectral_lines(stub(), session, "");
  auto configure_acquisition_type = client::configure_acquisition_type(
      stub(),
      session,
      AcquisitionType::ACQUISITION_TYPE_SPECTRUM);
  auto power_spectrum = client::read_power_spectrum_f64(stub(), session, "", 10.0, spectral_lines.number_of_spectral_lines());
  auto response = client::get_spectral_info_for_smt(stub(), session);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(312, response.spectrum_info().fft_size());
  EXPECT_EQ(1, response.spectrum_info().linear_db());
  EXPECT_EQ(2, response.spectrum_info().spectrum_type());
  EXPECT_EQ(312, response.spectrum_info().window_size());
  EXPECT_EQ(8, response.spectrum_info().window());
}

TEST_F(NiRFSADriverApiTests, TwoSessions_SetupTclkSyncPulseSenderSynchronization_Succeeds)
{
  auto first_session = init_session(stub(), PXI_5663E);
  auto second_session = init_session(stub(), PXI_5663E);

  auto tclk_stub = create_tclk_stub();
  auto result = nitclk_client::setup_for_sync_pulse_sender_synchronize(tclk_stub, {first_session, second_session}, 0);

  EXPECT_SUCCESS(first_session, result);
}

TEST_F(NiRFSADriverApiTests, SelfCalibrateWithStepsToOmit_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  const auto response = client::self_calibrate(stub(), session, SelfCalibrateSteps::SELF_CALIBRATE_STEPS_ALIGNMENT);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSADriverApiTests, IsSelfCalValid)
{
  auto session = init_session(stub(), PXI_5663E);
  const auto response = client::is_self_cal_valid(stub(), session);

  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(response.valid_steps_array(), ElementsAre(SELF_CALIBRATE_STEPS_DIGITIZER_SELF_CAL));
  EXPECT_EQ(SELF_CALIBRATE_STEPS_DIGITIZER_SELF_CAL, response.valid_steps_raw());
}

TEST_F(NiRFSADriverApiTests, SelfTest_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  const auto response = client::self_test(stub(), session);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ("PASS", response.test_message());
}

TEST_F(NiRFSADriverApiTests, ErrorMessage_ReturnsErrorMessage)
{
  auto session = init_session(stub(), PXI_5663E);
  const auto response = client::error_message(stub(), session, IVI_ATTRIBUTE_NOT_SUPPORTED_ERROR);

  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(
      response.error_message(),
      HasSubstr("Attribute or property not supported."));
}

TEST_F(NiRFSADriverApiTests, GetCalUserDefinedInfo_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  const auto response = client::get_cal_user_defined_info(stub(), session);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(
      "Simulated Device",
      response.info());
}

// NOTE: disabled because this test requires a 58XX device. Simulating a 58XX hangs on shutdown.
// FIXED in RFSA 21.5 (in development as of this comment).
TEST_F(NiRFSADriverApiTests, DISABLED_GetDeembeddingCompensationGain_Succeeds)
{
  auto session = init_session(stub(), "5830");

  const auto deembedding_type = client::set_attribute_vi_int32(
      stub(),
      session,
      "if1",
      NiRFSAAttribute::NIRFSA_ATTRIBUTE_DEEMBEDDING_TYPE,
      NiRFSAInt32AttributeValues::NIRFSA_INT32_DEEMBEDDING_TYPE_SCALAR);
  const auto compensation_gain = client::get_attribute_vi_real64(stub(), session, "", NiRFSAAttribute::NIRFSA_ATTRIBUTE_DEEMBEDDING_COMPENSATION_GAIN);

  EXPECT_NEAR(0.0, compensation_gain.value(), 1e-6);
  EXPECT_SUCCESS(session, compensation_gain);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
