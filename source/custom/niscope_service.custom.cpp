#include <niscope/niscope_service.h>

namespace ni {
namespace scope {
namespace grpc {

namespace internal = ni::hardware::grpc::internal;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status NiScopeService::Fetch(::grpc::ServerContext* context, const FetchRequest* request, FetchResponse* response)
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
::grpc::Status NiScopeService::FetchArrayMeasurement(::grpc::ServerContext* context, const FetchArrayMeasurementRequest* request, FetchArrayMeasurementResponse* response)
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
::grpc::Status NiScopeService::FetchBinary16(::grpc::ServerContext* context, const FetchBinary16Request* request, FetchBinary16Response* response)
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
::grpc::Status NiScopeService::FetchBinary8(::grpc::ServerContext* context, const FetchBinary8Request* request, FetchBinary8Response* response)
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
::grpc::Status NiScopeService::FetchMeasurementStats(::grpc::ServerContext* context, const FetchMeasurementStatsRequest* request, FetchMeasurementStatsResponse* response)
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
::grpc::Status NiScopeService::Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response)
{
  try {
    return ::grpc::Status(::grpc::UNIMPLEMENTED, "TODO: This server handler has not been implemented.");
  }
  catch (internal::LibraryLoadException& ex) {
    return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
  }
}

}  // namespace grpc
}  // namespace scope
}  // namespace ni