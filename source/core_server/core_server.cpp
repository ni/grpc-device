#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/server_configuration_parser.h"

static void RunServer(int argc, char** argv)
{
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  std::string server_address;
  try {
    //TODO: parse config file path from command line argument
    ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser;
    server_address = server_config_parser.parse_address();
  }
  catch (const std::exception& ex) {
    std::cerr << "\nERROR:\n\n"
              << ex.what() << "\n\nExiting.\n"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  // Listen on the given address without any authentication mechanism.
  grpc::ServerBuilder builder;
  int* listeningPort = new int(0);
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials(), listeningPort);

  // Register services available on the server.
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::CoreService core_service(&session_repository);
  builder.RegisterService(&core_service);

  // Assemble the server.
  auto server = builder.BuildAndStart();

  if (!server) {
    std::cout << "Server failed to start on " << server_address << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Server listening on port " << *listeningPort << std::endl;
  // This call will block until another thread shuts down the server.
  server->Wait();
}

int main(int argc, char** argv)
{
  RunServer(argc, argv);
  return 0;
}
