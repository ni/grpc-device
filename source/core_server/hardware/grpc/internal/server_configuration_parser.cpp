#include "server_configuration_parser.h"
#include <iostream>
#include <climits>

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {
  
const char* ServerConfigurationParser::kLocalhostAddressPrefix = "0.0.0.0:";
const char* ServerConfigurationParser::kDefaultFilename = "server_config.json";
const char* ServerConfigurationParser::kPortKey = "port";
const char* ServerConfigurationParser::kConfigFileNotFoundMessage = "The server configuration file was not found at the provided or default locations.";
const char* ServerConfigurationParser::kInvalidPortMessage = "The specified port number must between 0 and 65535.";
const char* ServerConfigurationParser::kMalformedJsonMessage = "The JSON in the server configuration file is malformed: \n\n";
const char* ServerConfigurationParser::kWrongPortTypeMessage = "The server port must be specified in the server's configuration file as an integer: \n\n";
const char* ServerConfigurationParser::kUnspecifiedPortMessage = "The server port must be specified in the server's configuration file.";

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
}

nlohmann::json ServerConfigurationParser::load(const char* config_file_path)
{
  // TODO: Prefer a passed in configuration file path and then search next to
  // the binary and finally at platform specific default config file locations.
  std::string file_path = config_file_path.empty() ? kDefaultFilename : config_file_path;
  
  std::ifstream input_stream(file_path);
  if (!input_stream) {
    throw ConfigFileNotFoundException();
  }

  try {
    return nlohmann::json::parse(input_stream);
  }
  catch (const nlohmann::json::parse_error& ex) {
    throw MalformedJsonException(ex.what());
  }
}

std::string ServerConfigurationParser::parse_address()
{
  int parsed_port = -1;
  std::string key(kPortKey);

  auto it = config_file_.find(key);
  if (it != config_file_.end()) {
      try {
        parsed_port = it->get<int>();
      }
      catch (const nlohmann::json::type_error& ex) {
        throw WrongPortTypeException(ex.what());
      }
  }
  else {
    throw UnspecifiedPortException();
  }
   
  if (parsed_port < 0 || parsed_port > USHRT_MAX) {
    throw InvalidPortException();
  }
  return kLocalhostAddressPrefix + std::to_string(parsed_port);
}

ServerConfigurationParser::ConfigFileNotFoundException::ConfigFileNotFoundException()
  : std::runtime_error(kConfigFileNotFoundMessage)
{
}

ServerConfigurationParser::InvalidPortException::InvalidPortException()
  : std::runtime_error(kInvalidPortMessage)
{
}

ServerConfigurationParser::MalformedJsonException::MalformedJsonException(const std::string& parse_error_details)
  : std::runtime_error(kMalformedJsonMessage + parse_error_details)
{
}

ServerConfigurationParser::WrongPortTypeException::WrongPortTypeException(const std::string& type_error_details)
  : std::runtime_error(kWrongPortTypeMessage + type_error_details)
{
}

ServerConfigurationParser::UnspecifiedPortException::UnspecifiedPortException()
  : std::runtime_error(kUnspecifiedPortMessage)
{
}

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni
