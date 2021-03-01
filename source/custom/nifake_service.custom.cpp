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
    return ::grpc::Status(::grpc::UNIMPLEMENTED, "TODO: This server handler has not been implemented.");
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

}  // namespace grpc
}  // namespace fake
}  // namespace ni
