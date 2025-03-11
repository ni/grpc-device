#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>

#include "device_server.h"
#include "nirfsg/nirfsg_client.h"
#include "nirfsg_restricted/nirfsg_restricted_client.h"

using namespace nirfsg_grpc;
using namespace nirfsg_restricted_grpc;
namespace client = nirfsg_grpc::experimental::client;
namespace restricted_client = nirfsg_restricted_grpc::experimental::client;
using namespace ::testing;

namespace ni {
namespace tests {
namespace system {

const auto PXI_5841 = "5841";
const int krfsgDriverApiSuccess = 0;

template <typename TResponse>
void EXPECT_SUCCESS(const TResponse& response)
{
  EXPECT_EQ(krfsgDriverApiSuccess, response.status());
}

class NiRFSGRestrictedDriverApiTests : public ::testing::Test {
 protected:
  NiRFSGRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nirfsg_stub_(NiRFSG::NewStub(device_server_->InProcessChannel())),
        nirfsg_restricted_stub_(NiRFSGRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiRFSGRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  std::unique_ptr<NiRFSG::Stub>& stub()
  {
    return nirfsg_stub_;
  }

  std::unique_ptr<NiRFSGRestricted::Stub>& restricted_stub()
  {
    return nirfsg_restricted_stub_;
  }
  
  void check_error(const nidevice_grpc::Session& session)
  {
    auto response = client::get_error(stub(), session);
    EXPECT_EQ("", std::string(response.error_description().c_str()));
  }
  
  template <typename TResponse>
  void EXPECT_SUCCESS(const TResponse& response)
  {
    EXPECT_EQ(krfsgDriverApiSuccess, response.status());
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
  std::unique_ptr<NiRFSGRestricted::Stub> nirfsg_restricted_stub_;
};

nidevice_grpc::Session init(const client::StubPtr& stub, const std::string& model)
{
  auto options = std::string("Simulate=1, DriverSetup=Model:") + model;
  auto response = client::init_with_options(stub, "FakeDevice", false, false, options);
  auto session = response.vi();
  EXPECT_SUCCESS(response);
  return session;
}

TEST_F(NiRFSGRestrictedDriverApiTests, RestrictedSetDeembeddingSparameterTable_Succeeds)
{
  auto session = init(stub(), PXI_5841);
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
  auto configure_table = restricted_client::create_deembedding_sparameter_table(restricted_stub(), session, "", "table", 1, 2);
  auto configure_frequencies = restricted_client::configure_sparameter_table_frequencies(restricted_stub(), session, "", "table", frequencies);
  auto configure_sparameter = restricted_client::configure_sparameter_table_sparameters(restricted_stub(), session, "", "table", parameters, nirfsg_restricted_grpc::SParameterOrientation::S_PARAMETER_ORIENTATION_PORT2_TOWARDS_DUT);
  auto close = client::close(stub(), session);

  EXPECT_SUCCESS(session, configure_table);
  EXPECT_SUCCESS(session, configure_frequencies);
  EXPECT_SUCCESS(session, configure_sparameter);
  EXPECT_SUCCESS(session, close);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
