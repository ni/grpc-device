#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxlte/nirfmxlte_client.h"
#include "nirfsa/nirfsa_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxlte_grpc;
namespace client = nirfmxlte_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

typedef ::google::protobuf::int32 int32;
typedef ::google::protobuf::int64 int64;
typedef double float64;

constexpr auto PXI_5663E = "5663E";
constexpr auto SYNC_FAILURE_WARNING = 374603;
constexpr auto SYNC_FAILURE_WARNING_STR = "Unable to synchronize";
constexpr auto MODACC_NB_IOT_AUTODETECT_CHECK = -376649;
constexpr auto MODACC_NB_IOT_AUTODETECT_CHECK_STR = "Autodetected NPUSCH channel parameters are not ";

class NiRFmxLTEDriverApiTests : public Test {
 protected:
  NiRFmxLTEDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxLTE::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxLTEDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxLTE::Stub>& stub() const
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
  std::unique_ptr<NiRFmxLTE::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

TEST_F(NiRFmxLTEDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxLTEDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = init_rfsa(rfsa_stub, "Sim");
  EXPECT_RESPONSE_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxLTEDriverApiTests, AcpContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const std::vector<int> empty_int_vec;
  std::vector<float64> componentCarrierBandwidth{20e6, 20e6};
  std::vector<float64> componentCarrierFrequency{-9.9e6, 9.9e6};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 1.95e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, "", componentCarrierBandwidth, componentCarrierFrequency, empty_int_vec));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 0.01));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto NUMBER_OF_OFFSETS = 3;
  std::vector<ACPFetchAbsolutePowersTraceResponse> acp_fetch_absolute_powers_trace_response_vec;
  std::vector<ACPFetchRelativePowersTraceResponse> acp_fetch_relative_powers_trace_response_vec;
  const auto acp_fetch_offset_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::acp_fetch_total_aggregated_power(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_OFFSETS; i++) {
    acp_fetch_absolute_powers_trace_response_vec.push_back(EXPECT_SUCCESS(session, client::acp_fetch_absolute_powers_trace(stub(), session, "", 10.0, i)));
    acp_fetch_relative_powers_trace_response_vec.push_back(EXPECT_SUCCESS(session, client::acp_fetch_relative_powers_trace(stub(), session, "", 10.0, i)));
  }
  const auto acp_fetch_spectrum_response = EXPECT_SUCCESS(session, client::acp_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_LT(0.0, acp_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_LT(0.0, acp_fetch_absolute_powers_trace_response_vec[0].x0());
  EXPECT_LT(0.0, acp_fetch_absolute_powers_trace_response_vec[0].dx());
  EXPECT_EQ(2, acp_fetch_absolute_powers_trace_response_vec[0].absolute_powers_trace_size());
  EXPECT_EQ(2, acp_fetch_absolute_powers_trace_response_vec[0].absolute_powers_trace().size());
  EXPECT_GT(0.0, acp_fetch_absolute_powers_trace_response_vec[0].absolute_powers_trace(0));
  EXPECT_LT(0.0, acp_fetch_relative_powers_trace_response_vec[0].x0());
  EXPECT_LT(0.0, acp_fetch_relative_powers_trace_response_vec[0].dx());
  EXPECT_EQ(2, acp_fetch_relative_powers_trace_response_vec[0].relative_powers_trace_size());
  EXPECT_EQ(2, acp_fetch_relative_powers_trace_response_vec[0].relative_powers_trace().size());
  EXPECT_GT(0.0, acp_fetch_relative_powers_trace_response_vec[0].relative_powers_trace(0));
  EXPECT_LT(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(117479, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(117479, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxLTEDriverApiTests, ChpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::chp_fetch_component_carrier_measurement(stub(), session, "", 10.0));
  const auto chp_fetch_spectrum_response = EXPECT_SUCCESS(session, client::chp_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_LT(0.0, chp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(217, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(217, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxLTEDriverApiTests, DLModAccContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const std::vector<int> empty_int_vec;
  std::vector<float64> componentCarrierBandwidth{20e6, 20e6};
  std::vector<float64> componentCarrierFrequency{-9.9e6, 9.9e6};
  std::vector<int> downlinkTestModel{DOWNLINK_TEST_MODEL_TM1_1, DOWNLINK_TEST_MODEL_TM1_1};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 2.14e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, "", componentCarrierBandwidth, componentCarrierFrequency, empty_int_vec));
  EXPECT_SUCCESS(session, client::cfg_downlink_test_model_array(stub(), session, "", downlinkTestModel));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_FRAME, 0, 1));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_evm_unit(stub(), session, "", MODACC_EVM_UNIT_PERCENTAGE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  ModAccFetchPDSCHQPSKConstellationResponse mod_acc_fetch_pdschqpsk_constellation_response;
  ModAccFetchEVMPerSubcarrierTraceResponse mod_acc_fetch_evm_per_subcarrier_trace_response;
  const auto mod_acc_fetch_composite_evm_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_composite_evm_array(stub(), session, "", 10.0));
  const auto mod_acc_fetch_iq_impairments_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments_array(stub(), session, "", 10.0));
  const auto mod_acc_fetch_pdschevm_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_pdschevm_array(stub(), session, "", 10.0));
  const auto mod_acc_fetch_pdsch1024q_amevm_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_pdsch1024q_amevm_array(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), "", i));
    mod_acc_fetch_pdschqpsk_constellation_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_pdschqpsk_constellation(stub(), session, carrier_string_response.selector_string_out(), 10.0));
    mod_acc_fetch_evm_per_subcarrier_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_per_subcarrier_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0));
  }

  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_frequency_error_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_frequency_error().size());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_array_response.mean_frequency_error(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index().size());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index().size());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index().size());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset().size());
  EXPECT_EQ(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance().size());
  // Sometimes nan: EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error().size());
  // Sometimes nan: EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error(0));
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_pdschevm_array_response.mean_rms_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_qpsk_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_qpsk_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_pdschevm_array_response.mean_rms_qpsk_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_16qam_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_16qam_evm().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_pdschevm_array_response.mean_rms_16qam_evm(0)));
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_64qam_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_64qam_evm().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_pdschevm_array_response.mean_rms_64qam_evm(0)));
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_256qam_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdschevm_array_response.mean_rms_256qam_evm().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_pdschevm_array_response.mean_rms_256qam_evm(0)));
  EXPECT_EQ(2, mod_acc_fetch_pdsch1024q_amevm_array_response.mean_rms_1024qam_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_pdsch1024q_amevm_array_response.mean_rms_1024qam_evm().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_pdsch1024q_amevm_array_response.mean_rms_1024qam_evm(0)));
  EXPECT_NE(0.0, mod_acc_fetch_pdschqpsk_constellation_response.qpsk_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pdschqpsk_constellation_response.qpsk_constellation(0).imaginary());
  EXPECT_EQ(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response.x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_per_subcarrier_trace_response.dx());
  EXPECT_EQ(1201, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier_size());
  EXPECT_EQ(1201, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier(0));
}

TEST_F(NiRFmxLTEDriverApiTests, NBIotAcpFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
  EXPECT_SUCCESS(session, client::cfg_nb_io_t_component_carrier(stub(), session, "", 0, NB_IOT_UPLINK_SUBCARRIER_SPACING_15KHZ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto NUMBER_OF_OFFSETS = 2;
  ACPFetchAbsolutePowersTraceResponse acp_fetch_absolute_powers_trace_response;
  ACPFetchRelativePowersTraceResponse acp_fetch_relative_powers_trace_response;
  const auto acp_fetch_offset_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::acp_fetch_component_carrier_measurement(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_OFFSETS; i++) {
    acp_fetch_absolute_powers_trace_response = EXPECT_SUCCESS(session, client::acp_fetch_absolute_powers_trace(stub(), session, "", 10.0, i));
    acp_fetch_relative_powers_trace_response = EXPECT_SUCCESS(session, client::acp_fetch_relative_powers_trace(stub(), session, "", 10.0, i));
  }
  const auto acp_fetch_spectrum_response = EXPECT_SUCCESS(session, client::acp_fetch_spectrum(stub(), session, "", 10.0));

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
  EXPECT_LT(0.0, acp_fetch_component_carrier_measurement_response.absolute_power());
  // There have been intermittent instances where the relative_power returned
  // isn't absolutely 0.0 from the driver. When this happens it doesn't appear to affect
  // any of the other tests.
  EXPECT_NEAR(0.0, acp_fetch_component_carrier_measurement_response.relative_power(), 0.001);
  EXPECT_LT(0.0, acp_fetch_absolute_powers_trace_response.x0());
  EXPECT_LT(0.0, acp_fetch_absolute_powers_trace_response.dx());
  EXPECT_EQ(2, acp_fetch_absolute_powers_trace_response.absolute_powers_trace_size());
  EXPECT_EQ(2, acp_fetch_absolute_powers_trace_response.absolute_powers_trace().size());
  EXPECT_GT(0.0, acp_fetch_absolute_powers_trace_response.absolute_powers_trace(0));
  EXPECT_LT(0.0, acp_fetch_relative_powers_trace_response.x0());
  EXPECT_LT(0.0, acp_fetch_relative_powers_trace_response.dx());
  EXPECT_EQ(2, acp_fetch_relative_powers_trace_response.relative_powers_trace_size());
  EXPECT_EQ(2, acp_fetch_relative_powers_trace_response.relative_powers_trace().size());
  EXPECT_GT(0.0, acp_fetch_relative_powers_trace_response.relative_powers_trace(0));
  EXPECT_LT(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(9901, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(9901, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxLTEDriverApiTests, NBIoTModAccFromExample_FetchData_DataLooksReasonable)
{
  nidevice_grpc::Session session;
  ModAccFetchCompositeEVMResponse mod_acc_fetch_composite_evm_response;
  int actualStatus = -1, attempts = 1;
  while (1) {
    session = init_session(stub(), PXI_5663E);
    EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
    EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
    EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
    EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
    EXPECT_SUCCESS(session, client::cfg_nb_io_t_component_carrier(stub(), session, "", 0, NB_IOT_UPLINK_SUBCARRIER_SPACING_15KHZ));
    EXPECT_SUCCESS(session, client::cfg_npusch_format(stub(), session, "", 1));
    EXPECT_SUCCESS(session, client::cfg_auto_npusch_channel_detection_enabled(stub(), session, "", AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED_TRUE));
    EXPECT_SUCCESS(session, client::cfg_npusch_starting_slot(stub(), session, "", 0));
    EXPECT_SUCCESS(session, client::cfg_npuschdmrs(stub(), session, "", NPUSCH_DMRS_BASE_SEQUENCE_MODE_AUTO, 0, 0, NPUSCH_DMRS_GROUP_HOPPING_ENABLED_FALSE, 0));
    EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_evm_unit(stub(), session, "", MODACC_EVM_UNIT_PERCENTAGE));
    EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

    // Intermittently fails with: "Autodetected NPUSCH channel parameters are not 3GPP spec compliant."
    try {
      mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.0);
      actualStatus = mod_acc_fetch_composite_evm_response.status();
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      const auto& error = ex.Trailers().find("ni-error")->second;
      actualStatus = std::stoi(error);
    }
    if (actualStatus == MODACC_NB_IOT_AUTODETECT_CHECK && attempts < 5) {
      TearDown();
      SetUp();
      ++attempts;
    }
    else {
      break;
    }
  }
  // If this fails, we want the test to be over now.
  ASSERT_GE(actualStatus, 0);

  const auto mod_acc_fetch_iq_impairments_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0));
  const auto mod_acc_fetch_in_band_emission_margin_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_in_band_emission_margin(stub(), session, "", 10.0));
  const auto mod_acc_fetch_npusch_constellation_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_npusch_constellation_trace(stub(), session, "", 10.0));
  const auto mod_acc_fetch_evm_per_symbol_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_per_symbol_trace(stub(), session, "", 10.0));

  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_response.mean_rms_composite_evm());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_response.maximum_peak_composite_evm());
  EXPECT_GT(0.0, mod_acc_fetch_composite_evm_response.mean_frequency_error());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_symbol_index());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_subcarrier_index());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_slot_index());
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_quadrature_error());
  EXPECT_EQ(0.0, mod_acc_fetch_in_band_emission_margin_response.in_band_emission_margin());
  EXPECT_EQ(72, mod_acc_fetch_npusch_constellation_trace_response.data_constellation_size());
  EXPECT_EQ(72, mod_acc_fetch_npusch_constellation_trace_response.data_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_npusch_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_npusch_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_EQ(12, mod_acc_fetch_npusch_constellation_trace_response.dmrs_constellation_size());
  EXPECT_EQ(12, mod_acc_fetch_npusch_constellation_trace_response.dmrs_constellation().size());
  EXPECT_LT(0.0, mod_acc_fetch_npusch_constellation_trace_response.dmrs_constellation(0).real());
  EXPECT_GT(0.0, mod_acc_fetch_npusch_constellation_trace_response.dmrs_constellation(0).imaginary());
  EXPECT_EQ(0.0, mod_acc_fetch_evm_per_symbol_trace_response.x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_per_symbol_trace_response.dx());
  EXPECT_EQ(7, mod_acc_fetch_evm_per_symbol_trace_response.rms_evm_per_symbol_size());
  EXPECT_EQ(7, mod_acc_fetch_evm_per_symbol_trace_response.rms_evm_per_symbol().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_per_symbol_trace_response.rms_evm_per_symbol(0));
}

TEST_F(NiRFmxLTEDriverApiTests, NBIoTModAccAcpChpObwSemCompositeSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  nidevice_grpc::Session session;
  ModAccFetchCompositeEVMResponse mod_acc_fetch_composite_evm_response;
  int actualStatus = -1, attempts = 1;
  while (1) {
    session = init_session(stub(), PXI_5663E);
    EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
    EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
    EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
    EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
    EXPECT_SUCCESS(session, client::cfg_nb_io_t_component_carrier(stub(), session, "", 0, NB_IOT_UPLINK_SUBCARRIER_SPACING_15KHZ));
    EXPECT_SUCCESS(session, client::cfg_npusch_format(stub(), session, "", 1));
    EXPECT_SUCCESS(session, client::cfg_auto_npusch_channel_detection_enabled(stub(), session, "", AUTO_NPUSCH_CHANNEL_DETECTION_ENABLED_TRUE));
    EXPECT_SUCCESS(session, client::cfg_npusch_starting_slot(stub(), session, "", 0));
    EXPECT_SUCCESS(session, client::cfg_npuschdmrs(stub(), session, "", NPUSCH_DMRS_BASE_SEQUENCE_MODE_AUTO, 0, 0, NPUSCH_DMRS_GROUP_HOPPING_ENABLED_FALSE, 0));
    EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP | MEASUREMENT_TYPES_CHP | MEASUREMENT_TYPES_MODACC | MEASUREMENT_TYPES_OBW | MEASUREMENT_TYPES_SEM, true));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
    EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
    EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
    EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
    EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
    EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
    EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.001));
    EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.001));
    EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.001));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
    EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

    // Intermittently fails with: "Autodetected NPUSCH channel parameters are not 3GPP spec compliant."
    try {
      mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.0);
      actualStatus = mod_acc_fetch_composite_evm_response.status();
    }
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {
      const auto& error = ex.Trailers().find("ni-error")->second;
      actualStatus = std::stoi(error);
    }
    if (actualStatus == MODACC_NB_IOT_AUTODETECT_CHECK && attempts < 5) {
      TearDown();
      SetUp();
      ++attempts;
    }
    else {
      break;
    }
  }
  // If this fails, we want the test to be over now.
  ASSERT_GE(actualStatus, 0);

  const auto mod_acc_fetch_iq_impairments_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0));
  const auto mod_acc_fetch_in_band_emission_margin_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_in_band_emission_margin(stub(), session, "", 10.0));
  const auto acp_fetch_offset_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::acp_fetch_component_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_component_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto obw_fetch_measurement_response = EXPECT_SUCCESS(session, client::obw_fetch_measurement(stub(), session, "", 10.0));
  const auto chp_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::chp_fetch_component_carrier_measurement(stub(), session, "", 10.0));

  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_response.mean_rms_composite_evm());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_response.maximum_peak_composite_evm());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_response.mean_frequency_error());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_symbol_index());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_subcarrier_index());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_slot_index());
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_quadrature_error());
  EXPECT_EQ(0.0, mod_acc_fetch_in_band_emission_margin_response.in_band_emission_margin());
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
  EXPECT_LT(0.0, acp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_LE(0.0, acp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_LT(0.0, sem_fetch_component_carrier_measurement_response.absolute_integrated_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.relative_integrated_power());
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_LT(0.0, chp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.relative_power());
}

TEST_F(NiRFmxLTEDriverApiTests, NBIoTSemFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
  EXPECT_SUCCESS(session, client::cfg_nb_io_t_component_carrier(stub(), session, "", 0, NB_IOT_UPLINK_SUBCARRIER_SPACING_15KHZ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_component_carrier_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_component_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(5, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(5, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_LT(0.0, sem_fetch_component_carrier_measurement_response.absolute_integrated_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.relative_integrated_power());
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_EQ(1000.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(3571, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(3571, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(3571, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(3571, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxLTEDriverApiTests, ObwSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.00, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 200e3, 0.0, 0));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_spectrum_response = EXPECT_SUCCESS(session, client::obw_fetch_spectrum(stub(), session, "", 10.0));
  const auto obw_fetch_measurement_response = EXPECT_SUCCESS(session, client::obw_fetch_measurement(stub(), session, "", 10.0));

  EXPECT_LT(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(403, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(403, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, obw_fetch_spectrum_response.spectrum(0));
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
}

TEST_F(NiRFmxLTEDriverApiTests, SEMContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const std::vector<int> empty_int_vec;
  std::vector<float64> componentCarrierBandwidth{20e6, 20e6};
  std::vector<float64> componentCarrierFrequency{-9.9e6, 9.9e6};
  std::vector<float64> componentCarrierMaximumOutputPower{0.0, 0.0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, "", componentCarrierBandwidth, componentCarrierFrequency, empty_int_vec));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL_NS01));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::sem_fetch_total_aggregated_power(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

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
  EXPECT_LT(0.0, sem_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(128429, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(128429, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(128429, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(128429, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxLTEDriverApiTests, SemAdvancedNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  constexpr auto NUMBER_OF_COMPONENT_CARRIERS = 1;
  constexpr auto NUMBER_OF_SUBBLOCKS = 2;
  constexpr auto NUMBER_OF_OFFSET_SEGMENT = 4;
  std::vector<float64> subblocks_center_frequency{1.95e+9, 30e+6};
  std::vector<int32> subblocks_sideband(4, SEM_OFFSET_SIDEBAND_BOTH);
  std::vector<int32> subblocks_rbw_filter_type(4, SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN);
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_number_of_subblocks(stub(), session, "", NUMBER_OF_SUBBLOCKS));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, subblock_string_response.selector_string_out(), subblocks_center_frequency[i]));
    EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, subblock_string_response.selector_string_out(), COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
    EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, subblock_string_response.selector_string_out(), NUMBER_OF_COMPONENT_CARRIERS));
    EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, subblock_string_response.selector_string_out(), {20e+6}, {0.0}, std::vector<int32>()));
    EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, subblock_string_response.selector_string_out(), NUMBER_OF_OFFSET_SEGMENT));
    EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, subblock_string_response.selector_string_out(), {15e+3, 1.5e+6, 5.5e+6, 20.5e+6}, {985e+3, 4.5e+6, 19.5e+6, 24.5e+6}, subblocks_sideband));
    EXPECT_SUCCESS(session, client::sem_cfg_offset_rbw_filter_array(stub(), session, subblock_string_response.selector_string_out(), {10e+3, 250e+3, 250e+3, 250e+3}, subblocks_rbw_filter_type));
    EXPECT_SUCCESS(session, client::sem_cfg_offset_bandwidth_integral_array(stub(), session, subblock_string_response.selector_string_out(), {3, 4, 4, 4}));
    EXPECT_SUCCESS(session, client::sem_cfg_offset_absolute_limit_array(stub(), session, subblock_string_response.selector_string_out(), {-19.5, -8.5, -11.5, -23.5}, {-19.5, -8.5, -11.5, -23.5}));
  }
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::cfge_node_b_category(stub(), session, "", ENODEB_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A));
  EXPECT_SUCCESS(session, client::sem_cfg_downlink_mask(stub(), session, "", SEM_DOWNLINK_MASK_TYPE_ENODEB_CATEGORY_BASED, 15.00e6, 0.00));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::sem_cfg_component_carrier_maximum_output_power_array(stub(), session, subblock_string_response.selector_string_out(), {0.0}));
  }
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  SEMFetchSubblockMeasurementResponse sem_fetch_subblock_measurement_response;
  SEMFetchUpperOffsetMarginArrayResponse sem_fetch_upper_offset_margin_array_response;
  SEMFetchLowerOffsetMarginArrayResponse sem_fetch_lower_offset_margin_array_response;
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = EXPECT_SUCCESS(session, client::build_subblock_string(stub(), "", i));
    sem_fetch_subblock_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_subblock_measurement(stub(), session, "", 10.0));
    for (int j = 0; j < NUMBER_OF_OFFSET_SEGMENT; j++) {
      sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, subblock_string_response.selector_string_out(), 10.0));
      sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, subblock_string_response.selector_string_out(), 10.0));
    }
  }
  const auto sem_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::sem_fetch_total_aggregated_power(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_LT(0.0, sem_fetch_subblock_measurement_response.subblock_power());
  EXPECT_LT(0.0, sem_fetch_subblock_measurement_response.integration_bandwidth());
  EXPECT_LT(0.0, sem_fetch_subblock_measurement_response.frequency());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(3, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(1, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(3, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_LT(0.0, sem_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(32411, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(32411, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(32411, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(32411, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxLTEDriverApiTests, ULLAAModAccMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  std::vector<float64> componentCarrierFrequency{-9.9e6, 9.9e6};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 50.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", 46));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_LAA, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), "", i));
    EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, carrier_string_response.selector_string_out(), 20e6, componentCarrierFrequency[i], 0));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXLTE_ATTRIBUTE_LAA_STARTING_SUBFRAME, 0));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXLTE_ATTRIBUTE_LAA_NUMBER_OF_SUBFRAMES, 1));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXLTE_ATTRIBUTE_LAA_UPLINK_START_POSITION, NIRFMXLTE_INT32_LAA_UPLINK_START_POSITION_00));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXLTE_ATTRIBUTE_LAA_UPLINK_ENDING_SYMBOL, NIRFMXLTE_INT32_LAA_UPLINK_ENDING_SYMBOL_13));
  }
  EXPECT_SUCCESS(session, client::cfg_auto_dmrs_detection_enabled(stub(), session, "", AUTO_DMRS_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_evm_unit(stub(), session, "", MODACC_EVM_UNIT_PERCENTAGE));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<ModAccFetchPUSCHConstellationTraceResponse> mod_acc_fetch_pusch_constellation_trace_response_vec;
  std::vector<ModAccFetchEVMPerSubcarrierTraceResponse> mod_acc_fetch_evm_per_subcarrier_trace_response_vec;
  const auto mod_acc_fetch_composite_evm_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_composite_evm_array(stub(), session, "", 10.0));
  const auto mod_acc_fetch_iq_impairments_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments_array(stub(), session, "", 10.0));
  const auto mod_acc_fetch_in_band_emission_margin_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_in_band_emission_margin_array(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), "", i));
    mod_acc_fetch_pusch_constellation_trace_response_vec.push_back(EXPECT_SUCCESS(session, client::mod_acc_fetch_pusch_constellation_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0)));
    mod_acc_fetch_evm_per_subcarrier_trace_response_vec.push_back(EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_per_subcarrier_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0)));
  }

  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_frequency_error_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.mean_frequency_error().size());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_array_response.mean_frequency_error(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index().size());
  EXPECT_EQ(3, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index().size());
  EXPECT_LT(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index(0));
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index_size());
  EXPECT_EQ(2, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index().size());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset().size());
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance().size());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance(0));
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error_size());
  EXPECT_EQ(2, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error().size());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error(0));
  EXPECT_EQ(2, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin_size());
  EXPECT_EQ(2, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin().size());
  EXPECT_EQ(0.0, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin(0));
  EXPECT_EQ(7200, mod_acc_fetch_pusch_constellation_trace_response_vec[0].data_constellation_size());
  EXPECT_EQ(7200, mod_acc_fetch_pusch_constellation_trace_response_vec[0].data_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response_vec[0].data_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response_vec[0].data_constellation(0).imaginary());
  EXPECT_EQ(1200, mod_acc_fetch_pusch_constellation_trace_response_vec[0].dmrs_constellation_size());
  EXPECT_EQ(1200, mod_acc_fetch_pusch_constellation_trace_response_vec[0].dmrs_constellation().size());
  EXPECT_LT(0.0, mod_acc_fetch_pusch_constellation_trace_response_vec[0].dmrs_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response_vec[0].dmrs_constellation(0).imaginary());
  EXPECT_EQ(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response_vec[0].x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_per_subcarrier_trace_response_vec[0].dx());
  EXPECT_EQ(1200, mod_acc_fetch_evm_per_subcarrier_trace_response_vec[0].mean_rms_evm_per_subcarrier_size());
  EXPECT_EQ(1200, mod_acc_fetch_evm_per_subcarrier_trace_response_vec[0].mean_rms_evm_per_subcarrier().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response_vec[0].mean_rms_evm_per_subcarrier(0));
}

TEST_F(NiRFmxLTEDriverApiTests, ULModAccAcpChpObwSemCompositeContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  std::vector<float64> componentCarrierBandwidth{5e6, 10e6};
  std::vector<float64> componentCarrierFrequency{-9.225e6, 2.475e6};
  std::vector<int> cellID{0, 0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, "", componentCarrierBandwidth, componentCarrierFrequency, cellID));
  EXPECT_SUCCESS(session, client::cfg_auto_dmrs_detection_enabled(stub(), session, "", AUTO_DMRS_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP | MEASUREMENT_TYPES_CHP | MEASUREMENT_TYPES_MODACC | MEASUREMENT_TYPES_OBW | MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL_NS01));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_component_carrier_measurement_array_response = EXPECT_SUCCESS(session, client::sem_fetch_component_carrier_measurement_array(stub(), session, "", 10.0));
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::sem_fetch_total_aggregated_power(stub(), session, "", 10.0));
  const auto obw_fetch_measurement_response = EXPECT_SUCCESS(session, client::obw_fetch_measurement(stub(), session, "", 10.0));
  const auto chp_fetch_component_carrier_measurement_array_response = EXPECT_SUCCESS(session, client::chp_fetch_component_carrier_measurement_array(stub(), session, "", 10.0));
  const auto chp_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::chp_fetch_total_aggregated_power(stub(), session, "", 10.0));
  const auto acp_fetch_offset_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_component_carrier_measurement_array_response = EXPECT_SUCCESS(session, client::acp_fetch_component_carrier_measurement_array(stub(), session, "", 10.0));
  const auto acp_fetch_total_aggregated_power_response = EXPECT_SUCCESS(session, client::acp_fetch_total_aggregated_power(stub(), session, "", 10.0));

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
  EXPECT_EQ(2, sem_fetch_component_carrier_measurement_array_response.absolute_integrated_power_size());
  EXPECT_EQ(2, sem_fetch_component_carrier_measurement_array_response.absolute_integrated_power().size());
  EXPECT_GT(0.0, sem_fetch_component_carrier_measurement_array_response.absolute_integrated_power(0));
  EXPECT_EQ(2, sem_fetch_component_carrier_measurement_array_response.relative_integrated_power_size());
  EXPECT_EQ(2, sem_fetch_component_carrier_measurement_array_response.relative_integrated_power().size());
  EXPECT_GT(0.0, sem_fetch_component_carrier_measurement_array_response.relative_integrated_power(0));
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_EQ(2, chp_fetch_component_carrier_measurement_array_response.absolute_power_size());
  EXPECT_EQ(2, chp_fetch_component_carrier_measurement_array_response.absolute_power().size());
  EXPECT_GT(0.0, chp_fetch_component_carrier_measurement_array_response.absolute_power(0));
  EXPECT_EQ(2, chp_fetch_component_carrier_measurement_array_response.relative_power_size());
  EXPECT_EQ(2, chp_fetch_component_carrier_measurement_array_response.relative_power().size());
  EXPECT_GT(0.0, chp_fetch_component_carrier_measurement_array_response.relative_power(0));
  EXPECT_LT(0.0, chp_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_EQ(2, acp_fetch_component_carrier_measurement_array_response.absolute_power_size());
  EXPECT_EQ(2, acp_fetch_component_carrier_measurement_array_response.absolute_power().size());
  EXPECT_GT(0.0, acp_fetch_component_carrier_measurement_array_response.absolute_power(0));
  EXPECT_EQ(2, acp_fetch_component_carrier_measurement_array_response.relative_power_size());
  EXPECT_EQ(2, acp_fetch_component_carrier_measurement_array_response.relative_power().size());
  EXPECT_GT(0.0, acp_fetch_component_carrier_measurement_array_response.relative_power(0));
  EXPECT_LT(0.0, acp_fetch_total_aggregated_power_response.total_aggregated_power());
}

TEST_F(NiRFmxLTEDriverApiTests, ULModAccMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_SUBBLOCKS = 2;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 1;
  std::vector<std::string> subblock_string_vec;
  const std::vector<float64> center_frequency_vec{1.95e9, 30e6};
  ModAccFetchPUSCHConstellationTraceResponse mod_acc_fetch_pusch_constellation_trace_response;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, NIRFMXLTE_INT32_DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_number_of_dut_antennas(stub(), session, "", 2));
  EXPECT_SUCCESS(session, client::cfg_transmit_antenna_to_analyze(stub(), session, "", 0));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::cfg_number_of_subblocks(stub(), session, "", NUMBER_OF_SUBBLOCKS));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    subblock_string_vec.push_back(subblock_string_response.selector_string_out());
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, subblock_string_vec[i], center_frequency_vec[i]));
    EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, subblock_string_vec[i], COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
    EXPECT_SUCCESS(session, client::cfg_band(stub(), session, subblock_string_vec[i], 1));
    EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, subblock_string_vec[i], NUMBER_OF_COMPONENT_CARRIERS));
    EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, subblock_string_vec[i], {20e6}, {0.0}, {0}));
  }
  EXPECT_SUCCESS(session, client::cfg_auto_dmrs_detection_enabled(stub(), session, "", AUTO_DMRS_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_evm_unit(stub(), session, "", MODACC_EVM_UNIT_PERCENTAGE));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_in_band_emission_mask_type(stub(), session, "", MODACC_IN_BAND_EMISSION_MASK_TYPE_RELEASE_11_ONWARDS));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  ModAccFetchCompositeEVMArrayResponse mod_acc_fetch_composite_evm_array_response;
  ModAccFetchIQImpairmentsArrayResponse mod_acc_fetch_iq_impairments_array_response;
  ModAccFetchInBandEmissionMarginArrayResponse mod_acc_fetch_in_band_emission_margin_array_response;
  ModAccFetchEVMPerSubcarrierTraceResponse mod_acc_fetch_evm_per_subcarrier_trace_response;
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    mod_acc_fetch_composite_evm_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_composite_evm_array(stub(), session, subblock_string_vec[i], 10.0));
    mod_acc_fetch_iq_impairments_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments_array(stub(), session, subblock_string_vec[i], 10.0));
    mod_acc_fetch_in_band_emission_margin_array_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_in_band_emission_margin_array(stub(), session, subblock_string_vec[i], 10.0));
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++) {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_vec[i], j);
      EXPECT_SUCCESS(session, carrier_string_response);
      mod_acc_fetch_evm_per_subcarrier_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_per_subcarrier_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0));
    }
  }
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_vec[i], 0);
    EXPECT_SUCCESS(session, carrier_string_response);
    mod_acc_fetch_pusch_constellation_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_pusch_constellation_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0));
  }

  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.mean_rms_composite_evm(0));
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm().size());
  EXPECT_LT(0.0, mod_acc_fetch_composite_evm_array_response.maximum_peak_composite_evm(0));
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.mean_frequency_error_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.mean_frequency_error().size());
  EXPECT_NE(0.0, mod_acc_fetch_composite_evm_array_response.mean_frequency_error(0));
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index().size());
  EXPECT_EQ(3, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_symbol_index(0));
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index().size());
  EXPECT_LT(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_subcarrier_index(0));
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index_size());
  EXPECT_EQ(1, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index().size());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_array_response.peak_composite_evm_slot_index(0));
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset_size());
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset().size());
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_origin_offset(0));
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance_size());
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance().size());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_gain_imbalance(0));
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error_size());
  EXPECT_EQ(1, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error().size());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_array_response.mean_iq_quadrature_error(0));
  EXPECT_EQ(1, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin_size());
  EXPECT_EQ(1, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin().size());
  EXPECT_EQ(0.0, mod_acc_fetch_in_band_emission_margin_array_response.in_band_emission_margin(0));
  EXPECT_EQ(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response.x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_per_subcarrier_trace_response.dx());
  EXPECT_EQ(1200, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier_size());
  EXPECT_EQ(1200, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier().size());
  EXPECT_LT(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier(0));
  EXPECT_EQ(7200, mod_acc_fetch_pusch_constellation_trace_response.data_constellation_size());
  EXPECT_EQ(7200, mod_acc_fetch_pusch_constellation_trace_response.data_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_EQ(1200, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation_size());
  EXPECT_EQ(1200, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation(0).imaginary());
}

TEST_F(NiRFmxLTEDriverApiTests, ULModAccSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  nidevice_grpc::Session session;
  ModAccFetchCompositeEVMResponse mod_acc_fetch_composite_evm_response;
  int attempts = 1;
  while (1) {
    session = init_session(stub(), PXI_5663E);
    EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
    EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
    EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
    EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 10e6, 0.0, 0));
    EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", 1));
    EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
    EXPECT_SUCCESS(session, client::cfg_auto_dmrs_detection_enabled(stub(), session, "", AUTO_DMRS_DETECTION_ENABLED_TRUE));
    EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_synchronization_mode_and_interval(stub(), session, "", MODACC_SYNCHRONIZATION_MODE_SLOT, 0, 1));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_evm_unit(stub(), session, "", MODACC_EVM_UNIT_PERCENTAGE));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_in_band_emission_mask_type(stub(), session, "", MODACC_IN_BAND_EMISSION_MASK_TYPE_RELEASE_11_ONWARDS));
    EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
    EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

    // Intermittently gives "374603: Unable to synchronize." and outputs nan values
    mod_acc_fetch_composite_evm_response = client::mod_acc_fetch_composite_evm(stub(), session, "", 10.0);
    if (mod_acc_fetch_composite_evm_response.status() == SYNC_FAILURE_WARNING && attempts < 5) {
      TearDown();
      SetUp();
      ++attempts;
    }
    else {
      break;
    }
  }
  EXPECT_SUCCESS(session, mod_acc_fetch_composite_evm_response);
  if (mod_acc_fetch_composite_evm_response.status() != 0) {
    return;
  }
  const auto mod_acc_fetch_iq_impairments_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0));
  const auto mod_acc_fetch_in_band_emission_margin_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_in_band_emission_margin(stub(), session, "", 10.0));
  const auto mod_acc_fetch_pusch_constellation_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_pusch_constellation_trace(stub(), session, "", 10.0));
  const auto mod_acc_fetch_evm_per_subcarrier_trace_response = EXPECT_SUCCESS(session, client::mod_acc_fetch_evm_per_subcarrier_trace(stub(), session, "", 10.0));

  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_symbol_index());
  EXPECT_LE(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_subcarrier_index());
  EXPECT_EQ(0, mod_acc_fetch_composite_evm_response.peak_composite_evm_slot_index());
  EXPECT_GT(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_NE(0.0, mod_acc_fetch_iq_impairments_response.mean_iq_quadrature_error());
  EXPECT_GT(0.0, mod_acc_fetch_in_band_emission_margin_response.in_band_emission_margin());
  EXPECT_EQ(144, mod_acc_fetch_pusch_constellation_trace_response.data_constellation_size());
  EXPECT_EQ(144, mod_acc_fetch_pusch_constellation_trace_response.data_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_EQ(24, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation_size());
  EXPECT_EQ(24, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation().size());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_pusch_constellation_trace_response.dmrs_constellation(0).imaginary());
  EXPECT_EQ(0.0, mod_acc_fetch_evm_per_subcarrier_trace_response.x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_per_subcarrier_trace_response.dx());
  EXPECT_EQ(600, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier_size());
  EXPECT_EQ(600, mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier().size());
  EXPECT_TRUE(isnan(mod_acc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier(0)));
}

TEST_F(NiRFmxLTEDriverApiTests, ULPvtSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 50.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, "", 10.0e6, 0.0, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_TDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_off_power_exclusion_periods(stub(), session, "", 0.0, 0.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto pvt_fetch_signal_power_trace_response = EXPECT_SUCCESS(session, client::pvt_fetch_signal_power_trace(stub(), session, "", 10.0));
  const auto pvt_fetch_measurement_response = EXPECT_SUCCESS(session, client::pvt_fetch_measurement(stub(), session, "", 10.0));

  EXPECT_GT(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_LT(0.0, pvt_fetch_signal_power_trace_response.dx());
  const auto signal_power_size = pvt_fetch_signal_power_trace_response.signal_power_size();
  EXPECT_LT(25000, signal_power_size);
  EXPECT_EQ(signal_power_size, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_GT(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_EQ(signal_power_size, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_EQ(signal_power_size, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_GT(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
  EXPECT_EQ(0, pvt_fetch_measurement_response.measurement_status());
  EXPECT_LT(0.0, pvt_fetch_measurement_response.mean_absolute_off_power_before());
  EXPECT_LT(0.0, pvt_fetch_measurement_response.mean_absolute_off_power_after());
  // Sometimes nan: EXPECT_LT(0.0, pvt_fetch_measurement_response.mean_absolute_on_power());
  EXPECT_LT(0.0, pvt_fetch_measurement_response.burst_width());
}

TEST_F(NiRFmxLTEDriverApiTests, ULSlotPhaseContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const auto NUMBER_OF_SLOTS = 20;
  std::vector<float64> componentCarrierBandwidth{20e6, 20e6};
  std::vector<float64> componentCarrierFrequency{-9.9e6, 9.9e6};
  std::vector<int> cellID{0, 1};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e+6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_spacing(stub(), session, "", COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, -1));
  EXPECT_SUCCESS(session, client::cfg_number_of_component_carriers(stub(), session, "", NUMBER_OF_COMPONENT_CARRIERS));
  EXPECT_SUCCESS(session, client::cfg_component_carrier_array(stub(), session, "", componentCarrierBandwidth, componentCarrierFrequency, cellID));
  EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, UPLINK_DOWNLINK_CONFIGURATION_0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPHASE, true));
  EXPECT_SUCCESS(session, client::slot_phase_cfg_synchronization_mode_and_interval(stub(), session, "", SLOT_PHASE_SYNCHRONIZATION_MODE_SLOT, 0, NUMBER_OF_SLOTS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  SlotPhaseFetchPhaseDiscontinuitiesResponse slot_phase_fetch_phase_discontinuities_response;
  SlotPhaseFetchSamplePhaseErrorResponse slot_phase_fetch_sample_phase_error_response;
  SlotPhaseFetchSamplePhaseErrorLinearFitTraceResponse slot_phase_fetch_sample_phase_error_linear_fit_trace_response;
  const auto slot_phase_fetch_maximum_phase_discontinuity_array_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_maximum_phase_discontinuity_array(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), "", i));
    slot_phase_fetch_phase_discontinuities_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_phase_discontinuities(stub(), session, carrier_string_response.selector_string_out(), 10.0));
    slot_phase_fetch_sample_phase_error_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_sample_phase_error(stub(), session, carrier_string_response.selector_string_out(), 10.0));
    slot_phase_fetch_sample_phase_error_linear_fit_trace_response = EXPECT_SUCCESS(session, client::slot_phase_fetch_sample_phase_error_linear_fit_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0));
  }

  EXPECT_EQ(2, slot_phase_fetch_maximum_phase_discontinuity_array_response.maximum_phase_discontinuity_size());
  EXPECT_EQ(2, slot_phase_fetch_maximum_phase_discontinuity_array_response.maximum_phase_discontinuity().size());
  EXPECT_NE(0.0, slot_phase_fetch_maximum_phase_discontinuity_array_response.maximum_phase_discontinuity(0));
  EXPECT_EQ(20, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity_size());
  EXPECT_EQ(20, slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity().size());
  EXPECT_TRUE(isnan(slot_phase_fetch_phase_discontinuities_response.slot_phase_discontinuity(0)));
  EXPECT_EQ(0.0, slot_phase_fetch_sample_phase_error_response.x0());
  EXPECT_LT(0.0, slot_phase_fetch_sample_phase_error_response.dx());
  EXPECT_EQ(307200, slot_phase_fetch_sample_phase_error_response.sample_phase_error_size());
  EXPECT_EQ(307200, slot_phase_fetch_sample_phase_error_response.sample_phase_error().size());
  EXPECT_NE(0.0, slot_phase_fetch_sample_phase_error_response.sample_phase_error(0));
  EXPECT_EQ(0.0, slot_phase_fetch_sample_phase_error_linear_fit_trace_response.x0());
  EXPECT_LT(0.0, slot_phase_fetch_sample_phase_error_linear_fit_trace_response.dx());
  EXPECT_EQ(307200, slot_phase_fetch_sample_phase_error_linear_fit_trace_response.sample_phase_error_linear_fit_size());
  EXPECT_EQ(307200, slot_phase_fetch_sample_phase_error_linear_fit_trace_response.sample_phase_error_linear_fit().size());
  EXPECT_NE(0.0, slot_phase_fetch_sample_phase_error_linear_fit_trace_response.sample_phase_error_linear_fit(0));
}

TEST_F(NiRFmxLTEDriverApiTests, ULSlotPowerSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  nidevice_grpc::Session session;
  BuildSubblockStringResponse subblock_string_response;
  BuildCarrierStringResponse carrier_string_response;
  SlotPowerFetchPowersResponse slot_power_fetch_powers_response;
  int attempts = 1;
  while (1) {
    session = init_session(stub(), PXI_5663E);
    EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
    EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1.95e9, 0.0, 0.0));
    EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PFI0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
    subblock_string_response = EXPECT_SUCCESS(session, client::build_subblock_string(stub(), "", 0));
    carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), 0));
    EXPECT_SUCCESS(session, client::cfg_component_carrier(stub(), session, carrier_string_response.selector_string_out(), 10e+6, 0.0, 0));
    EXPECT_SUCCESS(session, client::cfg_duplex_scheme(stub(), session, "", DUPLEX_SCHEME_FDD, 0));
    EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SLOTPOWER, true));
    EXPECT_SUCCESS(session, client::slot_power_cfg_measurement_interval(stub(), session, "", 0, 10));
    EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

    // Intermittently gives "374603: Unable to synchronize." and outputs nan values
    slot_power_fetch_powers_response = client::slot_power_fetch_powers(stub(), session, "", 10.0);
    if (slot_power_fetch_powers_response.status() == SYNC_FAILURE_WARNING && attempts < 5) {
      TearDown();
      SetUp();
      ++attempts;
    }
    else {
      break;
    }
  }
  EXPECT_SUCCESS(session, slot_power_fetch_powers_response);
  if (slot_power_fetch_powers_response.status() != 0) {
    return;
  }

  EXPECT_EQ(10, slot_power_fetch_powers_response.subframe_power_size());
  EXPECT_EQ(10, slot_power_fetch_powers_response.subframe_power().size());
  EXPECT_LT(0.0, slot_power_fetch_powers_response.subframe_power(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
