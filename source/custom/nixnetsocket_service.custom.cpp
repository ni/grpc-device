#include <nixnetsocket/nixnetsocket_service.h>

#include <atomic>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "xnetsocket_converters.h"

namespace nixnetsocket_grpc {

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= 0;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiXnetSocketService::GetSocketOption(::grpc::ServerContext* context, const GetSocketOptionRequest* request, GetSocketOptionResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto socket_grpc_session = request->socket();
    nxSOCKET socket = session_repository_->access_session(socket_grpc_session.id(), socket_grpc_session.name());
    int32_t level = request->level();
    int32_t opt_name;
    switch (request->opt_name_enum_case()) {
      case nixnetsocket_grpc::GetSocketOptionRequest::OptNameEnumCase::kOptName: {
        opt_name = static_cast<int32_t>(request->opt_name());
        break;
      }
      case nixnetsocket_grpc::GetSocketOptionRequest::OptNameEnumCase::kOptNameRaw: {
        opt_name = static_cast<int32_t>(request->opt_name_raw());
        break;
      }
      case nixnetsocket_grpc::GetSocketOptionRequest::OptNameEnumCase::OPT_NAME_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for opt_name was not specified or out of range");
        break;
      }
    }

    response->mutable_optval()->set_opt(request->opt_name());
    nxsocklen_t optlen{};
    int32_t status;
    switch (request->opt_name()) {
      case SocketOptions::SOCKET_OPTIONS_RX_DATA:
      case SocketOptions::SOCKET_OPTIONS_RCV_BUF:
      case SocketOptions::SOCKET_OPTIONS_SND_BUF: {
        int32_t data = 0;
        optlen = static_cast<nxsocklen_t>(sizeof(data));
        status = library_->GetSocketOption(socket, level, opt_name, &data, &optlen);
        response->set_status(status);
        if (status_ok(status)) {
          response->mutable_optval()->set_data_int32(data);
        }
        break;
      }
      case SocketOptions::SOCKET_OPTIONS_NON_BLOCK:
      case SocketOptions::SOCKET_OPTIONS_LINGER:
      case SocketOptions::SOCKET_OPTIONS_REUSE_ADDR: {
        bool data_bool = false;
        status = library_->GetSocketOption(socket, level, opt_name, &data_bool, &optlen);
        response->set_status(status);
        if (status_ok(status)) {
          response->mutable_optval()->set_data_bool(data_bool);
        }
        break;
      }
      case SocketOptions::SOCKET_OPTIONS_BIND_TO_DEVICE:
      case SocketOptions::SOCKET_OPTIONS_ERROR: {
        std::string data_string(256 - 1, '\0');  // Guessing here that max is 256... don't know how to figure out actual max size for string options.
        status = library_->GetSocketOption(socket, level, opt_name, (char*)(data_string.data()), &optlen);
        response->set_status(status);
        if (status_ok(status)) {
          response->mutable_optval()->set_data_string(data_string);
          nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_optval()->mutable_data_string()));
        }
        break;
      }
      default:
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for opt_name was not recognized.");
    }
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace nixnetsocket_grpc
