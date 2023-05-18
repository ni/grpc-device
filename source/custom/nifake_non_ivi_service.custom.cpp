#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/callback_router.h>
#include <server/server_reactor.h>

#include <memory>
#include <thread>
namespace nifake_non_ivi_grpc {

::grpc::ServerWriteReactor<ReadStreamResponse>* NiFakeNonIviService::ReadStream(::grpc::CallbackServerContext* context, const ReadStreamRequest* request)
{
  // Wraps a thread to call join on destruct.
  struct AutoJoinThread {
    static std::unique_ptr<AutoJoinThread> make_auto_join(std::thread&& thread)
    {
      return std::make_unique<AutoJoinThread>(std::move(thread));
    }
    AutoJoinThread(std::thread&& thread) : thread_(std::move(thread))
    {
    }
    ~AutoJoinThread() { thread_.join(); }
    std::thread thread_;
  };

  class ReadStreamReactor : public nidevice_grpc::ServerWriterReactor<ReadStreamResponse, AutoJoinThread> {
   public:
    const int32_t MIN_VALUE = 0;
    const int32_t MAX_VALUE = 1000000;

    ReadStreamReactor(const ReadStreamRequest* request)
    {
      auto status = start(request);
      if (!status.ok()) {
        this->try_finish(std::move(status));
      }
    }

    ::grpc::Status start(const ReadStreamRequest* request) {
      if (request->start() < MIN_VALUE || request->start() > MAX_VALUE) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for start is out of range.");
      }
      if (request->stop() < MIN_VALUE || request->stop() > MAX_VALUE) {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for stop is out of range.");
      }
      if (request->start() > request->stop()) {
        // This error has a different status code and an arbitrary delay for testing purposes.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return ::grpc::Status(::grpc::UNKNOWN, "The values for start and stop are reversed.");
      }

      // Send initial metadata to indicate that the stream has started successfully.
      StartSendInitialMetadata();

      this->set_producer(start_thread(request->start(), request->stop()));
      return ::grpc::Status::OK;
    }

    std::unique_ptr<AutoJoinThread> start_thread(int32_t start, int32_t stop)
    {
      return AutoJoinThread::make_auto_join(std::thread([=]() {
        ReadStreamResponse response;
        for (auto i = start; i <= stop; ++i) {
          response.set_value(i);
          queue_write(response);
        }
      }));
    }
  };

  return new ReadStreamReactor(request);
}

::grpc::Status NiFakeNonIviService::ConvertApiErrorStatusForFakeHandle(::grpc::ServerContextBase* context, int32_t status, FakeHandle handle)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetLatestErrorMessage(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status NiFakeNonIviService::ConvertApiErrorStatusForSecondarySessionHandle(::grpc::ServerContextBase* context, int32_t status, SecondarySessionHandle handle)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->GetLatestErrorMessage(&description[0], nidevice_grpc::kMaxGrpcErrorDescriptionSize);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nifake_non_ivi_grpc
