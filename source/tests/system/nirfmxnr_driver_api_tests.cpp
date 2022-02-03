#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxNR.h"
#include "nirfmxnr/nirfmxnr_client.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfmxnr_grpc;
namespace client = nirfmxnr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

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

  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }

  #define CHECK_ERROR(session) if (1) \
  { \
    auto response = client::get_error(stub(), session); \
    EXPECT_EQ("", std::string(response.error_description().c_str())); \
  }

  #define EXPECT_SUCCESS(session, response) if (1) \
  { \
    EXPECT_EQ(0, (response).status()); \
    CHECK_ERROR(session); \
  }

  #define GET_ATTR_(get_attr_fn, session_, selector_string_, attribute_id_) \
  ([this](auto &session, auto &selector_string, auto attribute_id) \
  { \
    auto response = client::get_attr_fn(stub(), session, selector_string, attribute_id); \
    EXPECT_SUCCESS(session, response); \
    return response.attr_val(); \
  } \
  )((session_), (selector_string_), (attribute_id_))

  #define GET_ATTR_I32(session_, selector_string_, attribute_id_) \
    GET_ATTR_(get_attribute_i32, session_, selector_string_, attribute_id_)

  #define GET_ATTR_F64(session_, selector_string_, attribute_id_) \
    GET_ATTR_(get_attribute_f64, session_, selector_string_, attribute_id_)

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxNR::Stub> stub_;
};

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

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
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
  ni::tests::system::EXPECT_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxNRDriverApiTests, AcpContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  int32 autoLevel = RFMXNR_VAL_TRUE;
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  // TODO: Conversion process ignored auto_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 3.5e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  if (autoLevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10.0e-3));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  ACPFetchRelativePowersTraceResponse acp_fetch_relative_powers_trace_response;
  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  int32 arraySize = acp_fetch_offset_measurement_array_response.lower_relative_power_size();
  const auto acp_fetch_total_aggregated_power_response = client::acp_fetch_total_aggregated_power(stub(), session, "", 10.0);
  for (int i = 0; i < arraySize; i++)
  {
    acp_fetch_relative_powers_trace_response = client::acp_fetch_relative_powers_trace(stub(), session, "", 10.0, i);
  }
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_total_aggregated_power_response);
  EXPECT_EQ(0.0, acp_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_SUCCESS(session, acp_fetch_relative_powers_trace_response);
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.x0());
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.dx());
  EXPECT_EQ(999, acp_fetch_relative_powers_trace_response.relative_powers_trace_size());
  EXPECT_EQ(999, acp_fetch_relative_powers_trace_response.relative_powers_trace().size());
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.relative_powers_trace(0));
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.spectrum(0));
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_AcpNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxNRDriverApiTests, ACPSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  int32 autoLevel = RFMXNR_VAL_TRUE;
  // TODO: Conversion process ignored auto_level_response.reference_level
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 3.5e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_rf_attenuation(stub(), session, "", RF_ATTENUATION_AUTO_TRUE, 10.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  if (autoLevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10.0e-3));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_measurement_method(stub(), session, "", ACP_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::acp_cfg_noise_compensation_enabled(stub(), session, "", ACP_NOISE_COMPENSATION_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  ACPFetchRelativePowersTraceResponse acp_fetch_relative_powers_trace_response;
  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  int32 arraySize = acp_fetch_offset_measurement_array_response.lower_relative_power_size();
  const auto acp_fetch_component_carrier_measurement_response = client::acp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  for (int i = 0; i < arraySize; i++)
  {
    acp_fetch_relative_powers_trace_response = client::acp_fetch_relative_powers_trace(stub(), session, "", 10.0, i);
  }
  const auto acp_fetch_spectrum_response = client::acp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, acp_fetch_relative_powers_trace_response);
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.x0());
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.dx());
  EXPECT_EQ(999, acp_fetch_relative_powers_trace_response.relative_powers_trace_size());
  EXPECT_EQ(999, acp_fetch_relative_powers_trace_response.relative_powers_trace().size());
  EXPECT_EQ(0.0, acp_fetch_relative_powers_trace_response.relative_powers_trace(0));
  EXPECT_SUCCESS(session, acp_fetch_spectrum_response);
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, acp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, acp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxNRDriverApiTests, ChpContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_component_carrier_measurement_array_response = client::chp_fetch_component_carrier_measurement_array(stub(), session, "", 10.0);
  const auto chp_fetch_total_aggregated_power_response = client::chp_fetch_total_aggregated_power(stub(), session, "", 10.0);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, chp_fetch_component_carrier_measurement_array_response);
  EXPECT_EQ(999, chp_fetch_component_carrier_measurement_array_response.absolute_power_size());
  EXPECT_EQ(999, chp_fetch_component_carrier_measurement_array_response.absolute_power().size());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_array_response.absolute_power(0));
  EXPECT_EQ(999, chp_fetch_component_carrier_measurement_array_response.relative_power_size());
  EXPECT_EQ(999, chp_fetch_component_carrier_measurement_array_response.relative_power().size());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_array_response.relative_power(0));
  EXPECT_SUCCESS(session, chp_fetch_total_aggregated_power_response);
  EXPECT_EQ(0.0, chp_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxNRDriverApiTests, ChpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_CHP, true));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto chp_fetch_component_carrier_measurement_response = client::chp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  const auto chp_fetch_spectrum_response = client::chp_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, chp_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, chp_fetch_spectrum_response);
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.dx());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, chp_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, chp_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLModAccContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
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

  int32 downlinkTestModel = RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM1_1;
  std::vector<float64> compositeRMSEVMMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> compositePeakEVMMaximum(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<int> compositePeakEVMSlotIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<int> compositePeakEVMSymbolIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<int> compositePeakEVMSubcarrierIndex(NUMBER_OF_COMPONENT_CARRIERS, 0);
  std::vector<float64> PDSCHRMSEVMMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierFrequencyErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQOriginOffsetMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQGainImbalanceMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierQuadratureErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  ModAccFetchRMSEVMPerSubcarrierMeanTraceResponse mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response;
  ModAccFetchRMSEVMPerSymbolMeanTraceResponse mod_acc_fetch_rmsevm_per_symbol_mean_trace_response;
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    compositeRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
    compositePeakEVMMaximum[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
    compositePeakEVMSlotIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
    compositePeakEVMSymbolIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
    compositePeakEVMSubcarrierIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
    componentCarrierFrequencyErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
    componentCarrierIQOriginOffsetMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
    componentCarrierIQGainImbalanceMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
    componentCarrierQuadratureErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
    switch (downlinkTestModel)
    {
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_2:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_3:
        PDSCHRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1:
        PDSCHRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_64QAM_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2_A:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1_A:
        PDSCHRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_256QAM_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_2:
        PDSCHRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_16QAM_RMS_EVM_MEAN);
        break;
    }
    mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
  }

  EXPECT_EQ(0.0, compositeRMSEVMMean[0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[0]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[1]);
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLModAccNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SUBBLOCKS = 2;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  std::vector<float64> centerFrequency { 3.5e9, 200.0e3 };
  std::vector<int> subblockFrequencyDefinition { RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_ABSOLUTE, RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_RELATIVE };
  std::vector<int> componentCarrierSpacingType { RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL };
  std::vector<float64> channelRaster { 15e3, 15e3 };
  std::vector<int> componentCarrierAtCenterFrequency { -1, -1 };
  float64 componentCarrierBandwidth[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { { 100e6, 100e6 }, { 100e6, 100e6 } };
  float64 componentCarrierFrequency[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { { -49.98e6, 50.01e6 }, { -49.98e6, 50.01e6 } };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_REFERENCE_LEVEL, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_EXTERNAL_ATTENUATION, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_SUBBLOCKS, NUMBER_OF_SUBBLOCKS));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++)
  {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CENTER_FREQUENCY, centerFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_SUBBLOCK_FREQUENCY_DEFINITION, subblockFrequencyDefinition[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, channelRaster[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, componentCarrierSpacingType[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, componentCarrierAtCenterFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++)
    {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, carrier_string_response);
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i][j]));
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i][j]));
    }
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), -1);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_FDD));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 downlinkTestModel = RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM1_1;
  float64 compositeRMSEVMMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 compositePeakEVMMaximum[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  int32 compositePeakEVMSlotIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  int32 compositePeakEVMSymbolIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  int32 compositePeakEVMSubcarrierIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  float64 PDSCHRMSEVMMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierFrequencyErrorMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierIQOriginOffsetMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierIQGainImbalanceMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierQuadratureErrorMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  ModAccFetchRMSEVMPerSubcarrierMeanTraceResponse mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response;
  ModAccFetchRMSEVMPerSymbolMeanTraceResponse mod_acc_fetch_rmsevm_per_symbol_mean_trace_response;
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++)
  {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++)
    {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, carrier_string_response);
      compositeRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
      compositePeakEVMMaximum[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
      compositePeakEVMSlotIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
      compositePeakEVMSymbolIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
      compositePeakEVMSubcarrierIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
      componentCarrierFrequencyErrorMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
      componentCarrierIQOriginOffsetMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
      componentCarrierIQGainImbalanceMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
      componentCarrierQuadratureErrorMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
      switch (downlinkTestModel)
      {
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_2:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_3:
        PDSCHRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1:
        PDSCHRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_64QAM_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2_A:
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1_A:
        PDSCHRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_256QAM_RMS_EVM_MEAN);
        break;
      case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_2:
        PDSCHRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_16QAM_RMS_EVM_MEAN);
        break;
      }
      mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
      mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    }
  }

  EXPECT_EQ(0.0, compositeRMSEVMMean[0][0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[0][1]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1][0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1][1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0][0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0][1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1][0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1][1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1][1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1][1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1][1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1][1]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[0][0]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[0][1]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[1][0]);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean[1][1]);
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLModAccSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_FDD));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 downlinkTestModel = RFMXNR_VAL_DOWNLINK_TEST_MODEL_TM1_1;
  float64 PDSCHRMSEVMMean = 0.0;
  ModAccFetchPDSCHQPSKConstellationTraceResponse mod_acc_fetch_pdschqpsk_constellation_trace_response;
  ModAccFetchPDSCH64QAMConstellationTraceResponse mod_acc_fetch_pdsch64q_am_constellation_trace_response;
  ModAccFetchPDSCH256QAMConstellationTraceResponse mod_acc_fetch_pdsch256q_am_constellation_trace_response;
  ModAccFetchPDSCH16QAMConstellationTraceResponse mod_acc_fetch_pdsch16q_am_constellation_trace_response;
  float64 compositeRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
  float64 compositePeakEVMMaximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
  int32 compositePeakEVMSlotIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
  int32 compositePeakEVMSymbolIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
  int32 compositePeakEVMSubcarrierIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
  float64 componentCarrierFrequencyErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
  float64 componentCarrierIQOriginOffsetMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
  float64 componentCarrierIQGainImbalanceMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
  float64 componentCarrierQuadratureErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
  switch (downlinkTestModel)
  {
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1:
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_2:
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_3:
      PDSCHRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN);
      mod_acc_fetch_pdschqpsk_constellation_trace_response = client::mod_acc_fetch_pdschqpsk_constellation_trace(stub(), session, "", 10.000000);
      break;
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2:
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1:
      PDSCHRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_64QAM_RMS_EVM_MEAN);
      mod_acc_fetch_pdsch64q_am_constellation_trace_response = client::mod_acc_fetch_pdsch64q_am_constellation_trace(stub(), session, "", 10.000000);
      break;
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM2_A:
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_1_A:
      PDSCHRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_256QAM_RMS_EVM_MEAN);
      mod_acc_fetch_pdsch256q_am_constellation_trace_response = client::mod_acc_fetch_pdsch256q_am_constellation_trace(stub(), session, "", 10.000000);
      break;
    case NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM3_2:
      PDSCHRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_16QAM_RMS_EVM_MEAN);
      mod_acc_fetch_pdsch16q_am_constellation_trace_response = client::mod_acc_fetch_pdsch16q_am_constellation_trace(stub(), session, "", 10.000000);
      break;
  }
  const auto mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, "", 10.000000);

  EXPECT_EQ(0.0, compositeRMSEVMMean);
  EXPECT_EQ(0.0, compositePeakEVMMaximum);
  EXPECT_EQ(0, compositePeakEVMSlotIndex);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean);
  EXPECT_EQ(0.0, PDSCHRMSEVMMean);
  EXPECT_SUCCESS(session, mod_acc_fetch_pdschqpsk_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdschqpsk_constellation_trace_response.qpsk_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdschqpsk_constellation_trace_response.qpsk_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch64q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch64q_am_constellation_trace_response.qam64_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch64q_am_constellation_trace_response.qam64_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch256q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch256q_am_constellation_trace_response.qam256_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch256q_am_constellation_trace_response.qam256_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch16q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch16q_am_constellation_trace_response.qam16_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch16q_am_constellation_trace_response.qam16_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLModAccUserDefinedChannelsFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  std::vector<int> PDSCHResourceBlockOffset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> PDSCHNumberOfResourceBlocks { -1 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_CELL_ID, 0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED, NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_DOWNLINK_CHANNEL_CONFIGURATION_MODE, NIRFMXNR_INT32_DOWNLINK_CHANNEL_CONFIGURATION_MODE_USER_DEFINED));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_INCREMENT_CELL_ID_ENABLED, NIRFMXNR_INT32_AUTO_INCREMENT_CELL_ID_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_MODULATION_TYPE, NIRFMXNR_INT32_PDSCH_MODULATION_TYPE_QPSK));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_SLOT_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_SYMBOL_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, NUMBER_OF_RESOURCE_BLOCK_CLUSTERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, carrier_string_response);
  auto bandwidth_part_string_response = client::build_bandwidth_part_string(stub(), carrier_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, bandwidth_part_string_response);
  auto user_string_response = client::build_user_string(stub(), bandwidth_part_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, user_string_response);
  auto pdsch_string_response = client::build_pdsch_string(stub(), user_string_response.selector_string_out(), 0);
  EXPECT_SUCCESS(session, pdsch_string_response);
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++)
  {
    auto pdsch_cluster_string_response = client::build_pdsch_cluster_string(stub(), pdsch_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, pdsch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pdsch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PDSCH_RESOURCE_BLOCK_OFFSET, PDSCHResourceBlockOffset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pdsch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PDSCH_NUMBER_OF_RESOURCE_BLOCKS, PDSCHNumberOfResourceBlocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PDSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PDSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_MAPPING_TYPE, NIRFMXNR_INT32_PDSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_DURATION, NIRFMXNR_INT32_PDSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PDSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SSB_ENABLED, NIRFMXNR_INT32_SSB_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SSB_CRB_OFFSET, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SSB_SUBCARRIER_OFFSET, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SSB_PATTERN, NIRFMXNR_INT32_SSB_PATTERN_B_3_GHZ_TO_6_GHZ));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 compositeRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
  float64 compositePeakEVMMaximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
  int32 compositePeakEVMSlotIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
  int32 compositePeakEVMSymbolIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
  int32 compositePeakEVMSubcarrierIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
  float64 componentCarrierFrequencyErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
  float64 componentCarrierIQOriginOffsetMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
  float64 componentCarrierIQGainImbalanceMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
  float64 componentCarrierQuadratureErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
  float64 PDSCHQPSKRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_QPSK_RMS_EVM_MEAN);
  float64 PDSCH16QAMRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_16QAM_RMS_EVM_MEAN);
  float64 PDSCH64QAMRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_64QAM_RMS_EVM_MEAN);
  float64 PDSCH256QAMRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_PDSCH_256QAM_RMS_EVM_MEAN);
  const auto mod_acc_fetch_pdschqpsk_constellation_trace_response = client::mod_acc_fetch_pdschqpsk_constellation_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_pdsch16q_am_constellation_trace_response = client::mod_acc_fetch_pdsch16q_am_constellation_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_pdsch64q_am_constellation_trace_response = client::mod_acc_fetch_pdsch64q_am_constellation_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_pdsch256q_am_constellation_trace_response = client::mod_acc_fetch_pdsch256q_am_constellation_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.000000);
  const auto mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, "", 10.000000);

  EXPECT_EQ(0.0, compositeRMSEVMMean);
  EXPECT_EQ(0.0, compositePeakEVMMaximum);
  EXPECT_EQ(0, compositePeakEVMSlotIndex);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean);
  EXPECT_EQ(0.0, PDSCHQPSKRMSEVMMean);
  EXPECT_EQ(0.0, PDSCH16QAMRMSEVMMean);
  EXPECT_EQ(0.0, PDSCH64QAMRMSEVMMean);
  EXPECT_EQ(0.0, PDSCH256QAMRMSEVMMean);
  EXPECT_SUCCESS(session, mod_acc_fetch_pdschqpsk_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdschqpsk_constellation_trace_response.qpsk_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdschqpsk_constellation_trace_response.qpsk_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch16q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch16q_am_constellation_trace_response.qam16_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch16q_am_constellation_trace_response.qam16_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch64q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch64q_am_constellation_trace_response.qam64_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch64q_am_constellation_trace_response.qam64_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_pdsch256q_am_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch256q_am_constellation_trace_response.qam256_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pdsch256q_am_constellation_trace_response.qam256_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLPVTContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  std::vector<float64> ratedTRP { 0.00, 0.00 };
  std::vector<float64> ratedEIRP { 0.00, 0.00 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_GNODEB_TYPE, NIRFMXNR_INT32_G_NODE_B_TYPE_1_C));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_RATED_TRP, ratedTRP[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_RATED_EIRP, ratedEIRP[i]));
  }
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_TDD));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_off_power_exclusion_periods(stub(), session, "", 0.0, 0.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PVT_MEASUREMENT_INTERVAL_AUTO, NIRFMXNR_INT32_PVT_MEASUREMENT_INTERVAL_AUTO_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PVT_MEASUREMENT_INTERVAL, 0.01));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  std::vector<int> measurementStatus { RFMXNR_VAL_PVT_MEASUREMENT_STATUS_FAIL };
  std::vector<float64> PVTResultsPkWindowedOFFPwr(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> PVTResultsPkWindowedOFFPwrMargin(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> PVTResultsPkWindowedOFFPwrTime(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> absoluteONPower(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  PVTFetchSignalPowerTraceResponse pvt_fetch_signal_power_trace_response;
  PVTFetchWindowedSignalPowerTraceResponse pvt_fetch_windowed_signal_power_trace_response;
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    measurementStatus[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PVT_RESULTS_MEASUREMENT_STATUS);
    PVTResultsPkWindowedOFFPwr[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER);
    PVTResultsPkWindowedOFFPwrMargin[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_MARGIN);
    PVTResultsPkWindowedOFFPwrTime[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_TIME);
    absoluteONPower[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PVT_RESULTS_ABSOLUTE_ON_POWER);
  }
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), "", i);
    EXPECT_SUCCESS(session, carrier_string_response);
    pvt_fetch_signal_power_trace_response = client::pvt_fetch_signal_power_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
    pvt_fetch_windowed_signal_power_trace_response = client::pvt_fetch_windowed_signal_power_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
  }

  EXPECT_EQ(0, measurementStatus[0]);
  EXPECT_EQ(0, measurementStatus[1]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwr[0]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwr[1]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrMargin[0]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrMargin[1]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrTime[0]);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrTime[1]);
  EXPECT_EQ(0.0, absoluteONPower[0]);
  EXPECT_EQ(0.0, absoluteONPower[1]);
  EXPECT_SUCCESS(session, pvt_fetch_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
  EXPECT_SUCCESS(session, pvt_fetch_windowed_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power_size());
  EXPECT_EQ(999, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power(0));
}

TEST_F(NiRFmxNRDriverApiTests, DLPVTSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_TM1_1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME, NIRFMXNR_INT32_DOWNLINK_TEST_MODEL_DUPLEX_SCHEME_TDD));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_GNODEB_TYPE, NIRFMXNR_INT32_G_NODE_B_TYPE_1_C));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_RATED_TRP, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_RATED_EIRP, 0.0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_off_power_exclusion_periods(stub(), session, "", 0.0, 0.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PVT_MEASUREMENT_INTERVAL_AUTO, NIRFMXNR_INT32_PVT_MEASUREMENT_INTERVAL_AUTO_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PVT_MEASUREMENT_INTERVAL, 0.01));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 measurementStatus = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_PVT_RESULTS_MEASUREMENT_STATUS);
  float64 PVTResultsPkWindowedOFFPwr = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER);
  float64 PVTResultsPkWindowedOFFPwrMargin = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_MARGIN);
  float64 PVTResultsPkWindowedOFFPwrTime = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_PVT_RESULTS_PEAK_WINDOWED_OFF_POWER_TIME);
  float64 absoluteONPower = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_PVT_RESULTS_ABSOLUTE_ON_POWER);
  const auto pvt_fetch_signal_power_trace_response = client::pvt_fetch_signal_power_trace(stub(), session, "", 10.0);
  const auto pvt_fetch_windowed_signal_power_trace_response = client::pvt_fetch_windowed_signal_power_trace(stub(), session, "", 10.0);

  EXPECT_EQ(0, measurementStatus);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwr);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrMargin);
  EXPECT_EQ(0.0, PVTResultsPkWindowedOFFPwrTime);
  EXPECT_EQ(0.0, absoluteONPower);
  EXPECT_SUCCESS(session, pvt_fetch_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
  EXPECT_SUCCESS(session, pvt_fetch_windowed_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power_size());
  EXPECT_EQ(999, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_windowed_signal_power_trace_response.windowed_signal_power(0));
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_FEMTestWithAutomaticSGSASharedLOFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_ListModeWithSGSAHandshakingFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_ListModeWithTimeBasedSynchronizationFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxNRDriverApiTests, ModAccAcpChpObwSemTxpCompositeSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  int32 linkDirection = RFMXNR_VAL_LINK_DIRECTION_UPLINK;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC | MEASUREMENT_TYPES_ACP | MEASUREMENT_TYPES_CHP | MEASUREMENT_TYPES_OBW | MEASUREMENT_TYPES_SEM | MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_sweep_time(stub(), session, "", ACP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::chp_cfg_sweep_time(stub(), session, "", CHP_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", ACP_AVERAGING_ENABLED_FALSE, 10, ACP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::chp_cfg_averaging(stub(), session, "", CHP_AVERAGING_ENABLED_FALSE, 10, CHP_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED, NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL, 1e-3));
  if (linkDirection == NIRFMXNR_INT32_LINK_DIRECTION_UPLINK)
  {
    EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfgg_node_b_category(stub(), session, "", G_NODE_B_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DOWNLINK_MASK_TYPE, NIRFMXNR_INT32_SEM_DOWNLINK_MASK_TYPE_STANDARD));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DELTA_F_MAXIMUM, 15.0e6));
    EXPECT_SUCCESS(session, client::sem_cfg_component_carrier_rated_output_power(stub(), session, "", 0.0));
  }
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 compositeRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
  float64 compositePeakEVMMaximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
  float64 componentCarrierFrequencyErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
  float64 componentCarrierIQOriginOffsetMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
  const auto acp_fetch_offset_measurement_array_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  const auto acp_fetch_component_carrier_measurement_response = client::acp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  const auto chp_fetch_component_carrier_measurement_response = client::chp_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_component_carrier_measurement_response = client::sem_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_EQ(0.0, compositeRMSEVMMean);
  EXPECT_EQ(0.0, compositePeakEVMMaximum);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean);
  EXPECT_SUCCESS(session, acp_fetch_offset_measurement_array_response);
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_relative_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_relative_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.lower_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.lower_absolute_power(0));
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power_size());
  EXPECT_EQ(999, acp_fetch_offset_measurement_array_response.upper_absolute_power().size());
  EXPECT_EQ(0.0, acp_fetch_offset_measurement_array_response.upper_absolute_power(0));
  EXPECT_SUCCESS(session, acp_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, acp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, acp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, chp_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, chp_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_EQ(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.peak_absolute_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.peak_frequency());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

TEST_F(NiRFmxNRDriverApiTests, ObwContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_OBW_SPAN_AUTO, NIRFMXNR_INT32_OBW_SPAN_AUTO_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "subblock0", NIRFMXNR_ATTRIBUTE_OBW_SPAN, 399.86e6));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);
  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_EQ(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.stop_frequency());
  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(999, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.spectrum(0));
}

TEST_F(NiRFmxNRDriverApiTests, ObwSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_OBW, true));
  EXPECT_SUCCESS(session, client::obw_cfg_sweep_time(stub(), session, "", OBW_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_OBW_SPAN_AUTO, NIRFMXNR_INT32_OBW_SPAN_AUTO_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "subblock0", NIRFMXNR_ATTRIBUTE_OBW_SPAN, 200e6));
  EXPECT_SUCCESS(session, client::obw_cfg_averaging(stub(), session, "", OBW_AVERAGING_ENABLED_FALSE, 10, OBW_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto obw_fetch_spectrum_response = client::obw_fetch_spectrum(stub(), session, "", 10.0);
  const auto obw_fetch_measurement_response = client::obw_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, obw_fetch_spectrum_response);
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.dx());
  EXPECT_EQ(999, obw_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, obw_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, obw_fetch_spectrum_response.spectrum(0));
  EXPECT_SUCCESS(session, obw_fetch_measurement_response);
  EXPECT_EQ(0.0, obw_fetch_measurement_response.occupied_bandwidth());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.absolute_power());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.start_frequency());
  EXPECT_EQ(0.0, obw_fetch_measurement_response.stop_frequency());
}

TEST_F(NiRFmxNRDriverApiTests, SemContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const auto NUMBER_OF_OFFSETS = 4;
  char carrierString[MAX_SELECTOR_STRING];
  int32 linkDirection = RFMXNR_VAL_LINK_DIRECTION_UPLINK;
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  std::vector<float64> componentCarrierRatedOutputPower { 0.0, 0.0 };
  std::vector<float64> offsetStartFrequency { 15.0e3, 1.5e6, 5.5e6, 40.3e6 };
  std::vector<float64> offsetStopFrequency { 985.0e3, 4.5e6, 39.3e6, 44.3e6 };
  std::vector<int> offsetSideband { RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXNR_VAL_SEM_OFFSET_SIDEBAND_BOTH };
  std::vector<float64> offsetRBW { 10.0e3, 250.0e3, 1.0e6, 1.0e6 };
  std::vector<int> offsetRBWFilterType { RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN, RFMXNR_VAL_SEM_OFFSET_RBW_FILTER_TYPE_GAUSSIAN };
  std::vector<int> bandwidthIntegral { 3, 4, 1, 1 };
  std::vector<int> limitFailMask { RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE, RFMXNR_VAL_SEM_OFFSET_LIMIT_FAIL_MASK_ABSOLUTE };
  std::vector<float64> absoluteLimitStart { -22.5, -8.5, -11.5, -23.5 };
  std::vector<float64> absoluteLimitStop { -22.5, -8.5, -11.5, -23.5 };
  std::vector<float64> relativeLimitStart { -53.0, -53.0, -53.0, -53.0 };
  std::vector<float64> relativeLimitStop { -60.0, -60.0, -60.0, -60.0 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
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
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
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
  if (linkDirection == NIRFMXNR_INT32_LINK_DIRECTION_UPLINK)
  {
    EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfgg_node_b_category(stub(), session, "", G_NODE_B_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DOWNLINK_MASK_TYPE, NIRFMXNR_INT32_SEM_DOWNLINK_MASK_TYPE_STANDARD));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DELTA_F_MAXIMUM, 15.0e6));
    EXPECT_SUCCESS(session, client::sem_cfg_component_carrier_rated_output_power_array(stub(), session, "", componentCarrierRatedOutputPower));
  }
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_total_aggregated_power_response = client::sem_fetch_total_aggregated_power(stub(), session, "", 10.0);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_total_aggregated_power_response);
  EXPECT_EQ(0.0, sem_fetch_total_aggregated_power_response.total_aggregated_power());
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(999, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(999, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

// NOTE: disabled due to "typedef struct" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_SemNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxNRDriverApiTests, SemSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  int32 linkDirection = RFMXNR_VAL_LINK_DIRECTION_UPLINK;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  if (linkDirection == NIRFMXNR_INT32_LINK_DIRECTION_UPLINK)
  {
    EXPECT_SUCCESS(session, client::sem_cfg_uplink_mask_type(stub(), session, "", SEM_UPLINK_MASK_TYPE_GENERAL));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfgg_node_b_category(stub(), session, "", G_NODE_B_CATEGORY_WIDE_AREA_BASE_STATION_CATEGORY_A));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DOWNLINK_MASK_TYPE, NIRFMXNR_INT32_SEM_DOWNLINK_MASK_TYPE_STANDARD));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_SEM_DELTA_F_MAXIMUM, 15.0e6));
    EXPECT_SUCCESS(session, client::sem_cfg_component_carrier_rated_output_power(stub(), session, "", 0.0));
  }
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  int32 arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  const auto sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  const auto sem_fetch_component_carrier_measurement_response = client::sem_fetch_component_carrier_measurement(stub(), session, "", 10.0);
  const auto sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  const auto sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_upper_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_upper_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_upper_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_upper_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_lower_offset_margin_array_response);
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.measurement_status().size());
  EXPECT_EQ(0, sem_fetch_lower_offset_margin_array_response.measurement_status(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_frequency().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_frequency(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_absolute_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_absolute_power(0));
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power_size());
  EXPECT_EQ(999, sem_fetch_lower_offset_margin_array_response.margin_relative_power().size());
  EXPECT_EQ(0.0, sem_fetch_lower_offset_margin_array_response.margin_relative_power(0));
  EXPECT_SUCCESS(session, sem_fetch_component_carrier_measurement_response);
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.peak_absolute_power());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.peak_frequency());
  EXPECT_EQ(0.0, sem_fetch_component_carrier_measurement_response.relative_power());
  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_spectrum_response);
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.x0());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.dx());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum_size());
  EXPECT_EQ(999, sem_fetch_spectrum_response.spectrum().size());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.spectrum(0));
  EXPECT_EQ(999, sem_fetch_spectrum_response.composite_mask_size());
  EXPECT_EQ(999, sem_fetch_spectrum_response.composite_mask().size());
  EXPECT_EQ(0.0, sem_fetch_spectrum_response.composite_mask(0));
}

TEST_F(NiRFmxNRDriverApiTests, TxpContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
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
  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_power_maximum());
  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
}

TEST_F(NiRFmxNRDriverApiTests, TxpSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL, 1.0e-3));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED, NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);
  const auto txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_power_maximum());
  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
}

TEST_F(NiRFmxNRDriverApiTests, ULModAccContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  std::vector<int> cellID { 0, 1 };
  std::vector<int> PUSCHResourceBlockOffset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> PUSCHNumberOfResourceBlocks { -1 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED, NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_INCREMENT_CELL_ID_ENABLED, NIRFMXNR_INT32_AUTO_INCREMENT_CELL_ID_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CELL_ID, cellID[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
  }
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED, NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_MODULATION_TYPE, NIRFMXNR_INT32_PUSCH_MODULATION_TYPE_QPSK));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_SYMBOL_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, NUMBER_OF_RESOURCE_BLOCK_CLUSTERS));
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++)
  {
    auto pusch_cluster_string_response = client::build_pusch_cluster_string(stub(), carrierString, i);
    EXPECT_SUCCESS(session, pusch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_RESOURCE_BLOCK_OFFSET, PUSCHResourceBlockOffset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCKS, PUSCHNumberOfResourceBlocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
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
  std::vector<float64> componentCarrierFrequencyErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQOriginOffsetMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierIQGainImbalanceMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> componentCarrierQuadratureErrorMean(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  std::vector<float64> inBandEmissionMargin(NUMBER_OF_COMPONENT_CARRIERS, 0.0);
  ModAccFetchPUSCHDataConstellationTraceResponse mod_acc_fetch_pusch_data_constellation_trace_response;
  ModAccFetchPUSCHDMRSConstellationTraceResponse mod_acc_fetch_puschdmrs_constellation_trace_response;
  ModAccFetchRMSEVMPerSubcarrierMeanTraceResponse mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response;
  ModAccFetchRMSEVMPerSymbolMeanTraceResponse mod_acc_fetch_rmsevm_per_symbol_mean_trace_response;
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    compositeRMSEVMMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
    compositePeakEVMMaximum[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
    compositePeakEVMSlotIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
    compositePeakEVMSymbolIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
    compositePeakEVMSubcarrierIndex[i] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
    componentCarrierFrequencyErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
    componentCarrierIQOriginOffsetMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
    componentCarrierIQGainImbalanceMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
    componentCarrierQuadratureErrorMean[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
    inBandEmissionMargin[i] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN);
  }
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), "", i);
    EXPECT_SUCCESS(session, carrier_string_response);
    mod_acc_fetch_pusch_data_constellation_trace_response = client::mod_acc_fetch_pusch_data_constellation_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
    mod_acc_fetch_puschdmrs_constellation_trace_response = client::mod_acc_fetch_puschdmrs_constellation_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
  }
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
    mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
  }
  const auto mod_acc_fetch_spectral_flatness_trace_response = client::mod_acc_fetch_spectral_flatness_trace(stub(), session, "", 10.0);

  EXPECT_EQ(0.0, compositeRMSEVMMean[0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1]);
  EXPECT_EQ(0.0, inBandEmissionMargin[0]);
  EXPECT_EQ(0.0, inBandEmissionMargin[1]);
  EXPECT_SUCCESS(session, mod_acc_fetch_pusch_data_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pusch_data_constellation_trace_response.pusch_data_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pusch_data_constellation_trace_response.pusch_data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_puschdmrs_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_puschdmrs_constellation_trace_response.pusch_dmrs_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_puschdmrs_constellation_trace_response.pusch_dmrs_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_spectral_flatness_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness(0));
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask(0));
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask(0));
}

TEST_F(NiRFmxNRDriverApiTests, ULModAccNonContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_SUBBLOCKS = 2;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  std::vector<float64> centerFrequency { 3.5e9, 200.0e3 };
  std::vector<int> subblockFrequencyDefinition { RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_ABSOLUTE, RFMXNR_VAL_SUBBLOCK_FREQUENCY_DEFINITION_RELATIVE };
  std::vector<int> band { 78, 78 };
  std::vector<int> componentCarrierSpacingType { RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL, RFMXNR_VAL_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL };
  std::vector<float64> channelRaster { 15e3, 15e3 };
  std::vector<int> componentCarrierAtCenterFrequency { -1, -1 };
  float64 componentCarrierBandwidth[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { { 100e6, 100e6 }, { 100e6, 100e6 } };
  float64 componentCarrierFrequency[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { { -49.98e6, 50.01e6 }, { -49.98e6, 50.01e6 } };
  int32 cellID[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { { 0, 1 }, { 0, 1 } };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_REFERENCE_LEVEL, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_EXTERNAL_ATTENUATION, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_UPLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED, NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_INCREMENT_CELL_ID_ENABLED, NIRFMXNR_INT32_AUTO_INCREMENT_CELL_ID_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_SUBBLOCKS, NUMBER_OF_SUBBLOCKS));
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++)
  {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CENTER_FREQUENCY, centerFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_SUBBLOCK_FREQUENCY_DEFINITION, subblockFrequencyDefinition[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_BAND, band[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, componentCarrierSpacingType[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, componentCarrierAtCenterFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, channelRaster[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, subblock_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++)
    {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, carrier_string_response);
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i][j]));
      EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i][j]));
      EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CELL_ID, cellID[i][j]));
    }
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), -1);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED, NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE));
    EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION, std::string("0-Last")));
    EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_SYMBOL_ALLOCATION, std::string("0-Last")));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 compositeRMSEVMMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 compositePeakEVMMaximum[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  int32 compositePeakEVMSlotIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  int32 compositePeakEVMSymbolIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  int32 compositePeakEVMSubcarrierIndex[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0 };
  float64 componentCarrierFrequencyErrorMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierIQOriginOffsetMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierIQGainImbalanceMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 componentCarrierQuadratureErrorMean[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  float64 inBandEmissionMargin[NUMBER_OF_SUBBLOCKS][NUMBER_OF_COMPONENT_CARRIERS] = { 0.0 };
  ModAccFetchRMSEVMPerSubcarrierMeanTraceResponse mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response;
  ModAccFetchRMSEVMPerSymbolMeanTraceResponse mod_acc_fetch_rmsevm_per_symbol_mean_trace_response;
  for (int i = 0; i < NUMBER_OF_SUBBLOCKS; i++)
  {
    auto subblock_string_response = client::build_subblock_string(stub(), "", i);
    EXPECT_SUCCESS(session, subblock_string_response);
    for (int j = 0; j < NUMBER_OF_COMPONENT_CARRIERS; j++)
    {
      auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), j);
      EXPECT_SUCCESS(session, carrier_string_response);
      compositeRMSEVMMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
      compositePeakEVMMaximum[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
      compositePeakEVMSlotIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
      compositePeakEVMSymbolIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
      compositePeakEVMSubcarrierIndex[i][j] = GET_ATTR_I32(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
      componentCarrierFrequencyErrorMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
      componentCarrierIQOriginOffsetMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
      componentCarrierIQGainImbalanceMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
      componentCarrierQuadratureErrorMean[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
      inBandEmissionMargin[i][j] = GET_ATTR_F64(session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN);
      mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
      mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    }
  }

  EXPECT_EQ(0.0, compositeRMSEVMMean[0][0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[0][1]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1][0]);
  EXPECT_EQ(0.0, compositeRMSEVMMean[1][1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0][0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[0][1]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1][0]);
  EXPECT_EQ(0.0, compositePeakEVMMaximum[1][1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSlotIndex[1][1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex[1][1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0][0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[0][1]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1][0]);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex[1][1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean[1][1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0][0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[0][1]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1][0]);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean[1][1]);
  EXPECT_EQ(0.0, inBandEmissionMargin[0][0]);
  EXPECT_EQ(0.0, inBandEmissionMargin[0][1]);
  EXPECT_EQ(0.0, inBandEmissionMargin[1][0]);
  EXPECT_EQ(0.0, inBandEmissionMargin[1][1]);
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
}

TEST_F(NiRFmxNRDriverApiTests, ULModAccSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  std::vector<int> PUSCHResourceBlockOffset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> PUSCHNumberOfResourceBlocks { -1 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE, 0.0, BOOLEAN_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_CELL_ID, 0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_BAND, 78));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED, NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE));
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
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++)
  {
    auto pusch_cluster_string_response = client::build_pusch_cluster_string(stub(), pusch_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, pusch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_RESOURCE_BLOCK_OFFSET, PUSCHResourceBlockOffset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCKS, PUSCHNumberOfResourceBlocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE, NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED, NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT, 10));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT, NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH, 1));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  float64 compositeRMSEVMMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_RMS_EVM_MEAN);
  float64 compositePeakEVMMaximum = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_MAXIMUM);
  int32 compositePeakEVMSlotIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX);
  int32 compositePeakEVMSymbolIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX);
  int32 compositePeakEVMSubcarrierIndex = GET_ATTR_I32(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX);
  float64 componentCarrierFrequencyErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN);
  float64 componentCarrierIQOriginOffsetMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN);
  float64 componentCarrierIQGainImbalanceMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN);
  float64 componentCarrierQuadratureErrorMean = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN);
  float64 inBandEmissionMargin = GET_ATTR_F64(session, "", NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN);
  const auto mod_acc_fetch_pusch_data_constellation_trace_response = client::mod_acc_fetch_pusch_data_constellation_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_puschdmrs_constellation_trace_response = client::mod_acc_fetch_puschdmrs_constellation_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response = client::mod_acc_fetch_rmsevm_per_subcarrier_mean_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_rmsevm_per_symbol_mean_trace_response = client::mod_acc_fetch_rmsevm_per_symbol_mean_trace(stub(), session, "", 10.0);
  const auto mod_acc_fetch_spectral_flatness_trace_response = client::mod_acc_fetch_spectral_flatness_trace(stub(), session, "", 10.0);

  EXPECT_EQ(0.0, compositeRMSEVMMean);
  EXPECT_EQ(0.0, compositePeakEVMMaximum);
  EXPECT_EQ(0, compositePeakEVMSlotIndex);
  EXPECT_EQ(0, compositePeakEVMSymbolIndex);
  EXPECT_EQ(0, compositePeakEVMSubcarrierIndex);
  EXPECT_EQ(0.0, componentCarrierFrequencyErrorMean);
  EXPECT_EQ(0.0, componentCarrierIQOriginOffsetMean);
  EXPECT_EQ(0.0, componentCarrierIQGainImbalanceMean);
  EXPECT_EQ(0.0, componentCarrierQuadratureErrorMean);
  EXPECT_EQ(0.0, inBandEmissionMargin);
  EXPECT_SUCCESS(session, mod_acc_fetch_pusch_data_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_pusch_data_constellation_trace_response.pusch_data_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_pusch_data_constellation_trace_response.pusch_data_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_puschdmrs_constellation_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_puschdmrs_constellation_trace_response.pusch_dmrs_constellation(0).real());
  EXPECT_EQ(0.0, mod_acc_fetch_puschdmrs_constellation_trace_response.pusch_dmrs_constellation(0).imaginary());
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_subcarrier_mean_trace_response.rms_evm_per_subcarrier_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean_size());
  EXPECT_EQ(999, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean().size());
  EXPECT_EQ(0.0, mod_acc_fetch_rmsevm_per_symbol_mean_trace_response.rms_evm_per_symbol_mean(0));
  EXPECT_SUCCESS(session, mod_acc_fetch_spectral_flatness_trace_response);
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.x0());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.dx());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness(0));
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_lower_mask(0));
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask_size());
  EXPECT_EQ(999, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask().size());
  EXPECT_EQ(0.0, mod_acc_fetch_spectral_flatness_trace_response.spectral_flatness_upper_mask(0));
}

// NOTE: disabled due to "ReadFromTDMSFile" in example's source code
TEST_F(NiRFmxNRDriverApiTests, DISABLED_ULModAccSpeedOptimizedFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxNRDriverApiTests, ULPVTContiguousMultiCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierBandwidth { 100e6, 100e6 };
  std::vector<float64> componentCarrierFrequency { -49.98e6, 50.01e6 };
  std::vector<int> cellID { 0, 1 };
  std::vector<int> PUSCHResourceBlockOffset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> PUSCHNumberOfResourceBlocks { -1 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  auto subblock_string_response = client::build_subblock_string(stub(), "", 0);
  EXPECT_SUCCESS(session, subblock_string_response);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, carrier_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, componentCarrierBandwidth[i]));
    EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY, componentCarrierFrequency[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrier_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_CELL_ID, cellID[i]));
  }
  strcpy_s(carrierString, sizeof("carrier::all"), "carrier::all");
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED, NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_MODULATION_TYPE, NIRFMXNR_INT32_PUSCH_MODULATION_TYPE_QPSK));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION, std::string("1")));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_SYMBOL_ALLOCATION, std::string("0-Last")));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, NUMBER_OF_RESOURCE_BLOCK_CLUSTERS));
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++)
  {
    auto pusch_cluster_string_response = client::build_pusch_cluster_string(stub(), carrierString, i);
    EXPECT_SUCCESS(session, pusch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_RESOURCE_BLOCK_OFFSET, PUSCHResourceBlockOffset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCKS, PUSCHNumberOfResourceBlocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, carrierString, NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_off_power_exclusion_periods(stub(), session, "", 0.0, 0.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  PVTFetchSignalPowerTraceResponse pvt_fetch_signal_power_trace_response;
  const auto pvt_fetch_measurement_array_response = client::pvt_fetch_measurement_array(stub(), session, "", 10.0);
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++)
  {
    auto carrier_string_response = client::build_carrier_string(stub(), "", i);
    EXPECT_SUCCESS(session, carrier_string_response);
    pvt_fetch_signal_power_trace_response = client::pvt_fetch_signal_power_trace(stub(), session, carrier_string_response.selector_string_out(), 10.0);
  }

  EXPECT_SUCCESS(session, pvt_fetch_measurement_array_response);
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.measurement_status_size());
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.measurement_status().size());
  EXPECT_EQ(0, pvt_fetch_measurement_array_response.measurement_status(0));
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_off_power_before_size());
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_off_power_before().size());
  EXPECT_EQ(0.0, pvt_fetch_measurement_array_response.absolute_off_power_before(0));
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_off_power_after_size());
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_off_power_after().size());
  EXPECT_EQ(0.0, pvt_fetch_measurement_array_response.absolute_off_power_after(0));
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_on_power_size());
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.absolute_on_power().size());
  EXPECT_EQ(0.0, pvt_fetch_measurement_array_response.absolute_on_power(0));
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.burst_width_size());
  EXPECT_EQ(999, pvt_fetch_measurement_array_response.burst_width().size());
  EXPECT_EQ(0.0, pvt_fetch_measurement_array_response.burst_width(0));
  EXPECT_SUCCESS(session, pvt_fetch_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
}

TEST_F(NiRFmxNRDriverApiTests, ULPVTSingleCarrierFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_RESOURCE_BLOCK_CLUSTERS = 1;
  std::vector<int> PUSCHResourceBlockOffset(NUMBER_OF_RESOURCE_BLOCK_CLUSTERS, 0);
  std::vector<int> PUSCHNumberOfResourceBlocks { -1 };
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 8.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH, 100e6));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_CELL_ID, 0));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING, 30e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED, NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION, std::string("1")));
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
  for (int i = 0; i < NUMBER_OF_RESOURCE_BLOCK_CLUSTERS; i++)
  {
    auto pusch_cluster_string_response = client::build_pusch_cluster_string(stub(), pusch_string_response.selector_string_out(), i);
    EXPECT_SUCCESS(session, pusch_cluster_string_response);
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_RESOURCE_BLOCK_OFFSET, PUSCHResourceBlockOffset[i]));
    EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, pusch_cluster_string_response.selector_string_out(), NIRFMXNR_ATTRIBUTE_PUSCH_NUMBER_OF_RESOURCE_BLOCKS, PUSCHNumberOfResourceBlocks[i]));
  }
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE, NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER, 0.0));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE, NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_TYPE1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE, NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION, 2));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION, NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS, 0));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_PVT, true));
  EXPECT_SUCCESS(session, client::pvt_cfg_measurement_method(stub(), session, "", PVT_MEASUREMENT_METHOD_NORMAL));
  EXPECT_SUCCESS(session, client::pvt_cfg_off_power_exclusion_periods(stub(), session, "", 0.0, 0.0));
  EXPECT_SUCCESS(session, client::pvt_cfg_averaging(stub(), session, "", PVT_AVERAGING_ENABLED_FALSE, 10, PVT_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto pvt_fetch_measurement_response = client::pvt_fetch_measurement(stub(), session, "", 10.0);
  const auto pvt_fetch_signal_power_trace_response = client::pvt_fetch_signal_power_trace(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, pvt_fetch_measurement_response);
  EXPECT_EQ(0, pvt_fetch_measurement_response.measurement_status());
  EXPECT_EQ(0.0, pvt_fetch_measurement_response.absolute_off_power_before());
  EXPECT_EQ(0.0, pvt_fetch_measurement_response.absolute_off_power_after());
  EXPECT_EQ(0.0, pvt_fetch_measurement_response.absolute_on_power());
  EXPECT_EQ(0.0, pvt_fetch_measurement_response.burst_width());
  EXPECT_SUCCESS(session, pvt_fetch_signal_power_trace_response);
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.x0());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.dx());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.signal_power().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.signal_power(0));
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit_size());
  EXPECT_EQ(999, pvt_fetch_signal_power_trace_response.absolute_limit().size());
  EXPECT_EQ(0.0, pvt_fetch_signal_power_trace_response.absolute_limit(0));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
