#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxcdma2k/nirfmxcdma2k_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxcdma2k_grpc;
namespace client = nirfmxcdma2k_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxCDMA2kDriverApiTests : public Test {
 protected:
  NiRFmxCDMA2kDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxCDMA2k::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxCDMA2kDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxCDMA2k::Stub>& stub() const
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
  std::unique_ptr<NiRFmxCDMA2k::Stub> stub_;
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

TEST_F(NiRFmxCDMA2kDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxCDMA2kDriverApiTests, AcpFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 2;
  int32 autoLevel = 1;

  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.00));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 833.490e+6 ));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,  DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  if(autoLevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", .02));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.00));
  }
  EXPECT_SUCCESS(session, client::cfg_band_class(stub(), session, "", 0 ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS ));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE ));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL ));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.67e-3 ));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS ));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  const auto acp_fetch_carrier_absolute_power_response = client::acp_fetch_carrier_absolute_power(stub(), session, "", 10.0);
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(2, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_NE(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, acp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_NE(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(6719, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(6719, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, CdaFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,  DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_radio_configuration(stub(), session, "", RADIO_CONFIGURATION_RC3));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CDA, true));
  EXPECT_SUCCESS(session, client::cda_cfg_synchronization_mode_and_interval(stub(), session, "", CDA_SYNCHRONIZATION_MODE_SLOT, 0 , 1));
  EXPECT_SUCCESS(session, client::cda_cfg_measurement_channel(stub(), session, "", 64, 0, CDA_MEASUREMENT_CHANNEL_BRANCH_I));
  EXPECT_SUCCESS(session, client::cda_cfg_power_unit(stub(), session, "", CDA_POWER_UNIT_DB));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto cda_fetch_code_domain_power_response = client::cda_fetch_code_domain_power(stub(), session, "", 10.0);
  const auto cda_fetch_code_domain_i_and_q_power_response = client::cda_fetch_code_domain_i_and_q_power(stub(), session, "", 10.0);
  const auto cda_fetch_symbol_evm_response = client::cda_fetch_symbol_evm(stub(), session, "", 10.0);
  const auto cda_fetch_iq_impairments_response = client::cda_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto cda_fetch_code_domain_i_and_q_power_trace_response = client::cda_fetch_code_domain_i_and_q_power_trace(stub(), session, "", 10.0);
  const auto cda_fetch_symbol_evm_trace_response = client::cda_fetch_symbol_evm_trace(stub(), session, "", 10.0);
  const auto cda_fetch_symbol_constellation_trace_response = client::cda_fetch_symbol_constellation_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, cda_fetch_code_domain_power_response);
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.total_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.total_active_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.mean_active_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.peak_active_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.mean_inactive_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_power_response.peak_inactive_power()));
  EXPECT_SUCCESS(session, cda_fetch_code_domain_i_and_q_power_response);
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.i_mean_active_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.q_mean_active_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.i_peak_inactive_power()));
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_response.q_peak_inactive_power()));
  EXPECT_SUCCESS(session, cda_fetch_symbol_evm_response);
  EXPECT_TRUE(isnan(cda_fetch_symbol_evm_response.rms_symbol_evm()));
  EXPECT_EQ(0.0, cda_fetch_symbol_evm_response.peak_symbol_evm());
  EXPECT_TRUE(isnan(cda_fetch_symbol_evm_response.rms_symbol_magnitude_error()));
  EXPECT_TRUE(isnan(cda_fetch_symbol_evm_response.rms_symbol_phase_error()));
  EXPECT_TRUE(isnan(cda_fetch_symbol_evm_response.mean_symbol_power()));
  EXPECT_NEAR(0.0, cda_fetch_symbol_evm_response.frequency_error(), 8000);
  EXPECT_NEAR(0, cda_fetch_symbol_evm_response.chip_rate_error(), 200);
  EXPECT_SUCCESS(session, cda_fetch_iq_impairments_response);
  EXPECT_TRUE(isnan(cda_fetch_iq_impairments_response.iq_origin_offset()));
  EXPECT_TRUE(isnan(cda_fetch_iq_impairments_response.iq_gain_imbalance()));
  EXPECT_TRUE(isnan(cda_fetch_iq_impairments_response.iq_quadrature_error()));
  EXPECT_SUCCESS(session, cda_fetch_code_domain_i_and_q_power_trace_response);
  EXPECT_EQ(64, cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers_size());
  EXPECT_EQ(64, cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers().size());
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_trace_response.i_code_domain_powers(0)));
  EXPECT_EQ(64, cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers_size());
  EXPECT_EQ(64, cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers().size());
  EXPECT_TRUE(isnan(cda_fetch_code_domain_i_and_q_power_trace_response.q_code_domain_powers(0)));
  EXPECT_SUCCESS(session, cda_fetch_symbol_evm_trace_response);
  EXPECT_EQ(24, cda_fetch_symbol_evm_trace_response.symbol_evm_size());
  EXPECT_EQ(24, cda_fetch_symbol_evm_trace_response.symbol_evm().size());
  EXPECT_TRUE(isnan(cda_fetch_symbol_evm_trace_response.symbol_evm(0)));
  EXPECT_SUCCESS(session, cda_fetch_symbol_constellation_trace_response);
  EXPECT_TRUE(isnan(cda_fetch_symbol_constellation_trace_response.symbol_constellation(0).real()));
  EXPECT_TRUE(isnan(cda_fetch_symbol_constellation_trace_response.symbol_constellation(0).imaginary()));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, ChpFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00 ));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.00, false ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.670e-3 ));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS ));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_carrier_absolute_power_response = client::chp_fetch_carrier_absolute_power(stub(), session, "", 10.0);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, chp_fetch_carrier_absolute_power_response);
  EXPECT_NE(0.0, chp_fetch_carrier_absolute_power_response.carrier_absolute_power());
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_NE(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(3347, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(3347, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, ModAccFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.00, false));
  EXPECT_SUCCESS(session, client::cfg_radio_configuration(stub(), session, "", RADIO_CONFIGURATION_RC3));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_evm_response = client::mod_acc_fetch_evm(stub(), session, "", 10.0);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto mod_acc_fetch_peak_cde_response = client::mod_acc_fetch_peak_cde(stub(), session, "", 10.0);
  const auto mod_acc_fetch_peak_active_cde_response = client::mod_acc_fetch_peak_active_cde(stub(), session, "", 10.0);
  const auto mod_acc_fetch_constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, mod_acc_fetch_evm_response);
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_response.rms_evm()));
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_response.peak_evm()));
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_response.rho()));
  EXPECT_NEAR(0.0, mod_acc_fetch_evm_response.frequency_error(), 8000);
  EXPECT_NEAR(0, mod_acc_fetch_evm_response.chip_rate_error(), 200);  
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_response.rms_magnitude_error()));
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_response.rms_phase_error()));
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_TRUE(isnan(mod_acc_fetch_iq_impairments_response.iq_origin_offset()));
  EXPECT_TRUE(isnan(mod_acc_fetch_iq_impairments_response.iq_gain_imbalance()));
  EXPECT_TRUE(isnan(mod_acc_fetch_iq_impairments_response.iq_quadrature_error()));
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_cde_response);
  EXPECT_NE(0.0, mod_acc_fetch_peak_cde_response.peak_cde());
  EXPECT_EQ(31, mod_acc_fetch_peak_cde_response.peak_cde_walsh_code_number());
  EXPECT_EQ(1, mod_acc_fetch_peak_cde_response.peak_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_peak_active_cde_response);
  EXPECT_TRUE(isinf(mod_acc_fetch_peak_active_cde_response.peak_active_cde()));
  EXPECT_EQ(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_walsh_code_length());
  EXPECT_EQ(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_walsh_code_number());
  EXPECT_EQ(0, mod_acc_fetch_peak_active_cde_response.peak_active_cde_branch());
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_TRUE(isnan(mod_acc_fetch_constellation_trace_response.constellation(0).real()));
  EXPECT_TRUE(isnan(mod_acc_fetch_constellation_trace_response.constellation(0).imaginary()));
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_NE(0.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_EQ(1536, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_EQ(1536, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_trace_response.evm(0)));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, ObwFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00 ));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,  DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.00, false ));        
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.670e-3));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_NEAR(72567.0, obw_fetch_measurement_response.occupied_bandwidth(), 100);
  EXPECT_NE(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_NEAR(833454000.0, obw_fetch_measurement_response.start_frequency(), 500);
  EXPECT_NEAR(833526000.0, obw_fetch_measurement_response.stop_frequency(), 500);
  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_NE(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_NE(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(5013, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(5013, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_NE(0.0, obw_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, QevmFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6 ));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00 ));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.00, false));
  EXPECT_SUCCESS(session, client::cfg_radio_configuration(stub(), session, "", RADIO_CONFIGURATION_RC3));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0 ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_QEVM, true));
  EXPECT_SUCCESS(session, client::qevm_cfg_averaging(stub(), session, "", QEVM_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::qevm_cfg_measurement_length(stub(), session, "", 1536));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto qevm_fetch_evm_response = client::qevm_fetch_evm(stub(), session, "", 10.0);
  const auto qevm_fetch_iq_impairments_response = client::qevm_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto qevm_fetch_evm_trace_response = client::qevm_fetch_evm_trace(stub(), session, "", 10.0);
  const auto qevm_fetch_constellation_trace_response = client::qevm_fetch_constellation_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, qevm_fetch_evm_response);
  EXPECT_TRUE(isnan(qevm_fetch_evm_response.mean_rms_evm()));
  EXPECT_EQ(0.0, qevm_fetch_evm_response.maximum_peak_evm());
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_frequency_error());
  EXPECT_TRUE(isnan(qevm_fetch_evm_response.mean_magnitude_error()));
  EXPECT_TRUE(isnan(qevm_fetch_evm_response.mean_phase_error()));
  EXPECT_NE(0.0, qevm_fetch_evm_response.mean_chip_rate_error());
  EXPECT_SUCCESS(session, qevm_fetch_iq_impairments_response);
  EXPECT_NE(0.0, qevm_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.mean_iq_gain_imbalance()));
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.mean_iq_quadrature_error()));
  EXPECT_NE(0.0, qevm_fetch_iq_impairments_response.maximum_iq_origin_offset());
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.maximum_iq_gain_imbalance()));
  EXPECT_TRUE(isnan(qevm_fetch_iq_impairments_response.maximum_iq_quadrature_error()));
  EXPECT_SUCCESS(session, qevm_fetch_evm_trace_response);
  EXPECT_EQ(0.0, qevm_fetch_evm_trace_response.x0());
  EXPECT_NE(0.0, qevm_fetch_evm_trace_response.dx());
  EXPECT_NEAR(1503, qevm_fetch_evm_trace_response.evm_size(), 10);
  EXPECT_NEAR(1503, qevm_fetch_evm_trace_response.evm().size(), 10);
  EXPECT_TRUE(isnan(qevm_fetch_evm_trace_response.evm(0)));
  EXPECT_SUCCESS(session, qevm_fetch_constellation_trace_response);
  EXPECT_TRUE(isnan(qevm_fetch_constellation_trace_response.constellation(0).real()));
  EXPECT_TRUE(isnan(qevm_fetch_constellation_trace_response.constellation(0).imaginary()));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, SlotPhaseFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SLOTS = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,  DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_radio_configuration(stub(), session, "", RADIO_CONFIGURATION_RC3));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPHASE, true));
  EXPECT_SUCCESS(session, client::slot_phase_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_PHASE_SYNCHRONIZATION_MODE_SLOT, 0 , NUMBER_OF_SLOTS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto slot_phase_fetch_maximum_phase_discontinuity_response = client::slot_phase_fetch_maximum_phase_discontinuity(stub(), session, "", 10.0);
  const auto slot_phase_fetch_phase_discontinuities_response = client::slot_phase_fetch_phase_discontinuities(stub(), session, "", 10.0);
  const auto slot_phase_fetch_chip_phase_error_trace_response = client::slot_phase_fetch_chip_phase_error_trace(stub(), session, "", 10.0);
  const auto slot_phase_fetch_chip_phase_error_linear_fit_trace_response = client::slot_phase_fetch_chip_phase_error_linear_fit_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, slot_phase_fetch_maximum_phase_discontinuity_response);
  EXPECT_EQ(0.0, slot_phase_fetch_maximum_phase_discontinuity_response.maximum_phase_discontinuity());
  EXPECT_SUCCESS(session, slot_phase_fetch_phase_discontinuities_response);
  EXPECT_EQ(16, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity_size());
  EXPECT_EQ(16, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity().size());
  EXPECT_TRUE(isnan(slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity(0)));
  EXPECT_SUCCESS(session, slot_phase_fetch_chip_phase_error_trace_response);
  EXPECT_EQ(0.0, slot_phase_fetch_chip_phase_error_trace_response.x0());
  EXPECT_NE(0.0, slot_phase_fetch_chip_phase_error_trace_response.dx());
  EXPECT_EQ(24576, slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error_size());
  EXPECT_EQ(24576, slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error().size());
  EXPECT_TRUE(isnan(slot_phase_fetch_chip_phase_error_trace_response.chip_phase_error(0)));
  EXPECT_SUCCESS(session, slot_phase_fetch_chip_phase_error_linear_fit_trace_response);
  EXPECT_EQ(0.0, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.x0());
  EXPECT_NE(0.0, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.dx());
  EXPECT_EQ(24576, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit_size());
  EXPECT_EQ(24576, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit().size());
  EXPECT_EQ(0.0, slot_phase_fetch_chip_phase_error_linear_fit_trace_response.chip_phase_error_linear_fit(0));
}

TEST_F(NiRFmxCDMA2kDriverApiTests, SlotPowerFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SLOTS = 16;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 833.490e+6, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,  DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_radio_configuration(stub(), session, "", RADIO_CONFIGURATION_RC3));
  EXPECT_SUCCESS(session, client::cfg_uplink_spreading(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPOWER, true));
  EXPECT_SUCCESS(session, client::slot_power_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_POWER_SYNCHRONIZATION_MODE_SLOT, 0 , NUMBER_OF_SLOTS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto slot_power_fetch_powers_response = client::slot_power_fetch_powers(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, slot_power_fetch_powers_response);
  EXPECT_EQ(16, slot_power_fetch_powers_response.slot_power_size());
  EXPECT_EQ(16, slot_power_fetch_powers_response.slot_power().size());
  EXPECT_NE(0.0, slot_power_fetch_powers_response.slot_power(0));
  EXPECT_EQ(16, slot_power_fetch_powers_response.slot_power_delta_size());
  EXPECT_EQ(16, slot_power_fetch_powers_response.slot_power_delta().size());
  EXPECT_TRUE(isnan(slot_power_fetch_powers_response.slot_power_delta(0)));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
