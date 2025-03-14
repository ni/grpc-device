#include "server_configuration_parser.h"

#include <climits>
#include <iostream>
#include <sstream>

#include "feature_toggles.h"
#include "moniker_stream_processor.h"

#if defined(_MSC_VER)
  #include <windows.h>
#else
  #include <unistd.h>
#endif

namespace nidevice_grpc {

static const char* kDefaultFilename = "server_config.json";
static const char* kAddressJsonKey = "address";
static const char* kPortJsonKey = "port";
static const char* kSidebandAddressJsonKey = "sideband_address";
static const char* kSidebandPortJsonKey = "sideband_port";
static const char* kMonikerStreamProcessorKey = "moniker_stream_processor_configuration";
static const char* kMonikerSidebandStreamReadWriteKey = "moniker_sideband_stream_read_write";
static const char* kMonikerStreamWriteKey = "moniker_stream_write";
static const char* kMonikerStreamReadKey = "moniker_stream_read";
static const char* kMonikerStreamReadWriteKey = "moniker_stream_read_write";
static const char* kServerCertJsonKey = "server_cert";
static const char* kServerKeyJsonKey = "server_key";
static const char* kRootCertJsonKey = "root_cert";
static const char* kSecurityJsonKey = "security";
static const char* kCertsFolderName = "certs";
static const char* kMaxMessageSizeKey = "max_message_size";
static const char* kFeatureTogglesKey = "feature_toggles";
static const char* kCodeReadinessKey = "code_readiness";
#if defined(_MSC_VER)
static const char* kPathDelimiter = "\\";
#else
static const char* kPathDelimiter = "/";
#endif

ServerConfigurationParser::ServerConfigurationParser()
    : config_file_path_(get_exe_path() + kDefaultFilename),
      certs_directory_(get_exe_path() + kCertsFolderName)
{
   load_config_file();
}

ServerConfigurationParser::ServerConfigurationParser(const std::string& config_file_path)
    : config_file_path_(config_file_path),
      certs_directory_(get_certs_directory(config_file_path))
{
   load_config_file();
}

ServerConfigurationParser::ServerConfigurationParser(const nlohmann::json& config_file)
    : config_file_(config_file), certs_directory_(get_exe_path() + kCertsFolderName)
{
}

// Returns the absolute path to the folder that contains the running executable.
// The path includes the trailing platform-dependent delimiter (i.e. /path/to/exe/folder/
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
  return exe_filename.erase(exe_filename.find_last_of(kPathDelimiter) + 1);
}

std::string ServerConfigurationParser::get_certs_directory(const std::string& config_file_path)
{
  std::string directory_path(config_file_path);
  size_t end_of_path_index = directory_path.find_last_of(kPathDelimiter);
  return end_of_path_index != std::string::npos
      ? directory_path.erase(end_of_path_index + 1) + kCertsFolderName
      : kCertsFolderName;
}

void ServerConfigurationParser::load_config_file()
{
  std::ifstream input_stream(config_file_path_);

  if (!input_stream) {
    throw ConfigFileNotFoundException(config_file_path_);
  }

  try {
    config_file_ = nlohmann::json::parse(input_stream);
  }
  catch (const nlohmann::json::parse_error& ex) {
    throw MalformedJsonException(ex.what());
  }
}

std::string ServerConfigurationParser::parse_address() const
{
  auto address = parse_bind_address() + ":" + std::to_string(parse_port());
  return address;
}

std::string ServerConfigurationParser::parse_sideband_address() const
{
  auto it = config_file_.find(kSidebandAddressJsonKey);
  return it != config_file_.end() ? it->get<std::string>() : "";
}

std::string ServerConfigurationParser::parse_server_cert() const
{
  auto file_name = parse_key_from_security_section(kServerCertJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimiter + file_name);
}

std::string ServerConfigurationParser::parse_server_key() const
{
  auto file_name = parse_key_from_security_section(kServerKeyJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimiter + file_name);
}

std::string ServerConfigurationParser::parse_root_cert() const
{
  auto file_name = parse_key_from_security_section(kRootCertJsonKey);
  return file_name.empty() ? "" : read_keycert(certs_directory_ + kPathDelimiter + file_name);
}

int ServerConfigurationParser::parse_max_message_size() const
{
  auto max_size_section_it = config_file_.find(kMaxMessageSizeKey);
  if (max_size_section_it != config_file_.end()) {
    try {
      return max_size_section_it->get<int>();
    }
    catch (const nlohmann::json::type_error& ex) {
      throw InvalidMaxMessageSizeException(ex.what());
    }
  }

  return UNLIMITED_MAX_MESSAGE_SIZE;
}

int ServerConfigurationParser::parse_sideband_port() const
{
  try {
    return parse_port_with_key(kSidebandPortJsonKey);
  }
  catch (const UnspecifiedPortException&) {
    return DEFAULT_SIDEBAND_PORT;
  }
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
  return FeatureToggles(std::move(map), parse_code_readiness());
}

FeatureToggles::CodeReadiness ServerConfigurationParser::parse_code_readiness() const
{
  auto code_readiness_it = config_file_.find(kCodeReadinessKey);
  if (code_readiness_it != config_file_.end()) {
    try {
      auto readiness_token_value = code_readiness_it->get<std::string>();
      std::transform(
          readiness_token_value.begin(),
          readiness_token_value.end(),
          readiness_token_value.begin(),
          [](unsigned char c) { return std::tolower(c); });

      using ReadinessMap = std::unordered_map<std::string, FeatureToggles::CodeReadiness>;
      const auto READINESS_MAP = ReadinessMap{
          {"release", FeatureToggles::CodeReadiness::kRelease},
          {"restrictedrelease", FeatureToggles::CodeReadiness::kRelease},
          {"restricted_release", FeatureToggles::CodeReadiness::kRelease},
          {"nextrelease", FeatureToggles::CodeReadiness::kNextRelease},
          {"next_release", FeatureToggles::CodeReadiness::kNextRelease},
          {"restrictednextrelease", FeatureToggles::CodeReadiness::kNextRelease},
          {"restricted_next_release", FeatureToggles::CodeReadiness::kNextRelease},
          {"incomplete", FeatureToggles::CodeReadiness::kIncomplete},
          {"prototype", FeatureToggles::CodeReadiness::kPrototype}};

      const auto readiness_map_iter = READINESS_MAP.find(readiness_token_value);
      if (readiness_map_iter != READINESS_MAP.end()) {
        return readiness_map_iter->second;
      }

      throw InvalidCodeReadinessException(readiness_token_value);
    }
    catch (const nlohmann::json::type_error& ex) {
      throw InvalidCodeReadinessException(ex.what());
    }
  }

  return FeatureToggles::CodeReadiness::kRelease;
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

std::string ServerConfigurationParser::parse_bind_address() const
{
  // Use default address if none is specified
  std::string parsed_bind_address = kDefaultAddress;

  auto it = config_file_.find(kAddressJsonKey);
  if (it != config_file_.end()) {
    try {
      parsed_bind_address = it->get<std::string>();
    }
    catch (const nlohmann::json::type_error& ex) {
      throw WrongAddressTypeException(ex.what());
    }

    if (parsed_bind_address.empty()) {
      throw InvalidAddressException();
    }
  }

  return parsed_bind_address;
}

int ServerConfigurationParser::parse_port() const
{
  return parse_port_with_key(kPortJsonKey);
}

int ServerConfigurationParser::parse_port_with_key(const std::string& key) const
{
  int parsed_port = -1;

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

  return parsed_port;
}

MonikerStreamProcessor ServerConfigurationParser::parse_moniker_stream_processor() const
{
    MonikerStreamProcessor stream_processor;

    auto core_config_it = config_file_.find(kMonikerStreamProcessorKey);
    if (core_config_it != config_file_.end()) {
        stream_processor.moniker_sideband_stream_read_write = parse_moniker_stream_processor_with_key(kMonikerSidebandStreamReadWriteKey);
        stream_processor.moniker_stream_write = parse_moniker_stream_processor_with_key(kMonikerStreamWriteKey);
        stream_processor.moniker_stream_read = parse_moniker_stream_processor_with_key(kMonikerStreamReadKey);
        stream_processor.moniker_stream_read_write = parse_moniker_stream_processor_with_key(kMonikerStreamReadWriteKey);
    }
    return stream_processor;
}

int ServerConfigurationParser::parse_moniker_stream_processor_with_key(const std::string& key) const
{
    int parsed_core = -1;

    auto it = config_file_.find(key);
    if (it != config_file_.end()) {
        try {
            parsed_core = it->get<int>();
        }
        catch (const nlohmann::json::type_error& ex) {
            throw WrongMonikerStreamProcessorTypeException(ex.what());
        }
    }

    if (parsed_core < -1) {
        throw InvalidMonikerStreamProcessorException();
    }

    return parsed_core;
}

ServerConfigurationParser::ConfigFileNotFoundException::ConfigFileNotFoundException(const std::string& config_file_path)
    : std::runtime_error(kConfigFileNotFoundMessage + config_file_path)
{
}

ServerConfigurationParser::InvalidAddressException::InvalidAddressException()
    : std::runtime_error(kInvalidAddressMessage)
{
}

ServerConfigurationParser::WrongAddressTypeException::WrongAddressTypeException(const std::string& type_error_details)
    : std::runtime_error(kWrongAddressTypeMessage + type_error_details)
{
}

ServerConfigurationParser::InvalidPortException::InvalidPortException()
    : std::runtime_error(kInvalidPortMessage)
{
}

ServerConfigurationParser::InvalidMonikerStreamProcessorException::InvalidMonikerStreamProcessorException()
    : std::runtime_error(kInvalidMonikerStreamProcessorMessage)
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

ServerConfigurationParser::WrongMonikerStreamProcessorTypeException::WrongMonikerStreamProcessorTypeException(const std::string& type_error_details)
    : std::runtime_error(kWrongMonikerStreamProcessorTypeMessage + type_error_details)
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

ServerConfigurationParser::InvalidCodeReadinessException::InvalidCodeReadinessException(const std::string& type_error_details)
    : std::runtime_error(kInvalidCodeReadinessMessage + type_error_details)
{
}

ServerConfigurationParser::InvalidMaxMessageSizeException::InvalidMaxMessageSizeException(const std::string& type_error_details)
    : std::runtime_error(kInvalidMaxMessageSizeMessage + type_error_details)
{
}
}  // namespace nidevice_grpc
