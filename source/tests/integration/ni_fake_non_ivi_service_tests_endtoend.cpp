#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>

#include <atomic>
#include <memory>
#include <thread>

#include <tests/utilities/async_helpers.h>

namespace ni {
namespace tests {
namespace integration {

using namespace ::testing;
using namespace nifake_non_ivi_grpc;

static const char* const kStartOutOfRangeErrorMessage = "The value for start is out of range.";
static const char* const kStopOutOfRangeErrorMessage = "The value for stop is out of range.";
static const char* const kStartAndStopReversedErrorMessage = "The values for start and stop are reversed.";

// Test NiFakeNonIviService using a client stub.
class NiFakeNonIviServiceTests_EndToEnd : public ::testing::Test {
 public:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  using SecondaryResourceRepository = nidevice_grpc::SessionResourceRepository<SecondarySessionHandle>;
  using FakeCrossDriverResourceRepository = nidevice_grpc::SessionResourceRepository<FakeCrossDriverHandle>;
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::shared_ptr<nidevice_grpc::SessionRepository> secondary_session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  std::shared_ptr<SecondaryResourceRepository> secondary_resource_repository_;
  std::shared_ptr<ni::tests::unit::NiFakeNonIviMockLibrary> library_;
  NiFakeNonIviService service_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<NiFakeNonIvi::Stub> stub_;
  std::atomic<bool> shutdown_{false};

  NiFakeNonIviServiceTests_EndToEnd()
      : session_repository_(std::make_shared<nidevice_grpc::SessionRepository>()),
        resource_repository_(std::make_shared<FakeResourceRepository>(session_repository_)),
        secondary_session_repository_(std::make_shared<nidevice_grpc::SessionRepository>()),
        secondary_resource_repository_(std::make_shared<SecondaryResourceRepository>(secondary_session_repository_)),
        library_(std::make_shared<ni::tests::unit::NiFakeNonIviMockLibrary>()),
        service_(library_, resource_repository_, std::make_shared<FakeCrossDriverResourceRepository>(session_repository_), std::make_shared<FakeCrossDriverResourceRepository>(secondary_session_repository_)),
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

  auto async_start_read_stream(
    ::grpc::ClientContext& context,
    ::grpc::CompletionQueue& completion_queue,
    void* tag,
    int32_t start,
    int32_t stop)
  {
    ReadStreamRequest request;
    request.set_start(start);
    request.set_stop(stop);
    return stub()->AsyncReadStream(&context, request, &completion_queue, tag);
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
  EXPECT_CALL(*library_, RegisterCallback(TEST_VALUE, _, _))
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

TEST_F(NiFakeNonIviServiceTests_EndToEnd, InvalidArgument_ReadStream_ReturnsInvalidArgumentError)
{
  ::grpc::ClientContext context;
  const auto START = -1;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);

  bool read_success = read_stream(*reader, 1);

  EXPECT_FALSE(read_success);
  auto status = reader->Finish();
  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_EQ(kStartOutOfRangeErrorMessage, status.error_message());
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, InvalidArgument_Finish_ReturnsInvalidArgumentError)
{
  ::grpc::ClientContext context;
  const auto START = -1;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);

  auto status = reader->Finish();

  EXPECT_EQ(::grpc::INVALID_ARGUMENT, status.error_code());
  EXPECT_EQ(kStartOutOfRangeErrorMessage, status.error_message());
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, InvalidArgument_Cancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = -1;
  const auto STOP = 10;
  auto reader = start_read_stream(context, START, STOP);

  context.TryCancel();
}

// When NiFakeNonIviService::ReadStream() reports a "start and stop reversed" error, it adds an
// arbitrary 100 ms delay before returning the error. WaitForInitialMetadata() should wait for
// this delay to complete.

TEST_F(NiFakeNonIviServiceTests_EndToEnd, StartAndStopReversedAndWaitForMetadata_ReadStream_ReturnsStartAndStopReversedError)
{
  ::grpc::ClientContext context;
  const auto START = 10;
  const auto STOP = 0;
  auto reader = start_read_stream(context, START, STOP);
  reader->WaitForInitialMetadata();

  bool read_success = read_stream(*reader, 1);

  EXPECT_FALSE(read_success);
  auto status = reader->Finish();
  EXPECT_EQ(::grpc::UNKNOWN, status.error_code());
  EXPECT_EQ(kStartAndStopReversedErrorMessage, status.error_message());
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, StartAndStopReversedAndWaitForMetadata_Finish_ReturnsStartAndStopReversedError)
{
  ::grpc::ClientContext context;
  const auto START = 10;
  const auto STOP = 0;
  auto reader = start_read_stream(context, START, STOP);
  reader->WaitForInitialMetadata();

  auto status = reader->Finish();

  EXPECT_EQ(::grpc::UNKNOWN, status.error_code());
  EXPECT_EQ(kStartAndStopReversedErrorMessage, status.error_message());
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, StartAndStopReversedAndWaitForMetadata_Cancel_CleanShutdown)
{
  ::grpc::ClientContext context;
  const auto START = 10;
  const auto STOP = 0;
  auto reader = start_read_stream(context, START, STOP);
  reader->WaitForInitialMetadata();

  context.TryCancel();
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, AsyncReadStream_ReturnsExpectedSequence)
{
  ::grpc::ClientContext context;
  ::grpc::CompletionQueue completion_queue;
  const auto START = 0;
  const auto STOP = 100;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_TAG = (void*)2;
  auto reader = async_start_read_stream(context, completion_queue, START_CALL_TAG, START, STOP);
  auto expected_values = make_range(START, STOP);

  ReadStreamResponse response;
  reader->Read(&response, READ_TAG);
  std::vector<ReadStreamResponse> responses;
  bool read_success = true;
  while (read_success && responses.size() < expected_values.size()) {
    auto completion = get_next_completion(completion_queue);
    if (get_completion_tag(completion) == START_CALL_TAG) {
       ASSERT_TRUE(is_completion_ok(completion));
    }
    else if (get_completion_tag(completion) == READ_TAG) {
      read_success = read_success && is_completion_ok(completion);
      if (is_completion_ok(completion)) {
        responses.push_back(response);
        if (responses.size() < expected_values.size()) {
          reader->Read(&response, READ_TAG);
        }
      }
    }
    else {
      FAIL() << "Unexpected completion: " << PrintToString(completion);
    }
  }

  EXPECT_TRUE(read_success);
  EXPECT_THAT(get_values(responses), ContainerEq(expected_values));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, AsyncReadTwoStreams_ReturnsExpectedSequences)
{
  ::grpc::ClientContext context1, context2;
  ::grpc::CompletionQueue completion_queue;
  const auto START = 0;
  const auto STOP = 100;
  const auto OFFSET = 100;
  const auto START_CALL_TAG1 = (void*)1;
  const auto START_CALL_TAG2 = (void*)2;
  const auto READ_TAG1 = (void*)3;
  const auto READ_TAG2 = (void*)4;
  auto reader1 = async_start_read_stream(context1, completion_queue, START_CALL_TAG1, START, STOP);
  auto reader2 = async_start_read_stream(context2, completion_queue, START_CALL_TAG2, START + OFFSET, STOP + OFFSET);
  auto expected_values1 = make_range(START, STOP);
  auto expected_values2 = make_range(START + OFFSET, STOP + OFFSET);

  ReadStreamResponse response1, response2;
  reader1->Read(&response1, READ_TAG1);
  reader2->Read(&response2, READ_TAG2);
  std::vector<ReadStreamResponse> responses1, responses2;
  bool read_success1 = true, read_success2 = true;
  while (read_success1 && read_success2 && (responses1.size() < expected_values1.size() || responses2.size() < expected_values2.size())) {
    auto completion = get_next_completion(completion_queue);
    if (get_completion_tag(completion) == START_CALL_TAG1 || get_completion_tag(completion) == START_CALL_TAG2) {
       ASSERT_TRUE(is_completion_ok(completion));
    }
    else if (get_completion_tag(completion) == READ_TAG1) {
      read_success1 = read_success1 && is_completion_ok(completion);
      if (is_completion_ok(completion)) {
        responses1.push_back(response1);
        if (responses1.size() < expected_values1.size()) {
          reader1->Read(&response1, READ_TAG1);
        }
      }
    }
    else if (get_completion_tag(completion) == READ_TAG2) {
      read_success2 = read_success2 && is_completion_ok(completion);
      if (is_completion_ok(completion)) {
        responses2.push_back(response2);
        if (responses2.size() < expected_values2.size()) {
          reader2->Read(&response2, READ_TAG2);
        }
      }
    }
    else {
      FAIL() << "Unexpected completion: " << PrintToString(completion);
    }
  }

  EXPECT_TRUE(read_success1);
  EXPECT_TRUE(read_success2);
  EXPECT_THAT(get_values(responses1), ContainerEq(expected_values1));
  EXPECT_THAT(get_values(responses2), ContainerEq(expected_values2));
}

TEST_F(NiFakeNonIviServiceTests_EndToEnd, AsyncStartAndStopReversedAndWaitForMetadata_ReadStreamWithoutBlocking_ReturnsStartAndStopReversedErrorWithoutBlocking)
{
  ::grpc::ClientContext context;
  ::grpc::CompletionQueue completion_queue;
  const auto START = 10;
  const auto STOP = 0;
  const auto START_CALL_TAG = (void*)1;
  const auto READ_INITIAL_METADATA_TAG = (void*)2;
  const auto READ_TAG = (void*)3;
  const auto FINISH_TAG = (void*)4;
  auto reader = async_start_read_stream(context, completion_queue, START_CALL_TAG, START, STOP);
  reader->ReadInitialMetadata(READ_INITIAL_METADATA_TAG);
  ASSERT_EQ(Completion(START_CALL_TAG, true), get_next_completion(completion_queue));
  ASSERT_EQ(Completion(READ_INITIAL_METADATA_TAG, true), get_next_completion(completion_queue));

  ReadStreamResponse response;
  reader->Read(&response, READ_TAG);
  Completion read_completion;
  bool read_completed = try_get_next_completion_without_blocking(completion_queue, read_completion);

  EXPECT_TRUE(read_completed);
  EXPECT_EQ(Completion(READ_TAG, false), read_completion); // read_completion should NOT be OK
  ::grpc::Status status;
  reader->Finish(&status, FINISH_TAG);
  Completion finish_completion;
  bool finish_completed = try_get_next_completion_without_blocking(completion_queue, finish_completion);
  EXPECT_TRUE(finish_completed);
  EXPECT_EQ(Completion(FINISH_TAG, true), finish_completion);
  EXPECT_EQ(::grpc::UNKNOWN, status.error_code());
  EXPECT_EQ(kStartAndStopReversedErrorMessage, status.error_message());
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
