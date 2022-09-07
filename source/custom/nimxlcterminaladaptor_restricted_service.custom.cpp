#include <iostream>
#include <vector>
#include <server/converters.h>
#include <nierr_Status.h>
#include <nimxlcterminaladaptor_restricted.pb.h>
#include <nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_service.h>
#include <custom/nimxlcterminaladaptor_restricted_converters.h>

namespace nimxlcterminaladaptor_restricted_grpc {
  
  using nidevice_grpc::converters::allocate_output_storage;
  using nidevice_grpc::converters::convert_to_grpc;
  using nimxlcterminaladaptor_restricted_grpc::NIErrStatus;
  
// Provide a callback that only returns false because we initialize json to nullptr on initialization.
bool nierr_noOpReallocJson(struct nierr_Status * s, uint32_t size)
{
   return false;
}

void nierr_Status_initialize(struct nierr_Status * status)
{
   status->code = 0;
   status->capacity = 0;
   status->reallocJson = &nierr_noOpReallocJson;
   status->json = nullptr;
}

class DeviceContainerPtr
{
    public:
    DeviceContainerPtr(NimxlcTerminalAdaptorRestrictedLibraryInterface* library, nimxlc_DeviceContainer container) {
        library_ = library;
        container_ = container;
    }

    ~DeviceContainerPtr() {
        library_->DeviceContainer_destroy(container_);
        container_ = nullptr;
        library_ = nullptr;
    }

    operator nimxlc_DeviceContainer*()
    {
        return &container_;
    }

    private:
    nimxlc_DeviceContainer container_;
    NimxlcTerminalAdaptorRestrictedLibraryInterface* library_;
};

class TerminalContainerPtr
{
    public:
    TerminalContainerPtr(NimxlcTerminalAdaptorRestrictedLibraryInterface* library, nimxlc_TerminalContainer container) {
        library_ = library;
        container_ = container;
    }

    ~TerminalContainerPtr() {
        library_->TerminalContainer_destroy(container_);
        container_ = nullptr;
        library_ = nullptr;
    }

    operator nimxlc_TerminalContainer*()
    {
        return &container_;
    }

    private:
    nimxlc_TerminalContainer container_;
    NimxlcTerminalAdaptorRestrictedLibraryInterface* library_;
};

::grpc::Status NimxlcTerminalAdaptorRestrictedService::GetDeviceContainer(::grpc::ServerContext* context, const GetDeviceContainerRequest* request, GetDeviceContainerResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto grpc_session = request->session();
        nimxlc_Session session = session_repository_->access_session(grpc_session.id(), grpc_session.name());

        nierr_Status status;
        nimxlcterminaladaptor_restricted_grpc::nierr_Status_initialize(&status);
       
        DeviceContainerPtr deviceContainerPtr(library_, library_->getDeviceContainer(session, &status));
        if (nierr_Status_isNotFatal(&status))
        {
            nimxlc_DeviceIterator deviceIterator = library_->DeviceContainer_begin(*deviceContainerPtr);
            while (!library_->DeviceIterator_isEnd(*deviceContainerPtr, deviceIterator) && nierr_Status_isNotFatal(&status))
            {
                auto device = response->add_container_out();
                device->set_name(library_->DeviceIterator_getDeviceName(*deviceContainerPtr, deviceIterator, &status));
                device->set_supportsonboardclock(library_->DeviceIterator_supportsOnBoardClock(*deviceContainerPtr, deviceIterator, &status));

                TerminalContainerPtr terminalContainerPtr(library_, library_->DeviceIterator_getTerminalContainer(*deviceContainerPtr, deviceIterator, &status));
                if (nierr_Status_isNotFatal(&status))
                {
                    nimxlc_TerminalIterator terminalIterator = library_->TerminalContainer_begin(*terminalContainerPtr);
                    while (!library_->TerminalIterator_isEnd(*terminalContainerPtr, terminalIterator) && nierr_Status_isNotFatal(&status))
                    {
                        auto terminal = device->add_terminals();
                        terminal->set_name(library_->TerminalIterator_getTerminalName(*terminalContainerPtr, terminalIterator, &status));
                        terminal->set_visibility(library_->TerminalIterator_getVisibility(*terminalContainerPtr, terminalIterator, &status));

                        library_->TerminalIterator_next(&terminalIterator);
                    }
                }
                
                library_->DeviceIterator_next(&deviceIterator);
            }
        }

        response->set_status((&status)->code);

        ::grpc::Status grpcStatus;
        if (nierr_Status_isFatal(&status)){
            grpcStatus = ::grpc::Status(::grpc::INTERNAL, status.json);
        }
        else {
            grpcStatus = ::grpc::Status::OK;
        }
        return grpcStatus;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
        return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
}

::grpc::Status NimxlcTerminalAdaptorRestrictedService::ConvertApiErrorStatusForNimxlc_Session(::grpc::ServerContext* context, int32_t status, nimxlc_Session session)
{
    std::string description;
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nimxlcterminaladaptor_restricted_grpc
