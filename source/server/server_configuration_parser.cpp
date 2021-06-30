#include "server_configuration_parser.h"

#include <climits>
#include <iostream>
#include <sstream>

#include "feature_toggles.h"

#if defined(_MSC_VER)
  #include <windows.h>
#else
  #include <unistd.h>
#endif

namespace nidevice_grpc {

static const char* kDefaultFilename = "server_config.json";
static const char* kPortJsonKey = "port";
static const char* kServerCertJsonKey = "server_cert";
static const char* kServerKeyJsonKey = "server_key";
static const char* kRootCertJsonKey = "root_cert";
static const char* kSecurityJsonKey = "security";
static const char* kCertsFolderName = "certs";
static const char* kFeatureTogglesKey = "feature_toggles";
#if defined(_MSC_VER)
static const char* kPathDelimitter = "\\";
#else
static const char* kPathDelimitter = "/";
#endif

ServerConfigurationParser::ServerConfigurationParser()
    : config_file_(load(get_exe_path() + kDefaultFilename)), certs_directory_(get_exe_path() + kCertsFolderName)
{
}

ServerConfigurationParser::ServerConfigurationParser(const std::string& config_file_path)
    : config_file_path_(config_file_path),
      config_file_(load(config_file_path)),
      certs_directory_(get_certs_directory(config_file_path))
{
}

ServerConfigurationParser::ServerConfigurationParser(const nlohmann::json& config_file)
    : config_file_(config_file), certs_directory_(get_exe_path() + kCertsFolderName)
{
}

// Returns the absolute path to the folder that contains the running executable.
// The path includes the trailing platform-dependent delimitter (i.e. /path/to/exe/folder/
// or C:\path\to\exe\folder\) and does not contain the executable name. This function is
// public for test use.
std::string ServerConfigurationParser::get_exe_path()
{
#if defined(_MSC_VER)
  char filename[MAX_PATH];
  size_t path_length = GetModuleFileNameA(NULL, filename, MAX_PATH);
#else
  char filename[PATH_MAX];
  ssize_t path_length = readlink("/proc/self/exe", filename, PATH_MAX);
#endif
  if (path_length <= 0) {
    throw InvalidExePathException();
  }
  std::string exe_filename(filename, path_length);
  return exe_filename.erase(exe_filename.find_last_of(kPathDelimitter) + 1);
}

std::string ServerConfigurationParser::get_certs_directory(const std::string& config_file_path)
{
  std::string directory_path(config_file_path);
  size_t end_of_path_index = directory_path.find_last_of(kPathDelimitter);
  return end_of_path_index != std::string::npos
      ? directory_path.erase(end_of_path_index + 1) + kCertsFolderName
      : kCertsFolderName;
}

nlohmann::json ServerConfigurationParser::load(const std::string& config_file_path)
{
  std::ifstream input_stream(config_file_path);

  if (!input_stream) {
    throw ConfigFileNotFoundException(config_file_path);
  }

  try {
    return nlohmann::json::parse(input_stream);
  }
  catch (const nlohmann::json::parse_error& ex) {
    throw MalformedJsonException(ex.what());
  }
}

std::string ServerConfigurationParser::parse_address() const
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

std::string ServerConfigurationParser::parse_server_cert() const
{
  auto file_name = parse_key_from_security_section(kServerCertJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimitter + file_name);
}

std::string ServerConfigurationParser::parse_server_key() const
{
  auto file_name = parse_key_from_security_section(kServerKeyJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimitter + file_name);
}

std::string ServerConfigurationParser::parse_root_cert() const
{
  auto file_name = parse_key_from_security_section(kRootCertJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimitter + file_name);
}

FeatureToggles ServerConfigurationParser::parse_feature_toggles() const
{
  FeatureToggleConfigurationMap map;
  auto feature_toggle_section_it = config_file_.find(kFeatureTogglesKey);
  if (feature_toggle_section_it != config_file_.end()) {
    try {
      for (const auto& feature : feature_toggle_section_it->items()) {
        map[feature.key()] = feature.value();
      }
    }
    catch (const nlohmann::json::type_error& ex) {
      throw InvalidFeatureToggleException(ex.what());
    }
  }
  return FeatureToggles(std::move(map));
}

std::string ServerConfigurationParser::parse_key_from_security_section(const char* key) const
{
  std::string parsed_value;

  auto security_section_it = config_file_.find(kSecurityJsonKey);
  if (security_section_it != config_file_.end()) {
    auto it = security_section_it->find(key);
    if (it != security_section_it->end()) {
      try {
        parsed_value = it->get<std::string>();
      }
      catch (const nlohmann::json::type_error&) {
        throw ValueTypeNotStringException(key);
      }
    }
  }
  return parsed_value;
}

std::string ServerConfigurationParser::read_keycert(const std::string& filename)
{
  std::string data;
  std::ifstream file(filename);
  if (!file) {
    throw FileNotFoundException(filename);
  }
  std::stringstream key_cert_contents;
  key_cert_contents << file.rdbuf();
  file.close();
  data = key_cert_contents.str();
  return data;
}

ServerConfigurationParser::ConfigFileNotFoundException::ConfigFileNotFoundException(const std::string& config_file_path)
    : std::runtime_error(kConfigFileNotFoundMessage + config_file_path)
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

ServerConfigurationParser::ValueTypeNotStringException::ValueTypeNotStringException(const std::string& key)
    : std::runtime_error(kValueTypeNotStringMessage + key)
{
}

ServerConfigurationParser::FileNotFoundException::FileNotFoundException(const std::string& filepath)
    : std::runtime_error(kFileNotFoundMessage + filepath)
{
}

ServerConfigurationParser::InvalidExePathException::InvalidExePathException()
    : std::runtime_error(kInvalidExePathMessage)
{
}

ServerConfigurationParser::InvalidFeatureToggleException::InvalidFeatureToggleException(const std::string& type_error_details)
    : std::runtime_error(kInvalidFeatureToggleMessage + type_error_details)
{
}
}  // namespace nidevice_grpc
