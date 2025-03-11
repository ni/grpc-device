#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>
#include <tuple>

#include "device_server.h"
#include "nirfmxinstr/nirfmxinstr_client.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfmxspecan_restricted/nirfmxspecan_restricted_client.h"
#include "rfmx_macros.h"
#include "waveform_helpers.h"

using namespace nirfmxspecan_grpc;
using namespace nirfmxspecan_restricted_grpc;
namespace client = nirfmxspecan_grpc::experimental::client;
namespace instr_client = nirfmxinstr_grpc::experimental::client;
namespace restricted_client = nirfmxspecan_restricted_grpc::experimental::client;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto PXI_5663 = "5663";
constexpr auto IQ_FETCH_DELETED_RECORD_ERROR = -379451;
constexpr auto IQ_FETCH_DELETED_RECORD_ERROR_STR = "The requested record number is invalid";

class NiRFmxSpecAnRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxSpecAnRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxspecan_stub_(NiRFmxSpecAn::NewStub(device_server_->InProcessChannel())),
        nirfmxspecan_restricted_stub_(NiRFmxSpecAnRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxSpecAnRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiRFmxSpecAn::Stub>& stub()
  {
    return nirfmxspecan_stub_;
  }

  std::unique_ptr<NiRFmxSpecAnRestricted::Stub>& restricted_stub()
  {
    return nirfmxspecan_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxSpecAn::Stub> nirfmxspecan_stub_;
  std::unique_ptr<NiRFmxSpecAnRestricted::Stub> nirfmxspecan_restricted_stub_;
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
  return init_session(stub, model, "FakeDevice");
}

TEST_F(NiRFmxSpecAnRestrictedDriverApiTests, IQFetchDataOverrideBehavior_DeleteOnFetch_RecordIsDeleted)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_IQ, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = restricted_client::iq_fetch_data_override_behavior(restricted_stub(), session, "", 10.0, 0, 1000, 1);
  EXPECT_SUCCESS(session, fetch_response);
  EXPECT_THAT(fetch_response.data(), Not(IsEmpty()));

  EXPECT_ERROR(
      IQ_FETCH_DELETED_RECORD_ERROR, IQ_FETCH_DELETED_RECORD_ERROR_STR, session,
      client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000));
}

TEST_F(NiRFmxSpecAnRestrictedDriverApiTests, IQFetchDataOverrideBehavior_NoDeleteOnFetch_RecordIsNotDeleted)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_IQ, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));

  const auto fetch_response = restricted_client::iq_fetch_data_override_behavior(restricted_stub(), session, "", 10.0, 0, 1000, 2);
  EXPECT_SUCCESS(session, fetch_response);
  EXPECT_THAT(fetch_response.data(), Not(IsEmpty()));
  const auto fetch_response_2 = client::iq_fetch_data(stub(), session, "", 10.0, 0, 1000);
  EXPECT_SUCCESS(session, fetch_response_2);

  EXPECT_THAT(fetch_response_2.data(), Not(IsEmpty()));
}

TEST_F(NiRFmxSpecAnRestrictedDriverApiTests, CacheResult_ReturnsNonEmptyResult)
{
  const auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::select_measurements(stub(), session, "", MeasurementTypes::MEASUREMENT_TYPES_ACP, true));
  EXPECT_SUCCESS(session, client::initiate(stub(), session, "", ""));
  auto read_response = EXPECT_SUCCESS(session, client::spectrum_read(stub(), session, "", 10.0));

  const auto response = restricted_client::cache_result(restricted_stub(), session, "", 512);
  EXPECT_SUCCESS(session, response);

  EXPECT_THAT(response.selector_string_out(), Not(IsEmpty()));
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
