#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "device_server.h"
#include "nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_client.h"

using namespace ::testing;
using namespace nimxlcterminaladaptor_restricted_grpc;
namespace client = nimxlcterminaladaptor_restricted_grpc::experimental::client;
namespace pb = ::google::protobuf;

namespace ni {
namespace tests {
namespace system {
namespace {

constexpr auto DEFAULT_HOSTNAME = "localhost";

class NiMxLcTerminalAdaptorRestrictedDriverApiTests : public Test {
 protected:
  NiMxLcTerminalAdaptorRestrictedDriverApiTests()
      : device_server_(DeviceServerInterface::Singleton()),
        nimxlcterminaladaptor_stub_(NimxlcTerminalAdaptorRestricted::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiMxLcTerminalAdaptorRestrictedDriverApiTests() {}

  void TearDown() override
  {
    device_server_->ResetServer();
  }

  template <typename TService>
  std::unique_ptr<typename TService::Stub> create_stub()
  {
    return TService::NewStub(device_server_->InProcessChannel());
  }

  std::unique_ptr<NimxlcTerminalAdaptorRestricted::Stub>& stub()
  {
    return nimxlcterminaladaptor_stub_;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<NimxlcTerminalAdaptorRestricted::Stub> nimxlcterminaladaptor_stub_;
};

nidevice_grpc::Session init_session(const client::StubPtr& stub, const std::string& hostname)
{
  std::cout << "inside init_session" << std::endl;
  auto response = client::create_session(stub, hostname.c_str());
  std::cout << "after client::create_session call" << std::endl;
  EXPECT_EQ(0, response.status());
  EXPECT_EQ(0, response.c_status().code());
  auto session = response.handle();
  return session;
}

nidevice_grpc::Session init_session(const client::StubPtr& stub)
{
  return init_session(stub, DEFAULT_HOSTNAME);
}

TEST_F(NiMxLcTerminalAdaptorRestrictedDriverApiTests, RefreshTerminalCache)
{
  std::cout << "start test" << std::endl;
  const auto session = init_session(stub());
  std::cout << "init_session" << std::endl;
  auto refresh_terminal_cache_response = client::refresh_terminal_cache(stub(), session);
  std::cout << "refresh_terminal_cache" << std::endl;
  EXPECT_EQ(0, refresh_terminal_cache_response.status());
  EXPECT_EQ(0, refresh_terminal_cache_response.c_status().code());
}

}  // namespace
}  // namespace system
}  // namespace tests
}  // namespace ni
