#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>

#include <atomic>
#include <memory>
#include <thread>

namespace ni {
namespace tests {
namespace integration {

using namespace ::testing;
using namespace nifake_non_ivi_grpc;

// Test NiFakeNonIviService using a client stub.
class NiFakeNonIviServiceTests_EndToEnd : public ::testing::Test {
 public:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  using SecondaryResourceRepository = nidevice_grpc::SessionResourceRepository<SecondarySessionHandle>;
  using FakeCrossDriverResourceRepository = nidevice_grpc::SessionResourceRepository<FakeCrossDriverHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  nidevice_grpc::SessionRepository secondary_session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  std::shared_ptr<SecondaryResourceRepository> secondary_resource_repository_;
  ni::tests::unit::NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<NiFakeNonIvi::Stub> stub_;
  std::atomic<bool> shutdown_{false};

  NiFakeNonIviServiceTests_EndToEnd()
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        secondary_session_repository_(),
        secondary_resource_repository_(std::make_shared<SecondaryResourceRepository>(&secondary_session_repository_)),
        library_(),
        service_(&library_, resource_repository_, std::make_shared<FakeCrossDriverResourceRepository>(&session_repository_), std::make_shared<FakeCrossDriverResourceRepository>(&secondary_session_repository_)),
        server_(start_server()),
        stub_(NiFakeNonIvi::NewStub(server_->InProcessChannel(::grpc::ChannelArguments())))
  {
  }

  virtual ~NiFakeNonIviServiceTests_EndToEnd()
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

  std::unique_ptr<NiFakeNonIvi::Stub>& stub()
  {
    return stub_;
  }
};

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);

  ReadStreamResponse response;
  for (auto i = START; i <= STOP; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadPartialStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);

  ReadStreamResponse response;
  for (auto i = START; i <= STOP / 2; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadTwoStreamsConsecutively_ReturnsExpectedSequences)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  const auto OFFSET = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  request.set_start(START + OFFSET);
  request.set_stop(STOP + OFFSET);
  ::grpc::ClientContext second_context;
  auto second_reader = stub()->ReadStream(&second_context, request);
  reader->WaitForInitialMetadata();

  ReadStreamResponse response;
  for (auto i = START; i <= STOP; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }

  for (auto i = START; i <= STOP; ++i) {
    second_reader->Read(&response);
    EXPECT_EQ(response.value(), i + OFFSET);
  }
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadPartialStream_ShutdownServerBeforeCancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  ReadStreamResponse response;
  for (auto i = START; i <= STOP / 2; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }

  shutdown();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadStream_ShutdownServerBeforeCancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);

  ReadStreamResponse response;
  for (auto i = START; i <= STOP; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
  }

  shutdown();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadTwoStreamsInterleaved_ReturnsExpectedSequences)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  const auto OFFSET = 100;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  request.set_start(START + OFFSET);
  request.set_stop(STOP + OFFSET);
  ::grpc::ClientContext second_context;
  auto second_reader = stub()->ReadStream(&second_context, request);
  reader->WaitForInitialMetadata();

  ReadStreamResponse response;
  for (auto i = START; i <= STOP; ++i) {
    reader->Read(&response);
    EXPECT_EQ(response.value(), i);
    second_reader->Read(&response);
    EXPECT_EQ(response.value(), i + OFFSET);
  }
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, StartReadStream_ShutdownBeforeRead_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);

  reader.reset();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, WaitForMetadata_Cancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  reader->WaitForInitialMetadata();

  reader.reset();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, WaitForMetadata_ShutdownAndRead_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  ReadStreamRequest request;
  request.set_start(START);
  request.set_stop(STOP);
  auto reader = stub()->ReadStream(&context, request);
  reader->WaitForInitialMetadata();

  shutdown();
  ReadStreamResponse response;
  reader->Read(&response);
}

const auto CALLBACK_DATA_OUT = 1234;
ACTION(ImmediatelyCallCallback)
{
  auto& callback_function = arg1;
  auto& callback_token = arg2;
  callback_function(CALLBACK_DATA_OUT, callback_token);
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, RegisterCallbackAndImmediatelyCall_ReadAsyncResponse_CallbackDataIncludedInResponse)
{
  const myInt16 TEST_VALUE = 25;
  ::grpc::ClientContext context;
  RegisterCallbackRequest request;
  request.set_input_data(TEST_VALUE);
  EXPECT_CALL(library_, RegisterCallback(TEST_VALUE, _, _))
      .WillOnce(DoAll(
          ImmediatelyCallCallback(),
          Return(kDriverSuccess)));
  auto reader = stub()->RegisterCallback(&context, request);
  reader->WaitForInitialMetadata();

  RegisterCallbackResponse response;
  auto status = reader->Read(&response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(CALLBACK_DATA_OUT, response.data_out());
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
