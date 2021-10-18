#include <gtest/gtest.h>

#include <thread>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nirfsg/nirfsg_service.h"

using namespace nirfsg_grpc;
namespace client = nirfsg_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace nirfsg_grpc {
// Needs to be in the nirfsg_grpc namespace for googletest to find this
// because of argument-dependent lookup - see
// https://stackoverflow.com/questions/33371088/how-to-get-a-custom-operator-to-work-with-google-test
bool operator==(const NIComplexNumber& first, const NIComplexNumber& second)
{
  return first.real() == second.real() && first.imaginary() == second.imaginary();
}
}  // namespace nirfsg_grpc

namespace ni {
namespace tests {
namespace system {

const auto PXI_5652 = "5652";
const auto PXI_5841 = "5841";

const int krfsgDriverApiSuccess = 0;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfsgDriverApiSuccess, response.status());
}

class NiRFSGDriverApiTests : public ::testing::Test {
 protected:
  NiRFSGDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfsg_stub_(NiRFSG::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFSGDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<NiRFSG::Stub>& stub()
  {
    return nirfsg_stub_;
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

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFSG::Stub> nirfsg_stub_;
};

InitWithOptionsResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::init_with_options(stub, "FakeDevice", false, false, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  auto session = response.vi();
  EXPECT_SUCCESS(response);
  return session;
}

TEST_F(NiRFSGDriverApiTests, PerformSelfTest_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::self_test(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_STREQ("Passed", response.self_test_message().c_str());
}

TEST_F(NiRFSGDriverApiTests, PerformReset_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::reset(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.status());
}

TEST_F(NiRFSGDriverApiTests, ConfigureGettingStartedSingleToneGenerationFromExample_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto initiate = client::initiate(stub(), session);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  auto check_status = client::check_generation_status(stub(), session);

  // change frequency
  auto abort = client::abort(stub(), session);
  auto configure_rf2 = client::configure_rf(stub(), session, 1.5e9, -5);
  auto initiate2 = client::initiate(stub(), session);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  auto check_status2 = client::check_generation_status(stub(), session);
  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, check_status);
  EXPECT_SUCCESS(session, abort);
  EXPECT_SUCCESS(session, configure_rf2);
  EXPECT_SUCCESS(session, initiate2);
  EXPECT_SUCCESS(session, check_status2);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, GenerateAndRouteReferenceClockFromExample_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto configure_generation_mode = client::configure_generation_mode(stub(), session, AttrGenerationModeRangeTable::ATTR_GENERATION_MODE_RANGE_TABLE_CW);
  auto configure_clock = client::configure_ref_clock(stub(), session, AttrRefClockSourceRangeTable::ATTR_REF_CLOCK_SOURCE_RANGE_TABLE_ONBOARD_CLOCK_STR, 10e6);
  auto initiate = client::initiate(stub(), session);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  auto check_status = client::check_generation_status(stub(), session);
  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, configure_generation_mode);
  EXPECT_SUCCESS(session, configure_clock);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, check_status);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, ConfigureDigitalEdgeStartTrigger_Succeeds)
{
  auto session = init_session(stub(), PXI_5841);
  auto response = client::configure_digital_edge_start_trigger(
      stub(),
      session,
      AttrTriggerSourceRangeTable::ATTR_TRIGGER_SOURCE_RANGE_TABLE_PXI_TRIG0_STR,
      AttrDigitalEdgeEdgeRangeTable::ATTR_DIGITAL_EDGE_EDGE_RANGE_TABLE_RISING_EDGE);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSGDriverApiTests, ReconfigureExportedRefClockOutTerminal_UpdatesRefClockSuccessfully)
{
  auto session = init_session(stub(), PXI_5652);
  auto initial_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);
  auto set_response = client::set_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL,
      NiRFSGStringAttributeValuesMapped::NIRFSG_STRING_ATTR_REF_CLOCK_OUTPUT_TERM_RANGE_TABLE_REF_OUT_STR);
  auto get_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(NIRFSG_VAL_REF_OUT_STR, get_response.value());
}

TEST_F(NiRFSGDriverApiTests, SetAutomaticThermalCorrection_UpdatesSuccessfully)
{
  auto session = init_session(stub(), PXI_5652);
  auto initial_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION);
  auto set_response = client::set_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION,
      NiRFSGInt32AttributeValues::NIRFSG_INT32_ENABLE_VALUES_DISABLE);
  auto get_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(
      NiRFSGInt32AttributeValues::NIRFSG_INT32_ENABLE_VALUES_DISABLE,
      get_response.value());
}

TEST_F(NiRFSGDriverApiTests, ExportSignal_Succeeds)
{
  auto session = init_session(stub(), PXI_5841);
  auto response = client::export_signal(
      stub(),
      session,
      RoutedSignal::ROUTED_SIGNAL_START_TRIGGER,
      std::string(""),
      OutputSignal::OUTPUT_SIGNAL_PFI0_STR);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSGDriverApiTests, DisableIQImpairment_IQImpairmentIsDisabled)
{
  auto session = init_session(stub(), PXI_5841);
  auto initial_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED);
  auto set_response = client::set_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED,
      false);
  auto get_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_FALSE(get_response.value());
}

TEST_F(NiRFSGDriverApiTests, ReconfigureIQRate_UpdatesIQRateSuccessfully)
{
  auto NEW_RATE = 1.2e6;
  auto session = init_session(stub(), PXI_5841);
  auto initial_response = client::get_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_RATE);
  auto set_response = client::set_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_RATE,
      NEW_RATE);
  auto get_response = client::get_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_IQ_RATE);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_NEAR(NEW_RATE, get_response.value(), .0001);
}

TEST_F(NiRFSGDriverApiTests, SetHostDMABufferSize_UpdatesHostDMABufferSizeSuccessfully)
{
  auto NEW_VALUE = 10 * 1024 * 1024;
  auto session = init_session(stub(), PXI_5841);
  auto initial_response = client::get_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE);
  auto set_response = client::set_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE,
      NEW_VALUE);
  auto get_response = client::get_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSGAttributes::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ(NEW_VALUE, get_response.value());
}

TEST_F(NiRFSGDriverApiTests, GetDeembeddingSParameters_Empty)
{
  auto session = init_session(stub(), PXI_5841);
  auto parameters = client::get_deembedding_sparameters(stub(), session);

  EXPECT_SUCCESS(session, parameters);
  EXPECT_EQ(0, parameters.number_of_sparameters());
  EXPECT_EQ(0, parameters.sparameters_size());
  EXPECT_EQ(0, parameters.sparameters().size());
}

TEST_F(NiRFSGDriverApiTests, SetDeembeddingSParameters_GetDeembeddingSParameters_Match)
{
  auto session = init_session(stub(), PXI_5841);
  std::vector<double> frequencies = {1 * 1000 * 1000 * 1000};
  auto parameter1 = nirfsg_grpc::NIComplexNumber();
  parameter1.set_real(1.0);
  parameter1.set_imaginary(-1.0);
  auto parameter2 = nirfsg_grpc::NIComplexNumber();
  parameter2.set_real(-0.5);
  parameter2.set_imaginary(0.5);
  auto parameter3 = nirfsg_grpc::NIComplexNumber();
  parameter3.set_real(0.0);
  parameter3.set_imaginary(1.0);
  auto parameter4 = nirfsg_grpc::NIComplexNumber();
  parameter4.set_real(-1.0);
  parameter4.set_imaginary(0.0);
  std::vector<nirfsg_grpc::NIComplexNumber> parameters = {parameter1, parameter2, parameter3, parameter4};
  auto set_parameters = client::create_deembedding_sparameter_table_array(
      stub(),
      session,
      "",
      "table",
      frequencies,
      parameters,
      2,
      SParameterOrientation::S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT);
  auto get_parameters = client::get_deembedding_sparameters(stub(), session);

  EXPECT_SUCCESS(session, set_parameters);
  EXPECT_SUCCESS(session, get_parameters);
  EXPECT_EQ(2, get_parameters.number_of_ports());
  EXPECT_EQ(4, get_parameters.sparameters_size());
  EXPECT_EQ(4, get_parameters.sparameters().size());
  EXPECT_EQ(parameter1, get_parameters.sparameters(0));
  EXPECT_EQ(parameter1, get_parameters.sparameters()[0]);
  EXPECT_EQ(parameter2, get_parameters.sparameters(1));
  EXPECT_EQ(parameter2, get_parameters.sparameters()[1]);
  EXPECT_EQ(parameter3, get_parameters.sparameters(2));
  EXPECT_EQ(parameter3, get_parameters.sparameters()[2]);
  EXPECT_EQ(parameter4, get_parameters.sparameters(3));
  EXPECT_EQ(parameter4, get_parameters.sparameters()[3]);
}
}  // namespace system
}  // namespace tests
}  // namespace ni