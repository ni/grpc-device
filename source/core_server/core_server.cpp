#include "hardware/grpc/core_service.h"
#include "nlohmann/json.hpp"
#include <fstream>

const char* klocalhostAddress = "0.0.0.0:";

static std::string GetServerAddress(int argc, char** argv)
{
      std::ifstream i("server.json");
      nlohmann::json config_file;
      i >> config_file;
      auto port = config_file["port"].get<int>();
      return klocalhostAddress + std::to_string(port);
}

static void RunServer(int argc, char** argv)
{
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  grpc::ServerBuilder builder;
  auto server_address = GetServerAddress();

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Register services available on the server.
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::CoreService core_service(&session_repository);
  builder.RegisterService(&core_service);

  // Assemble the server.
  auto server = builder.BuildAndStart();
  int* foo = nullptr;

  std::cout << "Server listening on " << server_address << std::endl;

  // This call will block until another thread shuts down the server.
  server->Wait();
}

int main(int argc, char** argv)
{
  RunServer(argc, argv);
  return 0;
}
