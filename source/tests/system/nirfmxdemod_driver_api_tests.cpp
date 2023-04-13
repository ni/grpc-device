#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxdemod/nirfmxdemod_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxdemod_grpc;
namespace client = nirfmxdemod_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

const auto PXI_5663E = "5663E";

class NiRFmxDemodDriverApiTests : public Test {
 protected:
  NiRFmxDemodDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFmxDemod::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxDemodDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFmxDemod::Stub>& stub() const
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
  std::unique_ptr<NiRFmxDemod::Stub> stub_;
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
  EXPECT_RESPONSE_SUCCESS(response);
  return session;
}

TEST_F(NiRFmxDemodDriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);
  auto session = init_response.instrument();
  EXPECT_SUCCESS(session, init_response);

  auto close_response = client::close(stub(), session, 0);

  EXPECT_RESPONSE_SUCCESS(close_response);
}

// ADemod
TEST_F(NiRFmxDemodDriverApiTests, ADemodAMBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::a_demod_cfg_rbw_filter(stub(), session, "", 100.00e+3, A_DEMOD_RBW_FILTER_TYPE_FLAT, 0.1));
  EXPECT_SUCCESS(session, client::a_demod_cfg_measurement_interval(stub(), session, "", 10.00e-3 ));
  EXPECT_SUCCESS(session, client::a_demod_cfg_am_carrier_suppressed(stub(), session, "", A_DEMOD_AM_CARRIER_SUPPRESSED_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::a_demod_cfg_averaging(stub(), session, "", A_DEMOD_AVERAGING_ENABLED_FALSE, 10, A_DEMOD_AVERAGING_TYPE_LINEAR));

  const auto a_demod_read_am_response = client::a_demod_read_am(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, a_demod_read_am_response);
  NEAR(2.55532, a_demod_read_am_response.mean_carrier_power(), 0.5);
  NEAR(68.8951, a_demod_read_am_response.mean_modulation_depth(), 0.5);
}

TEST_F(NiRFmxDemodDriverApiTests, ADemodFMBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::a_demod_cfg_rbw_filter(stub(), session, "", 100.00e+3, A_DEMOD_RBW_FILTER_TYPE_FLAT, 0.1));
  EXPECT_SUCCESS(session, client::a_demod_cfg_measurement_interval(stub(), session, "", 10.00e-3 ));
  EXPECT_SUCCESS(session, client::a_demod_cfg_fm_de_emphasis(stub(), session, "", 0.0));
  EXPECT_SUCCESS(session, client::a_demod_cfg_averaging(stub(), session, "", A_DEMOD_AVERAGING_ENABLED_FALSE, 10, A_DEMOD_AVERAGING_TYPE_LINEAR));

  const auto a_demod_read_fm_response = client::a_demod_read_fm(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, a_demod_read_fm_response);
  NEAR(-487.5, a_demod_read_fm_response.mean_carrier_frequency_error(), 0.5);
  NEAR(7880.26, a_demod_read_fm_response.mean_deviation(), 0.5);
}

TEST_F(NiRFmxDemodDriverApiTests, ADemodPMBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::a_demod_cfg_rbw_filter(stub(), session, "", 100.00e+3, A_DEMOD_RBW_FILTER_TYPE_FLAT, 0.1));
  EXPECT_SUCCESS(session, client::a_demod_cfg_measurement_interval(stub(), session, "", 10.00e-3));
  EXPECT_SUCCESS(session, client::a_demod_cfg_carrier_correction(stub(), session, "", A_DEMOD_CARRIER_FREQUENCY_CORRECTION_ENABLED_TRUE, A_DEMOD_CARRIER_PHASE_CORRECTION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::a_demod_cfg_averaging(stub(), session, "", A_DEMOD_AVERAGING_ENABLED_FALSE, 10, A_DEMOD_AVERAGING_TYPE_LINEAR));

  const auto a_demod_read_pm_response = client::a_demod_read_pm(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, a_demod_read_pm_response);
  NEAR(-461.135, a_demod_read_pm_response.mean_carrier_frequency_error(), 0.5);
  NEAR(386.444, a_demod_read_pm_response.mean_deviation(), 0.5);
}

// DDemod
TEST_F(NiRFmxDemodDriverApiTests, DDemodASKBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::d_demod_cfg_modulation_type(stub(), session, "", D_DEMOD_MODULATION_TYPE_ASK, D_DEMOD_M_4, D_DEMOD_DIFFERENTIAL_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_symbol_rate(stub(), session, "", 100.000e+3));
  EXPECT_SUCCESS(session, client::d_demod_cfg_number_of_symbols(stub(), session, "", 1000));
  std::vector<float> empty_float_vec;  
  EXPECT_SUCCESS(session, client::d_demod_cfg_pulse_shaping_filter(stub(), session, "", D_DEMOD_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE, 0.50, 0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_measurement_filter(stub(), session, "", D_DEMOD_MEASUREMENT_FILTER_TYPE_AUTO, 0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_averaging(stub(), session, "", D_DEMOD_AVERAGING_ENABLED_FALSE, 10));

  const auto d_demod_read_response = client::d_demod_read(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, d_demod_read_response);
  NEAR(0, d_demod_read_response.mean_modulation_error_ratio(), 20);
  NEAR(135, d_demod_read_response.maximum_peak_evm(), 50);
  NEAR(60, d_demod_read_response.mean_rms_evm(), 20);
  NEAR(0, d_demod_read_response.mean_frequency_offset(), 2000);
}

TEST_F(NiRFmxDemodDriverApiTests, DDemodFSKBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::cfg_frequency_reference(stub(), session, "", FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK , 10.0e+6));
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MEASUREMENT_TYPES_DDEMOD, true));
  EXPECT_SUCCESS(session, client::d_demod_cfg_modulation_type(stub(), session, "", D_DEMOD_MODULATION_TYPE_FSK, D_DEMOD_M_2, D_DEMOD_DIFFERENTIAL_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_fsk_deviation(stub(), session, "", 15.000e+3, D_DEMOD_FSK_REFERENCE_COMPENSATION_ENABLED_TRUE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_symbol_rate(stub(), session, "", 100.000e+3));
  EXPECT_SUCCESS(session, client::d_demod_cfg_number_of_symbols(stub(), session, "", 1000));
  std::vector<float> empty_float_vec;
  EXPECT_SUCCESS(session, client::d_demod_cfg_pulse_shaping_filter(stub(), session, "", D_DEMOD_PULSE_SHAPING_FILTER_TYPE_GAUSSIAN, 0.50, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_measurement_filter(stub(), session, "", D_DEMOD_MEASUREMENT_FILTER_TYPE_AUTO, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_averaging(stub(), session, "", D_DEMOD_AVERAGING_ENABLED_FALSE, 10));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto d_demod_fetch_fsk_results_response = client::d_demod_fetch_fsk_results(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, d_demod_fetch_fsk_results_response);
  NEAR(17000, d_demod_fetch_fsk_results_response.mean_fsk_deviation(), 2000);
  NEAR(33000, d_demod_fetch_fsk_results_response.mean_rms_fsk_error(), 2000);
  NEAR(400000, d_demod_fetch_fsk_results_response.maximum_peak_fsk_error(), 100000);
}

TEST_F(NiRFmxDemodDriverApiTests, DDemodMSKBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::d_demod_cfg_modulation_type(stub(), session, "", D_DEMOD_MODULATION_TYPE_MSK, D_DEMOD_M_4, D_DEMOD_DIFFERENTIAL_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_symbol_rate(stub(), session, "", 100.000e+3));
  EXPECT_SUCCESS(session, client::d_demod_cfg_number_of_symbols(stub(), session, "", 1000));
  std::vector<float> empty_float_vec;
  EXPECT_SUCCESS(session, client::d_demod_cfg_pulse_shaping_filter(stub(), session, "", D_DEMOD_PULSE_SHAPING_FILTER_TYPE_GAUSSIAN, 0.50, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_measurement_filter(stub(), session, "", D_DEMOD_MEASUREMENT_FILTER_TYPE_AUTO, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_averaging(stub(), session, "", D_DEMOD_AVERAGING_ENABLED_FALSE, 10));

  const auto d_demod_read_response = client::d_demod_read(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, d_demod_read_response);
  NEAR(0, d_demod_read_response.mean_modulation_error_ratio(), 50);
  NEAR(250, d_demod_read_response.maximum_peak_evm(), 50);
  NEAR(150, d_demod_read_response.mean_rms_evm(), 50);
  NEAR(0,  d_demod_read_response.mean_frequency_offset(), 50000);
}

TEST_F(NiRFmxDemodDriverApiTests, DDemodPSKBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::d_demod_cfg_modulation_type(stub(), session, "", D_DEMOD_MODULATION_TYPE_PSK, D_DEMOD_M_4, D_DEMOD_DIFFERENTIAL_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_psk_format(stub(), session, "", D_DEMOD_PSK_FORMAT_NORMAL));
  EXPECT_SUCCESS(session, client::d_demod_cfg_symbol_rate(stub(), session, "", 100.000e+3));
  EXPECT_SUCCESS(session, client::d_demod_cfg_number_of_symbols(stub(), session, "", 1000));
  std::vector<float> empty_float_vec;
  EXPECT_SUCCESS(session, client::d_demod_cfg_pulse_shaping_filter(stub(), session, "", D_DEMOD_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE, 0.50, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_measurement_filter(stub(), session, "", D_DEMOD_MEASUREMENT_FILTER_TYPE_AUTO, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_averaging(stub(), session, "", D_DEMOD_AVERAGING_ENABLED_FALSE, 10));

  const auto d_demod_read_response = client::d_demod_read(stub(), session, "", 10.0);
  EXPECT_SUCCESS(session, d_demod_read_response);
  NEAR(0, d_demod_read_response.mean_modulation_error_ratio(), 100);
  NEAR(102, d_demod_read_response.maximum_peak_evm(), 50);
  NEAR(45, d_demod_read_response.mean_rms_evm(), 20);
  NEAR(0, d_demod_read_response.mean_frequency_offset(), 20);
}

TEST_F(NiRFmxDemodDriverApiTests, DDemodQAMBasicFromExample_FetchData_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_string(stub(), session, "", NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS, std::string()));
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e+9, 0.00, 0.00));
  EXPECT_SUCCESS(session, client::d_demod_cfg_modulation_type(stub(), session, "", D_DEMOD_MODULATION_TYPE_QAM, D_DEMOD_M_16, D_DEMOD_DIFFERENTIAL_ENABLED_FALSE));
  EXPECT_SUCCESS(session, client::d_demod_cfg_symbol_rate(stub(), session, "", 100.000e+3));
  EXPECT_SUCCESS(session, client::d_demod_cfg_number_of_symbols(stub(), session, "", 1000));
  std::vector<float> empty_float_vec;
  EXPECT_SUCCESS(session, client::d_demod_cfg_pulse_shaping_filter(stub(), session, "", D_DEMOD_PULSE_SHAPING_FILTER_TYPE_RAISED_COSINE, 0.50, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_measurement_filter(stub(), session, "", D_DEMOD_MEASUREMENT_FILTER_TYPE_AUTO, 0.0, 1.0, empty_float_vec));
  EXPECT_SUCCESS(session, client::d_demod_cfg_averaging(stub(), session, "", D_DEMOD_AVERAGING_ENABLED_FALSE, 10));

  const auto d_demod_read_response = client::d_demod_read(stub(), session, "", 10.0);
  EXPECT_RESPONSE_WARNING(377702, d_demod_read_response);
  NEAR(0, d_demod_read_response.mean_modulation_error_ratio(), 100);
  NEAR(36, d_demod_read_response.maximum_peak_evm(), 20);
  NEAR(16, d_demod_read_response.mean_rms_evm(), 20);
  NEAR(0, d_demod_read_response.mean_frequency_offset(), 2000);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
