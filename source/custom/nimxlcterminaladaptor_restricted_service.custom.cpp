#include <custom/nimxlcterminaladaptor_restricted_converters.h>
#include <nierr_Status.h>
#include <nimxlcterminaladaptor_restricted.pb.h>
#include <nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_service.h>
#include <server/converters.h>

#include <iostream>
#include <map>

namespace nimxlcterminaladaptor_restricted_grpc {

using nidevice_grpc::converters::allocate_output_storage;
using nidevice_grpc::converters::convert_to_grpc;
using nimxlcterminaladaptor_restricted_grpc::NIErrStatus;

class DeviceContainerPtr {
 public:
  DeviceContainerPtr(NimxlcTerminalAdaptorRestrictedLibraryInterface* library, nimxlc_DeviceContainer container)
  {
    library_ = library;
    container_ = container;
  }

  ~DeviceContainerPtr()
  {
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

class TerminalContainerPtr {
 public:
  TerminalContainerPtr(NimxlcTerminalAdaptorRestrictedLibraryInterface* library, nimxlc_TerminalContainer container)
  {
    library_ = library;
    container_ = container;
  }

  ~TerminalContainerPtr()
  {
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
    nimxlc_Session session = session_repository_->access_session(grpc_session.name());

    auto status = allocate_output_storage<nierr_Status, NIErrStatus>(context);
    DeviceContainerPtr deviceContainerPtr(library_.get(), library_->getDeviceContainer(session, &status));
    if (nierr_Status_isNotFatal(&status)) {
      nimxlc_DeviceIterator deviceIterator = library_->DeviceContainer_begin(*deviceContainerPtr);
      while (!library_->DeviceIterator_isEnd(*deviceContainerPtr, deviceIterator) && nierr_Status_isNotFatal(&status)) {
        auto device = response->add_container_out();
        device->set_name(library_->DeviceIterator_getDeviceName(*deviceContainerPtr, deviceIterator, &status));
        device->set_supportsonboardclock(library_->DeviceIterator_supportsOnBoardClock(*deviceContainerPtr, deviceIterator, &status));

        TerminalContainerPtr terminalContainerPtr(library_.get(), library_->DeviceIterator_getTerminalContainer(*deviceContainerPtr, deviceIterator, &status));
        if (nierr_Status_isNotFatal(&status)) {
          nimxlc_TerminalIterator terminalIterator = library_->TerminalContainer_begin(*terminalContainerPtr);
          while (!library_->TerminalIterator_isEnd(*terminalContainerPtr, terminalIterator) && nierr_Status_isNotFatal(&status)) {
            auto terminal = device->add_terminals();
            terminal->set_name(library_->TerminalIterator_getTerminalName(*terminalContainerPtr, terminalIterator, &status));
            terminal->set_visibility(library_->TerminalIterator_getVisibility(*terminalContainerPtr, terminalIterator, &status));

            library_->TerminalIterator_next(&terminalIterator);
          }
        }

        library_->DeviceIterator_next(&deviceIterator);
      }
    }

    int32_t statusCode = (&status)->code;
    response->set_status(statusCode);
    convert_to_grpc(status, response->mutable_c_status());
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

::grpc::Status NimxlcTerminalAdaptorRestrictedService::ConvertApiErrorStatusForNimxlc_Session(::grpc::ServerContextBase* context, int32_t status, nimxlc_Session session)
{
  std::string description;
  auto metadata = context->client_metadata();
  auto iterator = metadata.find("ni-error");
  if (iterator != metadata.end()) {
    description = "Error " + std::string(iterator->second.data(), iterator->second.length()) + " has occurred in nimxlcTerminalAdaptor. Refer to the trailing metadata for details.";
  }

  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nimxlcterminaladaptor_restricted_grpc
