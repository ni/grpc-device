#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nitclk/nitclk_client.h"

using namespace nirfsg_grpc;
namespace client = nirfsg_grpc::experimental::client;
namespace nitclk_client = nitclk_grpc::experimental::client;
using namespace ::testing;

namespace nidevice_grpc {
// Needs to be in the nidevice_grpc namespace for googletest to find this
// because of argument-dependent lookup - see
// https://stackoverflow.com/questions/33371088/how-to-get-a-custom-operator-to-work-with-google-test
bool operator==(const NIComplexNumber& first, const NIComplexNumber& second)
{
  return first.real() == second.real() && first.imaginary() == second.imaginary();
}
}  // namespace nidevice_grpc

namespace ni {
namespace tests {
namespace system {

const auto PXI_5652 = "5652";
const auto PXI_5820 = "5820";
const auto PXI_5841 = "5841";
const auto IVI_ATTRIBUTE_NOT_SUPPORTED_ERROR = 0xBFFA0012;

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

  std::unique_ptr<nitclk_grpc::NiTClk::Stub> create_tclk_stub() const
  {
    return nitclk_grpc::NiTClk::NewStub(device_server_->InProcessChannel());
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
    if (response.status() != krfsgDriverApiSuccess) {
      auto error_message_response = client::error_message(stub(), session, response.status());
      EXPECT_EQ("", std::string(error_message_response.error_message().c_str()));
    }
    check_error(session);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFSG::Stub> nirfsg_stub_;
};

InitWithOptionsResponse init(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::init_with_options(stub, resource_name, false, false, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model, const std::string& resource_name)
{
  auto response = init(stub, model, resource_name);
  auto session = response.vi();
  EXPECT_SUCCESS(response);
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
}

TEST_F(NiRFSGDriverApiTests, PerformSelfTest_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::self_test(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_EQ("Passed", response.self_test_message());
}

TEST_F(NiRFSGDriverApiTests, PerformReset_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto response = client::reset(stub(), session);
  EXPECT_SUCCESS(session, response);
  EXPECT_EQ(0, response.status());
}

void WaitForAndAssertGenerationStarted(const client::StubPtr& stub, const nidevice_grpc::Session& session)
{
  int retries = 0;
  while (retries < 100) {
    auto check_status = client::check_generation_status(stub, session);
    EXPECT_SUCCESS(check_status);
    if (!check_status.is_done()) {
      return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    retries++;
  }
  EXPECT_TRUE(false);
}

TEST_F(NiRFSGDriverApiTests, GettingStartedSingleToneGenerationFromExample_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto initiate = client::initiate(stub(), session);

  WaitForAndAssertGenerationStarted(stub(), session);

  // change frequency
  auto abort = client::abort(stub(), session);
  auto configure_rf2 = client::configure_rf(stub(), session, 1.5e9, -5);
  auto initiate2 = client::initiate(stub(), session);

  WaitForAndAssertGenerationStarted(stub(), session);

  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, abort);
  EXPECT_SUCCESS(session, configure_rf2);
  EXPECT_SUCCESS(session, initiate2);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, GenerateAndRouteReferenceClockFromExample_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto configure_generation_mode = client::configure_generation_mode(stub(), session, GenerationMode::GENERATION_MODE_CW);
  auto configure_clock = client::configure_ref_clock(stub(), session, RefClockSource::REF_CLOCK_SOURCE_ONBOARD_CLOCK, 10e6);
  auto initiate = client::initiate(stub(), session);

  WaitForAndAssertGenerationStarted(stub(), session);

  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, configure_generation_mode);
  EXPECT_SUCCESS(session, configure_clock);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, ConfigureDigitalEdgeStartTrigger_Succeeds)
{
  auto session = init_session(stub(), PXI_5841);
  auto response = client::configure_digital_edge_start_trigger(
      stub(),
      session,
      TriggerSource::TRIGGER_SOURCE_PXI_TRIG0,
      DigitalEdgeEdge::DIGITAL_EDGE_EDGE_RISING_EDGE);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSGDriverApiTests, ReconfigureExportedRefClockOutTerminal_UpdatesRefClockSuccessfully)
{
  auto session = init_session(stub(), PXI_5652);
  auto initial_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);
  auto set_response = client::set_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL,
      NiRFSGStringAttributeValuesMapped::NIRFSG_STRING_REF_CLOCK_OUTPUT_TERM_REF_OUT);
  auto get_response = client::get_attribute_vi_string(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL);

  EXPECT_SUCCESS(session, initial_response);
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_NE(initial_response.value(), get_response.value());
  EXPECT_EQ("RefOut", get_response.value());
}

TEST_F(NiRFSGDriverApiTests, SetAutomaticThermalCorrection_UpdatesSuccessfully)
{
  auto session = init_session(stub(), PXI_5652);
  auto initial_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION);
  auto set_response = client::set_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION,
      NiRFSGInt32AttributeValues::NIRFSG_INT32_ENABLE_VALUES_DISABLE);
  auto get_response = client::get_attribute_vi_int32(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_AUTOMATIC_THERMAL_CORRECTION);

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
      OutputSignal::OUTPUT_SIGNAL_PFI0);

  EXPECT_SUCCESS(session, response);
}

TEST_F(NiRFSGDriverApiTests, DisableIQImpairment_IQImpairmentIsDisabled)
{
  auto session = init_session(stub(), PXI_5841);
  auto initial_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED);
  auto set_response = client::set_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED,
      false);
  auto get_response = client::get_attribute_vi_boolean(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_IMPAIRMENT_ENABLED);

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
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_RATE);
  auto set_response = client::set_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_RATE,
      NEW_RATE);
  auto get_response = client::get_attribute_vi_real64(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_RATE);

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
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE);
  auto set_response = client::set_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE,
      NEW_VALUE);
  auto get_response = client::get_attribute_vi_int64(
      stub(),
      session,
      "",
      NiRFSGAttribute::NIRFSG_ATTRIBUTE_HOST_DMA_BUFFER_SIZE);

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
  auto parameter1 = nidevice_grpc::NIComplexNumber();
  parameter1.set_real(1.0);
  parameter1.set_imaginary(-1.0);
  auto parameter2 = nidevice_grpc::NIComplexNumber();
  parameter2.set_real(-0.5);
  parameter2.set_imaginary(0.5);
  auto parameter3 = nidevice_grpc::NIComplexNumber();
  parameter3.set_real(0.0);
  parameter3.set_imaginary(1.0);
  auto parameter4 = nidevice_grpc::NIComplexNumber();
  parameter4.set_real(-1.0);
  parameter4.set_imaginary(0.0);
  std::vector<nidevice_grpc::NIComplexNumber> parameters = {parameter1, parameter2, parameter3, parameter4};
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

TEST_F(NiRFSGDriverApiTests, WriteArbWaveformI16_Succeeds)
{
  auto session = init_session(stub(), PXI_5841);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto configure_generation_mode = client::configure_generation_mode(stub(), session, GenerationMode::GENERATION_MODE_ARB_WAVEFORM);
  auto configure_power_level_type = client::configure_power_level_type(stub(), session, PowerLevelType::POWER_LEVEL_TYPE_PEAK_POWER);
  auto point1 = nidevice_grpc::NIComplexI16();
  point1.set_real(INT16_MAX);
  point1.set_imaginary(INT16_MIN);
  auto point2 = nidevice_grpc::NIComplexI16();
  point2.set_real(0);
  point2.set_imaginary(0);
  auto point3 = nidevice_grpc::NIComplexI16();
  point3.set_real(INT16_MIN);
  point3.set_imaginary(INT16_MAX);
  auto point4 = nidevice_grpc::NIComplexI16();
  point4.set_real(0);
  point4.set_imaginary(0);
  std::vector<nidevice_grpc::NIComplexI16> waveform = {point1, point2, point3, point4};
  auto write_waveform = client::write_arb_waveform_complex_i16(stub(), session, "waveform", waveform);
  auto initiate = client::initiate(stub(), session);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  auto check_status = client::check_generation_status(stub(), session);
  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, configure_generation_mode);
  EXPECT_SUCCESS(session, configure_power_level_type);
  EXPECT_SUCCESS(session, write_waveform);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, check_status);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, WriteArbWaveformF32_Succeeds)
{
  auto session = init_session(stub(), PXI_5820);
  auto configure_generation_mode = client::configure_generation_mode(stub(), session, GenerationMode::GENERATION_MODE_ARB_WAVEFORM);
  auto configure_power_level_type = client::configure_power_level_type(stub(), session, PowerLevelType::POWER_LEVEL_TYPE_PEAK_POWER);
  auto configure_iq_port_level = client::set_attribute_vi_real64(stub(), session, "", NiRFSGAttribute::NIRFSG_ATTRIBUTE_IQ_OUT_PORT_LEVEL, 0.2);
  auto configure_gain = client::set_attribute_vi_real64(stub(), session, "", NiRFSGAttribute::NIRFSG_ATTRIBUTE_ARB_PRE_FILTER_GAIN, -20);
  auto point1 = nidevice_grpc::NIComplexNumberF32();
  point1.set_real(0.7f);
  point1.set_imaginary(-0.7f);
  auto point2 = nidevice_grpc::NIComplexNumberF32();
  point2.set_real(0);
  point2.set_imaginary(1.0);
  auto point3 = nidevice_grpc::NIComplexNumberF32();
  point3.set_real(-0.7f);
  point3.set_imaginary(0.7f);
  auto point4 = nidevice_grpc::NIComplexNumberF32();
  point4.set_real(-1.0);
  point4.set_imaginary(0);
  auto point5 = nidevice_grpc::NIComplexNumberF32();
  point5.set_real(1.0);
  point5.set_imaginary(0);
  auto point6 = nidevice_grpc::NIComplexNumberF32();
  point6.set_real(0);
  point6.set_imaginary(-1.0f);
  auto point7 = nidevice_grpc::NIComplexNumberF32();
  point7.set_real(0.7f);
  point7.set_imaginary(0.7f);
  auto point8 = nidevice_grpc::NIComplexNumberF32();
  point8.set_real(-0.7f);
  point8.set_imaginary(-0.7f);
  std::vector<nidevice_grpc::NIComplexNumberF32> waveform = {point1, point2, point3, point4, point5, point6, point7, point8};
  auto write_waveform = client::write_arb_waveform_complex_f32(stub(), session, "waveform", waveform, false);
  auto initiate = client::initiate(stub(), session);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  auto check_status = client::check_generation_status(stub(), session);
  auto disable_output = client::configure_output_enabled(stub(), session, false);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_generation_mode);
  EXPECT_SUCCESS(session, configure_power_level_type);
  EXPECT_SUCCESS(session, configure_iq_port_level);
  EXPECT_SUCCESS(session, configure_gain);
  EXPECT_SUCCESS(session, write_waveform);
  EXPECT_SUCCESS(session, initiate);
  EXPECT_SUCCESS(session, check_status);
  EXPECT_SUCCESS(session, disable_output);
  EXPECT_SUCCESS(session, close);
}

TEST_F(NiRFSGDriverApiTests, SetUserData_GetUserData_DataMatches)
{
  auto session = init_session(stub(), PXI_5652);
  std::string data = "abc";
  data.push_back('\0');
  data.append("def");
  auto set_response = client::set_user_data(stub(), session, "identifier", data);
  auto get_response = client::get_user_data(stub(), session, "identifier");
  EXPECT_SUCCESS(session, set_response);
  EXPECT_SUCCESS(session, get_response);
  EXPECT_EQ(7, get_response.data().length());
  EXPECT_EQ(data, get_response.data());
}

TEST_F(NiRFSGDriverApiTests, TwoSessions_SetupTclkSyncPulseSenderSynchronization_Succeeds)
{
  auto first_session = init_session(stub(), PXI_5841, "FakeDevice");
  auto second_session = init_session(stub(), PXI_5841, "AnotherFakeDevice");

  auto tclk_stub = create_tclk_stub();
  auto result = nitclk_client::setup_for_sync_pulse_sender_synchronize(tclk_stub, {first_session, second_session}, 0);

  EXPECT_SUCCESS(first_session, result);
}

TEST_F(NiRFSGDriverApiTests, ErrorMessage_ReturnsErrorMessage)
{
  auto session = init_session(stub(), PXI_5652);
  const auto response = client::error_message(stub(), session, IVI_ATTRIBUTE_NOT_SUPPORTED_ERROR);

  EXPECT_SUCCESS(session, response);
  EXPECT_THAT(
      response.error_message(),
      HasSubstr("Attribute or property not supported."));
}
}  // namespace system
}  // namespace tests
}  // namespace ni
