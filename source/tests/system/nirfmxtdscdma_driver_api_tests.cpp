#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxtdscdma/nirfmxtdscdma_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxtdscdma_grpc;
namespace client = nirfmxtdscdma_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxTDSCDMADriverApiTests : public Test {
 protected:
  NiRFmxTDSCDMADriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxTDSCDMA::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxTDSCDMADriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxTDSCDMA::Stub>& stub() const
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
  std::unique_ptr<NiRFmxTDSCDMA::Stub> stub_;
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

TEST_F(NiRFmxTDSCDMADriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxTDSCDMADriverApiTests, AcpFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 2;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e+6));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1.91e+9));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.000660));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.00);
  const auto acp_fetch_carrier_absolute_power_response = client::acp_fetch_carrier_absolute_power(stub(), session, "", 10.00);
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, acp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_NE(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_NE(0, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_NE(0, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, CdaFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_NUMBER_OF_USERS = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10E+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91E+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CDA, true));
  EXPECT_SUCCESS(session, client::cda_cfg_averaging(stub(), session, "", CDA_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::cda_cfg_synchronization_mode_and_offset(stub(), session, "", CDA_SYNCHRONIZATION_MODE_SLOT, 0));
  EXPECT_SUCCESS(session, client::cda_cfg_measurement_channel(stub(), session, "", 16, 1));
  EXPECT_SUCCESS(session, client::cda_cfg_power_unit(stub(), session, "", CDA_POWER_UNIT_DB));
  EXPECT_SUCCESS(session, client::cfg_midamble_shift(stub(), session, "", MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT, MAX_NUMBER_OF_USERS, 8));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling_code(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto cda_fetch_iq_impairments_response = client::cda_fetch_iq_impairments(stub(), session, "", 10.00);
  const auto cda_fetch_code_domain_power_response = client::cda_fetch_code_domain_power(stub(), session, "", 10.00);
  const auto cda_fetch_symbol_evm_response = client::cda_fetch_symbol_evm(stub(), session, "", 10.00);
  const auto cda_fetch_mean_code_domain_power_trace_response = client::cda_fetch_mean_code_domain_power_trace(stub(), session, "", 10.00);
  const auto cda_fetch_mean_symbol_evm_trace_response = client::cda_fetch_mean_symbol_evm_trace(stub(), session, "", 10.00);
  const auto cda_fetch_symbol_constellation_trace_response = client::cda_fetch_symbol_constellation_trace(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, cda_fetch_iq_impairments_response);
  EXPECT_NE(0.0, cda_fetch_iq_impairments_response.iq_origin_offset());
  EXPECT_NE(0.0, cda_fetch_iq_impairments_response.iq_gain_imbalance());
  EXPECT_NE(0.0, cda_fetch_iq_impairments_response.iq_quadrature_error());
  EXPECT_SUCCESS(session, cda_fetch_code_domain_power_response);
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.mean_total_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.mean_total_active_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.mean_active_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.maximum_peak_active_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.mean_inactive_power());
  EXPECT_NE(0.0, cda_fetch_code_domain_power_response.maximum_peak_inactive_power());
  EXPECT_SUCCESS(session, cda_fetch_symbol_evm_response);
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.mean_rms_symbol_evm());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.maximum_peak_symbol_evm());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.frequency_error());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.chip_rate_error());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.mean_rms_symbol_magnitude_error());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.mean_rms_symbol_phase_error());
  EXPECT_NE(0.0, cda_fetch_symbol_evm_response.mean_symbol_power());
  EXPECT_SUCCESS(session, cda_fetch_mean_code_domain_power_trace_response);
  EXPECT_EQ(0, cda_fetch_mean_code_domain_power_trace_response.mean_code_domain_powers_size());
  EXPECT_EQ(0, cda_fetch_mean_code_domain_power_trace_response.mean_code_domain_powers().size());
  EXPECT_SUCCESS(session, cda_fetch_mean_symbol_evm_trace_response);
  EXPECT_EQ(0, cda_fetch_mean_symbol_evm_trace_response.mean_symbol_evm_size());
  EXPECT_EQ(0, cda_fetch_mean_symbol_evm_trace_response.mean_symbol_evm().size());
  EXPECT_SUCCESS(session, cda_fetch_symbol_constellation_trace_response);
}

TEST_F(NiRFmxTDSCDMADriverApiTests, ChpFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP , true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 660E-6));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_carrier_absolute_power_response = client::chp_fetch_carrier_absolute_power(stub(), session, "", 10.00);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, chp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, chp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_NE(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_NE(0, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_NE(0, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, ModAccFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_NUMBER_OF_USERS = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10E+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91E+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 80E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC , true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling_code(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::cfg_midamble_shift(stub(), session, "", MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT, MAX_NUMBER_OF_USERS, 8));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.00);
  const auto mod_acc_fetch_data_evm_response = client::mod_acc_fetch_data_evm(stub(), session, "", 10.00);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "" , 10.00);
  const auto mod_acc_fetch_constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.00);
  const auto mod_acc_fetch_midamble_evm_response = client::mod_acc_fetch_midamble_evm(stub(), session, "", 10.00);
  const auto mod_acc_fetch_midamble_and_data_power_response = client::mod_acc_fetch_midamble_and_data_power(stub(), session, "", 10.00);
  const auto mod_acc_fetch_evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, mod_acc_fetch_composite_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.peak_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.composite_rho());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.frequency_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.chip_rate_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_data_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_data_evm_response.rms_data_evm());
  EXPECT_NE(0.0, mod_acc_fetch_data_evm_response.peak_data_evm());
  EXPECT_NE(0.0, mod_acc_fetch_data_evm_response.data_rho());
  EXPECT_NE(0.0, mod_acc_fetch_data_evm_response.rms_data_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_data_evm_response.rms_data_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_quadrature_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_midamble_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_midamble_evm_response.rms_midamble_evm());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_evm_response.peak_midamble_evm());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_evm_response.midamble_rho());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_evm_response.rms_midamble_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_evm_response.rms_midamble_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_midamble_and_data_power_response);
  EXPECT_NE(0.0, mod_acc_fetch_midamble_and_data_power_response.midamble_power());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_and_data_power_response.data_field1_power());
  EXPECT_NE(0.0, mod_acc_fetch_midamble_and_data_power_response.data_field2_power());
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_NE(0.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_NE(0, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_NE(0, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_NE(0.0, mod_acc_fetch_evm_trace_response.evm(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, ModAccAcpChpObwSemCompositeFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_NUMBER_OF_USERS = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 80E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC | MEASUREMENT_TYPES_SEM| MEASUREMENT_TYPES_ACP | MEASUREMENT_TYPES_CHP | MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::cfg_midamble_shift(stub(), session, "", MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT, MAX_NUMBER_OF_USERS, 8));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::cfg_uplink_scrambling_code(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.000660));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.000660));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.000660));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.000660));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.00);
  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.00);
  const auto acp_fetch_carrier_absolute_power_response = client::acp_fetch_carrier_absolute_power(stub(), session, "", 10.00);
  const auto chp_fetch_carrier_absolute_power_response = client::chp_fetch_carrier_absolute_power(stub(), session, "", 10.00);
  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.00);
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.00);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.00);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.00);
  const auto sem_fetch_carrier_absolute_integrated_power_response = client::sem_fetch_carrier_absolute_integrated_power(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, mod_acc_fetch_composite_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.peak_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.composite_rho());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.frequency_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.chip_rate_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_phase_error());
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_NE(0, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, acp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, chp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, chp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_NE(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_NE(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_NE(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_NE(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_absolute_integrated_power_response);
  EXPECT_NE(0.0, sem_fetch_carrier_absolute_integrated_power_response.carrier_absolute_integrated_power());
}

TEST_F(NiRFmxTDSCDMADriverApiTests, ModAccPilotFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10E+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91E+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 50E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_pilot(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC , true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_slot_type(stub(), session, "", MODACC_MEASUREMENT_SLOT_TYPE_PILOT));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_pilot_evm_response = client::mod_acc_fetch_pilot_evm(stub(), session, "", 10.00);
  const auto mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.00);
  const auto mod_acc_fetch_constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.00);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "" , 10.00);
  const auto mod_acc_fetch_evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, mod_acc_fetch_pilot_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_pilot_evm_response.rms_pilot_evm());
  EXPECT_NE(0.0, mod_acc_fetch_pilot_evm_response.peak_pilot_evm());
  EXPECT_NE(0.0, mod_acc_fetch_pilot_evm_response.pilot_rho());
  EXPECT_NE(0.0, mod_acc_fetch_pilot_evm_response.rms_pilot_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_pilot_evm_response.rms_pilot_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_composite_evm_response);
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.peak_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.composite_rho());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.frequency_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.chip_rate_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_magnitude_error());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.rms_composite_phase_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.iq_quadrature_error());
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_NE(0.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_NE(0, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_NE(0, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_NE(0.0, mod_acc_fetch_evm_trace_response.evm(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, ObwFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 660e-6));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.00);
  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_NE(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_NE(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_NE(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_NE(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_NE(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_NE(0, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_NE(0, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, obw_fetch_spectrum_response.spectrum(0));
}

// The following test is disabled because the simulated device session always returns an error:
// '-357830: Burst Timing Detection Failed. 0 midamble(s) found.'
TEST_F(NiRFmxTDSCDMADriverApiTests, DISABLED_PvtFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10E+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91E+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT , true));
  EXPECT_SUCCESS(session, client::cfg_midamble_shift(stub(), session, "", MIDAMBLE_AUTO_DETECTION_MODE_MIDAMBLE_SHIFT, 16, 8));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto pvt_fetch_measurement_status_response = client::pvt_fetch_measurement_status(stub(), session, "", 10.00);
  const auto pvt_fetch_powers_response = client::pvt_fetch_powers(stub(), session, "", 10.00);
  const auto pvt_fetch_segment_measurement_array_response = client::pvt_fetch_segment_measurement_array(stub(), session, "", 10.00);
  const auto pvt_fetch_signal_power_trace_response = client::pvt_fetch_signal_power_trace(stub(), session, "", 10.00);

  EXPECT_SUCCESS(session, pvt_fetch_measurement_status_response);
  EXPECT_EQ(0, pvt_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, pvt_fetch_powers_response);
  EXPECT_NE(0.0, pvt_fetch_powers_response.mean_absolute_on_power());
  EXPECT_NE(0.0, pvt_fetch_powers_response.mean_absolute_off_power());
  EXPECT_SUCCESS(session, pvt_fetch_segment_measurement_array_response);
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_status_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_status().size());
  EXPECT_EQ(0, pvt_fetch_segment_measurement_array_response.segment_status(0));
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_margin_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_margin().size());
  EXPECT_NE(0.0, pvt_fetch_segment_measurement_array_response.segment_margin(0));
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_margin_time_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_margin_time().size());
  EXPECT_NE(0.0, pvt_fetch_segment_measurement_array_response.segment_margin_time(0));
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_mean_absolute_power_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_mean_absolute_power().size());
  EXPECT_NE(0.0, pvt_fetch_segment_measurement_array_response.segment_mean_absolute_power(0));
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_maximum_absolute_power_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_maximum_absolute_power().size());
  EXPECT_NE(0.0, pvt_fetch_segment_measurement_array_response.segment_maximum_absolute_power(0));
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_minimum_absolute_power_size());
  EXPECT_NE(0, pvt_fetch_segment_measurement_array_response.segment_minimum_absolute_power().size());
  EXPECT_NE(0.0, pvt_fetch_segment_measurement_array_response.segment_minimum_absolute_power(0));
  EXPECT_SUCCESS(session, pvt_fetch_signal_power_trace_response);
  EXPECT_NE(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_NE(0.0, pvt_fetch_signal_power_trace_response.dx());
  EXPECT_NE(0, pvt_fetch_signal_power_trace_response.signal_power_size());
  EXPECT_NE(0, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_NE(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_NE(0, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_NE(0, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_NE(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, SemFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10E+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91e+9, 0.000000, 0.000000));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.000000, 0.000000, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 660E-6));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.000000);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.000000);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.000000);
  const auto sem_fetch_carrier_absolute_integrated_power_response = client::sem_fetch_carrier_absolute_integrated_power(stub(), session, "", 10.000000);
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.000000);

  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_NE(0, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_NE(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_absolute_integrated_power_response);
  EXPECT_NE(0.0, sem_fetch_carrier_absolute_integrated_power_response.carrier_absolute_integrated_power());
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_NE(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_NE(0, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_NE(0, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_NE(0, sem_fetch_spectrum_response.relative_mask_size());
  EXPECT_NE(0, sem_fetch_spectrum_response.relative_mask().size());
  EXPECT_NE(0.0, sem_fetch_spectrum_response.relative_mask(0));
  EXPECT_NE(0, sem_fetch_spectrum_response.absolute_mask_size());
  EXPECT_NE(0, sem_fetch_spectrum_response.absolute_mask().size());
  EXPECT_NE(0.0, sem_fetch_spectrum_response.absolute_mask(0));
}

TEST_F(NiRFmxTDSCDMADriverApiTests, SlotPowerFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SLOTS = 28;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.91e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.00, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 16E-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPOWER, true));
  EXPECT_SUCCESS(session, client::slot_power_cfg_measurement_length(stub(), session, "", NUMBER_OF_SLOTS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto slot_power_fetch_powers_response = client::slot_power_fetch_powers(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, slot_power_fetch_powers_response);
  EXPECT_NE(0, slot_power_fetch_powers_response.slot_power_size());
  EXPECT_NE(0, slot_power_fetch_powers_response.slot_power().size());
  EXPECT_NE(0.0, slot_power_fetch_powers_response.slot_power(0));
  EXPECT_NE(0, slot_power_fetch_powers_response.slot_power_delta_size());
  EXPECT_NE(0, slot_power_fetch_powers_response.slot_power_delta().size());
  EXPECT_NE(0.0, slot_power_fetch_powers_response.slot_power_delta(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
