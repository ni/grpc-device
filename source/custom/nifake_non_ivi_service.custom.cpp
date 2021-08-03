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

// Note: this is a contrived callback implementation that depends on the callback being immediately called on register.
// It is used to exercise the other levels of codegen associated with unpacking and forwarding callback params.
::grpc::Status NiFakeNonIviService::RegisterCallback(::grpc::ServerContext* context, const RegisterCallbackRequest* request, RegisterCallbackResponse* response)
{
  using FakeCallbackRouter = nidevice_grpc::CallbackRouter<int32, int32>;

  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto registration = FakeCallbackRouter::register_handler([&](int32 val) { 
      response->set_echo_data(request->input_data());
      return 0; });
    auto status = library_->RegisterCallback(request->input_data(), FakeCallbackRouter::handle_callback, registration->token());
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

::grpc::Status NiFakeNonIviService::InputVarArgs(::grpc::ServerContext* context, const InputVarArgsRequest* request, InputVarArgsResponse* response)
{
  auto get_string_if = [](const google::protobuf::RepeatedPtrField<StringAndEnum>& vector, size_t n) -> const char* {
    if (vector.size() > n) {
      return vector[n].mystring().c_str();
    }
    return nullptr;
  };
  auto get_enum_if = [](const google::protobuf::RepeatedPtrField<StringAndEnum>& vector, size_t n) -> BeautifulColor {
    if (vector.size() > n) {
      return vector[n].myenum();
    }
    return static_cast<BeautifulColor>(0);
  };
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto name = request->input_name();
    auto varargs = request->string_and_enums();
    if (varargs.size() == 0) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "No values for string_and_enums were specified");
    }
    if (varargs.size() > 5) {
      return ::grpc::Status(::grpc::INVALID_ARGUMENT, "More than 5 values for string_and_enums were specified");
    }
    auto status = library_->InputVarArgs(name.c_str(), get_string_if(varargs, 0), get_enum_if(varargs, 0), get_string_if(varargs, 1), get_enum_if(varargs, 1), get_string_if(varargs, 2), get_enum_if(varargs, 2), get_string_if(varargs, 3), get_enum_if(varargs, 3), get_string_if(varargs, 4), get_enum_if(varargs, 4));
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}
}  // namespace nifake_non_ivi_grpc
