#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfsa/nirfsa_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxinstr_grpc;
namespace client = nirfmxinstr_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;
namespace specan_client = nirfmxspecan_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663 = "5663";
constexpr auto PXI_5663E = "5663E";

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

nirfsa_grpc::InitWithOptionsResponse init_rfsa(const nirfsa_client::StubPtr& stub, const std::string& resource_name)
{
  return nirfsa_client::init_with_options(stub, resource_name, false, false, "Simulate=1, DriverSetup=Model:5663E");
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.instrument();
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

::grpc::Status get_rfsa_session_array(const client::StubPtr& stub, const nidevice_grpc::Session& session, const std::vector<std::string>& session_names, GetNIRFSASessionArrayResponse& response)
{
  auto request = GetNIRFSASessionArrayRequest{};

  for (const auto& name : session_names) {
    request.add_session_names(name);
  }
  request.mutable_instrument()->CopyFrom(session);
  ::grpc::ClientContext context;
  // Note: this can't use the experimental::client APIs, because those omit the session name
  // for simplicity (for most cases that we test).
  return stub->GetNIRFSASessionArray(&context, request, &response);
}

void EXPECT_GET_RFSA_ARRAY_WRONG_NUMBER_OF_SESSIONS_ERROR(const ::grpc::Status& actual_status, size_t expected_number_of_sessions)
{
  EXPECT_EQ(::grpc::INVALID_ARGUMENT, actual_status.error_code());
  std::stringstream stream;
  stream << "Number of session_names must be zero or match actual array size (" << expected_number_of_sessions << ").";
  EXPECT_EQ(stream.str(), actual_status.error_message());
}

nidevice_grpc::Session init_from_rfsa_session_array(const client::StubPtr& stub, const nirfsa_client::StubPtr& rfsa_stub, const std::vector<std::string>& rfsa_resource_names)
{
  auto rfsa_sessions = std::vector<nidevice_grpc::Session>{};
  for (const auto& resource_name : rfsa_resource_names) {
    auto init_rfsa_response = init_rfsa(rfsa_stub, resource_name);
    EXPECT_RESPONSE_SUCCESS(init_rfsa_response);
    rfsa_sessions.push_back(init_rfsa_response.vi());
  }

  auto init_response = client::initialize_from_nirfsa_session_array(stub, rfsa_sessions);
  auto session = init_response.instrument();
  EXPECT_RESPONSE_SUCCESS(init_response);
  return session;
}

TEST_F(NiRFmxInstrDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  // Don't use EXPECT_STATUS because that checks the error text, which can report stale errors from
  // previous tests.
  EXPECT_RESPONSE_SUCCESS(close_response);
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASession_SelfTest_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  const auto rfsa_response = EXPECT_SUCCESS(session, client::get_nirfsa_session(stub(), session));

  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  EXPECT_RESPONSE_SUCCESS(nirfsa_client::self_test(rfsa_stub, rfsa_response.nirfsa_session()));
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASessionArrayAnonymous_SelfTest_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  const auto get_rfsa_response = EXPECT_SUCCESS(session, client::get_nirfsa_session_array(stub(), session));

  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  EXPECT_RESPONSE_SUCCESS(nirfsa_client::self_test(rfsa_stub, get_rfsa_response.nirfsa_sessions()[0]));
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASessionArrayNamed_SelfTest_Succeeds)
{
  constexpr auto RFSA_SESSION_NAME = "test_rfsa_session";
  auto session = init_session(stub(), PXI_5663E);

  auto get_rfsa_response = GetNIRFSASessionArrayResponse{};
  const auto status = get_rfsa_session_array(stub(), session, {RFSA_SESSION_NAME}, get_rfsa_response);
  EXPECT_SUCCESS(session, get_rfsa_response);

  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto rfsa_named_session = nidevice_grpc::Session{};
  rfsa_named_session.set_name(RFSA_SESSION_NAME);
  EXPECT_RESPONSE_SUCCESS(nirfsa_client::self_test(rfsa_stub, rfsa_named_session));
}

TEST_F(NiRFmxInstrDriverApiTests, GetNIRFSASessionArrayWithTooManyNames_ReturnsBadStatus)
{
  auto session = init_session(stub(), PXI_5663E);

  auto get_rfsa_response = GetNIRFSASessionArrayResponse{};
  const auto status = get_rfsa_session_array(stub(), session, {"rfsa_1", "one_too_many"}, get_rfsa_response);

  EXPECT_GET_RFSA_ARRAY_WRONG_NUMBER_OF_SESSIONS_ERROR(status, 1);
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromNIRFSA_SelfCalibrate_Succeeds)
{
  auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  auto init_rfsa_response = init_rfsa(rfsa_stub, "Sim");
  EXPECT_RESPONSE_SUCCESS(init_rfsa_response);
  auto init_response = client::initialize_from_nirfsa_session(stub(), init_rfsa_response.vi());
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  EXPECT_SUCCESS(session, client::self_calibrate(stub(), session, "", 0));
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromNIRFSAArray_SelfCalibrate_Succeeds)
{
  const auto session = init_from_rfsa_session_array(stub(), create_stub<nirfsa_grpc::NiRFSA>(), {"Sim1", "Sim2"});

  EXPECT_SUCCESS(session, client::self_calibrate(stub(), session, "", 0));
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromTwoRFSASessions_GetNIRFSASessionArrayAnonymous_SelfTestEachSessionSucceeds)
{
  const auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  const auto session = init_from_rfsa_session_array(stub(), rfsa_stub, {"Sim1", "Sim2"});

  const auto get_rfsa_response = client::get_nirfsa_session_array(stub(), session);
  EXPECT_SUCCESS(session, get_rfsa_response);

  EXPECT_EQ(2, get_rfsa_response.nirfsa_sessions_size());
  for (const auto& session : get_rfsa_response.nirfsa_sessions()) {
    EXPECT_RESPONSE_SUCCESS(nirfsa_client::self_test(rfsa_stub, session));
  }
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromTwoRFSASessions_GetNIRFSASessionArrayWithTooFewNames_ReturnsBadStatus)
{
  const auto session = init_from_rfsa_session_array(stub(), create_stub<nirfsa_grpc::NiRFSA>(), {"Sim1", "Sim2"});

  auto get_rfsa_response = GetNIRFSASessionArrayResponse{};
  const auto status = get_rfsa_session_array(stub(), session, {"rfsa_1"}, get_rfsa_response);

  EXPECT_GET_RFSA_ARRAY_WRONG_NUMBER_OF_SESSIONS_ERROR(status, 2);
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromTwoRFSASessions_GetNIRFSASessionArrayWithTooManyNames_ReturnsBadStatus)
{
  const auto session = init_from_rfsa_session_array(stub(), create_stub<nirfsa_grpc::NiRFSA>(), {"Sim1", "Sim2"});

  auto get_rfsa_response = GetNIRFSASessionArrayResponse{};
  const auto status = get_rfsa_session_array(stub(), session, {"rfsa_1", "rfsa_2", "rfsa_one_too_many"}, get_rfsa_response);

  EXPECT_GET_RFSA_ARRAY_WRONG_NUMBER_OF_SESSIONS_ERROR(status, 2);
}

TEST_F(NiRFmxInstrDriverApiTests, InitializeFromTwoRFSASessions_GetNIRFSASessionArrayNamed_ReturnsTwoSessions)
{
  const auto RFSA_SESSION_NAMES = std::vector<std::string>{"rfsa_1", "rfsa_2"};
  const auto rfsa_stub = create_stub<nirfsa_grpc::NiRFSA>();
  const auto session = init_from_rfsa_session_array(stub(), rfsa_stub, {"Sim1", "Sim2"});

  auto get_rfsa_response = GetNIRFSASessionArrayResponse{};
  const auto status = get_rfsa_session_array(stub(), session, RFSA_SESSION_NAMES, get_rfsa_response);

  EXPECT_EQ(::grpc::OK, status.error_code());
  EXPECT_EQ(2, get_rfsa_response.nirfsa_sessions_size());
  for (const auto& session_name : RFSA_SESSION_NAMES) {
    auto session = nidevice_grpc::Session{};
    session.set_name(session_name);
    EXPECT_RESPONSE_SUCCESS(nirfsa_client::self_test(rfsa_stub, session));
  }
}

TEST_F(NiRFmxInstrDriverApiTests, NoActiveList_GetListNames_ReturnsEmptyLists)
{
  const auto session = init_session(stub(), PXI_5663E);

  const auto response = EXPECT_SUCCESS(session, client::get_list_names(stub(), session, "", 0));

  EXPECT_THAT(response.list_names(), IsEmpty());
  EXPECT_THAT(response.personality(), IsEmpty());
}

TEST_F(NiRFmxInstrDriverApiTests, SetAndGetTuningSpeed_ReturnsTuningSpeed)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED, NiRFmxInstrInt32AttributeValues::NIRFMXINSTR_INT32_TUNING_SPEED_FAST));
  initiate_to_enter_committed_state(session);
  const auto tuning_speed = GET_ATTR_I32(session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);

  EXPECT_EQ(tuning_speed, NiRFmxInstrInt32AttributeValues::NIRFMXINSTR_INT32_TUNING_SPEED_FAST);
}

TEST_F(NiRFmxInstrDriverApiTests, SetAndGetFrequencyReferenceSource_ReturnsFrequencyReferenceSource)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_FREQUENCY_REFERENCE_SOURCE, NiRFmxInstrStringAttributeValuesMapped::NIRFMXINSTR_STRING_FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK));
  initiate_to_enter_committed_state(session);
  const auto frequency_reference_source = GET_ATTR_STR(session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_FREQUENCY_REFERENCE_SOURCE);

  EXPECT_EQ(frequency_reference_source, "OnboardClock");
}

TEST_F(NiRFmxInstrDriverApiTests, CallCfgMethods_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_mechanical_attenuation(stub(), session, "", MechanicalAttenuationAuto::MECHANICAL_ATTENUATION_AUTO_TRUE, 10.0));
}

TEST_F(NiRFmxInstrDriverApiTests, CallCheckMethods_SucceedsWithReasonableResponseValues)
{
  const auto session = init_session(stub(), PXI_5663E);
  const auto status_response = client::check_acquisition_status(stub(), session);
  EXPECT_SUCCESS(session, status_response);
  const auto list_exists_response = client::check_if_list_exists(stub(), session, "NOTALIST");
  EXPECT_SUCCESS(session, list_exists_response);
  const auto self_cal_response = client::is_self_calibrate_valid(stub(), session, "");
  EXPECT_SUCCESS(session, self_cal_response);

  EXPECT_EQ(status_response.acquisition_done(), true);
  EXPECT_EQ(list_exists_response.list_exists(), false);
  EXPECT_EQ(list_exists_response.personality(), Personality::PERSONALITY_NONE);
  EXPECT_EQ(self_cal_response.self_calibrate_valid(), true);
  EXPECT_THAT(self_cal_response.valid_steps_array(), ElementsAreArray(std::vector<SelfCalStep>{SelfCalStep::SELF_CAL_STEP_DIGITIZER_SELF_CAL}));
}

// Use a mix of RFmxSpecAn and RFmxInstr APIs in an RFmxInstr session.
TEST_F(NiRFmxInstrDriverApiTests, SpectrumBasicWithRFmxInstr_DataLooksReasonable)
{
  auto specan_stub = create_stub<nirfmxspecan_grpc::NiRFmxSpecAn>();
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, specan_client::cfg_rf(specan_stub, session, "", 1e9, 0, 0));
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, specan_client::spectrum_cfg_span(specan_stub, session, "", 1e6));
  EXPECT_SUCCESS(session, specan_client::spectrum_cfg_rbw_filter(specan_stub, session, "", true, 100e3, nirfmxspecan_grpc::SpectrumRbwFilterType::SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, specan_client::spectrum_cfg_averaging(specan_stub, session, "", false, 10, nirfmxspecan_grpc::SpectrumAveragingType::SPECTRUM_AVERAGING_TYPE_RMS));

  auto read_response = EXPECT_SUCCESS(session, specan_client::spectrum_read(specan_stub, session, "", 10.0));

  constexpr auto EXPECTED_SPECTRUM_SIZE = 1005;
  EXPECT_EQ(EXPECTED_SPECTRUM_SIZE, read_response.spectrum().size());
  constexpr auto MIDPOINT_X = EXPECTED_SPECTRUM_SIZE / 2;
  EXPECT_LT(read_response.spectrum(0), read_response.spectrum(MIDPOINT_X));
  EXPECT_LT(read_response.spectrum(EXPECTED_SPECTRUM_SIZE - 1), read_response.spectrum(MIDPOINT_X));
}

TEST_F(NiRFmxInstrDriverApiTests, GetModelName_ReturnsModelName)
{
  const auto session = init_session(stub(), PXI_5663E);
  const auto instrument_model = GET_ATTR_STR(session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_INSTRUMENT_MODEL);

  EXPECT_EQ(instrument_model, "NI PXIe-5663E");
}

TEST_F(NiRFmxInstrDriverApiTests, TimestampFromValuesRoundTrip_SucceedsWithOriginalValues)
{
  constexpr auto UNIX_TIMESTAMP = 10000;
  constexpr auto FRACTIONAL_SECONDS = .75;
  const auto timestamp_response = client::timestamp_from_values(stub(), UNIX_TIMESTAMP, FRACTIONAL_SECONDS);
  const auto values_response = client::values_from_timestamp(stub(), timestamp_response.timestamp());

  EXPECT_RESPONSE_SUCCESS(timestamp_response);
  EXPECT_RESPONSE_SUCCESS(values_response);
  EXPECT_EQ(UNIX_TIMESTAMP, values_response.seconds_since_1970());
  EXPECT_NEAR(FRACTIONAL_SECONDS, values_response.fractional_seconds(), .001);
}

TEST_F(NiRFmxInstrDriverApiTests, BuildPortString_SucceedsWithExpectedValue)
{
  constexpr auto EXPECTED_PORT_STRING = "port::RFSA1/10";
  const auto build_port_string_response = client::build_port_string(stub(), "", "", "RFSA1", 10);

  EXPECT_RESPONSE_SUCCESS(build_port_string_response);
  EXPECT_EQ(EXPECTED_PORT_STRING, build_port_string_response.selector_string_out());
}

TEST_F(NiRFmxInstrDriverApiTests, ExportSignal_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663E);
  auto response = client::export_signal(stub(), session, ExportSignalSource::EXPORT_SIGNAL_SOURCE_ADVANCE_TRIGGER, OutputTerminal::OUTPUT_TERMINAL_PFI0);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFmxInstrDriverApiTests, SetReadyForStartEventOutputTerminal_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663);
  auto response = client::set_attribute_string(
      stub(),
      session,
      "",
      NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_READY_FOR_START_EVENT_OUTPUT_TERMINAL,
      NiRFmxInstrStringAttributeValuesMapped::NIRFMXINSTR_STRING_OUTPUT_TERMINAL_PXI_TRIG0);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFmxInstrDriverApiTests, SetRStartTriggerDigitalEdgeSource_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663);
  auto response = client::set_attribute_string(
      stub(),
      session,
      "",
      NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_START_TRIGGER_DIGITAL_EDGE_SOURCE,
      NiRFmxInstrStringAttributeValuesMapped::NIRFMXINSTR_STRING_DIGITAL_EDGE_TRIGGER_SOURCE_TIMER_EVENT);

  EXPECT_SUCCESS(session, response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
