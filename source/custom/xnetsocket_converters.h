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

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;
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
      const pb_::RepeatedPtrField<nidevice_grpc::Session>& input,
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
  TimeValHolder(const pb_::Duration& input)
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
    const pb_::RepeatedPtrField<nidevice_grpc::Session>& input,
    const ResourceRepositorySharedPtr_& resource_repository)
{
  return SetHolder(input, resource_repository);
}

template <typename TSet>
inline TimeValHolder convert_from_grpc(const pb_::Duration& input)
{
  return TimeValHolder(input);
}

// This class allows us to have something allocated on the stack that can be used as an
// nxsockaddr* and initialized from a grpc SockAddr using standard codegen and copy convert routines.
struct SockOptDataHolder {
  SockOptData opt_data;
  int32_t data_int;
  bool data_bool;
  std::string data_string;

  SockOptDataHolder(const SockOptData& input) : opt_data(input)
  {
    data_int = opt_data.data_int32();
    data_bool = opt_data.data_bool();
    data_string = std::string(opt_data.data_string());
  }

  int32_t name() const
  {
    return opt_data.opt();
  }

  void* data()
  {
    void* dummy_pointer;
    switch (opt_data.data_case()) {
      case SockOptData::DataCase::kDataInt32:
        dummy_pointer = &data_int;
        break;
      case SockOptData::DataCase::kDataString:
        dummy_pointer = &data_string;
        break;
      case SockOptData::DataCase::kDataBool:
        dummy_pointer = &data_bool;
        break;
      default:
        // pass dummy_pointer
        break;
    }
    return dummy_pointer;
  }

  // size() method is used to simplify codegen calculating the size of the
  // selected data.
  nxsocklen_t size() const
  {
    switch (opt_data.data_case()) {
      case SockOptData::DataCase::kDataInt32:
        return sizeof(int32_t);
        break;
      case SockOptData::DataCase::kDataString:
        return opt_data.data_string().size();
        break;
      case SockOptData::DataCase::kDataBool:
        return sizeof(bool);
      default:
        return 0;
        break;
    }
  }
};

template <typename TSockOptData>
inline SockOptDataHolder convert_from_grpc(const SockOptData& input)
{
  return SockOptDataHolder(input);
}

}  // namespace nixnetsocket_grpc
#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H */
