#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#include <nixnetsocket/nixnetsocket_client.h>

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
constexpr auto SOCKET_COULD_NOT_BE_FOUND_ERROR = -13009;
constexpr auto SOCKET_COULD_NOT_BE_FOUND_MESSAGE = "The specified socket could not be found.";
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
                ]
              }
            }
          ]
        }
)"_json;

std::string create_simple_config(const std::string& interface_name)
{
  auto interface_config = json{};
  interface_config["name"] = interface_name;
  interface_config["MACs"] = std::vector<json>{SIMPLE_INTERFACE_CONFIG};

  auto config = json{};
  config["schema"] = SCHEMA;
  config["xnetInterfaces"] = std::vector<json>{interface_config};

  return config.dump();
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

#define EXPECT_SUCCESS(response)       \
  if (1) {                             \
    EXPECT_EQ(0, (response).status()); \
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
  auto socket_get_last_error = client::get_last_error_num(stub());
  auto socket_get_last_error_str = client::get_last_error_str(stub(), 512);

  auto close_response = client::close(stub(), socket_response.socket());
  auto close_get_last_error = client::get_last_error_num(stub());
  auto close_get_last_error_str = client::get_last_error_str(stub(), 512);

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_SUCCESS(socket_get_last_error);
  EXPECT_SUCCESS(socket_get_last_error_str);
  EXPECT_EQ("The specified IP Stack could not be found.", socket_get_last_error_str.error());
  EXPECT_XNET_ERROR(INVALID_XNET_SOCKET, close_response);
  EXPECT_XNET_ERROR(-13009, close_get_last_error);
  EXPECT_SUCCESS(close_get_last_error_str);
  EXPECT_THAT("The specified socket could not be found.", close_get_last_error_str.error());
}

TEST_F(NiXnetSocketNoHardwareTests, InitWithInvalidIpStack_Bind_ReturnsAndSetsExpectedErrors)
{
  auto sock_addr = SockAddr{};
  sock_addr.mutable_ipv4()->set_addr(0x7F000001);
  sock_addr.mutable_ipv4()->set_port(31764);
  auto socket_response = socket(stub());
  auto bind_response = client::bind(stub(), socket_response.socket(), sock_addr);
  auto bind_get_last_error = client::get_last_error_num(stub());
  auto bind_get_last_error_str = client::get_last_error_str(stub(), 512);

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, bind_response);
  EXPECT_XNET_ERROR(SOCKET_COULD_NOT_BE_FOUND_ERROR, bind_get_last_error);
  EXPECT_THAT(SOCKET_COULD_NOT_BE_FOUND_MESSAGE, bind_get_last_error_str.error());
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
  auto select_last_error = client::get_last_error_num(stub());
  auto select_last_error_str = client::get_last_error_str(stub(), 512);

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, select_response);
  EXPECT_XNET_ERROR(SOCKET_COULD_NOT_BE_FOUND_ERROR, select_last_error);
  EXPECT_THAT(SOCKET_COULD_NOT_BE_FOUND_MESSAGE, select_last_error_str.error());
}

TEST_F(NiXnetSocketNoHardwareTests, InvalidEmptyConfigJson_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  constexpr auto TEST_CONFIG = "{}";
  constexpr auto JSON_OBJECT_MISSING_VALUE = -13017;
  const auto stack_response = client::ip_stack_create(stub(), "test", "{}");

  EXPECT_XNET_ERROR(JSON_OBJECT_MISSING_VALUE, stack_response);
}

TEST_F(NiXnetSocketNoHardwareTests, ValidConfigJsonForMissingDevice_IpStackCreate_ReturnsInvalidInterfaceNameError)
{
  const auto TEST_CONFIG = create_simple_config("ENET6");
  constexpr auto INVALID_INTERFACE_NAME = -1074384758;
  const auto stack_response = client::ip_stack_create(stub(), "test", TEST_CONFIG);

  EXPECT_XNET_ERROR(INVALID_INTERFACE_NAME, stack_response);
}

TEST_F(NiXnetSocketLoopbackTests, IpStackCreate_CreateSocketWithIpStack_Succeeds)
{
  const auto stack_response = client::ip_stack_create(stub(), "test", create_simple_config("ENET1"));

  const auto socket_response = socket(stub(), stack_response.stack_ref());

  EXPECT_SUCCESS(stack_response);
  EXPECT_SUCCESS(socket_response);
}

TEST_F(NiXnetSocketLoopbackTests, IpStackCreateAndClear_CreateSocketWithIpStack_Fails)
{
  const auto create_stack_response = client::ip_stack_create(stub(), "test", create_simple_config("ENET1"));
  const auto clear_stack_response = client::ip_stack_clear(stub(), create_stack_response.stack_ref());

  const auto socket_response = socket(stub(), create_stack_response.stack_ref());

  EXPECT_SUCCESS(create_stack_response);
  EXPECT_SUCCESS(clear_stack_response);
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
