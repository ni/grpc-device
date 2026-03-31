#include <gtest/gtest.h>
#include <server/tls_config_loader.h>

namespace ni {
namespace tests {
namespace unit {

TEST(TlsConfigLoaderTests, CreateLoader_WhenNiTlsConfigNotInstalled_IsAvailableReturnsFalse)
{
  nidevice_grpc::TlsConfigLoader loader;

  EXPECT_FALSE(loader.is_available());
}

TEST(TlsConfigLoaderTests, CreateLoader_WhenNiTlsConfigNotInstalled_GetServerCredentialsThrows)
{
  nidevice_grpc::TlsConfigLoader loader;

  EXPECT_THROW(loader.get_server_credentials("ni-grpc-device"), std::runtime_error);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
