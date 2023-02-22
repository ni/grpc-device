#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxwcdma/nirfmxwcdma_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxwcdma_grpc;
namespace client = nirfmxwcdma_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxWCDMADriverApiTests : public Test {
 protected:
  NiRFmxWCDMADriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxWCDMA::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxWCDMADriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxWCDMA::Stub>& stub() const
  {
    return stub_;
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxWCDMA::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

TEST_F(NiRFmxWCDMADriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxWCDMADriverApiTests, AcpMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_CARRIERS = 2;
  const auto NUMBER_OF_OFFSETS = 2;
  const std::vector<int> empty_int_vec;

  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1.95e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_contiguous_carriers(stub(), session, "", NUMBER_OF_CARRIERS, -1));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 0.01));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", 2));
  EXPECT_SUCCESS(session, client::acp_cfg_offset_power_reference(stub(), session, "", ACP_OFFSET_POWER_REFERENCE_CARRIER_COMPOSITE, 0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<ACPFetchAbsolutePowersTraceResponse> acp_fetch_absolute_powers_trace_response_vec;
  std::vector<ACPFetchRelativePowersTraceResponse> acp_fetch_relative_powers_trace_response_vec;
  const auto acp_fetch_offset_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_carrier_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_carrier_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_total_carrier_power_response = EXPECT_SUCCESS(session, client::acp_fetch_total_carrier_power(stub(), session, "", 10.0));
  const auto acp_fetch_spectrum_response = EXPECT_SUCCESS(session, client::acp_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_SUCCESS(session, acp_fetch_carrier_measurement_array_response);
  EXPECT_EQ(2, acp_fetch_carrier_measurement_array_response.absolute_power_size());
  EXPECT_EQ(2, acp_fetch_carrier_measurement_array_response.absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_carrier_measurement_array_response.absolute_power(0));
  EXPECT_EQ(2, acp_fetch_carrier_measurement_array_response.relative_power_size());
  EXPECT_EQ(2, acp_fetch_carrier_measurement_array_response.relative_power().size());
  EXPECT_GT(0.0, acp_fetch_carrier_measurement_array_response.relative_power(0));
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_total_carrier_power_response);
  EXPECT_GT(0.0, acp_fetch_total_carrier_power_response.total_carrier_power());
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_LT(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(19801, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(19801, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, AcpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 2;

  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1.95e9 ));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "",  RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 0.01));

  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  const auto acp_fetch_carrier_measurement_response = client::acp_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_carrier_measurement_response);
  EXPECT_LT(0.0, acp_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_LT(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(16465, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(16465, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, ChpMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_CARRIERS = 2;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_contiguous_carriers(stub(), session, "", NUMBER_OF_CARRIERS, -1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_carrier_measurement_array_response = client::chp_fetch_carrier_measurement_array(stub(), session, "", 10.0);
  const auto chp_fetch_total_carrier_power_response = client::chp_fetch_total_carrier_power(stub(), session, "", 10.0);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, chp_fetch_carrier_measurement_array_response);
  EXPECT_EQ(2, chp_fetch_carrier_measurement_array_response.absolute_power_size());
  EXPECT_EQ(2, chp_fetch_carrier_measurement_array_response.absolute_power().size());
  EXPECT_GT(0.0, chp_fetch_carrier_measurement_array_response.absolute_power(0));
  EXPECT_GT(0.0, chp_fetch_carrier_measurement_array_response.absolute_power(1));
  EXPECT_EQ(2, chp_fetch_carrier_measurement_array_response.relative_power_size());
  EXPECT_EQ(2, chp_fetch_carrier_measurement_array_response.relative_power().size());
  EXPECT_GT(0.0, chp_fetch_carrier_measurement_array_response.relative_power(0));
  EXPECT_GT(0.0, chp_fetch_carrier_measurement_array_response.relative_power(1));
  EXPECT_SUCCESS(session, chp_fetch_total_carrier_power_response);
  EXPECT_LT(0.0, chp_fetch_total_carrier_power_response.total_carrier_power());
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_LT(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(8401, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(8401, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, ChpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_carrier_measurement_response = EXPECT_SUCCESS(session, client::chp_fetch_carrier_measurement(stub(), session, "", 10.0));
  const auto chp_fetch_spectrum_response = EXPECT_SUCCESS(session, client::chp_fetch_spectrum(stub(), session, "", 10.0));
  EXPECT_SUCCESS(session, chp_fetch_carrier_measurement_response);
  EXPECT_NEAR(0.0, chp_fetch_carrier_measurement_response.absolute_power(), 10);
  EXPECT_NEAR(0.0, chp_fetch_carrier_measurement_response.relative_power(), 10);
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_LT(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(4201, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(4201, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, CdaFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling(stub(), session, "", 0, UPLINK_SCRAMBLING_TYPE_LONG));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CDA, true));
  EXPECT_SUCCESS(session, client::cda_cfg_synchronization_mode_and_interval(stub(), session, "", CDA_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::cda_cfg_measurement_channel(stub(), session, "", 256, 0, CDA_MEASUREMENT_CHANNEL_MODULATION_TYPE_BPSK_QPSK, BRANCH_Q));
  EXPECT_SUCCESS(session, client::cda_cfg_power_unit(stub(), session, "", CDA_POWER_UNIT_DB));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto cda_fetch_symbol_evm_response = EXPECT_SUCCESS(session, client::cda_fetch_symbol_evm(stub(), session, "", 10.0));
  const auto cda_fetch_code_domain_power_response = EXPECT_SUCCESS(session, client::cda_fetch_code_domain_power(stub(), session, "", 10.0));
  const auto cda_fetch_code_domain_i_and_q_power_response = EXPECT_SUCCESS(session, client::cda_fetch_code_domain_i_and_q_power(stub(), session, "", 10.0));
  const auto cda_fetch_symbol_evm_trace_response = EXPECT_SUCCESS(session, client::cda_fetch_symbol_evm_trace(stub(), session, "", 10.0));
  const auto cda_fetch_code_domain_i_and_q_power_trace_response = EXPECT_SUCCESS(session, client::cda_fetch_code_domain_i_and_q_power_trace(stub(), session, "", 10.0));

  EXPECT_SUCCESS(session, cda_fetch_symbol_evm_response);
  EXPECT_LT(0.0, cda_fetch_symbol_evm_response.rms_symbol_evm());
  EXPECT_LT(0.0, cda_fetch_symbol_evm_response.peak_symbol_evm());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.rms_symbol_magnitude_error());
  EXPECT_LT(0.0, cda_fetch_symbol_evm_response.rms_symbol_phase_error());
  EXPECT_GT(0.0, cda_fetch_symbol_evm_response.mean_symbol_power());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.chip_rate_error());
  EXPECT_SUCCESS(session, cda_fetch_code_domain_power_response);
  EXPECT_LE(0.0, cda_fetch_code_domain_power_response.total_power());
  EXPECT_NEAR(0.0, cda_fetch_code_domain_power_response.total_active_power(), 10);
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.mean_inactive_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.peak_inactive_power()));
  EXPECT_SUCCESS(session, cda_fetch_code_domain_i_and_q_power_response);
  EXPECT_NE(0.0, cda_fetch_code_domain_i_and_q_power_response.i_mean_active_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_i_and_q_power_response.q_mean_active_power());
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.i_peak_inactive_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.q_peak_inactive_power()));
  EXPECT_SUCCESS(session, cda_fetch_symbol_evm_trace_response);
  EXPECT_EQ(10, cda_fetch_symbol_evm_trace_response.symbol_evm_size());
  EXPECT_EQ(10, cda_fetch_symbol_evm_trace_response.symbol_evm().size());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_trace_response.symbol_evm(0));
  EXPECT_SUCCESS(session, cda_fetch_code_domain_i_and_q_power_trace_response);
  EXPECT_EQ(256, cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers_size());
  EXPECT_EQ(256, cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers().size());
  EXPECT_NE(0.0, cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers(0));
  EXPECT_EQ(256, cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers_size());
  EXPECT_EQ(256, cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers().size());
  EXPECT_NE(0.0, cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, ModAccMarkerModeFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_USER_DEFINED_CHANNELS = 2;
  std::vector<int> spreadingFactor {256,64};
  std::vector<int> spreadingCode {0,16};
  std::vector<int> modulationType {MODULATION_TYPE_BPSK_QPSK, MODULATION_TYPE_BPSK_QPSK};
  std::vector<int> branch {BRANCH_Q, BRANCH_I};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, true));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling(stub(), session, "", 0x0, UPLINK_SCRAMBLING_TYPE_LONG));
  EXPECT_SUCCESS(session, client::cfg_channel_configuration_mode(stub(), session, "", CHANNEL_CONFIGURATION_MODE_TEST_MODEL));
  EXPECT_SUCCESS(session, client::cfg_uplink_test_model(stub(), session, "", UPLINK_TEST_MODEL_R6C_2_1));  
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_MARKER, 0, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_reference_waveform_response = client::mod_acc_fetch_reference_waveform(stub(), session, "", 10.0);  
  std::vector<nidevice_grpc::NIComplexNumberF32> reference_waveform;
  for( int i = 0; i< mod_acc_fetch_reference_waveform_response.reference_waveform_size(); i++)
  {
    reference_waveform.push_back( mod_acc_fetch_reference_waveform_response.reference_waveform(i));
  }

  EXPECT_SUCCESS(session, client::mod_acc_cfg_reference_waveform(stub(), session, "", mod_acc_fetch_reference_waveform_response.x0(), mod_acc_fetch_reference_waveform_response.dx(), reference_waveform));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  const auto mod_acc_fetch_evm_response = client::mod_acc_fetch_evm(stub(), session, "", 10.0);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto mod_acc_fetch_peak_cde_response = client::mod_acc_fetch_peak_cde(stub(), session, "", 10.0);
  const auto mod_acc_fetch_peak_active_cde_response = client::mod_acc_fetch_peak_active_cde(stub(), session, "", 10.0);
  const auto mod_acc_fetch_rcde_response = client::mod_acc_fetch_rcde(stub(), session, "", 10.0);
  const auto mod_acc_fetch_evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, mod_acc_fetch_reference_waveform_response);
  EXPECT_EQ(0.0, mod_acc_fetch_reference_waveform_response.x0());
  EXPECT_LT(0.0, mod_acc_fetch_reference_waveform_response.dx());
  EXPECT_LT(0.0, mod_acc_fetch_reference_waveform_response.reference_waveform(0).real());
  EXPECT_LT(0.0, mod_acc_fetch_reference_waveform_response.reference_waveform(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_response);
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_evm());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.peak_evm());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rho());
  EXPECT_NE(0.0, mod_acc_fetch_evm_response.frequency_error());
  EXPECT_EQ(0.0, mod_acc_fetch_evm_response.chip_rate_error());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_magnitude_error());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_response.iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_quadrature_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_cde_response);
  EXPECT_LT(0.0, mod_acc_fetch_peak_cde_response.peak_cde());
  EXPECT_LE(0, mod_acc_fetch_peak_cde_response.peak_cde_code());
  EXPECT_LE(0, mod_acc_fetch_peak_cde_response.peak_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_active_cde_response);
  EXPECT_LT(0.0, mod_acc_fetch_peak_active_cde_response.peak_active_cde());
  EXPECT_EQ(64, mod_acc_fetch_peak_active_cde_response.peak_active_cde_spreading_factor());
  EXPECT_EQ(16, mod_acc_fetch_peak_active_cde_response.peak_active_cde_code());
  EXPECT_EQ(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_rcde_response);
  EXPECT_LT(0.0, mod_acc_fetch_rcde_response.peak_rcde());
  EXPECT_LE(64, mod_acc_fetch_rcde_response.peak_rcde_spreading_factor());
  EXPECT_LE(0, mod_acc_fetch_rcde_response.peak_rcde_code());
  EXPECT_LE(0, mod_acc_fetch_rcde_response.peak_rcde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_LT(0.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_LT(2000, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_LT(2000, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_trace_response.evm(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).imaginary());
}

TEST_F(NiRFmxWCDMADriverApiTests, ModAccSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  nidevice_grpc::Session session;

  session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling(stub(), session, "", 0, UPLINK_SCRAMBLING_TYPE_LONG));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true)); 
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));  
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_evm_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm(stub(), session, "", 10.0));
  const auto mod_acc_fetch_iq_impairments_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0));
  const auto mod_acc_fetch_peak_cde_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_peak_cde(stub(), session, "", 10.0));
  const auto mod_acc_fetch_peak_active_cde_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_peak_active_cde(stub(), session, "", 10.0));
  const auto mod_acc_fetch_rcde_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_rcde(stub(), session, "", 10.0));
  const auto mod_acc_fetch_evm_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_trace(stub(), session, "", 10.0));
  const auto mod_acc_fetch_constellation_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0));
  
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_response);
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_evm());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.peak_evm());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rho());
  EXPECT_NE(0.0, mod_acc_fetch_evm_response.frequency_error());
  EXPECT_NE(0.0, mod_acc_fetch_evm_response.chip_rate_error());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_magnitude_error());
  EXPECT_LT(0.0, mod_acc_fetch_evm_response.rms_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_response.iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_quadrature_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_cde_response);
  EXPECT_GT(0.0, mod_acc_fetch_peak_cde_response.peak_cde());
  EXPECT_LE(0, mod_acc_fetch_peak_cde_response.peak_cde_code());
  EXPECT_LE(0, mod_acc_fetch_peak_cde_response.peak_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_active_cde_response);
  EXPECT_GT(0.0, mod_acc_fetch_peak_active_cde_response.peak_active_cde());
  EXPECT_EQ(2, mod_acc_fetch_peak_active_cde_response.peak_active_cde_spreading_factor());
  EXPECT_LE(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_code());
  EXPECT_LE(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_rcde_response);
  EXPECT_GT(0.0, mod_acc_fetch_rcde_response.peak_rcde());
  EXPECT_LE(0, mod_acc_fetch_rcde_response.peak_rcde_spreading_factor());
  EXPECT_LE(0, mod_acc_fetch_rcde_response.peak_rcde_code());
  EXPECT_LE(0, mod_acc_fetch_rcde_response.peak_rcde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_LT(0.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_EQ(2560, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_EQ(2560, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_trace_response.evm(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_EQ(2560, mod_acc_fetch_constellation_trace_response.constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).imaginary());
}

TEST_F(NiRFmxWCDMADriverApiTests, ObwMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.00, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_contiguous_carriers(stub(), session, "", 2, -1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_spectrum_response = EXPECT_SUCCESS(session, client::obw_fetch_spectrum(stub(), session, "", 10.0));
  const auto obw_fetch_measurement_response = EXPECT_SUCCESS(session, client::obw_fetch_measurement(stub(), session, "", 10.0));

  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_LT(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(13337, obw_fetch_spectrum_response.actual_array_size());
  EXPECT_EQ(13337, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, obw_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
}

TEST_F(NiRFmxWCDMADriverApiTests, ObwSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_LT(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(6673, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(6673, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, obw_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, QevmFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_QEVM, true));
  EXPECT_SUCCESS(session, client::qevm_cfg_averaging(stub(), session, "", QEVM_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::qevm_cfg_measurement_length(stub(), session, "", 2560));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  QEVMFetchEVMTraceResponse qevm_fetch_evm_trace_response;
  QEVMFetchConstellationTraceResponse qevm_fetch_constellation_trace_response;
  const auto qevm_fetch_evm_response = client::qevm_fetch_evm(stub(), session, "", 10.0);
  const auto qevm_fetch_iq_impairments_response = client::qevm_fetch_iq_impairments(stub(), session, "", 10.0);
   qevm_fetch_evm_trace_response = client::qevm_fetch_evm_trace(stub(), session, "", 10.0);
   qevm_fetch_constellation_trace_response = client::qevm_fetch_constellation_trace(stub(), session, "", 10.0);

  EXPECT_RESPONSE_WARNING(375920, qevm_fetch_evm_response);
  EXPECT_LT(0.0, qevm_fetch_evm_response.mean_rms_evm());
  EXPECT_LT(0.0, qevm_fetch_evm_response.maximum_peak_evm());
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_frequency_error());
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_magnitude_error());
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_phase_error());
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_chip_rate_error());
  EXPECT_RESPONSE_WARNING(375920, qevm_fetch_iq_impairments_response);
  EXPECT_GT(0.0, qevm_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.mean_iq_gain_imbalance()));
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.mean_iq_quadrature_error()));
  EXPECT_GT(0.0, qevm_fetch_iq_impairments_response.maximum_iq_origin_offset());
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.maximum_iq_gain_imbalance()));
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.maximum_iq_quadrature_error()));
  EXPECT_RESPONSE_WARNING(375920, qevm_fetch_evm_trace_response);
  EXPECT_EQ(0.0, qevm_fetch_evm_trace_response.x0());
  EXPECT_LT(0.0, qevm_fetch_evm_trace_response.dx());
  EXPECT_EQ(2560, qevm_fetch_evm_trace_response.evm_size());
  EXPECT_EQ(2560, qevm_fetch_evm_trace_response.evm().size());
  EXPECT_LT(0.0, qevm_fetch_evm_trace_response.evm(0));
  EXPECT_RESPONSE_WARNING(375920, qevm_fetch_constellation_trace_response);
  EXPECT_NE(0.0, qevm_fetch_constellation_trace_response.constellation(0).real());
  EXPECT_NE(0.0, qevm_fetch_constellation_trace_response.constellation(0).imaginary());
}


TEST_F(NiRFmxWCDMADriverApiTests, SemSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.00, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.000667));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  

  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_carrier_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));

  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_integrated_power());
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(16003, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(16003, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxWCDMADriverApiTests, SlotPowerFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.00, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling(stub(), session, "", 0, UPLINK_SCRAMBLING_TYPE_LONG));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPOWER, true));
  EXPECT_SUCCESS(session, client::slot_power_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_POWER_SYNCHRONIZATION_MODE_SLOT, 0, 15));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto slot_power_fetch_powers_response = EXPECT_SUCCESS(session, client::slot_power_fetch_powers(stub(), session, "", 10.0));

  EXPECT_SUCCESS(session, slot_power_fetch_powers_response);
  EXPECT_EQ(15, slot_power_fetch_powers_response.slot_power_size());
  EXPECT_EQ(15, slot_power_fetch_powers_response.slot_power().size());
  EXPECT_LT(0.0, slot_power_fetch_powers_response.slot_power(0));
  EXPECT_EQ(15, slot_power_fetch_powers_response.slot_power_delta_size());
  EXPECT_EQ(15, slot_power_fetch_powers_response.slot_power_delta().size());
  EXPECT_TRUE(isnan(slot_power_fetch_powers_response.slot_power_delta(0)));
}

TEST_F(NiRFmxWCDMADriverApiTests, SlotPhaseFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.00, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPHASE, true));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling(stub(), session, "", 0, UPLINK_SCRAMBLING_TYPE_LONG));
  EXPECT_SUCCESS(session, client::slot_power_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_PHASE_SYNCHRONIZATION_MODE_SLOT, 0, 15));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto slot_phase_fetch_measurement_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_measurement(stub(), session, "", 10.0));
  const auto slot_phase_fetch_phase_discontinuities_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_phase_discontinuities(stub(), session, "", 10.0));
  const auto slot_phase_fetch_chip_phase_error_linear_fit_trace_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_chip_phase_error_linear_fit_trace(stub(), session, "", 10.0));
  const auto slot_phase_fetch_chip_phase_error_trace_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_chip_phase_error_trace(stub(), session, "", 10.0));

  EXPECT_SUCCESS(session, slot_phase_fetch_measurement_response);
  EXPECT_NEAR(0.0, slot_phase_fetch_measurement_response.maximum_phase_discontinuity(), 180);
  EXPECT_LE(0, slot_phase_fetch_measurement_response.discontinuity_count_greater_than_limit1());
  EXPECT_LE(0, slot_phase_fetch_measurement_response.discontinuity_count_greater_than_limit2());
  EXPECT_NE(0, slot_phase_fetch_measurement_response.discontinuity_minimum_distance());
  EXPECT_SUCCESS(session, slot_phase_fetch_phase_discontinuities_response);
  EXPECT_EQ(15, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity_size());
  EXPECT_EQ(15, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity().size());
  EXPECT_TRUE(isnan(slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity(0)));
  EXPECT_SUCCESS(session, slot_phase_fetch_chip_phase_error_linear_fit_trace_response);
  EXPECT_EQ(0.0, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.x0());
  EXPECT_LT(0.0, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.dx());
  EXPECT_EQ(38400, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit_size());
  EXPECT_EQ(38400, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit().size());
  auto linear_fit_zero = slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit(0);
  EXPECT_TRUE(isnan(linear_fit_zero) || 0.0 == linear_fit_zero);
  EXPECT_SUCCESS(session, slot_phase_fetch_chip_phase_error_trace_response);
  EXPECT_EQ(0.0, slot_phase_fetch_chip_phase_error_trace_response.x0());
  EXPECT_LT(0.0, slot_phase_fetch_chip_phase_error_trace_response.dx());
  EXPECT_EQ(38400, slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error_size());
  EXPECT_EQ(38400, slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error().size());
  EXPECT_NE(0.0, slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
