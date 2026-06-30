#include "tls_config_loader.h"

#include <stdexcept>
#include <string>

#include "nierr_Status.h"

namespace {
// RAII wrapper for nierr_Status. nierr_Status is a plain C struct with no
// destructor, so the json heap buffer must be freed explicitly. This wrapper
// does that automatically and provides helper methods matching the repo
// convention (see NIErrStatusOutputConverter in
// source/custom/nimxlcterminaladaptor_restricted_converters.h).
struct NiErrStatusGuard {
  nierr_Status status;
  NiErrStatusGuard() { nierr_Status_initialize(&status); }
  ~NiErrStatusGuard() { nierr_Status_jsonFree(&status); }
  NiErrStatusGuard(const NiErrStatusGuard&) = delete;
  NiErrStatusGuard& operator=(const NiErrStatusGuard&) = delete;
  bool is_fatal() const { return nierr_Status_isFatal(&status); }
  // Returns the json detail string, or empty string if none.
  std::string detail() const { return status.json ? status.json : ""; }
  // Allows passing &guard directly to C functions expecting nierr_Status*.
  nierr_Status* operator&() { return &status; }
};
}  // namespace

namespace nidevice_grpc {

#if defined(_MSC_VER)
static const char* kNiTlsConfigLibraryName = "nitlsconfig.dll";
#else
static const char* kNiTlsConfigLibraryName = "libnitlsconfig.so";
#endif

TlsConfigLoader::TlsConfigLoader()
    : library_(kNiTlsConfigLibraryName),
      is_available_(false),
      read_certificate_mode_(nullptr),
      read_client_mode_(nullptr),
      read_certificate_chain_contents_(nullptr),
      read_certificate_key_contents_(nullptr),
      read_trusted_certificates_contents_(nullptr)
{
  library_.load();
  if (!library_.is_loaded()) {
    return;
  }

  read_certificate_mode_ = reinterpret_cast<ReadCertificateModeFunc>(
      library_.get_function_pointer("nitlsconfig_server_readCertificateMode"));
  read_client_mode_ = reinterpret_cast<ReadClientModeFunc>(
      library_.get_function_pointer("nitlsconfig_server_readClientMode"));
  read_certificate_chain_contents_ = reinterpret_cast<ReadContentsFunc>(
      library_.get_function_pointer("nitlsconfig_server_readCertificateChainContents"));
  read_certificate_key_contents_ = reinterpret_cast<ReadContentsFunc>(
      library_.get_function_pointer("nitlsconfig_server_readCertificateKeyContents"));
  read_trusted_certificates_contents_ = reinterpret_cast<ReadContentsFunc>(
      library_.get_function_pointer("nitlsconfig_server_readTrustedCertificatesContents"));

  is_available_ = read_certificate_mode_ != nullptr &&
      read_client_mode_ != nullptr &&
      read_certificate_chain_contents_ != nullptr &&
      read_certificate_key_contents_ != nullptr &&
      read_trusted_certificates_contents_ != nullptr;
}

bool TlsConfigLoader::is_available() const
{
  return is_available_;
}

ServerSecurityConfiguration TlsConfigLoader::get_server_credentials(
    const std::string& service_name) const
{
  if (!is_available_) {
    throw std::runtime_error("ni-tls-config: library is not available");
  }

  uint32_t mode = CertificateMode_Unknown;
  NiErrStatusGuard s;
  // The int32_t return value mirrors nierr_Status.code; checking is_fatal() on
  // the status struct is sufficient and also captures the JSON detail string.
  (void)read_certificate_mode_(service_name.c_str(), &mode, &s);
  if (s.is_fatal()) {
    throw std::runtime_error(
        "ni-tls-config: failed to read certificate mode for service: " +
        service_name + (s.detail().empty() ? "" : (" (" + s.detail() + ")")));
  }

  switch (static_cast<CertificateMode>(mode)) {
    case CertificateMode_Disabled:
      return ServerSecurityConfiguration();
    case CertificateMode_Unmanaged:
    case CertificateMode_ManagedSelfSigned:
      break;
    case CertificateMode_Unknown:
    default:
      throw std::runtime_error(
          "ni-tls-config: unsupported certificate mode " +
          std::to_string(mode) + " for service: " + service_name);
  }

  auto cert_chain = read_contents(
      service_name, read_certificate_chain_contents_, "certificate chain");
  auto cert_key = read_contents(
      service_name, read_certificate_key_contents_, "certificate key");

  uint32_t client_mode = ClientMode_Unknown;
  NiErrStatusGuard sc;
  (void)read_client_mode_(service_name.c_str(), &client_mode, &sc);
  if (sc.is_fatal()) {
    throw std::runtime_error(
        "ni-tls-config: failed to read client mode for service: " +
        service_name + (sc.detail().empty() ? "" : (" (" + sc.detail() + ")")));
  }

  std::string root_cert;
  if (client_mode != ClientMode_Disabled) {
    root_cert = read_contents(
        service_name, read_trusted_certificates_contents_, "trusted certificates");
  }

  return ServerSecurityConfiguration(cert_chain, cert_key, root_cert);
}

std::string TlsConfigLoader::read_contents(
    const std::string& service_name,
    ReadContentsFunc func,
    const char* description) const
{
  constexpr size_t kBufferSize = 4096;
  std::string contents(kBufferSize, '\0');
  size_t actual_size = 0;

  NiErrStatusGuard s;
  (void)func(service_name.c_str(), contents.data(), kBufferSize, &actual_size, &s);
  if (s.is_fatal()) {
    throw std::runtime_error(
        std::string("ni-tls-config: failed to read ") + description +
        " contents for service: " + service_name +
        (s.detail().empty() ? "" : (" (" + s.detail() + ")")));
  }

  if (actual_size > kBufferSize) {
    contents.resize(actual_size, '\0');
    NiErrStatusGuard s2;
    (void)func(service_name.c_str(), contents.data(), actual_size, &actual_size, &s2);
    if (s2.is_fatal()) {
      throw std::runtime_error(
          std::string("ni-tls-config: failed to read ") + description +
          " contents for service: " + service_name +
          (s2.detail().empty() ? "" : (" (" + s2.detail() + ")")));
    }
  }

  contents.resize(std::strlen(contents.c_str()));
  return contents;
}

}  // namespace nidevice_grpc
