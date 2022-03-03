#define NOMINMAX

#include <custom/xnetsocket_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace nixnetsocket_grpc;
using namespace ::testing;
namespace pb = ::google::protobuf;

namespace ni {
namespace tests {
namespace unit {
namespace {
TEST(XnetConvertersTests, IPv4GrpcSockAddr_ConvertFromGrpc_CreatesIPv4NXSockAddr)
{
  constexpr auto PORT = 1234;
  constexpr auto ADDRESS = 0xAABBCCDD;
  auto grpc_sock_addr = SockAddr{};
  grpc_sock_addr.mutable_ipv4()->set_port(PORT);
  grpc_sock_addr.mutable_ipv4()->set_addr(ADDRESS);

  auto converted_addr = convert_from_grpc<nxsockaddr>(grpc_sock_addr);
  auto addr_ptr = static_cast<nxsockaddr*>(converted_addr);
  auto reinterpreted_ipv4_addr = reinterpret_cast<nxsockaddr_in*>(addr_ptr);

  EXPECT_EQ(sizeof(nxsockaddr_in), converted_addr.size());
  EXPECT_EQ(nxAF_INET, addr_ptr->sa_family);
  EXPECT_EQ(PORT, reinterpreted_ipv4_addr->sin_port);
  EXPECT_EQ(ADDRESS, reinterpreted_ipv4_addr->sin_addr.addr);
}

SockAddr create_addr_ipv6(pb::uint32 port, pb::uint32 flow_info, const std::vector<char>& address, pb::uint32 scope_id)
{
  auto grpc_sock_addr = SockAddr{};
  auto ipv6_addr = SockAddrIPv6{};
  ipv6_addr.set_port(port);
  ipv6_addr.set_flow_info(flow_info);
  ipv6_addr.set_addr({address.cbegin(), address.cend()});
  ipv6_addr.set_scope_id(scope_id);
  grpc_sock_addr.mutable_ipv6()->CopyFrom(ipv6_addr);
  return grpc_sock_addr;
}

void EXPECT_IPV6_ADDR(
    const SockAddrHolder& converted_addr,
    pb::uint32 port,
    pb::uint32 flow_info,
    const std::vector<char>& address,
    pb::uint32 scope_id)
{
  auto addr_ptr = static_cast<const nxsockaddr*>(converted_addr);
  auto reinterpreted_ipv6_addr = reinterpret_cast<const nxsockaddr_in6*>(addr_ptr);

  EXPECT_EQ(sizeof(nxsockaddr_in6), converted_addr.size());
  EXPECT_EQ(nxAF_INET6, addr_ptr->sa_family);
  EXPECT_EQ(port, reinterpreted_ipv6_addr->sin6_port);
  EXPECT_EQ(flow_info, reinterpreted_ipv6_addr->sin6_flowinfo);
  EXPECT_THAT(reinterpreted_ipv6_addr->sin6_addr.addr, ElementsAreArray(address.data(), address.size()));
  EXPECT_EQ(scope_id, reinterpreted_ipv6_addr->sin6_scope_id);
}

TEST(XnetConvertersTests, IPv6GrpcSockAddr_ConvertFromGrpc_CreatesIPv6NXSockAddr)
{
  constexpr auto PORT = 1234;
  constexpr auto FLOW_INFO = 9999;
  const auto ADDRESS = std::vector<char>{0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
  constexpr auto SCOPE_ID = 8888;
  auto grpc_sock_addr = create_addr_ipv6(PORT, FLOW_INFO, ADDRESS, SCOPE_ID);

  auto converted_addr = convert_from_grpc<nxsockaddr>(grpc_sock_addr);

  EXPECT_IPV6_ADDR(converted_addr, PORT, FLOW_INFO, ADDRESS, SCOPE_ID);
}

TEST(XnetConvertersTests, IPv6GrpcSockAddrWithTooShortAddress_ConvertFromGrpc_CreatesAddrWithZeroesInMissingBytes)
{
  constexpr auto PORT = 1234;
  constexpr auto FLOW_INFO = 9999;
  const auto ADDRESS = std::vector<char>{0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9};
  const auto ADDRESS_WITH_ZEROES = std::vector<char>{0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
  constexpr auto SCOPE_ID = 8888;
  auto grpc_sock_addr = create_addr_ipv6(PORT, FLOW_INFO, ADDRESS, SCOPE_ID);

  auto converted_addr = convert_from_grpc<nxsockaddr>(grpc_sock_addr);

  EXPECT_IPV6_ADDR(converted_addr, PORT, FLOW_INFO, ADDRESS_WITH_ZEROES, SCOPE_ID);
}

TEST(XnetConvertersTests, IPv6GrpcSockAddrTooLongAddress_ConvertFromGrpc_CreatesIPv6NXSockAddrWithExtraBytesTruncated)
{
  constexpr auto PORT = 1234;
  constexpr auto FLOW_INFO = 9999;
  const auto ADDRESS = std::vector<char>{0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11};
  const auto TRUNCATED_ADDRESS = std::vector<char>{0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF};
  constexpr auto SCOPE_ID = 8888;
  auto grpc_sock_addr = create_addr_ipv6(PORT, FLOW_INFO, ADDRESS, SCOPE_ID);

  auto converted_addr = convert_from_grpc<nxsockaddr>(grpc_sock_addr);

  EXPECT_IPV6_ADDR(converted_addr, PORT, FLOW_INFO, TRUNCATED_ADDRESS, SCOPE_ID);
}

TEST(XnetConvertersTests, UnsetGrpcSockAddr_ConvertFromGrpc_CreatesEmptySockAddrWithUnspecifiedAddressFamily)
{
  auto grpc_sock_addr = SockAddr{};

  auto converted_addr = convert_from_grpc<nxsockaddr>(grpc_sock_addr);
  auto addr_ptr = static_cast<nxsockaddr*>(converted_addr);

  // Note: these are the values for a zeroed out nxsockaddr struct from our initial std::memset.
  EXPECT_EQ(0, converted_addr.size());
  EXPECT_EQ(nxAF_UNSPEC, addr_ptr->sa_family);
}

using ResourceRepositorySharedPtr = ResourceRepositorySharedPtr_;
struct ResourceRepositoryHolder {
  ResourceRepositoryHolder()
      : session_repository(std::make_unique<nidevice_grpc::SessionRepository>()),
        resource_repository(std::make_shared<nidevice_grpc::SessionResourceRepository<nxSOCKET>>(session_repository.get()))
  {
  }
  operator ResourceRepositorySharedPtr()
  {
    return resource_repository;
  }
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository;
  ResourceRepositorySharedPtr resource_repository;
};

ResourceRepositoryHolder create_resource_repository(std::unordered_map<std::string, nxSOCKET> socket_sessions)
{
  auto repository = ResourceRepositoryHolder{};
  for (const auto pair : socket_sessions) {
    uint32_t session_id;
    repository.resource_repository->add_session(
        pair.first, [pair]() { return std::tuple(0, pair.second); }, nullptr, session_id);
  }

  return repository;
}

nidevice_grpc::Session create_session(std::string name)
{
  auto session = nidevice_grpc::Session{};
  session.set_name(name);
  return session;
}

TEST(XnetConvertersTests, EmptyListOfSockets_ConvertFromGrpc_CreatesZeroedOutSocketSet)
{
  auto resource_repository = create_resource_repository({});
  auto grpc_socket_list = pb::RepeatedPtrField<nidevice_grpc::Session>{};

  auto converted_set = convert_from_grpc<nxfd_set>(grpc_socket_list, resource_repository);
  auto set_ptr = static_cast<nxfd_set*>(converted_set);

  EXPECT_EQ(0, set_ptr->fd_count);
}

TEST(XnetConvertersTests, ListOfTwoSockets_ConvertFromGrpc_CreateSocketSetWithBothSockets)
{
  constexpr auto SESSION_NAME_1 = "one";
  constexpr auto SESSION_NAME_2 = "two";
  constexpr auto SOCKET_1 = 1001;
  constexpr auto SOCKET_2 = 2002;
  auto resource_repository = create_resource_repository({{SESSION_NAME_1, SOCKET_1}, {SESSION_NAME_2, SOCKET_2}});
  auto grpc_socket_list = pb::RepeatedPtrField<nidevice_grpc::Session>{};
  grpc_socket_list.Add(create_session(SESSION_NAME_1));
  grpc_socket_list.Add(create_session(SESSION_NAME_2));

  auto converted_set = convert_from_grpc<nxfd_set>(grpc_socket_list, resource_repository);
  auto set_ptr = static_cast<nxfd_set*>(converted_set);

  EXPECT_EQ(2, set_ptr->fd_count);
  EXPECT_EQ(SOCKET_1, set_ptr->fd_array[0]);
  EXPECT_EQ(SOCKET_2, set_ptr->fd_array[1]);
}

TEST(XnetConvertersTests, ListWithSocketNotInRepository_ConvertFromGrpc_CreatesListWithOneZeroValuedSocket)
{
  constexpr auto SESSION_NAME = "test";
  auto resource_repository = create_resource_repository({});
  auto grpc_socket_list = pb::RepeatedPtrField<nidevice_grpc::Session>{};
  grpc_socket_list.Add(create_session(SESSION_NAME));

  auto converted_set = convert_from_grpc<nxfd_set>(grpc_socket_list, resource_repository);
  auto set_ptr = static_cast<nxfd_set*>(converted_set);

  EXPECT_EQ(1, set_ptr->fd_count);
  EXPECT_EQ(0, set_ptr->fd_array[0]);
}

TEST(XnetConvertersTests, EmptyDuration_ConvertFromGrpc_CreatesEmptyTimeVal)
{
  const auto duration = pb::Duration{};

  auto converted_timeval = convert_from_grpc<nxtimeval>(duration);
  auto timeval_ptr = static_cast<nxtimeval*>(converted_timeval);

  EXPECT_EQ(0, timeval_ptr->tv_sec);
  EXPECT_EQ(0, timeval_ptr->tv_usec);
}

TEST(XnetConvertersTests, Duration_ConvertFromGrpc_CreatesCorrespondingTimeVal)
{
  constexpr auto SECONDS = 100;
  constexpr auto MICROS = 500;
  auto duration = pb::Duration{};
  duration.set_seconds(SECONDS);
  duration.set_nanos(MICROS * 1000);

  auto converted_timeval = convert_from_grpc<nxtimeval>(duration);
  auto timeval_ptr = static_cast<nxtimeval*>(converted_timeval);

  EXPECT_EQ(SECONDS, timeval_ptr->tv_sec);
  EXPECT_EQ(MICROS, timeval_ptr->tv_usec);
}

TEST(XnetConvertersTests, DurationWithSubMicroSecondResolution_ConvertFromGrpc_CreatesCorrespondingTimeValWithFlooredValue)
{
  constexpr auto SECONDS = 100;
  constexpr auto NANOS = 5555;
  constexpr auto MICROS = 5;
  auto duration = pb::Duration{};
  duration.set_seconds(SECONDS);
  duration.set_nanos(NANOS);

  auto converted_timeval = convert_from_grpc<nxtimeval>(duration);
  auto timeval_ptr = static_cast<nxtimeval*>(converted_timeval);

  EXPECT_EQ(SECONDS, timeval_ptr->tv_sec);
  EXPECT_EQ(MICROS, timeval_ptr->tv_usec);
}
}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni
