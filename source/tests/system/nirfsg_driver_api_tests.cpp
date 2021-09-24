#include <gtest/gtest.h>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nirfsg/nirfsg_service.h"

using namespace nirfsg_grpc;
namespace client = nirfsg_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

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

TEST_F(NiRFSGDriverApiTests, ConfigureGettingStartedSingleToneGeneration_Succeeds)
{
  auto session = init_session(stub(), PXI_5652);
  auto configure_clock = client::configure_ref_clock(stub(), session, AttrRefClockSourceRangeTable::ATTR_REF_CLOCK_SOURCE_RANGE_TABLE_ONBOARD_CLOCK_STR, 10e6);
  auto configure_rf = client::configure_rf(stub(), session, 1e9, -5);
  auto configure_generation_mode = client::configure_generation_mode(stub(), session, AttrGenerationModeRangeTable::ATTR_GENERATION_MODE_RANGE_TABLE_CW);

  EXPECT_SUCCESS(session, configure_clock);
  EXPECT_SUCCESS(session, configure_rf);
  EXPECT_SUCCESS(session, configure_generation_mode);
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
}  // namespace system
}  // namespace tests
}  // namespace ni