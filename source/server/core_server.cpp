#include <mutex>
#include <nidcpower/nidcpower_library.h>
#include <nidcpower/nidcpower_service.h>
#include <nidigital/nidigital_library.h>
#include <nidigital/nidigital_service.h>
#include <nidmm/nidmm_library.h>
#include <nidmm/nidmm_service.h>
#include <niscope/niscope_library.h>
#include <niscope/niscope_service.h>
#include <niswitch/niswitch_library.h>
#include <niswitch/niswitch_service.h>
#include <nisync/nisync_library.h>
#include <nisync/nisync_service.h>
#include <nitclk/nitclk_library.h>
#include <nitclk/nitclk_service.h>

#include "logging.h"
#include "server_configuration_parser.h"
#include "server_security_configuration.h"
#include "session_utilities_service.h"
#include "syscfg_library.h"

#if defined(__GNUC__)
  #include "linux/daemonize.h"
  #include "linux/syslog_logging.h"
#endif

struct ServerConfiguration
{
  std::string server_address;
  std::string server_cert;
  std::string server_key;
  std::string root_cert;
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
  // Register services available on the server.
  nidevice_grpc::SessionRepository session_repository;
  nidevice_grpc::SysCfgLibrary syscfg_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_library);
  nidevice_grpc::SessionUtilitiesService core_service(&session_repository, &device_enumerator);
  builder.RegisterService(&core_service);

  nidigital_grpc::NiDigitalLibrary nidigital_library;
  nidigital_grpc::NiDigitalService nidigital_service(&nidigital_library, &session_repository);
  builder.RegisterService(&nidigital_service);

  niscope_grpc::NiScopeLibrary niscope_library;
  niscope_grpc::NiScopeService niscope_service(&niscope_library, &session_repository);
  builder.RegisterService(&niscope_service);

  niswitch_grpc::NiSwitchLibrary niswitch_library;
  niswitch_grpc::NiSwitchService niswitch_service(&niswitch_library, &session_repository);
  builder.RegisterService(&niswitch_service);

  nidmm_grpc::NiDmmLibrary nidmm_library;
  nidmm_grpc::NiDmmService nidmm_service(&nidmm_library, &session_repository);
  builder.RegisterService(&nidmm_service);

  nisync_grpc::NiSyncLibrary nisync_library;
  nisync_grpc::NiSyncService nisync_service(&nisync_library, &session_repository);
  builder.RegisterService(&nisync_service);

  nitclk_grpc::NiTClkLibrary nitclk_library;
  nitclk_grpc::NiTClkService nitclk_service(&nitclk_library, &session_repository);
  builder.RegisterService(&nitclk_service);
  
  nidcpower_grpc::NiDCPowerLibrary nidcpower_library;
  nidcpower_grpc::NiDCPowerService nidcpower_service(&nidcpower_library, &session_repository);
  builder.RegisterService(&nidcpower_service);

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
  // This code is currently unreachable, but if the call to wait exits, we need to clean up the service here.
  session_repository.reset_server();
  device_enumerator.clear_syscfg_session();
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
