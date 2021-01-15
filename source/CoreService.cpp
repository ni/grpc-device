#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <thread>
#include <CoreService.h>

grpc::Status CoreService::GetServerStatus(::grpc::ServerContext* context, const ServerStatus* status)
{
   status = true;
   return grpc::Status::OK;
}
