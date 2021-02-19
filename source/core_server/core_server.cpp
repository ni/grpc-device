#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/server_configuration_parser.h"
#include "hardware/grpc/internal/server_security_configuration.h"

/*std::shared_ptr<grpc::ServerCredentials> CreateCredentials(ni::hardware::grpc::internal::ServerConfigurationParser& server_config_parser)
{
  std::string server_cert, server_key, root_cert;

	std::shared_ptr<grpc::ServerCredentials> credentials;
  
  server_cert = server_config_parser.parse_server_cert();
  server_key = server_config_parser.parse_server_key();
  root_cert = server_config_parser.parse_root_cert();

	if (server_cert.empty())
	{
    credentials = grpc::InsecureServerCredentials();
	}
	else
	{
		grpc::SslServerCredentialsOptions::PemKeyCertPair key_cert_pair;
		key_cert_pair.private_key = server_key;
		key_cert_pair.cert_chain = server_cert;
		
    grpc::SslServerCredentialsOptions ssl_opts;
		ssl_opts.pem_key_cert_pairs.push_back(key_cert_pair);
    ssl_opts.client_certificate_request = root_cert.empty()
      ? GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE 
      : GRPC_SSL_REQUEST_AND_REQUIRE_CLIENT_CERTIFICATE_AND_VERIFY;
 		ssl_opts.pem_root_certs=root_cert;

		credentials = grpc::SslServerCredentials(ssl_opts);
  }
	return credentials;
}*/

static void RunServer(int argc, char** argv)
{
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  std::string server_address, server_cert, server_key, root_cert;

  std::shared_ptr<grpc::ServerCredentials> credentials;
  try {
    //TODO: parse config file path from command line argument
    ni::hardware::grpc::internal::ServerConfigurationParser server_config_parser;
    server_address = server_config_parser.parse_address();
    server_cert = server_config_parser.parse_server_cert();
    server_key = server_config_parser.parse_server_key();
    root_cert = server_config_parser.parse_root_cert();
  }
  catch (const std::exception& ex) {
    std::cerr << "\nERROR:\n\n"
              << ex.what() << "\n\nExiting.\n";
    exit(EXIT_FAILURE);
  }

  grpc::ServerBuilder builder;
  int listeningPort = 0;
  ni::hardware::grpc::internal::ServerSecurityConfiguration server_security_config(server_cert, server_key, root_cert);
  builder.AddListeningPort(server_address, server_security_config.get_credentials(), &listeningPort);
  // Register services available on the server.
  ni::hardware::grpc::internal::SessionRepository session_repository;
  ni::hardware::grpc::CoreService core_service(&session_repository);
  builder.RegisterService(&core_service);

  // Assemble the server.
  auto server = builder.BuildAndStart();

  if (!server) {
    std::cerr << "Server failed to start on " << server_address << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Server listening on port " << listeningPort << std::endl;
  // This call will block until another thread shuts down the server.
  server->Wait();
}

int main(int argc, char** argv)
{
  RunServer(argc, argv);
  return 0;
}
