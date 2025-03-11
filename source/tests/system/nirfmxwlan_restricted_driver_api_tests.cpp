#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxwlan/nirfmxwlan_client.h"
#include "nirfmxwlan_restricted/nirfmxwlan_restricted_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace nirfmxwlan_grpc;
using namespace nirfmxwlan_restricted_grpc;
namespace client = nirfmxwlan_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxwlan_restricted_grpc::experimental::client;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5841 = "5841";

class NiRFmxWLANRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxWLANRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxwlan_stub_(NiRFmxWLAN::NewStub(device_server_->InProcessChannel())),
        nirfmxwlan_restricted_stub_(NiRFmxWLANRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxWLANRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxWLAN::Stub>& stub()
  {
    return nirfmxwlan_stub_;
  }

  std::unique_ptr<NiRFmxWLANRestricted::Stub>& restricted_stub()
  {
    return nirfmxwlan_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxWLAN::Stub> nirfmxwlan_stub_;
  std::unique_ptr<NiRFmxWLANRestricted::Stub> nirfmxwlan_restricted_stub_;
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

void configure_OFDMModAccFromExample(const instr_client::StubPtr& instr_stub, const nidevice_grpc::Session& session, const client::StubPtr& wlan_stub)
{
  EXPECT_RESPONSE_SUCCESS(instr_client::cfg_frequency_reference(instr_stub, session, "", nirfmxinstr_grpc::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_RESPONSE_SUCCESS(client::cfg_frequency(wlan_stub, session, "", 2.412e9));
  EXPECT_RESPONSE_SUCCESS(client::cfg_reference_level(wlan_stub, session, "", 0.0));
  EXPECT_RESPONSE_SUCCESS(client::cfg_external_attenuation(wlan_stub, session, "", 0.0));
  EXPECT_RESPONSE_SUCCESS(client::cfg_iq_power_edge_trigger(wlan_stub, session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_RESPONSE_SUCCESS(client::cfg_standard(wlan_stub, session, "", STANDARD_802_11_AG));
  EXPECT_RESPONSE_SUCCESS(client::cfg_channel_bandwidth(wlan_stub, session, "", 20e06));
  EXPECT_RESPONSE_SUCCESS(client::select_measurements(wlan_stub, session, "", MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_measurement_length(wlan_stub, session, "", 0, 16));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_frequency_error_estimation_method(wlan_stub, session, "", OFDMMODACC_FREQUENCY_ERROR_ESTIMATION_METHOD_PREAMBLE_AND_PILOTS));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_amplitude_tracking_enabled(wlan_stub, session, "", OFDMMODACC_AMPLITUDE_TRACKING_ENABLED_FALSE));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_phase_tracking_enabled(wlan_stub, session, "", OFDMMODACC_PHASE_TRACKING_ENABLED_TRUE));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_symbol_clock_error_correction_enabled(wlan_stub, session, "", OFDMMODACC_SYMBOL_CLOCK_ERROR_CORRECTION_ENABLED_TRUE));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_channel_estimation_type(wlan_stub, session, "", OFDMMODACC_CHANNEL_ESTIMATION_TYPE_REFERENCE));
  EXPECT_RESPONSE_SUCCESS(client::ofdm_mod_acc_cfg_averaging(wlan_stub, session, "", OFDMMODACC_AVERAGING_ENABLED_FALSE, 10));
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
}

TEST_F(NiRFmxWLANRestrictedDriverApiTests, GetChannelListBehavior_ReturnsNonEmptyResult)
{
  const auto session = init_session(stub(), PXI_5841);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto response = restricted_client::get_channel_list(restricted_stub(), session, "", 0);
  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(response.center_frequencies(), Not(IsEmpty()));
  EXPECT_THAT(response.channel_bandwidths(), Not(IsEmpty()));
  EXPECT_GT(response.actual_array_size(), 0);
}

TEST_F(NiRFmxWLANRestrictedDriverApiTests, OFDMModAccFromExample_FetchCommonPilotErrorTradeIndB_ResponseLooksReasonable)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  const auto session = init_session(stub(), PXI_5841);
  configure_OFDMModAccFromExample(instr_stub, session, stub());
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto response = restricted_client::ofdm_mod_acc_fetch_common_pilot_error_trace_ind_b(restricted_stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0.0, response.x0());
  EXPECT_NE(0.0, response.dx());
  EXPECT_THAT(response.common_pilot_error_magnitude(), Not(IsEmpty()));
  EXPECT_THAT(response.common_pilot_error_phase(), Not(IsEmpty()));
}

TEST_F(NiRFmxWLANRestrictedDriverApiTests, OFDMModAccFromExample_NoiseCalibrate_Succeeds)
{
  char* resource_name = "RFSA";
  auto instr_stub = create_stub<nirfmxinstr_grpc::NiRFmxInstr>();
  const auto session = init_session(stub(), PXI_5841);
  configure_OFDMModAccFromExample(instr_stub, session, stub());
  std::vector<float64> center_frequency{2.412e9};
  std::vector<float64> channel_bandwidth{2.0e7};
  // Note that ofdm_mod_acc_noise_calibrate is non-public and requires setup with non-public attributes.
  const auto NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CENTER_FREQUENCIES = 10502272;
  const auto NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CHANNEL_BANDWIDTHS = 10502273;
  EXPECT_SUCCESS(session, client::set_attribute_f64_array(stub(), session, "", (nirfmxwlan_grpc::NiRFmxWLANAttribute)NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CENTER_FREQUENCIES, center_frequency));
  EXPECT_SUCCESS(session, client::set_attribute_f64_array(stub(), session, "", (nirfmxwlan_grpc::NiRFmxWLANAttribute)NIRFMXWLAN_ATTRIBUTE_OFDMMODACC_CHANNEL_BANDWIDTHS, channel_bandwidth));
  
  EXPECT_SUCCESS(session, restricted_client::ofdm_mod_acc_noise_calibrate(restricted_stub(), session, "", 0));

  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
