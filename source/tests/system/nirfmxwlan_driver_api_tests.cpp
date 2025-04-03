#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxwlan/nirfmxwlan_client.h"
#include "nirfsa/nirfsa_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace ::testing;
using namespace nirfmxwlan_grpc;
namespace client = nirfmxwlan_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

typedef ::google::protobuf::int32 int32;
typedef ::google::protobuf::int64 int64;
typedef double float64;

constexpr auto PXI_5663E = "5663E";
constexpr auto RISING_EDGE_DETECTION_FAILED_WARNING = 379206;
constexpr auto RISING_EDGE_DETECTION_FAILED_WARNING_STR = "Rising edge detection failed for the acquired waveform";
constexpr auto EVM_CHIPS_MUST_BE_300_WARNING = 685353;
constexpr auto EVM_CHIPS_MUST_BE_300_WARNING_STR = "Number of available payload chips for EVM measurements";
constexpr auto INCORRECT_TYPE_ERROR = -380251;
constexpr auto INCORRECT_TYPE_ERROR_STR = "Incorrect data type specified";

class NiRFmxWLANDriverApiTests : public Test {
 protected:
  NiRFmxWLANDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxWLAN::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxWLANDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxWLAN::Stub>& stub() const
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
  std::unique_ptr<NiRFmxWLAN::Stub> stub_;
};

std::string get_comma_seperated_string(const std::vector<std::string>& array_of_names)
{
  int name_index = 0;
  int comma_index = 0;
  std::stringstream output;
  while (name_index < array_of_names.size()) {
    output << array_of_names[name_index];
    if (++name_index != array_of_names.size()) {
      output << ',';
    }
  }
  return output.str();
}

InitializeResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, resource_name, options);
}

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  return init(stub, model, "FakeDevice");
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

nidevice_grpc::Session init_instr_session(const instr_client::StubPtr& stub, const char* resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + PXI_5663E;
  auto response = instr_client::initialize(stub, std::string(resource_name), options);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

nidevice_grpc::Session init_analysis_session(const client::StubPtr& stub)
{
  auto options = std::string("Analysisonly = 1; MaxNumWfms:8");
  auto response = client::initialize(stub, "", options);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
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

TEST_F(NiRFmxWLANDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxWLANDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
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

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccTXPCompositeFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP | MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0));
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);
  EXPECT_WARNING(RISING_EDGE_DETECTION_FAILED_WARNING, RISING_EDGE_DETECTION_FAILED_WARNING_STR, session, txp_fetch_measurement_response);

  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

TEST_F(NiRFmxWLANDriverApiTests, SemFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_STANDARD));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_span(stub(), session, "", SEM_SPAN_AUTO_TRUE, 66.0e6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_carrier_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.relative_power());
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
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(2454, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxWLANDriverApiTests, SEMCustomMaskFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 3;
  std::vector<float64> offset_start_frequency{9e06, 11e06, 20e06};
  std::vector<float64> offset_stop_frequency{11e06, 20e06, 40e06};
  std::vector<int> offset_sideband{SEM_OFFSET_SIDEBAND_BOTH, SEM_OFFSET_SIDEBAND_BOTH, SEM_OFFSET_SIDEBAND_BOTH};
  std::vector<float64> relative_limit_start{0.0, -20.0, -28.0};
  std::vector<float64> relative_limit_stop{-20.0, -28.0, -40.0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_CUSTOM));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, "", offset_start_frequency, offset_stop_frequency, offset_sideband));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_relative_limit_array(stub(), session, "", relative_limit_start, relative_limit_stop));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  const auto sem_fetch_carrier_measurement_response = EXPECT_SUCCESS(session, client::sem_fetch_carrier_measurement(stub(), session, "", 10.0));
  const auto sem_fetch_lower_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0));
  const auto sem_fetch_upper_offset_margin_array_response = EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0));
  int32 array_size = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_spectrum_response = EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.relative_power());
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
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(2974, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(2974, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(2974, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(2974, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxWLANDriverApiTests, TXPFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  EXPECT_WARNING(RISING_EDGE_DETECTION_FAILED_WARNING, RISING_EDGE_DETECTION_FAILED_WARNING_STR, session, txp_fetch_power_trace_response);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);
  EXPECT_WARNING(RISING_EDGE_DETECTION_FAILED_WARNING, RISING_EDGE_DETECTION_FAILED_WARNING_STR, session, txp_fetch_measurement_response);

  EXPECT_GT(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power().size());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_LT(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

TEST_F(NiRFmxWLANDriverApiTests, DSSSModAccFromExample_FetchData_DataLooksReasonable)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resource_name);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_B));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_DSSSMODACC, true));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_measurement_length(stub(), session, "", 0, 1000));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE, NIRFMXWLAN_INT32_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE_RECTANGULAR));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_DSSSMODACC_PULSE_SHAPING_FILTER_PARAMETER, 0.50));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_evm_unit(stub(), session, "", DSSSMODACC_EVM_UNIT_PERCENTAGE));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_averaging(stub(), session, "", DSSSMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto dsss_mod_acc_fetch_evm_response = client::dsss_mod_acc_fetch_evm(stub(), session, "", 10.0);
  EXPECT_WARNING(EVM_CHIPS_MUST_BE_300_WARNING, EVM_CHIPS_MUST_BE_300_WARNING_STR, session, dsss_mod_acc_fetch_evm_response);
  const auto dsss_mod_acc_fetch_ppdu_information_response = client::dsss_mod_acc_fetch_ppdu_information(stub(), session, "", 10.0);
  EXPECT_WARNING(EVM_CHIPS_MUST_BE_300_WARNING, EVM_CHIPS_MUST_BE_300_WARNING_STR, session, dsss_mod_acc_fetch_ppdu_information_response);
  const auto dsss_mod_acc_fetch_iq_impairments_response = client::dsss_mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  EXPECT_WARNING(EVM_CHIPS_MUST_BE_300_WARNING, EVM_CHIPS_MUST_BE_300_WARNING_STR, session, dsss_mod_acc_fetch_iq_impairments_response);
  const auto dsss_mod_acc_fetch_evm_per_chip_mean_trace_response = client::dsss_mod_acc_fetch_evm_per_chip_mean_trace(stub(), session, "", 10.0);
  EXPECT_WARNING(EVM_CHIPS_MUST_BE_300_WARNING, EVM_CHIPS_MUST_BE_300_WARNING_STR, session, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response);
  const auto dsss_mod_acc_fetch_constellation_trace_response = client::dsss_mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);
  EXPECT_WARNING(EVM_CHIPS_MUST_BE_300_WARNING, EVM_CHIPS_MUST_BE_300_WARNING_STR, session, dsss_mod_acc_fetch_constellation_trace_response);

  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.rms_evm_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm_80211_2016_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm_80211_2007_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm_80211_1999_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.frequency_error_mean());
  EXPECT_NE(0.0, dsss_mod_acc_fetch_evm_response.chip_clock_error_mean());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_response.number_of_chips_used());
  EXPECT_EQ(3, dsss_mod_acc_fetch_ppdu_information_response.data_modulation_format());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.payload_length());
  EXPECT_EQ(1, dsss_mod_acc_fetch_ppdu_information_response.preamble_type());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.locked_clocks_bit());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.header_crc_status());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.psdu_crc_status());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_origin_offset_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.x0());
  EXPECT_EQ(1, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.dx());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.evm_per_chip_mean_size());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.evm_per_chip_mean().size());
  EXPECT_EQ(0, dsss_mod_acc_fetch_constellation_trace_response.actual_array_size());
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccFromExample_FetchData_DataLooksReasonable)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resource_name);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_iq_impairments_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_iq_impairments(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_ppdu_type_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_mcs_index_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_mcs_index(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_guard_interval_type_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_guard_interval_type(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_lsig_parity_check_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_lsig_parity_check_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_sigcrc_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_sigcrc_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_sigbcrc_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_sigbcrc_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_pilot_constellation_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_data_constellation_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.0));

  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_EQ(16, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.relative_iq_origin_offset_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.absolute_iq_origin_offset_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_timing_skew_mean());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_guard_interval_type_response.guard_interval_type());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigbcrc_status_response.sig_b_crc_status());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_EQ(-26, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(1, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(53, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(53, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean(0));
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  std::vector<std::string> resource_names = {"RFSA1", "RFSA2"};
  std::string comma_separated_resource_name = get_comma_seperated_string(resource_names);
  std::vector<float64> center_frequency_array{5.180000e9, 5.260000e9};
  std::vector<std::string> selected_ports_strings = {"", ""};
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, comma_separated_resource_name);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), center_frequency_array[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    auto port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    selected_ports_strings[i] = port_string_response.selector_string_out();
    port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, port_string_response.selector_string_out(), 0.0));
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, port_string_response.selector_string_out(), 0.0));
  }
  std::string selected_ports_string_comma_separated = get_comma_seperated_string(selected_ports_strings);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selected_ports_string_comma_separated));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED, NIRFMXWLAN_INT32_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_ppdu_type_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_guard_interval_type_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_guard_interval_type(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_lsig_parity_check_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_lsig_parity_check_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_sigcrc_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_sigcrc_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_sigbcrc_status_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_sigbcrc_status(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_number_of_users_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_number_of_users(stub(), session, "", 10.0));
  const auto number_of_users = ofdm_mod_acc_fetch_number_of_users_response.number_of_users();
  std::vector<int32> mcs_index_vec(number_of_users);
  std::vector<int32> number_of_space_time_streams_vec(number_of_users);
  std::vector<int32> space_time_stream_offset_vec(number_of_users);
  auto number_of_stream_results = INT_MIN;
  for (int i = 0; i < number_of_users; i++) {
    const auto user_string_response = EXPECT_SUCCESS(session, client::build_user_string(stub(), "", i));
    const auto ofdm_mod_acc_fetch_mcs_index_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_mcs_index(stub(), session, user_string_response.selector_string_out(), 10.0));
    mcs_index_vec[i] = ofdm_mod_acc_fetch_mcs_index_response.mcs_index();
    const auto ofdm_mod_acc_fetch_number_of_space_time_streams_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_number_of_space_time_streams(stub(), session, user_string_response.selector_string_out(), 10.0));
    number_of_space_time_streams_vec[i] = ofdm_mod_acc_fetch_number_of_space_time_streams_response.number_of_space_time_streams();
    space_time_stream_offset_vec[i] = GET_ATTR_I32(session, user_string_response.selector_string_out(), NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_RESULTS_SPACE_TIME_STREAM_OFFSET);
    if ((space_time_stream_offset_vec[i] + number_of_space_time_streams_vec[i]) > number_of_stream_results) {
      number_of_stream_results = space_time_stream_offset_vec[i] + number_of_space_time_streams_vec[i];
    }
  }
  std::vector<OFDMModAccFetchFrequencyErrorMeanResponse> ofdm_mod_acc_fetch_frequency_error_mean_response_vec;
  std::vector<OFDMModAccFetchSymbolClockErrorMeanResponse> ofdm_mod_acc_fetch_symbol_clock_error_mean_response_vec;
  std::vector<std::vector<OFDMModAccFetchStreamRMSEVMResponse>> ofdm_mod_acc_fetch_stream_rmsevm_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<OFDMModAccFetchStreamRMSEVMPerSubcarrierMeanTraceResponse>> ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<OFDMModAccFetchPilotConstellationTraceResponse>> ofdm_mod_acc_fetch_pilot_constellation_trace_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<OFDMModAccFetchDataConstellationTraceResponse>> ofdm_mod_acc_fetch_data_constellation_trace_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<OFDMModAccFetchCrossPowerResponse>> ofdm_mod_acc_fetch_cross_power_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<OFDMModAccFetchIQImpairmentsResponse>> ofdm_mod_acc_fetch_iq_impairments_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; i++) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    ofdm_mod_acc_fetch_frequency_error_mean_response_vec.push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, segment_string_response.selector_string_out(), 10.0)));
    ofdm_mod_acc_fetch_symbol_clock_error_mean_response_vec.push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, segment_string_response.selector_string_out(), 10.0)));
    for (int j = 0; j < number_of_stream_results; j++) {
      const auto stream_string_response = EXPECT_SUCCESS(session, client::build_stream_string(stub(), segment_string_response.selector_string_out(), j));
      ofdm_mod_acc_fetch_stream_rmsevm_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_stream_rmsevm(stub(), session, stream_string_response.selector_string_out(), 10.0)));
      ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace(stub(), session, stream_string_response.selector_string_out(), 10.0)));
      ofdm_mod_acc_fetch_pilot_constellation_trace_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, stream_string_response.selector_string_out(), 10.0)));
      ofdm_mod_acc_fetch_data_constellation_trace_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, stream_string_response.selector_string_out(), 10.0)));
    }
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; j++) {
      const auto chain_string_response = EXPECT_SUCCESS(session, client::build_chain_string(stub(), segment_string_response.selector_string_out(), j));
      ofdm_mod_acc_fetch_cross_power_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_cross_power(stub(), session, chain_string_response.selector_string_out(), 10.0)));
      ofdm_mod_acc_fetch_iq_impairments_response_vec[i].push_back(EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_iq_impairments(stub(), session, chain_string_response.selector_string_out(), 10.0)));
    }
  }

  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_NE(0, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_EQ(2, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_lsig_parity_check_status_response.l_sig_parity_check_status());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigbcrc_status_response.sig_b_crc_status());
  EXPECT_EQ(1, number_of_users);
  for (int i = 0; i < number_of_users; i++) {
    EXPECT_LT(0, mcs_index_vec[i]);
    EXPECT_EQ(0, space_time_stream_offset_vec[i]);
  }
  EXPECT_LE(number_of_users, number_of_stream_results);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response_vec[0].frequency_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response_vec[0].symbol_clock_error_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response_vec[0][0].stream_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response_vec[0][0].stream_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response_vec[0][0].stream_pilot_rms_evm_mean());
  EXPECT_EQ(-28.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[0][0].x0());
  EXPECT_EQ(1.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[0][0].dx());
  EXPECT_NE(0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[0][0].stream_rms_evm_per_subcarrier_mean_size());
  EXPECT_NE(0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[0][0].stream_rms_evm_per_subcarrier_mean().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response_vec[0][0].stream_rms_evm_per_subcarrier_mean(0));
  EXPECT_NE(0, ofdm_mod_acc_fetch_pilot_constellation_trace_response_vec[0][0].pilot_constellation().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response_vec[0][0].pilot_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response_vec[0][0].pilot_constellation(0).imaginary());
  EXPECT_NE(0, ofdm_mod_acc_fetch_data_constellation_trace_response_vec[0][0].data_constellation().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response_vec[0][0].data_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response_vec[0][0].data_constellation(0).imaginary());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_cross_power_response_vec[0][0].cross_power_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response_vec[0][0].relative_iq_origin_offset_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_iq_impairments_response_vec[0][0].iq_gain_imbalance_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response_vec[0][0].iq_quadrature_error_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response_vec[0][0].absolute_iq_origin_offset_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response_vec[0][0].iq_timing_skew_mean());
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccSpeedOptimizedFromExample_FetchData_DataLooksReasonable)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resource_name);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED, NIRFMXWLAN_INT32_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_PPDU_TYPE, NIRFMXWLAN_INT32_OFDM_PPDU_TYPE_NON_HT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_HEADER_DECODING_ENABLED, NIRFMXWLAN_INT32_OFDM_HEADER_DECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_MCS_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_GUARD_INTERVAL_TYPE, NIRFMXWLAN_INT32_OFDM_GUARD_INTERVAL_TYPE_1_4));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_LTF_SIZE, NIRFMXWLAN_INT32_OFDM_LTF_SIZE_4X));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_BURST_START_DETECTION_ENABLED, NIRFMXWLAN_INT32_OFDMMODACC_BURST_START_DETECTION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED, NIRFMXWLAN_INT32_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0));

  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_EQ(16, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccTriggerBasedPPDUFromExample_FetchData_DataLooksReasonable)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resource_name);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AX));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_MCS_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_RU_SIZE, 26));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_RU_OFFSET_MRU_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_GUARD_INTERVAL_TYPE, NIRFMXWLAN_INT32_OFDM_GUARD_INTERVAL_TYPE_1_4));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_LTF_SIZE, NIRFMXWLAN_INT32_OFDM_LTF_SIZE_4X));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_PE_DISAMBIGUITY, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_PPDU_TYPE, NIRFMXWLAN_INT32_OFDM_PPDU_TYPE_SU));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE, NIRFMXWLAN_INT32_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT1));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_unused_tone_error_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_unused_tone_error(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_frequency_error_ccdf10_percent_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_frequency_error_ccdf10_percent(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_ppdu_type_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_pilot_constellation_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_data_constellation_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, "", 10.0));
  const auto ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response = EXPECT_SUCCESS(session, client::ofdm_mod_acc_fetch_unused_tone_error_mean_trace(stub(), session, "", 10.0));

  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_unused_tone_error_response.unused_tone_error_margin());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_unused_tone_error_response.unused_tone_error_margin_ru_index());
  EXPECT_EQ(1, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru_size());
  EXPECT_EQ(1, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru(0));
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_EQ(3, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.x0());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.dx());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error().size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_mask_size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_mask().size());
}

TEST_F(NiRFmxWLANDriverApiTests, SemMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  std::vector<std::string> resource_names = {"RFSA1", "RFSA2"};
  std::string comma_separated_resource_name = get_comma_seperated_string(resource_names);
  std::vector<float64> center_frequency_array{5.180000e9, 5.260000e9};
  std::vector<std::string> selected_ports_string{"", ""};
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, comma_separated_resource_name);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), center_frequency_array[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    auto port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    selected_ports_string[i] = port_string_response.selector_string_out();
    port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, port_string_response.selector_string_out(), 0.0));
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, port_string_response.selector_string_out(), 0.0));
  }
  std::string selected_ports_string_comma_separated = get_comma_seperated_string(selected_ports_string);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selected_ports_string_comma_separated));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_STANDARD));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_span(stub(), session, "", SEM_SPAN_AUTO_TRUE, 66.0e6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<std::vector<SEMFetchCarrierMeasurementResponse>> sem_fetch_carrier_measurement_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<SEMFetchLowerOffsetMarginArrayResponse>> sem_fetch_lower_offset_margin_array_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<SEMFetchUpperOffsetMarginArrayResponse>> sem_fetch_upper_offset_margin_array_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<SEMFetchSpectrumResponse>> sem_fetch_spectrum_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  const auto sem_fetch_measurement_status_response = EXPECT_SUCCESS(session, client::sem_fetch_measurement_status(stub(), session, "", 10.0));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; ++j) {
      const auto chain_string_response = EXPECT_SUCCESS(session, client::build_chain_string(stub(), segment_string_response.selector_string_out(), j));
      sem_fetch_carrier_measurement_response_vec[i].push_back(
          EXPECT_SUCCESS(session, client::sem_fetch_carrier_measurement(stub(), session, chain_string_response.selector_string_out(), 10.0)));
      sem_fetch_lower_offset_margin_array_response_vec[i].push_back(
          EXPECT_SUCCESS(session, client::sem_fetch_lower_offset_margin_array(stub(), session, chain_string_response.selector_string_out(), 10.0)));
      sem_fetch_upper_offset_margin_array_response_vec[i].push_back(
          EXPECT_SUCCESS(session, client::sem_fetch_upper_offset_margin_array(stub(), session, chain_string_response.selector_string_out(), 10.0)));
      sem_fetch_spectrum_response_vec[i].push_back(
          EXPECT_SUCCESS(session, client::sem_fetch_spectrum(stub(), session, chain_string_response.selector_string_out(), 10.0)));
    }
  }

  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response_vec[0][0].absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response_vec[0][0].relative_power());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].measurement_status_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].measurement_status().size());
  EXPECT_EQ(1, sem_fetch_lower_offset_margin_array_response_vec[0][0].measurement_status(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_frequency_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_frequency(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_absolute_power_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_absolute_power(0));
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_relative_power_size());
  EXPECT_EQ(4, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_lower_offset_margin_array_response_vec[0][0].margin_relative_power(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].measurement_status_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].measurement_status().size());
  EXPECT_EQ(1, sem_fetch_upper_offset_margin_array_response_vec[0][0].measurement_status(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_frequency_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_frequency().size());
  EXPECT_LT(0.0, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_frequency(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_absolute_power_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_absolute_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_absolute_power(0));
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_relative_power_size());
  EXPECT_EQ(4, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_relative_power().size());
  EXPECT_GT(0.0, sem_fetch_upper_offset_margin_array_response_vec[0][0].margin_relative_power(0));
  EXPECT_LT(0.0, sem_fetch_spectrum_response_vec[0][0].x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response_vec[0][0].dx());
  EXPECT_EQ(2454, sem_fetch_spectrum_response_vec[0][0].spectrum_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response_vec[0][0].spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response_vec[0][0].spectrum(0));
  EXPECT_EQ(2454, sem_fetch_spectrum_response_vec[0][0].composite_mask_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response_vec[0][0].composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response_vec[0][0].composite_mask(0));
}

TEST_F(NiRFmxWLANDriverApiTests, TXPMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  std::vector<std::string> resource_names = {"RFSA1", "RFSA2"};
  std::string comma_separated_resource_name = get_comma_seperated_string(resource_names);
  std::vector<float64> center_frequency_array{5.180000e9, 5.260000e9};
  std::vector<std::string> port_string = {"", ""};
  std::vector<std::string> selected_ports_string = {"", ""};
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, comma_separated_resource_name);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), center_frequency_array[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    auto port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    selected_ports_string[i] = port_string_response.selector_string_out();
    port_string_response = EXPECT_SUCCESS(session, instr_client::build_port_string(instr_stub, "", "", resource_names[i], 0));
    port_string[i] = port_string_response.selector_string_out();
  }
  std::string selected_ports_string_comma_separated = get_comma_seperated_string(selected_ports_string);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selected_ports_string_comma_separated));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, port_string[i], 0.0));
  }
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<std::vector<TXPFetchMeasurementResponse>> txp_fetch_measurement_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  std::vector<std::vector<TXPFetchPowerTraceResponse>> txp_fetch_power_trace_response_vec(NUMBER_OF_FREQUENCY_SEGMENTS);
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    const auto segment_string_response = EXPECT_SUCCESS(session, client::build_segment_string(stub(), "", i));
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; ++j) {
      // Note: using EXPECT_RESPONSE_SUCCESS here instead of EXPECT_SUCCESS because get_error() is
      // returning the text for RISING_EDGE_DETECTION_FAILED_WARNING
      const auto chain_string_response = client::build_chain_string(stub(), segment_string_response.selector_string_out(), j);
      EXPECT_RESPONSE_SUCCESS(chain_string_response);
      txp_fetch_measurement_response_vec[i].push_back(
          EXPECT_WARNING(
              RISING_EDGE_DETECTION_FAILED_WARNING, RISING_EDGE_DETECTION_FAILED_WARNING_STR, session,
              client::txp_fetch_measurement(stub(), session, chain_string_response.selector_string_out(), 10.0)));
      txp_fetch_power_trace_response_vec[i].push_back(
          EXPECT_WARNING(
              RISING_EDGE_DETECTION_FAILED_WARNING, RISING_EDGE_DETECTION_FAILED_WARNING_STR, session,
              client::txp_fetch_power_trace(stub(), session, chain_string_response.selector_string_out(), 10.0)));
    }
  }

  EXPECT_LT(0.0, txp_fetch_measurement_response_vec[0][0].average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response_vec[0][0].peak_power_maximum());
  EXPECT_GT(0.0, txp_fetch_power_trace_response_vec[0][0].x0());
  EXPECT_LT(0.0, txp_fetch_power_trace_response_vec[0][0].dx());
  EXPECT_EQ(25250, txp_fetch_power_trace_response_vec[0][0].power_size());
  EXPECT_EQ(25250, txp_fetch_power_trace_response_vec[0][0].power().size());
  EXPECT_LT(0.0, txp_fetch_power_trace_response_vec[0][0].power(0));
}

TEST_F(NiRFmxWLANDriverApiTests, AnalyzeNWaveformsIQ_FetchData_DataLooksReasonable)
{
  const auto num_frequency_segments = 1;
  const auto num_receive_chains = 2;
  double centerFrequency[num_receive_chains] = {5.18e9, 5.26e9};
  auto session = init_analysis_session(stub());
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", num_frequency_segments, num_receive_chains));
  for (int i = 0; i < num_frequency_segments; i++) {
    const auto build_segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, build_segment_string_response.selector_string_out(), centerFrequency[i]));
  }
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  // READ TDMS File
  auto waveforms = load_test_multiple_waveforms_data<float, nidevice_grpc::NIComplexNumberF32>("WLAN_80211n_20MHz_1Seg_2Chain_MIMO.json", 2);
  // Concatenate waveform data, two dimension array passed as one dimension array with size array determining where one starts and one stops.
  std::vector<float64> iq_x0{0, 0};
  std::vector<float64> iq_dx{0, 0};
  std::vector<int> iq_sizes{0, 0};
  std::vector<nidevice_grpc::NIComplexNumberF32> iq;
  for (int i = 0; i < num_receive_chains; i++) {
    auto waveform = waveforms[i];
    auto data = waveform.data;
    iq_x0[i] = waveform.t0;
    iq_dx[i] = waveform.dt;
    iq_sizes[i] = static_cast<int>(data.size());
    iq.insert(iq.end(), data.begin(), data.end());
  }

  // Analyze Waveforms
  EXPECT_SUCCESS(session, client::analyze_n_waveforms_iq(stub(), session, "", "", iq_x0, iq_dx, iq, iq_sizes, true));

  // Fetch Results and check they are reasonable
  const auto fetch_composite_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  EXPECT_GT(0.0, fetch_composite_response.composite_rms_evm_mean());
  EXPECT_GT(0.0, fetch_composite_response.composite_data_rms_evm_mean());
  EXPECT_GT(0.0, fetch_composite_response.composite_pilot_rms_evm_mean());
}

// Note: there aren't any complex attributes
TEST_F(NiRFmxWLANDriverApiTests, SetAttributeComplex_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_ni_complex_double_array(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_REFERENCE_LEVEL, complex_number_array({1.2, 2.2}, {1e6, 1.01e6})));
}

// Note: there aren't any i8 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxWLANDriverApiTests, SetAttributeInt8_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_i8(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, 1));
  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_u8(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, 1));
  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_i8_array(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, {1, 0, -1, 0}));
  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_u8_array(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, {1, 0, 1, 0}));
}

// Note: there aren't any i16 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxWLANDriverApiTests, SetAttributeInt16_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_i16(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, -400));
  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_u16(stub(), session, "", NiRFmxWLANAttribute::NIRFMXWLAN_ATTRIBUTE_OFDM_DCM_ENABLED, 400));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
