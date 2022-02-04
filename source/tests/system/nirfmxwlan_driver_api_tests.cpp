#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxWLAN.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxwlan/nirfmxwlan_client.h"
#include "nirfsa/nirfsa_client.h"

#ifdef WIN32
  #define strncpy strncpy_s
#endif

using namespace ::testing;
using namespace nirfmxwlan_grpc;
namespace client = nirfmxwlan_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";
const int RISING_EDGE_DETECTION_FAILED_WARNING = 379206;
const int EVM_CHIPS_MUST_BE_300_WARNING = 685353;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

template <typename TResponse>
void EXPECT_WARNING(const TResponse& response, const int expected_warning_id)
{
  EXPECT_EQ(expected_warning_id, response.status());
}

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

  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }

  template <typename TResponse>
  void EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
    check_error(session);
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  template <typename TAttr>
  int32 get_attr_i32(const nidevice_grpc::Session& session, const std::string& selector_string, TAttr attribute_id)
  {
    auto response = client::get_attribute_i32(stub(), session, selector_string, attribute_id);
    EXPECT_SUCCESS(session, response);
    return response.attr_val();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxWLAN::Stub> stub_;
};

void GetCommaSeparatedStringFromArray(char* array_of_names, int num_of_names, int name_length, char* comma_seperated_name)
{
  int name_index = 0;
  int comma_index = 0;
  while (name_index < num_of_names) {
    int char_index;
    for (char_index = 0; char_index < name_length; ++char_index) {
      if (*(array_of_names + name_index * name_length + char_index) == '\0') break;
      comma_seperated_name[comma_index++] = *(array_of_names + name_index * name_length + char_index);
    }
    if (++name_index != num_of_names) {
      comma_seperated_name[comma_index++] = ',';
    }
  }
  comma_seperated_name[comma_index] = '\0';
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
  EXPECT_SUCCESS(response);
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
  EXPECT_SUCCESS(response);
  return session;
}

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

TEST_F(NiRFmxWLANDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxWLANDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = init_rfsa(rfsa_stub, "Sim");
  ni::tests::system::EXPECT_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccTXPCompositeFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP | MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);
  EXPECT_WARNING(txp_fetch_measurement_response, RISING_EDGE_DETECTION_FAILED_WARNING);

  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
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
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_STANDARD));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_span(stub(), session, "", SEM_SPAN_AUTO_TRUE, 66.0e6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  const auto sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
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
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
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
  std::vector<float64> offsetStartFrequency{9e06, 11e06, 20e06};
  std::vector<float64> offsetStopFrequency{11e06, 20e06, 40e06};
  std::vector<int> offsetSideband{RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH};
  std::vector<float64> relativeLimitStart{0.0, -20.0, -28.0};
  std::vector<float64> relativeLimitStop{-20.0, -28.0, -40.0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_CUSTOM));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, "", offsetStartFrequency, offsetStopFrequency, offsetSideband));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_relative_limit_array(stub(), session, "", relativeLimitStart, relativeLimitStop));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  const auto sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
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
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
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
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
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
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_WARNING(txp_fetch_power_trace_response, RISING_EDGE_DETECTION_FAILED_WARNING);
  EXPECT_GT(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power().size());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_WARNING(txp_fetch_measurement_response, RISING_EDGE_DETECTION_FAILED_WARNING);
  EXPECT_LT(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

TEST_F(NiRFmxWLANDriverApiTests, DSSSModAccFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_B));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_DSSSMODACC, true));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_measurement_length(stub(), session, "", 0, 1000));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_DSSSMODACC_PULSE_SHAPING_FILTER_TYPE, NIRFMXWLAN_INT32_DSSS_MODACC_PULSE_SHAPING_FILTER_TYPE_RECTANGULAR));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_DSSSMODACC_PULSE_SHAPING_FILTER_PARAMETER, 0.50));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_evm_unit(stub(), session, "", DSSS_MODACC_EVM_UNIT_PERCENTAGE));
  EXPECT_SUCCESS(session, client::dsss_mod_acc_cfg_averaging(stub(), session, "", DSSS_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto dsss_mod_acc_fetch_evm_response = client::dsss_mod_acc_fetch_evm(stub(), session, "", 10.0);
  const auto dsss_mod_acc_fetch_ppdu_information_response = client::dsss_mod_acc_fetch_ppdu_information(stub(), session, "", 10.0);
  const auto dsss_mod_acc_fetch_iq_impairments_response = client::dsss_mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto dsss_mod_acc_fetch_evm_per_chip_mean_trace_response = client::dsss_mod_acc_fetch_evm_per_chip_mean_trace(stub(), session, "", 10.0);
  const auto dsss_mod_acc_fetch_constellation_trace_response = client::dsss_mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);

  EXPECT_WARNING(dsss_mod_acc_fetch_evm_response, EVM_CHIPS_MUST_BE_300_WARNING);
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.rms_evm_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm80211_2016_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm80211_2007_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.peak_evm80211_1999_maximum());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_response.frequency_error_mean());
  EXPECT_NE(0.0, dsss_mod_acc_fetch_evm_response.chip_clock_error_mean());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_response.number_of_chips_used());
  EXPECT_WARNING(dsss_mod_acc_fetch_ppdu_information_response, EVM_CHIPS_MUST_BE_300_WARNING);
  EXPECT_EQ(3, dsss_mod_acc_fetch_ppdu_information_response.data_modulation_format());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.payload_length());
  EXPECT_EQ(1, dsss_mod_acc_fetch_ppdu_information_response.preamble_type());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.locked_clocks_bit());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.header_crc_status());
  EXPECT_EQ(0, dsss_mod_acc_fetch_ppdu_information_response.psdu_crc_status());
  EXPECT_WARNING(dsss_mod_acc_fetch_iq_impairments_response, EVM_CHIPS_MUST_BE_300_WARNING);
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_origin_offset_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_WARNING(dsss_mod_acc_fetch_evm_per_chip_mean_trace_response, EVM_CHIPS_MUST_BE_300_WARNING);
  EXPECT_EQ(0.0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.x0());
  EXPECT_EQ(1, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.dx());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.evm_per_chip_mean_size());
  EXPECT_EQ(0, dsss_mod_acc_fetch_evm_per_chip_mean_trace_response.evm_per_chip_mean().size());
  EXPECT_WARNING(dsss_mod_acc_fetch_constellation_trace_response, EVM_CHIPS_MUST_BE_300_WARNING);
  EXPECT_EQ(0, dsss_mod_acc_fetch_constellation_trace_response.actual_array_size());
}

// TODO AB#1830352:
// Disabled because it's getting the error during initiate of
// "-1074135024: \nIVI: (Hex 0xBFFA0010) Invalid value for parameter or property.\n\nProperty: IQ Rate\nRequested Value:  80.0e6\nValue Must Be Less Than or Equal to:  75.0e6\nDevice: Simulated_NI_PXIe_5601_Device_31\n\nStatus Code: -200077"
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_DSSSPowerRampFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_B));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_POWERRAMP, true));
  EXPECT_SUCCESS(session, client::power_ramp_cfg_acquisition_length(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::power_ramp_cfg_averaging(stub(), session, "", POWER_RAMP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 x0 = 0;
  float64 dx = 0;
  const auto power_ramp_fetch_measurement_response = client::power_ramp_fetch_measurement(stub(), session, "", 10.0);
  const auto power_ramp_fetch_rise_trace_response = client::power_ramp_fetch_rise_trace(stub(), session, "", 10.0);
  x0 = 0;
  dx = 0;
  const auto power_ramp_fetch_fall_trace_response = client::power_ramp_fetch_fall_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, power_ramp_fetch_measurement_response);
  EXPECT_EQ(0.0, power_ramp_fetch_measurement_response.rise_time_mean());
  EXPECT_EQ(0.0, power_ramp_fetch_measurement_response.fall_time_mean());
  EXPECT_SUCCESS(session, power_ramp_fetch_rise_trace_response);
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.x0());
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.dx());
  EXPECT_EQ(0, power_ramp_fetch_rise_trace_response.raw_waveform_size());
  EXPECT_EQ(0, power_ramp_fetch_rise_trace_response.raw_waveform().size());
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.raw_waveform(0));
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.processed_waveform_size());
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.processed_waveform().size());
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.processed_waveform(0));
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.threshold_size());
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.threshold().size());
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.threshold(0));
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.power_reference_size());
  EXPECT_EQ(999, power_ramp_fetch_rise_trace_response.power_reference().size());
  EXPECT_EQ(0.0, power_ramp_fetch_rise_trace_response.power_reference(0));
  EXPECT_SUCCESS(session, power_ramp_fetch_fall_trace_response);
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.x0());
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.dx());
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.raw_waveform_size());
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.raw_waveform().size());
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.raw_waveform(0));
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.processed_waveform_size());
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.processed_waveform().size());
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.processed_waveform(0));
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.threshold_size());
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.threshold().size());
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.threshold(0));
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.power_reference_size());
  EXPECT_EQ(999, power_ramp_fetch_fall_trace_response.power_reference().size());
  EXPECT_EQ(0.0, power_ramp_fetch_fall_trace_response.power_reference(0));
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDM_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDM_MODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDM_MODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDM_MODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDM_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_iq_impairments_response = client::ofdm_mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_ppdu_type_response = client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_mcs_index_response = client::ofdm_mod_acc_fetch_mcs_index(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_guard_interval_type_response = client::ofdm_mod_acc_fetch_guard_interval_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_lsig_parity_check_status_response = client::ofdm_mod_acc_fetch_lsig_parity_check_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigcrc_status_response = client::ofdm_mod_acc_fetch_sigcrc_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigbcrc_status_response = client::ofdm_mod_acc_fetch_sigbcrc_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_pilot_constellation_trace_response = client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_data_constellation_trace_response = client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response = client::ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_numberof_symbols_used_response);
  EXPECT_EQ(16, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_symbol_clock_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.relative_iq_origin_offset_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.absolute_iq_origin_offset_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_timing_skew_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_ppdu_type_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_mcs_index_response);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_guard_interval_type_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_guard_interval_type_response.guard_interval_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_lsig_parity_check_status_response);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigcrc_status_response);
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigbcrc_status_response);
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigbcrc_status_response.sigb_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_pilot_constellation_trace_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_data_constellation_trace_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(-26, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(1, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(53, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(53, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean(0));
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto MAX_SELECTOR_STRING_LENGTH = 256;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  char resourceNames[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"RFSA1", "RFSA2"};
  char commaSeparatedResourceName[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  GetCommaSeparatedStringFromArray((char*)resourceNames, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, commaSeparatedResourceName);
  char selectedPorts[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"", ""};
  std::vector<float64> centerFrequencyArray{5.180000e9, 5.260000e9};
  char portString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsStringCommaSeparated[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  std::vector<float64> referenceLevelArray{0.0, 0.0};
  std::vector<float64> externalAttenuationArray{0.0, 0.0};
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, commaSeparatedResourceName);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), centerFrequencyArray[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    // TODO AB#1830349: Fix build_port_string parameter invalid issue.
    // auto port_string_response = instr_client::build_port_string(instr_stub, "", selectedPorts[i], resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(selectedPortsString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    // port_string_response = instr_client::build_port_string(instr_stub, "", "", resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(portString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    std::string port_string = "port::" + std::string(resourceNames[i]) + "/0";
    strncpy(selectedPortsString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    strncpy(portString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, portString[i], referenceLevelArray[i]));
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, portString[i], externalAttenuationArray[i]));
  }
  GetCommaSeparatedStringFromArray((char*)selectedPortsString, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, selectedPortsStringCommaSeparated);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selectedPortsStringCommaSeparated));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDM_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDM_MODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDM_MODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDM_MODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDM_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CHANNEL_MATRIX_POWER_ENABLED, NIRFMXWLAN_INT32_OFDM_MODACC_CHANNEL_MATRIX_POWER_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32* MCSIndexArray = NULL;
  int32 MCSIndexArrayLength = 0;
  int32* numberOfSpaceTimeStreamsArray = NULL;
  int32 numberOfSpaceTimeStreamsArrayLength = 0;
  int32* spaceTimeStreamOffsetArray = NULL;
  int32 numberOfStreamResults = INT_MIN;
  int32 PPDUType = NIRFMXWLAN_INT32_OFDM_PPDU_TYPE_MU;
  int32 numberOfUsers = 0;
  OFDMModAccFetchNumberOfUsersResponse ofdm_mod_acc_fetch_number_of_users_response;
  OFDMModAccFetchMCSIndexResponse ofdm_mod_acc_fetch_mcs_index_response;
  OFDMModAccFetchNumberOfSpaceTimeStreamsResponse ofdm_mod_acc_fetch_number_of_space_time_streams_response;
  OFDMModAccFetchFrequencyErrorMeanResponse ofdm_mod_acc_fetch_frequency_error_mean_response;
  OFDMModAccFetchSymbolClockErrorMeanResponse ofdm_mod_acc_fetch_symbol_clock_error_mean_response;
  OFDMModAccFetchStreamRMSEVMResponse ofdm_mod_acc_fetch_stream_rmsevm_response;
  OFDMModAccFetchStreamRMSEVMPerSubcarrierMeanTraceResponse ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response;
  OFDMModAccFetchPilotConstellationTraceResponse ofdm_mod_acc_fetch_pilot_constellation_trace_response;
  OFDMModAccFetchDataConstellationTraceResponse ofdm_mod_acc_fetch_data_constellation_trace_response;
  OFDMModAccFetchCrossPowerResponse ofdm_mod_acc_fetch_cross_power_response;
  OFDMModAccFetchIQImpairmentsResponse ofdm_mod_acc_fetch_iq_impairments_response;
  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_ppdu_type_response = client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_guard_interval_type_response = client::ofdm_mod_acc_fetch_guard_interval_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_lsig_parity_check_status_response = client::ofdm_mod_acc_fetch_lsig_parity_check_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigcrc_status_response = client::ofdm_mod_acc_fetch_sigcrc_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigbcrc_status_response = client::ofdm_mod_acc_fetch_sigbcrc_status(stub(), session, "", 10.0);
  ofdm_mod_acc_fetch_number_of_users_response = client::ofdm_mod_acc_fetch_number_of_users(stub(), session, "", 10.0);
  MCSIndexArrayLength = numberOfUsers;
  MCSIndexArray = (int32*)malloc(MCSIndexArrayLength * sizeof(int32));
  numberOfSpaceTimeStreamsArrayLength = numberOfUsers;
  numberOfSpaceTimeStreamsArray = (int32*)malloc(numberOfSpaceTimeStreamsArrayLength * sizeof(int32));
  spaceTimeStreamOffsetArray = (int32*)malloc(numberOfUsers * sizeof(int32));
  for (int i = 0; i < numberOfUsers; i++) {
    auto user_string_response = client::build_user_string(stub(), "", i);
    EXPECT_SUCCESS(session, user_string_response);
    ofdm_mod_acc_fetch_mcs_index_response = client::ofdm_mod_acc_fetch_mcs_index(stub(), session, user_string_response.selector_string_out(), 10.0);
    ofdm_mod_acc_fetch_number_of_space_time_streams_response = client::ofdm_mod_acc_fetch_number_of_space_time_streams(stub(), session, user_string_response.selector_string_out(), 10.0);
    spaceTimeStreamOffsetArray[i] = get_attr_i32(session, user_string_response.selector_string_out(), NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_RESULTS_SPACE_TIME_STREAM_OFFSET);
    if (MCSIndexArray == NULL || numberOfSpaceTimeStreamsArray == NULL) {
      FAIL() << "Could not allocate array";
    }
    if ((spaceTimeStreamOffsetArray[i] + numberOfSpaceTimeStreamsArray[i]) > numberOfStreamResults) {
      numberOfStreamResults = spaceTimeStreamOffsetArray[i] + numberOfSpaceTimeStreamsArray[i];
    }
  }
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; i++) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    ofdm_mod_acc_fetch_frequency_error_mean_response = client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, segment_string_response.selector_string_out(), 10.0);
    ofdm_mod_acc_fetch_symbol_clock_error_mean_response = client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, segment_string_response.selector_string_out(), 10.0);
    for (int j = 0; j < numberOfStreamResults; j++) {
      auto stream_string_response = client::build_stream_string(stub(), segment_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, stream_string_response);
      ofdm_mod_acc_fetch_stream_rmsevm_response = client::ofdm_mod_acc_fetch_stream_rmsevm(stub(), session, stream_string_response.selector_string_out(), 10.0);
      ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response = client::ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace(stub(), session, stream_string_response.selector_string_out(), 10.0);
      ofdm_mod_acc_fetch_pilot_constellation_trace_response = client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, stream_string_response.selector_string_out(), 10.0);
      ofdm_mod_acc_fetch_data_constellation_trace_response = client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, stream_string_response.selector_string_out(), 10.0);
    }
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; j++) {
      auto chain_string_response = client::build_chain_string(stub(), segment_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, chain_string_response);
      ofdm_mod_acc_fetch_cross_power_response = client::ofdm_mod_acc_fetch_cross_power(stub(), session, chain_string_response.selector_string_out(), 10.0);
      ofdm_mod_acc_fetch_iq_impairments_response = client::ofdm_mod_acc_fetch_iq_impairments(stub(), session, chain_string_response.selector_string_out(), 10.0);
    }
  }

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_numberof_symbols_used_response);
  EXPECT_EQ(16, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_ppdu_type_response);
  EXPECT_EQ(2, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_guard_interval_type_response);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_lsig_parity_check_status_response);
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_lsig_parity_check_status_response.lsig_parity_check_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigcrc_status_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigbcrc_status_response);
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_sigbcrc_status_response.sigb_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_number_of_users_response);
  EXPECT_EQ(1, ofdm_mod_acc_fetch_number_of_users_response.number_of_users());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_mcs_index_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_mcs_index_response.mcs_index());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_number_of_space_time_streams_response);
  for (int i = 0; i < numberOfUsers; i++) {
    EXPECT_EQ(0, spaceTimeStreamOffsetArray[i]);
  }
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_mcs_index_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_mcs_index_response.mcs_index());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_number_of_space_time_streams_response);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_symbol_clock_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_stream_rmsevm_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response.stream_rms_evm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response.stream_data_rms_evm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_response.stream_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response.stream_rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response.stream_rms_evm_per_subcarrier_mean().size());
  // EXPECT_EQ(0.0, ofdm_mod_acc_fetch_stream_rmsevm_per_subcarrier_mean_trace_response.stream_rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_pilot_constellation_trace_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation().size());
  // EXPECT_EQ(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  // EXPECT_EQ(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_data_constellation_trace_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation().size());
  // EXPECT_EQ(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  // EXPECT_EQ(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_cross_power_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_cross_power_response.cross_power_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_iq_impairments_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.relative_iq_origin_offset_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response.absolute_iq_origin_offset_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_timing_skew_mean());
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccSpeedOptimizedFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED, NIRFMXWLAN_INT32_OFDM_AUTO_PPDU_TYPE_DETECTION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_PPDU_TYPE, NIRFMXWLAN_INT32_OFDM_PPDU_TYPE_NON_HT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_HEADER_DECODING_ENABLED, NIRFMXWLAN_INT32_OFDM_HEADER_DECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_MCS_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_GUARD_INTERVAL_TYPE, NIRFMXWLAN_INT32_OFDM_GUARD_INTERVAL_TYPE_1_4));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_LTF_SIZE, NIRFMXWLAN_INT32_OFDM_LTF_SIZE_4_X));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDM_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDM_MODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDM_MODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDM_MODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_BURST_START_DETECTION_ENABLED, NIRFMXWLAN_INT32_OFDM_MODACC_BURST_START_DETECTION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED, NIRFMXWLAN_INT32_OFDM_MODACC_IQ_IMPAIRMENTS_ESTIMATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_LT(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_numberof_symbols_used_response);
  EXPECT_EQ(16, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_symbol_clock_error_mean_response);
  EXPECT_GT(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccTriggerBasedPPDUFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AX));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_MCS_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_RU_SIZE, 26));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_RU_OFFSET_MRU_INDEX, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_GUARD_INTERVAL_TYPE, NIRFMXWLAN_INT32_OFDM_GUARD_INTERVAL_TYPE_1_4));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_LTF_SIZE, NIRFMXWLAN_INT32_OFDM_LTF_SIZE_4_X));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDM_PE_DISAMBIGUITY, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_UNUSED_TONE_ERROR_MASK_REFERENCE, NIRFMXWLAN_INT32_OFDM_MODACC_UNUSED_TONE_ERROR_MASK_REFERENCE_LIMIT1));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_unused_tone_error_response = client::ofdm_mod_acc_fetch_unused_tone_error(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response = client::ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_frequency_error_ccdf10_percent_response = client::ofdm_mod_acc_fetch_frequency_error_ccdf10_percent(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_ppdu_type_response = client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_pilot_constellation_trace_response = client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_data_constellation_trace_response = client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response = client::ofdm_mod_acc_fetch_unused_tone_error_mean_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_unused_tone_error_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_unused_tone_error_response.unused_tone_error_margin());
  EXPECT_EQ(-1, ofdm_mod_acc_fetch_unused_tone_error_response.unused_tone_error_margin_ru_index());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response);
  EXPECT_EQ(1, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru_size());
  EXPECT_EQ(1, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru().size());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_unused_tone_error_margin_per_ru_response.unused_tone_error_margin_per_ru(0));
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_mean_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_ccdf10_percent_response);
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_symbol_clock_error_mean_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_ppdu_type_response);
  EXPECT_EQ(3, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_pilot_constellation_trace_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_data_constellation_trace_response);
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  EXPECT_NE(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.x0());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.dx());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error().size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_mask_size());
  EXPECT_EQ(0, ofdm_mod_acc_fetch_unused_tone_error_mean_trace_response.unused_tone_error_mask().size());
}

// TODO AB#1830352:
// Failing on ofdm_mod_acc_auto_level call with "-685094: The configured reference level is too high, The reference level should accurately represent the peak power in the signal."
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccWithEVMBasedAutoLevelFromExample_FetchData_DataLooksReasonable)
{
  char* resourceName = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_instr_session(instr_stub, resourceName);
  EXPECT_SUCCESS(session, instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e06));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_frequency_error_estimation_method(stub(), session, "", OFDM_MODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(stub(), session, "", OFDM_MODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_phase_tracking_enabled(stub(), session, "", OFDM_MODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(stub(), session, "", OFDM_MODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_channel_estimation_type(stub(), session, "", OFDM_MODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_auto_level(stub(), session, "", 10.0));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_numberof_symbols_used_response = client::ofdm_mod_acc_fetch_numberof_symbols_used(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_frequency_error_mean_response = client::ofdm_mod_acc_fetch_frequency_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_symbol_clock_error_mean_response = client::ofdm_mod_acc_fetch_symbol_clock_error_mean(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_iq_impairments_response = client::ofdm_mod_acc_fetch_iq_impairments(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_ppdu_type_response = client::ofdm_mod_acc_fetch_ppdu_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_mcs_index_response = client::ofdm_mod_acc_fetch_mcs_index(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_guard_interval_type_response = client::ofdm_mod_acc_fetch_guard_interval_type(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_lsig_parity_check_status_response = client::ofdm_mod_acc_fetch_lsig_parity_check_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigcrc_status_response = client::ofdm_mod_acc_fetch_sigcrc_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_sigbcrc_status_response = client::ofdm_mod_acc_fetch_sigbcrc_status(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_pilot_constellation_trace_response = client::ofdm_mod_acc_fetch_pilot_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_data_constellation_trace_response = client::ofdm_mod_acc_fetch_data_constellation_trace(stub(), session, "", 10.0);
  const auto ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response = client::ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rms_evm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rms_evm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rms_evm_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_numberof_symbols_used_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_numberof_symbols_used_response.number_of_symbols_used());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_frequency_error_mean_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_frequency_error_mean_response.frequency_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_symbol_clock_error_mean_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_symbol_clock_error_mean_response.symbol_clock_error_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_iq_impairments_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_iq_impairments_response.relative_iq_origin_offset_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_gain_imbalance_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_quadrature_error_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_iq_impairments_response.absolute_iq_origin_offset_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_iq_impairments_response.iq_timing_skew_mean());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_ppdu_type_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_ppdu_type_response.ppdu_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_mcs_index_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_mcs_index_response.mcs_index());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_guard_interval_type_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_guard_interval_type_response.guard_interval_type());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_lsig_parity_check_status_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_lsig_parity_check_status_response.lsig_parity_check_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigcrc_status_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_sigcrc_status_response.sig_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_sigbcrc_status_response);
  EXPECT_EQ(0, ofdm_mod_acc_fetch_sigbcrc_status_response.sigb_crc_status());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_pilot_constellation_trace_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).real());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_pilot_constellation_trace_response.pilot_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_data_constellation_trace_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).real());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_data_constellation_trace_response.data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_chain_rmsevm_per_subcarrier_mean_trace_response.chain_rms_evm_per_subcarrier_mean(0));
}

TEST_F(NiRFmxWLANDriverApiTests, SemMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto MAX_SELECTOR_STRING_LENGTH = 256;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  char resourceNames[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"RFSA1", "RFSA2"};
  char commaSeparatedResourceName[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  GetCommaSeparatedStringFromArray((char*)resourceNames, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, commaSeparatedResourceName);
  char selectedPorts[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"", ""};
  std::vector<float64> centerFrequencyArray{5.180000e9, 5.260000e9};
  std::vector<float64> referenceLevelArray{0.0, 0.0};
  std::vector<float64> externalAttenuationArray{0.0, 0.0};
  char portString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsStringCommaSeparated[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, commaSeparatedResourceName);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), centerFrequencyArray[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    // TODO AB#1830349: Fix build_port_string parameter invalid issue.
    // auto port_string_response = instr_client::build_port_string(instr_stub, "", selectedPorts[i], resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(selectedPortsString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    // port_string_response = instr_client::build_port_string(instr_stub, "", "", resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(portString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    std::string port_string = "port::" + std::string(resourceNames[i]) + "/0";
    strncpy(selectedPortsString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    strncpy(portString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, portString[i], referenceLevelArray[i]));
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, portString[i], externalAttenuationArray[i]));
  }
  GetCommaSeparatedStringFromArray((char*)selectedPortsString, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, selectedPortsStringCommaSeparated);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selectedPortsStringCommaSeparated));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_STANDARD));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_span(stub(), session, "", SEM_SPAN_AUTO_TRUE, 66.0e6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 arraySize = 0;
  SEMFetchCarrierMeasurementResponse sem_fetch_carrier_measurement_response;
  SEMFetchLowerOffsetMarginArrayResponse sem_fetch_lower_offset_margin_array_response;
  SEMFetchUpperOffsetMarginArrayResponse sem_fetch_upper_offset_margin_array_response;
  SEMFetchSpectrumResponse sem_fetch_spectrum_response;
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; ++j) {
      auto chain_string_response = client::build_chain_string(stub(), segment_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, chain_string_response);
      sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, chain_string_response.selector_string_out(), 10.0);
      sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, chain_string_response.selector_string_out(), 10.0);
      sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, chain_string_response.selector_string_out(), 10.0);
      arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
      sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, chain_string_response.selector_string_out(), 10.0);
    }
  }

  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(1, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_LT(0.0, sem_fetch_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
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
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(2454, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(2454, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxWLANDriverApiTests, TXPMIMOFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_DEVICES = 2;
  const auto MAX_SELECTOR_STRING_LENGTH = 256;
  const auto NUMBER_OF_FREQUENCY_SEGMENTS = 1;
  const auto NUMBER_OF_RECEIVE_CHAINS = 2;
  char resourceNames[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"RFSA1", "RFSA2"};
  char commaSeparatedResourceName[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  GetCommaSeparatedStringFromArray((char*)resourceNames, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, commaSeparatedResourceName);
  char selectedPorts[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH] = {"", ""};
  std::vector<float64> centerFrequencyArray{5.180000e9, 5.260000e9};
  char portString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsString[NUMBER_OF_DEVICES][MAX_SELECTOR_STRING_LENGTH];
  char selectedPortsStringCommaSeparated[MAX_SELECTOR_STRING_LENGTH * 2 + 1];
  std::vector<float64> referenceLevelArray{0.0, 0.0};
  std::vector<float64> externalAttenuationArray{0.0, 0.0};
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  auto session = init_session(stub(), PXI_5663E, commaSeparatedResourceName);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_PXI_CLK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_number_of_frequency_segments_and_receive_chains(stub(), session, "", NUMBER_OF_FREQUENCY_SEGMENTS, NUMBER_OF_RECEIVE_CHAINS));
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, segment_string_response.selector_string_out(), centerFrequencyArray[i]));
  }
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    // TODO AB#1830349: Fix build_port_string parameter invalid issue.
    // auto port_string_response = instr_client::build_port_string(instr_stub, "", selectedPorts[i], resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(selectedPortsString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    // port_string_response = instr_client::build_port_string(instr_stub, "", "", resourceNames[i], 0);
    // EXPECT_SUCCESS(session, port_string_response);
    // strncpy(portString[i], port_string_response.selector_string_out().c_str(), MAX_SELECTOR_STRING_LENGTH);
    // portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    std::string port_string = "port::" + std::string(resourceNames[i]) + "/0";
    strncpy(selectedPortsString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    selectedPortsString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
    strncpy(portString[i], port_string.c_str(), MAX_SELECTOR_STRING_LENGTH);
    portString[i][MAX_SELECTOR_STRING_LENGTH - 1] = '\0';
  }
  GetCommaSeparatedStringFromArray((char*)selectedPortsString, NUMBER_OF_DEVICES, MAX_SELECTOR_STRING_LENGTH, selectedPortsStringCommaSeparated);
  EXPECT_SUCCESS(session, client::cfg_selected_ports_multiple(stub(), session, "", selectedPortsStringCommaSeparated));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_N));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  for (int i = 0; i < NUMBER_OF_DEVICES; ++i) {
    EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, portString[i], externalAttenuationArray[i]));
  }
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  TXPFetchMeasurementResponse txp_fetch_measurement_response;
  TXPFetchPowerTraceResponse txp_fetch_power_trace_response;
  for (int i = 0; i < NUMBER_OF_FREQUENCY_SEGMENTS; ++i) {
    auto segment_string_response = client::build_segment_string(stub(), "", i);
    EXPECT_SUCCESS(session, segment_string_response);
    for (int j = 0; j < NUMBER_OF_RECEIVE_CHAINS; ++j) {
      auto chain_string_response = client::build_chain_string(stub(), segment_string_response.selector_string_out(), j);
      txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, chain_string_response.selector_string_out(), 10.0);
      txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, chain_string_response.selector_string_out(), 10.0);
    }
  }

  EXPECT_WARNING(txp_fetch_measurement_response, RISING_EDGE_DETECTION_FAILED_WARNING);
  EXPECT_LT(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.peak_power_maximum());
  EXPECT_WARNING(txp_fetch_power_trace_response, RISING_EDGE_DETECTION_FAILED_WARNING);
  EXPECT_GT(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(25250, txp_fetch_power_trace_response.power().size());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.power(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
