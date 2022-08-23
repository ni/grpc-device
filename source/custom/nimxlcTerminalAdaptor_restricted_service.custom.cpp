#include <vector>
#include <nierr_Status.h>
#include <nimxlcTerminalAdaptor_restricted/nimxlcTerminalAdaptor_restricted_service.h>
#include <custom/nimxlcTerminalAdaptor_restricted_converters.h>

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
            auto deviceVector = std::vector<DeviceInfo>();
            nimxlc_DeviceIterator deviceIterator = library_->DeviceContainer_begin(deviceContainer);
            while (!library_->DeviceIterator_isEnd(deviceContainer, deviceIterator) && nierr_Status_isNotFatal(&status))
            {
                DeviceInfo device;
                device.name = library_->DeviceIterator_getDeviceName(deviceContainer, deviceIterator, &status);
                device.supportsOnBoardClock = library_->DeviceIterator_supportsOnBoardClock(deviceContainer, deviceIterator, &status);

                nimxlc_TerminalContainer terminalContainer = library_->DeviceIterator_getTerminalContainer(deviceContainer, deviceIterator, &status);
                if (nierr_Status_isNotFatal(&status))
                {
                    auto terminalVector = std::vector<TerminalInfo>();
                    nimxlc_TerminalIterator terminalIterator = library_->TerminalContainer_begin(terminalContainer);
                    while (!library_->TerminalIterator_isEnd(terminalContainer, terminalIterator) && nierr_Status_isNotFatal(&status))
                    {
                        TerminalInfo terminal;
                        terminal.name = library_->TerminalIterator_getTerminalName(terminalContainer, terminalIterator, &status);
                        terminal.visibility = library_->TerminalIterator_getVisibility(terminalContainer, terminalIterator, &status);

                        terminalVector.push_back(terminal);
                        library_->TerminalIterator_next(&terminalIterator);
                    }
                    library_->TerminalContainer_destroy(terminalContainer);
                    device.terminals = terminalVector;
                }
                
                deviceVector.push_back(device);
                library_->DeviceIterator_next(&deviceIterator);
            }

            response->set_container_out(new DeviceInfo[deviceVector.length()]);
            for (int i = 0; i < deviceVector.length(); i++)
            {
                devices[i].name = deviceVector[i].name;
                devices[i].supportsOnboardClock = deviceVector[i].supportsOnboardClock;
                devices[i].terminals = new TerminalInfo(deviceVector[i].terminals.length());
                for (int j = 0; j < deviceVector[i].terminals.length(); j++)
                {
                    devices[i].terminals[j].name = deviceVector[i].terminals[j].name;
                    devices[i].terminals[j].visibility = deviceVector[i].terminals[j].visibility;
                }
            }
        }
        library_->DeviceContainer_destroy(deviceContainer);

        response->set_status(status);

        ::grpc::Status grpcStatus;
        if (nierr_Status_isFatal(&status)){
            grpcStatus = ::grpc::Status(::grpc::INTERNAL, status.jsonString);
        }
        else {
            grpcStatus = ::grpc::Status::OK;
        }
        response->set_status(status);
        return status;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
        return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
}
}  // namespace nimxlcterminaladaptor_restricted_grpc
