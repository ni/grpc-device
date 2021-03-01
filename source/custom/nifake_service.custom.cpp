#include <nifake/nifake_service.h>

#include <atomic>
#include <fstream>
#include <iostream>
#include <sstream>

namespace ni {
namespace fake {
namespace grpc {

namespace internal = ni::hardware::grpc::internal;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiFakeService::GetAStringUsingPythonCode(::grpc::ServerContext* context, const GetAStringUsingPythonCodeRequest* request, GetAStringUsingPythonCodeResponse* response)
{
  try {
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());
    ViInt32 a_number = request->a_number();

    std::string a_string(a_number, '\0');
    auto status = library_->GetAStringUsingPythonCode(vi, a_number, (ViChar*)a_string.data());
    response->set_status(status);
    if (status == 0) {
      response->set_a_string(a_string);
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiFakeService::GetArrayForPythonCodeDouble(::grpc::ServerContext* context, const GetArrayForPythonCodeDoubleRequest* request, GetArrayForPythonCodeDoubleResponse* response)
{
  try {
    return ::grpc::Status(::grpc::UNIMPLEMENTED, "TODO: This server handler has not been implemented.");
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiFakeService::GetArrayForPythonCodeCustomType(::grpc::ServerContext* context, const GetArrayForPythonCodeCustomTypeRequest* request, GetArrayForPythonCodeCustomTypeResponse* response)
{
  try {
    return ::grpc::Status(::grpc::UNIMPLEMENTED, "TODO: This server handler has not been implemented.");
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace grpc
}  // namespace fake
}  // namespace ni
