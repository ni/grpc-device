#include <gtest/gtest.h>

#include "device_server.h"
#include "niRFmxWLAN.h"
#include "nirfmxwlan/nirfmxwlan_client.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfmxwlan_grpc;
namespace client = nirfmxwlan_grpc::experimental::client;
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

class NiRFmxWLANDriverApiTests : public Test {
 protected:
  NiRFmxWLANDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxWLAN::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxWLANDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxWLAN::Stub>& stub() const
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
  std::unique_ptr<NiRFmxWLAN::Stub> stub_;
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

TEST_F(NiRFmxWLANDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  ni::tests::system::EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFmxWLANDriverApiTests, InitializeFromNIRFSA_Close_Succeeds)
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

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_DSSSModAccFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_DSSSPowerRampFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFSGSession" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_FEMTestWithAutomaticSGSASharedLOFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccEVMNoiseCompensationFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccMIMOFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "ReadWaveformsFromTDMSFile" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccMIMOAnalysisOnlyFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccSpeedOptimizedFromExample_FetchData_DataLooksReasonable)
{
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccTriggerBasedPPDUFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxWLANDriverApiTests, OFDMModAccTXPCompositeFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP|MEASUREMENT_TYPES_OFDMMODACC, true));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_measurement_length(stub(), session, "", 0, 16));
  EXPECT_SUCCESS(session, client::ofdm_mod_acc_cfg_averaging(stub(), session, "", OFDM_MOD_ACC_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  OFDMModAccFetchCompositeRMSEVMResponse ofdm_mod_acc_fetch_composite_rmsevm_response;
  TXPFetchMeasurementResponse txp_fetch_measurement_response;
  ofdm_mod_acc_fetch_composite_rmsevm_response = client::ofdm_mod_acc_fetch_composite_rmsevm(stub(), session, "", 10.0);
  txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, ofdm_mod_acc_fetch_composite_rmsevm_response);
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_rmsevm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_data_rmsevm_mean());
  EXPECT_EQ(0.0, ofdm_mod_acc_fetch_composite_rmsevm_response.composite_pilot_rmsevm_mean());
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_OFDMModAccWithEVMBasedAutoLevelFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxWLANDriverApiTests, SemFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_STANDARD));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_span(stub(), session, "", SEM_SPAN_AUTO_TRUE, 66.0e6));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 arraySize = 0;
  SEMFetchMeasurementStatusResponse sem_fetch_measurement_status_response;
  SEMFetchCarrierMeasurementResponse sem_fetch_carrier_measurement_response;
  SEMFetchLowerOffsetMarginArrayResponse sem_fetch_lower_offset_margin_array_response;
  SEMFetchUpperOffsetMarginArrayResponse sem_fetch_upper_offset_margin_array_response;
  SEMFetchSpectrumResponse sem_fetch_spectrum_response;
  sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, "", 10.0);
  sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.relative_power());
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

TEST_F(NiRFmxWLANDriverApiTests, SEMCustomMaskFromExample_FetchData_DataLooksReasonable)
{
  const auto NUMBER_OF_OFFSETS = 3;
  std::vector<float64> offsetStartFrequency {9e06, 11e06, 20e06};
  std::vector<float64> offsetStopFrequency {11e06, 20e06, 40e06};
  std::vector<int> offsetSideband {RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH, RFMXWLAN_VAL_SEM_OFFSET_SIDEBAND_BOTH};
  std::vector<float64> relativeLimitStart {0.0, -20.0, -28.0};
  std::vector<float64> relativeLimitStop {-20.0, -28.0, -40.0};
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_SEM, true));
  EXPECT_SUCCESS(session, client::sem_cfg_mask_type(stub(), session, "", SEM_MASK_TYPE_CUSTOM));
  EXPECT_SUCCESS(session, client::sem_cfg_averaging(stub(), session, "", SEM_AVERAGING_ENABLED_FALSE, 10, SEM_AVERAGING_TYPE_RMS));
  EXPECT_SUCCESS(session, client::sem_cfg_sweep_time(stub(), session, "", SEM_SWEEP_TIME_AUTO_TRUE, 1.0e-3));
  EXPECT_SUCCESS(session, client::sem_cfg_number_of_offsets(stub(), session, "", NUMBER_OF_OFFSETS));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_frequency_array(stub(), session, "", offsetStartFrequency, offsetStopFrequency, offsetSideband));
  EXPECT_SUCCESS(session, client::sem_cfg_offset_relative_limit_array(stub(), session, "", relativeLimitStart, relativeLimitStop));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  int32 arraySize = 0;
  SEMFetchMeasurementStatusResponse sem_fetch_measurement_status_response;
  SEMFetchCarrierMeasurementResponse sem_fetch_carrier_measurement_response;
  SEMFetchLowerOffsetMarginArrayResponse sem_fetch_lower_offset_margin_array_response;
  SEMFetchUpperOffsetMarginArrayResponse sem_fetch_upper_offset_margin_array_response;
  SEMFetchSpectrumResponse sem_fetch_spectrum_response;
  sem_fetch_measurement_status_response = client::sem_fetch_measurement_status(stub(), session, "", 10.0);
  sem_fetch_carrier_measurement_response = client::sem_fetch_carrier_measurement(stub(), session, "", 10.0);
  sem_fetch_lower_offset_margin_array_response = client::sem_fetch_lower_offset_margin_array(stub(), session, "", 10.0);
  sem_fetch_upper_offset_margin_array_response = client::sem_fetch_upper_offset_margin_array(stub(), session, "", 10.0);
  arraySize = sem_fetch_upper_offset_margin_array_response.measurement_status_size();
  sem_fetch_spectrum_response = client::sem_fetch_spectrum(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, sem_fetch_measurement_status_response);
  EXPECT_EQ(0, sem_fetch_measurement_status_response.measurement_status());
  EXPECT_SUCCESS(session, sem_fetch_carrier_measurement_response);
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.absolute_power());
  EXPECT_EQ(0.0, sem_fetch_carrier_measurement_response.relative_power());
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

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_SemMIMOFromExample_FetchData_DataLooksReasonable)
{
}

TEST_F(NiRFmxWLANDriverApiTests, TXPFromExample_FetchData_DataLooksReasonable)
{
  int32 autoLevel = RFMXWLAN_VAL_TRUE;
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK, 10e6));
  EXPECT_SUCCESS(session, client::cfg_frequency(stub(), session, "", 2.412e9));
  EXPECT_SUCCESS(session, client::cfg_external_attenuation(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::cfg_iq_power_edge_trigger(stub(), session, "", "0", IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE, -20.0, 0.0, TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO, 5.0e-6, IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE, BOOLEAN_TRUE));
  EXPECT_SUCCESS(session, client::cfg_standard(stub(), session, "", STANDARD_802_11_AG));
  EXPECT_SUCCESS(session, client::cfg_channel_bandwidth(stub(), session, "", 20e6));
  if (autoLevel)
  {
    EXPECT_SUCCESS(session, client::auto_level(stub(), session, "", 10e-3));
  }
  else
  {
    EXPECT_SUCCESS(session, client::cfg_reference_level(stub(), session, "", 0.0));
  }
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_TXP, true));
  EXPECT_SUCCESS(session, client::txp_cfg_maximum_measurement_interval(stub(), session, "", 1e-3));
  EXPECT_SUCCESS(session, client::txp_cfg_averaging(stub(), session, "", TXP_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  TXPFetchPowerTraceResponse txp_fetch_power_trace_response;
  TXPFetchMeasurementResponse txp_fetch_measurement_response;
  txp_fetch_power_trace_response = client::txp_fetch_power_trace(stub(), session, "", 10.0);
  txp_fetch_measurement_response = client::txp_fetch_measurement(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, txp_fetch_power_trace_response);
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.x0());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.dx());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power_size());
  EXPECT_EQ(999, txp_fetch_power_trace_response.power().size());
  EXPECT_EQ(0.0, txp_fetch_power_trace_response.power(0));
  EXPECT_SUCCESS(session, txp_fetch_measurement_response);
  EXPECT_EQ(0.0, txp_fetch_measurement_response.average_power_mean());
  EXPECT_EQ(0.0, txp_fetch_measurement_response.peak_power_maximum());
}

// NOTE: disabled due to "RFmxInstr_" in example's source code
TEST_F(NiRFmxWLANDriverApiTests, DISABLED_TXPMIMOFromExample_FetchData_DataLooksReasonable)
{
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
