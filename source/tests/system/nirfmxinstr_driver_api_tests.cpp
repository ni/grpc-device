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

const auto PXI_5663 = "5663";
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
  TResponse EXPECT_SUCCESS(const nidevice_grpc::Session& session, const TResponse& response)
  {
    ni::tests::system::EXPECT_SUCCESS(response);
    check_error(session);
    return response;
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

TEST_F(NiRFmxInstrDriverApiTests, CallCfgMethods_Succeeds)
{
  const auto session = init_session(stub(), PXI_5663E);

  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FrequencyReferenceSource::FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_mechanical_attenuation(stub(), session, "", MechanicalAttenuationAuto::MECHANICAL_ATTENUATION_AUTO_TRUE, 10.0));
}

TEST_F(NiRFmxInstrDriverApiTests, CallCheckMethods_SucceedsWithReasonableResponseValues)
{
  const auto session = init_session(stub(), PXI_5663E);

  const auto status_response = EXPECT_SUCCESS(session, client::check_acquisition_status(stub(), session));
  const auto list_exists_response = EXPECT_SUCCESS(session, client::check_if_list_exists(stub(), session, "NOTALIST"));
  const auto self_cal_response = EXPECT_SUCCESS(session, client::is_self_calibrate_valid(stub(), session, ""));

  EXPECT_EQ(status_response.acquisition_done(), Boolean::BOOLEAN_TRUE);
  EXPECT_EQ(list_exists_response.list_exists(), Boolean::BOOLEAN_FALSE);
  EXPECT_EQ(list_exists_response.personality(), Personality::PERSONALITY_NONE);
  EXPECT_EQ(self_cal_response.self_calibrate_valid(), Boolean::BOOLEAN_TRUE);
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

  auto read_response = specan_client::spectrum_read(specan_stub, session, "", 10.0);

  EXPECT_SUCCESS(session, read_response);
  int midpoint_x = 1005 / 2;
  EXPECT_LT(read_response.spectrum(0), read_response.spectrum(midpoint_x));
  EXPECT_LT(read_response.spectrum(1004), read_response.spectrum(midpoint_x));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
