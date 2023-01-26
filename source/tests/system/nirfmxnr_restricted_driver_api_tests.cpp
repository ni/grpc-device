#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxnr/nirfmxnr_client.h"
#include "nirfmxnr_restricted/nirfmxnr_restricted_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace nirfmxnr_grpc;
using namespace nirfmxnr_restricted_grpc;
namespace client = nirfmxnr_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxnr_restricted_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663E = "5663E";
constexpr auto NR_SYNC_FAILURE_WARNING1 = 684300;
constexpr auto NR_SYNC_FAILURE_WARNING1_STR = "Failed to synchronize to the signal";
constexpr auto NR_SYNC_FAILURE_WARNING2 = 684004;
constexpr auto NR_SYNC_FAILURE_WARNING2_STR = "Failed to synchronize to at-least one of the CC's";

#define EXPECT_NR_SYNC_FAILURE_WARNING(session, response)                                      \
  if ((response).status() == NR_SYNC_FAILURE_WARNING1) {                                       \
    EXPECT_WARNING(NR_SYNC_FAILURE_WARNING1, NR_SYNC_FAILURE_WARNING1_STR, session, response); \
  }                                                                                            \
  else {                                                                                       \
    EXPECT_WARNING(NR_SYNC_FAILURE_WARNING2, NR_SYNC_FAILURE_WARNING2_STR, session, response); \
  }

class NiRFmxNRRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxNRRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxnr_stub_(NiRFmxNR::NewStub(device_server_->InProcessChannel())),
        nirfmxnr_restricted_stub_(NiRFmxNRRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxNRRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxNR::Stub>& stub()
  {
    return nirfmxnr_stub_;
  }

  std::unique_ptr<NiRFmxNRRestricted::Stub>& restricted_stub()
  {
    return nirfmxnr_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxNR::Stub> nirfmxnr_stub_;
  std::unique_ptr<NiRFmxNRRestricted::Stub> nirfmxnr_restricted_stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, resource_name, options);
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

TEST_F(NiRFmxNRRestrictedDriverApiTests, DLModAccContiguousMultiCarrierFromExample_ModAccFetchTransientPeriodLocationsTrace_ResponseLooksReasonable)
{
  const auto MAX_SELECTOR_STRING = 256;
  const auto NUMBER_OF_COMPONENT_CARRIERS = 2;
  char carrierString[MAX_SELECTOR_STRING];
  std::vector<float64> componentCarrierFrequency{-49.98e6, 50.01e6};
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10.0e6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXNR_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 3.5e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_digital_edge_trigger(stub(), session, "", DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0, DIGITAL_EDGE_TRIGGER_EDGE_RISING, 0.0, false));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_LINK_DIRECTION, NIRFMXNR_INT32_LINK_DIRECTION_DOWNLINK));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE, NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1));
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER, 15e3));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE, NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY, -1));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS, NUMBER_OF_COMPONENT_CARRIERS));
  const auto subblock_string_response = EXPECT_SUCCESS(session, client::build_subblock_string(stub(), "", 0));
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    const auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i));
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

  ModAccFetchTransientPeriodLocationsTraceResponse mod_acc_fetch_transient_period_locations_trace_response[NUMBER_OF_COMPONENT_CARRIERS];
  for (int i = 0; i < NUMBER_OF_COMPONENT_CARRIERS; i++) {
    const auto carrier_string_response = EXPECT_SUCCESS(session, client::build_carrier_string(stub(), subblock_string_response.selector_string_out(), i));
    mod_acc_fetch_transient_period_locations_trace_response[i] = restricted_client::mod_acc_fetch_transient_period_locations_trace(restricted_stub(), session, carrier_string_response.selector_string_out(), 10.000000);
    EXPECT_NR_SYNC_FAILURE_WARNING(session, mod_acc_fetch_transient_period_locations_trace_response[i]);
    
    EXPECT_EQ(0.0, mod_acc_fetch_transient_period_locations_trace_response[i].x0());
    EXPECT_EQ(0.0, mod_acc_fetch_transient_period_locations_trace_response[i].dx());
    EXPECT_EQ(0, mod_acc_fetch_transient_period_locations_trace_response[i].transient_period_locations_size());
    EXPECT_EQ(0, mod_acc_fetch_transient_period_locations_trace_response[i].transient_period_locations().size());
  }
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
