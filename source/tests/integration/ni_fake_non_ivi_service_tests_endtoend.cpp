#include <gmock/gmock.h>
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

  auto start_read_stream(
    ::grpc::ClientContext& context,
    int32_t start,
    int32_t stop)
  {
    ReadStreamRequest request;
    request.set_start(start);
    request.set_stop(stop);
    return stub()->ReadStream(&context, request);
  }

  template <typename TResponse>
  bool read_stream(
    ::grpc::ClientReader<TResponse>& reader,
    size_t count,
    std::vector<TResponse>* responses = nullptr)
  {
    TResponse response;
    for (size_t i = 0; i < count; ++i) {
      if (!reader.Read(&response)) {
        return false;
      }
      if (responses) {
        responses->push_back(response);
      }
    }
    return true;
  }

  size_t get_range_length(int32_t start, int32_t stop)
  {
    return static_cast<size_t>(stop - start + 1);
  }

  std::vector<int32_t> make_range(int32_t start, int32_t stop)
  {
    std::vector<int32_t> range;
    range.reserve(get_range_length(start, stop));
    for (int32_t i = start; i <= stop; ++i) {
      range.push_back(i);
    }
    return range;
  }

  std::vector<int32_t> get_values(const std::vector<ReadStreamResponse>& responses) {
    std::vector<int32_t> values;
    for (auto& response : responses) {
      values.push_back(response.value());
    }
    return values;
  }
};

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  auto reader = start_read_stream(context, START, STOP);
  auto expected_values = make_range(START, STOP);

  std::vector<ReadStreamResponse> responses;
  bool read_success = read_stream(*reader, expected_values.size(), &responses);

  EXPECT_TRUE(read_success);
  EXPECT_THAT(get_values(responses), ContainerEq(expected_values));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadPartialStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  auto reader = start_read_stream(context, START, STOP);
  auto expected_values = make_range(START, STOP / 2);

  std::vector<ReadStreamResponse> responses;
  bool read_success = read_stream(*reader, expected_values.size(), &responses);

  EXPECT_TRUE(read_success);
  EXPECT_THAT(get_values(responses), ContainerEq(expected_values));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadTwoStreamsConsecutively_ReturnsExpectedSequences)
{
  ::grpc::ClientContext context1, context2;
  const auto START = 0;
  const auto STOP = 100;
  const auto OFFSET = 100;
  auto reader1 = start_read_stream(context1, START, STOP);
  auto reader2 = start_read_stream(context2, START + OFFSET, STOP + OFFSET);
  reader1->WaitForInitialMetadata();
  reader2->WaitForInitialMetadata();
  auto expected_values1 = make_range(START, STOP);
  auto expected_values2 = make_range(START + OFFSET, STOP + OFFSET);

  std::vector<ReadStreamResponse> responses1, responses2;
  bool read_success1 = read_stream(*reader1, expected_values1.size(), &responses1);
  bool read_success2 = read_stream(*reader2, expected_values2.size(), &responses2);

  EXPECT_TRUE(read_success1);
  EXPECT_TRUE(read_success2);
  EXPECT_THAT(get_values(responses1), ContainerEq(expected_values1));
  EXPECT_THAT(get_values(responses2), ContainerEq(expected_values2));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadPartialStream_ShutdownServerBeforeCancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  auto reader = start_read_stream(context, START, STOP);
  ASSERT_TRUE(read_stream(*reader, get_range_length(START, STOP / 2)));

  shutdown();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadStream_ShutdownServerBeforeCancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 100;
  auto reader = start_read_stream(context, START, STOP);
  ASSERT_TRUE(read_stream(*reader, get_range_length(START, STOP)));

  shutdown();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, ReadTwoStreamsInterleaved_ReturnsExpectedSequences)
{
  ::grpc::ClientContext context1, context2;
  const auto START = 0;
  const auto STOP = 100;
  const auto OFFSET = 100;
  auto reader1 = start_read_stream(context1, START, STOP);
  auto reader2 = start_read_stream(context2, START + OFFSET, STOP + OFFSET);
  reader1->WaitForInitialMetadata();
  reader2->WaitForInitialMetadata();
  auto expected_values1 = make_range(START, STOP);
  auto expected_values2 = make_range(START + OFFSET, STOP + OFFSET);

  std::vector<ReadStreamResponse> responses1, responses2;
  bool read_success1 = true, read_success2 = true;
  for (auto i = START; i <= STOP; ++i) {
    read_success1 = read_success1 && read_stream(*reader1, 1, &responses1);
    read_success2 = read_success2 && read_stream(*reader2, 1, &responses2);
  }

  EXPECT_TRUE(read_success1);
  EXPECT_TRUE(read_success2);
  EXPECT_THAT(get_values(responses1), ContainerEq(expected_values1));
  EXPECT_THAT(get_values(responses2), ContainerEq(expected_values2));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, StartReadStream_ShutdownBeforeRead_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);

  reader.reset();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, WaitForMetadata_Cancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);
  reader->WaitForInitialMetadata();

  reader.reset();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, WaitForMetadata_ShutdownAndRead_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 0;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);
  reader->WaitForInitialMetadata();

  shutdown();
  (void) read_stream(*reader, get_range_length(START, STOP));
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
  bool read_success = reader->Read(&response);

  EXPECT_TRUE(read_success);
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(CALLBACK_DATA_OUT, response.data_out());
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
