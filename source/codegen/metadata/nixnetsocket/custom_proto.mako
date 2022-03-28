message IPAddress {
  uint32 family = 1;
  string address = 2;
  string net_mask = 3;
  uint32 prefix_length = 4;
}

message GatewayAddress {
  uint32 family = 1;
  string address = 2;
}

message VirtualInterface {
  string xnet_interface_name = 1;
  string vlane_name = 2;
  string mac_address = 3;
  uint32 mac_mtu = 4;
  uint32 operational_status = 5;
  uint32 if_index = 6;
  repeated IPAddress ip_addresses = 7;
  repeated GatewayAddress gateway_addresses = 8;
}

message In6Addr {
  bytes addr = 1;
}

message InAddr {
  uint32 addr = 1;
}

message Addr {
  oneof addr {
    InAddr ipv4 = 1;
    In6Addr ipv6 = 2;
  }
}

message SockAddrIn {
  uint32 port = 1;
  InAddr addr = 2;
}

message SockAddrIn6 {
  uint32 port = 1;
  uint32 flow_info = 2;
  In6Addr addr = 3;
  uint32 scope_id = 4;
}

message SockAddr {
  oneof addr {
    SockAddrIn ipv4 = 1;
    SockAddrIn6 ipv6 = 2;
  }
}

message AddrInfo {
  repeated GetAddrInfoFlags flags = 1;
  int32 flags_raw = 2;
  AddressFamily family = 3;
  SocketProtocolType sock_type = 4;
  IPProtocol protocol = 5;
  SockAddr addr = 6;
  string canon_name = 7;
}

message AddrInfoHint {
  repeated GetAddrInfoFlags flags = 1;
  int32 flags_raw = 2;
  AddressFamily family = 3;
  SocketProtocolType sock_type = 4;
  IPProtocol protocol = 5;
}

message Linger {
  int32 l_onoff = 1;
  int32 l_linger = 2;
}

message IPMReq {
  InAddr imr_multiaddr = 1;
  InAddr imr_interface = 2;
}

message IPv6MReq {
  In6Addr ipv6mr_multiaddr = 1;
  int32 ipv6mr_interface = 2;
}

message SockOptData {
  oneof data {
    int32 data_int32 = 1;
    bool data_bool = 2;
    string data_string = 3;
    Linger data_linger = 4;
    IPMReq data_ip_mreq = 5;
    IPv6MReq data_ipv6_mreq = 6;
  }
}
