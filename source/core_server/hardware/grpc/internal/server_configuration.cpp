#include "server_configuration.h"
#include <iostream>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
const char* ServerConfiguration::kLocalhostAddressPrefix = "0.0.0.0:";
const char* ServerConfiguration::kDefaultFilename = "server.json";
const char* ServerConfiguration::kPortKey = "port";
const char* ServerConfiguration::kConfigFileNotFoundMessage = "The server configuration file was not found.";
const char* ServerConfiguration::kInvalidPortMessage = "The specified port number must between 0 and 65535.";

ServerConfiguration::ServerConfiguration(std::string config_file_path)
  : config_file_path_(config_file_path), config_file_(nlohmann::json())
{
}

ServerConfiguration::ServerConfiguration(nlohmann::json config_file)
  : config_file_path_(std::string()), config_file_(config_file)
{
}

void ServerConfiguration::parse_config()
{
  if(config_file_.empty()) {
    // TODO: Prefer a passed in configuration file path and then search next to
    // the binary and finally at platform specific default config file locations.
    std::string file_path;
    if (config_file_path_.empty()) {
      file_path = kDefaultFilename;
    }
    else {
      file_path = config_file_path_;
    }
    
    std::ifstream input_stream(file_path);
    if (!input_stream) {
      throw ConfigFileNotFoundException();
    }
    config_file_ = nlohmann::json::parse(input_stream);
  }
}

std::string ServerConfiguration::get_address()
{
   int parsed_port = -1;
   parse_config();
   if (!config_file_.empty()) {
      std::string key(kPortKey);
      auto it = config_file_.find(key);
      if (it != config_file_.end()) {
         parsed_port = config_file_[key].get<int>();
      }
   }
   
   if (parsed_port < 0 || parsed_port > USHRT_MAX) {
      throw InvalidPortException();
   }
   return kLocalhostAddressPrefix + std::to_string(parsed_port);
}

ServerConfiguration::ConfigFileNotFoundException::ConfigFileNotFoundException()
  : std::runtime_error(std::string(kConfigFileNotFoundMessage))
{
}

ServerConfiguration::InvalidPortException::InvalidPortException()
  : std::runtime_error(std::string(kInvalidPortMessage))
{
}
}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
