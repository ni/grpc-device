#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxbluetooth/nirfmxbluetooth_client.h"
#include "nirfsa/nirfsa_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace ::testing;
using namespace nirfmxbluetooth_grpc;
namespace client = nirfmxbluetooth_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace nidevice_grpc {
// Needs to be in the nidevice_grpc namespace for googletest to find this
// because of argument-dependent lookup - see
// https://stackoverflow.com/questions/33371088/how-to-get-a-custom-operator-to-work-with-google-test
bool operator==(const NIComplexNumberF32& first, const NIComplexNumber& second)
{
  return first.real() == second.real() && first.imaginary() == second.imaginary();
}
}  // namespace nidevice_grpc

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663E = "5663E";
constexpr auto PREAMBLE_BURST_SYNC_WARNING = 686280;
constexpr auto PREAMBLE_BURST_SYNC_WARNING_STR = "The Preamble Sync failed to detect start of the packet";
constexpr auto TYPE_MISMATCH_ERROR = -380251;
constexpr auto TYPE_MISMATCH_ERROR_STR = "Incorrect data type specified";

class NiRFmxBluetoothDriverApiTests : public Test {
 protected:
  NiRFmxBluetoothDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxBluetooth::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxBluetoothDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxBluetooth::Stub>& stub() const
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
  std::unique_ptr<NiRFmxBluetooth::Stub> stub_;
};

InitializeResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::initialize(stub, "FakeDevice", options);
}

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

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

nidevice_grpc::NIComplexNumber complex_number(
    const double real,
    const double imaginary)
{
  return complex<double, nidevice_grpc::NIComplexNumber>(real, imaginary);
}

TEST_F(NiRFmxBluetoothDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_RESPONSE_SUCCESS(init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxBluetoothDriverApiTests, Init_InitAgain_NewSessionInitializedValuesDiffer)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_RESPONSE_SUCCESS(init_response);
  EXPECT_TRUE(init_response.is_new_session());
  EXPECT_TRUE(init_response.new_session_initialized());

  auto init_response_2 = init(stub(), PXI_5663E);
  EXPECT_RESPONSE_SUCCESS(init_response_2);

  // 'is_new_session' comes from the driver and we expect that to be false since the same resource string and options were used.
  // 'new_session_initialized' should be true here, though, since a new grpc-device session name is used. This indicates when the
  // server calls the driver init method and a new mapping is created between the grpc-device session name and the session handle
  // returned from the driver.
  EXPECT_FALSE(init_response_2.is_new_session());
  EXPECT_TRUE(init_response_2.new_session_initialized());
}

TEST_F(NiRFmxBluetoothDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
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

TEST_F(NiRFmxBluetoothDriverApiTests, AcpBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQPowerEdgeTriggerSlope::IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TriggerMinimumQuietTimeMode::TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQPowerEdgeTriggerLevelType::IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_packet_type(stub(), session, "", PacketType::PACKET_TYPE_DH1));
  EXPECT_SUCCESS(session, client::cfg_data_rate(stub(), session, "", 1000000));
  EXPECT_SUCCESS(session, client::cfg_payload_length(stub(), session, "", PayloadLengthMode::PAYLOAD_LENGTH_MODE_AUTO, 10));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::acp_cfg_burst_synchronization_type(stub(), session, "", AcpBurstSynchronizationType::ACP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", AcpAveragingEnabled::ACP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::acp_cfg_offset_channel_mode(stub(), session, "", AcpOffsetChannelMode::ACP_OFFSET_CHANNEL_MODE_SYMMETRIC));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", 5));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto reference_channel_power = client::acp_fetch_reference_channel_power(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, reference_channel_power);
  const auto measurement_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, measurement_response);
  const auto mask_trace = client::acp_fetch_mask_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, mask_trace);
  const auto absolute_power_trace = client::acp_fetch_absolute_power_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, absolute_power_trace);
  const auto fetched_spectrum = client::acp_fetch_spectrum(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, fetched_spectrum);

  EXPECT_GT(reference_channel_power.reference_channel_power(), 0.0);
  EXPECT_THAT(measurement_response.lower_absolute_power(), Each(Ne(0.0)));
  EXPECT_THAT(measurement_response.upper_absolute_power(), Each(Ne(0.0)));
  EXPECT_THAT(measurement_response.lower_relative_power(), Each(Ne(0.0)));
  EXPECT_THAT(measurement_response.upper_relative_power(), Each(Ne(0.0)));
  EXPECT_GT(measurement_response.actual_array_size(), 0);
  EXPECT_EQ(mask_trace.x0(), 0.0);
  EXPECT_EQ(mask_trace.dx(), 0.0);
  EXPECT_THAT(mask_trace.limit_with_exception_mask(), Each(Ne(0.0)));
  EXPECT_THAT(mask_trace.limit_without_exception_mask(), Each(Ne(0.0)));
  EXPECT_EQ(mask_trace.actual_array_size(), 0);
  EXPECT_GT(absolute_power_trace.x0(), 0.0);
  EXPECT_GT(absolute_power_trace.dx(), 0.0);
  EXPECT_THAT(absolute_power_trace.absolute_power(), Each(Ne(0.0)));
  EXPECT_GT(absolute_power_trace.actual_array_size(), 0);
  EXPECT_GT(fetched_spectrum.x0(), 0.0);
  EXPECT_GT(fetched_spectrum.dx(), 0.0);
  EXPECT_THAT(fetched_spectrum.spectrum(), Each(Ne(0.0)));
  EXPECT_GT(fetched_spectrum.actual_array_size(), 0);
}

TEST_F(NiRFmxBluetoothDriverApiTests, TxpBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.402000e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQPowerEdgeTriggerSlope::IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TriggerMinimumQuietTimeMode::TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQPowerEdgeTriggerLevelType::IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_packet_type(stub(), session, "", PacketType::PACKET_TYPE_DH1));
  EXPECT_SUCCESS(session, client::cfg_data_rate(stub(), session, "", 1000000));
  EXPECT_SUCCESS(session, client::cfg_payload_length(stub(), session, "", PayloadLengthMode::PAYLOAD_LENGTH_MODE_AUTO, 10));
  EXPECT_SUCCESS(session, client::cfg_le_direction_finding(stub(), session, "", DirectionFindingMode::DIRECTION_FINDING_MODE_DISABLED, 160e-6, 1e-6));
  EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_burst_synchronization_type(stub(), session, "", TxpBurstSynchronizationType::TXP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TxpAveragingEnabled::TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  // We expect these actions to produce PREAMBLE_BURST_SYNC_WARNING since the test uses simulated hardware.
  const auto fetched_powers_response = client::txp_fetch_powers(stub(), session, "", 10.0);
  EXPECT_WARNING(PREAMBLE_BURST_SYNC_WARNING, PREAMBLE_BURST_SYNC_WARNING_STR, session, fetched_powers_response);
  const auto fetched_edr_powers_response = client::txp_fetch_edr_powers(stub(), session, "", 10.0);
  EXPECT_WARNING(PREAMBLE_BURST_SYNC_WARNING, PREAMBLE_BURST_SYNC_WARNING_STR, session, fetched_edr_powers_response);
  const auto fetched_lecte_reference_period_powers_response = client::txp_fetch_lecte_reference_period_powers(stub(), session, "", 10.0);
  EXPECT_WARNING(PREAMBLE_BURST_SYNC_WARNING, PREAMBLE_BURST_SYNC_WARNING_STR, session, fetched_lecte_reference_period_powers_response);

  EXPECT_GT(fetched_powers_response.average_power_mean(), 0.0);
  EXPECT_GT(fetched_powers_response.average_power_maximum(), 0.0);
  EXPECT_GT(fetched_powers_response.average_power_minimum(), 0.0);
  EXPECT_GT(fetched_powers_response.peak_to_average_power_ratio_maximum(), 0.0);
}

TEST_F(NiRFmxBluetoothDriverApiTests, ModAccMeasurement_FetchConstellationTrace_ComplexNumberLooksReasonable)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 2.402000e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQPowerEdgeTriggerSlope::IQ_POWER_EDGE_TRIGGER_SLOPE_RISING, -20.0, 0.0, TriggerMinimumQuietTimeMode::TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQPowerEdgeTriggerLevelType::IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, true));
  EXPECT_SUCCESS(session, client::cfg_packet_type(stub(), session, "", PacketType::PACKET_TYPE_2_DH1));
  EXPECT_SUCCESS(session, client::cfg_payload_length(stub(), session, "", PayloadLengthMode::PAYLOAD_LENGTH_MODE_AUTO, 10));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_MODACC, true));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_burst_synchronization_type(stub(), session, "", ModAccBurstSynchronizationType::MODACC_BURST_SYNCHRONIZATION_TYPE_PREAMBLE));
  EXPECT_SUCCESS(session, client::mod_acc_cfg_averaging(stub(), session, "", ModAccAveragingEnabled::MODACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  // We expect this action to produce PREAMBLE_BURST_SYNC_WARNING since the test uses simulated hardware.
  const auto constellation_trace_response = client::mod_acc_fetch_constellation_trace(stub(), session, "", 10.0);
  EXPECT_WARNING(PREAMBLE_BURST_SYNC_WARNING, PREAMBLE_BURST_SYNC_WARNING_STR, session, constellation_trace_response);

  // We expect the results to be empty since the measurement did not complete successfully.
  EXPECT_THAT(constellation_trace_response.constellation(), Each(Eq(complex_number(0.0, 0.0))));
  EXPECT_GT(constellation_trace_response.actual_array_size(), 0);
}

// Note: there aren't any i8 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxBluetoothDriverApiTests, SetAttributeInt8_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i8(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, 1));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_u8(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, 1));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i8_array(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, {1, 0, -1, 0}));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_u8_array(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, {1, 0, 1, 0}));
}

// Note: there aren't any i16 attributes in attributes.py, but this at least exercises the code.
TEST_F(NiRFmxBluetoothDriverApiTests, SetAttributeInt16_ExpectedError)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_i16(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, -400));
  EXPECT_ERROR(
      TYPE_MISMATCH_ERROR, TYPE_MISMATCH_ERROR_STR, session,
      client::set_attribute_u16(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, 400));
}

TEST_F(NiRFmxBluetoothDriverApiTests, SetAndGetAttributeInt32_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED, NiRFmxBluetoothInt32AttributeValues::NIRFMXBLUETOOTH_INT32_TXP_AVERAGING_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto txp_averaging_enabled = GET_ATTR_I32(session, "", NiRFmxBluetoothAttribute::NIRFMXBLUETOOTH_ATTRIBUTE_TXP_AVERAGING_ENABLED);

  EXPECT_EQ(NiRFmxBluetoothInt32AttributeValues::NIRFMXBLUETOOTH_INT32_TXP_AVERAGING_ENABLED_TRUE, txp_averaging_enabled);
}

TEST_F(NiRFmxBluetoothDriverApiTests, ConfigureTwentydBBandwidth_FetchMeasurements_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_TWENTY_DB_BANDWIDTH, true));
  EXPECT_SUCCESS(session, client::twentyd_b_bandwidth_cfg_averaging(stub(), session, "", TwentydBBandwidthAveragingEnabled::TWENTY_DB_BANDWIDTH_AVERAGING_ENABLED_FALSE, 10));

  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  const auto fetch_measurement_response = EXPECT_SUCCESS(session, client::twentyd_b_bandwidth_fetch_measurement(stub(), session, "", 10.0));
  const auto fetch_spectrum_response = EXPECT_SUCCESS(session, client::twentyd_b_bandwidth_fetch_spectrum(stub(), session, "", 10.0));

  EXPECT_NE(0.0, fetch_measurement_response.low_frequency());
  EXPECT_NE(0.0, fetch_measurement_response.peak_power());
  EXPECT_THAT(fetch_spectrum_response.spectrum(), Not(IsEmpty()));
  EXPECT_THAT(fetch_spectrum_response.spectrum(), Each(Ne(0.0)));
}

TEST_F(NiRFmxBluetoothDriverApiTests, BuildSlotString_ReturnsSlotString)
{
  const auto slot_string_response = client::build_slot_string(stub(), "", 25);

  EXPECT_EQ(slot_string_response.selector_string_out(), "slot25");
  EXPECT_RESPONSE_SUCCESS(slot_string_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
