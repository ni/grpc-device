#include <gmock/gmock.h>
#include <google/protobuf/util/time_util.h>
#include <gtest/gtest.h>
#include <nixnetsocket/nixnetsocket_client.h>

#include "device_server.h"

using namespace nixnetsocket_grpc;
namespace client = nixnetsocket_grpc::experimental::client;
namespace pb = google::protobuf;
using namespace ::testing;

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

class NiXnetDriverApiTests : public ::testing::Test {
 protected:
  NiXnetDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        stub_(NiXnetSocket::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }
  virtual ~NiXnetDriverApiTests() {}

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

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NiXnetSocket::Stub> stub_;
};

#define EXPECT_SUCCESS(response)       \
  if (1) {                             \
    EXPECT_EQ(0, (response).status()); \
  }

#define EXPECT_XNET_ERROR(error, response) \
  if (1) {                                 \
    EXPECT_EQ(error, (response).status()); \
  }

SocketResponse socket(client::StubPtr& stub)
{
  return client::socket(stub, 2 /* nxAF_INET */, 1 /* STREAM */, 6 /* TCP */);
}

TEST_F(NiXnetDriverApiTests, InitWithInvalidIpStack_Close_ReturnsAndSetsExpectedErrors)
{
  auto socket_response = client::socket(stub(), 2 /* nxAF_INET */, 1 /* STREAM */, 6 /* TCP */);

  auto close_response = client::close(stub(), socket_response.socket());

  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, socket_response);
  EXPECT_EQ(INVALID_IP_STACK_ERROR, socket_response.error_num());
  EXPECT_EQ(INVALID_IP_STACK_MESSAGE, socket_response.error_message());
  EXPECT_XNET_ERROR(GENERIC_NXSOCKET_ERROR, close_response);
  EXPECT_EQ(INVALID_SOCKET_ERROR, close_response.error_num());
  EXPECT_EQ(INVALID_SOCKET_MESSAGE, close_response.error_message());
}

TEST_F(NiXnetDriverApiTests, InitWithInvalidIpStack_Bind_ReturnsAndSetsExpectedErrors)
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

TEST_F(NiXnetDriverApiTests, SocketAndEmptySet_IsSet_ReturnsFalse)
{
  auto socket_response = socket(stub());
  auto is_set_response = client::is_set(stub(), socket_response.socket(), {});

  EXPECT_SUCCESS(is_set_response);
  EXPECT_EQ(NXSOCKET_FALSE, is_set_response.is_set());
}

TEST_F(NiXnetDriverApiTests, SocketAndSetContainingSocket_IsSet_ReturnsTrue)
{
  auto socket_response = socket(stub());
  auto is_set_response = client::is_set(stub(), socket_response.socket(), {socket_response.socket()});

  EXPECT_SUCCESS(is_set_response);
  EXPECT_EQ(NXSOCKET_TRUE, is_set_response.is_set());
}

TEST_F(NiXnetDriverApiTests, InvalidSocket_Select_ReturnsAndSetsExpectedErrors)
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
}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
