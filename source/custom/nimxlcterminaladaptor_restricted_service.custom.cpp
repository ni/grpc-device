#include <vector>
#include <server/converters.h>
#include <nierr_Status.h>
#include <nimxlcterminaladaptor_restricted.pb.h>
#include <nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_service.h>
#include <custom/nimxlcterminaladaptor_restricted_converters.h>

namespace nimxlcterminaladaptor_restricted_grpc {

::grpc::Status NimxlcTerminalAdaptorRestrictedService::GetDeviceContainer(::grpc::ServerContext* context, const GetDeviceContainerRequest* request, GetDeviceContainerResponse* response)
{
    if (context->IsCancelled()) {
        return ::grpc::Status::CANCELLED;
    }
    try {
        auto grpc_session = request->session();
        nimxlc_Session session = session_repository_->access_session(grpc_session.id(), grpc_session.name());

        nierr_Status status;
        nimxlc_DeviceContainer deviceContainer = library_->getDeviceContainer(session, &status);
        if (nierr_Status_isNotFatal(&status))
        {
            nimxlc_DeviceIterator deviceIterator = library_->DeviceContainer_begin(deviceContainer);
            while (!library_->DeviceIterator_isEnd(deviceContainer, deviceIterator) && nierr_Status_isNotFatal(&status))
            {
                auto device = response->add_container_out();
                device->set_name(library_->DeviceIterator_getDeviceName(deviceContainer, deviceIterator, &status));
                device->set_supportsonboardclock(library_->DeviceIterator_supportsOnBoardClock(deviceContainer, deviceIterator, &status));

                nimxlc_TerminalContainer terminalContainer = library_->DeviceIterator_getTerminalContainer(deviceContainer, deviceIterator, &status);
                if (nierr_Status_isNotFatal(&status))
                {
                    nimxlc_TerminalIterator terminalIterator = library_->TerminalContainer_begin(terminalContainer);
                    while (!library_->TerminalIterator_isEnd(terminalContainer, terminalIterator) && nierr_Status_isNotFatal(&status))
                    {
                        auto terminal = device->add_terminals();
                        terminal->set_name(library_->TerminalIterator_getTerminalName(terminalContainer, terminalIterator, &status));
                        terminal->set_visibility(library_->TerminalIterator_getVisibility(terminalContainer, terminalIterator, &status));

                        library_->TerminalIterator_next(&terminalIterator);
                    }
                    library_->TerminalContainer_destroy(terminalContainer);
                }
                
                library_->DeviceIterator_next(&deviceIterator);
            }
        }
        library_->DeviceContainer_destroy(deviceContainer);

        response->set_status(status.code);

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

::grpc::Status NimxlcTerminalAdaptorRestrictedService::ConvertApiErrorStatusForNimxlc_Session(int status,struct undefined_nimxlc_Session *session)
{
    std::string description;
    return nidevice_grpc::ApiErrorAndDescriptionToStatus(status, description);
}

}  // namespace nimxlcterminaladaptor_restricted_grpc
