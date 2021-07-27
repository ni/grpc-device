#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/async_processing_loop.h>

#include <chrono>
#include <memory>
namespace ni {
namespace tests {
namespace integration {

using namespace nifake_non_ivi_grpc;

// Test NiFakeNonIviService using a client stub.
class NiFakeNonIviServiceTests_EndToEnd : public ::testing::Test {
 public:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  ni::tests::unit::NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;
  std::unique_ptr<::grpc::ServerCompletionQueue> completion_queue_;
  std::thread callback_thread_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<NiFakeNonIvi::Stub> stub_;

  NiFakeNonIviServiceTests_EndToEnd()
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        library_(),
        service_(&library_, resource_repository_),
        server_(start_server()),
        stub_(NiFakeNonIvi::NewStub(server_->InProcessChannel(::grpc::ChannelArguments())))
  {
  }

  virtual ~NiFakeNonIviServiceTests_EndToEnd()
  {
    server_->Shutdown();
    completion_queue_->Shutdown();
    callback_thread_.join();
  }

  std::unique_ptr<::grpc::Server> start_server()
  {
    ::grpc::ServerBuilder builder;
    builder.RegisterService(&service_);
    completion_queue_ = builder.AddCompletionQueue();
    auto server = builder.BuildAndStart();
    callback_thread_ = std::thread([&]() { nidevice_grpc::run_async_processing_loop(completion_queue_.get(), service_); });
    return server;
  }

  std::unique_ptr<NiFakeNonIvi::Stub>& stub()
  {
    return stub_;
  }
};

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  reader->WaitForInitialMetadata();

  ReadStreamResponse response;
  for (auto i = START; i <= STOP; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }
}

}  // namespace integration
}  // namespace tests
}  // namespace ni