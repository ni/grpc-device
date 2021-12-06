#include <gtest/gtest.h>

#include <thread>

#include "device_server.h"
#include "nirfmxspecan/nirfmxspecan_client.h"
#include "nirfmxspecan/nirfmxspecan_service.h"

using namespace nirfmxspecan_grpc;
namespace client = nirfmxspecan_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {

const auto PXI_5663 = "5663";

const int krfmxSpecAnDriverApiSuccess = 0;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfmxSpecAnDriverApiSuccess, response.status());
}

class NiRFmxSpecAnDriverApiTests : public ::testing::Test {
 protected:
  NiRFmxSpecAnDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfmxspecan_stub_(NiRFmxSpecAn::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFmxSpecAnDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<NiRFmxSpecAn::Stub>& stub()
  {
    return nirfmxspecan_stub_;
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
    if (response.status() != krfmxSpecAnDriverApiSuccess) {
      auto error_message_response = client::get_error_string(stub(), session, response.status());
      EXPECT_EQ("", error_message_response.error_description());
    }
    check_error(session);
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiRFmxSpecAn::Stub> nirfmxspecan_stub_;
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
  EXPECT_SUCCESS(response);
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& model)
{
  return init_session(stub, model, "FakeDevice");
}

TEST_F(NiRFmxSpecAnDriverApiTests, SpectrumBasicFromExample_DataLooksReasonable)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::cfg_rf(stub(), session, "", 1e9, 0, 0));
  EXPECT_SUCCESS(session, client::spectrum_cfg_span(stub(), session, "", 1e6));
  EXPECT_SUCCESS(session, client::spectrum_cfg_rbw_filter(stub(), session, "", SpectrumAveragingEnabled::SPECTRUM_AVERAGING_ENABLED_TRUE, 100e3, SpectrumRbwFilterType::SPECTRUM_RBW_FILTER_TYPE_GAUSSIAN));
  EXPECT_SUCCESS(session, client::spectrum_cfg_averaging(stub(), session, "", SpectrumAveragingEnabled::SPECTRUM_AVERAGING_ENABLED_FALSE, 10, SpectrumAveragingType::SPECTRUM_AVERAGING_TYPE_RMS));

  auto read_response = client::spectrum_read(stub(), session, "", 10.0);

  EXPECT_SUCCESS(session, read_response);
  // Make sure the data looks roughly correct
  EXPECT_EQ(1005, read_response.actual_array_size());
  EXPECT_EQ(1005, read_response.spectrum_size());
  EXPECT_EQ(1005, read_response.spectrum().size());
  int midpoint_x = 1005 / 2;
  EXPECT_LT(read_response.spectrum(0), read_response.spectrum(midpoint_x));
  EXPECT_LT(read_response.spectrum(1004), read_response.spectrum(midpoint_x));
}

TEST_F(NiRFmxSpecAnDriverApiTests, SetAndGetAttributeInt32_Succeeds)
{
  auto session = init_session(stub(), PXI_5663);
  EXPECT_SUCCESS(session, client::set_attribute_i32(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT, NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_NF_EXTERNAL_PREAMP_PRESENT_TRUE));
  // This is one way to get the driver in a state where we can get attributes
  EXPECT_SUCCESS(session, client::spectrum_read(stub(), session, "", 10.0));

  auto get_response = client::get_attribute_i32(stub(), session, "", NiRFmxSpecAnAttribute::NIRFMXSPECAN_ATTRIBUTE_NF_EXTERNAL_PREAMP_PRESENT);

  EXPECT_SUCCESS(session, get_response);
  EXPECT_EQ(NiRFmxSpecAnInt32AttributeValues::NIRFMXSPECAN_INT32_NF_EXTERNAL_PREAMP_PRESENT_TRUE, get_response.attr_val());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
