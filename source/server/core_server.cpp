#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <register_all_services.h>

#include <mutex>

#include "feature_toggles.h"
#include "logging.h"
#include "server_configuration_parser.h"
#include "server_security_configuration.h"

#if defined(__GNUC__)
  #include "linux/daemonize.h"
  #include "linux/syslog_logging.h"
#endif

using FeatureState = nidevice_grpc::FeatureToggles::FeatureState;

struct ServerConfiguration {
  std::string server_address;
  std::string server_cert;
  std::string server_key;
  std::string root_cert;
  int max_message_size;
  nidevice_grpc::FeatureToggles feature_toggles;
};

static ServerConfiguration GetConfiguration(const std::string& config_file_path)
{
  ServerConfiguration config;
  try {
    nidevice_grpc::ServerConfigurationParser server_config_parser = config_file_path.empty()
        ? nidevice_grpc::ServerConfigurationParser()
        : nidevice_grpc::ServerConfigurationParser(config_file_path);
    config.server_address = server_config_parser.parse_address();
    config.server_cert = server_config_parser.parse_server_cert();
    config.server_key = server_config_parser.parse_server_key();
    config.root_cert = server_config_parser.parse_root_cert();
    config.max_message_size = server_config_parser.parse_max_message_size();
    config.feature_toggles = server_config_parser.parse_feature_toggles();
  }
  catch (const std::exception& ex) {
    nidevice_grpc::logging::log(
        nidevice_grpc::logging::Level_Error,
        "Failed to parse config: %s", ex.what());
    exit(EXIT_FAILURE);
  }
  return config;
}

static std::mutex server_mutex;
static std::unique_ptr<grpc::Server> server;
static bool shutdown = false;

static void StopServer()
{
  std::lock_guard<std::mutex> guard(server_mutex);
  shutdown = true;
  if (server) {
    server->Shutdown();
  }
}

static void RunServer(const ServerConfiguration& config)
{
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  grpc::ServerBuilder builder;
  int listeningPort = 0;
  nidevice_grpc::ServerSecurityConfiguration server_security_config(config.server_cert, config.server_key, config.root_cert);
  builder.AddListeningPort(config.server_address, server_security_config.get_credentials(), &listeningPort);

  auto services = nidevice_grpc::register_all_services(builder, config.feature_toggles);

  builder.SetMaxSendMessageSize(config.max_message_size);
  builder.SetMaxReceiveMessageSize(config.max_message_size);

  // Assemble the server.
  {
    std::lock_guard<std::mutex> guard(server_mutex);
    if (shutdown) {
      nidevice_grpc::logging::log(
          nidevice_grpc::logging::Level_Info,
          "Asked to shutdown before creating the server");
      return;
    }
    server = builder.BuildAndStart();
  }

  if (!server) {
    nidevice_grpc::logging::log(
        nidevice_grpc::logging::Level_Error,
        "Server failed to start on %s", config.server_address.c_str());
    exit(EXIT_FAILURE);
  }

  nidevice_grpc::logging::log(nidevice_grpc::logging::Level_Info, "Server listening on port %d", listeningPort);

  const char* security_description = server_security_config.is_insecure_credentials()
      ? "insecure credentials"
      : "secure credentials";
  const char* tls_description = "";
  auto credentials_options = server_security_config.try_get_options();
  if (credentials_options != nullptr) {
    tls_description = credentials_options->client_certificate_request == GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE
        ? " (Server-Side TLS)"
        : " (Mutual TLS)";
  }
  nidevice_grpc::logging::log(
      nidevice_grpc::logging::Level_Info,
      "Security is configured with %s%s.", security_description, tls_description);
  // This call will block until another thread shuts down the server.
  server->Wait();

  // destroy services in reverse order
  while (!services->empty()) {
    services->pop_back();
  }
}

struct Options {
  Options() :
#if defined(__GNUC__)
              daemonize(false),
              use_syslog(false),
              identity("ni_grpc_device_server"),
#endif
              config_file_path()
  {
  }

#if defined(__GNUC__)
  bool daemonize;
  bool use_syslog;
  std::string identity;
#endif
  std::string config_file_path;
};

#if defined(__GNUC__)
const char* usage = "Usage: ni_grpc_device_server [--help] [--daemonize] [--use-syslog] [--identity <foo>] [config-file-path]";
#else
const char* usage = "Usage: ni_grpc_device_server [--help] [config-file-path]";
#endif

Options parse_options(int argc, char** argv)
{
  Options options;
  for (int i = 1; i < argc; ++i) {
    bool known_option = true;
#if defined(__GNUC__)
    if (strcmp("--daemonize", argv[i]) == 0) {
      options.daemonize = true;
    }
    else if (strcmp("--use-syslog", argv[i]) == 0) {
      options.use_syslog = true;
    }
    else if (strcmp("--identity", argv[i]) == 0) {
      if (i + 1 < argc) {
        options.identity = argv[++i];
      }
      else {
        known_option = false;
      }
    }
    else
#endif
    if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
      nidevice_grpc::logging::log(nidevice_grpc::logging::Level_Info, usage);
      exit(EXIT_SUCCESS);
    }
    else if (i == argc - 1) {
      options.config_file_path = argv[i];
    }
    else {
      known_option = false;
    }

    if (!known_option) {
      nidevice_grpc::logging::log(nidevice_grpc::logging::Level_Error, usage);
      exit(EXIT_FAILURE);
    }
  }

#if defined(__GNUC__)
  if (options.daemonize && !options.use_syslog) {
    nidevice_grpc::logging::log(nidevice_grpc::logging::Level_Error, "--daemonize requires --use-syslog");
    exit(EXIT_FAILURE);
  }
#endif

  return options;
}

int main(int argc, char** argv)
{
  auto options = parse_options(argc, argv);
  auto config = GetConfiguration(options.config_file_path);
  setlocale(LC_ALL, "");
#if defined(__GNUC__)
  if (options.use_syslog) {
    nidevice_grpc::logging::setup_syslog(options.daemonize, options.identity);
    nidevice_grpc::logging::set_logger(&nidevice_grpc::logging::log_syslog);
  }

  if (options.daemonize) {
    nidevice_grpc::daemonize(&StopServer, options.identity);
  }
#endif

  RunServer(config);
  return EXIT_SUCCESS;
}
