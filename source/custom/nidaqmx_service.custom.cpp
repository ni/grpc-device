#include <nidaqmx/nidaqmx_service.h>
#include <server/callback_router.h>
#include <server/server_reactor.h>

#include <memory>
#include <thread>

namespace nidaqmx_grpc {

using DoneEventCallbackRouter = nidevice_grpc::CallbackRouter<int32, TaskHandle, int32>;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::ServerWriteReactor<RegisterDoneEventResponse>*
NiDAQmxService::RegisterDoneEvent(::grpc::CallbackServerContext* context, const RegisterDoneEventRequest* request)
{
  class RegisterDoneEventReactor : public nidevice_grpc::ServerWriterReactor<RegisterDoneEventResponse, nidevice_grpc::CallbackRegistration> {
   public:
    RegisterDoneEventReactor(const RegisterDoneEventRequest& request, NiDAQmxLibraryInterface* library, const ResourceRepositorySharedPtr& session_repository)
    {
      this->set_producer(
          start(request, library, session_repository));
    }

    std::unique_ptr<nidevice_grpc::CallbackRegistration> start(const RegisterDoneEventRequest& request, NiDAQmxLibraryInterface* library, const ResourceRepositorySharedPtr& session_repository)
    {
      std::unique_ptr<nidevice_grpc::CallbackRegistration> handler;
      try {
        auto task_grpc_session = request.task();
        TaskHandle task = session_repository->access_session(task_grpc_session.id(), task_grpc_session.name());
        uInt32 options = request.options();

        handler = DoneEventCallbackRouter::register_handler(
            [this](TaskHandle task, int32 callback_status) {
              RegisterDoneEventResponse callback_response;
              callback_response.set_status(callback_status);
              queue_write(callback_response);
              return DAQmxSuccess;
            });

        auto status = library->RegisterDoneEvent(task, options, DoneEventCallbackRouter::handle_callback, handler->token());

        // SendInitialMetadata after the driver call so that WaitForInitialMetadata can be used to ensure that calls are serialized.
        StartSendInitialMetadata();

        if (status) {
          RegisterDoneEventResponse failed_to_register_response;
          failed_to_register_response.set_status(status);
          queue_write(failed_to_register_response);
        }
      }
      catch (nidevice_grpc::LibraryLoadException& ex) {
        this->Finish(::grpc::Status(::grpc::NOT_FOUND, ex.what()));
      }

      return handler;
    }
  };

  return new RegisterDoneEventReactor(*request, library_, session_repository_);
}
}  // namespace nidaqmx_grpc
