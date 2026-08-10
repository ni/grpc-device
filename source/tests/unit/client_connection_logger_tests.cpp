#include <gtest/gtest.h>
#include <server/client_connection_logger.h>

namespace ni {
namespace tests {
namespace unit {

namespace {
::testing::AssertionResult parses_to(const std::string& peer, const std::string& expected_ip, const std::string& expected_port)
{
  std::string ip;
  std::string port;
  if (!nidevice_grpc::parse_peer(peer, ip, port)) {
    return ::testing::AssertionFailure() << "parse_peer(\"" << peer << "\") returned false";
  }
  if (ip != expected_ip || port != expected_port) {
    return ::testing::AssertionFailure()
        << "parse_peer(\"" << peer << "\") returned ip=\"" << ip << "\", port=\"" << port
        << "\", expected ip=\"" << expected_ip << "\", port=\"" << expected_port << "\"";
  }
  return ::testing::AssertionSuccess();
}
}  // namespace

TEST(ClientConnectionLoggerTests, Ipv4Peer_ParsePeer_ReturnsTrueAndSplitsIpAndPort)
{
  EXPECT_TRUE(parses_to("ipv4:127.0.0.1:12345", "127.0.0.1", "12345"));
}

TEST(ClientConnectionLoggerTests, Ipv6Peer_ParsePeer_ReturnsTrueAndSplitsIpAndPort)
{
  EXPECT_TRUE(parses_to("ipv6:[::1]:12345", "[::1]", "12345"));
}

TEST(ClientConnectionLoggerTests, Ipv6PeerWithFullAddress_ParsePeer_ReturnsTrueAndSplitsIpAndPort)
{
  EXPECT_TRUE(parses_to("ipv6:[2001:db8::1]:443", "[2001:db8::1]", "443"));
}

TEST(ClientConnectionLoggerTests, UnrecognizedScheme_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("unix:/tmp/socket", ip, port));
}

TEST(ClientConnectionLoggerTests, EmptyPeer_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv4MissingPort_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv4:127.0.0.1", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv4EmptyPort_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv4:127.0.0.1:", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv4EmptyIp_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv4::12345", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv4SchemeOnly_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv4:", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv6MissingPort_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv6:[::1]", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv6EmptyPort_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv6:[::1]:", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv6EmptyIp_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv6:[]:12345", ip, port));
}

TEST(ClientConnectionLoggerTests, IPv6SchemeOnly_ParsePeer_ReturnsFalse)
{
  std::string ip, port;

  EXPECT_FALSE(nidevice_grpc::parse_peer("ipv6:", ip, port));
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
