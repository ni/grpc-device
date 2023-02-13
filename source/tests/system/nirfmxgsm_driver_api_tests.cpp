#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxgsm/nirfmxgsm_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxgsm_grpc;
namespace client = nirfmxgsm_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxGSMDriverApiTests : public Test {
 protected:
  NiRFmxGSMDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxGSM::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxGSMDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxGSM::Stub>& stub() const
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
  std::unique_ptr<NiRFmxGSM::Stub> stub_;
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

TEST_F(NiRFmxGSMDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxGSMDriverApiTests, EvmFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_TIMESLOTS = 1;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 890.2e6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", NIRFMXGSM_INT32_IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.00, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 582e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_number_of_timeslots(stub(), session, "", NUMBER_OF_TIMESLOTS));
  EXPECT_SUCCESS(session, client::cfg_auto_tsc_detection_enabled(stub(), session, "", AUTO_TSC_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::cfg_signal_type(stub(), session, "slot::all", MODULATION_TYPE_8PSK, BURST_TYPE_NB, HB_FILTER_WIDTH_NARROW));
  EXPECT_SUCCESS(session, client::cfg_tsc(stub(), session, "slot::all", TSC_TSC0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_evm_response = client::mod_acc_fetch_evm(stub(), session, "", 10.0);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto mod_acc_fetch_detected_tsc_array_response = client::mod_acc_fetch_detected_tsc_array(stub(), session, "", 10.0);
  const auto mod_acc_fetch_evm_trace_response = client::mod_acc_fetch_evm_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, mod_acc_fetch_evm_response);
  EXPECT_LT(100.0, mod_acc_fetch_evm_response.mean_rms_evm());
  EXPECT_LT(100.0, mod_acc_fetch_evm_response.maximum_rms_evm());
  EXPECT_LT(200.0, mod_acc_fetch_evm_response.mean_peak_evm());
  EXPECT_LT(200.0, mod_acc_fetch_evm_response.maximum_peak_evm());
  EXPECT_LT(20.0, mod_acc_fetch_evm_response.ninety_fifth_percentile_evm());
  EXPECT_NE(0.0, mod_acc_fetch_evm_response.mean_frequency_error());
  EXPECT_LT(100, mod_acc_fetch_evm_response.peak_evm_symbol());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(-20.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_GT(-20.0, mod_acc_fetch_iq_impairments_response.maximum_iq_gain_imbalance());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.maximum_iq_origin_offset());
  EXPECT_SUCCESS(session, mod_acc_fetch_detected_tsc_array_response);
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc_size());
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc().size());
  EXPECT_NE(0, mod_acc_fetch_detected_tsc_array_response.detected_tsc(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_evm_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_evm_trace_response.x0());
  EXPECT_EQ(1.0, mod_acc_fetch_evm_trace_response.dx());
  EXPECT_LT(100, mod_acc_fetch_evm_trace_response.evm_size());
  EXPECT_LT(100, mod_acc_fetch_evm_trace_response.evm().size());
  EXPECT_LT(100.0, mod_acc_fetch_evm_trace_response.evm(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_constellation_trace_response);
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation_trace(0).real());
  EXPECT_NE(0.0, mod_acc_fetch_constellation_trace_response.constellation_trace(0).imaginary());
}

TEST_F(NiRFmxGSMDriverApiTests, ModAccOrfsPvtCompositeFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_TIMESLOTS = 1;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 890.2e6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", BAND_PGSM));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", NIRFMXGSM_INT32_IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 582e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC | MEASUREMENT_TYPES_ORFS | MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::cfg_number_of_timeslots(stub(), session, "", NUMBER_OF_TIMESLOTS));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::orfs_cfg_averaging(stub(), session, "", ORFS_AVERAGING_ENABLED_FALSE, 10, ORFS_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::orfs_cfg_measurement_type(stub(), session, "", ORFS_MEASUREMENT_TYPE_MODULATION_AND_SWITCHING));
  EXPECT_SUCCESS(session, client::orfs_cfg_offset_frequency_mode(stub(), session, "", ORFS_OFFSET_FREQUENCY_MODE_STANDARD));
  EXPECT_SUCCESS(session, client::cfg_auto_tsc_detection_enabled(stub(), session, "", AUTO_TSC_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::cfg_signal_type(stub(), session, "slot::all", MODULATION_TYPE_8PSK, BURST_TYPE_NB, HB_FILTER_WIDTH_NARROW));
  EXPECT_SUCCESS(session, client::cfg_tsc(stub(), session, "slot::all", TSC_TSC0));
  EXPECT_SUCCESS(session, client::cfg_power_control_level(stub(), session, "slot::all", 0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_evm_response = client::mod_acc_fetch_evm(stub(), session, "", 10.0);
  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto mod_acc_fetch_detected_tsc_array_response = client::mod_acc_fetch_detected_tsc_array(stub(), session, "", 10.0);
  const auto mod_acc_fetch_pfer_response = client::mod_acc_fetch_pfer(stub(), session, "", 10.0);
  const auto orfs_fetch_modulation_results_array_response = client::orfs_fetch_modulation_results_array(stub(), session, "", 10.0);
  const auto orfs_fetch_switching_results_array_response = client::orfs_fetch_switching_results_array(stub(), session, "", 10.0);
  const auto pvt_fetch_slot_measurement_array_response = client::pvt_fetch_slot_measurement_array(stub(), session, "", 10.0);
  const auto pvt_fetch_measurement_status_response = client::pvt_fetch_measurement_status(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, mod_acc_fetch_evm_response);
  EXPECT_LT(50.0, mod_acc_fetch_evm_response.mean_rms_evm());
  EXPECT_LT(50.0, mod_acc_fetch_evm_response.maximum_rms_evm());
  EXPECT_LT(200.0, mod_acc_fetch_evm_response.mean_peak_evm());
  EXPECT_LT(200.0, mod_acc_fetch_evm_response.maximum_peak_evm());
  EXPECT_LT(10.0, mod_acc_fetch_evm_response.ninety_fifth_percentile_evm());
  EXPECT_GT(0.0, mod_acc_fetch_evm_response.mean_frequency_error());
  EXPECT_LT(50, mod_acc_fetch_evm_response.peak_evm_symbol());
  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(-20.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_GT(-20.0, mod_acc_fetch_iq_impairments_response.maximum_iq_gain_imbalance());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.maximum_iq_origin_offset());
  EXPECT_SUCCESS(session, mod_acc_fetch_detected_tsc_array_response);
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc_size());
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc().size());
  EXPECT_NE(0, mod_acc_fetch_detected_tsc_array_response.detected_tsc(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_pfer_response);
  EXPECT_TRUE(isnan(mod_acc_fetch_pfer_response.mean_rms_phase_error()));
  EXPECT_TRUE(isnan(mod_acc_fetch_pfer_response.maximum_rms_phase_error()));
  EXPECT_TRUE(isnan(mod_acc_fetch_pfer_response.mean_peak_phase_error()));
  EXPECT_TRUE(isnan(mod_acc_fetch_pfer_response.maximum_peak_phase_error()));
  EXPECT_TRUE(isnan(mod_acc_fetch_pfer_response.mean_frequency_error()));
  EXPECT_EQ(-1, mod_acc_fetch_pfer_response.peak_symbol());
  EXPECT_SUCCESS(session, orfs_fetch_modulation_results_array_response);
  EXPECT_NE(0.0, orfs_fetch_modulation_results_array_response.modulation_carrier_power());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_relative_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_relative_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.lower_relative_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_relative_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_relative_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.upper_relative_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_absolute_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_absolute_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.lower_absolute_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_absolute_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_absolute_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, orfs_fetch_switching_results_array_response);
  EXPECT_NE(0.0, orfs_fetch_switching_results_array_response.switching_carrier_power());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_relative_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_relative_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.lower_relative_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_relative_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_relative_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.upper_relative_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_absolute_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_absolute_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.lower_absolute_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_absolute_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_absolute_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, pvt_fetch_slot_measurement_array_response);
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_average_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_average_power().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_average_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_width_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_width().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_burst_width(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_measurement_status_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_measurement_status().size());
  EXPECT_EQ(0, pvt_fetch_slot_measurement_array_response.slot_measurement_status(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_maximum_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_maximum_power().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_maximum_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_minimum_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_minimum_power().size());
  EXPECT_GT(-50.0, pvt_fetch_slot_measurement_array_response.slot_minimum_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_threshold_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_threshold().size());
  EXPECT_GT(0.0, pvt_fetch_slot_measurement_array_response.slot_burst_threshold(0));
  EXPECT_SUCCESS(session, pvt_fetch_measurement_status_response);
  EXPECT_EQ(0, pvt_fetch_measurement_status_response.measurement_status());
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxGSMDriverApiTests, DISABLED_MultiSlotPvtFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxGSMDriverApiTests, OrfsFromExample_FetchData_DataLooksReasonable)
{
  const auto AUTO_LEVEL_ON = 1;
  int32 autoLevel = AUTO_LEVEL_ON;
  // TODO: Conversion process ignored auto_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 890.2e6));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", NIRFMXGSM_INT32_IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 582e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_number_of_timeslots(stub(), session, "", 1));
  EXPECT_SUCCESS(session, client::cfg_signal_type(stub(), session, "slot::all", MODULATION_TYPE_8PSK, BURST_TYPE_NB, HB_FILTER_WIDTH_NARROW));
  if(autoLevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 0.0046));
  }
  else
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_auto_tsc_detection_enabled(stub(), session, "", AUTO_TSC_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::cfg_tsc(stub(), session, "slot::all", TSC_TSC0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ORFS, true));
  EXPECT_SUCCESS(session, client::orfs_cfg_noise_compensation_enabled(stub(), session, "", ORFS_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::orfs_cfg_measurement_type(stub(), session, "", ORFS_MEASUREMENT_TYPE_MODULATION_AND_SWITCHING));
  EXPECT_SUCCESS(session, client::orfs_cfg_offset_frequency_mode(stub(), session, "", ORFS_OFFSET_FREQUENCY_MODE_STANDARD));
  EXPECT_SUCCESS(session, client::orfs_cfg_evaluation_symbols(stub(), session, "", 50.0, 0, 90.0));
  EXPECT_SUCCESS(session, client::orfs_cfg_averaging(stub(), session, "", ORFS_AVERAGING_ENABLED_FALSE, 10, ORFS_AVERAGING_TYPE_LOG));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto orfs_fetch_modulation_results_array_response = client::orfs_fetch_modulation_results_array(stub(), session, "", 10.0);
  const auto orfs_fetch_switching_results_array_response = client::orfs_fetch_switching_results_array(stub(), session, "", 10.0);
  const auto orfs_fetch_modulation_power_trace_response = client::orfs_fetch_modulation_power_trace(stub(), session, "", 10.0);
  const auto orfs_fetch_switching_power_trace_response = client::orfs_fetch_switching_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, orfs_fetch_modulation_results_array_response);
  EXPECT_LT(0.0, orfs_fetch_modulation_results_array_response.modulation_carrier_power());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_relative_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_relative_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.lower_relative_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_relative_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_relative_power().size());
  EXPECT_GT(-30.0, orfs_fetch_modulation_results_array_response.upper_relative_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_absolute_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.lower_absolute_power().size());
  EXPECT_GT(-20.0, orfs_fetch_modulation_results_array_response.lower_absolute_power(0));
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_absolute_power_size());
  EXPECT_EQ(11, orfs_fetch_modulation_results_array_response.upper_absolute_power().size());
  EXPECT_GT(-20.0, orfs_fetch_modulation_results_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, orfs_fetch_switching_results_array_response);
  EXPECT_LT(10.0, orfs_fetch_switching_results_array_response.switching_carrier_power());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_relative_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_relative_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.lower_relative_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_relative_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_relative_power().size());
  EXPECT_GT(-40.0, orfs_fetch_switching_results_array_response.upper_relative_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_absolute_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.lower_absolute_power().size());
  EXPECT_GT(-20.0, orfs_fetch_switching_results_array_response.lower_absolute_power(0));
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_absolute_power_size());
  EXPECT_EQ(4, orfs_fetch_switching_results_array_response.upper_absolute_power().size());
  EXPECT_GT(-20.0, orfs_fetch_switching_results_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, orfs_fetch_modulation_power_trace_response);
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.offset_frequency_size());
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.offset_frequency().size());
  EXPECT_EQ(0.0, orfs_fetch_modulation_power_trace_response.offset_frequency(0));
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.absolute_power_size());
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.absolute_power().size());
  EXPECT_LT(10.0, orfs_fetch_modulation_power_trace_response.absolute_power(0));
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.relative_power_size());
  EXPECT_EQ(23, orfs_fetch_modulation_power_trace_response.relative_power().size());
  EXPECT_EQ(0.0, orfs_fetch_modulation_power_trace_response.relative_power(0));
  EXPECT_SUCCESS(session, orfs_fetch_switching_power_trace_response);
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.offset_frequency_size());
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.offset_frequency().size());
  EXPECT_EQ(0.0, orfs_fetch_switching_power_trace_response.offset_frequency(0));
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.absolute_power_size());
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.absolute_power().size());
  EXPECT_LT(10.0, orfs_fetch_switching_power_trace_response.absolute_power(0));
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.relative_power_size());
  EXPECT_EQ(9, orfs_fetch_switching_power_trace_response.relative_power().size());
  EXPECT_EQ(0.0, orfs_fetch_switching_power_trace_response.relative_power(0));
}

TEST_F(NiRFmxGSMDriverApiTests, PferFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_TIMESLOTS = 1;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 890.2e6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", NIRFMXGSM_INT32_IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 582e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_number_of_timeslots(stub(), session, "", NUMBER_OF_TIMESLOTS));
  EXPECT_SUCCESS(session, client::cfg_signal_type(stub(), session, "slot::all", MODULATION_TYPE_GMSK, BURST_TYPE_NB, HB_FILTER_WIDTH_NARROW));
  EXPECT_SUCCESS(session, client::cfg_auto_tsc_detection_enabled(stub(), session, "", AUTO_TSC_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::cfg_tsc(stub(), session, "slot::all", TSC_TSC0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto mod_acc_fetch_iq_impairments_response = client::mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto mod_acc_fetch_pfer_response = client::mod_acc_fetch_pfer(stub(), session, "", 10.0);
  const auto mod_acc_fetch_detected_tsc_array_response = client::mod_acc_fetch_detected_tsc_array(stub(), session, "", 10.0);
  const auto mod_acc_fetch_phase_error_trace_response = client::mod_acc_fetch_phase_error_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(-30.0, mod_acc_fetch_iq_impairments_response.mean_iq_gain_imbalance());
  EXPECT_GT(-30.0, mod_acc_fetch_iq_impairments_response.maximum_iq_gain_imbalance());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.mean_iq_origin_offset());
  EXPECT_GT(-10.0, mod_acc_fetch_iq_impairments_response.maximum_iq_origin_offset());
  EXPECT_SUCCESS(session, mod_acc_fetch_pfer_response);
  EXPECT_LT(80.0, mod_acc_fetch_pfer_response.mean_rms_phase_error());
  EXPECT_LT(80.0, mod_acc_fetch_pfer_response.maximum_rms_phase_error());
  EXPECT_LT(160.0, mod_acc_fetch_pfer_response.mean_peak_phase_error());
  EXPECT_LT(160.0, mod_acc_fetch_pfer_response.maximum_peak_phase_error());
  EXPECT_LT(0.0, mod_acc_fetch_pfer_response.mean_frequency_error());
  EXPECT_EQ(84, mod_acc_fetch_pfer_response.peak_symbol());
  EXPECT_SUCCESS(session, mod_acc_fetch_detected_tsc_array_response);
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc_size());
  EXPECT_EQ(1, mod_acc_fetch_detected_tsc_array_response.detected_tsc().size());
  EXPECT_EQ(-1, mod_acc_fetch_detected_tsc_array_response.detected_tsc(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_phase_error_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_phase_error_trace_response.x0());
  EXPECT_LT(0.0, mod_acc_fetch_phase_error_trace_response.dx());
  EXPECT_EQ(588, mod_acc_fetch_phase_error_trace_response.phase_error_size());
  EXPECT_EQ(588, mod_acc_fetch_phase_error_trace_response.phase_error().size());
  EXPECT_GT(-80.0, mod_acc_fetch_phase_error_trace_response.phase_error(0));
}

TEST_F(NiRFmxGSMDriverApiTests, PvtFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_TIME_SLOTS = 1;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 890.2e6, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_band(stub(), session, "", BAND_PGSM));
  EXPECT_SUCCESS(session, client::cfg_link_direction(stub(), session, "", LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", NIRFMXGSM_INT32_IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 582e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_number_of_timeslots(stub(), session, "", NUMBER_OF_TIME_SLOTS));
  EXPECT_SUCCESS(session, client::cfg_auto_tsc_detection_enabled(stub(), session, "", AUTO_TSC_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::cfg_signal_type(stub(), session, "slot::all", MODULATION_TYPE_8PSK, BURST_TYPE_NB, HB_FILTER_WIDTH_NARROW));
  EXPECT_SUCCESS(session, client::cfg_tsc(stub(), session, "slot::all", TSC_TSC0));
  EXPECT_SUCCESS(session, client::cfg_power_control_level(stub(), session, "slot::all", 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXGSM_ATTRIBUTE_PVT_RBW_FILTER_BANDWIDTH, 500000.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto pvt_fetch_measurement_status_response = client::pvt_fetch_measurement_status(stub(), session, "", 10.0);
  const auto pvt_fetch_slot_measurement_array_response = client::pvt_fetch_slot_measurement_array(stub(), session, "", 10.0);
  const auto pvt_fetch_power_trace_response = client::pvt_fetch_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, pvt_fetch_measurement_status_response);
  EXPECT_EQ(0, pvt_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, pvt_fetch_slot_measurement_array_response);
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_average_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_average_power().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_average_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_width_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_width().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_burst_width(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_measurement_status_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_measurement_status().size());
  EXPECT_EQ(0, pvt_fetch_slot_measurement_array_response.slot_measurement_status(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_maximum_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_maximum_power().size());
  EXPECT_LT(0.0, pvt_fetch_slot_measurement_array_response.slot_maximum_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_minimum_power_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_minimum_power().size());
  EXPECT_GT(-40.0, pvt_fetch_slot_measurement_array_response.slot_minimum_power(0));
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_threshold_size());
  EXPECT_EQ(1, pvt_fetch_slot_measurement_array_response.slot_burst_threshold().size());
  EXPECT_GT(0.0, pvt_fetch_slot_measurement_array_response.slot_burst_threshold(0));
  EXPECT_SUCCESS(session, pvt_fetch_power_trace_response);
  EXPECT_NE(0.0, pvt_fetch_power_trace_response.x0());
  EXPECT_NE(0.0, pvt_fetch_power_trace_response.dx());
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.upper_mask_size());
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.upper_mask().size());
  EXPECT_EQ(-36, pvt_fetch_power_trace_response.upper_mask(0));
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.signal_power_size());
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.signal_power().size());
  EXPECT_LT(0.0, pvt_fetch_power_trace_response.signal_power(0));
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.lower_mask_size());
  EXPECT_EQ(1767, pvt_fetch_power_trace_response.lower_mask().size());
  EXPECT_TRUE(isinf(pvt_fetch_power_trace_response.lower_mask(0)));
}
}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
