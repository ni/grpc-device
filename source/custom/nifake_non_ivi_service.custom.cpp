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

::grpc::Status NiFakeNonIviService::OutputVarArgs(::grpc::ServerContext* context, const OutputVarArgsRequest* request, OutputVarArgsResponse* response)
{
  auto input_name = request->input_name().c_str();
  auto channel_names = request->channel_names();
  if (channel_names.size() == 0) {
    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No values for channel_names were specified");
  }
  if (channel_names.size() > 4) {
    return ::grpc::Status(::grpc::INVALID_ARGUMENT, "More than 4 values for channel_names were specified");
  }
  auto get_channelName_if = [](const google::protobuf::RepeatedPtrField<std::string>& vector, int n) -> const char* {
    if (vector.size() > n) {
      return vector[n].c_str();
    }
    return nullptr;
  };
  auto get_color_if = [](std::vector<int32>& vector, int n) -> int32* {
    if (vector.size() > n) {
      return &(vector[n]);
    }
    return nullptr;
  };
  std::vector<int32> colors(channel_names.size());
  auto status = library_->OutputVarArgs(input_name, get_channelName_if(channel_names, 0), get_color_if(colors, 0), get_channelName_if(channel_names, 1), get_color_if(colors, 1), get_channelName_if(channel_names, 2), get_color_if(colors, 2), get_channelName_if(channel_names, 3), get_color_if(colors, 3));
  for (int i = 0; i < channel_names.size(); ++i) {
    response->add_colors(static_cast<BeautifulColor>(colors[i]));
  }
  response->set_status(status);
  return ::grpc::Status::OK;
}
}  // namespace nifake_non_ivi_grpc
