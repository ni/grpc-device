#include <gtest/gtest.h>
#include <nifake/nifake_client.h>
#include <nifake/nifake_mock_library.h>
#include <nifake/nifake_service.h>

#include <atomic>
#include <memory>
#include <thread>

namespace ni {
namespace tests {
namespace integration {

namespace client = nifake_grpc::experimental::client;
using namespace ::testing;
using namespace nifake_grpc;
const auto kDriverSuccess = 0U;

// Test NiFakeService using a client stub.
class NiFakeServiceTests_EndToEnd : public ::testing::Test {
 public:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<ViSession>;
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  std::shared_ptr<ni::tests::unit::NiFakeMockLibrary> library_;
  NiFakeService service_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<NiFake::Stub> stub_;
  std::atomic<bool> shutdown_{false};

  NiFakeServiceTests_EndToEnd()
      : session_repository_(std::make_shared<nidevice_grpc::SessionRepository>()),
        resource_repository_(std::make_shared<FakeResourceRepository>(session_repository_)),
        library_(std::make_shared<ni::tests::unit::NiFakeMockLibrary>()),
        service_(library_, resource_repository_),
        server_(start_server()),
        stub_(NiFake::NewStub(server_->InProcessChannel(::grpc::ChannelArguments())))
  {
  }

  virtual ~NiFakeServiceTests_EndToEnd()
  {
    shutdown();
  }

  void shutdown()
  {
    if (!shutdown_) {
      shutdown_ = true;
      server_->Shutdown();
    }
  }

  std::unique_ptr<::grpc::Server> start_server()
  {
    ::grpc::ServerBuilder builder;
    builder.RegisterService(&service_);
    return builder.BuildAndStart();
  }

  std::unique_ptr<NiFake::Stub>& stub()
  {
    return stub_;
  }
};

InitWithOptionsResponse init(const client::StubPtr& stub)
{
  return client::init_with_options(stub, "", false, false, "");
}

TEST_F(NiFakeServiceTests_EndToEnd, PassMappedEnumToGeneratedClient_PassesStringValueToLibraryAndSucceeds)
{
  auto init_response = init(stub());
  const auto EXPECTED = NIFAKE_VAL_ANDROID;
  EXPECT_CALL(*library_, StringValuedEnumInputFunctionWithDefaults(_, Pointee(*EXPECTED)))
      .WillOnce(Return(kDriverSuccess));
  auto response = client::string_valued_enum_input_function_with_defaults(stub(), init_response.vi(), MobileOSNames::MOBILE_OS_NAMES_ANDROID);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeServiceTests_EndToEnd, PassMappedEnumRawValueToGeneratedClient_PassesStringValueToLibraryAndSucceeds)
{
  auto init_response = init(stub());
  const auto RAW_VALUE = NIFAKE_VAL_IOS;
  EXPECT_CALL(*library_, StringValuedEnumInputFunctionWithDefaults(_, Pointee(*RAW_VALUE)))
      .WillOnce(Return(kDriverSuccess));
  auto response = client::string_valued_enum_input_function_with_defaults(stub(), init_response.vi(), std::string(RAW_VALUE));

  EXPECT_EQ(kDriverSuccess, response.status());
}
}  // namespace integration
}  // namespace tests
}  // namespace ni
