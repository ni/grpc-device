#include <gtest/gtest.h>

#include "device_server.h"
#include "niscope/niscope_client.h"
#include "niscope_restricted/niscope_restricted_client.h"

using namespace niscope_grpc;
using namespace niscope_restricted_grpc;
namespace client = niscope_grpc::experimental::client;
namespace restricted_client = niscope_restricted_grpc::experimental::client;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {

const int kScopeDriverApiSuccess = 0;

class NiScopeRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiScopeRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        niscope_stub_(NiScope::NewStub(device_server_->InProcessChannel())),
        niscope_restricted_stub_(NiScopeRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiScopeRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiScope::Stub>& stub()
  {
    return niscope_stub_;
  }

  std::unique_ptr<NiScopeRestricted::Stub>& restricted_stub()
  {
    return niscope_restricted_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiScope::Stub> niscope_stub_;
  std::unique_ptr<NiScopeRestricted::Stub> niscope_restricted_stub_;
};

InitWithOptionsResponse init_with_options(const client::StubPtr& stub, const std::string& resource_name, const std::string& option_string)
{
  return client::init_with_options(stub, resource_name, false /*id_query*/, false /*reset_device*/, option_string);
}

nidevice_grpc::Session init_session(const client::StubPtr& stub)
{
  auto response = init_with_options(stub, "FakeDevice", "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
  auto session = response.vi();
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  return session;
}

nidevice_grpc::Session init_multi_instrument_session(const client::StubPtr& stub)
{
  auto response = init_with_options(stub, "FakeDevice1,FakeDevice2", "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
  auto session = response.vi();
  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  return session;
}

TEST_F(NiScopeRestrictedDriverApiTests, NiScopeRestrictedGetStartTimestampInformation_SendRequest_NonZeroTimestampsReturned)
{
  const auto session = init_session(stub());
  const auto auto_setup_response = client::auto_setup(stub(), session);
  EXPECT_EQ(kScopeDriverApiSuccess, auto_setup_response.status());

  const auto response = restricted_client::get_start_timestamp_information(restricted_stub(), session);

  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  EXPECT_NE(0, response.sys_time_in_128_bits_t1());
  EXPECT_NE(0, response.sys_time_in_128_bits_t2());
  EXPECT_NE(0, response.sys_time_in_128_bits_t3());
  EXPECT_EQ(0, response.sys_time_in_128_bits_t4()); // Not sure why this is always 0, may be because it's on a simulated device.
  EXPECT_EQ(0, response.device_time_in_absolute_time_units()); // Not sure why this is always 0, may be because it's on a simulated device.
}

TEST_F(NiScopeRestrictedDriverApiTests, NiScopeRestrictedGetStartTimestampInformationWithChannels_SendRequest_NonZeroTimestampsReturned)
{
  GTEST_SKIP() << "This test is disabled until the VM driver runtime is updated to include the new function (added in NI-SCOPE 2025 Q4).";

  const auto session = init_multi_instrument_session(stub());
  const auto auto_setup_response = client::auto_setup(stub(), session);
  EXPECT_EQ(kScopeDriverApiSuccess, auto_setup_response.status());

  const auto response = restricted_client::get_start_timestamp_information_with_channels(restricted_stub(), session, "FakeDevice1/0,FakeDevice2/0", 2);

  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  EXPECT_NE(0, response.sys_time_in_128_bits_t1_array()[0]);
  EXPECT_NE(0, response.sys_time_in_128_bits_t1_array()[1]);
  EXPECT_NE(0, response.sys_time_in_128_bits_t2_array()[0]);
  EXPECT_NE(0, response.sys_time_in_128_bits_t2_array()[1]);
  EXPECT_NE(0, response.sys_time_in_128_bits_t3_array()[0]);
  EXPECT_NE(0, response.sys_time_in_128_bits_t3_array()[1]);
  EXPECT_EQ(0, response.sys_time_in_128_bits_t4_array()[0]); // Not sure why this is always 0, may be because it's on a simulated device.
  EXPECT_EQ(0, response.sys_time_in_128_bits_t4_array()[1]); // Not sure why this is always 0, may be because it's on a simulated device.
  EXPECT_EQ(0, response.device_time_in_absolute_time_units_array()[0]); // Not sure why this is always 0, may be because it's on a simulated device.
  EXPECT_EQ(0, response.device_time_in_absolute_time_units_array()[1]); // Not sure why this is always 0, may be because it's on a simulated device.
}

TEST_F(NiScopeRestrictedDriverApiTests, NiScopeRestrictedParseNumberOfChannels_SendRequest_NumberOfChannelsParsed)
{
  const auto session = init_multi_instrument_session(stub());
  const auto auto_setup_response = client::auto_setup(stub(), session);
  EXPECT_EQ(kScopeDriverApiSuccess, auto_setup_response.status());

  const auto response = restricted_client::parse_number_of_channels(restricted_stub(), session,"FakeDevice1/0,FakeDevice2/0-1");

  EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  EXPECT_EQ(3, response.num_channels());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
