#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#include <nixnetsocket/nixnetsocket_client.h>

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "device_server.h"
#include "enumerate_devices.h"

using namespace nixnetsocket_grpc;
namespace client = nixnetsocket_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;
using nlohmann::json;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto INVALID_XNET_SOCKET = -1;
constexpr auto GENERIC_NXSOCKET_ERROR = -1;
constexpr auto INVALID_SOCKET_ERROR = -13008;
constexpr auto INVALID_SOCKET_MESSAGE = "The specified socket could not be found.";
constexpr auto INVALID_IP_STACK_ERROR = -13009;
constexpr auto INVALID_IP_STACK_MESSAGE = "The specified IP Stack could not be found.";
constexpr auto NXSOCKET_FALSE = 0;
constexpr auto NXSOCKET_TRUE = 1;

constexpr auto SCHEMA = "file:///NIXNET_Documentation/xnetIpStackSchema-03.json";
const auto SIMPLE_INTERFACE_CONFIG = R"(      
        {
          "address": "inherit",
          "VLANs": [
            {
              "IPv4": {
                "mode": "static",
                "staticAddresses": [
                  {
                    "address": "192.22.33.44",
                    "subnetMask": "255.0.0.0"
                  }
                ],
                "gatewayAddresses": [
                  {
                    "address": "10.2.129.1"
                  }
                ]
              }
            }
          ]
        }
)"_json;

const auto MULTI_ADDRESS_INTERFACE_CONFIG = R"(      
        {
          "address": "inherit",
          "VLANs": [
            {
              "IPv4": {
                "mode": "static",
                "staticAddresses": [
                  {
                    "address": "192.22.11.22",
                    "subnetMask": "255.0.0.0"
                  },
                  {
                    "address": "192.23.45.67",
                    "subnetMask": "255.0.0.0"
                  }
                ],
                "gatewayAddresses": [
                  {
                    "address": "10.2.129.1"
                  }
                ]
              },
              "IPv6": {
                "mode": "enabled",
                "staticAddresses": [
                  {
                    "address": "2001:DB8:0:0:8:800:200C:417A/32"
                  }
                ],
                "gatewayAddresses": [
                  {
                    "address": "FF01::1"
                  }
                ]
              }
            }
          ]
        }
)"_json;

json create_interface_config(const std::string& interface_name, const json& interface_macs_config)
{
  auto interface_config = json{};
  interface_config["name"] = interface_name;
  interface_config["MACs"] = std::vector<json>{interface_macs_config};
  return interface_config;
}

std::string create_config(const std::vector<json>& interfaces_config)
{
  auto config = json{};
  config["schema"] = SCHEMA;
  config["xnetInterfaces"] = interfaces_config;

  return config.dump();
}

std::string create_simple_config(const std::string& interface_name)
{
  return create_config({create_interface_config(interface_name, SIMPLE_INTERFACE_CONFIG)});
}

class NiXnetSocketDriverApiTests : public ::testing::Test {
 protected:
  NiXnetSocketDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnetSocket::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetSocketDriverApiTests() {}

  void SetUp() override
  {
    const auto discovered_devices = EnumerateDevices();

    for (const auto& required_name : required_interfaces()) {
      auto found = std::find_if(
          discovered_devices.cbegin(),
          discovered_devices.cend(),
          [&required_name](const nidevice_grpc::DeviceProperties& properties) {
            return properties.name() == required_name;
          });

      if (found == discovered_devices.cend()) {
        GTEST_SKIP() << "Interface not found: " << required_name;
      }
    }
  }

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NiXnetSocket::Stub>& stub()
  {
    return stub_;
  }

  virtual std::vector<std::string> required_interfaces() const = 0;

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiXnetSocket::Stub> stub_;
};

class NiXnetSocketLoopbackTests : public NiXnetSocketDriverApiTests {
  virtual std::vector<std::string> required_interfaces() const override
  {
    return {"ENET1,ENET2,ENET3,ENET4"};
  }
};

class NiXnetSocketNoHardwareTests : public NiXnetSocketDriverApiTests {
  virtual std::vector<std::string> required_interfaces() const override
  {
    return {};
  }
};

#define EXPECT_SUCCESS(response)               \
  if (1) {                                     \
    EXPECT_EQ(0, (response).status());         \
    EXPECT_EQ("", (response).error_message()); \
  }

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

SocketResponse
socket(client::StubPtr& stub, const nidevice_grpc::Session& stack)
{
  return client::socket(stub, stack, 2 /* nxAF_INET */, 1 /* STREAM */, 6 /* TCP */);
}

SocketResponse socket(client::StubPtr& stub)
{
  return socket(stub, nidevice_grpc::Session{});
}

TEST_F(NiXnetSocketNoHardwareTests, InitWithInvalidIpStack_Close_ReturnsAndSetsExpectedErrors)
{
  auto socket_response = socket(stub());

  auto close_response = client::close(stub(), socket_response.socket());

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_EQ(INVALID_IP_STACK_ERROR, socket_response.error_num());
  EXPECT_EQ(INVALID_IP_STACK_MESSAGE, socket_response.error_message());
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, close_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, close_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, close_response.error_message());
}

TEST_F(NiXnetSocketNoHardwareTests, InitWithInvalidIpStack_Bind_ReturnsAndSetsExpectedErrors)
{
  auto sock_addr = SockAddr{};
  sock_addr.mutable_ipv4()->set_addr(0x7F000001);
  sock_addr.mutable_ipv4()->set_port(31764);
  auto socket_response = socket(stub());
  auto bind_response = client::bind(stub(), socket_response.socket(), sock_addr);

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, bind_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, bind_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, bind_response.error_message());
}

TEST_F(NiXnetSocketNoHardwareTests, SocketAndEmptySet_IsSet_ReturnsFalse)
{
  auto socket_response = socket(stub());
  auto is_set_response = client::is_set(stub(), socket_response.socket(), {});

  EXPECT_SUCCESS(is_set_response);
  EXPECT_EQ(NXSOCKET_FALSE, is_set_response.is_set());
}

TEST_F(NiXnetSocketNoHardwareTests, SocketAndSetContainingSocket_IsSet_ReturnsTrue)
{
  auto socket_response = socket(stub());
  auto is_set_response = client::is_set(stub(), socket_response.socket(), {socket_response.socket()});

  EXPECT_SUCCESS(is_set_response);
  EXPECT_EQ(NXSOCKET_TRUE, is_set_response.is_set());
}

TEST_F(NiXnetSocketNoHardwareTests, InvalidSocket_Select_ReturnsAndSetsExpectedErrors)
{
  auto socket_response = socket(stub());
  auto duration = pb::Duration{};
  duration.set_seconds(1);
  duration.set_nanos(500000);
  auto select_response = client::select(stub(), {socket_response.socket()}, {socket_response.socket()}, {}, duration);

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, select_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, select_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, select_response.error_message());
}

TEST_F(NiXnetSocketNoHardwareTests, InvalidEmptyConfigJson_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  constexpr auto TEST_CONFIG = "{}";
  constexpr auto JSON_OBJECT_MISSING_VALUE = -13017;
  const auto stack_response = client::ip_stack_create(stub(), "", "{}");

  EXPECT_XNET_ERROR(JSON_OBJECT_MISSING_VALUE, stack_response);
}

TEST_F(NiXnetSocketNoHardwareTests, ValidConfigJsonForMissingDevice_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  const auto TEST_CONFIG = create_simple_config("ENET6");
  constexpr auto INVALID_INTERFACE_NAME = -1074384758;
  const auto stack_response = client::ip_stack_create(stub(), "", TEST_CONFIG);

  EXPECT_XNET_ERROR(INVALID_INTERFACE_NAME, stack_response);
}

TEST_F(NiXnetSocketLoopbackTests, IpStackCreate_CreateSocketWithIpStack_Succeeds)
{
  const auto stack_response = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));

  const auto socket_response = socket(stub(), stack_response.stack_ref());

  EXPECT_SUCCESS(stack_response);
  EXPECT_SUCCESS(socket_response);
}

TEST_F(NiXnetSocketLoopbackTests, IpStackCreateAndClear_CreateSocketWithIpStack_Fails)
{
  const auto create_stack_response = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));
  const auto clear_stack_response = client::ip_stack_clear(stub(), create_stack_response.stack_ref());

  const auto socket_response = socket(stub(), create_stack_response.stack_ref());

  EXPECT_SUCCESS(create_stack_response);
  EXPECT_SUCCESS(clear_stack_response);
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
}

TEST_F(NiXnetSocketLoopbackTests, StackInfo)
{
  const auto create_stack_response = client::ip_stack_create(
      stub(),
      "",
      create_config(
          {create_interface_config("ENET1", MULTI_ADDRESS_INTERFACE_CONFIG)}));
  const auto wait_response = client::ip_stack_wait_for_interface(stub(), create_stack_response.stack_ref(), "", 5000);
  const auto stack_info_response = client::ip_stack_get_info(stub(), create_stack_response.stack_ref());

  EXPECT_SUCCESS(create_stack_response);
  EXPECT_SUCCESS(stack_info_response);
  EXPECT_SUCCESS(wait_response);
  EXPECT_EQ(1, stack_info_response.virtual_interfaces_size());
  const auto virtual_interface = stack_info_response.virtual_interfaces()[0];
  EXPECT_EQ("ENET1", virtual_interface.xnet_interface_name());
  EXPECT_EQ("00:80:2f:30:f4:58", virtual_interface.mac_address());
  EXPECT_EQ(1500, virtual_interface.mac_mtu());
  EXPECT_EQ(1, virtual_interface.if_index());
  EXPECT_EQ(4, virtual_interface.ip_addresses_size());
  const auto ipv4_address = virtual_interface.ip_addresses()[0];
  EXPECT_EQ(2 /* nxAF_INET */, ipv4_address.family());
  EXPECT_EQ("192.22.11.22", ipv4_address.address());
  EXPECT_EQ("255.0.0.0", ipv4_address.net_mask());
  EXPECT_EQ(8, ipv4_address.prefix_length());
  const auto ipv6_address = virtual_interface.ip_addresses()[2];
  EXPECT_EQ(10 /* nxAF_INET6 */, ipv6_address.family());
  EXPECT_EQ("2001:db8::8:800:200c:417a", ipv6_address.address());
  EXPECT_EQ("ffff:ffff::", ipv6_address.net_mask());
  EXPECT_EQ(32, ipv6_address.prefix_length());
  EXPECT_EQ(2, virtual_interface.gateway_addresses_size());
  const auto ipv4_gateway_address = virtual_interface.gateway_addresses()[0];
  EXPECT_EQ(2 /* nxAF_INET */, ipv4_gateway_address.family());
  EXPECT_EQ("10.2.129.1", ipv4_gateway_address.address());
  const auto ipv6_gateway_address = virtual_interface.gateway_addresses()[1];
  EXPECT_EQ(10 /* nxAF_INET6 */, ipv6_gateway_address.family());
  EXPECT_EQ("ff01::1", ipv6_gateway_address.address());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
