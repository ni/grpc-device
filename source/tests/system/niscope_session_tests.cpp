#include <gtest/gtest.h>
#include <server/session_utilities_service.h>

#include "niscope/niscope_library.h"
#include "niscope/niscope_service.h"

namespace ni {
namespace tests {
namespace system {

class NiScopeSessionTest : public ::testing::Test {
 public:
  virtual ~NiScopeSessionTest() {}

  void SetUp() override
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<ni::hardware::grpc::internal::SessionRepository>();
    device_enumerator_ = std::make_unique<ni::hardware::grpc::internal::DeviceEnumerator>();
    session_utilities_service_ = std::make_unique<ni::hardware::grpc::SessionUtilitiesService>(session_repository_.get(), device_enumerator_.get());
    niscope_library_ = std::make_unique<ni::scope::grpc::NiScopeLibrary>();
    niscope_service_ = std::make_unique<ni::scope::grpc::NiScopeService>(niscope_library_.get(), session_repository_.get());
    builder.RegisterService(session_utilities_service_.get());
    builder.RegisterService(niscope_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
  }

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    stub_ = ni::scope::grpc::NiScope::NewStub(channel_);
  }

  std::unique_ptr<ni::scope::grpc::NiScope::Stub>& GetStub()
  {
    return stub_;
  }

 protected:
  NiScopeSessionTest() {}

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::ni::scope::grpc::NiScope::Stub> stub_;
  std::unique_ptr<::ni::hardware::grpc::internal::SessionRepository> session_repository_;
  std::unique_ptr<::ni::hardware::grpc::internal::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<::ni::hardware::grpc::SessionUtilitiesService> session_utilities_service_;
  std::unique_ptr<::ni::scope::grpc::NiScopeLibrary> niscope_library_;
  std::unique_ptr<::ni::scope::grpc::NiScopeService> niscope_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiScopeSessionTest, NiScopeClient_InitializeSession_CreatesDriverSession)
{
  ResetStub();
  const char* resource_name = "FakeDevice";
  const char* option_string = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe";
  const char* session_name = "SessionName";
  ni::scope::grpc::InitWithOptionsRequest request;
  ni::scope::grpc::InitWithOptionsResponse response;
  request.set_resource_name(resource_name);
  request.set_option_string(option_string);
  request.set_session_name(session_name);
  request.set_reset_device(false);
  request.set_id_query(false);

  ::grpc::ClientContext context;
  ::grpc::Status status = GetStub()->InitWithOptions(&context, request, &response);

  EXPECT_TRUE(status.ok());
  std::cout << status.error_message() << std::endl;
  EXPECT_EQ(0, response.status());
  EXPECT_NE(0, response.vi().id());
}

}  // namespace system
}  // namespace tests
}  // namespace ni