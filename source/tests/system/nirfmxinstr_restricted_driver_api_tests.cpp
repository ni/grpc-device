#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxinstr_restricted/nirfmxinstr_restricted_client.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfsa/nirfsa_client.h"
#include "rfmx_macros.h"

using namespace ::testing;
using namespace nirfmxinstr_grpc;
using namespace nirfmxinstr_restricted_grpc;
namespace client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxinstr_restricted_grpc::experimental::client;
namespace nirfsa_client = nirfsa_grpc::experimental::client;
namespace pb = ::google::protobuf;
namespace specan_client = nirfmxspecan_grpc::experimental::client;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663 = "5663";
constexpr auto PXI_5663E = "5663E";
constexpr auto DEFAULT_RESOURCE_NAME = "FakeDevice";

class NiRFmxInstrRestrictedDriverApiTests : public Test {
 protected:
  NiRFmxInstrRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxinstr_stub_(NiRFmxInstr::NewStub(device_server_->InProcessChannel())),
        nirfmxinstr_restricted_stub_(NiRFmxInstrRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiRFmxInstrRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxInstr::Stub>& stub()
  {
    return nirfmxinstr_stub_;
  }

  std::unique_ptr<NiRFmxInstrRestricted::Stub>& restricted_stub()
  {
    return nirfmxinstr_restricted_stub_;
  }

  // Some APIs (GetAttribute) require you Initiate/Commit the session. Use an arbitrary SpecAn measurement type
  // to enter this state.
  void initiate_to_enter_committed_state(const nidevice_grpc::Session& session)
  {
    auto specan_stub = create_stub<nirfmxspecan_grpc::NiRFmxSpecAn>();
    EXPECT_SUCCESS(session, specan_client::select_measurements(specan_stub, session, "", nirfmxspecan_grpc::MeasurementTypes::MEASUREMENT_TYPES_CHP, true));
    EXPECT_SUCCESS(session, specan_client::initiate(specan_stub, session, "", ""));
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxInstr::Stub> nirfmxinstr_stub_;
  std::unique_ptr<NiRFmxInstrRestricted::Stub> nirfmxinstr_restricted_stub_;
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

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, DEFAULT_RESOURCE_NAME);
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, GetRFmxVersion)
{
  const auto session = init_session(stub(), PXI_5663);
  auto get_version_response = restricted_client::get_r_fmx_version(restricted_stub(), session);
  EXPECT_RESPONSE_SUCCESS(get_version_response);
  EXPECT_GT(get_version_response.r_fmx_version().length(), 0);
}

// GetTracesInfoForMonitorSnapshot
// GetForceAllTracesEnabled
// SetForceAllTracesEnabled

TEST_F(NiRFmxInstrRestrictedDriverApiTests, GetAttributeDesiredF64)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE, 150));
  initiate_to_enter_committed_state(session);
  auto get_desired_attr_response =  restricted_client::get_attribute_desired_f64(restricted_stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE);
  EXPECT_EQ(get_desired_attr_response.attr_val(), 150);
  auto get_attr_response =  client::get_attribute_f64(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE);
  EXPECT_LT(get_attr_response.attr_val(), get_desired_attr_response.attr_val());
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, GetAttributeDesiredI32)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED, INT_MAX));
  initiate_to_enter_committed_state(session);
  auto get_desired_attr_response =  restricted_client::get_attribute_desired_i32(restricted_stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);
  EXPECT_EQ(get_desired_attr_response.attr_val(), INT_MAX);
  auto get_attr_response =  client::get_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);
  EXPECT_LT(get_attr_response.attr_val(), get_desired_attr_response.attr_val());
}

// GetAttributeDesiredI64
// GetAttributeDesiredString
// GetAttributeDesiredF64Array
// GetAttributeDesiredF32Array
// GetAttributeDesiredF32
// GetAttributeAuthor

// SaveAllForRevert
// LoadAllForRevert
// GetInitiaitedSnapshotStrings
// GetSnapshotInfoFromCache
// GetLatestConfigurationSnapshot
// GetSnapshotState
// DeleteSnapshot
// ConvertForPowerUnitsUtility
// UnregisterSpecialClientSnapshotInterest
// GetCalibrationPlaneNames
// GetCalibrationPlaneEnabled
// GetExternalAttenuationTableNames
// GetActiveTableName
// GetSParameterExternalAttenuationType
// GetSignalConfigurationState64

TEST_F(NiRFmxInstrRestrictedDriverApiTests, SetIOTraceStatus)
{
  const auto session = init_session(stub(), PXI_5663);
  auto set_io_trace_status_response = restricted_client::set_io_trace_status(restricted_stub(), session, 1);
  EXPECT_RESPONSE_SUCCESS(set_io_trace_status_response);
}

// GetActiveResultName


}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
