#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/util/time_util.h>
#include <nixnetsocket.pb.h>
#include <nxsocket.h>
#include <server/converters.h>
#include <server/session_resource_repository.h>

#include <algorithm>
#include <cstring>
#include <memory>

namespace nixnetsocket_grpc {

namespace pb = ::google::protobuf;
using ResourceRepositorySharedPtr_ = std::shared_ptr<nidevice_grpc::SessionResourceRepository<nxSOCKET>>;

// This class allows us to have something allocated on the stack that can be used as an
// nxsockaddr* and initialized from a grpc SockAddr using standard codegen and copy convert routines.
struct SockAddrHolder {
  SockAddrHolder(const SockAddr& input)
  {
    // memset zero ensures:
    // (a) any unset bytes in the ipv6 addr are zero.
    // (b) If neither oneof case is selected, sa_familly will be nxAF_UNSPEC.
    std::memset(&addr, 0, sizeof(addr));

    switch (input.addr_case()) {
      case SockAddr::AddrCase::kIpv4:
        addr.ipv4.sin_family = nxAF_INET;
        addr.ipv4.sin_port = input.ipv4().port();
        addr.ipv4.sin_addr.addr = input.ipv4().addr();
        break;
      case SockAddr::AddrCase::kIpv6:
        addr.ipv6.sin6_family = nxAF_INET6;
        addr.ipv6.sin6_port = input.ipv6().port();
        addr.ipv6.sin6_flowinfo = input.ipv6().flow_info();
        std::memcpy(
            addr.ipv6.sin6_addr.addr,
            input.ipv6().addr().data(),
            std::min(
                sizeof(addr.ipv6.sin6_addr.addr),
                static_cast<size_t>(input.ipv6().addr().size())));
        addr.ipv6.sin6_scope_id = input.ipv6().scope_id();
        break;
      default:
        // pass. Use zero'd out SockAddrHolder.
        break;
    }
  }

  // Implicit conversion to nxsockaddr* simplifies codegen because these are passed by pointer to
  // the driver.
  operator nxsockaddr*()
  {
    return &(addr.ip_unknown);
  }

  operator const nxsockaddr*() const
  {
    return &(addr.ip_unknown);
  }

  // size() method is used to simplify codegen calculating the size of the
  // selected addr.
  nxsocklen_t size() const
  {
    switch (addr.ip_unknown.sa_family) {
      case nxAF_INET:
        return sizeof(nxsockaddr_in);
      case nxAF_INET6:
        return sizeof(nxsockaddr_in6);
      default:
        return 0;
    }
  }

  // Represent as a union: can be ipv4 or ipv6.
  union {
    nxsockaddr ip_unknown;
    nxsockaddr_in ipv4;
    nxsockaddr_in6 ipv6;
  } addr;
};

struct SetHolder {
  SetHolder(
      const pb::RepeatedPtrField<nidevice_grpc::Session>& input,
      const ResourceRepositorySharedPtr_& resource_repository)
  {
    nxFD_ZERO(&set);
    for (const auto& session : input) {
      const auto socket = resource_repository->access_session(session.id(), session.name());
      nxFD_SET(socket, &set);
    }
  }

  operator nxfd_set*()
  {
    return &set;
  }

  operator const nxfd_set*() const
  {
    return &set;
  }

  nxfd_set set;
};

struct TimeValHolder {
  TimeValHolder(const pb::Duration& input)
  {
    time_val.tv_sec = input.seconds();
    time_val.tv_usec = input.nanos() / 1000;
  }

  operator nxtimeval*()
  {
    return &time_val;
  }

  operator const nxtimeval*() const
  {
    return &time_val;
  }

  nxtimeval time_val;
};

template <typename TSockAddr>
inline SockAddrHolder convert_from_grpc(const SockAddr& input)
{
  return SockAddrHolder(input);
}

template <typename TSet>
inline SetHolder convert_from_grpc(
    const pb::RepeatedPtrField<nidevice_grpc::Session>& input,
    const ResourceRepositorySharedPtr_& resource_repository)
{
  return SetHolder(input, resource_repository);
}

template <typename TSet>
inline TimeValHolder convert_from_grpc(const pb::Duration& input)
{
  return TimeValHolder(input);
}
}  // namespace nixnetsocket_grpc
#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H */
