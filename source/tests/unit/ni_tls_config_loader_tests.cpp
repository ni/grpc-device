#include <gtest/gtest.h>
#include <server/ni_tls_config_loader.h>

namespace ni {
namespace tests {
namespace unit {

TEST(NiTlsConfigLoaderTests, CreateLoader_WhenNiTlsConfigNotInstalled_IsAvailableReturnsFalse)
{
  nidevice_grpc::NiTlsConfigLoader loader;

  EXPECT_FALSE(loader.is_available());
}

TEST(NiTlsConfigLoaderTests, CreateLoader_WhenNiTlsConfigNotInstalled_GetServerCredentialsThrows)
{
  nidevice_grpc::NiTlsConfigLoader loader;

  EXPECT_THROW(loader.get_server_credentials("ni-grpc-device"), std::runtime_error);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
