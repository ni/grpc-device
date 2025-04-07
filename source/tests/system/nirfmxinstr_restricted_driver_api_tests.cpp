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
  EXPECT_GT(get_version_response.version().length(), 0);
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, SetForceAllTracesEnabled_GetForceAllTracesEnabled_AttributeIsAsSet)
{
  const auto session = init_session(stub(), PXI_5663E);
  auto initial_enabled_response = restricted_client::get_force_all_traces_enabled(restricted_stub(), session, "");
  auto new_enabled_value = initial_enabled_response.attr_val() == 0 ? 1 : 0;
  EXPECT_SUCCESS(session, restricted_client::set_force_all_traces_enabled(restricted_stub(), session, "", new_enabled_value));

  auto get_enabled_response = restricted_client::get_force_all_traces_enabled(restricted_stub(), session, "");
  EXPECT_RESPONSE_SUCCESS(get_enabled_response);
  EXPECT_EQ(new_enabled_value, get_enabled_response.attr_val());
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, SetAttributeOutOfRange_GetAttributeDesiredF64_DesiredAttributeReturned)
{
  const double attenuation = 150.0;
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_f64(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE, attenuation));
  initiate_to_enter_committed_state(session);

  auto get_desired_attr_response = restricted_client::get_attribute_desired_f64(restricted_stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE);
  EXPECT_RESPONSE_SUCCESS(get_desired_attr_response);
  EXPECT_EQ(get_desired_attr_response.attr_val(), attenuation);

  auto get_attr_response = client::get_attribute_f64(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_MECHANICAL_ATTENUATION_VALUE);
  EXPECT_LT(get_attr_response.attr_val(), get_desired_attr_response.attr_val());
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, SetAttributeOutOfRange_GetAttributeDesiredI32_DesiredAttributeReturned)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED, INT_MAX));
  initiate_to_enter_committed_state(session);

  auto get_desired_attr_response = restricted_client::get_attribute_desired_i32(restricted_stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);
  EXPECT_RESPONSE_SUCCESS(get_desired_attr_response);
  EXPECT_EQ(get_desired_attr_response.attr_val(), INT_MAX);

  auto get_attr_response = client::get_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);
  EXPECT_LT(get_attr_response.attr_val(), get_desired_attr_response.attr_val());
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, GetAttributeAuthor)
{
  const auto session = init_session(stub(), PXI_5663E);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxInstrAttribute::NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED, 2));
  initiate_to_enter_committed_state(session);

  auto get_attribute_author_response = restricted_client::get_attribute_author(restricted_stub(), session, "", NIRFMXINSTR_ATTRIBUTE_TUNING_SPEED);
  EXPECT_RESPONSE_SUCCESS(get_attribute_author_response);
  EXPECT_EQ(get_attribute_author_response.attr_val(), 1);  // RfsgAttributeAuthor.User
}

TEST_F(NiRFmxInstrRestrictedDriverApiTests, SetIOTraceStatus)
{
  const auto session = init_session(stub(), PXI_5663);
  auto set_io_trace_status_response = restricted_client::set_io_trace_status(restricted_stub(), session, 1);
  EXPECT_RESPONSE_SUCCESS(set_io_trace_status_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
