#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxNR.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxnr/nirfmxnr_client.h"
#include "nirfsa/nirfsa_client.h"
#include "waveform_helpers.h"

using namespace ::testing;
using namespace nirfmxnr_grpc;
namespace client = nirfmxnr_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;
namespace pb = google::protobuf;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";
const auto NR_SYNC_FAILURE = 684300;
const auto NR_SYNC_FAILURE_STR = "Failed to synchronize to the signal";
const auto IVI_ERROR_INVALID_VALUE = -1074135024;
const auto IVI_ERROR_INVALID_VALUE_STR = "Invalid value for parameter or property";
const auto INCORRECT_TYPE_ERROR_CODE = -380251;
const auto INCORRECT_TYPE_ERROR_STR = "Incorrect data type specified";

template <typename TResponse>
void EXPECT_RESPONSE_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

class NiRFmxNRDriverApiTests : public Test {
 protected:
  NiRFmxNRDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxNR::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxNRDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxNR::Stub>& stub() const
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
  std::unique_ptr<NiRFmxNR::Stub> stub_;
};

#define CHECK_ERROR(session)                                          \
  if (1) {                                                            \
    auto response = client::get_error(stub(), session);               \
    EXPECT_EQ("", std::string(response.error_description().c_str())); \
  }

#define EXPECT_SUCCESS(session, response) \
  if (1) {                                \
    EXPECT_EQ(0, (response).status());    \
    CHECK_ERROR(session);                 \
  }

#define EXPECT_ERROR(expected_error, message_substring, session, response_) \
  if (1) {                                                                  \
    auto response = (response_);                                            \
    EXPECT_EQ(expected_error, response.status());                           \
    const auto error = client::get_error(stub(), session);                  \
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring));   \
  }

#define GET_ATTR_(get_attr_fn, session_, selector_string_, attribute_id_)                \
  ([this](auto& session, auto& selector_string, auto attribute_id) {                     \
    auto response = client::get_attr_fn(stub(), session, selector_string, attribute_id); \
    EXPECT_SUCCESS(session, response);                                                   \
    return response.attr_val();                                                          \
  })((session_), (selector_string_), (attribute_id_))

#define GET_ATTR_I32(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_i32, session_, selector_string_, attribute_id_)

#define GET_ATTR_F64(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_f64, session_, selector_string_, attribute_id_)

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

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

std::vector<nidevice_grpc::NIComplexNumber> complex_number_array(
    std::vector<double> reals,
    std::vector<double> imaginaries)
{
  return complex_array<double, nidevice_grpc::NIComplexNumber>(reals, imaginaries);
}

TEST_F(NiRFmxNRDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxNRDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = init_rfsa(rfsa_stub, "Sim");
  ni::tests::system::EXPECT_RESPONSE_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxNRDriverApiTests, AcpNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SUBBLOCKS = 2;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  float64 centerFrequency[NUMBER_OF_SUBBLOCKS] = {3.5e9, 200.0e6};
  int32 subblockFrequencyDefinition[NUMBER_OF_SUBBLOCKS] = {NIRFMXNR_INT32_SUBBLOCK_FREQUENCY_DEFINITION_ABSOLUTE, NIRFMXNR_INT32_SUBBLOCK_FREQUENCY_DEFINITION_RELATIVE};
  float64 componentCarrierFrequency[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = {{-49.98e6, 50.01e6}, {-49.98e6, 50.01e6}};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_SUBBLOCKS, NUMBER_OF_SUBBLOCKS));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CENTER_FREQUENCY, centerFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_SUBBLOCK_FREQUENCY_DEFINITION, subblockFrequencyDefinition[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), -1);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++) {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, carrier_string_response);
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i][j]));
    }
  }
  auto auto_level_response = client::auto_level(stub(), session, "", 10.0e-3);
  EXPECT_ERROR(IVI_ERROR_INVALID_VALUE, IVI_ERROR_INVALID_VALUE_STR, session, auto_level_response);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 0.001));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  ACPFetchSubblockMeasurementResponse fetch_subblock_responses[NUMBER_OF_SUBBLOCKS];
  ACPFetchOffsetMeasurementResponse fetch_measurement_responses[NUMBER_OF_SUBBLOCKS];
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++) {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    fetch_subblock_responses[i] = client::acp_fetch_subblock_measurement(stub(), session, subblock_string_response.selector_string_out(), 10.0);
    EXPECT_SUCCESS(session, fetch_subblock_responses[i]);
    fetch_measurement_responses[i] = client::acp_fetch_offset_measurement(stub(), session, subblock_string_response.selector_string_out(), 10.0);
    EXPECT_SUCCESS(session, fetch_measurement_responses[i]);
  }

  EXPECT_EQ(0.0, auto_level_response.reference_level());
  EXPECT_LT(0.0, fetch_subblock_responses[0].subblock_power());
  EXPECT_LT(0.0, fetch_subblock_responses[0].integration_bandwidth());
  EXPECT_LT(0.0, fetch_subblock_responses[0].frequency());
  EXPECT_LT(0.0, fetch_subblock_responses[1].subblock_power());
  EXPECT_LT(0.0, fetch_subblock_responses[1].integration_bandwidth());
  EXPECT_LT(0.0, fetch_subblock_responses[1].frequency());
  EXPECT_GT(0.0, fetch_measurement_responses[0].lower_relative_power());
  EXPECT_GT(0.0, fetch_measurement_responses[0].upper_relative_power());
  EXPECT_GT(0.0, fetch_measurement_responses[0].lower_absolute_power());
  EXPECT_GT(0.0, fetch_measurement_responses[0].upper_absolute_power());
  EXPECT_GT(0.0, fetch_measurement_responses[1].lower_relative_power());
  EXPECT_GT(0.0, fetch_measurement_responses[1].upper_relative_power());
  EXPECT_GT(0.0, fetch_measurement_responses[1].lower_absolute_power());
  EXPECT_GT(0.0, fetch_measurement_responses[1].upper_absolute_power());
}

TEST_F(NiRFmxNRDriverApiTests, ACPSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 3.5e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  auto auto_level_response = client::auto_level(stub(), session, "", 10.0e-3);
  EXPECT_SUCCESS(session, auto_level_response);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  int32 arraySize = acp_fetch_offset_measurement_array_response.lower_relative_power_size();
  const auto acp_fetch_component_carrier_measurement_response = client::acp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, acp_fetch_component_carrier_measurement_response);
  std::vector<ACPFetchRelativePowersTraceResponse> acp_fetch_relative_powers_trace_responses;
  for (int i = 0; i < arraySize; i++) {
    acp_fetch_relative_powers_trace_responses.push_back(client::acp_fetch_relative_powers_trace(stub(), session, "", 10.0, i));
    EXPECT_SUCCESS(session, acp_fetch_relative_powers_trace_responses.back());
  }
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);

  EXPECT_LT(0.0, auto_level_response.reference_level());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_LT(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_LT(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_LT(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(3, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_LT(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_GT(0.0, acp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_component_carrier_measurement_response.relative_power());
  for (int i = 0; i < arraySize; i++) {
    EXPECT_LT(0.0, acp_fetch_relative_powers_trace_responses[i].x0());
    EXPECT_LT(0.0, acp_fetch_relative_powers_trace_responses[i].dx());
    EXPECT_EQ(2, acp_fetch_relative_powers_trace_responses[i].relative_powers_trace_size());
    EXPECT_EQ(2, acp_fetch_relative_powers_trace_responses[i].relative_powers_trace().size());
    EXPECT_LE(0.0, acp_fetch_relative_powers_trace_responses[i].relative_powers_trace(0));
  }
  EXPECT_LT(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(59096, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(59096, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxNRDriverApiTests, ChpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_component_carrier_measurement_response = client::chp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, chp_fetch_component_carrier_measurement_response);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);

  EXPECT_LT(0.0, chp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(22933, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(22933, chp_fetch_spectrum_response.spectrum().size());
  int midpoint_x = 22933 / 2;
  EXPECT_LT(chp_fetch_spectrum_response.spectrum(0), chp_fetch_spectrum_response.spectrum(midpoint_x));
  EXPECT_LT(chp_fetch_spectrum_response.spectrum(22932), chp_fetch_spectrum_response.spectrum(midpoint_x));
}

TEST_F(NiRFmxNRDriverApiTests, DLModAccContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierFrequency{-49.98e6, 50.01e6};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_FDD));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<float64> compositeRMSEVMMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> compositePeakEVMMaximum(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<int> compositePeakEVMSlotIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<int> compositePeakEVMSymbolIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<int> compositePeakEVMSubcarrierIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<float64> pdschRMSEVMMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierFrequencyErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQOriginOffsetMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQGainImbalanceMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierQuadratureErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  ModAccFetchRMSEVMPerSubcarrierMeanTraceResponse mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[2];
  ModAccFetchRMSEVMPerSymbolMeanTraceResponse mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[2];
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    auto modacc_results_composite_rms_evm_mean_response = client::get_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
    if (i == 0) {
      EXPECT_ERROR(NR_SYNC_FAILURE, NR_SYNC_FAILURE_STR, session, modacc_results_composite_rms_evm_mean_response);
    }
    else {
      EXPECT_SUCCESS(session, modacc_results_composite_rms_evm_mean_response);
    }
    compositeRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
    compositePeakEVMMaximum[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
    compositePeakEVMSlotIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
    compositePeakEVMSymbolIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
    compositePeakEVMSubcarrierIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
    componentCarrierFrequencyErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
    componentCarrierIQOriginOffsetMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
    componentCarrierIQGainImbalanceMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
    componentCarrierQuadratureErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
    pdschRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN);
    mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[i] = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    EXPECT_ERROR(NR_SYNC_FAILURE, NR_SYNC_FAILURE_STR, session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[i]);
    mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[i] = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    EXPECT_ERROR(NR_SYNC_FAILURE, NR_SYNC_FAILURE_STR, session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[i]);
  }

  EXPECT_TRUE(isnan(compositeRMSEVMMean[0]));
  EXPECT_TRUE(isnan(compositeRMSEVMMean[1]));
  EXPECT_TRUE(isnan(compositePeakEVMMaximum[0]));
  EXPECT_TRUE(isnan(compositePeakEVMMaximum[1]));
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1]);
  EXPECT_TRUE(isnan(componentCarrierFrequencyErrorMean[0]));
  EXPECT_TRUE(isnan(componentCarrierFrequencyErrorMean[1]));
  EXPECT_TRUE(isnan(componentCarrierIQOriginOffsetMean[0]));
  EXPECT_TRUE(isnan(componentCarrierIQOriginOffsetMean[1]));
  EXPECT_TRUE(isnan(componentCarrierIQGainImbalanceMean[0]));
  EXPECT_TRUE(isnan(componentCarrierIQGainImbalanceMean[1]));
  EXPECT_TRUE(isnan(componentCarrierQuadratureErrorMean[0]));
  EXPECT_TRUE(isnan(componentCarrierQuadratureErrorMean[1]));
  EXPECT_TRUE(isnan(pdschRMSEVMMean[0]));
  EXPECT_TRUE(isnan(pdschRMSEVMMean[1]));
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[0].x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[0].dx());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[0].rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[0].rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[1].x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[1].dx());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[1].rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response[1].rms_evm_per_subcarrier_mean().size());
  // EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[0].x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[0].dx());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[0].rms_evm_per_symbol_mean_size());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[0].rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[1].x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[1].dx());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[1].rms_evm_per_symbol_mean_size());
  EXPECT_EQ(0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response[1].rms_evm_per_symbol_mean().size());
  // EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, ObwSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_OBW_SPAN_AUTO, NIRFMXNR_INT32_OBW_SPAN_AUTO_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "subblock0", NIRFMXNR_ATTRIBUTE_OBW_SPAN, 200e6));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);

  EXPECT_LT(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(40115, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(40115, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, obw_fetch_spectrum_response.spectrum(0));
  EXPECT_LT(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_LT(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_LT(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_LT(0.0, obw_fetch_measurement_response.stop_frequency());
}

TEST_F(NiRFmxNRDriverApiTests, SemContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const auto NUMBER_OF_OFFSETS = 4;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierFrequency{-49.98e6, 50.01e6};
  std::vector<float64> componentCarrierRatedOutputPower{0.0, 0.0};
  std::vector<float64> offsetStartFrequency{15.0e3, 1.5e6, 5.5e6, 40.3e6};
  std::vector<float64> offsetStopFrequency{985.0e3, 4.5e6, 39.3e6, 44.3e6};
  std::vector<int> offsetSideband{RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH};
  std::vector<float64> offsetRBW{10.0e3, 250.0e3, 1.0e6, 1.0e6};
  std::vector<int> offsetRBWFilterType{RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN};
  std::vector<int> bandwidthIntegral{3, 4, 1, 1};
  std::vector<int> limitFailMask{RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE};
  std::vector<float64> absoluteLimitStart{-22.5, -8.5, -11.5, -23.5};
  std::vector<float64> absoluteLimitStop{-22.5, -8.5, -11.5, -23.5};
  std::vector<float64> relativeLimitStart{-53.0, -53.0, -53.0, -53.0};
  std::vector<float64> relativeLimitStop{-60.0, -60.0, -60.0, -60.0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, "", offsetStartFrequency, offsetStopFrequency, offsetSideband));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_rbw_filter_array(stub(), session, "", offsetRBW, offsetRBWFilterType));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_bandwidth_integral_array(stub(), session, "", bandwidthIntegral));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_limit_fail_mask_array(stub(), session, "", limitFailMask));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_absolute_limit_array(stub(), session, "", absoluteLimitStart, absoluteLimitStop));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_relative_limit_array(stub(), session, "", relativeLimitStart, relativeLimitStop));
  EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  const auto sem_fetch_total_aggregated_power_response = client::sem_fetch_total_aggregated_power(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_total_aggregated_power_response);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);

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
  EXPECT_EQ(47906, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(47906, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(47906, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(47906, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxNRDriverApiTests, SemSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  const auto sem_fetch_component_carrier_measurement_response = client::sem_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_component_carrier_measurement_response);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);

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
  EXPECT_GT(0.0, sem_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_GT(0.0, sem_fetch_component_carrier_measurement_response.peak_absolute_power());
  EXPECT_LT(0.0, sem_fetch_component_carrier_measurement_response.peak_frequency());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_LT(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(25685, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(25685, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(25685, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(25685, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_GT(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxNRDriverApiTests, TxpContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierFrequency{-49.98e6, 50.01e6};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 20e6));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED, NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);

  EXPECT_LT(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_LT(0.0, txp_fetch_measurement_response.peak_power_maximum());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_LT(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(47925, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(47925, txp_fetch_power_trace_response.power().size());
  EXPECT_NE(0.0, txp_fetch_power_trace_response.power(0));
}

// Note: there aren't any complex attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxNRDriverApiTests, SetAttributeComplex_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      INCORRECT_TYPE_ERROR_CODE, INCORRECT_TYPE_ERROR_STR, session,
      client::set_attribute_ni_complex_double_array(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_OFFSET_START_FREQUENCY, complex_number_array({1.2, 2.2}, {1e6, 1.01e6})));
}

TEST_F(NiRFmxNRDriverApiTests, ULModAccSpeedOptimizedFromExample_FetchData_DataLooksReasonable)
{
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  std::vector<int> pusch_resource_block_offset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> pusch_number_of_resource_blocks{-1};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE2));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 50e6));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_CELL_ID, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 120e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED, NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED, NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_SYMBOL_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_MODULATION_TYPE, NIRFMXNR_INT32_PUSCH_MODULATION_TYPE_QPSK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, NUMBER_OF_RESOURCE_BLOCK_CLUSTERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, carrier_string_response);
  auto bandwidth_part_string_response = client::build_bandwidth_part_string(stub(), carrier_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, bandwidth_part_string_response);
  auto user_string_response = client::build_user_string(stub(), bandwidth_part_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, user_string_response);
  auto pusch_string_response = client::build_pusch_string(stub(), user_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, pusch_string_response);
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++) {
    auto pusch_cluster_string_response = client::build_pusch_cluster_string(stub(), pusch_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, pusch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_RESOURCE_BLOCK_OFFSET, pusch_resource_block_offset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCKS, pusch_number_of_resource_blocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_FRAME));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED, NIRFMXNR_INT32_MODACC_MAGNITUDE_AND_PHASE_ERROR_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED, NIRFMXNR_INT32_MODACC_IQ_MISMATCH_ESTIMATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_FREQUENCY_ERROR_ESTIMATION, NIRFMXNR_INT32_MODACC_FREQUENCY_ERROR_ESTIMATION_DISABLED));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED, NIRFMXNR_INT32_MODACC_SYMBOL_CLOCK_ERROR_ESTIMATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_PHASE_TRACKING_ENABLED, NIRFMXNR_INT32_MODACC_PHASE_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_TIMING_TRACKING_ENABLED, NIRFMXNR_INT32_MODACC_TIMING_TRACKING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED, NIRFMXNR_INT32_MODACC_IQ_ORIGIN_OFFSET_ESTIMATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE, NIRFMXNR_INT32_MODACC_EVM_REFERENCE_DATA_SYMBOLS_MODE_REFERENCE_WAVEFORM));

  // READ TDMS File
  auto waveform = load_test_waveform_data<float, nidevice_grpc::NIComplexNumberF32>("NR_FR2_UL_SISO_CC-1_BW-50MHz_SCS-120kHz.json");
  EXPECT_SUCCESS(session, client::mod_acc_cfg_reference_waveform(stub(), session, "", waveform.t0, waveform.dt, waveform.data));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  float64 composite_rms_evm_mean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
  float64 composite_peak_evm_maximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
  float64 pusch_data_rms_evm_mean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PUSCH_DATA_RMS_EVM_MEAN);
  float64 pusch_data_peak_evm_maximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PUSCH_DATA_PEAK_EVM_MAXIMUM);
  float64 pusch_dmrs_rms_evm_mean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PUSCH_DMRS_RMS_EVM_MEAN);
  float64 pusch_dmrs_peak_evm_maximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PUSCH_DMRS_PEAK_EVM_MAXIMUM);

  EXPECT_LT(0.0, composite_rms_evm_mean);
  EXPECT_LT(0.0, composite_peak_evm_maximum);
  EXPECT_LT(0.0, pusch_data_rms_evm_mean);
  EXPECT_LT(0.0, pusch_data_peak_evm_maximum);
  EXPECT_LT(0.0, pusch_dmrs_rms_evm_mean);
  EXPECT_LT(0.0, pusch_dmrs_peak_evm_maximum);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
