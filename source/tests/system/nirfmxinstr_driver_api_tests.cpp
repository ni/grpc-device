#include <gmock/gmock.h>
#include <gtest/gtest.h>  // For EXPECT matchers.

#include "device_server.h"
#include "niRFmxInstr.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfmxinstr_grpc;
namespace client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;
namespace specan_client = nirfmxspecan_grpc::experimental::client;
namespace pb = google::protobuf;

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

class NiRFmxInstrDriverApiTests : public Test {
 protected:
  NiRFmxInstrDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxInstr::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxInstrDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxInstr::Stub>& stub() const
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

  // Some APIs (GetAttribute) require you Initate/Commit the session. Use an arbitrary SpecAn measurement type
  // to enter this state.
  void initiate_to_enter_committed_state(const nidevice_grpc::Session& session)
  {
    auto specan_stub = create_stub<nirfmxspecan_grpc::NiRFmxSpecAn>();
    EXPECT_SUCCESS(session, specan_client::select_measurements(specan_stub, session, "", nirfmxspecan_grpc::MeasurementTypes::MEASUREMENT_TYPES_CHP, true));
    EXPECT_SUCCESS(session, specan_client::initiate(specan_stub, session, "", ""));
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxInstr::Stub> stub_;
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
  EXPECT_SUCCESS(response);
  return session;
}

TEST_F(NiRFmxInstrDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  // Don't check_error because this can report stale errors from previous tests.
  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASession_SelfTest_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  const auto rfsa_response = client::get_nirfsa_session(stub(), session);
  EXPECT_SUCCESS(session, rfsa_response);

  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  ni::tests::system::EXPECT_SUCCESS(nirfsa_client::self_test(rfsa_stub, rfsa_response.ni_rfsa_session()));
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromNIRFSA_SelfCalibrate_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = nirfsa_client::init_with_options(rfsa_stub, "Sim", false, false, "Simulate=1, DriverSetup=Model:5663E");
  ni::tests::system::EXPECT_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  client::self_calibrate(stub(), session, "", 0);
}

TEST_F(NiRFmxInstrDriverApiTests, NoActiveList_GetListNames_ReturnsEmptyLists)
{
  const auto session = init_session(stub(), PXI_5663E);

  const auto response = client::get_list_names(stub(), session, "", 0);

  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(response.list_names(), IsEmpty());
  EXPECT_THAT(response.personality(), IsEmpty());
}

TEST_F(NiRFmxInstrDriverApiTests, SetAndGetTuningSpeed_ReturnsTuningSpeed)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED, NiRFmxInstrInt32AttributeValues::NIRFMXINSTR_INT32_TUNING_SPEED_FAST));
  initiate_to_enter_committed_state(session);
  const auto response = client::get_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(response.attr_val(), NiRFmxInstrInt32AttributeValues::NIRFMXINSTR_INT32_TUNING_SPEED_FAST);
}

TEST_F(NiRFmxInstrDriverApiTests, SetAndGetFrequencyReferenceSource_ReturnsFrequencyReferenceSource)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_FREQUENCY_REFERENCE_SOURCE, NiRFmxInstrStringAttributeValuesMapped::NIRFMXINSTR_STRING_FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK));
  initiate_to_enter_committed_state(session);
  const auto response = client::get_attribute_string(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_FREQUENCY_REFERENCE_SOURCE);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(response.attr_val(), "OnboardClock");
}

TEST_F(NiRFmxInstrDriverApiTests, GetModelName_ReturnsModelName)
{
  const auto session = init_session(stub(), PXI_5663E);
  const auto response = client::get_attribute_string(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_INSTRUMENT_MODEL);

  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(response.attr_val(), "NI PXIe-5663E");
}

TEST_F(NiRFmxInstrDriverApiTests, TimestampFromValuesRoundTrip_SucceedsWithOriginalValues)
{
  constexpr auto UNIX_TIMESTAMP = 10000;
  constexpr auto FRACTIONAL_SECONDS = .75;
  const auto timestamp_response = client::timestamp_from_values(stub(), UNIX_TIMESTAMP, FRACTIONAL_SECONDS);
  const auto values_response = client::values_from_timestamp(stub(), timestamp_response.timestamp());

  ni::tests::system::EXPECT_SUCCESS(timestamp_response);
  ni::tests::system::EXPECT_SUCCESS(values_response);
  EXPECT_EQ(UNIX_TIMESTAMP, values_response.seconds_since1970());
  EXPECT_NEAR(FRACTIONAL_SECONDS, values_response.fractional_seconds(), .001);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
