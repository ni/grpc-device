#include "server_configuration_parser.h"

#include <climits>
#include <iostream>
#include <sstream>

#if defined(_MSC_VER)
  #include <windows.h>
#else
  #include <unistd.h>
#endif

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

static const char* kDefaultAddressPrefix = "[::]:";
static const char* kDefaultFilename = "server_config.json";
static const char* kPortJsonKey = "port";
static const char* kServerCertJsonKey = "server_cert";
static const char* kServerKeyJsonKey = "server_key";
static const char* kRootCertKeyJsonKey = "root_cert";
static const char* kSecurityJsonKey = "security";

ServerConfigurationParser::ServerConfigurationParser()
    : config_file_(load(get_exe_path() + kDefaultFilename))
{
}

ServerConfigurationParser::ServerConfigurationParser(const char* config_file_path)
    : config_file_path_(config_file_path), config_file_(load(config_file_path))
{
}

ServerConfigurationParser::ServerConfigurationParser(const nlohmann::json& config_file)
    : config_file_(config_file)
{
}

std::string ServerConfigurationParser::get_exe_path()
{
#if defined(_MSC_VER)
  char filename[MAX_PATH];
  GetModuleFileNameA(NULL, filename, MAX_PATH);
  std::string exe_filename(filename);
  return exe_filename.erase(exe_filename.find_last_of("\\") + 1);
#else
  char filename[PATH_MAX];
  readlink("/proc/self/exe", filename, PATH_MAX);
  std::string exe_filename(filename);
  return exe_filename.erase(exe_filename.find_last_of("/") + 1);
#endif
}

nlohmann::json ServerConfigurationParser::load(const std::string& config_file_path)
{
  // TODO: Prefer a passed in configuration file path and then search next to
  // the binary and finally at platform specific default config file locations.
  std::ifstream input_stream(config_file_path);

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

  auto it = config_file_.find(kPortJsonKey);
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
  return kDefaultAddressPrefix + std::to_string(parsed_port);
}

std::string ServerConfigurationParser::parse_server_cert()
{
  auto file_path = parse_security_string(kServerCertJsonKey);
  return read_keycert(file_path);
}

std::string ServerConfigurationParser::parse_server_key()
{
  auto file_path = parse_security_string(kServerKeyJsonKey);
  return read_keycert(file_path);
}

std::string ServerConfigurationParser::parse_root_cert()
{
  auto file_path = parse_security_string(kRootCertKeyJsonKey);
  return read_keycert(file_path);
}

std::string ServerConfigurationParser::parse_security_string(const char* key)
{
  std::string parsed_value;

  auto security_section_it =  config_file_.find(kSecurityJsonKey);
  if (security_section_it != config_file_.end()) {
    auto it = security_section_it->find(key);
    if (it != security_section_it->end()) {
      try {
        parsed_value = it->get<std::string>();
      }
      catch (const nlohmann::json::type_error& ex) {

        //throw WrongPortTypeException(ex.what());
      }
    }
  }
  return parsed_value;
}

std::string ServerConfigurationParser::read_keycert(const std::string& filename)
{	
	std::string data;
	std::ifstream file(filename);
	if (file)
	{
		std::stringstream key_cert_contents;
		key_cert_contents << file.rdbuf();
		file.close();
		data = key_cert_contents.str();
	}
	return data;
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
