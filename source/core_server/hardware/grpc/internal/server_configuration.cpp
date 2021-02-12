#include "server_configuration.h"
#include <iostream>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
const char* ServerConfigurationParser::kLocalhostAddressPrefix = "0.0.0.0:";
const char* ServerConfigurationParser::kDefaultFilename = "server_config.json";
const char* ServerConfigurationParser::kPortKey = "port";
const char* ServerConfigurationParser::kConfigFileNotFoundMessage = "The server configuration file was not found.";
const char* ServerConfigurationParser::kInvalidPortMessage = "The specified port number must between 0 and 65535.";

ServerConfigurationParser::ServerConfigurationParser()
{
  config_file_ = ServerConfigurationParser::load("");
}

ServerConfigurationParser::ServerConfigurationParser(const char* config_file_path)
  : config_file_path_(config_file_path)
{
  config_file_ = ServerConfigurationParser::load(config_file_path);
}

ServerConfigurationParser::ServerConfigurationParser(const nlohmann::json& config_file)
  : config_file_(config_file)
{
    std::cout << "Using JSON constructor" << std::endl;
}

nlohmann::json ServerConfigurationParser::load(const char* config_file_path)
{
  // TODO: Prefer a passed in configuration file path and then search next to
  // the binary and finally at platform specific default config file locations.
  std::string file_path;
  if (config_file_path == "") {
    file_path = kDefaultFilename;
  }
  else {
    file_path = config_file_path;
  }
  
  std::ifstream input_stream(file_path);
  if (!input_stream) {
    throw ConfigFileNotFoundException();
  }
  return nlohmann::json::parse(input_stream);
}

std::string ServerConfigurationParser::parse_address()
{
  int parsed_port = -1;
  std::string key(kPortKey);
  auto it = config_file_.find(key);
  if (it != config_file_.end()) {
      parsed_port = config_file_[key].get<int>();
  }
   
  if (parsed_port < 0 || parsed_port > USHRT_MAX) {
    throw InvalidPortException();
  }
  return kLocalhostAddressPrefix + std::to_string(parsed_port);
}

ServerConfigurationParser::ConfigFileNotFoundException::ConfigFileNotFoundException()
  : std::runtime_error(std::string(kConfigFileNotFoundMessage))
{
}

ServerConfigurationParser::InvalidPortException::InvalidPortException()
  : std::runtime_error(std::string(kInvalidPortMessage))
{
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
