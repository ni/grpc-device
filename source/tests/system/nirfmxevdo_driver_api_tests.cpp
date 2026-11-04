#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxevdo/nirfmxevdo_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxevdo_grpc;
namespace client = nirfmxevdo_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxEVDODriverApiTests : public Test {
 protected:
  NiRFmxEVDODriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxEVDO::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxEVDODriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxEVDO::Stub>& stub() const
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
  std::unique_ptr<NiRFmxEVDO::Stub> stub_;
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

TEST_F(NiRFmxEVDODriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxEVDODriverApiTests, AcpFromExample_FetchData_DataLooksReasonable)
{
  const auto number_of_offsets = 2;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 833.490e+6));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 0.02));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", number_of_offsets));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.67e-3));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto offset_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  const auto carrier_response = client::acp_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, offset_response);
  EXPECT_EQ(number_of_offsets, offset_response.lower_relative_power_size());
  EXPECT_EQ(number_of_offsets, offset_response.upper_relative_power_size());
  EXPECT_EQ(number_of_offsets, offset_response.lower_absolute_power_size());
  EXPECT_EQ(number_of_offsets, offset_response.upper_absolute_power_size());
  EXPECT_SUCCESS(session, carrier_response);
  EXPECT_SUCCESS(session, spectrum_response);
  EXPECT_GT(spectrum_response.spectrum_size(), 0);
  EXPECT_EQ(spectrum_response.spectrum_size(), spectrum_response.actual_array_size());
}

TEST_F(NiRFmxEVDODriverApiTests, CdaFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::cfg_physical_layer_subtype(stub(), session, "", PHYSICAL_LAYER_SUBTYPE_0_1));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CDA, true));
  EXPECT_SUCCESS(session, client::cda_cfg_synchronization_mode_and_interval(stub(), session, "", CDA_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::cda_cfg_uplink_measurement_channel(stub(), session, "", 64, 0, CDA_UPLINK_BRANCH_I));
  EXPECT_SUCCESS(session, client::cda_cfg_power_unit(stub(), session, "", CDA_POWER_UNIT_DB));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto code_domain_power_response = client::cda_fetch_uplink_code_domain_power(stub(), session, "", 10.0);
  const auto i_and_q_power_response = client::cda_fetch_uplink_code_domain_i_and_q_power(stub(), session, "", 10.0);
  const auto symbol_evm_response = client::cda_fetch_uplink_symbol_evm(stub(), session, "", 10.0);
  const auto iq_impairments_response = client::cda_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto code_domain_trace_response = client::cda_fetch_uplink_code_domain_i_and_q_power_trace(stub(), session, "", 10.0);
  const auto symbol_evm_trace_response = client::cda_fetch_uplink_symbol_evm_trace(stub(), session, "", 10.0);
  const auto constellation_response = client::cda_fetch_uplink_symbol_constellation_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, code_domain_power_response);
  EXPECT_SUCCESS(session, i_and_q_power_response);
  EXPECT_SUCCESS(session, symbol_evm_response);
  EXPECT_SUCCESS(session, iq_impairments_response);
  EXPECT_SUCCESS(session, code_domain_trace_response);
  EXPECT_GT(code_domain_trace_response.i_code_domain_powers_size(), 0);
  EXPECT_EQ(code_domain_trace_response.i_code_domain_powers_size(), code_domain_trace_response.actual_array_size());
  EXPECT_EQ(code_domain_trace_response.i_code_domain_powers_size(), code_domain_trace_response.q_code_domain_powers_size());
  EXPECT_SUCCESS(session, symbol_evm_trace_response);
  EXPECT_GT(symbol_evm_trace_response.symbol_evm_size(), 0);
  EXPECT_EQ(symbol_evm_trace_response.symbol_evm_size(), symbol_evm_trace_response.actual_array_size());
  EXPECT_SUCCESS(session, constellation_response);
  EXPECT_GT(constellation_response.symbol_constellation_size(), 0);
}

TEST_F(NiRFmxEVDODriverApiTests, ChpFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.670e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto carrier_response = client::chp_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, carrier_response);
  EXPECT_SUCCESS(session, spectrum_response);
  EXPECT_GT(spectrum_response.spectrum_size(), 0);
  EXPECT_EQ(spectrum_response.spectrum_size(), spectrum_response.actual_array_size());
}

TEST_F(NiRFmxEVDODriverApiTests, ModAccFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::cfg_physical_layer_subtype(stub(), session, "", PHYSICAL_LAYER_SUBTYPE_0_1));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto evm_response = client::mod_acc_fetch_uplink_evm(stub(), session, "", 10.0);
  const auto iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto peak_cde_response = client::mod_acc_fetch_uplink_peak_cde(stub(), session, "", 10.0);
  const auto peak_active_cde_response = client::mod_acc_fetch_uplink_peak_active_cde(stub(), session, "", 10.0);
  const auto constellation_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);
  const auto evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, evm_response);
  EXPECT_SUCCESS(session, iq_impairments_response);
  EXPECT_SUCCESS(session, peak_cde_response);
  EXPECT_SUCCESS(session, peak_active_cde_response);
  EXPECT_SUCCESS(session, constellation_response);
  EXPECT_GT(constellation_response.constellation_size(), 0);
  EXPECT_SUCCESS(session, evm_trace_response);
  EXPECT_GT(evm_trace_response.evm_size(), 0);
  EXPECT_EQ(evm_trace_response.evm_size(), evm_trace_response.actual_array_size());
}

TEST_F(NiRFmxEVDODriverApiTests, ObwFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.670e-3));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  const auto spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, measurement_response);
  EXPECT_SUCCESS(session, spectrum_response);
  EXPECT_GT(spectrum_response.spectrum_size(), 0);
  EXPECT_EQ(spectrum_response.spectrum_size(), spectrum_response.actual_array_size());
}

TEST_F(NiRFmxEVDODriverApiTests, SlotPhaseFromExample_FetchData_DataLooksReasonable)
{
  const auto number_of_slots = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::cfg_physical_layer_subtype(stub(), session, "", PHYSICAL_LAYER_SUBTYPE_0_1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPHASE, true));
  EXPECT_SUCCESS(session, client::slot_phase_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_PHASE_SYNCHRONIZATION_MODE_SLOT, 0, number_of_slots));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto discontinuity_response = client::slot_phase_fetch_phase_discontinuities(stub(), session, "", 10.0);
  const auto phase_trace_response = client::slot_phase_fetch_chip_phase_error_trace(stub(), session, "", 10.0);
  const auto linear_fit_response = client::slot_phase_fetch_chip_phase_error_linear_fit_trace(stub(), session, "", 10.0);
  const auto maximum_discontinuity_response = client::slot_phase_fetch_maximum_half_slot_phase_discontinuity(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, discontinuity_response);
  EXPECT_GT(discontinuity_response.half_slot_phase_discontinuity_size(), 0);
  EXPECT_EQ(discontinuity_response.half_slot_phase_discontinuity_size(), discontinuity_response.actual_array_size());
  EXPECT_SUCCESS(session, phase_trace_response);
  EXPECT_GT(phase_trace_response.chip_phase_error_size(), 0);
  EXPECT_EQ(phase_trace_response.chip_phase_error_size(), phase_trace_response.actual_array_size());
  EXPECT_SUCCESS(session, linear_fit_response);
  EXPECT_GT(linear_fit_response.chip_phase_error_linear_fit_size(), 0);
  EXPECT_EQ(linear_fit_response.chip_phase_error_linear_fit_size(), linear_fit_response.actual_array_size());
  EXPECT_SUCCESS(session, maximum_discontinuity_response);
}

TEST_F(NiRFmxEVDODriverApiTests, SlotPowerFromExample_FetchData_DataLooksReasonable)
{
  const auto number_of_slots = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", "PFI0", DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::cfg_physical_layer_subtype(stub(), session, "", PHYSICAL_LAYER_SUBTYPE_0_1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPOWER, true));
  EXPECT_SUCCESS(session, client::slot_power_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_POWER_SYNCHRONIZATION_MODE_SLOT, 0, number_of_slots));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto powers_response = client::slot_power_fetch_powers(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, powers_response);
  EXPECT_GT(powers_response.half_slot_power_size(), 0);
  EXPECT_EQ(powers_response.half_slot_power_size(), powers_response.actual_array_size());
  EXPECT_EQ(powers_response.half_slot_power_size(), powers_response.half_slot_power_delta_size());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
