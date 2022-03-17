#ifndef NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/util/time_util.h>
#include <nixnetsocket.pb.h>
#include <nixnetsocket/nixnetsocket_library_interface.h>
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

struct VirtualInterfaceOutputConverter {
  VirtualInterfaceOutputConverter(NiXnetSocketLibraryInterface* library) : virtual_interface_ptr(nullptr), library(library)
  {
  }

  nxVirtualInterface_t** operator&()
  {
    return &virtual_interface_ptr;
  }

  void to_grpc(pb_::RepeatedPtrField<VirtualInterface>& output)
  {
    auto curr_vi_ptr = virtual_interface_ptr;
    for (
        auto curr_vi_ptr = virtual_interface_ptr;
        curr_vi_ptr != nullptr;
        curr_vi_ptr = curr_vi_ptr->nextVirtualInterface) {
      auto curr_grpc_vi = output.Add();
      curr_grpc_vi->set_xnet_interface_name(curr_vi_ptr->xnetInterfaceName);
      curr_grpc_vi->set_mac_address(curr_vi_ptr->macAddress);
      curr_grpc_vi->set_mac_mtu(curr_vi_ptr->macMTU);
      curr_grpc_vi->set_operational_status(curr_vi_ptr->operationalStatus);
      curr_grpc_vi->set_if_index(curr_vi_ptr->ifIndex);
      for (
          auto curr_ip_addr_ptr = curr_vi_ptr->firstIPAddress;
          curr_ip_addr_ptr != nullptr;
          curr_ip_addr_ptr = curr_ip_addr_ptr->nextIPAddress) {
        auto curr_grpc_ip_addr = curr_grpc_vi->add_ip_addresses();
        curr_grpc_ip_addr->set_family(curr_ip_addr_ptr->family);
        curr_grpc_ip_addr->set_address(curr_ip_addr_ptr->address);
        curr_grpc_ip_addr->set_net_mask(curr_ip_addr_ptr->netmask);
        curr_grpc_ip_addr->set_prefix_length(curr_ip_addr_ptr->prefixLength);
      }
      for (
          auto curr_gateway_addr = curr_vi_ptr->firstGatewayAddress;
          curr_gateway_addr != nullptr;
          curr_gateway_addr = curr_gateway_addr->nextGatewayAddress) {
        auto curr_grpc_gateway_addr = curr_grpc_vi->add_gateway_addresses();
        curr_grpc_gateway_addr->set_family(curr_gateway_addr->family);
        curr_grpc_gateway_addr->set_address(curr_gateway_addr->address);
      }
    }
    // Free the stack info after we've read it.
    library->IpStackFreeInfo(virtual_interface_ptr);
    virtual_interface_ptr = nullptr;
  }

  nxVirtualInterface_t* virtual_interface_ptr;
  NiXnetSocketLibraryInterface* library;
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

inline void convert_to_grpc(VirtualInterfaceOutputConverter& storage, pb_::RepeatedPtrField<VirtualInterface>* output)
{
  storage.to_grpc(*output);
}

struct SockOptDataInputConverter {
  SockOptDataInputConverter(const SockOptData& input)
  {
    data_case = input.data_case();
    switch (data_case) {
      case SockOptData::DataCase::kDataInt32:
        data_int = input.data_int32();
        break;
      case SockOptData::DataCase::kDataBool:
        data_bool = input.data_bool();
        break;
      case SockOptData::DataCase::kDataString:
        data_string = std::string(input.data_string());
        break;
    }
  }

  void* data()
  {
    switch (data_case) {
      case SockOptData::DataCase::kDataInt32:
        return &data_int;
        break;
      case SockOptData::DataCase::kDataBool:
        return &data_bool;
        break;
      case SockOptData::DataCase::kDataString:
        return &data_string[0];
        break;
      case SockOptData::DataCase::DATA_NOT_SET:
        return nullptr;
        break;
    }
  }

  // size() method is used to simplify codegen calculating the size of the
  // populated data.
  nxsocklen_t size() const
  {
    switch (data_case) {
      case SockOptData::DataCase::kDataInt32:
        return sizeof(int32_t);
        break;
      case SockOptData::DataCase::kDataString:
        return static_cast<nxsocklen_t>(data_string.size());
        break;
      case SockOptData::DataCase::kDataBool:
        return sizeof(bool);
      default:
        return 0;
        break;
    }
  }

  SockOptData::DataCase data_case;
  int32_t data_int;
  bool data_bool;
  std::string data_string;
};

template <typename TSockOptData>
inline SockOptDataInputConverter convert_from_grpc(const SockOptData& input)
{
  return SockOptDataInputConverter(input);
}

// This class allows us to have something allocated on the stack that provides backing
// storage for a void* opt_val output param and converts it to the SockOptData grpc-type.
struct SockOptDataOutputConverter {
  SockOptDataOutputConverter(int32_t opt_name) : opt_name(opt_name)
  {
  }

  void* data()
  {
    switch (opt_name) {
      case OptName::OPT_NAME_IP_MULTICAST_TTL:
      case OptName::OPT_NAME_IPV6_MULTICAST_HOPS:
      case OptName::OPT_NAME_SO_RX_DATA:
      case OptName::OPT_NAME_SO_RCV_BUF:
      case OptName::OPT_NAME_SO_SND_BUF:
      case OptName::OPT_NAME_TCP_NODELAY: {
        return &data_int;
        break;
      }
      case OptName::OPT_NAME_SO_LINGER:
      case OptName::OPT_NAME_SO_NON_BLOCK:
      case OptName::OPT_NAME_SO_REUSE_ADDR: {
        return &data_bool;
        break;
      }
      case OptName::OPT_NAME_SO_BIND_TO_DEVICE:
      case OptName::OPT_NAME_SO_ERROR: {
        data_string = std::string(256 - 1, '\0');  // TODO: What's the max string size to allocate for a sock opt?
        return &data_string[0];
        break;
      }
      default:
        return nullptr;
        break;
    }
  }

  void to_grpc(SockOptData& output) const
  {
    switch (opt_name) {
      case OptName::OPT_NAME_IP_MULTICAST_TTL:
      case OptName::OPT_NAME_IPV6_MULTICAST_HOPS:
      case OptName::OPT_NAME_SO_RX_DATA:
      case OptName::OPT_NAME_SO_RCV_BUF:
      case OptName::OPT_NAME_SO_SND_BUF:
      case OptName::OPT_NAME_TCP_NODELAY: {
        output.set_data_int32(data_int);
        break;
      }
      case OptName::OPT_NAME_SO_LINGER:
      case OptName::OPT_NAME_SO_NON_BLOCK:
      case OptName::OPT_NAME_SO_REUSE_ADDR: {
        output.set_data_bool(data_bool);
        break;
      }
      case OptName::OPT_NAME_SO_BIND_TO_DEVICE:
      case OptName::OPT_NAME_SO_ERROR: {
        output.set_data_string(data_string);
        nidevice_grpc::converters::trim_trailing_nulls(*(output.mutable_data_string()));
        break;
      }
      default:
        break;
    }
  }

  int32_t opt_name;
  int32_t data_int;
  bool data_bool;
  std::string data_string;
};

inline void convert_to_grpc(const SockOptDataOutputConverter& storage, SockOptData* output)
{
  storage.to_grpc(*output);
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

template <>
struct TypeToStorageType<nxVirtualInterface_t, google::protobuf::RepeatedPtrField<nixnetsocket_grpc::VirtualInterface>> {
  using StorageType = nixnetsocket_grpc::VirtualInterfaceOutputConverter;
};
// Specialization of TypeToStorageType so that allocate_storage_type will
// allocate SockOptDataOutputConverters for void* output params.
template <>
struct TypeToStorageType<void*, nixnetsocket_grpc::SockOptData> {
  using StorageType = nixnetsocket_grpc::SockOptDataOutputConverter;
};
}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_XNET_SOCKET_CONVERTERS_H */
