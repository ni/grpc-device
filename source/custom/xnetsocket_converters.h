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

// Helper classes and overrides of standard conversion routines go in nixnetsocket_grpc.
namespace nixnetsocket_grpc {

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;
using ResourceRepositorySharedPtr_ = std::shared_ptr<nidevice_grpc::SessionResourceRepository<nxSOCKET>>;

// This class allows us to have something allocated on the stack that can be used as an
// nxsockaddr* and initialized from a grpc SockAddr using standard codegen and copy convert routines.
struct SockAddrInputConverter {
  SockAddrInputConverter(const SockAddr& input)
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
        // pass. Use zero'd out SockAddrInputConverter.
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

// This class allows us to have something allocated on the stack that provides backing
// storage for an nxsockaddr output param and converts it to the SockAddr grpc-type.
struct SockAddrOutputConverter {
  SockAddrOutputConverter()
  {
    std::memset(&storage, 0, sizeof(storage));
  }

  template <typename TAddr>
  const TAddr* storage_cast() const
  {
    return reinterpret_cast<const TAddr*>(&storage);
  }

  template <typename TAddr>
  TAddr* storage_cast()
  {
    return reinterpret_cast<TAddr*>(&storage);
  }

  // Overriding the address_of operator is like a implicit conversion for output
  // params. This works with our default output param passing codegen that passes
  // this as nxaccepr(sock, &addr, &addrlen);
  nxsockaddr* operator&()
  {
    return storage_cast<nxsockaddr>();
  }

  void to_grpc(SockAddr& output) const
  {
    switch (storage.ss_family) {
      case nxAF_INET: {
        auto ipv4_input = storage_cast<const nxsockaddr_in>();
        auto ipv4_output = output.mutable_ipv4();
        ipv4_output->set_port(ipv4_input->sin_port);
        ipv4_output->set_addr(ipv4_input->sin_addr.addr);
      } break;
      case nxAF_INET6: {
        const auto ipv6_input = storage_cast<const nxsockaddr_in6>();
        auto ipv6_output = output.mutable_ipv6();
        ipv6_output->set_port(ipv6_input->sin6_port);
        ipv6_output->set_flow_info(ipv6_input->sin6_flowinfo);
        // Reinterpret unsigned char to char.
        auto addr_out = reinterpret_cast<const char*>(ipv6_input->sin6_addr.addr);
        auto addr_size = sizeof(ipv6_input->sin6_addr.addr);
        ipv6_output->set_addr(
            {&addr_out[0],
             &addr_out[addr_size]});
        ipv6_output->set_scope_id(ipv6_input->sin6_scope_id);
      } break;
      default:
        break;
    }
  }

  // nxsockaddr_storage is a type specifically designed to be large enough to hold
  // any of the nxsockaddr types.
  nxsockaddr_storage storage;
};

struct SetInputConverter {
  SetInputConverter(
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

struct TimeValInputConverter {
  TimeValInputConverter(const pb_::Duration& input)
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
inline SockAddrInputConverter convert_from_grpc(const SockAddr& input)
{
  return SockAddrInputConverter(input);
}

inline void convert_to_grpc(const SockAddrOutputConverter& storage, SockAddr* output)
{
  storage.to_grpc(*output);
}

template <typename TTimeVal>
inline SetInputConverter convert_from_grpc(
    const pb_::RepeatedPtrField<nidevice_grpc::Session>& input,
    const ResourceRepositorySharedPtr_& resource_repository)
{
  return SetInputConverter(input, resource_repository);
}

template <typename TTimeVal>
inline TimeValInputConverter convert_from_grpc(const pb_::Duration& input)
{
  return TimeValInputConverter(input);
}

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
    return opt_data.opt_name();
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

// Template specializations go in nidevice_grpc::converters.
namespace nidevice_grpc {
namespace converters {
// Specialization of TypeToStorageType so that allocate_storage_type will
// allocate SockAddrOutputConverters for nxsockaddr output params.
template <>
struct TypeToStorageType<nxsockaddr, nixnetsocket_grpc::SockAddr> {
  using StorageType = nixnetsocket_grpc::SockAddrOutputConverter;
};
}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H */
