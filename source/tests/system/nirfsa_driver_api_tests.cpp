#include <gmock/gmock.h>
#include <gtest/gtest.h>  // For EXPECT matchers.

#include "device_server.h"
#include "ivi.h"  // VI_SUCCESS
#include "niRFSAErrors.h"
#include "nirfsa/nirfsa_client.h"

using namespace ::testing;
using namespace nirfsa_grpc;
namespace client = nirfsa_grpc::experimental::client;
namespace pb = google::protobuf;

namespace ni {
namespace tests {
namespace system {

const auto PXI_5663E = "5663E";
const auto PXI_5603 = "5603";
class NiRFSADriverApiTests : public Test {
 protected:
  NiRFSADriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiRFSA::NewStub(device_server_->InProcessChannel()))
  {
  }

  virtual ~NiRFSADriverApiTests() {}

  void SetUp() override
  {
    device_server_->ResetServer();
  }

  const std::unique_ptr<NiRFSA::Stub>& stub() const
  {
    return stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFSA::Stub> stub_;
};

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(VI_SUCCESS, response.status());
}

template <typename TResponse>
void EXPECT_SUCCESS(const ::grpc::Status& status, const TResponse& response)
{
  EXPECT_SUCCESS(response);
  EXPECT_EQ(::grpc::Status::OK.error_code(), status.error_code());
}

InitWithOptionsResponse init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  return client::init_with_options(stub, "FakeDevice", false, false, options);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  auto response = init(stub, model);
  EXPECT_SUCCESS(response);
  return response.vi();
}

TEST_F(NiRFSADriverApiTests, Init_Close_Succeeds)
{
  auto init_response = init(stub(), PXI_5663E);

  auto close_response = client::close(stub(), init_response.vi());

  EXPECT_SUCCESS(init_response);
  EXPECT_SUCCESS(close_response);
}

TEST_F(NiRFSADriverApiTests, ConfigureGettingStartedIQ_Succeeds)
{
  auto session = init_session(stub(), PXI_5663E);
  auto configure_clock = client::configure_ref_clock(stub(), session, RefClockSourceRangeTable::REF_CLOCK_SOURCE_RANGE_TABLE_ONBOARD_CLOCK_STR, 10e6);
  auto configure_reference_level = client::configure_reference_level(stub(), session, "", 0);
  auto configure_acquisition_type = client::configure_acquisition_type(stub(), session, AcquisitionTypeRangeTable::ACQUISITION_TYPE_RANGE_TABLE_IQ);
  auto configure_number_of_samples = client::configure_number_of_samples(stub(), session, "", true, 1000);
  auto configure_iq_rate = client::configure_iq_rate(stub(), session, "", 1e6);

  EXPECT_SUCCESS(configure_clock);
  EXPECT_SUCCESS(configure_reference_level);
  EXPECT_SUCCESS(configure_acquisition_type);
  EXPECT_SUCCESS(configure_number_of_samples);
  EXPECT_SUCCESS(configure_iq_rate);
}

TEST_F(NiRFSADriverApiTests, GetDeviceResponse_ReturnsResponseData)
{
  auto session = init_session(stub(), PXI_5663E);
  auto response = client::get_device_response(stub(), session, "", DeviceResponse::DEVICE_RESPONSE_DOWNCONVERTER_IF_RESPONSE);

  const auto EXPECTED_SIZE = 81;
  EXPECT_SUCCESS(response);
  EXPECT_THAT(response.frequencies(), Each(Not(Eq(0))));
  EXPECT_THAT(response.phase_response(), Each(Eq(0)));
  EXPECT_THAT(response.magnitude_response(), Each(Eq(0)));
  EXPECT_EQ(EXPECTED_SIZE, response.frequencies().size());
  EXPECT_EQ(EXPECTED_SIZE, response.phase_response().size());
  EXPECT_EQ(EXPECTED_SIZE, response.magnitude_response().size());
}

// TODO: AB#1639825. This currently fails because of an off-by-one error.
TEST_F(NiRFSADriverApiTests, GetRelayName_ReturnsRelayName)
{
  auto session = init_session(stub(), PXI_5603);
  auto response = client::get_relay_name(stub(), session, "", 1);

  EXPECT_SUCCESS(response);
  EXPECT_EQ("Cal Tone Path Switch", response.name());
}

TEST_F(NiRFSADriverApiTests, GetRelayOperationsCount_ReturnsOperationCounts)
{
  const auto EXPECTED = std::vector<pb::int32>{0, 0, 0, 0};
  auto session = init_session(stub(), PXI_5603);
  auto response = client::get_relay_operations_count(stub(), session, "");

  EXPECT_SUCCESS(response);
  EXPECT_THAT(
      response.operations_count(),
      ElementsAreArray(EXPECTED.cbegin(), EXPECTED.cend()));
}

}  // namespace system
}  // namespace tests
}  // namespace ni
