#include <nifake/nifake_service.h>

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
    ViStatus status = library_->GetAStringUsingPythonCode(vi, a_number, (ViChar*)a_string.data());
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
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());

    ViInt32 number_of_elements;
    ViStatus status = library_->GetArraySizeForPythonCode(vi, &number_of_elements);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    response->mutable_array_out()->Resize(number_of_elements, 0);
    ViReal64* array_out = response->mutable_array_out()->mutable_data();
    status = library_->GetArrayForPythonCodeDouble(vi, number_of_elements, array_out);
    response->set_status(status);
    return ::grpc::Status::OK;
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
    auto session = request->vi();
    ViSession vi = session_repository_->access_session(session.id(), session.name());

    ViInt32 number_of_elements;
    ViStatus status = library_->GetArraySizeForPythonCode(vi, &number_of_elements);
    if (status != 0) {
      response->set_status(status);
      return ::grpc::Status::OK;
    }

    std::vector<CustomStruct> array_out(number_of_elements);
    status = library_->GetArrayForPythonCodeCustomType(vi, number_of_elements, array_out.data());
    response->set_status(status);
    if (status == 0) {
      Copy(array_out, response->mutable_array_out());
    }
    return ::grpc::Status::OK;
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace grpc
}  // namespace fake
}  // namespace ni
