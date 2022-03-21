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
using namespace std::string_literals;  // for trailing ""s string literal syntax;

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
constexpr auto INVALID_ARGUMENT_ERROR = 13822;
constexpr auto INVALID_ARGUMENT_MESSAGE = "Invalid argument";
constexpr auto NXSOCKET_FALSE = 0;
constexpr auto NXSOCKET_TRUE = 1;
constexpr auto IPV4_LOCALHOST_ADDR = 0x0100007FU;
constexpr auto IPV4_LOCALHOST_ADDRESS_STR = "127.0.0.1";
constexpr auto IPV6_LOCALHOST_ADDRESS_STR = "::1";
const auto IPV6_LOCALHOST_ADDR = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1"s;
const auto IPV6_ZERO_ADDR = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"s;

constexpr auto SCHEMA = "file:///NIXNET_Documentation/xnetIpStackSchema-03.json";
const auto SIMPLE_INTERFACE_CONFIG = R"(      
        {
          "address": "generated",
          "name": "",
          "VLANs": [
            {
              "IPv4": {
                "DAD": false,
                "mode": "static",
                "staticAddresses": [
                  {
                    "address": "192.22.33.44",
                    "subnetMask": "255.0.0.0"
                  }
                ]
              },
              "IPv6": {
                  "mode": "enabled"
              },
              "isTagged": false,
              "name": ""
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
                    "address": "10.23.45.67",
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

std::string unique_static_ipv4_address()
{
  static std::atomic<uint32_t> instance_id_counter;
  const auto instance_id = instance_id_counter++;
  ASSERT_EQ(0, instance_id & 0xFF000000), "instance-id must fit in 24 bits.";
  auto ipv4_addr = std::stringstream{};
  ipv4_addr << std::dec << "10." << ((instance_id >> 16) & 0xFF) << "." << ((instance_id >> 8) & 0xFF) << "." << (instance_id & 0xFF);
  return ipv4_addr.str();
}

json create_interface_config(const std::string& interface_name, const json& interface_macs_config, const std::string& static_ip_address = {})
{
  auto interface_config = json{};
  interface_config["name"] = interface_name;
  interface_config["MACs"] = std::vector<json>{interface_macs_config};
  if (!static_ip_address.empty()) {
    interface_config["MACs"][0]["VLANs"][0]["IPv4"]["staticAddresses"][0]["address"] = static_ip_address;
  }
  return interface_config;
}

std::string create_config(const std::vector<json>& interfaces_config)
{
  auto config = json{};
  config["schema"] = SCHEMA;
  config["xnetInterfaces"] = interfaces_config;

  return config.dump();
}

std::string create_simple_config(const std::string& interface_name, const std::string& static_ip_address = unique_static_ipv4_address())
{
  return create_config({create_interface_config(interface_name, SIMPLE_INTERFACE_CONFIG, static_ip_address)});
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
    EXPECT_LE(0, (response).status());         \
    EXPECT_EQ("", (response).error_message()); \
    EXPECT_EQ(0, (response).error_num());      \
  }

#define EXPECT_XNET_STATUS(error, response) \
  if (1) {                                  \
    EXPECT_EQ(error, (response).status());  \
  }

#define EXPECT_XNET_ERROR(expected_status, error, message, response) \
  if (1) {                                                           \
    EXPECT_EQ(expected_status, (response).status());                 \
    EXPECT_EQ(error, (response).error_num());                        \
    EXPECT_EQ(message, (response).error_message());                  \
  }

#define EXPECT_INVALID_ARGUMENT_ERROR(response)                                                              \
  if (1) {                                                                                                   \
    EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, INVALID_ARGUMENT_ERROR, INVALID_ARGUMENT_MESSAGE, (response)); \
  }

SocketResponse
socket(client::StubPtr& stub, const nidevice_grpc::Session& stack)
{
  return client::socket(stub, stack, ADDRESS_FAMILY_INET, SOCKET_PROTOCOL_TYPE_STREAM, IP_PROTOCOL_TCP);
}

SocketResponse socket(client::StubPtr& stub)
{
  return socket(stub, nidevice_grpc::Session{});
}

TEST_F(NiXnetSocketNoHardwareTests, InitWithInvalidIpStack_Close_ReturnsAndSetsExpectedErrors)
{
  auto socket_response = socket(stub());

  auto close_response = client::close(stub(), socket_response.socket());

  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_EQ(INVALID_IP_STACK_ERROR, socket_response.error_num());
  EXPECT_EQ(INVALID_IP_STACK_MESSAGE, socket_response.error_message());
  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, close_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, close_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, close_response.error_message());
}

TEST_F(NiXnetSocketNoHardwareTests, InitWithInvalidIpStack_Bind_ReturnsAndSetsExpectedErrors)
{
  auto sock_addr = SockAddr{};
  sock_addr.mutable_ipv4()->mutable_addr()->set_addr(0x7F000001);
  sock_addr.mutable_ipv4()->set_port(31764);
  auto socket_response = socket(stub());
  auto bind_response = client::bind(stub(), socket_response.socket(), sock_addr);

  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, bind_response);
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

  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, select_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, select_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, select_response.error_message());
}

TEST_F(NiXnetSocketNoHardwareTests, InvalidEmptyConfigJson_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  constexpr auto TEST_CONFIG = "{}";
  constexpr auto JSON_OBJECT_MISSING_VALUE = -13017;
  const auto stack_response = client::ip_stack_create(stub(), "", "{}");

  EXPECT_XNET_STATUS(JSON_OBJECT_MISSING_VALUE, stack_response);
}

TEST_F(NiXnetSocketNoHardwareTests, ValidConfigJsonForMissingDevice_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  const auto TEST_CONFIG = create_simple_config("ENET6");
  constexpr auto INVALID_INTERFACE_NAME = -1074384758;
  const auto stack_response = client::ip_stack_create(stub(), "", TEST_CONFIG);

  EXPECT_XNET_STATUS(INVALID_INTERFACE_NAME, stack_response);
}

TEST_F(NiXnetSocketLoopbackTests, IPv4LocalhostAddress_AToNAndPToN_ReturnsCorrectAddr)
{
  const auto stack = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));
  const auto a_to_n = client::inet_a_to_n(stub(), stack.stack_ref(), IPV4_LOCALHOST_ADDRESS_STR);
  const auto p_to_n = client::inet_p_to_n(stub(), stack.stack_ref(), 2 /* nxAF_INET */, IPV4_LOCALHOST_ADDRESS_STR);

  EXPECT_SUCCESS(a_to_n);
  EXPECT_SUCCESS(p_to_n);
  EXPECT_EQ(IPV4_LOCALHOST_ADDR, a_to_n.name().addr());
  EXPECT_EQ(IPV4_LOCALHOST_ADDR, p_to_n.dst().ipv4().addr());
}

TEST_F(NiXnetSocketLoopbackTests, IPv6LocalhostAddress_PToN_ReturnsCorrectAddr)
{
  const auto stack = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));
  const auto p_to_n = client::inet_p_to_n(stub(), stack.stack_ref(), 10 /* nxAF_INET6 */, IPV6_LOCALHOST_ADDRESS_STR);

  EXPECT_SUCCESS(p_to_n);
  EXPECT_EQ(IPV6_LOCALHOST_ADDR, p_to_n.dst().ipv6().addr());
}

TEST_F(NiXnetSocketLoopbackTests, PToNWithInvalidFamily_ReturnsError)
{
  const auto stack = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));
  const auto p_to_n_in6_with_in_addr = client::inet_p_to_n(stub(), stack.stack_ref(), 10 /* nxAF_INET6 */, "127.0.0.`");
  const auto p_to_n_UNSPEC = client::inet_p_to_n(stub(), stack.stack_ref(), 0 /* nxAF_UNSPEC */, IPV4_LOCALHOST_ADDRESS_STR);
  const auto p_to_n_42 = client::inet_p_to_n(stub(), stack.stack_ref(), 42 /* bogus */, "10.0.0.1");

  // Invalid address is a zero status (1 is success; -1 is invalid family)
  // https://man7.org/linux/man-pages/man3/inet_pton.3.html
  EXPECT_XNET_STATUS(0, p_to_n_in6_with_in_addr);
  EXPECT_EQ(IPV6_ZERO_ADDR, p_to_n_in6_with_in_addr.dst().ipv6().addr());
  EXPECT_INVALID_ARGUMENT_ERROR(p_to_n_UNSPEC);
  EXPECT_INVALID_ARGUMENT_ERROR(p_to_n_42);
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
  EXPECT_XNET_STATUS(GENERIC_NXSOCKET_ERROR, socket_response);
}

TEST_F(NiXnetSocketLoopbackTests, MultiAddressIpStack_GetInfo_ReturnsExpectedInfo)
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
  const auto second_ipv4_address = virtual_interface.ip_addresses()[1];
  EXPECT_EQ(2 /* nxAF_INET */, second_ipv4_address.family());
  EXPECT_EQ("10.23.45.67", second_ipv4_address.address());
  EXPECT_EQ("255.0.0.0", second_ipv4_address.net_mask());
  EXPECT_EQ(8, second_ipv4_address.prefix_length());
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

TEST_F(NiXnetSocketLoopbackTests, RecvAndTransmitSocketsOnLoopbackAddress_SendAndReceiveData_ReceivesExpectedData)
{
  const auto rx_stack = client::ip_stack_create(stub(), "", create_simple_config("ENET1"));
  const auto wait = client::ip_stack_wait_for_interface(stub(), rx_stack.stack_ref(), "", 5000);
  const auto rx_socket = socket(stub(), rx_stack.stack_ref());
  const auto rx_p_to_n = client::inet_p_to_n(stub(), rx_stack.stack_ref(), 2 /* AF INET*/, "127.0.0.1");
  auto sock_addr = SockAddr{};
  sock_addr.mutable_ipv4()->mutable_addr()->CopyFrom(rx_p_to_n.dst().ipv4());
  const auto bind = client::bind(stub(), rx_socket.socket(), sock_addr);
  const auto get_name = client::get_sock_name(stub(), rx_socket.socket());
  const auto listen = client::listen(stub(), rx_socket.socket(), 10);
  const auto tx_socket = socket(stub(), rx_stack.stack_ref());
  EXPECT_SUCCESS(rx_stack);
  EXPECT_SUCCESS(wait);
  EXPECT_SUCCESS(rx_p_to_n);
  EXPECT_SUCCESS(rx_socket);
  EXPECT_SUCCESS(bind);
  EXPECT_SUCCESS(get_name);
  EXPECT_SUCCESS(listen);
  EXPECT_SUCCESS(tx_socket);

  const auto connect = client::connect(stub(), tx_socket.socket(), get_name.addr());
  const auto accept = client::accept(stub(), rx_socket.socket());
  const auto send = client::send(stub(), tx_socket.socket(), "HelloWorld", 0);
  const auto recv = client::recv(stub(), accept.socket(), 10, 0);

  EXPECT_SUCCESS(connect);
  EXPECT_SUCCESS(send);
  EXPECT_SUCCESS(recv);
  EXPECT_EQ("HelloWorld", recv.mem());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
