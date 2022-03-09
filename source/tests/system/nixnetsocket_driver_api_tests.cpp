#include <gmock/gmock.h>
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

constexpr auto INVALID_SOCKET = -1;
constexpr auto FAILED_INIT = -1;
constexpr auto SOCKET_COULD_NOT_BE_FOUND = -13009;

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

TEST_F(NiXnetDriverApiTests, InitWithInvalidIpStack_Close_ReturnsAndSetsExpectedErrors)
{
  auto socket_response = client::socket(stub(), 2 /* nxAF_INET */, 1 /* STREAM */, 6 /* TCP */);
  auto socket_get_last_error = client::get_last_error_num(stub());
  auto socket_get_last_error_str = client::get_last_error_str(stub(), 512);

  auto close_response = client::close(stub(), socket_response.socket());
  auto close_get_last_error = client::get_last_error_num(stub());
  auto close_get_last_error_str = client::get_last_error_str(stub(), 512);

  EXPECT_XNET_ERROR(FAILED_INIT, socket_response);
  EXPECT_SUCCESS(socket_get_last_error);
  EXPECT_SUCCESS(socket_get_last_error_str);
  EXPECT_EQ("The specified IP Stack could not be found.", socket_get_last_error_str.error());
  EXPECT_XNET_ERROR(INVALID_SOCKET, close_response);
  EXPECT_XNET_ERROR(-13009, close_get_last_error);
  EXPECT_SUCCESS(close_get_last_error_str);
  EXPECT_THAT("The specified socket could not be found.", close_get_last_error_str.error());
}

TEST_F(NiXnetDriverApiTests, InitWithInvalidIpStack_Bind_ReturnsAndSetsExpectedErrors)
{
  auto sock_addr = SockAddr{};
  sock_addr.mutable_ipv4()->set_addr(0x7F000001);
  sock_addr.mutable_ipv4()->set_port(31764);
  auto socket_response = client::socket(stub(), 2 /* nxAF_INET */, 1 /* STREAM */, 6 /* TCP */);
  auto bind_response = client::bind(stub(), socket_response.socket(), sock_addr);
  auto bind_get_last_error = client::get_last_error_num(stub());
  auto bind_get_last_error_str = client::get_last_error_str(stub(), 512);

  EXPECT_XNET_ERROR(FAILED_INIT, socket_response);
  EXPECT_XNET_ERROR(FAILED_INIT, bind_response);
  EXPECT_XNET_ERROR(-13009, bind_get_last_error);
  EXPECT_THAT("The specified socket could not be found.", bind_get_last_error_str.error());
}
}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
