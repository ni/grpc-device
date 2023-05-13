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
    ReadStreamReactor(int32 start, int32 stop)
        : start_(start),
          stop_(stop)
    {
      this->set_producer(
          start_thread());
    }

    std::unique_ptr<AutoJoinThread> start_thread()
    {
      return AutoJoinThread::make_auto_join(std::thread([=]() {
        ReadStreamResponse response;
        for (auto i = start_; i <= stop_; ++i) {
          response.set_value(i);
          queue_write(response);
        }
      }));
    }

    int32 start_;
    int32 stop_;
  };

  return new ReadStreamReactor(
      request->start(),
      request->stop());
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
