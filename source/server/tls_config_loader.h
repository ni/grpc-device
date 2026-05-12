#ifndef NIDEVICE_GRPC_TLS_CONFIG_LOADER_H
#define NIDEVICE_GRPC_TLS_CONFIG_LOADER_H

#include <string>

#include "nierr_Status.h"
#include "server_security_configuration.h"
#include "shared_library.h"

namespace nidevice_grpc {

// Dynamically loads the nitlsconfig library (if installed) and reads per-service
// TLS configuration from it.  The library is never a link-time dependency.
class TlsConfigLoader {
 public:
  TlsConfigLoader();
  ~TlsConfigLoader() = default;

  TlsConfigLoader(const TlsConfigLoader&) = delete;
  TlsConfigLoader& operator=(const TlsConfigLoader&) = delete;

  // Returns true only when the library was found and all function pointers resolved.
  bool is_available() const;

  // Reads TLS configuration for the given service and returns the corresponding
  // server credentials.  When certificate_mode is Disabled, returns insecure
  // credentials.  Throws std::runtime_error on any other failure.
  ServerSecurityConfiguration get_server_credentials(const std::string& service_name) const;

 private:
  // C enum values that mirror the nitlsconfig ABI (do not rename/reorder).
  enum CertificateMode {
    CertificateMode_Disabled = 0,
    CertificateMode_Unmanaged = 1,
    CertificateMode_ManagedSelfSigned = 2,
    CertificateMode_Unknown = 255,
  };

  // C enum values that mirror the nitlsconfig ABI (do not rename/reorder).
  enum ClientMode {
    ClientMode_Disabled = 0,
    ClientMode_Unmanaged = 1,
    ClientMode_ManagedSelfSigned = 2,
    ClientMode_Unknown = 255,
  };

  using ReadCertificateModeFunc = int32_t (*)(const char*, uint32_t*, nierr_Status*);
  using ReadClientModeFunc = int32_t (*)(const char*, uint32_t*, nierr_Status*);
  using ReadContentsFunc = int32_t (*)(const char*, char*, size_t, size_t*, nierr_Status*);

  std::string read_contents(
      const std::string& service_name,
      ReadContentsFunc func,
      const char* description) const;

  SharedLibrary library_;
  bool is_available_;

  ReadCertificateModeFunc read_certificate_mode_;
  ReadClientModeFunc read_client_mode_;
  ReadContentsFunc read_certificate_chain_contents_;
  ReadContentsFunc read_certificate_key_contents_;
  ReadContentsFunc read_trusted_certificates_contents_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_TLS_CONFIG_LOADER_H
