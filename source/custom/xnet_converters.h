#ifndef NIDEVICE_GRPC_DEVICE_XNET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_XNET_CONVERTERS_H

#include <nixnet.pb.h>
#include <nixnet.h>
#include <server/converters.h>

#include <algorithm>
#include <cstring>

namespace nixnet_grpc {

// This class allows us to have something allocated on the stack that can be used as an
// void* and initialized from a grpc StateValue using standard codegen and copy convert routines.
struct StateValueHolder {
  StateValueHolder(const StateValue& input)
  {
    switch (input.state_value_case()) {
      case StateValue::ValueCase::kIpv4:
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

template <typename TSockAddr>
inline StateValueHolder convert_from_grpc(const StateValue& input)
{
  return StateValueHolder(input);
}
}  // namespace nixnet_grpc
#endif /* NIDEVICE_GRPC_DEVICE_XNET_CONVERTERS_H */