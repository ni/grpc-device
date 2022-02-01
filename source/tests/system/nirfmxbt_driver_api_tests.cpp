#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxBT.h"
#include "nirfmxbt/nirfmxbt_client.h"
#include "nirfmxbt/nirfmxbt_service.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfmxbt_grpc;
namespace client = nirfmxbt_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(0, response.status());
}

class NiRFmxBTDriverApiTests : public Test {
 protected:
  NiRFmxBTDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxBT::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxBTDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxBT::Stub>& stub() const
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

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxBT::Stub> stub_;
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
  EXPECT_SUCCESS(response);
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

TEST_F(NiRFmxBTDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxBTDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
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

TEST_F(NiRFmxBTDriverApiTests, AcpBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0.0, 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQPowerEdgeTriggerSlope::IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TriggerMinimumQuietTimeMode::TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 100e-6, IQPowerEdgeTriggerLevelType::IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, Boolean::BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_packet_type(stub(), session, "", PacketType::PACKET_TYPE_DH1));
  EXPECT_SUCCESS(session, client::cfg_data_rate(stub(), session, "", 1000000));
  EXPECT_SUCCESS(session, client::cfg_payload_length(stub(), session, "", PayloadLengthMode::PAYLOAD_LENGTH_MODE_AUTO, 10));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_ACP, Boolean::BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::acp_cfg_burst_synchronization_type(stub(), session, "", AcpBurstSynchronizationType::ACP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE));
  EXPECT_SUCCESS(session, client::acp_cfg_averaging(stub(), session, "", AcpAveragingEnabled::ACP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::acp_cfg_offset_channel_mode(stub(), session, "", AcpOffsetChannelMode::ACP_OFFSET_CHANNEL_MODE_SYMMETRIC));
  EXPECT_SUCCESS(session, client::acp_cfg_number_of_offsets(stub(), session, "", 5));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  auto reference_channel_power = client::acp_fetch_reference_channel_power(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, reference_channel_power);
  auto measurement_response = client::acp_fetch_offset_measurement_array(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, measurement_response);
  auto mask_trace = client::acp_fetch_mask_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, mask_trace);
  auto absolute_power_trace = client::acp_fetch_absolute_power_trace(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, absolute_power_trace);
  auto fetched_spectrum = client::acp_fetch_spectrum(stub(), session, "", 10.0);
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

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni